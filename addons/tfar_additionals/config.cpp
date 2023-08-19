#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {"tf_acr_stationar"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Data_F","task_force_radio","task_force_radio_items","ace_interaction","cba_common"};
        authors[] = {"ARAB","KpoT","Rampage"};
        authorUrl = "https://steamcommunity.com/sharedfiles/filedetails/?id=2423977008";
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class tfar_additionals
        {
            file = "z\TF47\addons\tfar_additionals\functions";
            class action{};
            class init_radio_unit{};
        };
    };
};

#include "CfgEventHandlers.hpp"
