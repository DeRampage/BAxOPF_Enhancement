#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_common"};
        authors[] = {"Ampersand","Rampage"};
        authorUrl = "https://github.com/ampersand38/dwyl";
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class DismountWhereYouLook
        {
            file = "z\TF47\addons\dwyl\functions";
            class exit{};
            class findLookedAt{};
            class getExits{};
            class showExits{};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"
