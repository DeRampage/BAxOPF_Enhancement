params ["_chr", "_targets"];
_s1 = "";

switch _chr do
{
case "а" ;
case "a" : {_s1 =  "morse_a"; };
case "б" ;
case "b" : {_s1 =  "morse_b"; };
case "ц" ;
case "c" : {_s1 =  "morse_c"; };
case "д" ;
case "d" : {_s1 =  "morse_d"; };
case "е" ;
case "e" : {_s1 =  "morse_e"; };
case "ф" ;
case "f" : {_s1 =  "morse_f"; };
case "г" ;
case "g" : {_s1 =  "morse_g"; };
case "х" ;
case "h" : {_s1 =  "morse_h"; };
case "и" ;
case "i" : {_s1 =  "morse_i"; };
case "й" ;
case "j" : {_s1 =  "morse_j"; };
case "к" ;
case "k" : {_s1 =  "morse_k"; };
case "л" ;
case "l" : {_s1 =  "morse_l"; };
case "м" ;
case "m" : {_s1 =  "morse_m"; };
case "н" ;
case "n" : {_s1 =  "morse_n"; };
case "о" ;
case "o" : {_s1 =  "morse_o"; };
case "п" ;
case "p" : {_s1 =  "morse_p"; };
case "щ" ;
case "q" : {_s1 =  "morse_q"; };
case "р" ;
case "r" : {_s1 =  "morse_r"; };
case "с" ;
case "s" : {_s1 =  "morse_s"; };
case "т" ;
case "t" : {_s1 =  "morse_t"; };
case "у" ;
case "u" : {_s1 =  "morse_u"; };
case "ж" ;
case "v" : {_s1 =  "morse_v"; };
case "в" ;
case "w" : {_s1 =  "morse_w"; };
case "ь" ;
case "ъ" ;
case "x" : {_s1 =  "morse_x"; };
case "ы" ;
case "y" : {_s1 =  "morse_y"; };
case "з" ;
case "z" : {_s1 =  "morse_z"; };

case "ч" ;
case "ö" : {_s1 =  "morse_oe"; };
case "ш" : {_s1 =  "morse_ch"; };
case "э" : {_s1 =  "morse_ee"; };
case "ü" ;
case "ю" : {_s1 =  "morse_ue"; };
case "ä" ;
case "я" : {_s1 =  "morse_ae"; };

case "0" : {_s1 =  "morse_0"; };
case "1" : {_s1 =  "morse_1"; };
case "2" : {_s1 =  "morse_2"; };
case "3" : {_s1 =  "morse_3"; };
case "4" : {_s1 =  "morse_4"; };
case "5" : {_s1 =  "morse_5"; };
case "6" : {_s1 =  "morse_6"; };
case "7" : {_s1 =  "morse_7"; };
case "8" : {_s1 =  "morse_8"; };
case "9" : {_s1 =  "morse_9"; };

case "." : {_s1 =  "morse_dot"; };
case "," : {_s1 =  "morse_comma"; };
case "-" : {_s1 =  "morse_dash"; };
case "?" : {_s1 =  "morse_question"; };


case "+" : {_s1 =  "morse_plus"; };
case "!" : {_s1 =  "morse_exclamation"; };
case ":" : {_s1 =  "morse_colon"; };
case "(" : {_s1 =  "morse_ob"; };
case ")" : {_s1 =  "morse_cb"; };
case ";" : {_s1 =  "morse_semicolon"; };


case "/" : {_s1 =  "morse_slash"; };



default {_s1 =  "morse_space";};
};

{ kif_sound = _x say3d _s1; } foreach _targets;
waituntil {isNull  kif_sound};