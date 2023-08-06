#include "script_component.hpp"

class CfgPatches {
    class ClearTree {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_common"};
        author = "Ampersand";
        authors[] = {"Ampersand","Rabbit","Rampage"};
        VERSION_CONFIG;
    };
};

class Extended_PreInit_EventHandlers {
    class ClearTree {
        init = "call compile preprocessFileLineNumbers 'ClearTree\initSettings.sqf'";
    };
};

class CfgFunctions {
    class TF47 
    {
        class ClearTree
        {
            file = "z\TF47\addons\ClearTree\functions";
            class clearTree;
            class canClearTree;
        };
    };
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
        picture="z\TF47\addons\ClearTree\textures\Axe_Icon.paa";
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
                    condition = "[_player] call TF47_fnc_canClearTree";
                    //wait a frame to handle "Do When releasing action menu key" option
                    statement = "[{[] call TF47_fnc_clearTree},[]] call CBA_fnc_execNextFrame";
                    exceptions[] = {};
                    showDisabled = 0;
                    icon = "z\TF47\addons\ClearTree\textures\Axe_Icon_White.paa";
                };
            };
        };
    };
};

#include "CfgEventHandlers.hpp"