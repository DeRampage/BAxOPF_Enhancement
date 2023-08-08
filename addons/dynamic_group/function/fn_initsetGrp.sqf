#include "\z\TF47\addons\dynamic_Group\DynamicGroupsCommonDefines.inc"

if (isNil "is_menuok") then {is_menuok = true;};
if (isNil "lhd" ) then {lhd = [0,0,0]};
if !(isNil "F_getNearestFob") then {
    if !(round (player distance2D ([] call F_getNearestFob)) < 150 || (player distance2D lhd) <= 200) exitwith {closeDialog 0; hint localize "STR_NConfigure";([] call BIS_fnc_displayMission) createDisplay 'RscDisplayDynamicGroups';};
};
//if !(round (player distance2D ([] call F_getNearestFob)) < 150 || (player distance2D lhd) <= 200) exitwith {closeDialog 0; hint localize "STR_NConfigure";([] call BIS_fnc_displayMission) createDisplay 'RscDisplayDynamicGroups';};

_display = (findDisplay 135624);
_roles = [
    "b_inf",
    "b_recon",
    "b_motor_inf",
    "b_mech_inf",
    "b_armor",
    "b_art",
    "b_mortar",
    "b_air",
    "b_att_air",
    "b_naval",
    "b_hq",
    "b_med",
    "b_support",
    "b_maint",
    "b_installation",
    "b_antiair",
    "b_plane_cas",
    "b_plane_cap", 
    "b_plane_sead",
    "b_plane_multi",
    "b_plane",
    "b_plane_cargo"
];

// get Data for Combolist
{
//    if (getNumber(configfile >> "CfgMarkers" >> _x >> "side") isEqualto 1) exitwith {};
    
    _name = getText (configfile >> "CfgMarkers" >> _x >> "Name");
    _icon = getText (configfile >> "CfgMarkers" >> _x >> "icon");

    _index = (_display displayCtrl 2100) lbAdd  (_name);
    (_display displayCtrl 2100)lbSetData                    [ _index, format["%1#%2", _x, "ColorBLUFOR"]];
    (_display displayCtrl 2100)lbSetText                    [ _index, _name];
    (_display displayCtrl 2100)lbSetPicture                 [ _index, _icon];
    (_display displayCtrl 2100)lbSetPictureColor            [ _index, [1,1,1,1]];
    (_display displayCtrl 2100)lbSetPictureColorSelected    [ _index, [1,1,1,1]];
//    (_display displayCtrl 2100) ctrlShow                     [1005, false];
//    (_display displayCtrl 2100) ctrlShow                     [2190, false];

} forEach _roles;


{
    _SquadLanguage=_x;

    _indexLang = (_display displayCtrl 2180) lbAdd              (_SquadLanguage);
    (_display displayCtrl 2180)lbSetData                    [ _indexLang, format["%1", _x]];
    (_display displayCtrl 2180)lbSetText                    [ _indexLang, _SquadLanguage];

} forEach  (parseSimpleArray TF47_dynamic_Group_TF47_GroupLanguage);

{
    _factionName=_x;

    _index = (_display displayCtrl 2190) lbAdd              (_factionName);
    (_display displayCtrl 2190)lbSetData                    [ _index, format["%1", _x]];
    (_display displayCtrl 2190)lbSetText                    [ _index, _factionName];

} forEach  (parseSimpleArray TF47_dynamic_Group_TF47_GroupFaction);

//define stuff

_intRole = _roles find (group player getVariable [VAR_GROUP_ROLE,""]);
_intLang = (parseSimpleArray TF47_dynamic_Group_TF47_GroupLanguage) find (group player getVariable [VAR_GROUP_LANG,""]);
_intFact = 0;

if !((group player getVariable [VAR_GROUP_FACT,""]) == "NoFaction") then {
    _intFact = (parseSimpleArray TF47_dynamic_Group_TF47_GroupFaction) find (group player getVariable [VAR_GROUP_FACT,""]);
};

_intFreq = group player getVariable [VAR_GROUP_FREQ,""];

// Fill out 

(_display displayCtrl 2100) lbSetCurSel _intRole;
(_display displayCtrl 2180) lbSetCurSel _intLang;
(_display displayCtrl 2190) lbSetCurSel _intFact;
(_display displayCtrl 1400) ctrlSetText _intFreq;
