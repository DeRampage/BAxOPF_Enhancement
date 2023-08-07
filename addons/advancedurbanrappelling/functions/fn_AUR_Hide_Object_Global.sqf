        params ["_obj"];
        if( _obj isKindOf "Land_Can_V2_F" || _obj isKindOf "B_static_AA_F" || _obj isKindOf "B_Static_Designator_01_F") then {
                hideObjectGlobal _obj;
        };