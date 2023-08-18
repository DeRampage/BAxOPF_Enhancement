/*  
* Author: Ampers  
* Edit: Rabbit, Rampage  
* Destroy a Tree
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
private _position1 = AGLToASL positionCameraToWorld [0, 0, 10];  
   
private _intersections = lineIntersectsSurfaces [_position0, _position1, cameraOn, objNull, true, 1, "VIEW"];   
   
if (_intersections isEqualTo []) exitWith {};  
  
(_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObj", "_parentObject"];  
   
if !((nearestTerrainObjects [ _intersectObj , ["TREE", "SMALL TREE", "BUSH"], 10]) isEqualTo [] ) then {
    [5,	
    [_intersectObj],	
    {  
    params ["_intersectObj"];  
    _intersectObj#0 setDamage 1;	
    if (clearTree_hidetree) then {  
        [_intersectObj] spawn   
        {  
        params ["_intersectObj"];
        _intersectObj#0 hideObjectGlobal true;   
        };  
    };  
    },  
    {hint "Cancelled tree cutting"},  
    "Cut Tree"] call ace_common_fnc_progressBar;  
};
(_intersections # 0)  
