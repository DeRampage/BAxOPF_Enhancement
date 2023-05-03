#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_trenches"};
        author = "Ampersand";
        authors[] = {"Ampersand","Rampage"};
        url = "https://github.com/ampersand38/Brush-Clearing";
        VERSION_CONFIG;
    };
};

class CfgFunctions {
    class TF47 
    {
        class brushClearing 
        {
            file = "z\TF47\addons\brushClearing\functions";
            class clearBrush;
            class canClearBrush;
        };
    };
};

class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class ClearBrush {
                    displayName = "Clear Grass/Bush";
                    condition = "[_player] call TF47_fnc_canClearBrush";
                    //wait a frame to handle "Do When releasing action menu key" option
                    statement = "[{[] call TF47_fnc_clearBrush},[]] call CBA_fnc_execNextFrame";
                    exceptions[] = {};
                    showDisabled = 0;
                    icon = "z\TF47\addons\brushClearing\ui\bushremover.paa";
                };
            };
        };
    };
};

#include "CfgEventHandlers.hpp"