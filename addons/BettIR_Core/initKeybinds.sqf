/** 
    ************** KEYBINDS **************
*/
["BettIR", 'BettIR_ToggleGogglesIlluminator', 'Toggle Goggles Illuminator', {
    // toggle illuminator on/off
    [player] call TF47_fnc_toggleNvgIlluminator;


    true;
}, {false}, [0x31, [true, false, true]], false] call CBA_fnc_addKeybind;

["BettIR", 'BettIR_ToggleWeaponIlluminator', 'Toggle Weapon Illuminator', {
    // toggle illuminator on/off
    [player] call TF47_fnc_toggleWeaponIlluminator;
    

    true;
}, {false}, [0x26, [true, false, true]], false] call CBA_fnc_addKeybind;


["BettIR", 'BettIR_HoldWeaponIlluminator', "Hold Weapon Illuminator", {
    // turn on weapon illuminator when pressed
    [player] call TF47_fnc_weaponIlluminatorOn;

    true;
}, {
    // turn off weapon illuminator when pressed
    [player] call TF47_fnc_weaponIlluminatorOff;

    true;
}, nil, false] call CBA_fnc_addKeybind;


["BettIR", 'BettIR_HoldWeaponLaser', "Hold Weapon IR Laser", {
    // turn on weapon IR laser when pressed
    player action ["IRLaserOn", player];

    true;
}, {
    // turn off weapon IR laser when pressed
    player action ["IRLaserOff", player];

    true;
}, nil, false] call CBA_fnc_addKeybind;