#include "TF47_AUR_MACROS.h"

if (AUR_GET_RAPPELLING_STATUS(player)) exitWith {False;};
if !("AUR_BelayDevice" in (_player call ace_common_fnc_uniqueItems)) exitWith {false};  //only with a belay device u can rappell
private _ropes = (GetPosATL player) nearObjects ["Land_Can_V2_F", 2];
//systemChat str count _ropes;
private _ret = False;

//needs performance
scopeName "TF47_TieInCheck";

{
        _ret2 = _x getVariable ["TF47_AUR_IS_TIE_IN_POINT", 0];
        if (_ret2 > 0) then {_ret= True; breakTo "TF47_TieInCheck";}
} forEach _ropes;

_ret;
