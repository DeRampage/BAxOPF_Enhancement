#include "script_component.hpp"

class CfgPatches
{
    class ADDON
    {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Ui_F","A3_Anims_F_Config_Sdr","A3_Language_F","cba_common","cba_events","cba_keybinding","cba_main","cba_settings","cba_xeh"};
        author[] = {"Xaneas","Rampage"};
        VERSION_CONFIG;
    };
    
        #include "compat_ace.hpp"
    
};

class CfgFunctions 
{
    class TF47 
    {
        class better_inventory
        {
            file = "z\TF47\addons\better_inventory\functions";
            class InventoryOpened;
            class ShowContainers;
        };
    };
};

#include "CfgEventHandlers.hpp"

class Extended_InventoryOpened_EventHandlers {
    class CAManBase
    {
        BetterInventory_EH = "[] call TF47_fnc_InventoryOpened";
    };
};

class Extended_InventoryClosed_EventHandlers {
    class CAManBase
    {
//        BetterInventory_EH = "[] call TF47_fnc_ChangeInventoryClosed";
    };
};

class Extended_Put_EventHandlers {
    class CAManBase
    {
        BetterInventory_EH = "[] call TF47_fnc_ShowContainers";
    };
};

class Extended_Take_EventHandlers {
    class CAManBase
    {
        BetterInventory_EH = "[] call TF47_fnc_ShowContainers";
    };
};

class RscFrame;
class RscText;
class RscListBox;
class RscActiveText;
class RscProgress;
class RscPicture;
class RscCombo;
class RscButtonMenu;
class RscStructuredText;
class RscEdit;
class RscButton;

class BI_Background_Base: RscText
{
    idc = -1;
    colorBackground[] = {1.0,1.0,1.0,0.12};
};

class BI_Frame_Base: RscFrame
{
    idc = -1;
    colorText[] = {1.0,1.0,1.0,1.0};
    colorBackground[] = {1.0,1.0,1.0,1.0}; //{1.0,1.0,1.0,0.25};
};

class RscDisplayInventory
{
/////////////////////////////////////////// Background Controls ///////////////////////////////////////////
    class ControlsBackground
    {
        class BI_Background: RscText
        {
            idc = 8800;
            x = "safeZoneX + safeZoneW * 0.15364584";
            y = "safeZoneY + safeZoneH * 0.15462963";
            w = "safeZoneW * 0.69166667";
            h = "safeZoneH * 0.68888889";
            colorBackground[] = {0.0,0.0,0.0,0.8};
        };
        
        class BI_Background_Frame: RscFrame
        {
            idc = 8850;
            x = "safeZoneX + safeZoneW * 0.15364584";
            y = "safeZoneY + safeZoneH * 0.15462963";
            w = "safeZoneW * 0.69166667";
            h = "safeZoneH * 0.68888889";
        };
        
//// Banner ////
        
        class BI_Banner_Frame: RscFrame
        {
            idc = 8851;
            x = "safeZoneX + safeZoneW * 0.15364584";
            y = "safeZoneY + safeZoneH * 0.13240741";
            w = "safeZoneW * 0.69166667";
            h = "safeZoneH * 0.02222223";
        };
        
//// Ground Box ////
/*
        class BI_Cargo_Tab_Frame: RscFrame
        {
            idc = 8851;
            x = "safeZoneX + safeZoneW * 0.23854167";
            y = "safeZoneY + safeZoneH * 0.33240741";
            w = "safeZoneW * 0.08125";
            h = "safeZoneH * 0.02777778";
        };

        class BI_Ground_Tab_Frame: RscFrame
        {
            idc = 8852;
            x = "safeZoneX + safeZoneW * 0.15729167";
            y = "safeZoneY + safeZoneH * 0.33240741";
            w = "safeZoneW * 0.08020834";
            h = "safeZoneH * 0.02777778";
        };
        
        class BI_Ground_Dropdown_Frame: RscFrame
        {
            idc = 8853;
            x = "safeZoneX + safeZoneW * 0.15729167";
            y = "safeZoneY + safeZoneH * 0.36203704";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.02777778";
        };
*/        
        class BI_Frame_Ground_Box: BI_Frame_Base
        {
            idc = 8801;
            x = "safeZoneX + safeZoneW * 0.15729167";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };
        
//// Uniform Box ////
        class BI_Frame_Uniform_Box: BI_Frame_Base
        {
            idc = 8802;
            x = "safeZoneX + safeZoneW * 0.33020834";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };
        
//// Vest Box ////
        class BI_Frame_Vest_Box: BI_Frame_Base
        {
            idc = 8803;
            x = "safeZoneX + safeZoneW * 0.50364584";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };
        
//// Backpack Box ////
        class BI_Frame_Backpack_Box: BI_Frame_Base
        {
            idc = 8804;
            x = "safeZoneX + safeZoneW * 0.67708334";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };
        
//// Primary ////
        class BI_Background_Primary: BI_Background_Base
        {
            idc = 8855;
            x = "safeZoneX + safeZoneW * 0.34739584";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
        };
        class BI_Frame_Primary: BI_Frame_Base
        {
            idc = 8805;
            x = "safeZoneX + safeZoneW * 0.34739584";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
        };
        
