#define _ARMA_

class CfgPatches
{
    class SNC_ugl_fix
    {
        name = "ugl_fix";
        units[] = {};
        weapons[] = {};
        requiredVersion = "REQUIRED_VERSION";
        requiredAddons[] = {"A3_Weapons_F","rhsusf_c_weapons"};
        author = "TF47 -Sonic-";
        version = "2.3.0.0";
        versionStr = "2.3.0.0";
        versionAr[] = {2,3,0,0};
    };
};
class CfgAmmo
{
    class SmokeShellBlue;
    class SmokeShellGreen;
    class SmokeShellOrange;
    class SmokeShellPurple;
    class SmokeShellRed;
    class SmokeShellYellow;
    class FlareBase;
    class SmokeShell
    {
        simulation = "shotSmoke";
        deflectionSlowDown = 0.18;
    };
    class G_40mm_Smoke: SmokeShell
    {
        simulation = "shotSmoke";
        deflectionSlowDown = 0.18;
    };
    class F_40mm_White: FlareBase
    {
        intensity = 1000000;
    };
    class F_40mm_Yellow: F_40mm_White{};
    class F_40mm_Red: F_40mm_White{};
    class F_40mm_Green: F_40mm_White{};
    class rhs_40mm_smoke_green: SmokeShellGreen
    {
        simulation = "shotSmoke";
        deflecting = 10;
        deflectionSlowDown = 0.18;
    };
    class rhs_40mm_smoke_red: SmokeShellRed
    {
        simulation = "shotSmoke";
        deflecting = 10;
        deflectionSlowDown = 0.18;
    };
    class rhs_40mm_smoke_white: SmokeShell
    {
        simulation = "shotSmoke";
        deflecting = 10;
        deflectionSlowDown = 0.18;
    };
    class rhs_40mm_smoke_yellow: SmokeShellYellow
    {
        simulation = "shotSmoke";
        deflecting = 10;
        deflectionSlowDown = 0.18;
    };
};
