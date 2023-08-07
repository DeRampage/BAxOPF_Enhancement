#include "script_component.hpp"

class CfgPatches
{
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main"};
        author = "Desty";        
        VERSION_CONFIG;
    };
};

#include "CfgSettings.hpp"
#include "CfgFunctions.hpp"
#include "CfgEventHandlers.hpp"

