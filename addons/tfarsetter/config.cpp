#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        author = "johnb43";
        authors[] = {"johnb43", "Chatter", "M3ales", "Tirpitz93", "TF47 Desty"};
        requiredAddons[] = {
            "cba_main",
            "ace_interact_menu",
            "task_force_radio",
            "zen_main"
        };
        units[] = {};
        weapons[] = {};
    };
};

#include "CfgVehicles.hpp"
#include "CfgEventHandlers.hpp"

/*
    TFAR radio settings (array):
    0: active channel <NUMBER>
    1: Volume <NUMBER>
    2: Frequencies for channels <ARRAY>
    3: Stereo setting <NUMBER>
    4: Encryption code <STRING>
    5: Additional active channel <NUMBER>
    6: Additional active channel stereo mode <NUMBER>
    7: Owner's UID <STRING>
    8: Speaker mode <NUMBER>
    9: turned on <BOOL>
*/

/*
    Profile: [[], [], [], false]:
    0: SR sttings (from TFAR_fnc_getSwSettings; see above for layout of that)
    1: LR settings (from TFAR_fnc_getLrSettings; see above for layout of that)
    2: VLR settings (from TFAR_fnc_getLrSettings; see above for layout of that)
    3: Headset status (from missionNamespace getVariable ["TFAR_core_isHeadsetLowered", false])
*/
