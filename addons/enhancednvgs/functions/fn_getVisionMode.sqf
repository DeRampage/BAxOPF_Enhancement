/*
 *    Author: PDT
 *    checks the player's vision mode
 *
 *    Arguments:
 *  None
 *
 *    Return Value:
 *    <BOOL> - true if player is using NVGs; false if not
 *
 * example:
 * call PDT_EnhancedNVG_fnc_getVisionMode;
 */

// the player's vision mode it's always 0 in Zeus
private _visionMode = currentVisionMode player;

// check if the player is in Zeus
//private _inZeus = if !(isNull findDisplay 312) then {true} else {false};

if (_visionMode != 1) exitWith { false };

true

