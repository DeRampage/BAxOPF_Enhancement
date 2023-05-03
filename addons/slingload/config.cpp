#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {
            "TF47_slingload_apexFitting",
            "TF47_slingload_wreckDummy"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_interaction"};
        author = "Ampersand";
        authors[] = {"Ampersand","Rampage"};
        authorUrl = "https://github.com/ampersand38/slr";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgNonAIVehicles.hpp"
#include "CfgWeapons.hpp"
