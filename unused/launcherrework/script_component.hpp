#define COMPONENT Launchers
#include "\z\TF47\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_DATABASE
    #define DEBUG_MODE_FULL
#endif
    #ifdef DEBUG_SETTINGS_DATABASE
    #define DEBUG_SETTINGS DEBUG_SETTINGS_DATABASE
#endif

#include "\z\TF47\addons\main\script_macros.hpp"
