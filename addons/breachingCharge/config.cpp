#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {"AMP_Breaching_Charge","AMP_Breaching_Charge_Place","AMP_Door_Wedge_Place"};
        weapons[] = {"AMP_Breaching_Charge_Muzzle"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "A3_Weapons_F_Explosives",
            "ace_interaction",
            "ace_explosives"
        };
        authors[] = {"Ampersand","Rampage"};
        authorUrl = "https://github.com/ampersand38/";
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class COMPONENT
        {
            file = "z\TF47\addons\breachingCharge\functions";
            class breachObstacle{};
            class getDoor{};
            class nearestDoor{};
            class plantBreachingCharge{};
            class rotateAmmoObj{};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
