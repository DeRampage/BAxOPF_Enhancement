/*
    
    author: -SONIC-
    
    description:
        Dialog defines.
    parameter:
        nothing
    return
        nothing
    example
        na
        
*/

class RscControlsGroupNoScrollbars;
class RscButton;
class RscText;
class RscFrame;
class RscEdit;
class RscCombo;
class RscCheckBox;
class RscActiveText;

class tf47_DynGrp_base_scrollbar
{
    color[] = {1,1,1,0.6};
    colorActive[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.3};
    shadow = 0;
    thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
    arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
    arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
    border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
};
class tf47_DynGrp_base_combo : RscCombo
{
    type = 4;
    colorSelect[] = {0,0,0,1};
    colorText[] = {0.95,0.95,0.95,1};
    colorBackground[] = {0,0,0,1};
    colorScrollbar[] = {1,0,0,1};
    soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1};
    soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1};
    soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1};
    maxHistoryDelay = 1;
    class ComboScrollBar : tf47_DynGrp_base_scrollbar
    {
    };
    style = 16;
    w = 0.12;
    h = 0.035;
    shadow = 0;
    colorSelectBackground[] = {1,1,1,0.7};
    arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
    arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
    wholeHeight = 0.45;
    color[] = {1,1,1,1};
    colorActive[] = {1,0,0,1};
    colorDisabled[] = {1,1,1,0.25};
};

