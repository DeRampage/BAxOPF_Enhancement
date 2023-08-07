#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

[
    QGVAR(airProfile),
    "EDITBOX",
    ["Air profile", "Applies the specified profile when you get in air vehicles."],
    ["TF47 TFAR Setter", "Vehicles"],
    "",
    false
] call CBA_fnc_addSetting;

[
    QGVAR(landProfile),
    "EDITBOX",
    ["Land profile", "Applies the specified profile when you get in land vehicles."],
    ["TF47 TFAR Setter", "Vehicles"],
    "",
    false
] call CBA_fnc_addSetting;

[
    QGVAR(askSaveConfirmation),
    "CHECKBOX",
    ["Ask save confirmation", "Asks the player for confirmation before saving a profile."],
    ["TF47 TFAR Setter", "Profiles"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(askLoadConfirmation),
    "CHECKBOX",
    ["Ask load confirmation", "Asks the player for confirmation before loading a profile."],
    ["TF47 TFAR Setter", "Profiles"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(askDeleteConfirmation),
    "CHECKBOX",
    ["Ask delete confirmation", "Asks the player for confirmation before deleting a profile."],
    ["TF47 TFAR Setter", "Profiles"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(enableArsenalAutoSettings),
    "CHECKBOX",
    ["Enable arsenal radio settings saving", "Saves the current radio settings before entering the arsenal and applies them when you exit the arsenal (both ACE and BI Arsenals)."],
    ["TF47 TFAR Setter", "Funtionality"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(enableMountingAutoSettings),
    "CHECKBOX",
    ["Enable mounting radio settings saving", "Saves the current radio settings before entering a vehicle and applies them when you dismount."],
    ["TF47 TFAR Setter", "Vehicles"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(enableCompatFK),
    "CHECKBOX",
    ["Enable FK Server detection", "When loading SR settings on an FK server, it will automatically change the channel to which squad you are in."],
    ["TF47 TFAR Setter", "Funtionality"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(enableSRInteractions),
    "CHECKBOX",
    ["Enable 'SR' interactions", "Enables both saving and loading actions for SR."],
    ["TF47 TFAR Setter", "Funtionality"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(enableLRInteractions),
    "CHECKBOX",
    ["Enable 'LR' interactions", "Enables both saving and loading actions for LR."],
    ["TF47 TFAR Setter", "Funtionality"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(enableVLRInteractions),
    "CHECKBOX",
    ["Enable 'VLR' interactions", "Enables both saving and loading actions for VLR."],
    ["TF47 TFAR Setter", "Funtionality"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(enableSRAndLRInteractions),
    "CHECKBOX",
    ["Enable 'SR & LR' interactions", "Enables both saving and loading actions for 'SR & LR'."],
    ["TF47 TFAR Setter", "Funtionality"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(enableAllInteractions),
    "CHECKBOX",
    ["Enable 'All' interactions", "Enables both saving and loading actions for 'All'."],
    ["TF47 TFAR Setter", "Funtionality"],
    true,
    false
] call CBA_fnc_addSetting;

ADDON = true;
