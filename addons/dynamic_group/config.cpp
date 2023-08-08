#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Ui_F","cba_common"};
        authors[] = {"Sonic"};
        VERSION_CONFIG;
    };
};
 
class CfgMarkers
{
    class b_unknown;
    class b_plane;
    class b_att_air: b_unknown
    {
        name="$STR_A3_CfgMarkers_NATO_att_air";
        icon="\z\TF47\addons\dynamic_Group\data\b_att_air.paa";
        texture="\z\TF47\addons\dynamic_Group\data\b_att_air.paa";
    };
    class b_plane_cas: b_plane
    {
        name = "CAS";
    };
    class b_plane_cap: b_plane
    {
        name = "CAP";
    };
    class b_plane_sead: b_plane
    {
        name = "SEAD";
    };
    class b_plane_multi: b_plane
    {
        name = "Multirole";
    };
    class b_plane_cargo: b_plane
    {
        name = "Cargo";
    };
};

#include "CfgEventHandlers.hpp"
#include "cfgFunctions.hpp"
#include "cfgScriptPaths.hpp"
#include "cfgVehicles.hpp"
#include "dlg\define.hpp"
#include "dlg\ui.hpp"
#include "dlg\SetGrpGui.hpp"
