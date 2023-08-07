/**
    Created by Vestarr

    Switches the weapon IR Illuminator OFF
    
    Parameters: Array
        0 - _unit <OBJECT> - Unit which we're toggling it for
    Returns: None


    Example: [true] call TF47_fnc_weaponIlluminatorOff
 */
params ['_unit'];

_lightObject = _unit getVariable ["BettIR_weapon_illuminator_object", objNull];
                
if (!(isNull _lightObject)) then {
    deleteVehicle _lightObject; 
    _unit setVariable ["BettIR_weapon_illuminator_object", objNull, false];
};


_unit setVariable ['BettIR_weapon_illuminator_on', false, true];