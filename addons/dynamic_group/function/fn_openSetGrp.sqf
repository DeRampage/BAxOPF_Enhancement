
/*
    
    author: -SONIC-
    
    description:
        load when Frequenz Dialog is open.
    parameter:
        nothing
    return
        nothing
    example
        na
        
*/

disableSerialization; 

params ["_display"];

#include "\z\TF47\addons\dynamic_Group\DynamicGroupsCommonDefines.inc"
// Close old UI
with uiNamespace do { ["CloseDisplay"] call DISPLAY;};

//check if Group Leader
if !(["PlayerIsLeader",[player]] call BIS_fnc_dynamicGroups) exitWith {hint "Only Teamleader allowed"};

private _editIntern = (_display displayCtrl 1400);

_freqIntern = "Intern Frequenz";

if (!(group player getVariable "SNC_core_Marker_Sql_Freq_Intern" isEqualTo "")) then{
    _freqIntern = group player getVariable "SNC_core_Marker_Sql_Freq_Intern";
};

_editIntern ctrlSetText format ["%1",_freqIntern];

private _editTitle = (_display displayCtrl 1405);

_txt = format ["Einstelung von %1",groupId group player];

_editTitle ctrlSetText format ["%1",_txt];
