/*
 *    Author: PDT
 *    creates CBA event handler
 *
 *    Arguments:
 *  None
 *
 *    Return Value:
 *    None
 *
 */

["visionMode", {
  params ["_unit", "_visionMode"];
  [] spawn TF47_fnc_setNvgEffect;
}, true] call CBA_fnc_addPlayerEventHandler;
