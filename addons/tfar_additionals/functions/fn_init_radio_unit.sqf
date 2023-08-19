// init radio unit, should be executed on server only
params ["_target",["_lr_radio",""],["_texture",""]];

_group1 = createGroup [civilian, true];
_unit1 = _group1 createUnit ["VirtualMan_F", [0,0,0], [], 0, "none"]; 
//_unit1 = _group1 createUnit ["C_man_1_1_F", [0,0,0], [], 0, "none"];
_unit1 allowDamage false;


if (_lr_radio=="") then {
 _radio_side = _target getvariable["Radio_Side","WEST"];
 switch (_radio_side) do
    {
    case "EAST": { _unit1 addBackpack "tf_mr3000"; };
    case "GUER": { _unit1 addBackpack "tf_anprc155"; };
    default { _unit1 addBackpack "tf_rt1523g"; };
    };
 }
 else
 {
 _unit1 addBackpack _lr_radio;
 };

if (_texture=="") then {
_bp_texture = _target getvariable["Backpack_Texture","dpcu"];
 switch (_bp_texture) do
    {
    case "black": { _target setObjectTextureGlobal [0, "\task_force_radio_items\models\data\camo\backpack_black_co.paa"]; };
    case "green": { _target setObjectTextureGlobal [0, "\task_force_radio_items\models\data\camo\backpack_green_co.paa"]; };
    case "mcam":  { _target setObjectTextureGlobal [0, "\task_force_radio_items\models\data\camo\backpack_mcam_co.paa"]; };
    case "sage":  { _target setObjectTextureGlobal [0, "\task_force_radio_items\models\data\camo\backpack_sage_co.paa"]; };
    default {};
    };

}
else
{
_target setObjectTextureGlobal [0, _texture];
};

//[_unit1] remoteExec ["hideObjectGlobal", 2];
//_unit1 hideObjectGlobal true;

_unit1 attachTo [_target,[0,0,0.1]];
_unit1 disableai "all";
_unit1  setObjectScale 0.01; 


/*
_lr_freq = _target  getVariable ["Def_Freq",0];
if (_lr_freq >0) then {

[_unit1,_lr_freq] spawn { waitUntil {sleep 1; time > 4}; 

 _radio_list = (_this select 0) call TFAR_fnc_lrRadiosList;
 if ((count _radio_list)>0) then {[_radio_list select 0, 1, str (_this select 1)] call TFAR_fnc_SetChannelFrequency;};
 
 };};

*/
 