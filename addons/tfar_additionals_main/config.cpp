#define _ARMA_

class CfgPatches
{
    class KIF_Radio
    {
        units[] = {"KIF_ModuleRadio"};
        requiredVersion = 1.0;
        requiredAddons[] = {"A3_Data_F","task_force_radio","task_force_radio_items","ace_interaction","cba_common"};
        author = "KpoT";
        version = 0.2;
        versionStr = "0.3";
        weapons[] = {"KIF_RadioNorth"};
        magazines[] = {};
        ammo[] = {};
    };
};
class CBA_Extended_EventHandlers;
class CfgVehicles
{
    class Logic;
    class Module_F: Logic
    {
        class AttributesBase
        {
            class Combo;
            class Edit;
            class Checkbox;
            class ModuleDescription;
        };
        class ModuleDescription
        {
            class AnyBrain;
        };
    };
    class KIF_ModuleRadio: Module_F //todo in cba settings wandeln
    {
        scope = 2;
        displayName = "$STR_KIF_RADIO_MODUL_NAME";
        icon = "z\TF47\addons\tfar_additionals_main\icons\radio_icon.paa";
        category = "Supports";
        function = "KIF_fnc_Init";
        functionPriority = 10;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 0;
        class Attributes: AttributesBase
        {
            class CustomAddActionText: Edit
            {
                property = "KIF_CustomAddActionText";
                displayName = "$STR_KIF_RADIO_MODUL_EDIT";
                tooltip = "$STR_KIF_RADIO_MODUL_EDIT_HINT";
                typeName = "STRING";
            };
            class Interaction_Menu_Type: Combo
            {
                property = "KIF_Interaction_type";
                displayName = "$STR_KIF_RADIO_IMENU";
                tooltip = "$STR_KIF_RADIO_IMENU_HINT";
                typeName = "NUMBER";
                class Values
                {
                    class Interaction_1
                    {
                        name = "Action Menu";
                        value = 0;
                        default = 1;
                    };
                    class Interaction_2
                    {
                        name = "Ace Interaction Menu";
                        value = 1;
                    };
                    class Interaction_3
                    {
                        name = "Both (ace & action)";
                        value = 2;
                    };
                };
            };
            class Only_Selected_Radios
            {
                displayName = "$STR_KIF_RADIO_ONLY_SELECTED";
                tooltip = "$STR_KIF_RADIO_ONLY_SELECTED_HINT";
                property = "Only_Selected_Radios";
                control = "Checkbox";
                expression = "_this setVariable ['OnlySelected',_value,true];";
                defaultValue = "false";
                unique = 0;
            };
            class Radio_BP_Array
            {
                control = "EditArray";
                defaultValue = "['tfar_mr3000','tfar_anprc155']";
                displayName = "$STR_KIF_RADIO_ARRAY";
                tooltip = "$STR_KIF_RADIO_ARRAY";
                expression = "_this setVariable ['Radio_BP_Array',_value,true];";
                property = "Radio_BP_Array";
                wikiType = "[[Array]]";
            };
            class ModuleDescription: ModuleDescription{};
        };
        class ModuleDescription: ModuleDescription
        {
            description = "$STR_KIF_RADIO_MODUL_DESCRIPTION";
            sync[] = {"AnyPerson"};
        };
    };
    class FloatingStructure_F;
    class kif_handset: FloatingStructure_F
    {
        mapSize = 0.08;
        scope = 1;
        scopeCurator = 2;
        icon = "iconObject_circle";
        vehicleClass = "Cargo";
    };
    class kif_h250u: kif_handset
    {
        displayName = "Handset H-250/U";
        //model = "\z\TF47\addons\tfar_additionals_main\assets\h186.p3d"; //todo in additionals mergen
    };
};
class CfgFunctions
{
    class KIF
    {
        class Radio_Support
        {
            file = "z\TF47\addons\tfar_additionals_main\functions";
            class Init{};
            class RadioInit{};
            class AddAction2Unit{};
            class Use_Receiver{};
            class PlayChar{};
            class PlayMorse{};
            class SwitchOnOff{};
        };
    };
};
class Extended_PostInit_EventHandlers
{
    class KIF_PostInitHandler
    {
        init = "call KIF_fnc_RadioInit";
    };
};