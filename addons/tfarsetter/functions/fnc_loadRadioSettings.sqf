#include "script_component.hpp"
/*
 * Authors: johnb43
    * Loads select radio configurations from a chosen profile.
 *
 * Arguments:
 * 0: Which radios should be loaded <ARRAY>
    * 1: Load other type of radio (only works for LR and VLR) <BOOLEAN>
    * 2: Which profile is selected <STRING>
    * 3: SR Radio <STRING>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params ["_loadFromRadios", "_loadSameType", "_profile", "_radio"];
_loadFromRadios params ["_doSR", "_doLR", "_doVLR"];

GETPRVAR(FORMAT_1(QGVAR(profile%1),_profile),[]) params ["_SR", "_LR", "_VLR", "_headsetStatus"];

private _text = "SR";

// If SR radio is specifically defined, choose that over the active SR
_radio = [_radio, call TFAR_fnc_activeSwRadio] select (_radio isEqualTo "");

// Load the side encryption. However, the radio settings in a profile will never be overwritten
private _code = tfar_radiocode_independent;

switch (side player) do {
                case east: {_code = tfar_radiocode_east};
                case west: {_code = tfar_radiocode_west};
                default {};
};

// If the SR settings should be loaded
if (_doSR) then {
                // Don't load anything if nothing is present
                if (_SR isEqualTo []) exitWith {};

                [_radio, _SR] call TFAR_fnc_setSwSettings;

                // Set side code
                [_radio, _code] call TFAR_fnc_setSwRadioCode;

                // Set the correct SR channel if FK compat mode is enabled and FKFramework is loaded
                if !(GVAR(enableCompatFK) && {!isNil {"FKF/CfgArsenalBlacklist" call Clib_fnc_getSettings}}) exitWith {};

                private _index = 8;

                // Find in which squad the player is in and change index accordingly
                switch (((str (group player)) splitString " ") select 1) do {
                                case "A": {_index = 0};
                                case "B": {_index = 1};
                                case "C": {_index = 2};
                                case "D": {_index = 3};
                                case "E": {_index = 4};
                                case "PltHQ": {_index = 5};
                                case "KNGT": {_index = 6};
                                case "RPTR": {_index = 7};
                                default {};
                };

                [_radio, _index] call TFAR_fnc_setSwChannel;
};

// If the LR settings should be loaded
if (_doLR) then {
                // Don't load anything if nothing is present
                if (_LR isEqualTo []) exitWith {};

                // If loading from a LR to a LR, saveSameType == true, if loading from VLR to LR, then not
                _radio = [player call TFAR_fnc_vehicleLR, player call TFAR_fnc_backpackLR] select _loadSameType;
                [_radio, _LR] call TFAR_fnc_setLrSettings;

                // Set side code
                [_radio, _code] call TFAR_fnc_setLrRadioCode;

                // Change text accordingly
                _text = ["LR", "SR and LR"] select _doSR;
};

// If the VLR settings should be loaded
if (_doVLR) then {
                // Don't load anything if nothing is present
                if (_VLR isEqualTo []) exitWith {};

                // If loading from a VLR to a VLR, saveSameType == true, if loading from LR to VLR, then not
                _radio = [player call TFAR_fnc_backpackLR, player call TFAR_fnc_vehicleLR] select _loadSameType;
                [_radio, _VLR] call TFAR_fnc_setLrSettings;

                // Set side code
                [_radio, _code] call TFAR_fnc_setLrRadioCode;

                // Change text accordingly
                _text = [[["VLR", "SR and VLR"] select _doSR, "LR and VLR"] select _doLR, "SR, LR and VLR"] select (_doSR && _doLR);
};

// Set the headset up or down
if (!isNil "_headsetStatus") then {
                _headsetStatus call TFAR_fnc_setHeadsetLowered;
};

[format ["Loaded %1 settings from %2", _text, _profile], ICON_LOAD] call ace_common_fnc_displayTextPicture;
