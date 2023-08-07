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
        class RideWhereYouLook
        {
            file = "z\TF47\addons\rwyl\functions";
            class findSeat{};
            class moveSeat{};
            class moveSeatLocal{};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"
