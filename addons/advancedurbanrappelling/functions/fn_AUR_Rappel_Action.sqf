params ["_player"];        

// systemChat format ["Function: Rappel_Action, Params: %1", _this];

        if([_player] call TF47_fnc_AUR_Rappel_Action_Check) then {
                _rappelPoint = [_player,getPosASL _player,"POSITION"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point;
                if(count _rappelPoint > 0) then {
                        _player setVariable ["AUR_Rappelling_Last_Started_Time",diag_tickTime];
                        _player setVariable ["AUR_Rappelling_Last_Rappel_Point",_rappelPoint];
                        _ropeLength = ([_player] call TF47_fnc_AUR_Get_Player_Height_Above_Ground) * 1.3;
                        [_player, getPosASL _player, _rappelPoint select 0, _rappelPoint select 1,_ropeLength] spawn TF47_fnc_AUR_Rappel;
                } else {
                        [["Couldn't attach rope. Move closer to edge!", false],"TF47_fnc_AUR_Hint",_player] call TF47_fnc_AUR_RemoteExec;
                };
        } else {
                [["Couldn't attach rope. Move closer to edge!", false],"TF47_fnc_AUR_Hint",_player] call TF47_fnc_AUR_RemoteExec;
        };