/*
 * Author: Ampersand
 * Checks if a unit can deploy a door wedge.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Can deploy <BOOL>
 *
 * Example:
 * [ACE_player] call TF47_wedge_fnc_canDeployDoorWedge
 *
 * Public: No
 */

params ["_unit"];

//do you have a wedge?
if !("AMP_Door_Wedge" in items _unit) exitWith {false};

//how about only near a door??
private _position0 = eyePos _unit;
private _position1 = _position0 vectorAdd (eyeDirection _unit vectorMultiply 2);

private _intersections = lineIntersectsSurfaces [_position0, _position1, _unit, objNull, true, 1, "GEOM"];

if (_intersections isEqualTo []) exitWith {false};

private _intersectPosASL = _intersections select 0 select 0;
private _surfaceNormal = _intersections select 0 select 1;
private _house = _intersections select 0 select 2;

// shithouse is bugged
if (typeOf _house == "") exitWith {false};

_intersections = [_house, "GEOM"] intersect [ASLToAGL _position0, ASLToAGL _position1];

private _door = toLower (_intersections select 0 select 0);

if (isNil "_door") exitWith {false};

true;
