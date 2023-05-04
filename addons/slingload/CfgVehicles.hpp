class CfgVehicles {
    class Plane_Base_F {};
    class VTOL_Base_F: Plane_Base_F {
        slingLoadMaxCargoMass = 13000;
    };

    class ace_refuel_helper;
    class TF47_slingload_apexFitting: ace_refuel_helper {
        author = "Ampersand";
        displayName = CSTRING(SlingLoadApexFitting);
        _generalMacro = "TF47_slingload_apexFitting";
        icon = "\a3\ui_f\data\IGUI\Cfg\VehicleToggles\SlingLoadRopeIconOn_ca.paa";
        model = "\z\TF47\addons\slingload\data\apexFitting.p3d";
        //model = "\z\TF47\addons\slingload\data\ropeEndLoop.p3d"; //wrong path on texture ropeEndLoop_co.paa
        damageEffect = "";
        destrType = "";
        acre_hasInfantryPhone = 0;
    };
    class ACE_Explosives_Place;
    class TF47_slingload_wreckDummy: ACE_Explosives_Place {
        author = "Ampersand";
        mapSize = 1;
        _generalMacro = QGVAR(wreckDummy);
        displayName = CSTRING(WreckDummy);
        icon = "iconObject_1x1";
        model = "\z\TF47\addons\slingload\data\wreckDummy.p3d";
        cost = 0;

    };
    class Land_Screwdriver_V1_F;
    class TF47_slingload_hook: Land_Screwdriver_V1_F {
        author = "Ampersand";
        model = "\a3\data_f\Hook\Hook_F.p3d";
        displayName = CSTRING(SlingLoadHook);
        _generalMacro = "TF47_slingload_hook";
        icon = "\a3\ui_f\data\IGUI\Cfg\VehicleToggles\SlingLoadRopeIconOn_ca.paa";
        //ace_refuel_canReceive = 0;
        //ace_cargo_space = 0;
        //ace_cargo_hasCargo = 0;
        /*
        class ACE_Actions {
            class TF47_slingload_adjustRope {
                displayName = "Adjust Rope";
                condition = TF47_slingload_canAdjustRope;
                statement = "";
                icon = "\a3\ui_f\data\IGUI\Cfg\VehicleToggles\SlingLoadRopeIconOn_ca.paa";
                position = [0,0,1];
            };
        };
        */
    };
    /*
    class Rope;
    class TF47_Rope : Rope {
    model = "\z\TF47\addons\slingload\data\rope.p3d";
    segmentType = "TF47_RopeSegment";
};
    class TF47_RopeLadder : Rope {
        model = "\z\TF47\addons\slingload\data\ropeLadder.p3d";
        segmentType = "TF47_RopeLadderSegment";
    };
    class TF47_RopeLadder2 : Rope {
        model = "\z\TF47\addons\slingload\data\ropeLadder2.p3d";
        segmentType = "TF47_RopeLadderSegment2";
    };
    */
};
