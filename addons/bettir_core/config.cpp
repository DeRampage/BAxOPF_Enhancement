#include "script_component.hpp"

class CfgPatches
{
    class COMPONENT
    {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_UI_F"};
        author[] = {"Vestarr","Rampage"};
        VERSION_CONFIG;
    };
};
class CfgSettings
{
    class CBA
    {
        class Versioning
        {
            class BettIR_Core{};
        };
    };
};

class CfgFunctions {
    class TF47 
    {
        class BettIR_core
        {
            file = "z\TF47\addons\BettIR_Core\functions";
            class getCompatibleNVGs;
            class getCompatibleWeaponAttachments;
            class handleVisionModeChange;
            class updateUnitList;
            class nvgIlluminatorOn;
            class nvgIlluminatorOff;
            class toggleNvgIlluminator;
            class weaponIlluminatorOn;
            class weaponIlluminatorOff;
            class toggleWeaponIlluminator;
        };
    };
};


class CfgVehicles
{
    class Lamps_base_F;
    class BettIR_Illuminator_NVG: Lamps_base_F
    {
        scope = 1;
        scopeCurator = 1;
        displayName = "BettIR Light Object";
        model = "\z\TF47\addons\BettIR_Core\data\models\Light.p3d";
        class Hitpoints{};
        class AnimationSources{};
        class Reflectors
        {
            class Light_1
            {
                color[] = {70,40,60};
                ambient[] = {0.05,0.1,0.05};
                intensity = 1; //original 0.9
                size = 1;
                innerAngle = 25;
                outerAngle = 85;
                coneFadeCoef = 4;
                position = "Light_1_pos";
                direction = "Light_1_dir";
                hitpoint = "";
                selection = "";
                useFlare = 1;
                flareSize = 0.1;
                flareMaxDistance = 50; //original 10
                class Attenuation
                {
                    start = 0;
                    constant = 0;
                    linear = 0;
                    quadratic = 1;
                    hardLimitStart = 8;
                    hardLimitEnd = 22;
                };
            };
        };
    };
    class BettIR_Illuminator_Weapon: BettIR_Illuminator_NVG
    {
        displayName = "BettIR Weapon Light Object";
        class Reflectors: Reflectors
        {
            class Light_1: Light_1
            {
                color[] = {160,120,80};
                innerAngle = 3;
                outerAngle = 15;
                coneFadeCoef = 2; //original 6
                intensity = 70; //original 35
                useFlare = 1;
                flareSize = 0.6;
                flareMaxDistance = 350;
                class Attenuation: Attenuation
                {
                    start = 0.85;
                    constant = 0;
                    linear = 0;
                    quadratic = 1;
                    hardLimitStart = 280;
                    hardLimitEnd = 350;
                };
            };
        };
    };
};

