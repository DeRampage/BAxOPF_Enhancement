gge_swap_var_swappedLastFrame = false;
gge_swap_var_swapping = false;
gge_swap_var_lastFrameWep = currentWeapon player;
gge_swap_var_animStateBeforeSwitch = animationState player;

gge_swap_var_rifleState = "AmovPercMstpSrasWrflDnon_AmovPercMstpSlowWrflDnon";
gge_swap_var_handgunState = "AmovPercMstpSrasWpstDnon_AmovPercMstpSlowWpstDnon";
gge_swap_var_launcherState = "amovpercmstpslowwlnrdnon";
gge_swap_var_binocularState = "AmovPercMstpSoptWbinDnon";


gge_swap_var_wepHolderOffset_normal = [0,0.7,-1.4];
gge_swap_var_wepHolderOffset_side_normal = [-0.7,0.3,-1.7];
gge_swap_var_wepHolderOffset_tactical = [0.05,0.985,-1.475];
gge_swap_var_wepHolderOffset_side_tactical = [-0.65,0.5,-1.775];

gge_swap_var_shouldStoreRifleNextFrame = false;

gge_swap_var_wepHolderOffset = gge_swap_var_wepHolderOffset_normal;
gge_swap_var_wepHolderOffset_side = gge_swap_var_wepHolderOffset_side_normal;


gge_swap_var_PBY = [90,70,-180];
gge_swap_var_PBY_side = [120,50,100];

gge_swap_var_chestWeaponHolder = "GroundWeaponHolder_Scripted" createVehicle [0,0,0];

gge_swap_var_selectedMode = 0;

gge_swap_var_tacticalAnimationsEnabled = false;

gge_swap_var_magazineItemCargo = [];


gge_swap_var_primaryWeaponsItems = [];
gge_swap_previousMag = nil;

// Animations
// R2P Stages
_r2p1 = ["gge_swap_anim_R2P1", -1, false, false, {
    // Store rifle on chest
    //[false] call gge_swap_fnc_storeWeaponOnChest;
    gge_swap_var_shouldStoreRifleNextFrame = true;
}];
_r2p2 = ["gge_swap_anim_R2P2", -1, false, false, {}];
_r2p1_side = ["gge_swap_anim_R2P1_side", -1, false, false, {
    // Store rifle on chest
    //[false] call gge_swap_fnc_storeWeaponOnChest;
    gge_swap_var_shouldStoreRifleNextFrame = true;
}];
_r2p2_side = ["gge_swap_anim_R2P2_side", -1, false, false, {}];
gge_swap_var_r2p_anim = [[_r2p1, _r2p2], {gge_swap_var_swapping = false;}];
gge_swap_var_r2p_side_anim = [[_r2p1_side, _r2p2_side], {gge_swap_var_swapping = false;}];

gge_swap_var_r2p_anim_used = gge_swap_var_r2p_anim;

// P2R Stages
_p2r1 = ["gge_swap_anim_P2R1", -1, false, false, {}];
_p2r2 = ["gge_swap_anim_P2R2", -1, false, false, {}];
_p2r1_side = ["gge_swap_anim_P2R1_side", -1, false, false, {}];
_p2r2_side = ["gge_swap_anim_P2R2_side", -1, false, false, {}];
gge_swap_var_p2r_anim = [[_p2r1, _p2r2], {gge_swap_var_swapping = false;}];
gge_swap_var_p2r_side_anim = [[_p2r1_side, _p2r2_side], {gge_swap_var_swapping = false;}];

gge_swap_var_p2r_anim_used = gge_swap_var_p2r_anim;


// R2L Stages
_r2l1 = ["gge_swap_anim_R2P1", -1, false, false, {
    // Store rifle on chest
    //[false] call gge_swap_fnc_storeWeaponOnChest;
    gge_swap_var_shouldStoreRifleNextFrame = true;
}];
//_r2l2 = ["gge_swap_anim_LU", -1, false, false, {}];
gge_swap_var_r2l_anim = [[_r2l1], {gge_swap_var_swapping = false;}];

