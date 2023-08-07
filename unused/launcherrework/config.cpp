#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = 
        {
            "tf47_weap_maaws",
            "tf47_weap_raws_green",
            "tf47_weap_raws_olive",
            "tf47_weap_raws_sand"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Weapons_F_Tank_Launchers_MRAWS","rhsusf_c_weapons","A3_Weapons_F_Tank","ace_frag"};
        author = "TF47 Desty";
        VERSION_CONFIG;
    };
};

class CfgCloudlets {
    class WPCloud;
    class WPTrails;
    
    class TF47_WP_Cloud : WPCloud {
        lifeTime = 160;
        lifeTimeVar = 1;
        coreDistance = 11;
        damageTime = 0.1;
        coreIntensity = 15;
        constantDistance = 1;
        damageType = "Fire";
        blockAIVisibility = 1;
        rubbing = 0.02;
        weight = 1.2777;
        volume = 1;
        color[] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
        size[] = {17,17,18,19,20,24,25,27};
    };
    
    class TF47_WP_Trails : WPTrails {
        blockAIVisibility = 1;
    };
};

class TF47_SmokeExplosion {
    class Explosion1 {
        intensity = 1;
        interval = 1;
        lifeTime = 80;
        position[] = {0, 0, 0};
        qualityLevel = -1;
        simulation = "particles";
        type = "TF47_WP_Cloud";
    };
    
    class LightExp {
        intensity = 0.001;
        interval = 1;
        lifeTime = 1;
        position[] = {0, 0, 0};
        simulation = "light";
        type = "ExploLight";
    };
    
    class Trails {
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        position[] = {0, 0, 0};
        simulation = "particles";
        type = "TF47_WP_Trails";
    };
    
    class flame_Light {
        simulation = "light";
        type = "FiredLightMed";
        position = "destructionEffect1";
        intensity = 1;
        interval = 1;
        lifeTime = 340;
    };
    
    class flame_sound {
        simulation = "sound";
        type = "Fire";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 340;
    };
};

class CfgAmmo {
    #include "\z\TF47\addons\LauncherRework\M3\CfgAmmo.hpp"
};

class CfgMagazines {
    #include "\z\TF47\addons\LauncherRework\M3\CfgMagazines.hpp"
};

class CfgWeapons {
    #include "\z\TF47\addons\LauncherRework\M3\CfgWeapons.hpp"
};

class ace_arsenal_stats {
    #include "\z\TF47\addons\LauncherRework\M3\ACE_Arsenal_Stats.hpp"
};
