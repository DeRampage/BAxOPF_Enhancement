#include "TF47_AUR_MACROS.h"
params ["_player","_rappelPoint","_ropeLength"];
//hint format ["Player: %1 \nPre_rappel_position: %2, \nRappelPoint: %3 \n RappelDirection: %4,\n RopeLength: %5.", str _player,str  _playerPreRappelPosition,str _rappelPoint, str _rappelDirection,str  _ropeLength];
// _player setVariable ["AUR_Is_Rappelling",true,true];

// systemChat "Attaching rope...";

_master = createVehicle ["B_static_AA_F", _rappelPoint, [], 0, "CAN_COLLIDE"];
AUR_SET_MASTER(_player, _master);
AUR_SET_MASTER(_master, _master);
// _master setPosWorld (getPosASL _rappelPoint vectorAdd [0,0,0]);
_anchor2 = createVehicle ["Land_Can_V2_F", _player, [], 0, "CAN_COLLIDE"];
AUR_SET_MASTER(_anchor2, _master);
AUR_SET_ENDPOINT_LEADER(_player, _anchor2);
_ropeClassName = "";
switch (_ropeLength) do {
    case 30: { _ropeClassName = "AUR_rope30";};
    case 40: { _ropeClassName = "AUR_rope40";};
    case 50: { _ropeClassName = "AUR_rope50";};
    case 60: { _ropeClassName = "AUR_rope60";};
    case 80: { _ropeClassName = "AUR_rope80";};
    case 100: { _ropeClassName = "AUR_rope100";};
    default { _ropeClassName = "AUR_rope100";};
};

_player  removeItem _ropeClassName;
_rope = ropeCreate [_master, [0,0,-1.5],_anchor2, [0,0,0],_ropeLength];
AUR_SET_MASTER(_rope, _master);
AUR_SET_ROPE_LEADER(_master,_rope);
AUR_SET_ROPE_LENGTH(_player, _ropeLength);

[_player,"Prepare_Rope"] call TF47_fnc_AUR_Has_Rope_Check; //Set the Variables
// hideObject anchor;
// anchor enableSimulation false;
// anchor allowDamage false;

[[_master],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
_rope allowDamage false;
_anchor2 attachTo [_player,[0,0,0],"lefthand"];
// systemChat "setting vars";
AUR_SET_STATUS_HOLDING_ROPE(_player, True);


