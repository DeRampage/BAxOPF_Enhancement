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

