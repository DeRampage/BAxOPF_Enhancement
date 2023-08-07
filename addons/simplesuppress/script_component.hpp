#define COMPONENT SimpleSuppress
#define COMPONENT_BEAUTIFIED SimpleSuppress
#include "\z\TF47\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#include "\z\TF47\addons\SimpleSuppress\script_macros.hpp"

#define IDC_OVERLAY 1202
#define OVERLAYS_LIST [ARR_3(QPATHTOF(data\overlay_light.paa),QPATHTOF(data\overlay_medium.paa),QPATHTOF(data\overlay_dark.paa))]

#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(Simple Suppress - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(Simple Suppress - COMPONENT)
#endif