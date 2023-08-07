//legacy

params ["_player"];
if(vehicle _player != _player) exitWith {false;}; //u cant climb with a vehicle
if(_player getVariable ["AUR_Is_Rappelling",false]) exitWith {false};
if(_player getVariable ["AR_Is_Rappelling",false]) exitWith {false};
if !("TF47_AUR_Grappling_Hook" in (_player call ace_common_fnc_uniqueItems)) exitWith {false};  //only with Grappling Gear u can climb
if !(_player call TF47_fnc_AUR_Has_Rope_Check) exitWith {false}; //u cant climb without a rope
_rappelPoint = [_player] call TF47_fnc_AUR_Get_Anchor_Point_Player_Looking_At;
if(count _rappelPoint == 0) exitWith {false};
_angle = [_player, _rappelPoint select 0, 20] call TF47_fnc_AUR_Get_Trajectory_Angle;
if(_angle < 0) exitWith {false};
true;