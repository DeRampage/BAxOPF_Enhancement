//функция добавляет юниту взамодействие для пользоваения его рацией: ["text", unit] call KIF_fnc_AddAction2Unit;
params ["_str", "_unit"];

_menu_type = KIF_Radio_Logic getVariable ["Interaction_Menu_Type", 0];


if !(_menu_type isEqualTo 1) then { // add  action menu

_unit addAction [_str, {params ["_target", "_caller", "_actionId", "_arguments"]; [_target,_caller] call KIF_fnc_Use_Receiver;},
    nil, 1.5, true, true, "",
    "!((lifeState _originalTarget) isEqualTo 'INCAPACITATED' )and(count (_originalTarget call TFAR_fnc_backpackLR)>0)and(alive _originalTarget)and(({typeof _x == 'rope_terminator'} count (attachedObjects _target))<1)and(_originalTarget != _this)and(({_x isKindOf 'kif_handset'} count (attachedObjects player))<1)",
    2,false, "",""];
 };

if !(_menu_type isEqualTo 0) then { // add  ace interaction menu

_action = ["Radio_operator",_str,"",{params ["_target", "_player"]; [_target,_player] spawn KIF_fnc_Use_Receiver;},{params ["_target", "_player"]; !((lifeState _target) isEqualTo 'INCAPACITATED' )and(count (_target call TFAR_fnc_backpackLR)>0)and(alive _target)and(({typeof _x == 'rope_terminator'} count (attachedObjects _target))<1)and(({_x isKindOf 'kif_handset'} count (attachedObjects _player))<1)}] call ace_interact_menu_fnc_createAction; //and(_target != _player)
[_unit, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;



};