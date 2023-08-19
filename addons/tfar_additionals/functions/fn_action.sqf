params ["_starget", "_caller"];

_target = (attachedObjects _starget) select 0;
{ if ((typeof _x)=="VirtualMan_F") then {_target = _x}; } forEach attachedObjects _starget;
if (isWeaponDeployed player) exitWith {};  

    removeHeadgear _target;
    removeGoggles _target;
    removeAllAssignedItems _target;

    {_target linkItem _x } foreach (assignedItems player);
    _target addHeadgear Headgear player;
    _target addGoggles Goggles player; 
    
    //_radio = (_target call TFAR_fnc_lrRadiosList) select 0;
    //_settings = _radio call TFAR_fnc_getLrSettings;
    missionNamespace setVariable ["bis_fnc_moduleRemoteControl_unit", _target];
    
    _anchor = createVehicle ["rope_terminator", [0,0,0], [], 0, "CAN_COLLIDE"];
    _anchor allowDamage false;
    _anchor enableRopeAttach true;    
    [_anchor, false] remoteExec ["enableSimulationGlobal", 2];
    
    _anchor attachto [_starget, [0,0,0],"rope"];
    _pos = position _anchor;

    if (currentWeapon player != "") then {kif_da = [-.01,-.053,-0.084];kif_dv = [[-1,4,0],[-3,-3,-9]];}else{kif_da = [-.011,-.06,-0.085];kif_dv = [[-2,4,0],[-6,-6,-9]];};
    kif_hs = createvehicle["kif_h250u",[0,0,0],[], 0,"CAN_COLLIDE"];
    kif_hs enableRopeAttach true;
    sleep 0.1; 
    kif_hs attachto [player,kif_da,"LeftHandMiddle1",true]; 
    [[kif_hs,kif_dv],"setVectorDirAndUp",true,false] call BIS_fnc_MP;
    _starget animateSource ["hs_hide",1, true];
    radioAnims_playerProbablyReloading=true; // tfar_animations mod compart.
    player playactionnow "take_receiver_anim";
    _myRope = ropeCreate [kif_hs,"rope",_anchor, "rope", 1.2];
    _myRope allowDamage false;
        sleep 0.1;
    // положить трубку
    stop_calling=false;

    _idt = player addAction ["<t color='#FFA500'>"+ ( localize "STR_TF47_tfar_additionals_RADIO_MODUL_PUT_RD")+"</t>",{stop_calling=true;}];

    [_starget,_idt] spawn
    { params ["_starget","_idt"];
    _currentMagazineDetail = currentMagazineDetail player;
    waitUntil { (!alive _starget) or ((_starget distance player)>2) or (_currentMagazineDetail != currentMagazineDetail player) or (stop_calling) or ((lifeState player) isEqualTo "INCAPACITATED") or (!alive player)};
    
    if (isMultiplayer) then {"task_force_radio_pipe" callExtension (format ["RELEASE_ALL_TANGENTS    %1", name player]);    };
    sleep 0.1;
    //_radio = call TFAR_fnc_activeLRRadio;
    //_settings = _radio call TFAR_fnc_getLrSettings;
    missionNamespace setVariable ["bis_fnc_moduleRemoteControl_unit", nil];
    TFAR_currentUnit = player;
    // ********** анимация *****************************
        player playActionNow "phone_anim_stop"; 
        deletevehicle ((ropeAttachedObjects kif_hs) select 0); deletevehicle ((ropes kif_hs) select 0); deletevehicle kif_hs;
        player removeAction _idt;
        _starget animateSource ["hs_hide",0, true];
        radioAnims_playerProbablyReloading=nil; // tfar_animations mod compart.
    };