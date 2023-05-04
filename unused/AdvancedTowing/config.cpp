class CfgPatches
{
   class TF47_AdvancedTowing
   {
      units[] = {"TF47_AdvancedTowing"};
      requiredVersion = 1.0;
      requiredAddons[] = {"A3_Modules_F"};
   };
};

class CfgNetworkMessages
{
   
   class AdvancedTowingRemoteExecClient
   {
      module = "AdvancedTowing";
      parameters[] = {"ARRAY","STRING","OBJECT","BOOL"};
   };
   
   class AdvancedTowingRemoteExecServer
   {
      module = "AdvancedTowing";
      parameters[] = {"ARRAY","STRING","BOOL"};
   };
   
};

class CfgFunctions 
{
   class TF47
   {
      class AdvancedTowing
      {
         file = "z\TF47\addons\AdvancedTowing\functions";
         class advancedTowingInit{postInit=1};
      };
   };
};

#include "CfgVehicles.hpp"