        class BI_Background_Primary_Silencer: BI_Background_Base
        {
            idc = 8856;
            x = "safeZoneX + safeZoneW * 0.34739584";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Primary_Silencer: BI_Frame_Base
        {
            idc = 8806;
            x = "safeZoneX + safeZoneW * 0.34739584";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Primary_Bipod: BI_Background_Base
        {
            idc = 8857;
            x = "safeZoneX + safeZoneW * 0.36875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Primary_Bipod: BI_Frame_Base
        {
            idc = 8807;
            x = "safeZoneX + safeZoneW * 0.36875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Primary_Laser: BI_Background_Base
        {
            idc = 8858;
            x = "safeZoneX + safeZoneW * 0.39010417";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Primary_Laser: BI_Frame_Base
        {
            idc = 8808;
            x = "safeZoneX + safeZoneW * 0.39010417";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Primary_Optic: BI_Background_Base
        {
            idc = 8859;
            x = "safeZoneX + safeZoneW * 0.41197917";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Primary_Optic: BI_Frame_Base
        {
            idc = 8809;
            x = "safeZoneX + safeZoneW * 0.41197917";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Primary_Underbarrel: BI_Background_Base
        {
            idc = 8860;
            x = "safeZoneX + safeZoneW * 0.4546875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Primary_Underbarrel: BI_Frame_Base
        {
            idc = 8810;
            x = "safeZoneX + safeZoneW * 0.4546875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Primary_Ammo: BI_Background_Base
        {
            idc = 8861;
            x = "safeZoneX + safeZoneW * 0.43333334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Primary_Ammo: BI_Frame_Base
        {
            idc = 8811;
            x = "safeZoneX + safeZoneW * 0.43333334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
        };
        
//// Launcher ////
        class BI_Background_Launcher: BI_Background_Base
        {
            idc = 8862;
            x = "safeZoneX + safeZoneW * 0.52083334";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
        };
        class BI_Frame_Launcher: BI_Frame_Base
        {
            idc = 8812;
            x = "safeZoneX + safeZoneW * 0.52083334";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
        };
        
        class BI_Background_Launcher_Silencer: BI_Background_Base
        {
            idc = 8863;
            x = "safeZoneX + safeZoneW * 0.52083334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Launcher_Silencer: BI_Frame_Base
        {
            idc = 8813;
            x = "safeZoneX + safeZoneW * 0.52083334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Launcher_Bipod: BI_Background_Base
        {
            idc = 8864;
            x = "safeZoneX + safeZoneW * 0.546875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Launcher_Bipod: BI_Frame_Base
        {
            idc = 8814;
            x = "safeZoneX + safeZoneW * 0.546875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Launcher_Laser: BI_Background_Base
        {
            idc = 8865;
            x = "safeZoneX + safeZoneW * 0.57239584";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Launcher_Laser: BI_Frame_Base
        {
            idc = 8815;
            x = "safeZoneX + safeZoneW * 0.57239584";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Launcher_Optic: BI_Background_Base
        {
            idc = 8866;
            x = "safeZoneX + safeZoneW * 0.5984375";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Launcher_Optic: BI_Frame_Base
        {
            idc = 8816;
            x = "safeZoneX + safeZoneW * 0.5984375";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Launcher_Ammo: BI_Background_Base
        {
            idc = 8867;
            x = "safeZoneX + safeZoneW * 0.62395834";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Launcher_Ammo: BI_Frame_Base
        {
            idc = 8817;
            x = "safeZoneX + safeZoneW * 0.62395834";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
//// Secondary ////
        class BI_Background_Secondary: BI_Background_Base
        {
            idc = 8868;
            x = "safeZoneX + safeZoneW * 0.69375";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
        };
        class BI_Frame_Secondary: BI_Frame_Base
        {
            idc = 8818;
            x = "safeZoneX + safeZoneW * 0.69375";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
        };
        
        class BI_Background_Secondary_Silencer: BI_Background_Base
        {
            idc = 8869;
            x = "safeZoneX + safeZoneW * 0.69375";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Secondary_Silencer: BI_Frame_Base
        {
            idc = 8819;
            x = "safeZoneX + safeZoneW * 0.69375";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Secondary_Bipod: BI_Background_Base
        {
            idc = 8870;
            x = "safeZoneX + safeZoneW * 0.71927084";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Secondary_Bipod: BI_Frame_Base
        {
            idc = 8820;
            x = "safeZoneX + safeZoneW * 0.71927084";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Secondary_Laser: BI_Background_Base
        {
            idc = 8871;
            x = "safeZoneX + safeZoneW * 0.7453125";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Secondary_Laser: BI_Frame_Base
        {
            idc = 8821;
            x = "safeZoneX + safeZoneW * 0.7453125";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Secondary_Optic: BI_Background_Base
        {
            idc = 8872;
            x = "safeZoneX + safeZoneW * 0.77083334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Secondary_Optic: BI_Frame_Base
        {
            idc = 8822;
            x = "safeZoneX + safeZoneW * 0.77083334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
        class BI_Background_Secondary_Ammo: BI_Background_Base
        {
            idc = 8873;
            x = "safeZoneX + safeZoneW * 0.796875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        class BI_Frame_Secondary_Ammo: BI_Frame_Base
        {
            idc = 8823;
            x = "safeZoneX + safeZoneW * 0.796875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
        };
        
//// Uniform ////
        class BI_Background_Uniform: BI_Background_Base
        {
            idc = 8874;
            x = "safeZoneX + safeZoneW * 0.39270834";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        class BI_Frame_Uniform: BI_Frame_Base
        {
            idc = 8824;
            x = "safeZoneX + safeZoneW * 0.39270834";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        
//// Vest ////
        class BI_Background_Vest: BI_Background_Base
        {
            idc = 8875;
            x = "safeZoneX + safeZoneW * 0.56614584";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        class BI_Frame_Vest: BI_Frame_Base
        {
            idc = 8825;
            x = "safeZoneX + safeZoneW * 0.56614584";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };

//// Backpack ////
        class BI_Background_Backpack: BI_Background_Base
        {
            idc = 8876;
            x = "safeZoneX + safeZoneW * 0.7390625";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        class BI_Frame_Backpack: BI_Frame_Base
        {
            idc = 8826;
            x = "safeZoneX + safeZoneW * 0.7390625";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        
//// Helmet ////
        class BI_Background_Helmet: BI_Background_Base
        {
            idc = 8877;
            x = "safeZoneX + safeZoneW * 0.15989584";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        class BI_Frame_Helmet: BI_Frame_Base
        {
            idc = 8827;
            x = "safeZoneX + safeZoneW * 0.15989584";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        
//// Facewear ////
        class BI_Background_Facewear: BI_Background_Base
        {
            idc = 8878;
            x = "safeZoneX + safeZoneW * 0.20104167";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        class BI_Frame_Facewear: BI_Frame_Base
        {
            idc = 8828;
            x = "safeZoneX + safeZoneW * 0.20104167";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        
//// NVG ////
        class BI_Background_NVG: BI_Background_Base
        {
            idc = 8879;
            x = "safeZoneX + safeZoneW * 0.2421875";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        class BI_Frame_NVG: BI_Frame_Base
        {
            idc = 8829;
            x = "safeZoneX + safeZoneW * 0.2421875";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        
//// Binocular ////
        class BI_Background_Binocular: BI_Background_Base
        {
            idc = 8880;
            x = "safeZoneX + safeZoneW * 0.28385417";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        class BI_Frame_Binocular: BI_Frame_Base
        {
            idc = 8830;
            x = "safeZoneX + safeZoneW * 0.28385417";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
        };
        
//// Map ////
        class BI_Background_Map: BI_Background_Base
        {
            idc = 8881;
            x = "safeZoneX + safeZoneW * 0.16927084";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
        class BI_Frame_Map: BI_Frame_Base
        {
            idc = 8831;
            x = "safeZoneX + safeZoneW * 0.16927084";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
        
//// GPS ////
        class BI_Background_GPS: BI_Background_Base
        {
            idc = 8882;
            x = "safeZoneX + safeZoneW * 0.1984375";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
        class BI_Frame_GPS: BI_Frame_Base
        {
            idc = 8832;
            x = "safeZoneX + safeZoneW * 0.1984375";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
        
//// Radio ////
    /*
        #if __has_include("\idi\acre\addons\main\script_component.hpp")
        
        #else
    */
        class BI_Background_Radio: BI_Background_Base
        {
            idc = 8883;
            x = "safeZoneX + safeZoneW * 0.22760417";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
        class BI_Frame_Radio: BI_Frame_Base
        {
            idc = 8833;
            x = "safeZoneX + safeZoneW * 0.22760417";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
    /*
        #endif
    */
//// Compass ////
        class BI_Background_Compass: BI_Background_Base
        {
            idc = 8884;
            x = "safeZoneX + safeZoneW * 0.25677084";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
        class BI_Frame_Compass: BI_Frame_Base
        {
            idc = 8834;
            x = "safeZoneX + safeZoneW * 0.25677084";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
        
//// Clock ////
        class BI_Background_Clock: BI_Background_Base
        {
            idc = 8885;
            x = "safeZoneX + safeZoneW * 0.2859375";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
        class BI_Frame_Clock: BI_Frame_Base
        {
            idc = 8835;
            x = "safeZoneX + safeZoneW * 0.2859375";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
        };
    };
/////////////////////////////////////////// Controls ///////////////////////////////////////////
    class controls
    {
        
//// Top Banner Background Line ////
        class TitleBackground: RscText
        {
            //idc = 1020;
            x = "safeZoneX + safeZoneW * 0.15364584";
            y = "safeZoneY + safeZoneH * 0.13240741";
            w = "safeZoneW * 0.69166667";
            h = "safeZoneH * 0.02222223";
        };
        
//// Top Banner Rank Insigne Background ////
        class RankBackground: RscText
        {
            //idc = 1014;
            x = "safeZoneX + safeZoneW * 0.15364584";
            y = "safeZoneY + safeZoneH * 0.13240741";
            w = "safeZoneW * 0.01145834";
            h = "safeZoneH * 0.02222223";
        };

//// Top Banner Rank Insigne Icon ////
        class RankPicture: RscPicture
        {
            //idc = 1203;
            x = "safeZoneX + safeZoneW * 0.15364584";
            y = "safeZoneY + safeZoneH * 0.13240741";
            w = "safeZoneW * 0.01145834";
            h = "safeZoneH * 0.02222223";
        };

//// Top Banner Player Name ////
        class PlayersName: RscText
        {
            //idc = 111;
            x = "safeZoneX + safeZoneW * 0.16822917";
            y = "safeZoneY + safeZoneH * 0.13240741";
            w = "safeZoneW * 0.45364584";
            h = "safeZoneH * 0.02222223";
        };
        
//// Top Banner Exit Button ////
        class ButtonBack: RscActiveText
        {
            //idc = 2;
            x = "safeZoneX + safeZoneW * 0.8328125";
            y = "safeZoneY + safeZoneH * 0.13240741";
            w = "safeZoneW * 0.01145834";
            h = "safeZoneH * 0.02222223";
        };
        
//// Ground Itemlist Weight ////
        class GroundLoad: RscProgress
        {
            //idc = 6307;
            x = "safeZoneX + safeZoneW * 0.15729167";
            y = "safeZoneY + safeZoneH * 0.82407408";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.01111112";
            colorFrame[] = {1,1,1,1};
        };

//// Ground Itemlist ////
        class GroundContainer: RscListBox
        {
            itemBackground[] = {1,1,1,0.2};
            x = "safeZoneX + safeZoneW * 0.15729167";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };
        class SoldierContainer: GroundContainer
        {
            itemBackground[] = {1,1,1,0.2};
            x = "safeZoneX + safeZoneW * 0.15729167";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };
    
//// Ground Tab ////
        class GroundTab: RscActiveText
        {
            //idc = 6321;
            x = "safeZoneX + safeZoneW * 0.15729167";
            y = "safeZoneY + safeZoneH * 0.33240741";
            w = "safeZoneW * 0.08020834";
            h = "safeZoneH * 0.02777778";
        };
        
//// Cargo Container Tab ////
        class SoldierTab: GroundTab
        {
            //idc = 6401;
            x = "safeZoneX + safeZoneW * 0.23854167";
            y = "safeZoneY + safeZoneH * 0.33240741";
            w = "safeZoneW * 0.08125";
            h = "safeZoneH * 0.02777778";
        };
        
//// Ground Filter Dropdown Menu ////
        class GroundFilter: RscCombo
        {
            //idc = 6554;
            x = "safeZoneX + safeZoneW * 0.15729167";
            y = "safeZoneY + safeZoneH * 0.36203704";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.02777778";
        };
        
//// Inventory White Selection ////
        class ContainerMarker: GroundTab
        {
            //idc = 6325;
            x = "100.995";
            y = "0.148";
            w = "0.33";
            h = "0.736";
        };
        
//// Ground White Selection ////
        class GroundMarker: ContainerMarker
        {
            //idc = 6385;
            x = "100.995";
            y = "0.148";
            w = "0.33";
            h = "0.736";
        };
        
//// Total Weight ////
        class TotalLoad: GroundLoad
        {
            //idc = 6308;
            x = "safeZoneX + safeZoneW * 0.3296875";
            y = "safeZoneY + safeZoneH * 0.82407408";
            w = "safeZoneW * 0.509375";
            h = "safeZoneH * 0.01111112";
            colorFrame[] = {1,1,1,1};
        };
        
//// Primary ////
        class SlotPrimary: GroundTab
        {
            //idc = 610;
            x = "safeZoneX + safeZoneW * 0.34739584";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
            colorBackground[] = {1,1,1,0.1};
        };
        
        class SlotPrimaryMuzzle: SlotPrimary
        {
            //idc = 620;
            x = "safeZoneX + safeZoneW * 0.34739584";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotPrimaryUnderBarrel: SlotPrimary
        {
            //idc = 641;
            x = "safeZoneX + safeZoneW * 0.36875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotPrimaryFlashlight: SlotPrimary
        {
            //idc = 622;
            x = "safeZoneX + safeZoneW * 0.39010417";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotPrimaryOptics: SlotPrimary
        {
            //idc = 621;
            x = "safeZoneX + safeZoneW * 0.41197917";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotPrimaryMagazineGL: SlotPrimary
        {
            //idc = 644;
            x = "safeZoneX + safeZoneW * 0.43333334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotPrimaryMagazine: SlotPrimary
        {
            //idc = 623;
            x = "safeZoneX + safeZoneW * 0.4546875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.02083334";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Launcher ////
        class SlotSecondary: SlotPrimary
        {
            //idc = 611;
            x = "safeZoneX + safeZoneW * 0.52083334";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotSecondaryMuzzle: SlotPrimary
        {
            //idc = 624;
            x = "safeZoneX + safeZoneW * 0.52083334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotSecondaryUnderBarrel: SlotPrimary
        {
            //idc = 642;
            x = "safeZoneX + safeZoneW * 0.546875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotSecondaryFlashlight: SlotPrimary
        {
            //idc = 626;
            x = "safeZoneX + safeZoneW * 0.57239584";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotSecondaryOptics: SlotPrimary
        {
            //idc = 625;
            x = "safeZoneX + safeZoneW * 0.5984375";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotSecondaryMagazine: SlotPrimary
        {
            //idc = 627;
            x = "safeZoneX + safeZoneW * 0.62395834";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Secondary ////
        class SlotHandgun: SlotPrimary
        {
            //idc = 612;
            x = "safeZoneX + safeZoneW * 0.69375";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.128125";
            h = "safeZoneH * 0.08240741";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotHandgunMuzzle: SlotPrimary
        {
            //idc = 628;
            x = "safeZoneX + safeZoneW * 0.69375";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotHandgunUnderBarrel: SlotPrimary
        {
            //idc = 643;
            x = "safeZoneX + safeZoneW * 0.71927084";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotHandgunFlashlight: SlotPrimary
        {
            //idc = 630;
            x = "safeZoneX + safeZoneW * 0.7453125";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotHandgunOptics: SlotPrimary
        {
            //idc = 629;
            x = "safeZoneX + safeZoneW * 0.77083334";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        class SlotHandgunMagazine: SlotPrimary
        {
            //idc = 631;
            x = "safeZoneX + safeZoneW * 0.796875";
            y = "safeZoneY + safeZoneH * 0.25";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03333334";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Uniform ////
        class UniformSlot: SlotPrimary
        {
            //idc = 6331;
            x = "safeZoneX + safeZoneW * 0.39270834";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Uniform Weight ////
        class UniformLoad: GroundLoad
        {
            //idc = 6304;
            x = "safeZoneX + safeZoneW * 0.39270834";
            y = "safeZoneY + safeZoneH * 0.37777778";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.01111112";
            colorFrame[] = {1,1,1,1};
        };

//// Uniform Itemlist ////
        class UniformContainer: GroundContainer
        {
            //idc = 633;
            x = "safeZoneX + safeZoneW * 0.33020834";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };

//// Vest ////
        class VestSlot: SlotPrimary
        {
            //idc = 6381;
            x = "safeZoneX + safeZoneW * 0.56614584";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Vest Weight ////
        class VestLoad: GroundLoad
        {
            //idc = 6305;
            x = "safeZoneX + safeZoneW * 0.56614584";
            y = "safeZoneY + safeZoneH * 0.37777778";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.01111112";
            colorFrame[] = {1,1,1,1};
        };

//// Vest Itemlist ////
        class VestContainer: UniformContainer
        {
            //idc = 638;
            x = "safeZoneX + safeZoneW * 0.50364584";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };

//// Backpack ////
        class BackpackSlot: SlotPrimary
        {
            //idc = 6191;
            x = "safeZoneX + safeZoneW * 0.7390625";
            y = "safeZoneY + safeZoneH * 0.31111112";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Backpack Weight ////
        class BackpackLoad: GroundLoad
        {
            //idc = 6306;
            x = "safeZoneX + safeZoneW * 0.7390625";
            y = "safeZoneY + safeZoneH * 0.37777778";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.01111112";
            colorFrame[] = {1,1,1,1};
        };

//// Backpack Itemlist ////
        class BackpackContainer: UniformContainer
        {
            //idc = 619;
            x = "safeZoneX + safeZoneW * 0.67708334";
            y = "safeZoneY + safeZoneH * 0.39351852";
            w = "safeZoneW * 0.1625";
            h = "safeZoneH * 0.425";
        };

//// Helmet ////
        class SlotHeadgear: SlotPrimary
        {
            //idc = 6240;
            x = "safeZoneX + safeZoneW * 0.15989584";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Facewear ////
        class SlotGoggles: SlotPrimary
        {
            //idc = 6216;
            x = "safeZoneX + safeZoneW * 0.20104167";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// NVG ////
        class SlotHMD: SlotPrimary
        {
            //idc = 6217;
            x = "safeZoneX + safeZoneW * 0.2421875";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Binocular ////
        class SlotBinoculars: SlotPrimary
        {
            //idc = 6238;
            x = "safeZoneX + safeZoneW * 0.28385417";
            y = "safeZoneY + safeZoneH * 0.16574075";
            w = "safeZoneW * 0.03697917";
            h = "safeZoneH * 0.06574075";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Map ////
        class SlotMap: SlotPrimary
        {
            //idc = 6211;
            x = "safeZoneX + safeZoneW * 0.16927084";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// GPS ////
        class SlotGPS: SlotPrimary
        {
            //idc = 6215;
            x = "safeZoneX + safeZoneW * 0.1984375";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Radio ////
    /*
        #if __has_include("\idi\acre\addons\main\script_component.hpp")
        class SlotRadio: SlotPrimary
        {
            w = "0";
            h = "0";
        };
        #else
    */
        class SlotRadio: SlotPrimary
        {
            //idc = 6214;
            x = "safeZoneX + safeZoneW * 0.22760417";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
            colorBackground[] = {1,1,1,0.1};
        };
    /*
        #endif
    */    
//// Compass ////
        class SlotCompass: SlotPrimary
        {
            //idc = 6212;
            x = "safeZoneX + safeZoneW * 0.25677084";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Clock ////
        class SlotWatch: SlotPrimary
        {
            //idc = 6213;
            x = "safeZoneX + safeZoneW * 0.2859375";
            y = "safeZoneY + safeZoneH * 0.24444445";
            w = "safeZoneW * 0.025";
            h = "safeZoneH * 0.03888889";
            colorBackground[] = {1,1,1,0.1};
        };
        
//// Hidden ////
        class CA_ContainerBackground: RscText
        {
            w = "0";
            h = "0";
        };
        class CA_PlayerBackground: RscText
        {
            w = "0";
            h = "0";
        };
        class UniformTab: GroundTab
        {
            w = "0";
            h = "0";
        };
        class VestTab: UniformTab
        {
            w = "0";
            h = "0";
        };
        class BackpackTab: UniformTab
        {
            w = "0";
            h = "0";
        };
        
//// Exile compat ////
        /*
        #if __has_include("\exile_client\bootstrap\fn_postInit.sqf")
            #include "compat_exile_RscDisplayInventory.hpp"
        #endif
        */
    };
};
