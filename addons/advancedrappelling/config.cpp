#include "script_component.hpp"
class CfgPatches 
{
   class ADDON 
   {
      name = COMPONENT;
      units[] = {};
      weapons[] = {};
      requiredVersion = REQUIRED_VERSION;
      requiredAddons[] = {"A3_Modules_F"};
      author[] = {"sethduda","Rampage"};
      VERSION_CONFIG;
   };
};

class CfgNetworkMessages
{
   class AdvancedRappellingRemoteExecClient
   {
      module = "AdvancedRappelling";
      parameters[] = {"ARRAY","STRING","OBJECT","BOOL"};
   };
   class AdvancedRappellingRemoteExecServer
   {
      module = "AdvancedRappelling";
      parameters[] = {"ARRAY","STRING","BOOL"};
   };
};

class CfgFunctions 
{
   class TF47
   {
      class AdvancedRappelling
      {
         file = "z\TF47\addons\AdvancedRappelling\functions";
         class advancedRappellingInit{postInit=1};
      };
   };
};

class CfgSounds
{
   class AR_Rappel_Loop
   {
      name = "AR_Rappel_Loop";
      sound[] = {"\z\TF47\addons\AdvancedRappelling\sounds\AR_Rappel_Loop.ogg", db+20, 1};
      titles[] = {0,""};
   };
   class AR_Rappel_Start
   {
      name = "AR_Rappel_Start";
      sound[] = {"\z\TF47\addons\sounds\AR_Rappel_Start.ogg", db+20, 1};
      titles[] = {0,""};
   };
   class AR_Rappel_End
   {
      name = "AR_Rappel_End";
      sound[] = {"\z\TF47\addons\AdvancedRappelling\sounds\AR_Rappel_End.ogg", db+20, 1};
      titles[] = {0,""};
   };
};

#include "CfgAnimations.hpp"