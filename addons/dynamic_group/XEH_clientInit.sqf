//XEH_clientInit.sqf
#include "script_component.hpp"

if(!hasInterface) exitWith {};

#include "\a3\ui_f\hpp\defineDIKCodes.inc"

[
    "TF47 Groupmanager", 
    "TF47_groupmanager_key", 
    "Open groupmanager toggle", 
    {}, 
    {},
    [DIK_PAUSE, [false, false, false]],
    false, 
    0
] call CBA_fnc_addKeybind;