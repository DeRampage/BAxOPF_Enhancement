#include "script_component.hpp"

/*
 * Author: -Sonic-
 * Update Grouptraker.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call TF47_Grp_fnc_groupTracking
 *
 * Public: No

 prefix = TF47
 component = dynamic_Group
 */
 
#define mkr_inf ["b_inf", "b_recon","b_motor_inf","b_mech_inf"]
#define mkr_support ["b_hq","b_med","b_support","b_maint","b_installation", "b_antiair", "b_air"]
#define mkr_attack ["b_armor","b_art","b_mortar","b_att_air","b_plane","b_naval","b_plane_cas","b_plane_cap", "b_plane_sead","b_plane_multi","b_plane_cargo"]

/*

inf | support | attack 
----------------------------------
            | CCT|
RONIN| CLEARSKY | RAYO
DEATHTRAP| BIGBIRD | REAPER

...
_roles = [
    "b_inf",
    "b_recon",
    "b_motor_inf",
    "b_mech_inf",
    "b_armor",
    "b_art",
    "b_mortar",
    "b_air",
    "b_att_air",
    "b_plane",
    "b_naval",
    "b_hq",
    "b_med",
    "b_support",
    "b_maint",
    "b_installation",
    "b_antiair"
];

*/

if !(isNil QGVAR(staticTracker))then{
    {deleteMarkerLocal _x;} forEach GVAR(staticTracker);
};
GVAR(staticTracker) = [];

if !(isNil QGVAR(dynTracker))then{
    {deleteMarkerLocal _x;} forEach GVAR(dynTracker);
};
GVAR(dynTracker) = [];

if ( !(GVAR(EnableMapTracker)) || (isNil "ACE_player") || !(alive ACE_player) ) exitWith{};

private _infGrps = []; //groups
private _supportGrps = [];
private _attackGrps  = [];

{
    private _grpType = _x getVariable ["BIS_dg_rol","b_unknown"];
    switch (true)do{
        case(_grpType in mkr_inf):{_infGrps pushBack _x};
        case(_grpType in mkr_support):{_supportGrps pushBack _x};
        case(_grpType in mkr_attack):{_attackGrps pushBack _x};
        Default{};
    };
}forEach (allgroups select {side _x isEqualto playerSide && (_x getVariable ["BIS_dg_reg",false]) && isPlayer leader _x});

