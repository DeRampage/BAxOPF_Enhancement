if (!(hasInterface )) exitWith {};
[] spawn
{
waitUntil { !isNull findDisplay 46 };
lastPressedkeyCheck = 0;
lastPressedKey = 0;
temp = true;
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



(findDisplay 46) displayAddEventHandler ["KeyDown", {
    _key = _this select 1;
    if ((_key == 31) and ((animationState player == "ARMA_AlternativeRunWithLauncher") or (animationState player == "ARMA_AlternativePistol") or (animationState player == "ARMA_AlternativeRun_Water_Light") or (animationState player == "ARMA_AlternativeRun") or (animationState player == "ARMA_AlternativeRunLowered") or (animationState player == "ARMA_AlternativeRun_Water_Heavy"))) then {
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
}];




(findDisplay 46) displayAddEventHandler ["KeyUp", {
  if (!(WBK_AR_DOUBLESHIFT)) exitWith {};
    _key = _this select 1;
        if ((_key == 42)) then {
		if ((animationState player == "ARMA_AlternativeRun_Water_Light") or (animationState player == "ARMA_AlternativeRun") or (animationState player == "ARMA_AlternativeRunLowered") or (animationState player == "ARMA_AlternativeRun_Water_Heavy")) then {
		player playMoveNow "AmovPercMstpSrasWrflDnon";
		};
		temp = true;
		};
}];

(findDisplay 46) displayAddEventHandler ["KeyDown", {
 if (!(WBK_AR_DOUBLESHIFT)) exitWith {};
    _key = _this select 1;
    if ((_key == 42) and ((player getHit "legs") < 0.5) and (isSprintAllowed player) and !(currentWeapon player == "") and (primaryWeapon player == currentWeapon player) and (temp) and !(stance player == "UNDEFINED") and (player == vehicle player) and ((getPosASL player select 2) > -1.45)) then {
	if  ((lastPressedkeyCheck <= 0.5)) then {
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
	lastPressedkeyCheck = 0;
	temp = false;
	};
}];



/////////////Pistol
(findDisplay 46) displayAddEventHandler ["KeyUp", {
 if (!(WBK_AR_DOUBLESHIFT)) exitWith {};
    _key = _this select 1;
        if ((_key == 42)) then {
		if ((animationState player == "ARMA_AlternativePistol")) then {
		player playMoveNow "AmovPercMstpSrasWpstDnon";
		};
		temp = true;
		};
}];

(findDisplay 46) displayAddEventHandler ["KeyDown", {
 if (!(WBK_AR_DOUBLESHIFT)) exitWith {};
    _key = _this select 1;
    if ((_key == 42) and ((player getHit "legs") < 0.5) and (isSprintAllowed player) and !(currentWeapon player == "") and (handgunWeapon player == currentWeapon player) and (temp) and ((getStamina player) >= 3) and !(stance player == "UNDEFINED") and (player == vehicle player) and ((getPosASL player select 2) > -0.6)) then {
	if  ((lastPressedkeyCheck <= 0.5)) then {
	player playMoveNow "ARMA_AlternativePistol";
	};
	lastPressedkeyCheck = 0;
	temp = false;
	};
}];



/////////////Launcher
(findDisplay 46) displayAddEventHandler ["KeyUp", {
 if (!(WBK_AR_DOUBLESHIFT)) exitWith {};
    _key = _this select 1;
        if ((_key == 42)) then {
		if ((animationState player == "ARMA_AlternativeRunWithLauncher")) then {
		player playMoveNow "AmovPercMstpSrasWlnrDnon";
		};
		temp = true;
		};
}];

(findDisplay 46) displayAddEventHandler ["KeyDown", {
 if (!(WBK_AR_DOUBLESHIFT)) exitWith {};
    _key = _this select 1;
    if ((_key == 42) and ((player getHit "legs") < 0.5) and (isSprintAllowed player) and !(currentWeapon player == "") and (secondaryWeapon player == currentWeapon player) and (temp) and ((getStamina player) >= 3) and !(stance player == "UNDEFINED") and (player == vehicle player) and ((getPosASL player select 2) > -0.6)) then {
	if  ((lastPressedkeyCheck <= 0.5)) then {
	player playMoveNow "ARMA_AlternativeRunWithLauncher";
	};
	lastPressedkeyCheck = 0;
	temp = false;
	};
}];



[] spawn {
while {true} do {
if ((((player getHit "legs") >= 0.5) or !(isSprintAllowed player) or ((getPosASL player select 2) < -1.45) or ((getPosASL player select 2) > -0.6)) and ((animationState player == "ARMA_AlternativeRun_Water_Light") or (animationState player == "ARMA_AlternativeRun_Water_Heavy"))) then {
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
sleep 0.1;
};
};


while {true} do {
lastPressedkeyCheck = lastPressedkeyCheck + 0.1;
if ((((getStamina player) <= 3) or ((player getHit "legs") >= 0.5) or !(isSprintAllowed player) or ((getPosASL player select 2) < -0.6)) and ((animationState player == "ARMA_AlternativeRunWithLauncher") or (animationState player == "ARMA_AlternativeRun") or (animationState player == "ARMA_AlternativePistol") or (animationState player == "ARMA_AlternativeRunLowered"))) then {
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
sleep 0.1;
};
};