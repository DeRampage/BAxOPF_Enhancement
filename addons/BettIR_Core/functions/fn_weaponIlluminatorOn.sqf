/**
    Created by Vestarr

    Switches the weapon IR Illuminator ON
    
    Parameters: Array
        0 - _unit <OBJECT> - Unit which we're toggling it for
    Returns: None


    Example: [true] call TF47_fnc_weaponIlluminatorOn
 */

params ['_unit'];

if (_unit getVariable ['BettIR_weapon_illuminator_on', false]) exitWith {};
if (currentVisionMode _unit != 1) exitWith {};
if (currentWeapon _unit != primaryWeapon _unit) exitWith {}; 

_weaponsItems = primaryWeaponItems _unit;
_attachmentClassname = toLower (_weaponsItems select 1);

if (_attachmentClassname != '') then {
    _attachmentIndex = BettIR_CompatibleAttachments findIf { _x == _attachmentClassname };

    if (_attachmentIndex != -1) then {
        _offset = BettIR_CompatibleAttachmentsOffsets select _attachmentIndex;
        _unit setVariable ['BettIR_weapon_illuminator_offset', _offset, false];
        _unit setVariable ['BettIR_weapon_illuminator_on', true, true]; 
        
        if (currentVisionMode player == 1) then {
            _light = 'BettIR_Illuminator_Weapon' createVehicleLocal (getPosATL _unit);
            hideObject _light;
            _light setVariable ['BettIR_owner', _unit];
            _unit setVariable ['BettIR_weapon_illuminator_object', _light, false];
            BettIR_UnitList_LastUpdate = time;
            [] spawn TF47_fnc_updateUnitList;
        };
    };
};