if(GVAR(staticGroupList))then{

    private _startStaticMarker = if (GVAR(startMarkerName) in allMapMarkers) then { getMarkerPos GVAR(startMarkerName); } else {[0,-300,0]; };
    private _id = 0;
    private _idx = 0;
    {
        private _markerType = _x getVariable ["BIS_dg_rol","b_unknown"]; 

        private _mkr = [
            format ["TF47_Grp_staticTrk_inf_%1", _id ],
            (_startStaticMarker#0),
            (_startStaticMarker#1-((_idx+1)*300)),
            (_x getVariable ["BIS_dg_rol","b_unknown"]),
            (format ["Color%1", side _x]),
            (format ["%1 | %2 | Freq: %3", (groupid _x), (getText (configfile >> "CfgMarkers" >> _markerType >> "Name")), (_x getVariable ["BIS_dg_frq",""]) ])
        ] call TF47_fnc_createTrackingIconLocal;

        GVAR(staticTracker) pushBack _mkr;
        _id = _id +1;

        if(GVAR(indicateGroupsize))then{
            private _sizeGrp = count units _x;

            private _sizeMarker = switch (true) do {
                case(_sizeGrp > 5 && _sizeGrp <= 14):{"group_1"}; //squad
                case(_sizeGrp > 15 && _sizeGrp <= 45 /* lol */):{"group_2"}; //platoon
                default {"group_0"}; //fireteam
            };

            private _mkr_size = [
                format ["TF47_Grp_staticTrk_size_%1", _id ],
                (_startStaticMarker#0),
                (_startStaticMarker#1-((_idx+1)*300)),
                _sizeMarker,
                "ColorBlack",
                ""
            ] call TF47_fnc_createTrackingIconLocal;
            
            GVAR(staticTracker) pushBack _mkr_size;
            _id = _id +1;
        };
        _idx = _idx +1;
    }forEach _infGrps;

    _idx = 0;
    {
        
        private _markerType = _x getVariable ["BIS_dg_rol","b_unknown"]; 
        private _n = if(_markerType isEqualTo (mkr_support#0))then{0}else{1}; //hq above all
        private _mkr = [
            format ["TF47_Grp_staticTrk_support_%1", _id],
            (_startStaticMarker#0 + 2000),
            (_startStaticMarker#1- ( (_idx+1)*300*_n) ),
            (_x getVariable ["BIS_dg_rol","b_unknown"]),
            (format ["Color%1", side _x]),
            (format ["%1 | %2 | Freq: %3", (groupid _x), (getText (configfile >> "CfgMarkers" >> _markerType >> "Name")), (_x getVariable ["BIS_dg_frq",""]) ])
        ] call TF47_fnc_createTrackingIconLocal;
        GVAR(staticTracker) pushBack _mkr;
        _id = _id +1;
        _idx = _idx +1;
    }forEach _supportGrps;
    _idx = 0;
    
    {
        private _markerType = _x getVariable ["BIS_dg_rol","b_unknown"]; 

        private _mkr = [
            format ["TF47_Grp_staticTrk_attack_%1", _id],
            (_startStaticMarker#0 + 4000),
            (_startStaticMarker#1-((_idx+1)*300)),
            (_x getVariable ["BIS_dg_rol","b_unknown"]),
            (format ["Color%1", side _x]),
            (format ["%1 | %2 | Freq: %3", (groupid _x), (getText (configfile >> "CfgMarkers" >> _markerType >> "Name")), (_x getVariable ["BIS_dg_frq",""]) ])
        ] call TF47_fnc_createTrackingIconLocal;
        GVAR(staticTracker) pushBack _mkr;
        _id = _id +1;
        _idx = _idx +1;
    }forEach _attackGrps;

};

if(GVAR(dynamicGroupTracker))then{

    {
        private _markerType = _x getVariable ["BIS_dg_rol","b_unknown"]; 
        private _posLeader = getpos (leader _x);
        private _mkr = [
            format ["TF47_Grp_dynTrk_%1", [_posLeader#0, _posLeader#1] ],
            (_posLeader#0),
            (_posLeader#1),
            (_x getVariable ["BIS_dg_rol","b_unknown"]),
            (format ["Color%1", side _x]),
            (groupid _x)
        ] call TF47_fnc_createTrackingIconLocal;
        GVAR(dynTracker) pushBack _mkr;

        if(GVAR(indicateGroupsize))then{
            private _sizeGrp = count units _x;

            private _sizeMarker = switch (true) do {
                case(_sizeGrp > 5 && _sizeGrp <= 14):{"group_1"}; //squad
                case(_sizeGrp > 15 && _sizeGrp <= 45 /* lol */):{"group_2"}; //platoon
                default {"group_0"}; //fireteam
            };

            private _mkr_size = [
                format ["TF47_Grp_dyn_size_%1", [_posLeader#0, _posLeader#1] ],
                (_posLeader#0),
                (_posLeader#1),
                _sizeMarker,
                "ColorBlack",
                ""
            ] call TF47_fnc_createTrackingIconLocal;
            GVAR(dynTracker) pushBack _mkr_size;
        
        };
    }forEach _infGrps;

    {
        
        private _markerType = _x getVariable ["BIS_dg_rol","b_unknown"]; 
        private _posLeader = getpos (leader _x);
        private _mkr = [
            format ["TF47_Grp_dynTrk_%1", [_posLeader#0, _posLeader#1] ],
            (_posLeader#0),
            (_posLeader#1),
            (_x getVariable ["BIS_dg_rol","b_unknown"]),
            (format ["Color%1", side _x]),
            (groupid _x)
        ] call TF47_fnc_createTrackingIconLocal;
        GVAR(dynTracker) pushBack _mkr;

    }forEach _supportGrps;
    
    {
        private _markerType = _x getVariable ["BIS_dg_rol","b_unknown"]; 
        private _posLeader = getpos (leader _x);
        private _mkr = [
            format ["TF47_Grp_dynTrk_%1", [_posLeader#0, _posLeader#1] ],
            (_posLeader#0),
            (_posLeader#1),
            (_x getVariable ["BIS_dg_rol","b_unknown"]),
            (format ["Color%1", side _x]),
            (groupid _x)
        ] call TF47_fnc_createTrackingIconLocal;
        GVAR(dynTracker) pushBack _mkr;

    }forEach _attackGrps;

};
