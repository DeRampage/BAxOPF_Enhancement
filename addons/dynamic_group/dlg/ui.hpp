class RscDisplayDynamicGroups
{
    scriptName = "RscDisplayDynamicGroups";
    scriptPath = "TF47_dynGrp";
    onLoad = "[""onLoad"",_this,""RscDisplayDynamicGroups"",'TF47_dynGrp'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
    onUnload = "[""onUnload"",_this,""RscDisplayDynamicGroups"",'TF47_dynGrp'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
    class controls
    {
        class SectionManage: RscControlsGroupNoScrollbars
        {
            class controls
            {
                class TextPlayerSide: RscText
                {
                    shadow = 0;
                    style = 1;
                    idc = 9383;
                    text = "$STR_TF47_dynamic_group_Uniform";
                    x = "0.4 * ( ( (safezoneW / safezoneH) min 1.2) / 40)";
                    y = "3.2 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    w = "3.4 * ( ( (safezoneW / safezoneH) min 1.2) / 40)";
                    h = "1.2 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    colorText[] = {0,0,0,1};
                    colorBackground[] = {0.6,0.6,0.6,0.6};
                    sizeEx = "0.9 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                };
                class TextPlayerScore: RscText
                {
                    shadow = 0;
                    style = 1;
                    idc = 9386;
                    text = "$STR_TF47_dynamic_group_Freq";
                    x = "0.4 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
                    y = "4.5 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    w = "3.4 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "1.2 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    colorText[] = {0,0,0,1};
                    colorBackground[] = {0.6,0.6,0.6,0.6};
                    sizeEx = "0.9 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                };
                class TextPlayerSideFill: RscText
                {
                    shadow = 0;
                    style = 0;
                    idc = 9388;
                    x = "3.8 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
                    y = "3.2 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    w = "8.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "1.2 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    colorBackground[] = {0.4,0.4,0.4,0.6};
                };
                class TextPlayerScoreFill: RscText
                {
                    shadow = 0;
                    style = 0;
                    idc = 9389;
                    x = "3.8 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
                    y = "4.5 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    w = "8.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "1.2 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    colorBackground[] = {0.4,0.4,0.4,0.6};
                };
                class TextPrivate: RscText
                {
                    text = "$STR_TF47_dynamic_group_Role";
                };
                class TextGroupRole: RscText
                {
                    shadow = 0;
                    style = 0;
                    idc = 9399999;
                    text = "Inf";
                    x = "3.8 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
                    y = "5.8 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    w = "8.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "1.2 * ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    colorBackground[] = {0.4,0.4,0.4,0.6};
                };

               class TF47_SelInsiBtn: RscButton
                {
                    colorText[] = {0,0,0,0};
                    colorDisabled[] = {0,0,0,0};
                    colorBackground[] = {0,0,0,0};
                    colorBackgroundDisabled[] = {0,0,0,0};
                    colorBackgroundActive[] = {0,0,0,0};
                    colorFocused[] = {0,0,0,0};
                    colorShadow[] = {0,0,0,0};
                    colorBorder[] = {0,0,0,0};

                    x = "12.3 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    y = "1.9 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    w = "7 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "5.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    action = "call TF47_fnc_selInsi;";
                };
                class CheckboxPrivate: RscCheckBox
                {
                    idc = -1;
                    x = "500000 ";
                    y = "500000 ";
                    w = "0.0001 ";
                    h = "0.0001 ";
                };
            };
        };
        class ButtonPromoteDisband: RscButton
        {
            idc = 9979;
            text = "";
            x = "30.1 *   ( ((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)";
            y = "18.4 *   ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - ( ((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
            w = "9.3 *    ( ((safezoneW / safezoneH) min 1.2) / 40)";
            h = "2 *      ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            colorBackground[] = {-1,-1,-1,-1};
        };
        
        class TF47_SetgrpBtn: RscButton
        {
            idc = 9340052;
            text = "$STR_TF47_dynamic_group_setRole";  //--- ToDo: Localize;
            x = "30.1 *   ( ((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)";
            y = "18.4 *   ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - ( ((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
            w = "9.3 *    ( ((safezoneW / safezoneH) min 1.2) / 40)";
            h = "2 *      ( ( ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            //action = "createDialog  'Rsctf47_DynGrp_setGrp';";
        };
        class TF47_SetInsiBtn: RscButton
        {
            idc = 934000;
            text = "$STR_TF47_dynamic_group_selInsi"; //--- ToDo: Localize;
            x = "0.624781 * safezoneW + safezoneX";
            y = "0.676 * safezoneH + safezoneY";
            w = "0.115088 * safezoneW";
            h = "0.044 * safezoneH";
            action = "call TF47_fnc_selInsi;";
        };
    };
};
