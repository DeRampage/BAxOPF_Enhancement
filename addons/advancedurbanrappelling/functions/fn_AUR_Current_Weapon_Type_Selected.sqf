        params ["_player"];
        if(currentWeapon _player == handgunWeapon _player) exitWith {"HANDGUN"};
        if(currentWeapon _player == primaryWeapon _player) exitWith {"PRIMARY"};
        if(currentWeapon _player == secondaryWeapon _player) exitWith {"SECONDARY"};
        "OTHER";