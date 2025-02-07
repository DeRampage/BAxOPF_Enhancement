#include "script_component.hpp"
/*
 * Author: Ampersand
 * Edit: TF47 Rampage
 * Attach the lift points connected to the held fitting to the specified hook on the helicopter, counts the slingloads up
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Unit <OBJECT>
 * 1: Cargo Hook Position <ARRAY> <OPTIONAL>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * example:
 * [_heli, _unit] call TF47_slingload_fnc_attachCargo
 * [cursorObject, player, (cursorObject selectionPosition "slingload0") vectorAdd [0,-3,0]] call TF47_slingload_fnc_attachCargo
 */

params ["_heli", "_unit", ["_cargoHookIndex", 0]];

private _apexFitting = _unit getVariable ["TF47_slingload_heldFitting", objNull];
if (isNull _apexFitting) exitWith {false};
private _cargo = _apexFitting getVariable ["TF47_slingload_cargo4Fitting", objNull];
if (isNull _cargo) exitWith {false};
private _cargoWreck = _cargo getVariable [QGVAR(wreckDummy), objNull];
if !(isNull _cargoWreck) then {
    _cargo = _cargoWreck;
};
private _ropes4Cargo = _cargo getVariable ["TF47_slingload_ropes4Cargo", []];

private _lengths = [];
{
    _lengths pushBack (_x getVariable ["TF47_slingload_ropeLength", 10]);
    ropeDestroy _x;
} forEach ropes _apexFitting;
_ropes4Cargo = _ropes4Cargo - [objNull];

private _liftPoints = _apexFitting getVariable ["TF47_slingload_points4Fitting", []];

_apexFitting setVariable ["TF47_slingload_cargo4Fitting", objNull, true];
deleteVehicle _apexFitting;

private _cargoHookName = [
    "TF47_slingload_cargoHookMain",
    "TF47_slingload_cargoHookForward",
    "TF47_slingload_cargoHookAft"
] select _cargoHookIndex;

private _heliModel = getText (configOf _heli >> "model");
private _cargoHookPosition = if (_heliModel in TF47_customHooks) then {
    private _customHooksInfo = TF47_customHooks get _heliModel;
    _customHooksInfo select _cargoHookIndex
} else {
    _heli selectionPosition "slingload0"
};

private _ropes4Hook = _heli getVariable [_cargoHookName, []];
{
    private _rope = ropeCreate [_heli, _cargoHookPosition, _cargo, _x, _lengths select _forEachIndex, ["", [0,0,-1]], ["RopeEnd", [0,0,-11]]];
    _rope setVariable ["TF47_slingload_point4Rope", _x, true];
    _ropes4Hook pushBack _rope;
    _ropes4Cargo pushBack _rope;
} forEach _liftPoints;

_heli setVariable [_cargoHookName, _ropes4Hook - [objNull], true];
_cargo setVariable ["TF47_slingload_ropes4Cargo", _ropes4Cargo - [objNull], true];

["TF47_slingload_localise", [_heli]] call CBA_fnc_serverEvent;

true
