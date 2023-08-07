//Should be only on request with a nice drawn throwing angle and maybe a grappling gun

params ["_player"];
_rappelPoint = [_player] call TF47_fnc_AUR_Get_Anchor_Point_Player_Looking_At;
[_player,"Climb_Up"] call TF47_fnc_AUR_Has_Rope_Check; //Set the Variables
if(count _rappelPoint > 0) then {
        _player setVariable ["AUR_Rappelling_Last_Started_Time",diag_tickTime];
        _player setVariable ["AUR_Rappelling_Last_Rappel_Point",_rappelPoint];
        _ropeLength = ((ASLtoAGL (_rappelPoint select 0)) select 2) * 1.3;
        _maxAvailableLength = player getVariable ["TF47_AUR_Rope_length", 0];
        _angle = [_player, _rappelPoint select 0, 20] call TF47_fnc_AUR_Get_Trajectory_Angle;
        _grap = createVehicle ["Land_Can_V2_F", _player, [], 0, "CAN_COLLIDE"];
        _velocity = (getPosASL _player) vectorFromTo (_rappelPoint select 0);
        _velocity set [2,0];
        _velocity = vectorNormalized _velocity;// draw throwing angle before throwing
        _velocity set [2,tan _angle];
        _velocity = _velocity vectorMultiply 20;
        _grap setVelocity _velocity;
        _grap allowDamage false;
        //hideObject _grap;
        _playerHoldingAnchor = createVehicle ["B_static_AA_F", _player, [], 0, "CAN_COLLIDE"];
        hideObject _playerHoldingAnchor;
        _playerHoldingAnchor allowDamage false;
        _rope = ropeCreate [_playerHoldingAnchor, [0,0.15,0], _grap, [0, 0, 0], 30];
        
        sleep 1;
        
        //systemChat Format["Benötigte Seillänge: %1 Maximale vorhandene Länge: %2", _ropeLength, _maxAvailableLength];//debug
        if(_maxAvailableLength <= _ropeLength) exitWith {
                [["Couldn't grapple the edge. Rope is to short!", false],"TF47_fnc_AUR_Hint",_player] call TF47_fnc_AUR_RemoteExec;
                sleep 1;
                ropeDestroy _rope;
                deleteVehicle _playerHoldingAnchor;
                deleteVehicle _grap;                    
        };
        _grap enableSimulation false;
        _grap setPosASL (_rappelPoint select 0);
        
        sleep 1;
        
        ropeDestroy _rope;
        deleteVehicle _playerHoldingAnchor;
        deleteVehicle _grap;                
        //dont swing like tarzan but connect the player to the rope
        [_player, getPosASL _grap, _rappelPoint select 0, _rappelPoint select 1,_maxAvailableLength, true] spawn TF47_fnc_AUR_Rappel;
} else {
        [["Couldn't attach rope. Move closer to edge!", false],"TF47_fnc_AUR_Hint",_player] call TF47_fnc_AUR_RemoteExec;
};