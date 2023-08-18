[
    "TF47_SelectedSeatColour", "COLOR",
    ["Selected Seat Colour", "Colour of the icon for the currently selected seat."],
    "TF47 Ride & Dismount",
    ["IGUI", "TEXT_RGB"] call BIS_fnc_displayColorGet, // default value
    false, // isGlobal
    {},
    false // needRestart
] call CBA_settings_fnc_init;

[
    "TF47_ShowAllSeats", "CHECKBOX",
    ["Show All Seats", "Show all selectable seats as translucent generic icon."],
    "TF47 Ride & Dismount",
    true, // default value
    false, // isGlobal
    {},
    false // needRestart
] call CBA_settings_fnc_init;

[
    "TF47_OtherSeatsColour", "COLOR",
    ["Selected Seat Colour", "Colour of the icon(s) for the other seats."],
    "TF47 Ride & Dismount",
    ["IGUI", "BCG_RGB"] call BIS_fnc_displayColorGet, // default value
    false, // isGlobal
    {},
    false // needRestart
] call CBA_settings_fnc_init;

[
    "TF47_HopVehicleRange", "SLIDER",
    ["Hop Vehicle Range", "Maximum distance across which players can jump to a different vehicle."],
    "TF47 Ride & Dismount",
    [1, 10, 5, 0], // default value
    true, // isGlobal
    {},
    false // needRestart
] call CBA_settings_fnc_init;
