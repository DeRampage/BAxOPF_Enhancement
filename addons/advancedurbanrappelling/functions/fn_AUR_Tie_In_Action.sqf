#include "TF47_AUR_MACROS.h"

//todo tie in action from rappel function
params ["_player"];

// systemChat format ["Function File: %1","fn_AUR_tie_in_Action.sqf"];
//systemChat format ["Function: Tie In, Params: %1",_this];

_cans  = GetPosATL _player nearObjects ["Land_Can_V2_F", 2];
//systemChat format ["Number of ropes found: %1",count _cans];
_ret = False;
scopeName "TF47_RopeFinder";
_can = "";
{
_ret2 = AUR_GET_TIE_IN_POINT_STATUS(_x);
if (_ret2 > 0) then {_can = _x;  breakTo "TF47_RopeFinder";}
} forEach _cans;
_master = AUR_GET_MASTER(_can);
AUR_SET_MASTER(_player, _master);
//_length = AUR_GET_LENGTH_AVAILABLE(_player);
_length = _player getVariable ["TF47_AUR_Rope_length",0];
//clean up old rope
// _rope setVariable ["TF47_AUR_InUse", True, True];
AUR_SET_USE_STATUS(_can, True);

deleteVehicle AUR_GET_ENDPOINT_TOP(_player);
//systemChat str ((ropeEndPosition _rope) select 0);

_anchor = AUR_GET_ENDPOINT_LEADER(_player);
//systemChat format ["Anchor: %1", _anchor];
//systemChat format ["Anchor: %1", getPosASL _anchor];
//systemChat format ["Rope Length: %1", _length];
_dist = _player distance _anchor;

_topRopeStartLength = _dist;

// Create rappel device (attached to player)
_rappelDevice = (AUR_GET_RAPPEL_DEVICE(_player));
// hideObject _rappelDevice;
// _rappelDevice setPosWorld (position _player);
// _rappelDevice allowDamage false;
// [[_rappelDevice],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
ropeDestroy AUR_GET_ROPE_TOP(_player);
[[_player,_rappelDevice,_anchor],"TF47_fnc_AUR_Play_Rappelling_Sounds_Global"] call TF47_fnc_AUR_RemoteExecServer;
//systemChat  format ["Rappel Device: %1", _rappelDevice];
_bottomRopeStartLength = _length - (_dist +1);

// _ropeBottom = ropeCreate [_rappelDevice, [-0.15,0,0], _bottomRopeStartLength];
// _ropeBottom allowDamage false;
// _ropeTop = ropeCreate [_rappelDevice, [0,0.15,0], _anchor, [0, 0, 0], _dist +1];
// AUR_SET_ROPE_TOP(_player,_ropeTop) ;
// AUR_SET_ROPE_BOTTOM(_player,_ropeBottom) ;
// _ropeTop allowDamage false;
//systemChat  format ["Top Rope: %1", _ropeTop];
//systemChat  format ["Bottom Rope: %1", _ropeBottom];

_rappelDirection = [getPosASL _master, getPosASL _anchor] call BIS_fnc_vectorFromXToY;  //close enough

_onGround = False;

if (AUR_GET_TIE_IN_POINT_STATUS(_can) == 2) then {_onGround = True};
//should be using the Length u selected, not the maximum u have on yourself
[_player, getPosASL _player, getPosASL _anchor, _rappelDirection, _length, _onGround] spawn TF47_fnc_AUR_Rappel;
