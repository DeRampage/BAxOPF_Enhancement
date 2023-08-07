        params ["_player"];
        if(_player getVariable ["AUR_Is_Rappelling",false]) exitWith {false;};
        if(vehicle _player != _player) exitWith {false;};
        if(([_player] call TF47_fnc_AUR_Get_Player_Height_Above_Ground) < 4) exitWith {false};
        if!([_player,getPosASL _player,"FAST_EXISTS_CHECK"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point) exitWith {false;};
        if(count ([_player,getPosASL _player,"POSITION"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point) == 0) exitWith {false;};
        true;