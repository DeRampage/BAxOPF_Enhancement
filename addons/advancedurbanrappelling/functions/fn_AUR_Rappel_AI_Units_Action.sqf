        params ["_player"];
        _aiUnits = [_player] call TF47_fnc_AUR_Get_AI_Units_Ready_To_Rappel;
        _rappelPoint = _player getVariable ["AUR_Rappelling_Last_Rappel_Point",[]];
        if([_player] call TF47_fnc_AUR_Rappel_Action_Check) then {
                _rappelPoint = [_player,getPosASL _player,"POSITION"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point;        
        };
        _index = 0;
        _allRappelPoints = _rappelPoint select 2;
        if(count _rappelPoint > 0) then {
                {
                        if(!(_x getVariable ["AUR_Is_Rappelling",false])) then {
                                [_x, getPosASL _player, _allRappelPoints select (_index mod 3), _rappelPoint select 1,60] spawn TF47_fnc_AUR_Rappel;
                                sleep 5;
                        };
                        _index = _index + 1;
                } forEach (_aiUnits);
        };