class BettIR_Config
{
    class CompatibleAttachments
    {
        class __base_rightSiderailPointer
        {
            offset[] = {0.05,0.28,0.06};
        };
        class __base_topRailPointer
        {
            offset[] = {0,0.28,0.12};
        };
        class acc_pointer_ir: __base_rightSiderailPointer{};
        class ace_acc_pointer_green: __base_rightSiderailPointer{};
        class rhsusf_acc_anpeq15side
        {
            offset[] = {0.035,0.28,0.1};
        };
        class rhsusf_acc_anpeq15side_bk: rhsusf_acc_anpeq15side{};
        class rhsusf_acc_anpeq15_top
        {
            offset[] = {-0.027,0.28,0.15};
        };
        //from compat
        class rhsusf_acc_anpeq15_wmx: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_wmx_light: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_wmx_sc: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_wmx_light_sc: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_wmx_h: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_wmx_light_h: rhsusf_acc_anpeq15_top{};
        //compat
        class rhsusf_acc_anpeq15_top_h: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_bk_top: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_bk_top_h: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_h: rhsusf_acc_anpeq15_top{};
        class rhsusf_acc_anpeq15_bk: rhsusf_acc_anpeq15{};
        class rhsusf_acc_anpeq15_bk_h: rhsusf_acc_anpeq15{};
        class rhsusf_acc_anpeq15_light: rhsusf_acc_anpeq15{};
        class rhsusf_acc_anpeq15_light_h: rhsusf_acc_anpeq15{};
        class rhsusf_acc_anpeq15_bk_light: rhsusf_acc_anpeq15_light{};
        class rhsusf_acc_anpeq15_bk_light_h: rhsusf_acc_anpeq15_light{};
        class rhsusf_acc_anpeq16a: rhsusf_acc_anpeq15side{};
        class rhsusf_acc_anpeq16a_top: rhsusf_acc_anpeq15_bk_top{};
        class rhsusf_acc_anpeq16a_top_light: rhsusf_acc_anpeq16a_top{};
        class rhs_acc_perst3_top: rhsusf_acc_anpeq15_top{};
        class rhs_acc_perst3
        {
            offset[] = {0.032,0.32,0.105};
        };
        class rhs_acc_perst3_2dp_h: rhs_acc_perst3{};
        class rhs_acc_perst3_2dp_light_h: rhs_acc_perst3_2dp_h{};
        class cup_acc_anpeq_15
        {
            offset[] = {0.035,0.28,0.1};
        };
        class cup_acc_anpeq_15_black: cup_acc_anpeq_15{};
        class cup_acc_anpeq_15_od: cup_acc_anpeq_15{};
        class cup_acc_anpeq_15_tan_top
        {
            offset[] = {-0.027,0.28,0.15};
        };
        class cup_acc_anpeq_15_black_top: cup_acc_anpeq_15_tan_top{};
        class cup_acc_anpeq_15_od_top: cup_acc_anpeq_15_tan_top{};
        class cup_acc_anpeq_15_flashlight_tan_l: cup_acc_anpeq_15{};
        class cup_acc_anpeq_15_flashlight_od_l: cup_acc_anpeq_15_flashlight_tan_l{};
        class cup_acc_anpeq_15_flashlight_black_l: cup_acc_anpeq_15_flashlight_tan_l{};
        class cup_acc_anpeq_15_flashlight_black_F: cup_acc_anpeq_15_flashlight_black_l{};
        class CUP_acc_anpeq_15_flashlight_od_F: cup_acc_anpeq_15_flashlight_black_l{};
        class CUP_acc_anpeq_15_flashlight_tan_F: cup_acc_anpeq_15_flashlight_black_l{};
        class cup_acc_anpeq_15_top_flashlight_tan_l: cup_acc_anpeq_15_tan_top{};
        class cup_acc_anpeq_15_top_flashlight_od_l: cup_acc_anpeq_15_top_flashlight_tan_l{};
        class cup_acc_anpeq_15_top_flashlight_black_l: cup_acc_anpeq_15_top_flashlight_tan_l{};
        class cup_acc_anpeq_15_top_flashlight_tan_f: cup_acc_anpeq_15_top_flashlight_tan_l{};
        class cup_acc_anpeq_15_top_flashlight_od_f: cup_acc_anpeq_15_top_flashlight_tan_f{};
        class cup_acc_anpeq_15_top_flashlight_black_f: cup_acc_anpeq_15_top_flashlight_tan_f{};
        class cup_acc_anpeq_2_grey
        {
            offset[] = {0.05,0.28,0.065};
        };
        class cup_acc_anpeq_2_desert: cup_acc_anpeq_2_grey{};
        class cup_acc_anpeq_2_camo: cup_acc_anpeq_2_grey{};
        class cup_acc_anpeq_2_black_top
        {
            offset[] = {-0.021,0.28,0.13};
        };
        class cup_acc_anpeq_2_coyote_top: cup_acc_anpeq_2_black_top{};
        class cup_acc_anpeq_2_od_top: cup_acc_anpeq_2_black_top{};
        class cup_acc_anpeq_2_flashlight_black_l: cup_acc_anpeq_2_black_top{};
        class cup_acc_anpeq_2_flashlight_od_l: cup_acc_anpeq_2_black_top{};
        class cup_acc_anpeq_2_flashlight_coyote_l: cup_acc_anpeq_2_black_top{};
        class cup_acc_anpeq_2_flashlight_black_f: cup_acc_anpeq_2_flashlight_black_l{};
        class cup_acc_anpeq_2_flashlight_od_f: cup_acc_anpeq_2_flashlight_black_f{};
        class cup_acc_anpeq_2_flashlight_coyote_f: cup_acc_anpeq_2_flashlight_black_f{};
        class cup_acc_llm01_l
        {
            offset[] = {0.058,0.28,0.08};
        };
        class cup_acc_llm01_coyote_l: cup_acc_llm01_l{};
        class cup_acc_llm01_desert_l: cup_acc_llm01_l{};
        class cup_acc_llm01_hex_l: cup_acc_llm01_l{};
        class cup_acc_llm01_od_l: cup_acc_llm01_l{};
        class cup_acc_llm
        {
            offset[] = {0.05,0.28,0.06};
        };
        class cup_acc_llm_black: cup_acc_llm{};
        class cup_acc_llm_od: cup_acc_llm{};
    };
    class CompatibleNightvisionGoggles
    {
        class __base_NVG
        {
            offset[] = {0,0.15,0.14};
        };
        class __base_Monocular
        {
            offset[] = {-0.04,0.14,0.1};
        };
        class NVGoggles: __base_NVG{};
        class NVGoggles_tna_F: NVGoggles{};
        class NVGoggles_OPFOR: NVGoggles{};
        class NVGoggles_INDEP: NVGoggles{};
        class NVGogglesB_gry_F: NVGoggles{};
        class NVGogglesB_grn_F: NVGoggles{};
        class NVGogglesB_blk_F: NVGoggles{};
        class O_NVGoggles_ghex_F: NVGoggles{};
        class O_NVGoggles_hex_F: NVGoggles{};
        class O_NVGoggles_grn_F: NVGoggles{};
        class O_NVGoggles_urb_F: NVGoggles{};
        class ACE_NVG_Gen2: NVGoggles{};
        class ACE_NVG_Gen4: NVGoggles{};
        class ACE_NVG_Wide: NVGoggles{};
        class rhsusf_ANPVS_15: NVGoggles{};
        class rhsusf_ANPVS_14: __base_Monocular{};
        class rhs_1PN138: __base_Monocular{};
        class CUP_NVG_PVS15_black: __base_NVG{};
        class CUP_NVG_PVS15_tan: CUP_NVG_PVS15_black{};
        class CUP_NVG_PVS15_od: CUP_NVG_PVS15_black{};
        class CUP_NVG_PVS15_winter: CUP_NVG_PVS15_black{};
        class CUP_NVG_PVS15_Hide: CUP_NVG_PVS15_black{};
        class CUP_NVG_PVS7: __base_NVG{};
        class CUP_NVG_PVS7_Hide: CUP_NVG_PVS7{};
        class CUP_NVG_PVS14: __base_Monocular{};
        class CUP_NVG_PVS14_Hide: CUP_NVG_PVS14{};
        class CUP_NVG_HMNVS: __base_Monocular{};
        class CUP_NVG_HMNVS_Hide: CUP_NVG_HMNVS{};
        class CUP_NVG_GPNVG_black: __base_NVG{};
        class CUP_NVG_GPNVG_tan: __base_NVG{};
        class CUP_NVG_GPNVG_green: __base_NVG{};
        class CUP_NVG_GPNVG_winter: __base_NVG{};
        class CUP_NVG_GPNVG_Hide: __base_NVG{};
        class USP_NSEAS: __base_NVG{};
        class USP_GPNVG18: __base_NVG{};
        class USP_GPNVG18_TAN: __base_NVG{};
        class USP_PVS14: __base_NVG{};
        class USP_PVS15: __base_NVG{};
        class USP_PVS31_COMPACT: __base_NVG{};
        class USP_PVS31_HIGH: USP_PVS31_COMPACT{};
        class USP_PVS31_LOW: USP_PVS31_COMPACT{};
        class USP_PVS31_MONOL: __base_Monocular{};
        class USP_PVS31_MONOR: USP_PVS31_MONOL{};
    };
};

#include "CfgEventHandlers.hpp"
