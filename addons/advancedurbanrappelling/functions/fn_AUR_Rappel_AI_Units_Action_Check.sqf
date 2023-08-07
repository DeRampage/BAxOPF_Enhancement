        params ["_player"];
        if(leader _player != _player) exitWith {false;};
        _hasAiUnits = false;
        {
                if(!isPlayer _x) exitWith {
                        _hasAiUnits = true;
                };
        } forEach units _player;
        if(!_hasAiUnits) exitWith {false;};
        if((count ([_player] call TF47_fnc_AUR_Get_AI_Units_Ready_To_Rappel)) == 0) exitWith {false;};
        true;