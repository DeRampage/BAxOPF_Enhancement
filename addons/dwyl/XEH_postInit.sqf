#include "script_component.hpp"

if (!hasInterface) exitWith {};

[
    "TF47 Ride & Dismount", "TF47_dwyl_dismount", "Dismount",
    {_this call TF47_dwyl_fnc_exit},
    {},
    [48, [false, true, false]], false                  //, 0, true
] call CBA_fnc_addKeybind; // V

[
    "TF47 Ride & Dismount", "TF47_dwyl_showExits", "Show Exits (Hold)",
    {_this call TF47_dwyl_fnc_showExits},
    {
        [{dwyl_exit_pfh_running = false;}] call CBA_fnc_execNextFrame;
    }, [0, [false, false, false]], false                  //, 0, true
] call CBA_fnc_addKeybind; // Unbound

[
    "TF47 Ride & Dismount", "TF47_dwyl_showAndDismount", "Show Exits And Dismount On Release",
    {_this call TF47_dwyl_fnc_showExits},
    {_this call TF47_dwyl_fnc_exit},
    [0, [false, false, false]], false                  //, 0, true
] call CBA_fnc_addKeybind; // Unbound
