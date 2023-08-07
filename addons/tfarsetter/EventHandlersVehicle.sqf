// When mounting, save loadout and apply a profile's config
player addEventHandler ["GetInMan", {
    // If CBA settings for this are disabled, break
    if (!GVAR(enableMountingAutoSettings)) exitWith {};

       params ["_unit", "", "_vehicle"];

    // If not correct type of vehicle
    if !(_vehicle isKindOf "Air" || _vehicle isKindOf "Land") exitWith {};

    // Get currently active radios
    private _data = [(call TFAR_fnc_activeSwRadio) call TFAR_fnc_getSwSettings, (player call TFAR_fnc_backpackLR) call TFAR_fnc_getLrSettings];

    // If entries are nil, set them to []
    {
        if (isNil "_x") then {
            _data set [_forEachIndex, []];
        };
    } forEach _data;

    // Add headset status
    _data set [3, missionNamespace getVariable ["TFAR_core_isHeadsetLowered", false]];

    GVAR(radioLoadout) = _data;

    // Get data from profile
    _data = GETPRVAR(FORMAT_1(QGVAR(profile%1),[ARR_2(GVAR(landProfile),GVAR(airProfile))] select (_vehicle isKindOf "Air")),[]);

    // If nothing can be applied, exit
    if (_data isEqualTo [] || isNil "_data") exitWith {};

    // If a SW is found and the settings are not [], load them
    if (call TFAR_fnc_haveSWRadio && {(_data select 0) isNotEqualTo []}) then {
        [call TFAR_fnc_activeSwRadio, _data select 0] call TFAR_fnc_setSwSettings;
    };

    // If no LR radio found in vehicle, then continue
    if (call TFAR_fnc_haveLRRadio) then {
        // Apply VLR to VLR if possible, otherwise a mix of settings (LR -> VLR, VLR -> LR, LR -> LR)
        private _radioVLR = _unit call TFAR_fnc_vehicleLR;
        [[_unit call TFAR_fnc_backpackLR, _radioVLR] select (!isNil "_radioVLR"), _data select ([1, 2] select (!isNil {_data select 2} && {(_data select 2) isNotEqualto []}))] call TFAR_fnc_setLrSettings;
    };

    // Set the headset up or down
    if (!isNil {_data select 3}) then {
                    (_data select 3) call TFAR_fnc_setHeadsetLowered;
    };
}];

// When switching seats, apply a profile's config
player addEventHandler ["SeatSwitchedMan", {
    // If CBA settings for this are disabled, break
    if (!GVAR(enableMountingAutoSettings)) exitWith {};

       params ["_unit1", "", "_vehicle"];

    // If not correct type of vehicle
    if !(_vehicle isKindOf "Air" || _vehicle isKindOf "Land") exitWith {};

    // Get data from profile
    private _data = GETPRVAR(FORMAT_1(QGVAR(profile%1),[ARR_2(GVAR(landProfile),GVAR(airProfile))] select (_vehicle isKindOf "Air")),[]);

    // If nothing can be applied, exit
    if (_data isEqualTo [] || isNil "_data") exitWith {};

    // If a SW is found and the settings are not [], load them
    if (call TFAR_fnc_haveSWRadio && {(_data select 0) isNotEqualTo []}) then {
        [call TFAR_fnc_activeSwRadio, _data select 0] call TFAR_fnc_setSwSettings;
    };

    // If no LR radio found in vehicle, then continue
    if (call TFAR_fnc_haveLRRadio) then {
        // Apply VLR to VLR if possible, otherwise a mix of settings (LR -> VLR, VLR -> LR, LR -> LR)
        private _radioVLR = _unit1 call TFAR_fnc_vehicleLR;
        [[_unit1 call TFAR_fnc_backpackLR, _radioVLR] select (!isNil "_radioVLR"), _data select ([1, 2] select (!isNil {_data select 2} && {(_data select 2) isNotEqualto []}))] call TFAR_fnc_setLrSettings;
    };

    // Set the headset up or down
    if (!isNil {_data select 3}) then {
                    (_data select 3) call TFAR_fnc_setHeadsetLowered;
    };
}];

// When leaving a vehicle, the previously saved loadout will be applied
player addEventHandler ["GetOutMan", {
    // If CBA settings for this are disabled, break
    if (!GVAR(enableMountingAutoSettings)) exitWith {};

       params ["_unit", "_role"];

    GVAR(radioLoadout) params ["_SR", "_LR", "_headsetStatus"];

    // If a SW is found and the settings are not [], load them
    if (call TFAR_fnc_haveSWRadio && {_SR isNotEqualTo []}) then {
        [call TFAR_fnc_activeSwRadio, _SR] call TFAR_fnc_setSwSettings;
    };

    // If no LR radio found in vehicle, then continue
    if (call TFAR_fnc_haveLRRadio && {_LR isNotEqualTo []}) then {
        [_unit call TFAR_fnc_backpackLR, _LR] call TFAR_fnc_setLrSettings;
    };

    // Set the headset up or down
    _headsetStatus call TFAR_fnc_setHeadsetLowered;
}];
