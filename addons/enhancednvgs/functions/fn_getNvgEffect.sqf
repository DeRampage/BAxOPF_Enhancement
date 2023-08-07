/*
 *    Author: PDT
 *    gets the player's select NVG effect and checks if ACE is running
 *
 *    Arguments:
 *  None
 *
 *    Return Value:
 *    <ARRAY> - [<NUMBER>, <BOOL>], ["NVG Effect", true if using ACE; false is not]
 *
 * example:
 * call PDT_EnhancedNVG_fnc_getNvgEffect;
 */

private _effectSelection = TF47_EnhancedNVGs_NVG_Effect;    // selected effect
private _aceCheck        = TF47_EnhancedNVGs_Using_ACE;     // ace check
private _nvgBlacklist    = TF47_EnhancedNVGs_NVG_Blacklist; // nvg blacklist

// player is using blacklisted NVGs
if ((hmd player) in _nvgBlacklist) then {
  _effectSelection = "";
};

[_effectSelection, _aceCheck]