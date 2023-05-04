//private _displayName = localize LSTRING(AttachCargo);
private _icon = "\a3\ui_f\data\igui\cfg\vehicletoggles\slingloadropeiconon2_ca.paa";

//private _statement = TF47_slingload_fnc_attachCargo; - TF47 Rampage stuff
/*
private _statement = {[_target, _player, []] call TF47_slingload_fnc_attachCargo};
private _condition = TF47_slingload_fnc_canAttachCargo;
private _cargoHookName = "TF47_slingload_cargoHookMain";
private _cargoHookNameForward = "TF47_slingload_cargoHookForward";
private _cargoHookNameAft = "TF47_slingload_cargoHookAft";
private _position = "slingload0";
*/

// Create Ace Action
//_action = ["TF47_slingload_attachCargo", _displayName, _icon, _statement, _condition, {}, _cargoHookName, _position, 5.0] call ace_interact_menu_fnc_createAction;
//["Helicopter_Base_H", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass; //includes also some unwanted Helos

//Load Heli Configs 
//#include "configs\Vanilla.sqf"

{
    _displayName = localize LSTRING(ReleaseCargo);
    _statement = {[_target] call TF47_slingload_fnc_releaseCargo};
    _condition = {[_target, _player] call TF47_slingload_fnc_canReleaseCargo};
    _action = ["TF47_slingload_releaseCargo", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
    [_x, 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

    _displayName = localize LSTRING(CargoHookNameMain);
    //_icon = "\a3\ui_f\data\igui\cfg\vehicletoggles\slingloadropeiconon2_ca.paa";
    _statement = {[_target, "Main"] call TF47_slingload_fnc_releaseCargo};
    _condition = {[_target, _player, "Main"] call TF47_slingload_fnc_canReleaseCargo};
    _action = ["TF47_slingload_releaseCargo", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
    [_x, 1, ["ACE_SelfActions", "TF47_slingload_releaseCargo"], _action, true] call ace_interact_menu_fnc_addActionToClass;

    _displayName = localize LSTRING(CargoHookNameForward);
    //_icon = "\a3\ui_f\data\igui\cfg\vehicletoggles\slingloadropeiconon2_ca.paa";
    _statement = {[_target, "Forward"] call TF47_slingload_fnc_releaseCargo};
    _condition = {[_target, _player, "Forward"] call TF47_slingload_fnc_canReleaseCargo};
    _action = ["TF47_slingload_releaseCargo", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
    [_x, 1, ["ACE_SelfActions", "TF47_slingload_releaseCargo"], _action, true] call ace_interact_menu_fnc_addActionToClass;

    _displayName = localize LSTRING(CargoHookNameAft);
    //_icon = "\a3\ui_f\data\igui\cfg\vehicletoggles\slingloadropeiconon2_ca.paa";
    _statement = {[_target, "Aft"] call TF47_slingload_fnc_releaseCargo};
    _condition = {[_target, _player, "Aft"] call TF47_slingload_fnc_canReleaseCargo};
    _action = ["TF47_slingload_releaseCargo", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
    [_x, 1, ["ACE_SelfActions", "TF47_slingload_releaseCargo"], _action, true] call ace_interact_menu_fnc_addActionToClass;

    [_x, "init", FUNC(addACEActions), true, [], true] call CBA_fnc_addClassEventHandler;
} forEach [
    "Helicopter",
    "VTOL_Base_F",
    "CUP_B_MV22_USMC"
];


///////////////////////////////////////////////////////////////////////////////
// cargo
///////////////////////////////////////////////////////////////////////////////
_displayName = localize LSTRING(RigForSlingLoad);
//_icon = "\a3\ui_f\data\igui\cfg\vehicletoggles\slingloadropeiconon2_ca.paa";
_condition = TF47_slingload_fnc_canRigCargo;
_statement = {};
_action = ["TF47_slingload_rig", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
["All", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(AutoRig);
//_icon = "\a3\ui_f\data\igui\cfg\vehicletoggles\slingloadropeiconon2_ca.paa";
_condition = TF47_slingload_fnc_canRigCargoAuto;
_statement = TF47_slingload_fnc_rigCargoAuto;
_action = ["TF47_slingload_rigAuto", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
["All", 0, ["ACE_MainActions","TF47_slingload_rig"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(ManualRig);
_icon = "\a3\ui_f\data\igui\rscingameui\rscunitinfoairrtdfull\ico_insp_hand_ca.paa";
_statement = TF47_slingload_fnc_rigCargoManual;
_condition = TF47_slingload_fnc_canRigCargoManual;
_action = ["TF47_slingload_rigManual", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
["All", 0, ["ACE_MainActions","TF47_slingload_rig"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(AdjustRigging);
_icon = "\a3\3den\Data\Cfg3DEN\History\scaleItems_ca.paa";
_statement = {};
_condition = TF47_slingload_fnc_canAdjustRigging;
_action = ["TF47_slingload_adjustRigging", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
["All", 0, ["ACE_MainActions","TF47_slingload_rig"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(AdjustRiggingAll);
//_icon = "\a3\3den\Data\Cfg3DEN\History\scaleItems_ca.paa";
_statement = {[_target, _player, true] call TF47_slingload_fnc_adjustRigging};
_condition = {true};
_action = ["TF47_slingload_adjustRiggingAll", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
["All", 0, ["ACE_MainActions","TF47_slingload_rig", "TF47_slingload_adjustRigging"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(AdjustRiggingSingle);
//_icon = "\a3\3den\Data\Cfg3DEN\History\scaleItems_ca.paa";
_statement = {[_target, _player, false] call TF47_slingload_fnc_adjustRigging};
//_condition = {true};
_action = ["TF47_slingload_adjustRiggingAll", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
["All", 0, ["ACE_MainActions","TF47_slingload_rig", "TF47_slingload_adjustRigging"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(RemoveRigging);
_icon = "\a3\ui_f\data\IGUI\Cfg\Actions\Obsolete\ui_action_cancel_ca.paa";
_statement = TF47_slingload_fnc_removeRigging;
_condition = TF47_slingload_fnc_canRemoveRigging;
_action = ["TF47_slingload_removeRigging", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
["All", 0, ["ACE_MainActions","TF47_slingload_rig"], _action, true] call ace_interact_menu_fnc_addActionToClass;

///////////////////////////////////////////////////////////////////////////////
// cargo sling apex fitting
///////////////////////////////////////////////////////////////////////////////
_displayName = localize "STR_ACE_Explosives_Pickup";
_statement = TF47_slingload_fnc_pickUpFitting;
_condition = {isNull (_player getVariable ["TF47_slingload_heldFitting", objNull])};
_icon = "\A3\ui_f\data\IGUI\Cfg\Actions\Obsolete\ui_action_takemine_ca.paa";
_action = ["TF47_slingload_pickup", _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
["TF47_slingload_apexFitting", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
