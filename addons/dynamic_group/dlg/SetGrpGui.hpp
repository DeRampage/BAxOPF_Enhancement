class Rsctf47_DynGrp_setGrp
{
    idd = 135624;
    movingEnable = false;
    onLoad = "uiNamespace setVariable ['tf47_dyngrp_setgrp_dialog_var',(_this select 0)]; [] spawn TF47_fnc_initsetGrp;"; 
    onUnLoad = "uiNamespace setVariable ['tf47_dyngrp_setgrp_dialog_var',nil]"; 
    class ControlsBackground
    {
        class BackgroundsetGrp: RscText
        {
            x = 0.380169 * safezoneW + safezoneX;
            y = 0.2668 * safezoneH + safezoneY;
            w = 0.243787 * safezoneW;
            h = 0.3652 * safezoneH;
            colorBackground[]={0,0,0,0.69999999};
        };
    };
    class Controls
    {
        class Header: RscText
        {
            idc=-1;
            text="$STR_TF47_dynamic_group_SetGroupData";
            x = 0.380169 * safezoneW + safezoneX;
            y = 0.2382 * safezoneH + safezoneY;
            w = 0.243787 * safezoneW;
            h = 0.0264 * safezoneH;
            colorText[]={1,1,1,1};
            colorBackground[]=
            {
                "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
                "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
                "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
                "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
            };
            sizeEx="1.25 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        };

        class Freq_titel: RscText
        {
            idc = 1001;
            text = "$STR_TF47_dynamic_group_IntFreq"; //--- ToDo: Localize;
            x = 0.432969 * safezoneW + safezoneX;
            y = 0.445 * safezoneH + safezoneY;
            w = 0.0979687 * safezoneW;
            h = 0.033 * safezoneH;
        };
        class Freq_edit: RscEdit
        {
            idc = 1400;
            x = 0.432969 * safezoneW + safezoneX;
            y = 0.4846 * safezoneH + safezoneY;
            w = 0.139219 * safezoneW;
            h = 0.044 * safezoneH;
            colorBackground[] = {-1,-1,-1,0.5};
            colorActive[] = {-1,-1,-1,1};
        };
        class Role_titel: RscText
        {
            idc = 1003;
            text = "Role"; //--- ToDo: Localize;
            x = 0.432969 * safezoneW + safezoneX;
            y = 0.313 * safezoneH + safezoneY;
            w = 0.0979687 * safezoneW;
            h = 0.033 * safezoneH;
        };
        class Role_Combo: RscCombo
        {
            idc = 2100;
            x = 0.432969 * safezoneW + safezoneX;
            y = 0.3504 * safezoneH + safezoneY;
            w = 0.134062 * safezoneW;
            h = 0.033 * safezoneH;
        };
        class ButtonApply: RscButton
        {
            idc = 9978;

            text = "$STR_TF47_dynamic_group_Apply"; //--- ToDo: Localize;
            x = 0.501238 * safezoneW + safezoneX;
            y = 0.6364 * safezoneH + safezoneY;
            w = 0.122513 * safezoneW;
            h = 0.044 * safezoneH;
            action = "[] call TF47_fnc_applysetGrp;";
        };
        class ButtonCancel: RscButton
        {
            idc = 9980;

            text = "$STR_TF47_dynamic_group_Cancel"; //--- ToDo: Localize;
            x = 0.379962 * safezoneW + safezoneX;
            y = 0.6364 * safezoneH + safezoneY;
            w = 0.1188 * safezoneW;
            h = 0.044 * safezoneH;
            action = "closeDialog 0; ([] call BIS_fnc_displayMission) createDisplay 'RscDisplayDynamicGroups';";
        };
    };
};
