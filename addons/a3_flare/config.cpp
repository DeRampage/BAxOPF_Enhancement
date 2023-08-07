#include "script_component.hpp" 

class CfgPatches
{
    class ADDON
    {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Air_F","A3_Data_F"};
        author[] = {"AveryTheKitty","Rampage"};
        requiredVersion = 0.1;
        VERSION_CONFIG;
    };
};
class CfgCoreData
{
    eyeFlare = "\z\TF47\addons\A3_Flare\eyeflare_CA.paa";
    eyeFlareSun = "\z\TF47\addons\A3_Flare\eyeflare_CA.paa";
};
class CfgVehicles
{
    class AllVehicles;
    class Air: AllVehicles
    {
        class MarkerLights
        {
            class PositionRed
            {
                useFlare = 1;
            };
        };
    };
};
