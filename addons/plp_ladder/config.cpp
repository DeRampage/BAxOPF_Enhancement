#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Data_F_AoW_Loadorder"};
        author = "Rampage";
        VERSION_CONFIG;
    };
};
class CfgMovesBasic
{
    class Actions
    {
        class NoActions;
        class LadderCivilActions: NoActions
        {
            stop = "PLP_LTR_LadderCivilStatic";
            default = "PLP_LTR_LadderCivilStatic";
            down = "PLP_LTR_LadderCivilDownLoop";
            up = "PLP_LTR_LadderCivilUpLoop";
        };
        class LadderRifleActions: LadderCivilActions
        {
            stop = "PLP_LTR_LadderRifleStatic";
            default = "PLP_LTR_LadderRifleStatic";
            down = "PLP_LTR_LadderRifleDownLoop";
            up = "PLP_LTR_LadderRifleUpLoop";
        };
    };
    class StandBase;
};
class CfgMovesMaleSdr: CfgMovesBasic
{
    class States
    {
        class LadderCivilStatic;
        class LadderRifleStatic;
        class LadderCivilOn_Top: LadderCivilStatic
        {
            ConnectTo[] = {"PLP_LTR_LadderCivilStatic",1};
        };
        class LadderRifleOn: LadderCivilOn_Top
        {
            ConnectTo[] = {"PLP_LTR_LadderRifleStatic",1};
        };
        class LadderCivilUpLoop;
        class PLP_LTR_LadderCivilUpLoop: LadderCivilUpLoop
        {
            file = "z\TF47\addons\plp_ladder\data\ladderUpCiv.rtm";
            speed = "-(25/30)";
            InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderCivilStatic",0.1,"PLP_LTR_LadderCivilDownLoop",0.1,"LadderCivilTopOff",0.1,"PLP_LTR_LadderCivilSlide",0.1};
            stamina = -1;
        };
        class PLP_LTR_LadderCivilDownLoop: LadderCivilUpLoop
        {
            file = "z\TF47\addons\plp_ladder\data\ladderDownCiv.rtm";
            speed = "-(25/30)/1.1111";
            InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderCivilStatic",0.1,"PLP_LTR_LadderCivilUpLoop",0.1,"LadderCivilDownOff",0.1,"PLP_LTR_LadderCivilSlide",0.1};
            stamina = -0.3;
        };
        class PLP_LTR_LadderRifleUpLoop: LadderCivilUpLoop
        {
            file = "z\TF47\addons\plp_ladder\data\ladderUpRfl.rtm";
            speed = "-(25/30)/1.1111";
            InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderRifleStatic",0.1,"PLP_LTR_LadderRifleDownLoop",0.1,"LadderRifleTopOff",0.1,"PLP_LTR_LadderRifleSlide",0.1};
            actions = "LadderRifleActions";
            stamina = -1;
        };
        class PLP_LTR_LadderRifleDownLoop: PLP_LTR_LadderRifleUpLoop
        {
            file = "z\TF47\addons\plp_ladder\data\ladderDownRfl.rtm";
            InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderRifleStatic",0.1,"PLP_LTR_LadderRifleUpLoop",0.1,"LadderRifleDownOff",0.1,"PLP_LTR_LadderRifleSlide",0.1};
            stamina = -0.3;
        };
        class PLP_LTR_LadderCivilStatic: LadderCivilStatic
        {
            file = "z\TF47\addons\plp_ladder\data\ladderStaticCiv.rtm";
            InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderCivilUpLoop",0.1,"PLP_LTR_LadderCivilDownLoop",0.1,"PLP_LTR_LadderCivilSlide",0.1};
        };
        class PLP_LTR_LadderRifleStatic: LadderRifleStatic
        {
            file = "z\TF47\addons\plp_ladder\data\ladderStaticRfl.rtm";
            InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderRifleUpLoop",0.1,"PLP_LTR_LadderRifleDownLoop",0.1,"PLP_LTR_LadderRifleSlide",0.1};
        };
        class PLP_LTR_LadderCivilSlide: LadderCivilStatic
        {
            file = "z\TF47\addons\plp_ladder\data\ladderSlideCiv.rtm";
            InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderCivilSlideEnd",0.01};
            actions = "NoActions";
        };
        class PLP_LTR_LadderRifleSlide: LadderRifleStatic
        {
            file = "z\TF47\addons\plp_ladder\data\ladderSlideRfl.rtm";
            InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderRifleSlideEnd",0.01};
            actions = "NoActions";
        };
        class PLP_LTR_LadderCivilSlideEnd: LadderCivilStatic
        {
            looped = 0;
            speed = "-(37/30)";
            file = "z\TF47\addons\plp_ladder\data\ladderSlideEndCiv.rtm";
            InterpolateTo[] = {"Unconscious",0.02,"AmovPercMstpSnonWnonDnon",0.3};
            actions = "NoActions";
        };
        class PLP_LTR_LadderRifleSlideEnd: LadderRifleStatic
        {
            looped = 0;
            speed = "-(37/30)";
            file = "z\TF47\addons\plp_ladder\data\ladderSlideEndRfl.rtm";
            InterpolateTo[] = {"Unconscious",0.02,"AmovPercMstpSlowWrflDnon",0.3};
            actions = "NoActions";
        };
    };
};
class CfgAnimation
{
    ladderSpeed = "0.5*2.5";
};
class CfgUserActions
{
    class PLP_LTR_ladderSlideDown
    {
        displayName = "Slide Down";
        tooltip = "Slide down the ladder.";
        onActivate = "call PLP_fnc_LTR_ladderSlideDown";
    };
};
class CfgDefaultKeysPresets
{
    class Arma2
    {
        class Mappings
        {
            PLP_LTR_ladderSlideDown[] = {"0x1D + 256 + 0x1F"};
        };
    };
};
class UserActionGroups
{
    class PLP_ladderTweakRemastered
    {
        name = "Ladder Tweak Remastered";
        isAddon = 1;
        group[] = {"PLP_LTR_ladderSlideDown"};
    };
};
class CfgFunctions
{
    class PLP
    {
        class LTR
        {
            class LTR_ladderSlideDown
            {
                file = "z\TF47\addons\plp_ladder\fn_ladderSlideDown.sqf";
            };
        };
    };
};
