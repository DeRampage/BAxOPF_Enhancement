// /*LEGACY
// */

// #include "TF47_AUR_MACROS.h"
// params ["_player","_rappelPoint","_rappelDirection","_ropeLength"];
// //hint format ["Player: %1 \nPre_rappel_position: %2, \nRappelPoint: %3 \n RappelDirection: %4,\n RopeLength: %5.", str _player,str  _playerPreRappelPosition,str _rappelPoint, str _rappelDirection,str  _ropeLength];
// // _player setVariable ["AUR_Is_Rappelling",true,true];

// _playerStartPosition = getPosASL _player;
// _dummyAnchor = "";


// // Create anchor for rope (at rappel point)
// _anchor = createVehicle ["B_static_AA_F", _player, [], 0, "CAN_COLLIDE"];
// AUR_SET_MASTER(_player, _anchor)
// AUR_SET_RAPPEL_DEVICE( _player, _anchor2,)

// // hideObject _anchor;
// // _anchor enableSimulation false;
// // _anchor allowDamage false;
// // [[_anchor],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
// // _anchor setVariable ["TF47_AUR_isAnchor", True, true];
// // Create anchor for rope (at rappel point)
// _anchor2 = createVehicle ["Land_Can_V2_F", _player, [], 0, "CAN_COLLIDE"];
// AUR_SET_MASTER( _player, _anchor2,)
// AUR_SET_ENDPOINT_TOP(_player, _anchor2,)
// hideObject _anchor2;
// _anchor2 enableSimulation false;
// _anchor2 allowDamage false;
// [[_anchor2],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
// // Create anchor for rope (at rappel point)
// _anchor3 = createVehicle ["Land_Can_V2_F", _player, [], 0, "CAN_COLLIDE"];
// AUR_SET_MASTER(_player, _anchor3)
// AUR_SET_RAPPEL_DEVICE2(_player, _anchor3)

// hideObject _anchor3;
// _anchor3 enableSimulation false;
// _anchor3 allowDamage false;
// [[_anchor3],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
// hint typeName _rappelPoint;
// _ropeAnchor = "";

// if (typeName _rappelPoint == "OBJECT") then  {
        // hint "creating dummy rope";
        // _dummyAnchor = createVehicle ["B_static_AA_F", _rappelPoint, [], 0, "CAN_COLLIDE"];
    // AUR_SET_RAPPEL_DEVICE2(_player, _dummyAnchor)
        // // hideObject _dummyAnchor;
        // _rappelPoint = getPosASL _anchor;
        // _ropeAnchor = ropeCreate[_dummyAnchor, [0,0,-1],_anchor2, [0,0,0]];
        // _ropeAnchor allowDamage false;
        // systemChat str _ropeAnchor;
        // // [[_dummyAnchor],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
        
        // _dummyAnchor addAction ["This is the dummy Anchor", {}];
// };

// _anchorRopeLength = ropeLength _ropeAnchor;
// systemChat str _anchorRopeLength;
// // // Create rappel device (attached to player)
// // _rappelDevice = createVehicle ["B_static_AA_F", _player, [], 0, "CAN_COLLIDE"];
// // hideObject _rappelDevice;
// // _rappelDevice setPosWorld _playerStartPosition;
// // _rappelDevice allowDamage false;
// // [[_rappelDevice],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;

// // [[_player,_rappelDevice,_anchor],"TF47_fnc_AUR_Play_Rappelling_Sounds_Global"] call TF47_fnc_AUR_RemoteExecServer;

// _bottomRopeStartLength = _ropeLength - 1;
// _topRopeStartLength = _ropeLength - _anchorRopeLength;
// systemChat str _topRopeStartLength;
// // if(_playerStartingOnGround) then {
        // // _topRopeStartLength = abs ((_rappelPoint select 2) - (getPosASL _player select 2) - 3);
        // // _bottomRopeStartLength = (_ropeLength - _topRopeStartLength) max 2;
// // };

// // _ropeBottom = ropeCreate [_rappelDevice, [-0.15,0,0], _bottomRopeStartLength];
// // _ropeBottom allowDamage false;

// _weight = createVehicle ["Land_Can_V2_F", _player, [], 0, "CAN_COLLIDE"];
// // hideObject _weight;
// // [[_weight],"TF47_fnc_AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
// _ropeTop = ropeCreate [_anchor, [0, 0, 0], _anchor2, [0,0,0], _topRopeStartLength ];
// _anchor setVelocity ((vectorDir player) vectorMultiply -2);
// systemChat str (player distance _anchor);
// _ropeTop allowDamage false;
// _anchor setPosWorld _rappelPoint;
// systemChat str ropeLength _ropeTop;
// systemChat str _ropeTop;
// AUR_SET_ROPE_LENGTH(_player, _ropeLength);

// _ropeTop setVariable ["TF47_AUR_isRappelRope", true, true];
// _ropeTop setVariable ["TF47_AUR_RopeAnchor", _anchor, true];
// _ropeTop setVariable ["TF47_AUR_RopeAnchor2", _anchor2, true];
// _ropeTop setVariable ["TF47_AUR_RopeAnchor3", _anchor3, true];