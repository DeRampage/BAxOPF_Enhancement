params ["_player","_rappelDevice","_rappelAncor"];
        if(!hasInterface || !(call TF47_fnc_AUR_Has_Addon_Sounds_Installed) ) exitWith {};
        if(player distance _player < 15) then {
                [_player, "AUR_Rappel_Start"] call TF47_fnc_AUR_Play_3D_Sound;
                [_rappelDevice, "AUR_Rappel_Loop"] call TF47_fnc_AUR_Play_3D_Sound;
        };
        _this spawn {
                params ["_player","_rappelDevice","_rappelAncor"];
                private ["_lastDistanceFromAnchor","_distanceFromAnchor"];
                _lastDistanceFromAnchor = _rappelDevice distance _rappelAncor;
                while {_player getVariable ["AUR_Is_Rappelling",false]} do {
                        _distanceFromAnchor = _rappelDevice distance _rappelAncor;
                        if(_distanceFromAnchor > _lastDistanceFromAnchor + 0.1 && player distance _player < 15) then {
                                [_player, "AUR_Rappel_Loop"] call TF47_fnc_AUR_Play_3D_Sound;
                                sleep 0.2;
                                [_rappelDevice, "AUR_Rappel_Loop"] call TF47_fnc_AUR_Play_3D_Sound;
                        };
                        sleep 0.9;
                        _lastDistanceFromAnchor = _distanceFromAnchor;
                };
        };
        _this spawn {
                params ["_player"];
                while {_player getVariable ["AUR_Is_Rappelling",false]} do {
                        sleep 0.1;
                };
                if(player distance _player < 15) then {
                        [_player, "AUR_Rappel_End"] call TF47_fnc_AUR_Play_3D_Sound;
                };
        };