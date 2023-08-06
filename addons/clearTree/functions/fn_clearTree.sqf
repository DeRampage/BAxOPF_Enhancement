/*
* Author: Ampers
  Edit: Rabbit
* Destroy a Tree or place a grass cutter
*
* Arguments:
* -
*
* Return Value:
* -
*
* Example:
* [] call clearTree_fnc_clearTree
*/

private _position0 = AGLToASL positionCameraToWorld [0, 0, 0]; 
private _position1 = AGLToASL positionCameraToWorld [0, 0, 2];
_delay = 10; 
 
private _intersections = lineIntersectsSurfaces [_position0, _position1, cameraOn, objNull, true, 1, "VIEW"]; 
 
if (_intersections isEqualTo []) exitWith {};

(_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObj", "_parentObject"];

if (_intersectObj isEqualTo objNull && {_parentObject isEqualTo objNull}) then {
    //terrain, spawn grass cutter
    createVehicle ["Land_ClutterCutter_small_F", ASLtoAGL _intersectPosASL, [], 0, "CAN_COLLIDE"];
} else {
    //not terrain
    if !((nearestTerrainObjects [ _intersectObj , ["TREE", "SMALL TREE"], 10]) isEqualTo [] ) then 
    {
        //map bush, destroy
        _intersectObj setDamage 1;
            
            
        if (clearTree_hidetree) then 
        {
        [_intersectObj] spawn 
                {
                params ["_intersectObj"];
                sleep 10;
                _intersectObj hideObjectGlobal true; 
                };
        };
}; };
(_intersections # 0)