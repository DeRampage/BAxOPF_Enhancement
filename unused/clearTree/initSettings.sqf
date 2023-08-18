[
    "clearTree_requireAxe", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Require Axe", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "Does a player require an axe in its inventory for tree clearing?"],
    "Brush and Tree Clearing", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "clearTree_hidetree", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    "Hide Tree after destroying it?", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "Brush and Tree Clearing", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
]   call CBA_fnc_addSetting;
