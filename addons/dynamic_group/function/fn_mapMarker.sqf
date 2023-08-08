/*if (TF47_MapMarker) then {
    [{ 
        { 
            if ( _x select [ 0, 13 ] == "_USER_DEFINED" ) then { 

                //Delete User marker 
                private _pos     = getMarkerPos _x; 
                private _color     = getMarkerColor _x; 
                private _type     = getMarkerType _x; 
                private _text     = markerText _x;
                private _dir     = markerDir _newMarker; 
                private _Markerarray = _x splitString"/"; 
                
                //Channel: https://community.bistudio.com/wiki/Channel_IDs
                if !(((_Markerarray select 2) == "3" ) || ((_Markerarray select 2) == "4")) then{ 
                    deleteMarker _x;                
                }; 
                
            }; 
        }forEach allMapMarkers; 
    }, Interval, []] call CBA_fnc_addPerFrameHandler;
};
*/
["created", {
    params["_newMarker"];

//    if(!local _newMarker) exitWith {};
    private _name                 = format ["%1", _newMarker];
     _name                         = _name splitString "/";
     if !(tf47_dynamic_group_TF47_MapMarker) exitWith {};
    
    private _channel             = _name select (count _name -1);
    if !( _channel == "0" || { _channel == "1" } || { _channel == "2" }) exitWith {};
    private _MarkerPlayerID     = _name select 0;
     _MarkerPlayerID             = _MarkerPlayerID splitString "#";
    private _UserArrayPos        = (_MarkerPlayerID select 1);
    private _CreatorUID= (getUserInfo _UserArrayPos)select 2;
    private _PlayerWhitelisted     = _CreatorUID in tf47_dynamic_group_tf47_mapmarker_whitelist;
    private _PlayerUnit         = (getUserInfo _UserArrayPos select 10);
    private _PlayerUnitRole     = (group _PlayerUnit) getVariable ["BIS_dg_rol",false];
    
    
    if (_PlayerWhitelisted) exitWith {};
    if (_PlayerUnitRole == "b_hq") exitWith {};

    private _type = getMarkerType _newMarker;
    private _pos = getMarkerPos _newMarker;
    private _color = getMarkerColor _newMarker;
    private _text = markerText _newMarker;
    private _dir = markerDir _newMarker;
    _name set [(count _name) -1, "3"];
    _name = _name joinString "/";
    deleteMarker _newMarker;
    private _marker = createMarker [_name, _pos];
    _marker setMarkerPos _pos;
    _marker setMarkerType _type;
    _marker setMarkerColor _color;
    _marker setMarkerText _text;
    _marker setMarkerDir _dir;
    hint "Your marker has been moved to the group channel!";
}] call CBA_fnc_addMarkerEventHandler;