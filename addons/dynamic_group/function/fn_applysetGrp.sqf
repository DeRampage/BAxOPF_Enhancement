#include "\z\SNC\addons\dynamic_Group\DynamicGroupsCommonDefines.inc"

_rolesel      = lbCurSel 2100;
_freq         = ctrlText 1400;
_data         = lbData [2100, lbCurSel 2100] splitString "#";
_language     = lbData [2180, lbCurSel 2180];
_faction      = lbData [2190, lbCurSel 2190];

_markerType   = _data select 0;

group player setVariable ["BIS_dg_rol",_markerType,true];

group player setVariable ["BIS_dg_lan",_language,true];

if !(_freq=="") then {
    group player setVariable ["BIS_dg_frq",_freq,true];
};

group player setVariable ["BIS_dg_fac",_faction,true];

//close display and open Dynamic Groups Display
closeDialog 0; ([] call BIS_fnc_displayMission) createDisplay 'RscDisplayDynamicGroups';
