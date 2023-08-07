#include "script_component.hpp"
/*
 * Authors: johnb43
    * Creates a new profile.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

["Create/Import Radio Preset", [
    ["EDIT", ["Preset name", "Allows you to store multiple radio presets. If you use whitespaces, it will remove those. Profiles names are case insensitive. DO NOT USE PUNCTUATION MARKS."], "", true],
    ["EDIT", ["Preset settings", "Paste radio preset here, if you are importing. Leave blank if you are creating a new profile."], "", true]
],
{
    params ["_results"];
    _results params ["_preset", "_settings"];

    // Remove whitespaces
    _preset = _preset splitString " " joinString "";

    // If the new preset is invalid, then quit
    if (_preset isEqualTo "") exitWith {};

    // If settings are left to default, add default preset; otherwise make string into array
    _settings = parseSimpleArray (["[[], [], [], false]", _settings] select (_settings isNotEqualTo ""));

    // Set the UID on the SR (only required for SR). Done as a precaution if the imported profile comes from another player
    if ((_settings select 0) isNotEqualTo []) then {
        (_settings select 0) set [7, getPlayerUID player];
    };

    private _presets = GETPRVAR(QGVAR(profileNames),[]);

    // If preset isn't in preset list, add it. Make everything lowercase for string comparison
    if !((toLower _preset) in (_presets apply {toLower _x})) then {
        _presets pushBack _preset;
        SETPRVAR(QGVAR(profileNames),_presets);
        SETPRVAR(FORMAT_1(QGVAR(profile%1),_preset),_settings);
    } else {
        // If preset is already in the list, it's going to overwrite it. Ask for confirmation if necessary. Needs to be scheduled because of BIS_fnc_guiMessage
        [_preset, _settings] spawn {
            params ["_preset", "_settings"];
            // Wait for confimation or setting is not enabled
            if (!GVAR(askDeleteConfirmation) || {[format ["Are you sure you want to overwrite profile '%1'?", _preset], "Confirmation", "Yes", "No"] call BIS_fnc_guiMessage}) then {
                // Overwrite profile
                SETPRVAR(FORMAT_1(QGVAR(profile%1),_preset),_settings);
            };
        };
    };
}, {}] call zen_dialog_fnc_create;
