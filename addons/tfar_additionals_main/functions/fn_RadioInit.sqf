if ((!isNull KIF_Radio_Logic) && (hasInterface))then
 {
    private _str = KIF_Radio_Logic getVariable ["CustomAddActionText", ""];
    if (_str == "") then {_str ="<t color='#FFA500'>"+ ( localize "STR_KIF_RADIO_MODUL_STD_TEXT")+"</t>"; }; 
    
    if (KIF_Radio_Logic getvariable ["OnlySelected", false]) then 
     {
     _Radio_BP_Array = KIF_Radio_Logic getvariable ["Radio_BP_Array",[""]];
      {if ((count (_x call TFAR_fnc_backpackLR)>0) && (_x!=player) && ((backpack _x) in _Radio_BP_Array) ) then {[_str,_x] call KIF_fnc_AddAction2Unit;};} forEach allUnits;
     }
     else
     {
      {if ((count (_x call TFAR_fnc_backpackLR)>0) && (_x!=player) ) then {[_str,_x] call KIF_fnc_AddAction2Unit;};} forEach allUnits;
     };
    
    player addEventHandler ["InventoryClosed", { params ["_unit", "_container"];
    [_unit] spawn 
        {
        params["_unit"]; 
        sleep 1;
        _Radio_BP_Array = KIF_Radio_Logic getvariable ["Radio_BP_Array",[""]];
        if ((count (_unit call TFAR_fnc_backpackLR)>0) and ( !(KIF_Radio_Logic getvariable ["OnlySelected", false]) or ((KIF_Radio_Logic getvariable ["OnlySelected", false]) and ((backpack _unit) in _Radio_BP_Array) ) )  ) then 
         {
         if (isNil "KIF_ActionAttached") then 
            {  KIF_ActionAttached=true;
            _str = KIF_Radio_Logic getVariable ["CustomAddActionText", ""];
            if (_str == "") then {_str ="<t color='#FFA500'>"+ ( localize "STR_KIF_RADIO_MODUL_STD_TEXT")+"</t>";};
            _ID = [_str,_unit ] remoteExec ["KIF_fnc_AddAction2Unit", [0,-2] select isDedicated, true]; 
            };
        };
       };
    }];
 };
