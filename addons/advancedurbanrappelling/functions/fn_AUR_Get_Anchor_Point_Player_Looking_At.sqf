params ["_player"];
private ["_rappelPoint","_intersectStartASL","_intersectStartASL","_surfaces","_lookingPosition","_surfaceNormal","_rappelPosition"];
_rappelPoint = [];
_intersectStartASL = AGLToASL positionCameraToWorld [0,0,0];
_intersectEndASL = AGLToASL positionCameraToWorld [0,0,100];
_surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, _player, objNull, true, 1, "FIRE", "NONE"];
if(count _surfaces > 0) then {
        _lookingPosition = (_surfaces select 0) select 0;
        _surfaceNormal = (_surfaces select 0) select 1;
        _intersectEndASL = _lookingPosition vectorAdd (_surfaceNormal vectorMultiply -0.8);
        _intersectStartASL = _intersectEndASL vectorAdd [0,0,2.5];
        _surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, objNull, objNull, true, 1, "FIRE", "NONE"];
        if(count _surfaces > 0) then {
                _rappelPosition =(_surfaces select 0) select 0;
                if!([_player,_rappelPosition,"FAST_EXISTS_CHECK"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point) exitWith {_rappelPoint};
                _rappelPoint = [_player,_rappelPosition,"POSITION"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point;
        };
};
_rappelPoint;