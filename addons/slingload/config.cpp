#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {
            "TF47_slingload_apexFitting",
            "TF47_slingload_wreckDummy"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_interaction"};
        author = "Ampersand";
        authors[] = {"Ampersand","Rampage"};
        authorUrl = "https://github.com/ampersand38/slr";
        VERSION_CONFIG;
    };
};
class CfgFunctions 
{
    class TF47
    {
        class Slingload
        {
            file = "z\TF47\addons\slingload\functions";
            class addACEActions{};
            class adjustRigging{};
            class canAdjustRigging{};
            class attachCargo{};
            class canAttachCargo{};
            class cancelPlacement{};
            class canReleaseCargo{};
            class canRemoveRigging{};
            class canRigCargo{};
            class canRigCargoAuto{};
            class canRigCargoManual{};
            class getCargoLiftPoints{};
            class handleScrollWheel{};
            class pickUpFitting{};
            class releaseCargo{};
            class removeRigging{};
            class rigCargo{};
            class rigCargoAuto{};
            class rigCargoManual{};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgNonAIVehicles.hpp"
#include "CfgWeapons.hpp"
