#include "script_component.hpp"

class CfgPatches {
    class clearTree {
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

class CfgFunctions {
    class TF47 
    {
        class clearTree
        {
            file = "z\TF47\addons\clearTree\functions";
            class clearTree;
            class canclearTree;
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
        picture="\z\TF47\addons\clearTree\textures\Axe_Icon.paa";
        //ACE_Attachable = "Land_Axe_F"; //why?!
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
                class clearTree {
                    displayName = "Cut Tree";
                    condition = "[_player] call TF47_fnc_canclearTree";
                    //wait a frame to handle "Do When releasing action menu key" option
                    statement = "[{[] call TF47_fnc_clearTree},[]] call CBA_fnc_execNextFrame";
                    exceptions[] = {};
                    showDisabled = 0;
                    icon = "z\TF47\addons\clearTree\textures\Axe_Icon_White.paa";
                };
            };
        };
    };
};

#include "CfgEventHandlers.hpp"
