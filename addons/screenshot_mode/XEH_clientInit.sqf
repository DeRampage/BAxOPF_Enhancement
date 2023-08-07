//XEH_clientInit.sqf
#include "script_component.hpp"

if(!hasInterface) exitWith {};

GVAR(active) = false;

[
    localize "STR_TF47_Screenshot_mode_title",
    QGVAR(toggle),
    localize "STR_TF47_Screenshot_mode_Toggle",
    {
        GVAR(active) = !GVAR(active);
        [!GVAR(active)] call FUNC(toggleAll);
    },
    ''
] call CBA_fnc_addKeybind;
