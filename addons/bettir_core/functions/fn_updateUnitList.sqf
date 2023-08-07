/**
    Created by Vestarr

    Updates the global list of nearby units that use IR lights
    
    Parameters: None
    Returns: None
 */

// get a list of people in the viewdistance who qualify for the IR Light
BettIR_UnitList = allUnits select {
    if (alive _x 
        && (currentVisionMode _x) == 1
        && (_x getVariable ['BettIR_nvg_illuminator_on', false] || _x getVariable ['BettIR_weapon_illuminator_on', false]) 
        && (player == _x || (player distance _x) <= BettIR_ViewDistance)
    ) then {
        if (_x getVariable ['BettIR_nvg_illuminator_on', false]) then {
            // if all conditions match but the unit doesn't have a light object, it means
            // that the unit is new to our nearest area - so let's create a local light object for him
            if (isNull (_x getVariable ['BettIR_nvg_illuminator_object', objNull])) then {
                // first let's check if the NVG goggles are compatible with the guy
                _nvgClassname = toLower (hmd _x);

                if (_nvgClassname != '') then {
                    _nvgIndex = BettIR_CompatibleNVGs findIf { _x == _nvgClassname };

                    if (_nvgIndex != -1) then {
                        _offset = BettIR_CompatibleNVGsOffsets select _nvgIndex;
                        _x setVariable ['BettIR_nvg_illuminator_offset', _offset, false];
                        
                        _light = 'BettIR_Illuminator_NVG' createVehicleLocal (getPosATL _x);
                        _light setVariable ['BettIR_owner', _x];
                        _x setVariable ['BettIR_nvg_illuminator_object', _light, false];
                    } else {
                        // if it's not compatible, set it back to false (if local)
                        if (local _x) then {
                            _x setVariable ['BettIR_nvg_illuminator_on', false, true]; 
                        };
                    };
                };
            };
        };

        if ((currentWeapon _x == primaryWeapon _x) && _x getVariable ['BettIR_weapon_illuminator_on', false]) then {
            if (isNull (_x getVariable ['BettIR_weapon_illuminator_object', objNull])) then {
                _weaponsItems = primaryWeaponItems _x;
                _attachmentClassname = toLower (_weaponsItems select 1);

                if (_attachmentClassname != '') then {
                    _attachmentIndex = BettIR_CompatibleAttachments findIf { _x == _attachmentClassname };

                    if (_attachmentIndex != -1) then {
                        _offset = BettIR_CompatibleAttachmentsOffsets select _attachmentIndex;
                        _x setVariable ['BettIR_weapon_illuminator_offset', _offset, false];
                        
                        _light = 'BettIR_Illuminator_Weapon' createVehicleLocal (getPosATL _x);
                        _light setVariable ['BettIR_owner', _x];
                        _x setVariable ['BettIR_weapon_illuminator_object', _light, false];
                    } else {
                        // if it's not compatible, set it back to false (if local)
                        if (local _x) then {
                            _x setVariable ['BettIR_weapon_illuminator_on', false, true]; 
                        };
                    };
                };
            };
        };

        true;
    } else {
        // if the unit has a light but they don't meet the conditions, let's remove their light
        _light = _x getVariable ['BettIR_nvg_illuminator_object', objNull];
        if (!isNull _light) then {
            deleteVehicle _light;
            _x setVariable ['BettIR_nvg_illuminator_object', objNull, false];
            _x setVariable ['BettIR_nvg_illuminator_offset', [0,0,0], false];
        };

        _light = _x getVariable ['BettIR_weapon_illuminator_object', objNull];
        if (!isNull _light) then {
            deleteVehicle _light;
            _x setVariable ['BettIR_weapon_illuminator_object', objNull, false];
            _x setVariable ['BettIR_weapon_illuminator_offset', [0,0,0], false];
        };

        false;
    };
};
