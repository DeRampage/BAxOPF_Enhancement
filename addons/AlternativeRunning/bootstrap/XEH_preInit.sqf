["Alternative Running", "AR_EnableDisable", ["Activate/Deactivate alternative running", "Activate Alternative Running"], { 
if ((animationState player == "ARMA_AlternativeRunWithLauncher") or (animationState player == "ARMA_AlternativePistol") or (animationState player == "ARMA_AlternativeRun_Water_Light") or (animationState player == "ARMA_AlternativeRun") or (animationState player == "ARMA_AlternativeRunLowered") or (animationState player == "ARMA_AlternativeRun_Water_Heavy")) exitWith {
	    if ((primaryWeapon player == currentWeapon player)) then {
	    player playMoveNow "AmovPercMstpSrasWrflDnon";
	    }else{
	    if ((currentWeapon player == secondaryWeapon player)) then {
	    player playMoveNow "AmovPercMstpSrasWlnrDnon";
	    }else{
	    player playMoveNow "AmovPercMstpSrasWpstDnon";
	    };
	    };
};
if (!(currentWeapon player == "") and (primaryWeapon player == currentWeapon player)) exitWith {
if (((player getHit "legs") < 0.5) and (isSprintAllowed player) and !(stance player == "UNDEFINED") and (player == vehicle player) and ((getPosASL player select 2) > -1.45)) then {
	if ((getPosASL player select 2) < -0.6) then {
	_weapInfo = getNumber (configfile >> "CfgMagazines" >> currentMagazine player >> "count");
	if (_weapInfo >= 40) then {
	player playMoveNow "ARMA_AlternativeRun_Water_Heavy";
	}else{
	player playMoveNow "ARMA_AlternativeRun_Water_Light";
	};
	}else{
	if ((getStamina player) >= 3) then {
	_weapInfo = getNumber (configfile >> "CfgMagazines" >> currentMagazine player >> "count");
	if (((_weapInfo <= 10) or (_weapInfo >= 40)) and (WBK_AR_MGBOLTISWORK)) then {
	player playMoveNow "ARMA_AlternativeRunLowered";
	}else{
	player playMoveNow "ARMA_AlternativeRun";
	};
	};
	};
};
};
if (!(currentWeapon player == "") and (handgunWeapon player == currentWeapon player)) exitWith {
if (((player getHit "legs") < 0.5) and (isSprintAllowed player) and ((getStamina player) >= 3) and !(stance player == "UNDEFINED") and (player == vehicle player) and ((getPosASL player select 2) > -0.6)) then {
	player playMoveNow "ARMA_AlternativePistol";
};
};
if (!(currentWeapon player == "") and (secondaryWeapon player == currentWeapon player)) exitWith {
if (((player getHit "legs") < 0.5) and (isSprintAllowed player) and ((getStamina player) >= 3) and !(stance player == "UNDEFINED") and (player == vehicle player) and ((getPosASL player select 2) > -0.6)) then {
	player playMoveNow "ARMA_AlternativeRunWithLauncher";
};
};
}, {}, [17, [true, false, true]]] call cba_fnc_addKeybind; 




[ 
    "AR_EnableDisableDoubleShiftPress", 
    "LIST", 
    "Enable AR on Double shift?",
    "Alternative Running (Client Settings)",
    [[true, false], ["YES", "NO"], 0],
    0,
    {   
        params ["_value"]; 
        WBK_AR_DOUBLESHIFT = _value; 
    }
] call CBA_fnc_addSetting;



[ 
    "AR_EnableDisableAltRunMGBOLT", 
    "LIST", 
    "Enable run animation for MG/Bolt action?",
    "Alternative Running (Client Settings)",
    [[true, false], ["YES", "NO"], 0],
    0,
    {   
        params ["_value"]; 
        WBK_AR_MGBOLTISWORK = _value; 
    }
] call CBA_fnc_addSetting;