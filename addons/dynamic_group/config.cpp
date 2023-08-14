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
        name="$STR_TF47_dynamic_group_A3_CfgMarkers_NATO_att_air";
        icon="\z\TF47\addons\dynamic_Group\data\b_att_air.paa";
        texture="\z\TF47\addons\dynamic_Group\data\b_att_air.paa";
    };
    class b_sof: b_unknown
    {
        name="$STR_TF47_dynamic_group_A3_CfgMarkers_SOF";
        icon="\z\TF47\addons\dynamic_Group\data\b_sof.paa";
        texture="\z\TF47\addons\dynamic_Group\data\b_sof.paa";
    };
    class b_jfst: b_unknown
    {
        name="$STR_TF47_dynamic_group_A3_CfgMarkers_JFST";
        icon="\z\TF47\addons\dynamic_Group\data\b_jfst.paa";
        texture="\z\TF47\addons\dynamic_Group\data\b_jfst.paa";
    };
    class b_csar: b_unknown
    {
        name="$STR_TF47_dynamic_group_A3_CfgMarkers_csar";
        icon="\z\TF47\addons\dynamic_Group\data\b_csar.paa";
        texture="\z\TF47\addons\dynamic_Group\data\b_csar.paa";
    };
    class b_cargo: b_unknown
    {
        name="$STR_TF47_dynamic_group_A3_CfgMarkers_cargo";
        icon="\z\TF47\addons\dynamic_Group\data\b_cargo.paa";
        texture="\z\TF47\addons\dynamic_Group\data\b_cargo.paa";
    };
    class b_uav: b_unknown
    {
        name="$STR_TF47_dynamic_group_A3_CfgMarkers_uav";
        icon="\z\TF47\addons\dynamic_Group\data\b_uav.paa";
        texture="\z\TF47\addons\dynamic_Group\data\b_uav.paa";
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
        name = "SEAD/DEAD";
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
