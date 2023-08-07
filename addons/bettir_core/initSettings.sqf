[
    'BettIR_ViewDistance', // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    ['View distance', // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    'How far do you want to see the effect?'],
    'BettIR', // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [150, 12000, 300, 0], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;
