#define UNFLIP_CHECK_WAITTIME       4
#define UNFLIP_FORCEFACTOR_STEP     0.2
#define UNFLIP_FORCEFACTOR_MAX      5

["TF47_unflip_start", {
    params ["_vehicle", "_player"];

    diag_log text format ["[TF47_Unflipping] Player '%1', started unflipping '%2'", _player, _vehicle];

    private _unflippingUnits = _vehicle getVariable ["TF47_unflippingUnits", []];
    _unflippingUnits pushBackUnique _player;
    _vehicle setVariable ["TF47_unflippingUnits", _unflippingUnits, true];

    private _requiredUnits = _vehicle call TF47_fnc_unflipRequiredAmount;
    // Enough people, exit and unflip vehicle
    if (_requiredUnits <= count _unflippingUnits) exitWith {
        diag_log text format ["[TF47_Unflipping] Vehicle '%1', enough people to unflip (%2)", _vehicle, _requiredUnits];

        // Schedule unflip
        [
            // condition
            {
                params ["_vehicle", "_requiredUnits"];
                count (_vehicle getVariable ["TF47_unflippingUnits", []]) < _requiredUnits
            },
            // statement (failure)
            {},
            // args
            [_vehicle, _requiredUnits],
            // timeout
            TF47_unflip_time,
            // onTimeout (success)
            {
                params ["_vehicle"];
                private _unflipAttempted = _vehicle call TF47_fnc_unflipVehicle;

                // check if unflip was successful
                if (_unflipAttempted) then {
                    [{
                        params ["_vehicle"];

                        if (isNull _vehicle) exitWith {};

                        private _upsideDown = (vectorUp _vehicle vectorDotProduct surfaceNormal getPos _vehicle) < -0.80;
                        private _bank = _vehicle call BIS_fnc_getPitchBank select 1;

                        // unflip successful --> reset force factor
                        if (!_upsideDown && 55 > abs _bank) then {
                            _vehicle setVariable ["TF47_forceFactor", nil, false];
                            diag_log text format ["[TF47_Unflipping] Vehicle '%1', unflip was successful.", _vehicle];

                        // unflip unsuccessful --> increase force factor
                        } else {
                            private _forceFactor = ((_vehicle getVariable ["TF47_forceFactor", 1]) + UNFLIP_FORCEFACTOR_STEP) min UNFLIP_FORCEFACTOR_MAX;
                            _vehicle setVariable ["TF47_forceFactor", _forceFactor, false];
                            diag_log text format ["[TF47_Unflipping] Vehicle '%1', unflip was unsuccessful. Increased force factor to %2", _vehicle, _forceFactor];
                        };
                    }, [_vehicle], UNFLIP_CHECK_WAITTIME] call CBA_fnc_waitAndExecute;
                };

                _vehicle setVariable ["TF47_unflippingUnits", [], true];
            }
        ] call CBA_fnc_waitUntilAndExecute;

        // Inform clients that unflip is ready and force them into unflip action wait time
        ["TF47_unflip_ready", [_vehicle, _requiredUnits, TF47_unflip_time], _unflippingUnits] call CBA_fnc_targetEvent;
    };

    diag_log text format ["[TF47_Unflipping] Vehicle '%1', not enough people to unflip (%2)", _vehicle, _requiredUnits];
    ["TF47_unflip_start_client", _vehicle, _player] call CBA_fnc_targetEvent;

}] call CBA_fnc_addEventHandler;

["TF47_unflip_stop", {
    params ["_vehicle", "_player"];
    diag_log text format ["[TF47_Unflipping] Player '%1', stopped unflipping '%2'", _player, _vehicle];

    private _unflippingUnits = _vehicle getVariable ["TF47_unflippingUnits", []];
    _vehicle setVariable ["TF47_unflippingUnits", _unflippingUnits - [_player], true];
}] call CBA_fnc_addEventHandler;
