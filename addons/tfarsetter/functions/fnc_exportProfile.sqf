#include "script_component.hpp"
/*
 * Authors: johnb43
 * Export a profile to the clipboard.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

["Export Radio Preset", [
    ["COMBO", ["Export Radio Preset", "Allows you to select a preset to export to the clipboard."], [GETPRVAR(QGVAR(profileNames),[]), GETPRVAR(QGVAR(profileNames),[]), 0], false]
],
{
    params ["_results"];
    _results params ["_selectedPreset"];

    private _presets = GETPRVAR(QGVAR(profileNames),[]);

    // Delete the preset from the list if it's in there
    private _index = _presets findIf {_x isEqualTo _selectedPreset};
    if (_index isEqualTo -1) exitWith {};

    private _settings = GETPRVAR(FORMAT_1(QGVAR(profile%1),_selectedPreset),[]);

    // If profile is invalid, don't copy to clipboard
    if (_settings isEqualTo []) exitWith {};

    // Copy to the clipboard
    "ace_clipboard" callExtension (str _settings + ";");
    "ace_clipboard" callExtension "--COMPLETE--";

    [format ["Profile '%1' has been copied to your clipboard.", _selectedPreset], ICON_LOAD] call ace_common_fnc_displayTextPicture;
}, {}] call zen_dialog_fnc_create;
