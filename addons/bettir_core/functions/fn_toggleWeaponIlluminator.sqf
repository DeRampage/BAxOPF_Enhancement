/**
    Created by Vestarr

    Toggles the weapon-mounted IR Illuminator
    
    Parameters: Array
        0 - _unit <OBJECT> - Unit which we're toggling it for
    Returns: None


    Example: [true] call TF47_fnc_toggleWeaponIlluminator
 */

params ['_unit'];

_isOn = _unit getVariable ['BettIR_weapon_illuminator_on', false];

if (_isOn) then {
    [_unit] call TF47_fnc_weaponIlluminatorOff;
} else {
    [_unit] call TF47_fnc_weaponIlluminatorOn;
};
