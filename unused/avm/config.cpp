#include "script_component.hpp"

class CfgPatches
{
    class ADDON {
        name = COMPONENT;        
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_interact_menu", "ace_medical", "ace_medical_treatment", "cba_settings"};
        authors[] = {"Jack Napier", "Desty","Rampage"};
        VERSION_CONFIG;
    };
};

class Extended_PreInit_EventHandlers {
    class COMPONENT {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class COMPONENT {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};
