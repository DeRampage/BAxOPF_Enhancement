#include "\z\TF47\addons\dynamic_Group\DynamicGroupsCommonDefines.inc"

if !(["PlayerIsLeader",[player]] call BIS_fnc_dynamicGroups) exitWith {};

private _display = uiNamespace getVariable [VAR_UI_DISPLAY, displayNull];
if (isNull _display) exitWith {};

([] call BIS_fnc_displayMission) createDisplay  "tf47_DynGrp_setGrp";

