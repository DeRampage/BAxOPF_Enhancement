if(vehicle player != player) exitWith {false;}; //u cant climb with a vehicle
if(_player getVariable ["AUR_Is_Rappelling",false]) exitWith {false};
if(_player getVariable ["AR_Is_Rappelling",false]) exitWith {false};
"AUR_AnchorKit" in (items player) 
