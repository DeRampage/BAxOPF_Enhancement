#include "TF47_AUR_MACROS.h"

if (AUR_GET_RAPPELLING_STATUS(player)) exitWith {False;};
_cans = (GetPosATL player) nearObjects ["Land_Can_V2_F", 2];
// systemChat str count _cans;
_ret = False;
scopeName "TF47_TieInCheck";

{
_ret2 = AUR_GET_TIE_IN_POINT_STATUS(_x);
        if (_ret2 == 1) then {_ret= True; breakTo "TF47_TieInCheck";}
        } forEach _cans;
_ret;
