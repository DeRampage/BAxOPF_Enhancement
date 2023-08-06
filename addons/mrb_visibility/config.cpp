#include "script_component.hpp"

class cfgPatches
{
	class ADDON
	{
		name = COMPONENT;
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"A3_Armor_F_Beta","A3_Armor_F_Beta_APC_Tracked_01","A3_Armor_F_Beta_APC_Tracked_02","A3_Armor_F_Gamma_MBT_01","A3_Armor_F_Gamma_MBT_02","A3_Armor_F_EPB_APC_Tracked_03","A3_Armor_F_EPB_MBT_03","A3_Soft_F","A3_Soft_F_Exp_Offroad_02","A3_Data_F","A3_Boat_F","A3_Air_F_Beta","A3_Air_F_Gamma_Plane_Fighter_03","A3_Air_F_EPC_Plane_CAS_01","A3_Air_F_EPC_Plane_CAS_02","A3_Air_F_Exp_Plane_Civil_01","A3_Air_F_Jets_Plane_Fighter_01","A3_Air_F_Jets_Plane_Fighter_02","A3_Air_F_Jets_Plane_Fighter_04","A3_Air_F_Jets_UAV_05","A3_Air_F","A3_Air_F_Heli","A3_Weapons_F_Jets"};
		author[] = {"burns","Rampage"};
		url = "http://www.armed-assault.de";
		VERSION_CONFIG;
	};
};
class cfgVehicles
{
	class Plane;
	class Plane_Base_F: Plane
	{
		featureType = 2;
	};
	class Helicopter;
	class Helicopter_Base_F: Helicopter
	{
		featureType = 2;
	};
	class Tank;
	class Tank_F: Tank
	{
		featureType = 2;
	};
	class Car;
	class Car_F: Car
	{
		featureType = 2;
	};
	class Ship;
	class Ship_F: Ship
	{
		featureType = 2;
	};
};
