#include "script_component.hpp"
/*
 * Authors: johnb43
    * Saves select radio configurations to a chosen profile.
 *
 * Arguments:
 * 0: Which radios should be saved <ARRAY>
    * 1: Load other type of radio (only works for LR and VLR) <BOOLEAN>
    * 2: Which profile is selected <STRING>
    * 3: SR Radio <STRING>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params ["_saveToRadios", "_saveSameType", "_profile", "_radio"];
_saveToRadios params ["_doSR", "_doLR", "_doVLR"];

// Get data from selected profile
private _data = GETPRVAR(FORMAT_1(QGVAR(profile%1),_profile),[]);
private _dataRadio = [];
private _text = "SR";

// If the SR settings should be saved
if (_doSR) then {
                _dataRadio = ([_radio, call TFAR_fnc_activeSwRadio] select (_radio isEqualTo "")) call TFAR_fnc_getSwSettings;

    // If player has no SW radio, it will reset the settings to nothing
                if (isNil "_dataRadio") then {
                                _dataRadio = [];
                };

    // Set the data in the first element
                _data set [0, _dataRadio];
};

// If the LR settings should be saved
if (_doLR) then {
                _dataRadio = (player call TFAR_fnc_backpackLR) call TFAR_fnc_getLrSettings;

    // If player has no LR radio, it will reset the settings to nothing
                if (isNil "_dataRadio") then {
                                _dataRadio = [];
                };

    // If saving from a LR to a LR, saveSameType == true, if saving from VLR to LR, then not
                _data set [[2, 1] select _saveSameType, _dataRadio];

    // Change text accordingly
                _text = ["LR", "SR and LR"] select _doSR;
};

// If the VLR settings should be saved
if (_doVLR) then {
                _dataRadio = (player call TFAR_fnc_vehicleLR) call TFAR_fnc_getLrSettings;

    // If player has no VLR radio, it will reset the settings to nothing
                if (isNil "_dataRadio") then {
                                _dataRadio = [];
                };

    // If saving from a VLR to a VLR, saveSameType == true, if saving from LR to VLR, then not
                _data set [[1, 2] select _saveSameType, _dataRadio];

    // Change text accordingly
                _text = [[["VLR", "SR and VLR"] select _doSR, "LR and VLR"] select _doLR, "SR, LR and VLR"] select (_doSR && _doLR);
};

// Save whether headset is down or up
_data set [3, missionNamespace getVariable ["TFAR_core_isHeadsetLowered", false]];

SETPRVAR(FORMAT_1(QGVAR(profile%1),_profile),_data);

[format ["Saved %1 settings to %2", _text, _profile], ICON_SAVE] call ace_common_fnc_displayTextPicture;
