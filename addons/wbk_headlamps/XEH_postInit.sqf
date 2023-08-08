if (isServer) then {
addMissionEventHandler ['HandleDisconnect',{
_unit = _this select 0;
if (!(isNil {_unit getVariable "WBK_AttachedFlaslights"})) exitWith {
_var = _unit getVariable "WBK_AttachedFlaslights";
{
deleteVehicle _x;
} forEach _var;
};
}];
};




if (!(hasInterface )) exitWith {};
[] spawn
{
	waitUntil { !isNull findDisplay 46 };
	sleep 0.5;
	player setVariable ["WBK_AttachedFlaslights",nil,true];
["WebKnight Headlamps", "wbk_headlampOnOff", ["Enable/Disable headlamp", "Enable/Disable an headlamp"], { 
_unit = missionNamespace getVariable["bis_fnc_moduleRemoteControl_unit", player];
if ((lifeState _unit == "INCAPACITATED") or !(alive _unit) or !("WBK_HeadLampItem" in items _unit)) exitWith {};
_unit spawn WBK_CustomFlashlight;
}, {}, [38, [false, true, false]]] call cba_fnc_addKeybind;  
};