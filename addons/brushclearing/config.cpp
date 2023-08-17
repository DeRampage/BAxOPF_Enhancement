#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_trenches", "ace_gestures", "ace_common"};
        author = "Ampersand";
        authors[] = {"Ampersand","Rampage"};
        url = "https://github.com/ampersand38/Brush-Clearing";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class GVAR(clearBrush) {
                    displayName = "Clear Grass/Bush";
                    condition = QUOTE(_player call FUNC(canClearBrush));
                    // Wait a frame to handle "Do When releasing action menu key" option
                    statement = QUOTE([ARR_2({_this call FUNC(clearBrush)},_player)] call CBA_fnc_execNextFrame);
                    exceptions[] = {};
                    showDisabled = 0;
                    icon = "\a3\modules_f\data\hideterrainobjects\icon32_ca.paa";
                };
            };
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVersioning.hpp"
