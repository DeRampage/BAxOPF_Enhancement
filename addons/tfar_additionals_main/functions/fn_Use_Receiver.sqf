params ["_target", "_caller"];

if (isWeaponDeployed _caller) exitWith {};  

    //*************** AI
    _group = createGroup [civilian, true];
    _unit1 = _group createUnit ["VirtualMan_F", [0,0], [], 0, "none"]; //_unit1 = _group createUnit ["C_man_1_1_F", [0,0], [], 0, "none"];
    _unit1 allowDamage false;
    //[_unit1] remoteExec ["hideObjectGlobal", 2];
    removeHeadgear _unit1;
    removeGoggles _unit1;
    removeAllAssignedItems _unit1;
    _unit1 addBackpack (backpack _target);
    _unit1 attachTo [player,[0,0,0],"spine3",true];
    _unit1 disableai "all";
    _unit1  setObjectScale 0.01;
    {_unit1 linkItem _x } foreach (assignedItems player);
    _unit1 addHeadgear Headgear player;
    _unit1 addGoggles Goggles player; 
    
    (unitBackpack _unit1) setVariable["radio_settings",( (unitBackpack _target) getvariable["radio_settings",nil]),true];
    
    //_radio = (_target call TFAR_fnc_lrRadiosList) select 0;
    //_settings = (_radio call TFAR_fnc_getLrSettings);
    
    //missionNamespace setVariable ["bis_fnc_moduleRemoteControl_unit", _unit1];
    
    _anchor = createVehicle ["rope_terminator", [0,0,0], [], 0, "CAN_COLLIDE"];
    _anchor allowDamage false;
    _anchor enableRopeAttach true;    
    [_anchor, false] remoteExec ["enableSimulationGlobal", 2];
    
    if ((backpack _target) in ["B_LIB_SOV_RA_Radio","B_LIB_SOV_RA_Radio_ACRE2"]) then
        {
         _anchor attachto [_target, [-0.2,0,0],"leftupleg",true];
        }
        else
        {
        if ((backpack _target) in ["fow_b_uk_p37_radio_blanco","fow_b_uk_p37_radio"]) then
          {
          _anchor attachto [_target, [0.05,0.2,.12],"pelvis",true];
          }
          else
          {
          _anchor attachto [_target, [0,-0.2,-.05],"spine3",true];
          };
        };
    _pos = position _anchor;
    
    
    if ((backpack _target) in ["ff_tornd2","ff_tornd2_2","ff_tornd2_3","B_LIB_GER_Radio","B_LIB_SOV_RA_Radio","B_LIB_US_Radio","fow_b_torn_radio","fow_b_us_radio",
    "fow_b_us_radio_scr","fow_b_uk_p37_radio","fow_b_uk_p37_radio_blanco","B_LIB_GER_Radio_ACRE2","B_LIB_SOV_RA_Radio_ACRE2","B_LIB_US_Radio_ACRE2"]) then
    {
        if (currentWeapon player != "") then { kif_da = [-0.012,-0.05,-0.06];  kif_dv = [[0,1,-.2],[1,1,3]]; } else { kif_da = [-0.02,-0.07,-0.05]; kif_dv = [[0,1,-.2],[1,2,1]]; };
        //kif_hs = createvehicle["KIF_handset_retro",[0,0,0],[], 0, "CAN_COLLIDE"];
        kif_hs = createSimpleObject ["z\tfar\addons\external_intercom\data\TFAR_handset.p3d", player selectionPosition "head"]; 
    } else {
        if (currentWeapon player != "") then {kif_da = [-.01,-.053,-0.084];kif_dv = [[-1,4,0],[-3,-3,-9]];}else{kif_da = [-.011,-.06,-0.085];kif_dv = [[-2,4,0],[-6,-6,-9]];};
        //kif_hs = createvehicle["kif_h250u",[0,0,0],[], 0,"CAN_COLLIDE"];
        kif_hs = createSimpleObject ["z\tfar\addons\external_intercom\data\TFAR_handset.p3d", player selectionPosition "head"]; 
    };
    //todo vllt doch lieber an den kopp pappen?
    /*
    kif_hs enableRopeAttach true;
    sleep 0.1; 
    kif_hs attachto [player,kif_da,"LeftHandMiddle1",true]; 
    [[kif_hs,kif_dv],"setVectorDirAndUp",true,false] call BIS_fnc_MP;
    radioAnims_playerProbablyReloading=true; // tfar_animations mod compart.
    */
    kif_hs enableRopeAttach true;
    sleep 0.1;
    kif_hs attachTo [player, [-0.14,-0.02,0.02], "head", true];    
    kif_hs setVectorDirAndUp [[-2.5,0.8,0.25],[-1,-1,1]];

    missionNamespace setVariable ["bis_fnc_moduleRemoteControl_unit", _unit1];    
    
    
//    _radio = (_unit1 call TFAR_fnc_lrRadiosList) select 0;
//    if !(isnil "_radio") then { [_radio select 0, _radio select 1, _settings] call TFAR_fnc_setLrSettings; };
    // ********************

    //player playactionnow "take_receiver_anim";
    //_myRope = ropeCreate [kif_hs,"rope",_anchor, "rope", 1.2];
    _myRope = ropeCreate [kif_hs, "plug", _anchor, "rope", 50, ["", [0,0,-1]], ["", [0,0,-1]], "TFAR_RopeSmallWire"];

    _myRope allowDamage false;

        sleep 0.1;

    // положить трубку
    stop_calling=false;

    _idt = _caller addAction ["<t color='#FFA500'>"+ ( localize "STR_KIF_RADIO_MODUL_PUT_RD")+"</t>",{stop_calling=true;}];

    [_target,_caller,_idt,_unit1] spawn
    { params ["_target","_caller","_idt","_unit1"];
    _currentMagazineDetail = currentMagazineDetail player;
    waitUntil { (!alive _target) or ((_target distance _caller)>2) or (_currentMagazineDetail != currentMagazineDetail player)or(stop_calling)or((lifeState _target) isEqualTo "INCAPACITATED")or((lifeState _caller) isEqualTo "INCAPACITATED")or(!alive player)};
    
    if (isMultiplayer) then {"task_force_radio_pipe" callExtension (format ["RELEASE_ALL_TANGENTS    %1", name player]);    };
    sleep 0.1;

    (unitBackpack _target) setVariable["radio_settings",( (unitBackpack _unit1) getvariable["radio_settings",nil]),true];
    //_radio = call TFAR_fnc_activeLRRadio;
    //if !(isnil "_radio") then {_settings =  (_radio call TFAR_fnc_getLrSettings);} else { };


    missionNamespace setVariable ["bis_fnc_moduleRemoteControl_unit", nil];
    TFAR_currentUnit = player;

//    _radio = (_target call TFAR_fnc_lrRadiosList) select 0;
//    if !(isnil "_radio") then {[_radio select 0, _radio select 1, _settings] call TFAR_fnc_setLrSettings;};


    sleep 0.1;
    
        
    // ********** анимация *****************************
        player playActionNow "phone_anim_stop"; 
        deletevehicle ((ropeAttachedObjects kif_hs) select 0); deletevehicle ((ropes kif_hs) select 0); deletevehicle kif_hs;
        _caller removeAction _idt;
        radioAnims_playerProbablyReloading=nil; // tfar_animations mod compart.
    sleep 0.2;    
    deleteVehicle _unit1;    
    };