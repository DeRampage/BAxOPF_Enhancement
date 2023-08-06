#include "BIS_AddonInfo.hpp"
class CfgPatches {
    class ClearTree {
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.0;
        requiredAddons[] = {"ace_common"};
        version = 2.0.1;
        versionStr = 2.0.1;
        versionAr[] = {2, 0, 1};
        author = "Ampersand, Rabbit";
    };
};

class Extended_PreInit_EventHandlers {
    class ClearTree {
        init = "call compile preprocessFileLineNumbers 'ClearTree\initSettings.sqf'";
    };
};

class CfgFunctions {
    #include "functions\CfgFunctions.hpp"
};

class CfgWeapons {
	class ItemCore;
	class InventoryItem_Base_F;
	class bunwell_itemcore: ItemCore
	{
		type=4096;
		detectRange=-1;
		simulation="ItemMineDetector";
		scope=0;
		author="Rabbit";
	};
	class bunwell_axe: bunwell_itemcore
	{
		displayName="Axe";
		scope=2;
		author="Rabbit";
		picture="\ClearTree\textures\Axe_Icon.paa";
		ACE_Attachable = "Land_Axe_F";
		model = "\A3\Structures_F\Items\Tools\Axe_F.p3d";
		icon="iconObject_circle";
		descriptionShort="Paul Bunyan";
		class ItemInfo: InventoryItem_Base_F
		{
			mass=8;
		};
	};
};




class CfgVehicles {
	
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
				class ClearTree {
					displayName = "Cut Tree";
					condition = "[_player] call ClearTree_fnc_canClearTree";
					//wait a frame to handle "Do When releasing action menu key" option
					statement = "[{[] call ClearTree_fnc_clearTree},[]] call CBA_fnc_execNextFrame";
					exceptions[] = {};
					showDisabled = 0;
					icon = "\ClearTree\textures\Axe_Icon_White.paa";
				};
            };
        };
    };
};
