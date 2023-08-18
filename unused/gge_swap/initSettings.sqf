// CBA Settings [ADDON: gge_swap]:
////// GGE_SWAP SETTINGS ///////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CHECKBOX --- extra argument: default value
[
    "gge_swap_var_tacticalAnimationsEnabled",
    "CHECKBOX",
    ["Using Funny's Tactical Animations", "Enable if you are using Funny's Tactical Animations mod!"],
    "GGE: Weapon Swap",
    false,
    0,
    {call gge_swap_fnc_toggleFunnysAnimations;}
    ] call CBA_fnc_addSetting;

[
    "gge_swap_var_selectedMode",
    "LIST",
    ["Weapon Sling Location", "Select whether you want weapon stored in front or to the side"],
    "GGE: Weapon Swap",
    [[0, 1], ["Weapon In Front","Weapon To Side"], 0],
    0,
    {[false] call gge_swap_fnc_attachWeaponHolder;
}] call CBA_fnc_addSetting;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////