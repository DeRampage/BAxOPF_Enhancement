#include "script_component.hpp"
/*
Author: Ampers
PFH to show which exit the player is looking at

* Arguments:
* None
*
* Return Value:
* None

* Example:
* [] call TF47_dwyl_fnc_showExits
*/

if !(isNull curatorCamera) exitWith {};

private _vehicle = vehicle player;
if (_vehicle == player) exitWith {};

private _sp = [_vehicle] call TF47_dwyl_fnc_getExits;

dwyl_exit_position = nil;

TF47_dwyl_colour = ["IGUI", "TEXT_RGB"] call BIS_fnc_displayColorGet;
TF47_dwyl_colour_faded = [
    TF47_dwyl_colour select 0,
    TF47_dwyl_colour select 1,
    TF47_dwyl_colour select 2,
    (TF47_dwyl_colour select 3) / 2
];

dwyl_exit_pfh_running = true;

[{
    params ["_args", "_pfID"];
    _args params ["_vehicle", "_sp"];
    if (!dwyl_exit_pfh_running || {vehicle player == player}) exitWith {
        dwyl_exit_pfh_running = false;
        [_pfID] call CBA_fnc_removePerFrameHandler;
    };

    private _indexClosest = [_vehicle, _sp] call TF47_dwyl_fnc_findLookedAt;
    dwyl_exit_position = _sp select _indexClosest;

    {
        private _isSelected = _forEachIndex == _indexClosest;
        private _colour = [TF47_dwyl_colour_faded, TF47_dwyl_colour] select _isSelected;
        private _size = [ICON_SIZE_NOTSELECTED, ICON_SIZE_SELECTED] select _isSelected;
        drawIcon3D ["a3\ui_f\data\IGUI\Cfg\Actions\getout_ca.paa", _colour, _vehicle modelToWorldVisual _x, _size, _size, 0, ""];
    } forEach _sp;
}, 0, [_vehicle, _sp]] call CBA_fnc_addPerFrameHandler;
