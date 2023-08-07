#include "\z\TF47\addons\dynamic_Group\DynamicGroupsCommonDefines.inc"

_rolesel      = lbCurSel 2100;
_freq         = ctrlText 1400;
_data         = lbData [2100, lbCurSel 2100] splitString "#";
_markerType   = _data select 0;

group player setVariable ["BIS_dg_rol",_markerType,true];

if !(_freq=="") then {
    group player setVariable ["BIS_dg_frq",_freq,true];
};

//close display and open Dynamic Groups Display
closeDialog 0; ([] call BIS_fnc_displayMission) createDisplay 'RscDisplayDynamicGroups';
