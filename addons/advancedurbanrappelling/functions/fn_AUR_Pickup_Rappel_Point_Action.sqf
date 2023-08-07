#include "TF47_AUR_MACROS.h"
/*
* Author: Tirpitz
* 
* Short: picks up rappel point and picks up rope into players hand ready to be re dedeployed, or packed up.
*
* Params: _player: the unit doing th picking up
*
* Example [_player] call TF47_fnc_AUR_Pickup_Rappel_Point_Action;
*/

params ["_player"];

_cans = (GetPosATL player) nearObjects ["Land_Can_V2_F", 2];
// systemChat str count _cans;
_can = False;
scopeName "TF47_TieInCheck";

{
_ret2 = AUR_GET_TIE_IN_POINT_STATUS(_x);
        if (_ret2 == 1) then {_can= _x; breakTo "TF47_TieInCheck";}
        } forEach _cans;

_master = AUR_GET_MASTER(_can);
AUR_SET_MASTER(_player, _master);

//cleanup When picking up a rappel point there should be two ropes and 4 objects, 2 can be reused
ropeDestroy AUR_GET_ROPE_LEADER(_player);
ropeDestroy AUR_GET_ROPE_TOP(_player);
deleteVehicle AUR_GET_RAPPEL_DEVICE(_player);
deleteVehicle AUR_GET_ENDPOINT_TOP(_player);

_ropeLength = AUR_GET_ROPE_LENGTH(_player); //total rope length

_leaderEndpoint = AUR_GET_ENDPOINT_LEADER(_player);
AUR_SET_TIE_IN_POINT_STATUS(_leaderEndpoint, 0); //this is no longer a valid tie in point
// AUR_SET_STATUS_ROPE(_leader);




AUR_GET_ENDPOINT_LEADER(_player) attachTo [_player,[0,0,0],"lefthand"];

_ropeLeader = ropeCreate [_master, [0, 0, -1.5],AUR_GET_ENDPOINT_LEADER(_player), [0,0,0], _ropeLength ];
AUR_SET_MASTER(_ropeLeader, AUR_GET_MASTER(_player));
AUR_SET_STATUS_ROPE(_ropeLeader, True);
AUR_SET_ROPE_LEADER(_player, _ropeLeader);
_ropeLeader allowDamage false;
// systemChat str ropeLength _ropeLeader;

AUR_SET_STATUS_HOLDING_ROPE(_player, True);