// L2R Stages
_l2r1 = ["gge_swap_anim_LD", -1, false, false, {}];
_l2r2 = ["gge_swap_anim_P2R2", -1, false, false, {}];
gge_swap_var_l2r_anim = [[_l2r1, _l2r2], {gge_swap_var_swapping = false;}];

// R2B Stages
_r2b1 = ["gge_swap_anim_R2P1", -1, false, false, {
gge_swap_var_shouldStoreRifleNextFrame = true;
//[false] call gge_swap_fnc_storeWeaponOnChest;
}];
_r2b2 = ["gge_swap_anim_BU", -1, false, false, {}];
gge_swap_var_r2b_anim = [[_r2b1, _r2b2], {gge_swap_var_swapping = false; [binocular player] call gge_swap_fnc_instantSwapWeapon; player selectWeapon binocular player;}];

// B2R Stages
_b2r1 = ["gge_swap_anim_BD", -1, false, false, {call gge_swap_fnc_retrieveWeaponFromChest}];
_b2r2 = ["gge_swap_anim_P2R2", -1, false, false, {}];
gge_swap_var_b2r_anim = [[_b2r1, _b2r2], {gge_swap_var_swapping = false;}];

// R2U Stages
_r2u1 = ["gge_swap_anim_R2P1", -1, false, false, {
 gge_swap_var_shouldStoreRifleNextFrame = true;
 gge_swap_var_switchingToUnarmed = true;
 //[true] call gge_swap_fnc_storeWeaponOnChest
 }];
//gge_swap_var_r2u_anim = [[_r2u1], {gge_swap_var_swapping = false; [{[""] call gge_swap_fnc_instantSwapWeapon; player action ["SwitchWeapon", player, player, -1];}] call CBA_fnc_execNextFrame;}];
gge_swap_var_r2u_anim = [[_r2u1], {gge_swap_var_swapping = false;}];
// U2R Stages
_u2r1 = ["gge_swap_anim_P2R2", -1, false, false, {}];
gge_swap_var_u2r_anim = [[_u2r1], {gge_swap_var_swapping = false;}];


// Sourced from ffur2007slx2_5 via https://community.bistudio.com/wiki/BIS_fnc_setPitchBank
fnc_SetPitchBankYaw = { 
    private ["_object","_rotations","_aroundX","_aroundY","_aroundZ","_dirX","_dirY",
    "_dirZ","_upX","_upY","_upZ","_dir","_up","_dirXTemp","_upXTemp"];
    _object = _this select 0; 
    _rotations = _this select 1; 
    _aroundX = _rotations select 0; 
    _aroundY = _rotations select 1; 
    _aroundZ = (360 - (_rotations select 2)) - 360; 
    _dirX = 0; 
    _dirY = 1; 
    _dirZ = 0; 
    _upX = 0; 
    _upY = 0; 
    _upZ = 1; 
    if (_aroundX != 0) then { 
        _dirY = cos _aroundX; 
        _dirZ = sin _aroundX; 
        _upY = -sin _aroundX; 
        _upZ = cos _aroundX; 
    }; 
    if (_aroundY != 0) then { 
        _dirX = _dirZ * sin _aroundY; 
        _dirZ = _dirZ * cos _aroundY; 
        _upX = _upZ * sin _aroundY; 
        _upZ = _upZ * cos _aroundY; 
    }; 
    if (_aroundZ != 0) then { 
        _dirXTemp = _dirX; 
        _dirX = (_dirXTemp* cos _aroundZ) - (_dirY * sin _aroundZ); 
        _dirY = (_dirY * cos _aroundZ) + (_dirXTemp * sin _aroundZ);        
        _upXTemp = _upX; 
        _upX = (_upXTemp * cos _aroundZ) - (_upY * sin _aroundZ); 
        _upY = (_upY * cos _aroundZ) + (_upXTemp * sin _aroundZ);         
    }; 
    _dir = [_dirX,_dirY,_dirZ]; 
    _up = [_upX,_upY,_upZ]; 
    _object setVectorDirAndUp [_dir,_up]; 
};  


