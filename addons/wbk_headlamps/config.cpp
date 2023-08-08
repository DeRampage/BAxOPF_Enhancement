class CfgPatches {
    class wbk_headlamps {
        units[]={};
        weapons[]={};
        requiredVersion=1.02;
        requiredAddons[]={"A3_Air_F","A3_Data_F","a3_anims_f"};
        authors[] = {"WebKnight", "Rampage"};
    };
};

class CfgWeapons
{
    class ItemCore;
    class InventoryItem_Base_F;
    class WBK_HeadLampItem: ItemCore
    {
        author = "WebKnight";
        displayName = "Head Lamp";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        scope = 2;      
        scopeArsenal = 2;
        scopeCurator = 2;
        simulation= "ItemMineDetector";
        picture = "\z\TF47\addons\wbk_headlamps\wbk_flashlight_pic.paa";
        descriptionShort = "Head Lamp that you can activate by pressing CTRL+L (By Default).";
        class ItemInfo: InventoryItem_Base_F
        {
            mass = 4;
        };
    };
};

class DefaultEventhandlers;
class CfgMovesBasic
{
    class Default;
    class StandBase;
    class HealBase: Default
    {
        disableWeapons=1;
        disableWeaponsLong=1;
        showWeaponAim=0;
        canPullTrigger=0;
        duty=0.2;
        limitGunMovement=0;
        aiming="empty";
        aimingBody="empty";
        actions="HealActionBase";
        looped=0;
    };
    class ManActions
    {
        WBK_head_flashlight[]=
        {
            "WBK_head_flashlight",
            "Gesture"
        };
        WBK_head_flashlight_off[]=
        {
            "WBK_head_flashlight_off",
            "Gesture"
        };
    };
};
class CfgGesturesMale
{
    class ManActions
    {
    };
    class Actions;
    class Default;
    class States
    {
        class WBK_head_flashlight: Default
        {
            speed=0.95;
            looped=0;
            file="z\TF47\addons\wbk_headlamps\head_flashlight.rtm";
            mask="leftHand";
            disableWeapons=1;
            interpolationRestart=2;
            leftHandIKBeg=0;
            leftHandIKCurve[]={0};
            leftHandIKEnd=0;
            rightHandIKBeg=1;
            rightHandIKCurve[]={1};
            rightHandIKEnd=1;
            weaponIK=0;
            canReload=1;
        };
        class WBK_head_flashlight_off: Default
        {
            speed=0.95;
            looped=0;
            file="z\TF47\addons\wbk_headlamps\head_flashlight.rtm";
            mask="leftHand";
            disableWeapons=1;
            interpolationRestart=2;
            leftHandIKBeg=0;
            leftHandIKCurve[]={0};
            leftHandIKEnd=0;
            rightHandIKBeg=1;
            rightHandIKCurve[]={1};
            rightHandIKEnd=1;
            weaponIK=0;
            canReload=1;
        };
    };
};
class CfgVehicles
{
    class Reflector_Cone_01_narrow_white_F;
    class WBK_HeadLampLightObject: Reflector_Cone_01_narrow_white_F
    {
        scope=2;
        scopeCurator=2;
        displayName="Wbk Headlamp";
        class Reflectors
        {
            class Light_1
            {
                color[]={1,1,1};
                ambient[]={1,1,1};
                intensity=500;
                size=1;
                innerAngle=60;
                outerAngle=118;
                coneFadeCoef=6;
                position="Light_1_pos";
                direction="Light_1_dir";
                hitpoint="Light_1_hitpoint";
                hitpointClass="Hit_Light_1";
                selection="Light_1_hide";
                useFlare=0;
                class Attenuation
                {
                    start=0;
                    constant=0;
                    linear=2;
                    quadratic=0.5;
                    hardLimitStart=10;
                    hardLimitEnd=20;
                };
            };
            class Light_1_Flare: Light_1
            {
                hitpointClass="Hit_Light_1_Flare";
                outerAngle=178;
                useFlare=1;
                flareSize=0.45;
                flareMaxDistance=250;
            };
        };
    };
};

class CfgSounds
{
    sounds[] = {};
    class WBK_flashlight_on
    {
    name = "WBK_flashlight_on";
    sound[] = {"z\TF47\addons\wbk_headlamps\flashlight_on.wav", db+10, 1};
    titles[]={};
    };
    class WBK_flashlight_off
    {
    name = "WBK_flashlight_off";
    sound[] = {"z\TF47\addons\wbk_headlamps\flashlight_off.wav", db+10, 1};
    titles[]={};
    };
};

class Extended_InitPost_EventHandlers 
{
    class CAManBase
    {
        class WBK_HeadLamps_InitEventHandler
        {
            onRespawn = true;
            init="_unit = _this select 0; if (local _unit) then {_unit setVariable ['WBK_AttachedFlaslights',nil,true];  _unit spawn WBK_CreateLightOnGun; _unit spawn WBK_CreateAiHeadlampsAtNight;};";
        };
    };
};

class Extended_PreInit_EventHandlers
{
    class WBK_Headlapms_PreInit
    {
        init="call compile preprocessFileLineNumbers 'z\TF47\addons\wbk_headlamps\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers 
{
    class WBK_Headlapms_PostInit 
    {
        init="call compile preprocessFileLineNumbers 'z\TF47\addons\wbk_headlamps\XEH_postInit.sqf'";
    };
};
