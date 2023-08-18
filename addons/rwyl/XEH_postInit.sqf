#include "script_component.hpp"

["TF47_rwyl_moveSeatLocal", {
    //params ["_unit", "_vehicle", "_proxy"];
    call TF47_rwyl_fnc_moveSeatLocal;
}] call CBA_fnc_addEventHandler;

["TF47_rwyl_setEffectiveCommander", {(_this select 0) setEffectiveCommander (_this select 1)}] call CBA_fnc_addEventHandler;

if (!hasInterface) exitWith {};

#include "initVehicles.sqf"

[
    "Ride Where You Look", "TF47_rwyl_showSeats", "Show Seats (Hold)",{
        if (visibleMap) exitWith {};
        if (isNull curatorCamera) then {
            [player] call TF47_rwyl_fnc_findSeat;
        } else {
            if (count (curatorSelected # 0) == 1) then {
                private _unit = (curatorSelected # 0 # 0);
                if (_unit isKindOf "CAManBase") then {
                    [_unit] call TF47_rwyl_fnc_findSeat;
                };
            };
        };
    },{
        TF47_rwyl_pfh_running = false;
        //TF47_rwyl_vehicle = nil;
        //TF47_rwyl_proxy = nil;
    }, [29, [false, false, false]], false                  //, 0, true
] call CBA_fnc_addKeybind; // LCTRL

[
    "Ride Where You Look", "TF47_rwyl_showSeatsToggle", "Show Seats (Toggle)",{
        if (visibleMap) exitWith {};
        if TF47_rwyl_pfh_running then {
            TF47_rwyl_pfh_running = false;
        } else {
            if (isNull curatorCamera) then {
                [player] call TF47_rwyl_fnc_findSeat;
            } else {
                private _unit = (curatorSelected # 0 # 0);
                if (_unit isKindOf "CAManBase") then {
                    [_unit] call TF47_rwyl_fnc_findSeat;
                };
            };
        };
    },{}                  //, 0, true
] call CBA_fnc_addKeybind; //

[
    "Ride Where You Look", "TF47_rwyl_selectSeat", "Select Seat",{
        if (!TF47_rwyl_pfh_running) exitWith {};
        if (isNull curatorCamera) then {
            [player] call TF47_rwyl_fnc_moveSeat;
        } else {
            if (count (curatorSelected # 0) == 1) then {
                [curatorSelected # 0 # 0] call TF47_rwyl_fnc_moveSeat;
            };
        };
        TF47_rwyl_pfh_running = false;
    },{
    }, [45, [false, true, false]], false                  //, 0, true
] call CBA_fnc_addKeybind; // x

[
    "Ride Where You Look", "TF47_rwyl_holdRelease", "Show (Hold) and Select (Release)",{
        if (visibleMap) exitWith {};
        if (isNull curatorCamera) then {
            [player] call TF47_rwyl_fnc_findSeat;
        } else {
            if (count (curatorSelected # 0) == 1) then {
                private _unit = (curatorSelected # 0 # 0);
                if (_unit isKindOf "CAManBase") then {
                    [_unit] call TF47_rwyl_fnc_findSeat;
                };
            };
        };
    },{
        if (isNull curatorCamera) then {
            [player] call TF47_rwyl_fnc_moveSeat;
        } else {
            if (count (curatorSelected # 0) == 1) then {
                [curatorSelected # 0 # 0] call TF47_rwyl_fnc_moveSeat;
            };
        };
        TF47_rwyl_pfh_running = false;
    }
] call CBA_fnc_addKeybind; // x
