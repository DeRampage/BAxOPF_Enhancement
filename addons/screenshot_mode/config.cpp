#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"TF47_main", "cba_settings"};
        author = "Gruppe Adler";
        url = "https://gruppe-adler.de";
        VERSION_CONFIG;
    };
};
class CfgFunctions 
{
    class TF47
    {
        class Screenshot_Mode
        {
            file = "z\TF47\addons\screenshot_mode\functions";
            class toggleACENametags{};
            class toggleAll{};
            class toggleDuiHud{};
            class toggleSTHud{};
            class toggleTFAR{};
            class toggleVanillaHUD{};
        };
    };
};
class Extended_PostInit_EventHandlers {
    class ADDON {
        clientInit = QUOTE(call COMPILE_FILE(XEH_clientInit));
    };
};

class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};
