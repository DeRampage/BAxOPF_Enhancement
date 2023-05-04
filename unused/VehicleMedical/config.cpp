#include "script_component.hpp"

class CfgPatches {
    class COMPONENT {
        name = COMPONENT;
        author = "TF47 Desty";
        version[] = { 2, 3, 0, -1 }; //Negative last digit indicates alpha/beta
        requiredAddons[] = {"ace_interact_menu", "ace_medical", "ace_medical_treatment", "cba_settings"};
        units[] = {};
        weapons[] = {};
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
