#include "script_component.hpp"
/*
 * Author: johnb43
 * Makes all subentries of the interaction menu for loading from profiles.
 *
 * Arguments:
 * 0: Arguments from interaction <ARRAY>
 * 1: Radio types to be loaded from <ARRAY>
 * 2: Load other type of radio (only works for LR and VLR) <BOOLEAN>
 * If arg#2 is set to true, it will load the same type of radio (LR -> LR, VLR -> VLR). If false, not the same type (LR -> VLR, VLR -> LR).
 * 3: SR Radio <STRING> (optional)
 *
 * Return Value:
 * All interaction submenus for loading from all profiles <ARRAY>
 *
 * Public: No
 */

params ["_player", "_radioLoadTypes", "_loadSameType", ["_radio", "", [""]]];

private _profileNames = GETPRVAR(QGVAR(profileNames),[]);

// If there are no profiles, exit
if (_profileNames isEqualTo []) exitWith {[]};

private _menus = [];

// Make menus
{
    _menus pushBack [[
        format [GVAR(profileLoad%1), _x], // Action name
        _x, // Display name
        "", // Icon
        { // Statement
            // All action parameters are passed. Needs to be scheduled because of BIS_fnc_guiMessage
            (_this select 2) spawn {
                // Wait for confimation or setting is not enabled
                if (!GVAR(askLoadConfirmation) || {[format ["Are you sure you want to load from profile '%1'?", _this select 2], "Confirmation", "Yes", "No"] call BIS_fnc_guiMessage}) then {
                    _this call FUNC(loadRadioSettings);
                };
            };
        },
        { // Condition
            GETPRVAR(FORMAT_1(QGVAR(profile%1),_this select 2 select 2),[]) params ["_SR", "_LR", "_VLR"];
            (_this select 2 select 0) params ["_doSR", "_doLR", "_doVLR"];

            // Do not show load options from profiles where radios in question are not defined
            (!_doSR || {_SR isNotEqualTo []}) && {!_doLR || {_LR isNotEqualTo []}} && {!_doVLR || {_VLR isNotEqualTo []}};
        },
        nil, // Children actions
        [_radioLoadTypes, _loadSameType, _x, _radio] //Action parameters
    ] call ace_interact_menu_fnc_createAction, [], _player];
} forEach _profileNames;

_menus;
