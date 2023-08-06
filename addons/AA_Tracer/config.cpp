#include "script_component.hpp"

class CfgPatches
{
	class ADDON
	{
		name = COMPONENT;
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"A3_Weapons_F","A3_Weapons_F_Jets"};
		author[] = {"ANZACSAS Steven","Rampage"};
		VERSION_CONFIG;
	};
};
class CfgAmmo
{
	class BulletBase;
	class B_35mm_AA: BulletBase
	{
		brightness = 50;
		timeToLive = 200;
		tracerEndTime = 200;
	};
	class ammo_Gun35mmAABase;
	class ammo_AAA_Gun35mm_AA: ammo_Gun35mmAABase
	{
		brightness = 50;
		timeToLive = 200;
		tracerEndTime = 200;
	};
};

