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
			file = "plp\PLP_ladderTweakRemastered\data\ladderUpCiv.rtm";
			speed = "-(25/30)";
			InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderCivilStatic",0.1,"PLP_LTR_LadderCivilDownLoop",0.1,"LadderCivilTopOff",0.1,"PLP_LTR_LadderCivilSlide",0.1};
			stamina = -1;
		};
		class PLP_LTR_LadderCivilDownLoop: LadderCivilUpLoop
		{
			file = "plp\PLP_ladderTweakRemastered\data\ladderDownCiv.rtm";
			speed = "-(25/30)/1.1111";
			InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderCivilStatic",0.1,"PLP_LTR_LadderCivilUpLoop",0.1,"LadderCivilDownOff",0.1,"PLP_LTR_LadderCivilSlide",0.1};
			stamina = -0.3;
		};
		class PLP_LTR_LadderRifleUpLoop: LadderCivilUpLoop
		{
			file = "plp\PLP_ladderTweakRemastered\data\ladderUpRfl.rtm";
			speed = "-(25/30)/1.1111";
			InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderRifleStatic",0.1,"PLP_LTR_LadderRifleDownLoop",0.1,"LadderRifleTopOff",0.1,"PLP_LTR_LadderRifleSlide",0.1};
			actions = "LadderRifleActions";
			stamina = -1;
		};
		class PLP_LTR_LadderRifleDownLoop: PLP_LTR_LadderRifleUpLoop
		{
			file = "plp\PLP_ladderTweakRemastered\data\ladderDownRfl.rtm";
			InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderRifleStatic",0.1,"PLP_LTR_LadderRifleUpLoop",0.1,"LadderRifleDownOff",0.1,"PLP_LTR_LadderRifleSlide",0.1};
			stamina = -0.3;
		};
		class PLP_LTR_LadderCivilStatic: LadderCivilStatic
		{
			file = "plp\PLP_ladderTweakRemastered\data\ladderStaticCiv.rtm";
			InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderCivilUpLoop",0.1,"PLP_LTR_LadderCivilDownLoop",0.1,"PLP_LTR_LadderCivilSlide",0.1};
		};
		class PLP_LTR_LadderRifleStatic: LadderRifleStatic
		{
			file = "plp\PLP_ladderTweakRemastered\data\ladderStaticRfl.rtm";
			InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderRifleUpLoop",0.1,"PLP_LTR_LadderRifleDownLoop",0.1,"PLP_LTR_LadderRifleSlide",0.1};
		};
		class PLP_LTR_LadderCivilSlide: LadderCivilStatic
		{
			file = "plp\PLP_ladderTweakRemastered\data\ladderSlideCiv.rtm";
			InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderCivilSlideEnd",0.01};
			actions = "NoActions";
		};
		class PLP_LTR_LadderRifleSlide: LadderRifleStatic
		{
			file = "plp\PLP_ladderTweakRemastered\data\ladderSlideRfl.rtm";
			InterpolateTo[] = {"Unconscious",0.02,"PLP_LTR_LadderRifleSlideEnd",0.01};
			actions = "NoActions";
		};
		class PLP_LTR_LadderCivilSlideEnd: LadderCivilStatic
		{
			looped = 0;
			speed = "-(37/30)";
			file = "plp\PLP_ladderTweakRemastered\data\ladderSlideEndCiv.rtm";
			InterpolateTo[] = {"Unconscious",0.02,"AmovPercMstpSnonWnonDnon",0.3};
			actions = "NoActions";
		};
		class PLP_LTR_LadderRifleSlideEnd: LadderRifleStatic
		{
			looped = 0;
			speed = "-(37/30)";
			file = "plp\PLP_ladderTweakRemastered\data\ladderSlideEndRfl.rtm";
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
				file = "plp\PLP_ladderTweakRemastered\fn_ladderSlideDown.sqf";
			};
		};
	};
};
