#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {"tf_acr_stationar"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Data_F","task_force_radio","task_force_radio_items","tfar_core","ace_interaction","cba_common"};
        authors[] = {"ARAB","KpoT","Rampage"};
        authorUrl = "https://steamcommunity.com/sharedfiles/filedetails/?id=2423977008";
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class tfar_additionals
        {
            file = "z\TF47\addons\tfar_additionals\functions";
            class action{};
            class init_radio_unit{};
        };
    };
};

class CBA_Extended_EventHandlers;

class cfgVehicles
{
    class ThingX;
    class tf_acr_stationar: ThingX
    {
        class EventHandlers
        {
            init = "params ['_entity']; if (isServer) then { [_entity] execvm '\z\TF47\addons\tfar_additionals\functions\fn_init_radio_unit.sqf';};";
            deleted = "params ['_entity']; if (isServer) then {  {deletevehicle _x;} foreach (attachedObjects _entity);};";
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
        };
        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = {0,0.8,0.4};
        ace_dragging_carryDirection = 0;
        scope = 2;
        scopeCurator = 2;
        model = "";
        mass = 20;
        displayName = "AN/ACR Stationar";
        editorPreview = "\z\TF47\addons\tfar_additionals\assets\tfr_lr_radio.jpg";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\task_force_radio_items\models\data\camo\backpack_dpcu_co.paa"};
        icon = "iconObject_4x5";
        editorSubcategory = "EdSubcat_Electronics";
        cost = 1000;
        class ACE_Actions
        {
            class ACE_MainActions
            {
                selection = "";
                distance = 1.5;
                condition = "true";
                class ACE_RadioLR_Use
                {
                    selection = "";
                    displayName = "$STR_TF47_tfar_additionals_RADIO_USE";
                    condition = "(alive _target) and (({typeof _x == 'rope_terminator'} count (attachedObjects _target))<1)and(({_x isKindOf 'kif_handset'} count (attachedObjects player))<1)";
                    statement = "_target execVM '\z\TF47\addons\tfar_additionals\functions\fn_action.sqf';";
                    showDisabled = 0;
                    exceptions[] = {"isNotInside","isNotSwimming"};
                };
                class ACE_FF_Force_Put_HS
                {
                    selection = "";
                    displayName = "$STR_TF47_tfar_additionals_FIELDPHONE_PUT_RD";
                    condition = "(({ if (typeof _x == 'rope_terminator') then { !isPlayer (attachedTo (ropeAttachedTo _x))} else { false }; } count (attachedObjects _target) )>0)";
                    statement = "{if (typeof _x == 'rope_terminator') then {deletevehicle (ropeAttachedTo _x); deletevehicle _x;}; } foreach (attachedObjects _target); _target animateSource ['hs_hide',0, true]; ";
                    showDisabled = 0;
                    exceptions[] = {"isNotInside","isNotSwimming"};
                };
            };
        };
        class UserActions
        {
            class kif_use_lr_stationar
            {
                displayName = "$STR_TF47_tfar_additionals_RADIO_USE";
                displayNameDefault = "";
                position = "";
                radius = 2.0;
                onlyForPlayer = 0;
                condition = "(alive this) and (({typeof _x == 'rope_terminator'} count (attachedObjects this))<1)and(({_x isKindOf 'kif_handset'} count (attachedObjects player))<1)";
                statement = "this execVM '\z\TF47\addons\tfar_additionals\functions\fn_action.sqf';";
            };
        };
        class AnimationSources
        {
            class hs_hide
            {
                source = "user";
                animPeriod = 0;
                initPhase = 0;
            };
        };
        class Attributes
        {
            class Radio_Side
            {
                control = "combo";
                property = "Radio_Side";
                displayName = "Radio Side";
                tooltip = "";
                expression = "if isServer then {_this setVariable ['Radio_Side', _value];};";
                typeName = "String";
                class Values
                {
                    class Side_1
                    {
                        name = "BLUFOR";
                        value = "WEST";
                        default = 1;
                    };
                    class Side_2
                    {
                        name = "OPFOR";
                        value = "EAST";
                    };
                    class Side_3
                    {
                        name = "Guerilla";
                        value = "GUER";
                    };
                };
            };
            class Radio_Texture_Combo
            {
                control = "combo";
                property = "Backpack_Texture";
                displayName = "Texture";
                tooltip = "";
                expression = "if isServer then {_this setVariable ['Backpack_Texture', _value];};";
                typeName = "String";
                class Values
                {
                    class Camo_1
                    {
                        name = "Dpcu";
                        value = "dpcu";
                        default = 1;
                    };
                    class Camo_2
                    {
                        name = "Black";
                        value = "black";
                    };
                    class Camo_3
                    {
                        name = "Green";
                        value = "green";
                    };
                    class Camo_4
                    {
                        name = "Mcam";
                        value = "mcam";
                    };
                    class Camo_5
                    {
                        name = "Sage";
                        value = "sage";
                    };
                };
            };
        };
    };

    class rope_terminator: ThingX
    {
        displayName = "Rope Terminator";
        //model = "z\TF47\addons\tfar_additionals\assets\rope_terminator.p3d";
        model = "\A3\Structures_F_EPA\Items\Tools\CanOpener_F.p3d";
        mapSize = 0.08;
        scope = 1;
        scopeCurator = 2;
        icon = "iconObject_circle";
        vehicleClass = "Cargo";
    };
};
#include "CfgEventHandlers.hpp"
