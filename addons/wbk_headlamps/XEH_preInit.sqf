[ 
    "WBK_HeadLamps_IsVolumetricAppearOnAIParam", 
    "LIST", 
    "Is volumetric light appear on AI gun flashlight?",
    "WebKnight HeadLamps",
    [[false, true], ["NO", "YES"], 0],
    1,
    {   
        params ["_value"]; 
        WBK_IsVolumetricAppearOnAI = _value; 
    }
] call CBA_fnc_addSetting;




[ 
    "WBK_HeadLamps_IsAIActivateHeadlamps", 
    "LIST", 
    "AI turn head lamps during night? (If they dont have nvg)",
    "WebKnight HeadLamps",
    [[false, true], ["NO", "YES"], 0],
    1,
    {   
        params ["_value"]; 
        WBK_IsAIEnableHeadlamps = _value; 
    }
] call CBA_fnc_addSetting;







["WebKnight Headlamps", "wbk_headlampOnOff", ["Enable/Disable headlamp", "Enable/Disable an headlamp"], { 
_unit = missionNamespace getVariable["bis_fnc_moduleRemoteControl_unit", player];
if ((lifeState _unit == "INCAPACITATED") or !(alive _unit) or !("WBK_HeadLampItem" in items _unit)) exitWith {};
_unit spawn WBK_CustomFlashlight;
}, {}, [38, [false, true, false]]] call cba_fnc_addKeybind;  



WBK_CreateAiHeadlampsAtNight = {
if (!(WBK_IsAIEnableHeadlamps) or (isPlayer _this)) exitWith {};
while {alive _this} do {
waitUntil {(daytime >= 19) and ("WBK_HeadLampItem" in items _this) and (hmd _this == "")};
_this spawn WBK_CustomFlashlight;
sleep 1;
waitUntil {((daytime >= 7) and (daytime < 19)) and ("WBK_HeadLampItem" in items _this) and (hmd _this == "")};
_this spawn WBK_CustomFlashlight;
sleep 1;
};
};



WBK_PlaySound = {
_dude = _this select 0;
_sound = _this select 1;
_rad = _this select 2;
_part = _this select 3;
_soundCache = "Land_HelipadEmpty_F" createVehicle position _dude;
_soundCache attachTo [_dude, [0, 0, 0], _part]; 
[_soundCache, _sound, _rad] call CBA_fnc_globalSay3d;
sleep 1;
deleteVehicle _soundCache;
};




