#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main"};
        author = "TF47 Desty";
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class COMPONENT
        {
            file = "z\TF47\addons\EnhancedNVGs\functions";
            class getVisionMode{};
            class getNvgEffect{};
            class setNvgEffect{};
        };
    };
};       

class Extended_PostInit_EventHandlers
{
    class COMPONENT
    {
        init="call compile preprocessFileLineNumbers 'z\TF47\addons\EnhancedNVGs\XEH_postInit.sqf'";
    };
};
class Extended_PreInit_EventHandlers
{
    class COMPONENT
    {
        init="call compile preprocessFileLineNumbers 'z\TF47\addons\EnhancedNVGs\XEH_preInit.sqf'";
    };
};

class CfgEffects
{
  gpEffect[] = {1.0, 1.0, 0.0, {0.0, 0.0, 0.0, 0.00}, {0.518, 0.737, 0.196, 0.0}, {0.300, 0.590, 0.110, 0.0}};
  wpEffect[] = {1.0, 1.0, 0.0, {0.0, 0.0, 0.0, 0.0}, {0.0, 0.906, 1.0, 0.0}, {0.300, 0.590, 0.110, 0.0}};
  mwEffect[] = {1.0, 1.0, 0.0, 0.0, {0.0, 0.0, 0.00}, {0.078, 0.769, 0.576, 0.0}, {0.300, 0.590, 0.110, 0.0}};
  apEffect[] = {1.0, 1.0, 0.0, {0.0, 0.0, 0.0, 0.00}, {1,0.976,0.149, 0.0}, {0.300, 0.590, 0.110, 0.0}};

  wpAceEffect[] = {1.0, 1.0, 0.0, {0.0, 0.0, 0.0, 0.00}, {0.051, 1.9, 2.9, 0.0}, {0.300, 0.590, 0.110, 0.0}};
  mwAceEffect[] = {1.0, 1.0, 0.0, {0.0, 0.0, 0.0, 0.00}, {0.090, 1.9, 1.9, 0.0}, {0.300, 0.590, 0.110, 0.0}};
  apAceEffect[] = {1.0, 1.0, 0.0, {0.0, 0.0, 0.0, 0.00}, {0.992,1,0.576, 0.0}, {0.300, 0.590, 0.110, 0.0}};
  gpAceEffect[] = {1.0, 1.0, 0.0, {0.0, 0.0, 0.0, 0.00}, {0.49, 0.984, 0.533, 0.0}, {0.300, 0.590, 0.110, 0.0}};
};
