#include "function_macros.hpp"

/*
 * Author: M3ales
 * Ace Vehicle Medical Version
 *
 * Arguments:
 * 0: Patient <OBJECT>
 *
 * Return Value:
 * Version Number <ARRAY>
 *
 * Example:
 *     ([] call TF47_vehicle_medical_fnc_getVersion) params ["_major", "_minor", "_patch"];
 *
 * Public: Yes
 */

getArray(configFile >> "CfgPatches" >> QUOTE(COMPONENT) >> "version")