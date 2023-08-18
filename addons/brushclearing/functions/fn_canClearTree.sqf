/*
Author: Ampersand
Check if it's destroy tree or cut grass.

* Arguments:
* 0: Unit trying to tag <OBJECT>
*
* Return Value:
* -

* Example:
* [player] call clearTree_fnc_canclearTree
*/

params ["_player"];

if (!alive _player) exitWith {false};
if !([_player, objNull, ["isNotDragging", "isNotCarrying", "isNotSwimming"]] call ace_common_fnc_canInteractWith) exitWith {false};

if (
    clearTree_requireAxe &&
    {!("bunwell_axe" in (_player call ace_common_fnc_uniqueItems))}
) exitWith {false};

// Check if unit is a player
private _isPlayer = isPlayer _player;

if !([_player] call ace_common_fnc_canDig) exitWith {false};

if (_isPlayer && {!local _player}) exitWith {false};

private _startPos = if (_isPlayer) then {
    AGLToASL positionCameraToWorld [0, 0, 0]
} else {
    eyePos _player
};

// Check 7m in front of unit if there is an object
private _intersections = lineIntersectsSurfaces [_startPos, _startPos vectorAdd ((getCameraViewDirection _player) vectorMultiply 7), _player];

if (_intersections isEqualTo []) exitWith {false};

(_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObj", "_parentObject"];

//not terrain
if !((nearestTerrainObjects [ _intersectObj , ["TREE", "SMALL TREE", "BUSH"], 10]) isEqualTo [] ) exitWith {true};
//terrain
if (_intersectObj isEqualTo objNull && {_parentObject isEqualTo objNull}) exitWith {false}; 
