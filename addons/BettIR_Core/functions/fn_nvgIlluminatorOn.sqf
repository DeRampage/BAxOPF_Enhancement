/**
    Created by Vestarr

    Switches the NVG-mounted IR Illuminator ON
    
    Parameters: Array
        0 - _unit <OBJECT> - Unit which we're toggling it for
    Returns: None


    Example: [true] call TF47_fnc_nvgIlluminatorOn
 */

params ['_unit'];

if (_unit getVariable ['BettIR_nvg_illuminator_on', false]) exitWith {};
if (currentVisionMode _unit != 1) exitWith {};

_nvgClassname = toLower (hmd _unit);

if (_nvgClassname != '') then {
    _nvgIndex = BettIR_CompatibleNVGs findIf { _x == _nvgClassname };

    if (_nvgIndex != -1) then {
        _offset = BettIR_CompatibleNVGsOffsets select _nvgIndex;
        _unit setVariable ['BettIR_nvg_illuminator_offset', _offset, false];
        _unit setVariable ['BettIR_nvg_illuminator_on', true, true]; 
        
        if (currentVisionMode player == 1) then {
            _light = 'BettIR_Illuminator_NVG' createVehicleLocal (getPosATL _unit);
            hideObject _light;
            _light setVariable ['BettIR_owner', _unit];
            _unit setVariable ['BettIR_nvg_illuminator_object', _light, false];
            BettIR_UnitList_LastUpdate = time;
            [] spawn TF47_fnc_updateUnitList;
        };
    };
};
