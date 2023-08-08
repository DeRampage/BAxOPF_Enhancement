#include "script_component.hpp"

// Map Group Tracking
// MGT
[
    QGVAR(EnableMapTracker),
    "CHECKBOX",
    ["Enable group tracking", "Show registered groups on map"], 
    "TF47 Groupmanager", 
    false,
    true,
    {
        [QGVAR(EnableMapTracker), _this] call EFUNC(common,cbaSettings_settingChanged);

        [{
             if(GVAR(EnableMapTracker))then{
                 [] call TF47_fnc_updateGroupTracking;
             }else{
                [_this select 1] call CBA_fnc_removePerFrameHandler;
             };
        }, GVAR(Interval), []] call CBA_fnc_addPerFrameHandler;

    },
    false
] call CBA_fnc_addSetting;

[
    QGVAR(staticGroupList),
    "CHECKBOX", 
    ["Static grouplist on map border", "Show registered groups as list on map"], 
    "TF47 Groupmanager", 
    false,
    true,
    {},
    true // Needs mission restart
] call cba_settings_fnc_init;

[
    QGVAR(dynamicGroupTracker),
    "CHECKBOX", 
    ["Blueforcetracking", "Mapmarkers follow group leader"], 
    "TF47 Groupmanager", 
    false,
    true,
    {},
    true // Needs mission restart
] call cba_settings_fnc_init;

[
    QGVAR(Interval),
    "SLIDER",
    ["Map List Update intervall", "Set the update interval (sek)"], 
    "TF47 Groupmanager", 
    [1, 30, 1, 1],
    true,
    {[QGVAR(Interval), _this] call EFUNC(common,cbaSettings_settingChanged)},
    true // Needs mission restart
] call CBA_fnc_addSetting;

[
    QGVAR(startMarkerName),
    "EDITBOX", 
    ["Mapmarker Name", "Set the Map Markername"], 
    "TF47 Groupmanager", 
    "",
    true,
    {},
    true // Needs mission restart
] call cba_settings_fnc_init;

[
    QGVAR(indicateGroupsize),
    "CHECKBOX", 
    ["Groupsize", "Indicate groupsize on marker"], 
    "TF47 Groupmanager", 
    false,
    true,
    {},
    true // Needs mission restart
] call cba_settings_fnc_init;


[
    QGVAR(TF47_MapMarker),
    "CHECKBOX", 
    ["Restriction for Mapmarker", "Move the Marker from non Whitelistet Player to Groupchannel"], 
    "TF47 Marker", 
    false,
    false,
    { call TF47_dynGrps_fnc_mapMarker },
    true // Needs mission restart
] call cba_settings_fnc_init;

[
    QGVAR(TF47_MapMarker_Whitelist),
    "EDITBOX", 
    ["MapMarker_Whitelist", "Player UID, so that they can put Marker on Sidechannel"], 
    "TF47 Marker", 
    "['76561198100256441']",
    true,
    {},
    false // Needs mission restart
] call cba_settings_fnc_init;


[
    QGVAR(TF47_GroupFaction),
    "EDITBOX", 
    ["Custome Fractions", "Enter custome Fraction"], 
    "TF47 Groupmanager", 
    "['US Army','BW']",
    true,
    {},
    false // Needs mission restart
] call cba_settings_fnc_init;

[
    QGVAR(TF47_GroupLanguage),
    "EDITBOX", 
    ["Squad Language", "Define Language"], 
    "TF47 Groupmanager", 
    "['DE','EN']",
    true,
    {},
    false // Needs mission restart
] call cba_settings_fnc_init;
