class CfgPatches
{
    class AntiBounceSystem
    {
        units[]={};
        weapons[] = {};
        requiredVersion = 1.98;
        requiredAddons[] = {"CBA_Extended_EventHandlers"};
        name = "Anti-Bounce System";
        author = "Leopard20"; 
    };
};

class CfgFunctions {
    class TF47 {
        class ABS
        {
            file = "\z\TF47\addons\AntiBounceSystem\functions";
            class contact_end {};
            class addEHs {};
            class removeEHs {};
        };
    };
};

class Extended_PreInit_EventHandlers
{
    class AIO_AIMENU 
    {
        init = "call compile preProcessFileLineNumbers '\z\TF47\addons\AntiBounceSystem\XEH_preInit.sqf'";
    };
};

class Extended_InitPost_EventHandlers {
    class Car {
        class ABS_addEHs {
            init = "call ABS_fnc_addEHs";
        };
    };
    
    class Tank {
        class ABS_addEHs {
            init = "call ABS_fnc_addEHs";
        };
    };
    
    class Motorcycle {
        class ABS_addEHs {
            init = "call ABS_fnc_addEHs";
        };
    };
};