class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class TF47_Menu {
                displayName = "TF47 Menu";
                condition = QUOTE(true);
                exceptions[] = {"isNotSwimming", "isNotInside", "notOnMap", "isNotSitting"};
                statement = "[] call TF47_fnc_openGrpmgmt";
                showDisabled = 1;
                icon = QUOTE(\z\TF47\addons\main\data\tf47.paa);
                
                 class TF47_Groupmanager{
                    displayName = "Group Manager";
                    condition = "!isNil {player getVariable 'BIS_dg_ini'}";
                    statement = "[] call TF47_fnc_openGrpmgmt";
                    exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting", "isNotOnLadder", "isNotRefueling"};
                    showDisabled = 0;
                };
            };
        };
    };
};