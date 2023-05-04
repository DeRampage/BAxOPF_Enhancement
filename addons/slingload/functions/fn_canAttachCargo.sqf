#include "script_component.hpp"
/*
 * Author: Ampersand
 * Edit: TF47 Rampage
 * check if unit is able to adjust the length of the rope for the hook and less than 3 Loads are connected
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli, _unit] call TF47_slingload_fnc_canAttachCargo
 * [cursorObject, ACE_player] call TF47_slingload_fnc_canAttachCargo
 */

params ["_heli", "_player"];

if (typeOf _heli isEqualTo "TF47_slingload_apexFitting") exitWith { false };

!isNull (_player getVariable ["TF47_slingload_heldFitting", objNull])
&& {
    private _cfg = configOf _heli;
    getText (_cfg >> "model") in TF47_customHooks
    || {getNumber (_cfg >> "slingLoadMaxCargoMass") > 0}
}
