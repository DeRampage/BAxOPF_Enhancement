#include "script_component.hpp"

class CfgPatches {
    class AMP_Door_Wedge {
        name = COMPONENT;
        units[] = {"AMP_Door_Wedge_Place"};
        weapons[] = {"AMP_Door_Wedge"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "A3_Weapons_F_Explosives",
            "ace_interaction",
            "ace_explosives"
        };
        author = "Ampersand";
        authors[] = {"Ampersand","Rampage"};
        authorUrl = "https://github.com/ampersand38/";
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class DoorWedge
        {
            file = "z\TF47\addons\wedge\functions";
            class canDeployDoorWedge{};
            class canRemoveDoorWedge{};
            class deployDoorWedge{};
            class removeDoorWedge{};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"

#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
