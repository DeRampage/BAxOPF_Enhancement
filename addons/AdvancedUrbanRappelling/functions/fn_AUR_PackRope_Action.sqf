#include "TF47_AUR_MACROS.h"
/*
*   Author: Tirpitz
*   Packs up rope and places item on ground if rope items present

*/

params [["_player", player]];
_length = AUR_GET_ROPE_LENGTH(_player);

_ropeClassName = "";
switch (_length) do {
    case 30: { _ropeClassName = "AUR_rope30";};
    case 40: { _ropeClassName = "AUR_rope40";};
    case 50: { _ropeClassName = "AUR_rope50";};
    case 60: { _ropeClassName = "AUR_rope60";};
    case 80: { _ropeClassName = "AUR_rope80";};
    case 100: { _ropeClassName = "AUR_rope100";};
    default { _ropeClassName = "AUR_rope100";};
};

if (_player canAdd _ropeClassName) then {
     _player addItem _ropeClassName;
} else {
_groundHolder = createVehicle ["WeaponHolderSimulated", player,[],0,"CAN_COLLIDE"];
_groundHolder addWeaponCargoGlobal [_ropeClassName, 1];
};
//clean UP, at this point there should only be 1 rope and its anchor and endpoint.
deleteVehicle  AUR_GET_ENDPOINT_LEADER(_player);   
ropeDestroy  AUR_GET_ROPE_LEADER(_player);
_master = AUR_GET_MASTER(_player);
AUR_SET_STATUS_HOLDING_ROPE(_player, False);
AUR_ON_DISCONNECT(_player);
deleteVehicle _master;