gge_swap_fnc_toggleFunnysAnimations = {
    call gge_swap_fnc_attachWeaponHolder;
};

gge_swap_fnc_attachWeaponHolder = {
    params [["_toUnarmed", false, [false]]];
    detach gge_swap_var_chestWeaponHolder;
    player disableCollisionWith gge_swap_var_chestWeaponHolder;
    gge_swap_var_wepHolderOffset = [gge_swap_var_wepHolderOffset_normal, gge_swap_var_wepHolderOffset_tactical] select gge_swap_var_tacticalAnimationsEnabled;    
    gge_swap_var_wepHolderOffset_side = [gge_swap_var_wepHolderOffset_side_normal, gge_swap_var_wepHolderOffset_side_tactical] select gge_swap_var_tacticalAnimationsEnabled;
        
    
    
    // If we're switching to unarmed then we want to store gat on chest regardless of setting
    if (_toUnarmed && (gge_swap_var_selectedMode == 1)) then {
        gge_swap_var_wepHolderOffset_side = [gge_swap_var_wepHolderOffset_normal, gge_swap_var_wepHolderOffset_tactical] select gge_swap_var_tacticalAnimationsEnabled;
    };

    _pars = [[gge_swap_var_wepHolderOffset, gge_swap_var_PBY], [gge_swap_var_wepHolderOffset_side, gge_swap_var_PBY_side]] select gge_swap_var_selectedMode;

    if (_toUnarmed && (gge_swap_var_selectedMode == 1)) then {    
        _pars set [1, gge_swap_var_PBY];
    };
    gge_swap_var_r2p_anim_used = [gge_swap_var_r2p_anim, gge_swap_var_r2p_side_anim] select gge_swap_var_selectedMode;
    gge_swap_var_p2r_anim_used = [gge_swap_var_p2r_anim, gge_swap_var_p2r_side_anim] select gge_swap_var_selectedMode;

    _animState = animationState player;
    player switchMove "AmovPercMstpSrasWrflDnon_AmovPercMstpSlowWrflDnon";
    gge_swap_var_chestWeaponHolder attachTo [player, (player selectionPosition "spine3") vectorAdd (_pars select 0), "spine3"]; 
    [gge_swap_var_chestWeaponHolder, _pars select 1] call fnc_SetPitchBankYaw;
    player switchMove _animState;
    gge_swap_var_chestWeaponHolder hideObject true;
    // Fix up weapon to side after we've switched
    if (_toUnarmed) then {
        gge_swap_var_wepHolderOffset_side = [gge_swap_var_wepHolderOffset_side_normal, gge_swap_var_wepHolderOffset_side_tactical] select gge_swap_var_tacticalAnimationsEnabled;
    };
};


// Make sure player is initialised before setting up offset
waitUntil {(!isNull (findDisplay 46))};

call gge_swap_fnc_attachWeaponHolder;




// Make sure we're not putting shit in the wepaon holder when we take something
player addEventHandler ["Take", {
    params ["_unit", "_container", "_item"];
    gge_swap_var_chestWeaponHolder setDamage 0;
    
    
    // Cleanse weapon holder to floor
    _dropHolder =  createVehicle ["WeaponHolderSimulated", player modelToWorld [0,0,1], [], 0, "CAN_COLLIDE"];
    _dropHolder addMagazineCargoGlobal magazineCargo gge_swap_var_chestWeaponHolder;
    _dropHolder addItemCargoGlobal itemCargo gge_swap_var_chestWeaponHolder;
    _dropHolder addBackpackCargoGlobal backpackCargo gge_swap_var_chestWeaponHolder;
    clearMagazineCargoGlobal (gge_swap_var_chestWeaponHolder);
    clearItemCargoGlobal (gge_swap_var_chestWeaponHolder);
    clearBackpackCargoGlobal (gge_swap_var_chestWeaponHolder);
    gge_swap_var_chestWeaponHolder setDamage 1;
    
    
    // Remove any dirty empty rifles added to container
    _result = [_container, "Rifle"] call CBA_fnc_removeWeaponCargo;

}];

