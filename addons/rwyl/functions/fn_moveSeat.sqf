#include "script_component.hpp"
/*
Author: Ampers
Move unit into vehicle seat near center of view

* Arguments:
* 0: Unit <OBJECT>
*
* Return Value:
* -

* Example:
* [player] call TF47_rwyl_fnc_moveSeat
*/

params ["_unit"];

if (isNull TF47_rwyl_vehicle) exitWith {}; // no vehicle

if (TF47_rwyl_isSeatTaken || {TF47_rwyl_isSeatLocked}) then {
    TF47_rwyl_proxy = ""; // Move into other empty seat
} else {
    if (isNil "TF47_rwyl_proxy") then {
        private _sn = selectionNames TF47_rwyl_vehicle select {
            private _proxy = toLower _x;
            private _proxyIndex = _proxy select [(_proxy find ".") + 1];
            // has non-zero selection position
            !((TF47_rwyl_vehicle selectionPosition [_proxy, "FireGeometry", "AveragePoint"]) isEqualTo [0,0,0]) && {
            // ends with a number after a period
            ((parseNumber _proxyIndex > 0) || {_proxyIndex isEqualTo "0"}) && {
            // contains seat role
            (("cargo" in toLower _proxy) || {("gunner" in toLower _proxy) || {("driver" in toLower _proxy) ||
            {("commander" in toLower _proxy) || {("pilot" in toLower _proxy)}}}})}}
        };

        //"no cargo proxies found in selectionNames"
        if (_sn isEqualTo []) exitWith {false};

        private _sp = _sn apply {TF47_rwyl_vehicle selectionPosition [_x, "FireGeometry", "AveragePoint"]};

        private _screenPosArray = _sp apply {
            private _w2s = worldToScreen (TF47_rwyl_vehicle modelToWorld _x);
            if (_w2s isEqualTo []) then {
                1000
            } else {
                ([getMousePosition, [0.5,0.5]] select (isNull curatorCamera && {isNil "ace_interact_menu_openedMenuType"})) distance2D _w2s
            };
        };

        TF47_rwyl_proxy = _sn # (_screenPosArray findIf {_x == selectMin _screenPosArray});
    };
};

// Check for drag, carry, escort
if (isClass (configFile >> "CfgPatches" >> "ace_main")) then {
    private _draggedUnit = _unit getVariable ["ace_dragging_draggedObject", objNull];
    if (!isNull _draggedUnit && {_draggedUnit isKindOf "CAManBase"}) then {
        [_unit, _draggedUnit] call ace_dragging_fnc_dropObject;
        _unit = _draggedUnit;
    } else {
        private _carriedUnit = _unit getVariable ["ace_dragging_carriedObject", objNull];
        if (!isNull _carriedUnit && {_carriedUnit isKindOf "CAManBase"}) then {
            [_unit, _carriedUnit] call ace_dragging_fnc_dropObject_carry;
            _unit = _carriedUnit;
        } else {
            private _escortedUnit = _unit getVariable ["ace_captives_escortedUnit", objNull];
            if (!isNull _escortedUnit) then {
                [_unit, _escortedUnit, false] call ace_captives_fnc_doEscortCaptive;
                _unit = _escortedUnit;
            };
        };
    };
};

private _currentVehicle = vehicle _unit;
private _isSameVehicle = TF47_rwyl_vehicle == _currentVehicle;
// If same vehicle and selected seat is taken/locked then do nothing
if (TF47_rwyl_proxy == "" && {_isSameVehicle}) exitWith {
    TF47_rwyl_vehicle = objNull;
    TF47_rwyl_proxy = nil;

    false
};

// If same vehicle then enable moveToSeat actions
private _effectiveCommander = effectiveCommander _currentVehicle;
if (_isSameVehicle && {_effectiveCommander != _unit}) then {
    _currentVehicle setVariable ["TF47_rwyl_effectiveCommander", _effectiveCommander, true];
    ["TF47_rwyl_setEffectiveCommander", [_currentVehicle, _unit]] call CBA_fnc_globalEvent;
};

["TF47_rwyl_moveSeatLocal", [_unit, TF47_rwyl_vehicle, TF47_rwyl_proxy], _unit] call CBA_fnc_targetEvent;

TF47_rwyl_vehicle = objNull;
TF47_rwyl_proxy = nil;

true
