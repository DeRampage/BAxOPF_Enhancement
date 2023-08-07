#include "script_component.hpp"
/*
 * Authors: johnb43
    * Deletes a chosen profile.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

["Delete Radio Preset", [
    ["COMBO", ["Delete Radio Preset", "Allows you to select a preset to delete."], [GETPRVAR(QGVAR(profileNames),[]), GETPRVAR(QGVAR(profileNames),[]), 0], false]
],
{
    params ["_results"];
    _results params ["_selectedPreset"];

    // Needs to be scheduled because of BIS_fnc_guiMessage
    _selectedPreset spawn {
        // Wait for confimation or setting is not enabled
        if (!GVAR(askDeleteConfirmation) || {[format ["Are you sure you want to delete profile '%1'?", _this], "Confirmation", "Yes", "No"] call BIS_fnc_guiMessage}) then {
            // Set the profile to nil to delete variable
            SETPRVAR(FORMAT_1(QGVAR(profile%1),_this),nil);

            private _presets = GETPRVAR(QGVAR(profileNames),[]);

            // Delete the preset from the list if it's in there
            private _index = _presets findIf {_x isEqualTo _this};
            if (_index isEqualTo -1) exitWith {};

            _presets deleteAt _index;
            SETPRVAR(QGVAR(profileNames),_presets);
        };
    };
}, {}] call zen_dialog_fnc_create;
