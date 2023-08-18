["Brush Clearing", QGVAR(brushClearing), "Clear Brush/tree", {
    private _player = ACE_player;

    // Clear brush if possible
    if (_player call FUNC(canClearBrush)) then {
        _player call FUNC(clearBrush);
    }; 
    // Or clear tree if possible
    if (_player call FUNC(canClearTree)) then {
        _player call FUNC(clearTree);
    };

    true
}, {}, [-1, [false, false, false]]] call CBA_fnc_addKeybind; // UNBOUND
