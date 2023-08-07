//#include "script_component.hpp"

//if (!hasInterface) exitWith {};

// load compatible nightvision goggles
BettIR_CompatibleNVGsData = [] call TF47_fnc_getCompatibleNVGs;
BettIR_CompatibleNVGs = BettIR_CompatibleNVGsData select 0;
BettIR_CompatibleNVGsOffsets = BettIR_CompatibleNVGsData select 1;

// load compatible attachments
BettIR_CompatibleAttachmentsData = [] call TF47_fnc_getCompatibleWeaponAttachments;
BettIR_CompatibleAttachments = BettIR_CompatibleAttachmentsData select 0;
BettIR_CompatibleAttachmentsOffsets = BettIR_CompatibleAttachmentsData select 1;

// prepare unit tracking variables
BettIR_UnitList = [];
BettIR_UnitList_LastUpdate = time;
BettIR_UnitList_UpdateInterval = 0.5;

BettIR_EachFrameHandlerId = -1;

/** 
    ************** KEYBINDS **************
*/

#include "initKeybinds.sqf"


// add a handler for the nightvision change
["visionMode", {
    params ["_unit", "_newVisionMode", "_oldVisionMode"];

    // check if we're currently switching to/from nightvision
    _isNightvision = _newVisionMode == 1;
    // call the handler function
    [_isNightvision] spawn TF47_fnc_handleVisionModeChange; 


}, true] call CBA_fnc_addPlayerEventHandler;
