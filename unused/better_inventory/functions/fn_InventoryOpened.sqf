#include "script_component.hpp"

[] Spawn {
    disableSerialization;
    
    waitUntil { !isNull findDisplay 602 };

    _display = findDisplay 602;
    
    // Show all Containers when you open the Inventory
    [] call TF47_fnc_ShowContainers;
    
    // Show all Container when a Container is clicked
    (_display displayCtrl 6331) ctrlAddEventHandler ["ButtonClick","
        []spawn {
            [] call TF47_fnc_ShowContainers;
        };
    "];

    (_display displayCtrl 6381) ctrlAddEventHandler ["ButtonClick","
        []spawn {
            [] call TF47_fnc_ShowContainers;
        };
    "];

    (_display displayCtrl 6191) ctrlAddEventHandler ["ButtonClick","
        []spawn {
            [] call TF47_fnc_ShowContainers;
        };
    "];

//// Dual Arms Compatibility
    if (isClass(configFile>>"CfgPatches">>"secondary_weapons")) then {
        [] spawn {
            WaitUntil {!isNull displayCtrl 1337};
            buttonSetAction [1337, "
                (primaryWeapon player) spawn SecondaryWeapons_events_swapSecondaryWeapon;
                [] spawn {
                    WaitUntil {!(ctrlVisible 633) OR !(ctrlVisible 638) OR !(ctrlVisible 619)};
                    [] call TF47_fnc_ShowContainers;
                };
            "];
        };
        [] spawn {
            WaitUntil {!isNull displayCtrl 6969};
            buttonSetAction [6969, "
                (primaryWeapon player) spawn SecondaryWeapons_events_addSecondaryWeapon;
                [] spawn {
                    WaitUntil {!(ctrlVisible 633) OR !(ctrlVisible 638) OR !(ctrlVisible 619)};
                    [] call TF47_fnc_ShowContainers;
                };
            "];
        };
    };
};