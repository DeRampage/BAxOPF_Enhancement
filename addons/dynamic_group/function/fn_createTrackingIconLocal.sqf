params [
    ["_mkr_id",""],
    ["_pos_X",0],
    ["_pos_Y",0],
    ["_mkr_type",""],
    ["_mkr_col",""],
    ["_mkr_text",""]
];

private _marker = createMarkerLocal [_mkr_id, [_pos_X, _pos_Y] ]; \
_marker setMarkerShapeLocal "ICON"; \
_marker setMarkerTypeLocal _mkr_type; \
_marker setMarkerColorLocal _mkr_col; \
_marker setMarkerTextLocal _mkr_text;
_marker;