// Make sure we don't leave empty rifles everywhere
player addEventHandler ["Put", {
    params ["_unit", "_container", "_item"];
    if (_item == "Rifle") then {
        // Remove any dirty empty rifles added to container
        _result = [_container, "Rifle"] call CBA_fnc_removeWeaponCargo;
    };
}];

// Hide weapon holder when enter vehicle
player addEventHandler ["GetInMan", {
    params ["_unit", "_role", "_vehicle", "_turret"];
    gge_swap_var_chestWeaponHolder setDamage 0;
    [gge_swap_var_chestWeaponHolder, true] remoteExec ["hideObject", 0];
    gge_swap_var_chestWeaponHolder setDamage 1;
}];

// Unhide weapon holder when exit vehicle
player addEventHandler ["GetOutMan", {
    params ["_unit", "_role", "_vehicle", "_turret"];
    gge_swap_var_chestWeaponHolder setDamage 0;
    [gge_swap_var_chestWeaponHolder, false] remoteExec ["hideObject", 0];
    gge_swap_var_chestWeaponHolder setDamage 1;
}];

// Reset weapon holder pos on respawn
player addEventHandler ["Respawn", {
    params ["_unit", "_corpse"];
    
    detach gge_swap_var_chestWeaponHolder;
    
    call gge_swap_fnc_attachWeaponHolder;
    
}];

// Drop chest gat on death
player addEventHandler ["Killed", {
    params ["_unit", "_killer", "_instigator", "_useEffects"];
    
    gge_swap_var_chestWeaponHolder setDamage 0;
    // Cleanse weapon holder to floor
    _dropHolder =  createVehicle ["WeaponHolderSimulated", player modelToWorld [0,0,1], [], 0, "CAN_COLLIDE"];
    _dropHolder addMagazineCargoGlobal magazineCargo gge_swap_var_chestWeaponHolder;
    _dropHolder addItemCargoGlobal itemCargo gge_swap_var_chestWeaponHolder;
    _dropHolder addBackpackCargoGlobal backpackCargo gge_swap_var_chestWeaponHolder;
    _weps = weaponsItemsCargo gge_swap_var_chestWeaponHolder;
    {_dropHolder addWeaponWithAttachmentsCargo [_x, 1];} foreach _weps;
    clearMagazineCargoGlobal (gge_swap_var_chestWeaponHolder);
    clearItemCargoGlobal (gge_swap_var_chestWeaponHolder);
    clearBackpackCargoGlobal (gge_swap_var_chestWeaponHolder);
    clearWeaponCargoGlobal (gge_swap_var_chestWeaponHolder);
    gge_swap_var_chestWeaponHolder setDamage 1;
    
}];



// Sourced from PixeL_GaMMa via https://forums.bohemia.net/forums/topic/216673-quick-stringreplace/
PX_fnc_splitReplace = {
    params["_str", "_find", "_replace"];    
    private _result = ([" "+_str+" ", _find, true] call BIS_fnc_splitString) joinString _replace;    
    _result select [1, (count _result)-2];
};

gge_swap_fnc_storeWeaponOnChest = {
    params ["_toUnarmed"];
    
    [_toUnarmed] call gge_swap_fnc_attachWeaponHolder;
    
    gge_swap_var_chestWeaponHolder enableSimulationGlobal true;
    gge_swap_var_chestWeaponHolder hideObject false;
    gge_swap_var_chestWeaponHolder setDamage 0;
    _primaryWepItems = ((weaponsItems player) select {(_x select 0) == (primaryWeapon player)}) select 0;
    //gge_swap_var_primaryWeaponsItems = _primaryWeaponItems;
    gge_swap_var_chestWeaponHolder addWeaponWithAttachmentsCargoGlobal [_primaryWepItems, 1];
    player removeWeapon (primaryWeapon player);
    player addWeapon "Rifle";
    gge_swap_var_chestWeaponHolder setDamage 1;
    
    if (_toUnarmed) then {
        player action ["SwitchWeapon", player, player, 299];
    };
};

