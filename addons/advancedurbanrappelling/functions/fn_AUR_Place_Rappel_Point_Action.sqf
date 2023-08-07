#include "TF47_AUR_MACROS.h"

params ["_player"];
_oldRope = AUR_GET_ROPE_LEADER(_player);
// systemChat str _oldRope;
ropeDestroy _oldRope;
deleteVehicle (_player getVariable "TF47_AUR_RopeEndObject");


_dummyAnchor = _player getVariable "TF47_AUR_AnchorObject";
// hideObject _anchor;
// _anchor enableSimulation false;
// _anchor allowDamage false;
// [[_anchor],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;

// Create anchor for rope (at rappel point)
// _dummyAnchor2 = createVehicle ["Land_Can_V2_F", _player, [], 0, "CAN_COLLIDE"];
// hideObject _dummyAnchor2;
// _dummyAnchor2 enableSimulation false;
// _dummyAnchor2 allowDamage false;
// [[_dummyAnchor2],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;



_master = AUR_GET_MASTER(_player);
_leaderEndpoint = AUR_GET_ENDPOINT_LEADER(_player);
AUR_SET_TIE_IN_POINT_STATUS(_leaderEndpoint, 1);
AUR_SET_MASTER(_leaderEndpoint,( AUR_GET_MASTER(_player)));
// AUR_SET_STATUS_ROPE(_leader);
AUR_SET_ENDPOINT_LEADER(_player, _leaderEndpoint);
detach (AUR_GET_ENDPOINT_LEADER(_player));
(AUR_GET_ENDPOINT_LEADER(_player)) setPosASL (getPosASL _player);
//create leader rope, reusing the master anchor, and the leader endpoint created earlier
_leader = ropeCreate [_master, [0,0,-1.5],_leaderEndpoint,[0,0,0]];
_leader allowDamage false;
// systemChat str _leader;
AUR_SET_MASTER(_leader,( AUR_GET_MASTER(_player)));
// AUR_SET_STATUS_ROPE(_leader);
AUR_SET_ROPE_LEADER(_player, _leader);
// AUR_SET_LENGTH_LEADER(_player, (ropeLength _leader));

_ropeLength = AUR_GET_LENGTH_AVAILABLE(_player);

_anchorRopeLength = ropeLength _leader;
// systemChat str _anchorRopeLength;

_bottomRopeStartLength = _ropeLength - 1;
_topRopeStartLength = _ropeLength - _anchorRopeLength;
// systemChat str _topRopeStartLength;


_endpointTop = createVehicle ["Land_Can_V2_F", getPosASL _leaderEndpoint, [], 0, "CAN_COLLIDE"];
// hideObject _endpointTop;
// _endpointTop enableSimulation false;
_endpointTop allowDamage false;
_endpointTop setPosASL (getPosASL AUR_GET_ENDPOINT_LEADER(_player));
AUR_SET_ENDPOINT_TOP(_player, _endpointTop);
AUR_SET_TIE_IN_POINT_STATUS(_endpointTop, 2); //allow tieing in near this point (at top)
AUR_SET_MASTER(_endpointTop, AUR_GET_MASTER(_player));
_rappelDevice = createVehicle ["B_static_AA_F",  AUR_GET_ENDPOINT_LEADER(_player), [], 0, "CAN_COLLIDE"];
AUR_SET_MASTER(_rappelDevice, AUR_GET_MASTER(_player));
AUR_SET_RAPPEL_DEVICE(_player, _rappelDevice);
hideObject _rappelDevice;
// _rappelDevice enableSimulation false;
_rappelDevice allowDamage false;

_ropeTop = ropeCreate [_rappelDevice, [0, 0, -1.5],_endpointTop, [0,0,0], _topRopeStartLength ];
AUR_SET_MASTER(_ropeTop, AUR_GET_MASTER(_player));
AUR_SET_STATUS_ROPE(_ropeTop, True);
AUR_SET_ROPE_TOP(_player, _ropeTop);

_endpointTop setVelocity ((vectorDir player) vectorMultiply 5);

_ropeTop allowDamage false;
// systemChat str ropeLength _ropeTop;

AUR_SET_STATUS_HOLDING_ROPE(_player, False);
AUR_ON_DISCONNECT(_player);