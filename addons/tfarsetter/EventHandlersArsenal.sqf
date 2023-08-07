// When arsenals open, save current radio config
["ace_arsenal_displayOpened", {
    // If CBA settings for this are disabled, break
    if (!GVAR(enableArsenalAutoSettings)) exitWith {};

    // Get currently active radios
    private _data = [(call TFAR_fnc_activeSwRadio) call TFAR_fnc_getSwSettings, (player call TFAR_fnc_backpackLR) call TFAR_fnc_getLrSettings];

    // If entries are nil, set them to []
    {
        if (isNil "_x") then {
            _data set [_forEachIndex, []];
        };
    } forEach _data;

    // Add headset status
    _data pushBack (missionNamespace getVariable ["TFAR_core_isHeadsetLowered", false]);

    GVAR(radioLoadout) = _data;
}] call CBA_fnc_addEventHandler;

[missionNamespace, "arsenalOpened", {
    // If CBA settings for this are disabled, break
    if (!GVAR(enableArsenalAutoSettings)) exitWith {};

    // Get currently active radios
    private _data = [(call TFAR_fnc_activeSwRadio) call TFAR_fnc_getSwSettings, (player call TFAR_fnc_backpackLR) call TFAR_fnc_getLrSettings];

    // If entries are nil, set them to []
    {
        if (isNil "_x") then {
            _data set [_forEachIndex, []];
        };
    } forEach _data;

    // Add headset status
    _data pushBack (missionNamespace getVariable ["TFAR_core_isHeadsetLowered", false]);

    GVAR(radioLoadout) = _data;
}] call BIS_fnc_addScriptedEventHandler;

// When arsenals close, apply previously saved config
["ace_arsenal_displayClosed", {
    // If CBA settings for this are disabled, break
    if (!GVAR(enableArsenalAutoSettings)) exitWith {};

    // Load the SW settings when a SW is detected. However, there is a 10s timeout timer, in case a SW is never selected.
    [{
       call TFAR_fnc_haveSWRadio
    }, {
        private _SR = GVAR(radioLoadout) select 0;

        if (_SR isNotEqualto []) then {
            [call TFAR_fnc_activeSwRadio, _SR] call TFAR_fnc_setSwSettings;
        };

        (GVAR(radioLoadout) select 3) call TFAR_fnc_setHeadsetLowered;
    }, [], 10] call CBA_fnc_waitUntilAndExecute;

    // Load the LR settings when a LR is detected. However, there is a 10s timeout timer, in case a LR is never selected.
    [{
       call TFAR_fnc_haveLRRadio
    }, {
        private _LR = GVAR(radioLoadout) select 1;

        if (_LR isNotEqualto []) then {
            [player call TFAR_fnc_backpackLR, _LR] call TFAR_fnc_setLrSettings;
        };

        (GVAR(radioLoadout) select 3) call TFAR_fnc_setHeadsetLowered;
    }, [], 10] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[missionNamespace, "arsenalClosed", {
    // If CBA settings for this are disabled, break
    if (!GVAR(enableArsenalAutoSettings)) exitWith {};

    // Load the SW settings when a SW is detected. However, there is a 10s timeout timer, in case a SW is never selected.
    [{
       call TFAR_fnc_haveSWRadio
    }, {
        private _SR = GVAR(radioLoadout) select 0;

        if (_SR isNotEqualto []) then {
            [call TFAR_fnc_activeSwRadio, _SR] call TFAR_fnc_setSwSettings;
        };

        (GVAR(radioLoadout) select 3) call TFAR_fnc_setHeadsetLowered;
    }, [], 10] call CBA_fnc_waitUntilAndExecute;

    // Load the LR settings when a LR is detected. However, there is a 10s timeout timer, in case a LR is never selected.
    [{
       call TFAR_fnc_haveLRRadio
    }, {
        private _LR = GVAR(radioLoadout) select 1;

        if (_LR isNotEqualto []) then {
            [player call TFAR_fnc_backpackLR, _LR] call TFAR_fnc_setLrSettings;
        };

        (GVAR(radioLoadout) select 3) call TFAR_fnc_setHeadsetLowered;
    }, [], 10] call CBA_fnc_waitUntilAndExecute;
}] call BIS_fnc_addScriptedEventHandler;