gge_swap_fnc_addWeaponWithAttachmentsToUnit = {
    params["_weaponDetails"];
    _weapon = _weaponDetails select 0;
    _accessories = _weaponDetails - [_weaponDetails select 0];
    
    player addWeapon _weapon;
    
    {
        player addWeaponItem [_weapon, _x, true];
    }foreach _accessories;
    
};

gge_swap_fnc_retrieveWeaponFromChest = {

    _allMags = magazinesAmmoFull player;
    _vestMags = _allMags select {"Vest" in (_x select 4)};
    _uniformMags = _allMags select {"Uniform" in (_x select 4)};
    _backpackMags = _allMags select {"Backpack" in (_x select 4)};
    _nonGrenadeMuzzleClasses = ["Vest", "Backpack", "Uniform", primaryWeapon player, secondaryWeapon player, handgunWeapon player];
    _grenadesInMuzzle = _allMags select {!((_x select 4) in _nonGrenadeMuzzleClasses)};
    
    
    [((weaponsItemsCargo gge_swap_var_chestWeaponHolder) select 0)] call gge_swap_fnc_addWeaponWithAttachmentsToUnit;
    {player removeMagazine _x} forEach magazines player;
    
    {(vestContainer player) addMagazineAmmoCargo [_x select 0, 1, _x select 1];} foreach _vestMags;
    {(uniformContainer player) addMagazineAmmoCargo [_x select 0, 1, _x select 1];} foreach _uniformMags;
    {(backpackContainer player) addMagazineAmmoCargo [_x select 0, 1, _x select 1];} foreach _backpackMags;
    {player addMagazine (_x select 0); player selectWeapon (_x select 4);} foreach _grenadesInMuzzle;
    
    clearWeaponCargoGlobal gge_swap_var_chestWeaponHolder;
    storedPrimaryWeaponItems = "";
    
    gge_swap_var_chestWeaponHolder hideObject true;
    gge_swap_var_chestWeaponHolder enableSimulationGlobal false;
    
};

gge_swap_fnc_instantSwapWeapon = {
    params ["_wepToSwapTo"];
    
    // To handgun
    if (_wepToSwapTo == handgunWeapon player) then {
        [[ player,gge_swap_var_handgunState], "switchMove"] call BIS_fnc_MP;
        ["gge_core_anim_clearAction"] call gge_core_fnc_playGesture;
        //[["gge_core_anim_clearAction"], "playActionNow"] call BIS_fnc_MP;
    };
    // To rifle
    if (_wepToSwapTo == primaryWeapon player) then {
        [[ player,gge_swap_var_rifleState], "switchMove"] call BIS_fnc_MP;
        ["gge_core_anim_clearAction"] call gge_core_fnc_playGesture;
        //[["gge_core_anim_clearAction"], "playActionNow"] call BIS_fnc_MP;
    };
    // To launcher
    if (_wepToSwapTo == secondaryWeapon player) then {
        [[ player,gge_swap_var_launcherState], "switchMove"] call BIS_fnc_MP;
        ["gge_core_anim_clearAction"] call gge_core_fnc_playGesture;

        //[["gge_core_anim_clearAction"], "playActionNow"] call BIS_fnc_MP;
    };
    // To binos
    if (_wepToSwapTo == binocular player) then {
        [[ player,gge_swap_var_binocularState], "switchMove"] call BIS_fnc_MP;
        ["gge_core_anim_clearAction"] call gge_core_fnc_playGesture;

        //[["gge_core_anim_clearAction"], "playActionNow"] call BIS_fnc_MP;
    };
    
    // To unarmed
    if (_wepToSwapTo == "") then {
        [[ player,"amovpercmstpsnonwnondnon"], "switchMove"] call BIS_fnc_MP;
        ["gge_core_anim_clearAction"] call gge_core_fnc_playGesture;
        //player action ["SWITCHWEAPON",player,player,-1];
        //[["gge_swap_anim_R2P1"], "playActionNow"] call BIS_fnc_MP;
        //null = [this] spawn {sleep 0.6; player action ['SwitchWeapon', player, player, 100];};
    };
            
};

