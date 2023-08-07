#include "TF47_AUR_MACROS.h"

/*
* Author Tirpitz
* Cleans up after a rappel detach (either by detach rappel device action or climb to top)
*   params: _player, the unit to disconnect from the system.
*/

params ["_player"];
diag_log "Cleanup_after";
diag_log str _player;
_totalLength = AUR_GET_ROPE_LENGTH(_player);
// systemChat format ["Total Length: %1",_totalLength];

deleteVehicle AUR_GET_RAPPEL_DEVICE(_player);

ropeDestroy AUR_GET_ROPE_TOP(_player);
ropeDestroy AUR_GET_ROPE_BOTTOM(_player);

_rappelDevice = createVehicle ["B_static_AA_F", AUR_GET_ENDPOINT_LEADER(_player), [], 0, "CAN_COLLIDE"];
AUR_SET_MASTER(_rappelDevice, AUR_GET_MASTER(_player));
AUR_SET_RAPPEL_DEVICE(_player, _rappelDevice);
_rappelDevice setPosWorld (getPosWorld AUR_GET_ENDPOINT_LEADER(_player));
hideObject _rappelDevice;
// _rappelDevice enableSimulation false;
_rappelDevice allowDamage false;
_endpointTop = createVehicle ["Land_Can_V2_F", _player, [], 0, "CAN_COLLIDE"];
// hideObject _endpointTop;
// _endpointTop enableSimulation false;
_endpointTop allowDamage false;
// _endpointTop setPosWorld (getPosWorld AUR_GET_ENDPOINT_LEADER(_player));
AUR_SET_MASTER(_endpointTop, AUR_GET_MASTER(_player));
AUR_SET_TIE_IN_POINT_STATUS(_endpointTop, 2); //allow tieing in near this point (on the ground)
AUR_SET_ENDPOINT_TOP(_player, _endpointTop);


_ropeTop = ropeCreate [_rappelDevice, [0, 0, 0],_endpointTop, [0,0,0], AUR_GET_LENGTH_AVAILABLE(_player) ];
AUR_SET_MASTER(_ropeTop, AUR_GET_MASTER(_player));
AUR_SET_STATUS_ROPE(_ropeTop, True);
AUR_SET_ROPE_TOP(_player, _ropeTop);

_endpointTop setVelocity ((vectorDir player) vectorMultiply -5);
AUR_ON_DISCONNECT(_player); //disconnect player from system



