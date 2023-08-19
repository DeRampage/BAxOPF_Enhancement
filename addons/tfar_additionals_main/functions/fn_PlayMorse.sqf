params["_message","_sender"];
_all_morse_radio = entities "KIF_Radio_North";
sleep 0.5;
forceUnicode 0;
_message = (toLower _message) + endl; 


for "_i" from 0 to (count _message)-1 do
  {
  _chr = _message select [_i,1];
  
  if ((alive _sender)and(kif_transmiting)) then
   {
   [_chr,_all_morse_radio] call kif_fnc_PlayChar;
   if !(isnil "kif_morse_radio") then { _txt = ctrlText 1604; _txt = _txt + _chr;  ctrlSetText [1604, _txt];};
   };
  };

if !(isnil "kif_morse_radio") then {
  if ((kif_morse_radio animationSourcePhase "kif_radio_switch")>0) then {kif_morse_radio animateSource ["kif_radio_switch",0,1];[kif_morse_radio,"kif_radio_noise"] call kif_fnc_SwitchOnOff;};
  };
kif_transmiting = false; publicVariable 'kif_transmiting';