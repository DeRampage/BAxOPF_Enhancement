#include "script_component.hpp"
/*
 * Author: Ampersand
 * Edit: TF47 Rampage
 * release hooked cargo on a hook / all hooks
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * example:
 * [_heli, "main"] call TF47_slingload_fnc_releaseCargo
 */

params ["_heli", ["_cargoHookName", ""]];

private _hooksToRelease = [CARGOHOOKNAMES, [_cargoHookName]] select (toLower _cargoHookName in CARGOHOOKNAMES);

{
    {
        ropeDestroy _x
    } forEach (_heli getVariable ["TF47_slingload_cargoHook" + _x, []]);
    _heli setVariable ["TF47_slingload_cargoHook" + _x, [], true];
} forEach _hooksToRelease;
