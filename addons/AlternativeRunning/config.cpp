#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"CBA_Extended_EventHandlers","CBA_MAIN"};
        author[] = {"Rampage"};
        VERSION_CONFIG;
    };
};
class Extended_PreInit_EventHandlers
{
    class AlternativeRunnigs_PreInit
    {
        init = "call compile preprocessFileLineNumbers 'z\TF47\addons\AlternativeRunning\bootstrap\XEH_preInit.sqf'";
    };
};
class Extended_PostInit_EventHandlers
{
    class AlternativeRunnigs_PostInit
    {
        init = "call compile preprocessFileLineNumbers 'z\TF47\addons\AlternativeRunning\bootstrap\XEH_postInit.sqf'";
    };
};
class CfgMovesBasic
{
    class Actions
    {
        class Default;
        class NoActions;
    };
};
class CfgMovesMaleSdr: CfgMovesBasic
{
    class States
    {
        class AmovPercMrunSlowWlnrDf;
        class AmovPercMevaSlowWlnrDf: AmovPercMrunSlowWlnrDf
        {
            stamina = -1;
            aimPrecision = 7;
            actions = "LauncherStandActions";
            file = "a3\anims_f\data\anim\sdr\mov\erc\spr\low\lnr\amovpercmsprslowwlnrdf.rtm";
            duty = 1.4;
            relSpeedMin = 0.7;
            speed = 0.707401;
            soundOverride = "sprint";
            InterpolateTo[] = {"Unconscious",0.02,"AmovPercMrunSrasWlnrDf",0.02,"AmovPknlMrunSrasWlnrDf",0.025,"AmovPercMevaSlowWlnrDfr",0.025,"AmovPercMevaSlowWlnrDfl",0.025,"AmovPercMstpSrasWlnrDnon_AmovPpneMstpSnonWnonDnon",0.02,"AmovPercMstpSrasWlnrDnon_AmovPercMstpSrasWrflDnon",0.02,"AmovPercMstpSrasWlnrDnon_AmovPercMstpSrasWpstDnon",0.02,"ARMA_AlternativeRunWithLauncher",0.02};
            headBobStrength = 0.223881;
        };
        class SprintBaseDf;
        class ARMA_AlternativeRunWithLauncher: SprintBaseDf
        {
            soundOverride = "run";
            soundEdge[] = {0.25,0.5,0.75,1};
            soundEnabled = 1;
            file = "a3\anims_f\data\anim\sdr\mov\erc\run\low\lnr\amovpercmrunslowwlnrdf.rtm";
            speed = 0.81475;
            canReload = 0;
            stamina = -1.85;
            actions = "NoActions";
            headBobStrength = 0;
            variantsAI[] = {};
            variantsPlayer[] = {};
            duty = 1;
            disableWeapons = 1;
            disableWeaponsLong = 1;
            leftHandIKBeg = 1;
            leftHandIKCurve[] = {1};
            leftHandIKEnd = 1;
            rightHandIKBeg = 1;
            rightHandIKCurve[] = {1};
            rightHandIKEnd = 1;
            weaponIK = 4;
            collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl_offset.p3d";
            ConnectTo[] = {};
            InterpolateTo[] = {"Unconscious",0.02,"AmovPercMrunSrasWlnrDf",0.02,"AmovPknlMrunSrasWlnrDf",0.025,"AmovPercMevaSlowWlnrDfr",0.025,"AmovPercMevaSlowWlnrDfl",0.025,"AmovPercMstpSrasWlnrDnon_AmovPpneMstpSnonWnonDnon",0.02,"AmovPercMstpSrasWlnrDnon_AmovPercMstpSrasWrflDnon",0.02,"AmovPercMstpSrasWlnrDnon_AmovPercMstpSrasWpstDnon",0.02};
        };
        class HubShootingRangeKneel_move1;
        class AmovPercMstpSnonWnonDnon;
        class AmovPercMrunSnonWnonDf;
        class SprintCivilBaseDf;
        class ARMA_AlternativePistol: SprintCivilBaseDf
        {
            file = "z\TF47\addons\AlternativeRunning\ARMA_AlternativePistol.rtm";
            speed = -0.61;
            canReload = 0;
            stamina = -1.25;
            actions = "NoActions";
            headBobStrength = 0;
            variantsAI[] = {};
            variantsPlayer[] = {};
            duty = 1;
            showHandGun = 1;
            disableWeapons = 1;
            disableWeaponsLong = 1;
            leftHandIKBeg = 0;
            leftHandIKCurve[] = {};
            leftHandIKEnd = 0;
            rightHandIKBeg = 0;
            rightHandIKCurve[] = {0};
            rightHandIKEnd = 0;
            weaponIK = 0;
            collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl_offset.p3d";
            InterpolateTo[] = {"AmovPercMsprSlowWpstDf_AmovPpneMstpSrasWpstDnon",0.02,"AmovPercMstpSrasWpstDnon",0.02,"AmovPercMwlkSrasWpstDf",0.025,"AmovPercMrunSrasWpstDf",0.02,"AmovPknlMevaSrasWpstDf",0.02,"AmovPercMevaSrasWpstDfl",0.02,"AmovPercMevaSrasWpstDfr",0.02,"AmovPercMevaSrasWpstDf",0.02,"AmovPercMevaSlowWpstDf",0.02,"Unconscious",0.02};
        };
        class AmovPercMevaSrasWpstDf: SprintCivilBaseDf
        {
            actions = "PistolStandEvasiveActionsF";
            limitGunMovement = 0.1;
            collisionShape = "A3\anims_f\data\geom\sdr\Perc_Wpst.p3d";
            showHandGun = 1;
            duty = 0.8;
            static = 1;
            enableOptics = 0;
            speed = 1.666666;
            file = "a3\anims_f\data\anim\sdr\mov\erc\spr\low\pst\amovpercmsprslowwpstdf.rtm";
            weaponIK = 2;
            headBobStrength = 0.233831;
            ConnectTo[] = {};
            InterpolateTo[] = {"AmovPercMsprSlowWpstDf_AmovPpneMstpSrasWpstDnon",0.02,"AmovPercMstpSrasWpstDnon",0.02,"AmovPercMwlkSrasWpstDf",0.025,"AmovPercMrunSrasWpstDf",0.02,"AmovPknlMevaSrasWpstDf",0.02,"AmovPercMevaSrasWpstDfl",0.02,"AmovPercMevaSrasWpstDfr",0.02,"ARMA_AlternativePistol",0.02,"Unconscious",0.02};
            disableWeaponsLong = 1;
        };
        class AmovPercMevaSlowWpstDf: AmovPercMevaSrasWpstDf
        {
            actions = "PistolLowStandActionsFastF";
            InterpolateTo[] = {"AmovPercMsprSlowWpstDf_AmovPpneMstpSrasWpstDnon",0.025,"AmovPercMstpSlowWpstDnon",0.025,"AmovPercMwlkSlowWpstDf",0.025,"AmovPercMrunSlowWpstDf",0.025,"AmovPercMevaSlowWpstDfl",0.025,"AmovPknlMevaSrasWpstDf",0.025,"AmovPknlMevaSrasWpstDfr",0.025,"AmovPknlMevaSrasWpstDfl",0.025,"AmovPercMevaSlowWpstDfr",0.025,"ARMA_AlternativePistol",0.02,"Unconscious",0.02};
        };
        class AmovPercMevaSrasWrflDf: SprintBaseDf
        {
            speed = 1.60971;
            weaponIK = 1;
            headBobStrength = 0.25;
            duty = 1;
            disableWeapons = 1;
            disableWeaponsLong = 1;
            collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl_offset.p3d";
            ConnectTo[] = {"AovrPercMrunSrasWrflDf",1.202};
            InterpolateTo[] = {"AovrPercMstpSrasWrflDf",0.232,"AmovPercMrunSlowWrflDf",0.025,"AmovPercMwlkSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf_ldst",0.025,"AmovPercMsprSlowWrflDf_AmovPpneMstpSrasWrflDnon",0.02,"AmovPknlMevaSrasWrflDf",0.025,"AmovPercMevaSlowWrflDf",0.02,"Unconscious",0.02,"AmovPercMevaSrasWrflDf_AmovPknlMstpSrasWrflDnon",0.02,"AmovPercMtacSrasWrflDf",0.02,"AmovPercMtacSrasWrflDfl",0.02,"AmovPercMtacSrasWrflDfr",0.02,"AmovPercMstpSrasWrflDnon",0.02,"AmovPercMevaSrasWrflDfl",0.02,"AmovPercMevaSrasWrflDfr",0.02,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025,"ARMA_AlternativeRun",0.025,"ARMA_AlternativeRunLowered",0.025,"ARMA_AlternativeRun_Water_Heavy",0.025,"ARMA_AlternativeRun_Water_Light",0.025};
        };
        class AmovPercMevaSlowWrflDf: AmovPercMevaSrasWrflDf
        {
            actions = "RifleStandLowEvasiveActionsF";
            headBobStrength = 0.253731;
            ConnectTo[] = {};
            InterpolateTo[] = {"AmovPercMstpSlowWrflDnon",0.025,"AmovPercMwlkSlowWrflDf_ver2",0.025,"AmovPercMtacSlowWrflDf_ver2",0.025,"AmovPercMwlkSlowWrflDf",0.5,"AmovPercMrunSlowWrflDf",0.025,"AmovPercMsprSlowWrflDf_AmovPpneMstpSrasWrflDnon",0.02,"AmovPercMevaSrasWrflDf",0.02,"AmovPknlMevaSrasWrflDf",0.02,"AidlPercMevaSrasWrflDf",0.01,"AmovPercMevaSlowWrflDfl",0.025,"AmovPercMevaSlowWrflDfr",0.025,"Unconscious",0.02,"ARMA_AlternativeRun",0.025,"ARMA_AlternativeRunLowered",0.025,"ARMA_AlternativeRun_Water_Heavy",0.025,"ARMA_AlternativeRun_Water_Light",0.025};
        };
        class ARMA_AlternativeRun: SprintBaseDf
        {
            file = "z\TF47\addons\AlternativeRunning\ARMA_AlternativeRun.rtm";
            speed = -0.61;
            canReload = 0;
            stamina = -1.25;
            actions = "NoActions";
            headBobStrength = 0;
            variantsAI[] = {};
            variantsPlayer[] = {};
            duty = 1;
            disableWeapons = 1;
            disableWeaponsLong = 1;
            leftHandIKBeg = 0;
            leftHandIKCurve[] = {};
            leftHandIKEnd = 0;
            rightHandIKBeg = 1;
            rightHandIKCurve[] = {1};
            rightHandIKEnd = 1;
            weaponIK = 1;
            collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl_offset.p3d";
            ConnectTo[] = {"AovrPercMrunSrasWrflDf",1.202};
            InterpolateTo[] = {"AovrPercMstpSrasWrflDf",0.232,"AmovPercMrunSlowWrflDf",0.025,"AmovPercMwlkSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf_ldst",0.025,"AmovPercMsprSlowWrflDf_AmovPpneMstpSrasWrflDnon",0.02,"AmovPknlMevaSrasWrflDf",0.025,"AmovPercMevaSlowWrflDf",0.02,"Unconscious",0.02,"AmovPercMevaSrasWrflDf_AmovPknlMstpSrasWrflDnon",0.02,"AmovPercMtacSrasWrflDf",0.02,"AmovPercMtacSrasWrflDfl",0.02,"AmovPercMtacSrasWrflDfr",0.02,"AmovPercMstpSrasWrflDnon",0.02,"AmovPercMevaSrasWrflDfl",0.02,"AmovPercMevaSrasWrflDfr",0.02,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025};
        };
        class ARMA_AlternativeRunLowered: SprintBaseDf
        {
            file = "z\TF47\addons\AlternativeRunning\ARMA_AlternativeRunLowered.rtm";
            speed = -0.61;
            canReload = 0;
            stamina = -1.25;
            actions = "NoActions";
            headBobStrength = 0;
            variantsAI[] = {};
            variantsPlayer[] = {};
            duty = 1;
            disableWeapons = 1;
            disableWeaponsLong = 1;
            leftHandIKBeg = 0;
            leftHandIKCurve[] = {};
            leftHandIKEnd = 0;
            rightHandIKBeg = 0;
            rightHandIKCurve[] = {0};
            rightHandIKEnd = 0;
            weaponIK = 0;
            collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl_offset.p3d";
            ConnectTo[] = {"AovrPercMrunSrasWrflDf",1.202};
            InterpolateTo[] = {"AovrPercMstpSrasWrflDf",0.232,"AmovPercMrunSlowWrflDf",0.025,"AmovPercMwlkSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf_ldst",0.025,"AmovPercMsprSlowWrflDf_AmovPpneMstpSrasWrflDnon",0.02,"AmovPknlMevaSrasWrflDf",0.025,"AmovPercMevaSlowWrflDf",0.02,"Unconscious",0.02,"AmovPercMevaSrasWrflDf_AmovPknlMstpSrasWrflDnon",0.02,"AmovPercMtacSrasWrflDf",0.02,"AmovPercMtacSrasWrflDfl",0.02,"AmovPercMtacSrasWrflDfr",0.02,"AmovPercMstpSrasWrflDnon",0.02,"AmovPercMevaSrasWrflDfl",0.02,"AmovPercMevaSrasWrflDfr",0.02,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025};
        };
        class ARMA_AlternativeRun_Water_Heavy: SprintBaseDf
        {
            file = "z\TF47\addons\AlternativeRunning\ARMA_AlternativeRun_Water_Heavy.rtm";
            speed = -2.95;
            soundEdge[] = {0,0.2,0.35,0.5,0.66,0.8,0.95};
            canReload = 0;
            stamina = -2;
            actions = "NoActions";
            headBobStrength = 0;
            variantsAI[] = {};
            variantsPlayer[] = {};
            duty = 1;
            disableWeapons = 1;
            disableWeaponsLong = 1;
            leftHandIKBeg = 1;
            leftHandIKCurve[] = {1};
            leftHandIKEnd = 1;
            rightHandIKBeg = 1;
            rightHandIKCurve[] = {1};
            rightHandIKEnd = 1;
            weaponIK = 1;
            collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl_offset.p3d";
            ConnectTo[] = {"AovrPercMrunSrasWrflDf",1.202};
            InterpolateTo[] = {"AovrPercMstpSrasWrflDf",0.232,"AmovPercMrunSlowWrflDf",0.025,"AmovPercMwlkSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf_ldst",0.025,"AmovPercMsprSlowWrflDf_AmovPpneMstpSrasWrflDnon",0.02,"AmovPknlMevaSrasWrflDf",0.025,"AmovPercMevaSlowWrflDf",0.02,"Unconscious",0.02,"AmovPercMevaSrasWrflDf_AmovPknlMstpSrasWrflDnon",0.02,"AmovPercMtacSrasWrflDf",0.02,"AmovPercMtacSrasWrflDfl",0.02,"AmovPercMtacSrasWrflDfr",0.02,"AmovPercMstpSrasWrflDnon",0.02,"AmovPercMevaSrasWrflDfl",0.02,"AmovPercMevaSrasWrflDfr",0.02,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025};
        };
        class ARMA_AlternativeRun_Water_Light: SprintBaseDf
        {
            file = "z\TF47\addons\AlternativeRunning\ARMA_AlternativeRun_Water_Light.rtm";
            speed = -2.5;
            soundEdge[] = {0,0.2,0.35,0.5,0.66,0.8,0.95};
            canReload = 0;
            stamina = -1.5;
            actions = "NoActions";
            headBobStrength = 0;
            variantsAI[] = {};
            variantsPlayer[] = {};
            duty = 1;
            disableWeapons = 1;
            disableWeaponsLong = 1;
            leftHandIKBeg = 1;
            leftHandIKCurve[] = {1};
            leftHandIKEnd = 1;
            rightHandIKBeg = 1;
            rightHandIKCurve[] = {1};
            rightHandIKEnd = 1;
            weaponIK = 1;
            collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl_offset.p3d";
            ConnectTo[] = {"AovrPercMrunSrasWrflDf",1.202};
            InterpolateTo[] = {"AovrPercMstpSrasWrflDf",0.232,"AmovPercMrunSlowWrflDf",0.025,"AmovPercMwlkSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf_ldst",0.025,"AmovPercMsprSlowWrflDf_AmovPpneMstpSrasWrflDnon",0.02,"AmovPknlMevaSrasWrflDf",0.025,"AmovPercMevaSlowWrflDf",0.02,"Unconscious",0.02,"AmovPercMevaSrasWrflDf_AmovPknlMstpSrasWrflDnon",0.02,"AmovPercMtacSrasWrflDf",0.02,"AmovPercMtacSrasWrflDfl",0.02,"AmovPercMtacSrasWrflDfr",0.02,"AmovPercMstpSrasWrflDnon",0.02,"AmovPercMevaSrasWrflDfl",0.02,"AmovPercMevaSrasWrflDfr",0.02,"AmovPercMrunSrasWrflDf",0.025,"AmovPercMrunSrasWrflDf",0.025};
        };
    };
};
