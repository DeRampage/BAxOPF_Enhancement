#include "script_component.hpp"
/*
 * Author: johnb43
 * Adds all SR to the menu for saving self-interactions.
 *
 * Arguments:
 * 0: Player <OBJECT>
 *
 * Return Value:
 * All interaction submenus of SR <ARRAY>
 *
 * Public: No
 */

params ["_player"];

private _menus = [];

// Make menus for each SR
{
    _menus pushBack [[
        format [QGVAR(interactSavingSR%1), _x], // Action name
        [_x, "displayName", ""] call TFAR_fnc_getWeaponConfigProperty, // Display name
        [_x, "picture", ""] call TFAR_fnc_getWeaponConfigProperty, // Icon
        {}, // Statement
        {GVAR(enableSRInteractions)}, // Condition
        { // Children actions
            // Send player and radio information
            [_this select 2 select 0, [true, false, false], true, _this select 2 select 1] call FUNC(profileMenusSave);
        },
        [_player, _x] // Action parameters
    ] call ace_interact_menu_fnc_createAction, [], _player];
} forEach (_player call TFAR_fnc_radiosList);

_menus
