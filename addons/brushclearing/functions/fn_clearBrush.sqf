#include "script_component.hpp" 
/* 
* Author: Ampersand, johnb43
* Edit: Rabbit, Rampage
* Place a grass cutter. 
* 
* Arguments: 
* 0: Unit trying to clear brush <OBJECT> 
* If unit is a player, unit must be local. 
* 
* Return Value: 
* Object that was cut down, grass cutter or objNull if nothing was found <OBJECT> 
* 
* Example: 
* [player] call abc_main_fnc_clearBrush 
*/ 
 
params ["_unit"];  
//_unit = player;

// Check if unit is a player 
private _startPos = if (isPlayer _unit) then { 
    AGLToASL positionCameraToWorld [0, 0, 0] 
} else { 
    eyePos _unit 
}; 
 
// Check 7m in front of unit if there is an object 
private _intersections = lineIntersectsSurfaces [_startPos, _startPos vectorAdd ((getCameraViewDirection _unit) vectorMultiply 7), _unit]; 
 
if (_intersections isEqualTo []) exitWith {objNull}; 
 
(_intersections # 0) params ["_intersectPosASL", "", "_intersectObj", "_parentObject"]; 
 
// Play gesture 
["ace_common_playActionNow", [_unit, "ace_gestures_cover"], _unit] call CBA_fnc_targetEvent; 
 
// If terrain, spawn grass cutter 
if (isNull _intersectObj && {isNull _parentObject}) then { 
    [3,  
    _intersectPosASL,  
    {   
        params["_intersectPosASL"];       
        private _existing_small = _intersectPosASL nearestObject "Land_ClutterCutter_small_F";
        private _existing_med = _intersectPosASL nearestObject "Land_ClutterCutter_medium_F";
        private _distance = 1;    
        private _cutter = "Land_ClutterCutter_small_F";    
        if (!isNull _existing_small) then {    
            _distance = _existing_small distance _intersectPosASL;
            //systemChat "Small existiert";
            //systemChat str _distance;
            if (_distance < 3) then {    
                _cutter = "Land_ClutterCutter_medium_F"; 
            };  
        };   
        if (!isNull _existing_med) then {    
            _distance = _existing_med distance _intersectPosASL;
            //systemChat "Medium existiert";
            //systemChat str _distance;  
            if (_distance < 5) then {    
                _cutter = "Land_ClutterCutter_large_F";  
            };  
        }; 
        //systemChat _cutter;    
        createVehicle [_cutter, ASLtoAGL _intersectPosASL, [], 0, "CAN_COLLIDE"];   
    },   
    {},   
    "Cut Grass/Bush"] call ace_common_fnc_progressBar; 
}; 
