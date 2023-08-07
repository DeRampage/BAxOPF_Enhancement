params ["_unit",["_ropeLength",0],["_rappelPoint",[]],["_rappelDirection",[]]];
        if(count _rappelPoint == 0) then {
                _findRappelPointResult = [_unit,getPosASL _unit,"POSITION"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point;        
                if(count _findRappelPointResult > 0) then {
                        _rappelPoint = _findRappelPointResult select 0;
                        _rappelDirection = _findRappelPointResult select 1;
                };
        };
        if(count _rappelPoint > 0) then {
                if(_ropeLength <= 0) then {
                        _ropeLength = ([_unit] call TF47_fnc_AUR_Get_Player_Height_Above_Ground) * 1.3;
                };
                [_unit, getPosASL _unit, _rappelPoint, _rappelDirection, _ropeLength] spawn TF47_fnc_AUR_Rappel;
        } else {
                hint "Could not rappel unit - move unit closer to edge!";
        };