params ["_player",["_searchType","Fast"]];

private _uniqueItems = _player call ace_common_fnc_uniqueItems;   
private _ropeClassNames = ["AUR_rope30","AUR_rope40","AUR_rope50","AUR_rope60","AUR_rope80","AUR_rope100"];//add Ace_ropes
private _lengths = []; 
private _length = 0; 
private _availableRope = []; 

if (_searchType != "Fast") then {  //check for all ropes and setting variables
    {
    //Do u have some ropes? Pls be more performant
        if(_x in _uniqueItems) then {   
            _availableRope pushBackUnique _x; //classnames of available ropes
            _y = _x splitString "AUR_rope"; //only length of available ropes
            _length = parseNumber (_y select 0); 
        };  
    } forEach _ropeClassNames;  
    
    _player setVariable  ["TF47_AUR_Rope_length", _length]; //maximum Length
    _player setVariable  ["TF47_AUR_Rope_classname", _availableRope];  //classname of available ropes
    
    //systemChat format ["Function: Has Rope Long, Params: %1",_this];//debug
    !(_length isEqualTo 0)
} else {  //Quick check for Ropes
   ((_ropeClassNames findIf {_x in _uniqueItems}) != -1)
};