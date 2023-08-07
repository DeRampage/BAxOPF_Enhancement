params ["_player",["_globalExec",false]];

if(local _player && _globalExec) exitWith {};

if(local _player && !_globalExec) then {
        [[_player],"TF47_fnc_AUR_Enable_Rappelling_Animation_Global"] call TF47_fnc_AUR_RemoteExecServer;
};

if(_player != player) then {
        _player enableSimulation false;
};

if([] call TF47_fnc_AUR_Has_Addon_Animations_Installed) then {                
        if([_player] call TF47_fnc_AUR_Current_Weapon_Type_Selected == "HANDGUN") then {
        // systemChat "anim: pistol";
                if(local _player) then {
            
                        _player switchMove "AUR_01_Idle_Pistol";
                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Idle_Pistol_No_Actions",true];
                } else {
                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Idle_Pistol_No_Actions"];                        
                };
        } else {
                if(local _player) then {
                        _player switchMove "AUR_01_Idle";
                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Idle_No_Actions",true];
                } else {
                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Idle_No_Actions"];
                };
        };
        if!(local _player) then {
                // Temp work around to avoid seeing other player as standing
                _player switchMove "AUR_01_Idle_No_Actions";
                sleep 1;
                _player switchMove "AUR_01_Idle_No_Actions";
                sleep 1;
                _player switchMove "AUR_01_Idle_No_Actions";
                sleep 1;
                _player switchMove "AUR_01_Idle_No_Actions";
        };
} else {
        if(local _player) then {
                _player switchMove "HubSittingChairC_idle1";
                _player setVariable ["AUR_Animation_Move","HubSittingChairC_idle1",true];
        } else {
                _player setVariable ["AUR_Animation_Move","HubSittingChairC_idle1"];                
        };
};

_animationEventHandler = -1;
if(local _player) then {
        _animationEventHandler = _player addEventHandler ["AnimChanged",{
                params ["_player","_animation"];
                if(call TF47_fnc_AUR_Has_Addon_Animations_Installed) then {
                        if((toLower _animation) find "TF47_fnc_AUR_" < 0) then {
                                if([_player] call TF47_fnc_AUR_Current_Weapon_Type_Selected == "HANDGUN") then {
                                        _player switchMove "AUR_01_Aim_Pistol";
                                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Aim_Pistol_No_Actions",true];
                                } else {
                                        _player switchMove "AUR_01_Aim";
                                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Aim_No_Actions",true];
                                };
                        } else {
                                if(toLower _animation == "TF47_fnc_AUR_01_aim") then {
                                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Aim_No_Actions",true];
                                };
                                if(toLower _animation == "TF47_fnc_AUR_01_idle") then {
                                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Idle_No_Actions",true];
                                };
                                if(toLower _animation == "TF47_fnc_AUR_01_aim_pistol") then {
                                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Aim_Pistol_No_Actions",true];
                                };
                                if(toLower _animation == "TF47_fnc_AUR_01_idle_pistol") then {
                                        _player setVariable ["AUR_Animation_Move","TF47_fnc_AUR_01_Idle_Pistol_No_Actions",true];
                                };
                        };
                } else {
                        _player switchMove "HubSittingChairC_idle1";
                        _player setVariable ["AUR_Animation_Move","HubSittingChairC_idle1",true];
                };
        }];
};

if(!local _player) then {
        [_player] spawn {
                params ["_player"];
                private ["_currentState"];
                while {_player getVariable ["AUR_Is_Rappelling",false]} do {
                        _currentState = toLower animationState _player;
                        _newState = toLower (_player getVariable ["AUR_Animation_Move",""]);
                        if!(call TF47_fnc_AUR_Has_Addon_Animations_Installed) then {
                                _newState = "HubSittingChairC_idle1";
                        };
                        if(_currentState != _newState) then {
                                _player switchMove _newState;
                                _player switchGesture "";
                                sleep 1;
                                _player switchMove _newState;
                                _player switchGesture "";
                        };
                        sleep 0.1;
                };                        
        };
};

waitUntil {!(_player getVariable ["AUR_Is_Rappelling",false])};

if(_animationEventHandler != -1) then {
        _player removeEventHandler ["AnimChanged", _animationEventHandler];
};

_player switchMove "";        
_player enableSimulation true;
