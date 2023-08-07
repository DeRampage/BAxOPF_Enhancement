#include "script_component.hpp"

class cfgPatches
{
    class ADDON
    {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
requiredAddons[] = {"ace_nightvision"};
version = "1.0.1";
author[] = {"D. Wolfe","Rampage"};
authorUrl = "https://steamcommunity.com/id/redthirten/";
        VERSION_CONFIG;
};
};
class CfgWeapons
{
class Binocular;
class NVGoggles: Binocular
{
ace_nightvision_border = "\z\TF47\addons\Larger_ACE_Nightvision_Border\data\nvg_mask_binos_4096_2x.paa";
};
class O_NVGoggles_hex_F: NVGoggles
{
ace_nightvision_border = "\z\TF47\addons\Larger_ACE_Nightvision_Border\data\nvg_mask_quad_4096_2x.paa";
};
class ACE_NVG_Biocular: NVGoggles
{
ace_nightvision_border = "\z\TF47\addons\Larger_ACE_Nightvision_Border\data\nvg_mask_4096_2x.paa";
};
class ACE_NVG_Monocular: NVGoggles
{
ace_nightvision_border = "\z\TF47\addons\Larger_ACE_Nightvision_Border\data\nvg_mask_4096_2x.paa";
};
class ACE_NVG_Binocular: NVGoggles
{
ace_nightvision_border = "\z\TF47\addons\Larger_ACE_Nightvision_Border\data\nvg_mask_binos_4096_2x.paa";
};
class ACE_NVG_Quadocular: NVGoggles
{
ace_nightvision_border = "\z\TF47\addons\Larger_ACE_Nightvision_Border\data\nvg_mask_quad_4096_2x.paa";
};
};
