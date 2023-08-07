// CBA Settings [ADDON: a3am]:

[
    QGVAR(landSpeed),
    "LIST",
    [localize "STR_TF47_a3am_Speed_DisplayName", "STR_TF47_a3am_Speed_Description"],
    [localize "STR_TF47_a3am_Description", localize "STR_TF47_a3am_Land_DisplayName"],
    [
        [SPEED_KMH, SPEED_MPH, SPEED_KNOT, SPEED_MS, SPEED_FPS, SPEED_FFF],
        [LSTRING(Speed_KMH), LSTRING(Speed_MPH), LSTRING(Speed_KNOT), LSTRING(Speed_MS), LSTRING(Speed_FPS), LSTRING(Speed_FFF)],
    0]
] call CBA_fnc_addSetting;

[
    QGVAR(seaSpeed),
    "LIST",
    [localize "STR_TF47_a3am_Speed_DisplayName", localize "STR_TF47_a3am_Speed_Description"],
    [localize "STR_TF47_a3am_Description", localize "STR_TF47_a3am_Sea_DisplayName"],
    [
        [SPEED_KMH, SPEED_MPH, SPEED_KNOT, SPEED_MS, SPEED_FPS, SPEED_FFF],
        [LSTRING(Speed_KMH), LSTRING(Speed_MPH), LSTRING(Speed_KNOT), LSTRING(Speed_MS), LSTRING(Speed_FPS), LSTRING(Speed_FFF)],
    0]
] call CBA_fnc_addSetting;

[
    QGVAR(heliSpeed),
    "LIST",
    [localize "STR_TF47_a3am_Speed_DisplayName", localize "STR_TF47_a3am_Speed_Description"],
    [localize "STR_TF47_a3am_Description", localize "STR_A3_TIME_TRIALS_HELI_NAME"],
    [
        [SPEED_KMH, SPEED_MPH, SPEED_KNOT, SPEED_MS, SPEED_FPS, SPEED_FFF],
        [LSTRING(Speed_KMH), LSTRING(Speed_MPH), LSTRING(Speed_KNOT), LSTRING(Speed_MS), LSTRING(Speed_FPS), LSTRING(Speed_FFF)],
    0]
] call CBA_fnc_addSetting;

[
    QGVAR(heliAlt),
    "LIST",
    [localize "STR_TF47_a3am_Alt_DisplayName", localize "STR_TF47_a3am_Alt_Description"],
    [localize "STR_TF47_a3am_Description", localize "STR_A3_TIME_TRIALS_HELI_NAME"],
    [
        [ALT_M, ALT_F, ALT_Y, ALT_R, ALT_A], 
        [LSTRING(Alt_M), LSTRING(Alt_F), LSTRING(Alt_Y), LSTRING(Alt_R), LSTRING(Alt_A)], 
    0]
] call CBA_fnc_addSetting;

[
    QGVAR(planeSpeed),
    "LIST",
    [localize "STR_TF47_a3am_Speed_DisplayName", localize "STR_TF47_a3am_Speed_Description"],
    [localize "STR_TF47_a3am_Description", localize "STR_A3_Showcase_FixedWings_Mission_Name"],
    [
        [SPEED_KMH, SPEED_MPH, SPEED_KNOT, SPEED_MS, SPEED_FPS, SPEED_FFF],
        [LSTRING(Speed_KMH), LSTRING(Speed_MPH), LSTRING(Speed_KNOT), LSTRING(Speed_MS), LSTRING(Speed_FPS), LSTRING(Speed_FFF)],
    0]
] call CBA_fnc_addSetting;

[
    QGVAR(planeAlt),
    "LIST",
    [localize "STR_TF47_a3am_Alt_DisplayName", localize "STR_TF47_a3am_Alt_Description"],
    [localize "STR_TF47_a3am_Description", localize "STR_A3_Showcase_FixedWings_Mission_Name"],
    [
        [ALT_M, ALT_F, ALT_Y, ALT_R, ALT_A], 
        [LSTRING(Alt_M), LSTRING(Alt_F), LSTRING(Alt_Y), LSTRING(Alt_R), LSTRING(Alt_A)], 
    0]
] call CBA_fnc_addSetting;
