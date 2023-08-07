
#define SETTINGS_CAT "TF47 Unflipping"

[
    "TF47_unit_mass_limit",
    "SLIDER",
    [localize "STR_TF47_unflipping_unit_mass_limit", localize "STR_TF47_unflipping_unit_mass_limit_desc"],
    SETTINGS_CAT,
    [0, 100000, 3000, 0],
    true,
    {}
] call CBA_fnc_addSetting;

[
    "TF47_unit_man_limit",
    "SLIDER",
    [localize "STR_TF47_unflipping_unit_man_limit", localize "STR_TF47_unflipping_unit_man_limit_desc"],
    SETTINGS_CAT,
    [1, 100, 7, 0],
    true,
    {}
] call CBA_fnc_addSetting;

[
    "TF47_unflip_time",
    "SLIDER",
    [localize "STR_TF47_unflipping_unflip_time", localize "STR_TF47_unflipping_unflip_time_desc"],
    SETTINGS_CAT,
    [1, 600, 5, 0],
    true,
    {}
] call CBA_fnc_addSetting;

[
    "TF47_vehicle_mass_limit",
    "SLIDER",
    [localize "STR_TF47_unflipping_vehicle_mass_limit", localize "STR_TF47_unflipping_vehicle_mass_limit"],
    SETTINGS_CAT,
    [0, 100000, 100000, 0],
    true,
    {}
] call CBA_fnc_addSetting;

[
    "TF47_require_toolkit",
    "CHECKBOX",
    [localize "STR_TF47_unflipping_require_toolkit", localize "STR_TF47_unflipping_require_toolkit"],
    SETTINGS_CAT,
    false,
    true,
    {}
] call CBA_fnc_addSetting;

[
    "TF47_require_serviceVehicle",
    "CHECKBOX",
    [localize "STR_TF47_unflipping_require_serviceVehicle", localize "STR_TF47_unflipping_require_serviceVehicle"],
    SETTINGS_CAT,
    false,
    true,
    {}
] call CBA_fnc_addSetting;
