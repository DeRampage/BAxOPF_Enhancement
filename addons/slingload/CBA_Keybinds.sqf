[
    localize "STR_TF47_slingload_Rigging", "TF47_slingloading_releaseCargo", localize LSTRING(ReleaseCargo),{
        [vehicle player] call TF47_slingload_fnc_releaseCargo;
    }
] call CBA_fnc_addKeybind;
