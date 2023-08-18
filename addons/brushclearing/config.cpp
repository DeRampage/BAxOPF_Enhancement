#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_trenches", "ace_gestures", "ace_common"};
        author = "Ampersand";
         authors[] = {"Ampersand","Rabbit","Rampage"};
        url = "https://github.com/ampersand38/Brush-Clearing";
        VERSION_CONFIG;
    };
};
class CfgFunctions {
    class TF47 
    {
        class brushclearing
        {
            file = "z\TF47\addons\brushclearing\functions";
            class clearTree;
            class canclearTree;
            class clearBrush;
            class canclearBrush;
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
        picture="\z\TF47\addons\brushclearing\textures\Axe_Icon.paa";
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
                class GVAR(clearBrush) {
                    displayName = "Clear Grass/Bush";
                    condition = QUOTE(_player call FUNC(canClearBrush));
                    // Wait a frame to handle "Do When releasing action menu key" option
                    statement = QUOTE([ARR_2({_this call FUNC(clearBrush)},_player)] call CBA_fnc_execNextFrame);
                    exceptions[] = {};
                    showDisabled = 0;
                    icon = "\a3\modules_f\data\hideterrainobjects\icon32_ca.paa";
                };
                class clearTree {
                    displayName = "Cut Tree";
                    condition = "[_player] call TF47_fnc_canclearTree";
                    //wait a frame to handle "Do When releasing action menu key" option
                    statement = "[{[] call TF47_fnc_clearTree},[]] call CBA_fnc_execNextFrame";
                    exceptions[] = {};
                    showDisabled = 0;
                    icon = "z\TF47\addons\brushclearing\textures\Axe_Icon_White.paa";
                };
            };
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVersioning.hpp"
