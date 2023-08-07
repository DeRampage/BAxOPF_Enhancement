#include "TF47_AUR_MACROS.h"

params ["_player", "_length"];
if (AUR_GET_STATUS_HOLDING_ROPE(_player)) exitWith {false};
//if !(_player call TF47_fnc_AUR_Has_Rope_Check) exitWith {false};

//rework needed
_ropeClassName = "";
switch (_length) do {
    case 30: { _ropeClassName = "AUR_rope30";};
    case 40: { _ropeClassName = "AUR_rope40";};
    case 50: { _ropeClassName = "AUR_rope50";};
    case 60: { _ropeClassName = "AUR_rope60";};
    case 80: { _ropeClassName = "AUR_rope80";};
    case 100: { _ropeClassName = "AUR_rope100";};
};
if (_ropeClassName in items player) exitWith {True};