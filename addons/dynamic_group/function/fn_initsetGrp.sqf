#include "\z\TF47\addons\dynamic_Group\DynamicGroupsCommonDefines.inc"

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

{
//if (getNumber(configfile >> "CfgMarkers" >> _x >> "side") isEqualto 1) exitwith {};
    
    _name = getText (configfile >> "CfgMarkers" >> _x >> "Name");
    _icon = getText (configfile >> "CfgMarkers" >> _x >> "icon");

    _index = (_display displayCtrl 2100) lbAdd  (_name);
    (_display displayCtrl 2100)lbSetData                    [ _index, format["%1#%2", _x, "ColorBLUFOR"]];
    (_display displayCtrl 2100)lbSetText                    [ _index, _name];
    (_display displayCtrl 2100)lbSetPicture                 [ _index, _icon];
    (_display displayCtrl 2100)lbSetPictureColor            [ _index, [1,1,1,1]];
    (_display displayCtrl 2100)lbSetPictureColorSelected    [ _index, [1,1,1,1]];

} forEach _roles;

_intFreq = group player getVariable VAR_GROUP_FREQ;

(_display displayCtrl 2100) lbSetCurSel 0;
(_display displayCtrl 1400) ctrlSetText _intFreq;