WBK_CustomFlashlight = {
_unit = _this;
if (!(isNil {_unit getVariable "WBK_AttachedFlaslights"})) exitWith {
_unit playActionNow "WBK_head_flashlight_off";
[_unit, "WBK_flashlight_off",5,"head"] spawn WBK_PlaySound;
_var = _unit getVariable "WBK_AttachedFlaslights";
{
deleteVehicle _x;
} forEach _var;
_unit setVariable ["WBK_AttachedFlaslights",nil,true]; 
};
[_unit, "WBK_flashlight_on",5,"head"] spawn WBK_PlaySound;
_unit playActionNow "WBK_head_flashlight";
_light_head = "WBK_HeadLampLightObject" createVehicle [0,0,0]; 
_volumetric_l = createSimpleObject ["A3\data_f\VolumeLight_searchLightSmall", getPosASL _unit]; 
_unit spawn {
waitUntil {!(alive _this) or !(isNull objectParent _this) or (isNil {_this getVariable "WBK_AttachedFlaslights"}) or !("WBK_HeadLampItem" in items _this)};
if (!(isNil {_this getVariable "WBK_AttachedFlaslights"})) exitWith {
_var = _this getVariable "WBK_AttachedFlaslights";
{
deleteVehicle _x;
} forEach _var;
_this setVariable ["WBK_AttachedFlaslights",nil,true]; 
};
};
if ((getText (configfile >> "CfgWeapons" >> headgear _unit >> "displayName") find "Clone") == 0) exitWith { 
_light_head1 = "WBK_HeadLampLightObject" createVehicle [0,0,0]; 
_volumetric_2 = createSimpleObject ["A3\data_f\VolumeLight_searchLightSmall", getPosASL _unit]; 
_light_head1 attachto [_unit,[-0.17,0.041,0.22], "head",true];   
_volumetric_2 attachto [_unit,[-0.17,-0.01,0.2], "head",true];    
_light_head attachto [_unit,[0.05,0.041,0.22], "head",true];  
_volumetric_l attachto [_unit,[0.05,-0.01,0.2], "head",true];  
[_volumetric_l, {
_y = 0;  
_p = 190;  
_r  = 80; 
_this setVectorDirAndUp [        
 [sin _y * cos _p, cos _y * cos _p, sin _p],        
 [[sin _r, -sin _p, cos _r * cos _p], -_y] call BIS_fnc_rotateVector2D        
]; 
}] remoteExec ["call", 0];
[_volumetric_2, {
_y = 0;  
_p = 190;  
_r  = 80; 
_this setVectorDirAndUp [        
 [sin _y * cos _p, cos _y * cos _p, sin _p],        
 [[sin _r, -sin _p, cos _r * cos _p], -_y] call BIS_fnc_rotateVector2D        
]; 
}] remoteExec ["call", 0];
_unit setVariable ["WBK_AttachedFlaslights",[_volumetric_l,_light_head,_volumetric_2,_light_head1],true]; 
};
_unit setVariable ["WBK_AttachedFlaslights",[_volumetric_l,_light_head],true]; 
if (typeOf _unit isKindOf "TIOWSpaceMarine_Base") exitWith { 
_light_head attachto [_unit,[0.05,-0.13,0.12], "head",true];   
_volumetric_l attachto [_unit,[0.04,-0.19,0.09], "head",true];    
[_volumetric_l, {
_y = 0;  
_p = 190;  
_r  = 80; 
_this setVectorDirAndUp [        
 [sin _y * cos _p, cos _y * cos _p, sin _p],        
 [[sin _r, -sin _p, cos _r * cos _p], -_y] call BIS_fnc_rotateVector2D        
]; 
}] remoteExec ["call", 0];
}; 
_light_head attachto [_unit,[0,0.041,0.22], "head",true];  
_volumetric_l attachto [_unit,[0,-0.01,0.2], "head",true];   
[_volumetric_l, {
_y = 0;  
_p = 190;  
_r  = 80; 
_this setVectorDirAndUp [        
 [sin _y * cos _p, cos _y * cos _p, sin _p],        
 [[sin _r, -sin _p, cos _r * cos _p], -_y] call BIS_fnc_rotateVector2D        
]; 
}] remoteExec ["call", 0];
};







WBK_CreateLightOnGun = {
if (!(isPlayer _this) and !(WBK_IsVolumetricAppearOnAI)) exitWith {};
while {alive _this} do {
waitUntil {(_this isFlashlightOn (currentWeapon _this)) and (isNull objectParent _this)};
[_this, "WBK_flashlight_on",5,"leftHand"] spawn WBK_PlaySound;
_crtWeap = currentWeapon _this;
_volumetric_l = createSimpleObject ["A3\data_f\VolumeLight_searchLightSmall", getPosASL _this]; 
if (currentWeapon _this == primaryWeapon _this) then {
_volumetric_l attachto [_this,[0.51,0.8,-0.15], "weapon",true]; 
[_volumetric_l, 180] remoteExec ["setDir", 0];   
}else{
_volumetric_l attachto [_this,[0,-0.03,-0.05], "rightHand",true];     
[_volumetric_l, {
_y = 90; 
_p = 130; 
_r  = 90; 
_this setVectorDirAndUp [        
 [sin _y * cos _p, cos _y * cos _p, sin _p],        
 [[sin _r, -sin _p, cos _r * cos _p], -_y] call BIS_fnc_rotateVector2D        
]; 
}] remoteExec ["call", 0];
};
Uisleep 0.01;
waitUntil {!(_this isFlashlightOn (currentWeapon _this)) or !(currentWeapon _this == _crtWeap) or !(isNull objectParent _this)};
[_this, "WBK_flashlight_off",5,"leftHand"] spawn WBK_PlaySound;
deleteVehicle _volumetric_l;
Uisleep 0.01;
};
};