
params ["_player"];


_anchor = createVehicle ["WeaponHolderSimulated", player,[],0,"CAN_COLLIDE"];
_player removeItem "AUR_AnchorKit";

_anchor addWeaponCargoGlobal ["AUR_AnchorKit", 1];
//_anchor setPos (getPos player);
_anchor allowDamage false;

// _anchor addAction ["Attach Rope", {[player, (_this select 0),80] spawn TF47_fnc_AUR_Prepare_Rope;}, nil, 6, true, false, "", "true", 2, false,"","[player] call TF47_fnc_AUR_Prepare_Rope_Check"];

//rework needed
//put in AddAction File, make ACE Actions, translate!!
_anchor addAction   ["Attach 30m Rope", {[player, (_this select 0),30] spawn TF47_fnc_AUR_Prepare_Rope;}, nil, 6, true, false, "","[player, 30] call TF47_fnc_AUR_Prepare_Rope_Check", 2, false,"",""];
_anchor addAction   ["Attach 40m Rope", {[player, (_this select 0),40] spawn TF47_fnc_AUR_Prepare_Rope;}, nil, 6, true, false, "","[player, 40] call TF47_fnc_AUR_Prepare_Rope_Check", 2, false,"",""];
_anchor addAction   ["Attach 50m Rope", {[player, (_this select 0),50] spawn TF47_fnc_AUR_Prepare_Rope;}, nil, 6, true, false, "","[player, 50] call TF47_fnc_AUR_Prepare_Rope_Check", 2, false,"",""];
_anchor addAction   ["Attach 60m Rope", {[player, (_this select 0),60] spawn TF47_fnc_AUR_Prepare_Rope;}, nil, 6, true, false, "","[player, 60] call TF47_fnc_AUR_Prepare_Rope_Check", 2, false,"",""];
_anchor addAction   ["Attach 80m Rope", {[player, (_this select 0),80] spawn TF47_fnc_AUR_Prepare_Rope;}, nil, 6, true, false, "","[player, 80] call TF47_fnc_AUR_Prepare_Rope_Check", 2, false,"",""];
_anchor addAction   ["Attach 100m Rope", {[player, (_this select 0),100] spawn TF47_fnc_AUR_Prepare_Rope;}, nil, 6, true, false, "","[player, 100] call TF47_fnc_AUR_Prepare_Rope_Check", 2, false,"",""];