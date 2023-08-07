params ["_player"];
        if(leader _player != _player) exitWith {[]};
        _hasAiUnits = false;
        {
                if(!isPlayer _x) exitWith {
                        _hasAiUnits = true;
                };
        } forEach units _player;
        if(!_hasAiUnits) exitWith {[]};
        _canRappel = [_player] call TF47_fnc_AUR_Rappel_Action_Check;
        _isRappelling = _player getVariable ["AUR_Is_Rappelling",false];
        _didRappel = (diag_tickTime - (_player getVariable ["AUR_Rappelling_Last_Started_Time",0])) < 300;
        _aiUnitsReady = [];
        if(_canRappel || _isRappelling || _didRappel) then {
                _rappelPoint = _player getVariable ["AUR_Rappelling_Last_Rappel_Point",[]];
                _rappelPosition = [0,0,0];
                if(count _rappelPoint > 0) then {
                        _rappelPosition = ASLToATL (_rappelPoint select 0);
                };
                if(_canRappel) then {
                        _rappelPosition = getPosATL _player;
                };
                {
                        if(!isPlayer _x && _rappelPosition distance _x < 15 && abs ((_rappelPosition select 2) - ((getPosATL _x) select 2)) < 4 && not (_x getVariable ["AUR_Is_Rappelling",false]) && alive _x && vehicle _x == _x ) then {
                                _aiUnitsReady pushBack _x;
                        };
                } forEach units _player;
        };
        _aiUnitsReady;