gge_swap_fnc_updateAnim = {
    params ["_find", "_replace"];
    [[ player,[gge_swap_var_animStateBeforeSwitch, _find, _replace] call PX_fnc_splitReplace], "switchMove"] call BIS_fnc_MP;
    ["gge_core_anim_clearAction"] call gge_core_fnc_playGesture;
};

gge_swap_fnc_handleSwap = {
    
    if ((gge_swap_var_lastFrameWep == "Rifle") && (currentWeapon player == "Rifle")) then {
        if (!((weaponsItemsCargo gge_swap_var_chestWeaponHolder) isEqualTo [])) then {
            [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
                call gge_swap_fnc_retrieveWeaponFromChest;
                gge_swap_var_p2r_anim_used call gsas_fnc_playStagedAnimation;
                gge_swap_var_swapping = true;
        };
    };
    
    if (stance player == "PRONE") exitWith {};
    
    // If we are not reloading, update magazine info
    /*
    if (!gge_core_var_isReloading) then {
        gge_swap_var_magazineItemCargo set [0, magazinesDetailUniform player];
        gge_swap_var_magazineItemCargo set [1, magazinesDetailVest player];
        gge_swap_var_magazineItemCargo set [2, magazinesDetailBackpack player];    
        gge_swap_var_magazineItemCargo = magazineCargo player;
    };
    */
    
    if (currentMagazine player != "") then {
        gge_swap_previousMag = [currentMagazine player, player ammo currentWeapon player];
    };
    
    // We have swapped while reloading!
    /*
    if (gge_core_var_isReloading && gge_swap_var_swapping) then {
        if (!(isNil gge_swap_previousMag)) then {
            player addMagazine gge_swap_previousMag;
        };
    };
    */
    
    if (gge_swap_var_shouldStoreRifleNextFrame) then {
        [gge_swap_var_switchingToUnarmed] call gge_swap_fnc_storeWeaponOnChest;
        gge_swap_var_shouldStoreRifleNextFrame = false;
        gge_swap_var_switchingToUnarmed = false;
    };
    
    // Weapon has been switched
    if (currentWeapon player != gge_swap_var_lastFrameWep) then {
            
        // Handle switch anim state
        gge_swap_var_animStateBeforeSwitch = configName (configFile >> getText (configFile >> "CfgVehicles" >> typeOf player >> "moves") >> "States" >> (animationState player));
        
        // If current weapon is rifle and different to rifle stored on chest, put chest rifle on ground and replace with this rifle
        // new wep is primary check
        _isPrimary = (currentWeapon player == primaryWeapon player) && currentWeapon player != "Rifle";
        if (_isPrimary && !((weaponsItemsCargo gge_swap_var_chestWeaponHolder) isEqualTo [])) then {
            _droppedWep =  createVehicle ["WeaponHolderSimulated", player modelToWorld [0,0,1], [], 0, "CAN_COLLIDE"];
            _droppedWep addWeaponWithAttachmentsCargoGlobal [(weaponsItemsCargo gge_swap_var_chestWeaponHolder) select 0, 1];
            gge_swap_var_chestWeaponHolder setDamage 0;
            clearWeaponCargoGlobal gge_swap_var_chestWeaponHolder;
            gge_swap_var_chestWeaponHolder setDamage 1;
            //[false] call gge_swap_fnc_storeWeaponOnChest;
        };
        
        // Handle swap anim
        switch (currentWeapon player) do {
            case primaryWeapon player: {
                switch (gge_swap_var_lastFrameWep) do {
                    //P2R
                    case handgunWeapon player: {
                        // Instant swap
                        // Play anims next frame
                        [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
                        call gge_swap_fnc_retrieveWeaponFromChest;
                        ["pst", "rfl"] call gge_swap_fnc_updateAnim;
                        gge_swap_var_p2r_anim_used call gsas_fnc_playStagedAnimation;
                        gge_swap_var_swapping = true;
                    };
                    //L2R
                    case secondaryWeapon player: {
                        [primaryWeapon player] call gge_swap_fnc_instantSwapWeapon;
                        call gge_swap_fnc_retrieveWeaponFromChest;
                        ["lnr", "rfl"] call gge_swap_fnc_updateAnim;
                        gge_swap_var_l2r_anim call gsas_fnc_playStagedAnimation;
                        gge_swap_var_swapping = true;
                    };
                    //B2R
                    case binocular player: {
                        [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
                        ["bin", "rfl"] call gge_swap_fnc_updateAnim;
                        gge_swap_var_b2r_anim call gsas_fnc_playStagedAnimation;
                        gge_swap_var_swapping = true;
                    };                    
                    /*
                    case primaryWeapon player: {
                        [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
                        call gge_swap_fnc_retrieveWeaponFromChest;
                        ["pst", "rfl"] call gge_swap_fnc_updateAnim;
                        gge_swap_var_p2r_anim_used call gsas_fnc_playStagedAnimation;
                        gge_swap_var_swapping = true;
                    };
                    */
                    // U2R
                    /*
                    default {
                        // Never reached??
                        hint "DEFAULT CASE REACHED!?";
                        [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
                        call gge_swap_fnc_retrieveWeaponFromChest;
                        //["non", "rfl"] call gge_swap_fnc_updateAnim;
                        gge_swap_var_u2r_anim call gsas_fnc_playStagedAnimation;
                        gge_swap_var_swapping = true;                
                    };
                    */
                };                
            };
            case handgunWeapon player: {
                switch (gge_swap_var_lastFrameWep) do {
                    //R2P
                    case primaryWeapon player: {
                        // HACK: Need this to interrupt reloads, not sure why not needed for P2R but oh well :/
                        if (gge_core_var_isReloading) then {
                            [player, "gge_core_anim_clearAction"] remoteExec ["playActionNow", 0];
                        };
                        [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
                        ["rfl", "pst"] call gge_swap_fnc_updateAnim;
                        gge_swap_var_r2p_anim_used call gsas_fnc_playStagedAnimation;
                        gge_swap_var_swapping = true;
                    };
                };        
            };
            case secondaryWeapon player: {
                switch (gge_swap_var_lastFrameWep) do {
                    //R2L
                    case primaryWeapon player: {
                        [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
                        ["rfl", "lnr"] call gge_swap_fnc_updateAnim;
                        ["ras", "low"] call gge_swap_fnc_updateAnim;
                        gge_swap_var_r2l_anim call gsas_fnc_playStagedAnimation;
                        gge_swap_var_swapping = true;
                    };
                };
            };
            case binocular player: {
                switch (gge_swap_var_lastFrameWep) do {
                    //R2B
                    case primaryWeapon player: {
                        //[currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
                        //["rfl", "bin"] call gge_swap_fnc_updateAnim;
                        gge_swap_var_r2b_anim call gsas_fnc_playStagedAnimation;
                        gge_swap_var_swapping = true;
                    };
                };
            };
        };
        
        if ((gge_swap_var_lastFrameWep != "") && (gge_swap_var_lastFrameWep == primaryWeapon player) && (currentWeapon player == "")) then {
            [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
            gge_swap_var_r2u_anim call gsas_fnc_playStagedAnimation;
            gge_swap_var_swapping = true;
        };
        
        if ((gge_swap_var_lastFrameWep == "") && (currentWeapon player == primaryWeapon player) && (currentWeapon player != "")) then {
            [currentWeapon player] call gge_swap_fnc_instantSwapWeapon;
            call gge_swap_fnc_retrieveWeaponFromChest;
            //["non", "rfl"] call gge_swap_fnc_updateAnim;
            gge_swap_var_u2r_anim call gsas_fnc_playStagedAnimation;
            gge_swap_var_swapping = true;    
        };
        
        
        
        
        gge_swap_var_lastFrameWep = currentWeapon player;
    };
    
    
    if ((primaryWeapon player == "") && !((weaponsItemsCargo gge_swap_var_chestWeaponHolder) isEqualTo [])) then {
        player addWeapon "Rifle";
    };
    
};

// Return method
addMissionEventHandler ["Draw3D", {call gge_swap_fnc_handleSwap;}];