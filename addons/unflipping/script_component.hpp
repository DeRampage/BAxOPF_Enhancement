#define COMPONENT unflipping
#include "\z\TF47\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_MAIN
    #define DEBUG_MODE_FULL
#endif
    #ifdef DEBUG_SETTINGS_MAIN
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MAIN
#endif

#include "\z\TF47\addons\main\script_macros.hpp"

#define ICON_PATH(name) \z\TF47\addons\##COMPONENT##\ui\##name##.paa
#define CONCAT(a,b) a##b
#define COMPILE_FILE(name) compileFinal preprocessFileLineNumbers '\z\TF47\addons\##COMPONENT##\##name##.sqf'
#define FUNC(name) TF47_fnc_##name
#define LSTR(module,name) CONCAT(STR_TF47_AVM_,CONCAT(module,CONCAT(_,name)))
#define LSTRING(module,name) QUOTE(LSTR(module,name))
