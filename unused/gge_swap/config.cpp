#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Functions_F","A3_Anims_F","cba_main"};
        author = "Goobin, edit by Rampage";
        VERSION_CONFIG;
    };
};
class CfgFunctions{

    class TF47
    {
        class COMPONENT
        {
            file = "z\TF47\addons\gge_swap\functions";
            class gge_swap_init {};
        };
    };
};
class CfgMovesBasic {
    class default;
    class DefaultDie;
    class ManActions{

        gge_swap_anim_R2P1[]= {
            "gge_swap_anim_R2P1",
            "gesture"            
        };        
        gge_swap_anim_R2P2[]= {
            "gge_swap_anim_R2P2",
            "gesture"            
        };
        gge_swap_anim_P2R1[]= {
            "gge_swap_anim_P2R1",
            "gesture"            
        };
        gge_swap_anim_P2R2[]= {
            "gge_swap_anim_P2R2",
            "gesture"            
        };
        gge_swap_anim_R2P1_side[]= {
            "gge_swap_anim_R2P1_side",
            "gesture"            
        };        
        gge_swap_anim_R2P2_side[]= {
            "gge_swap_anim_R2P2_side",
            "gesture"            
        };
        gge_swap_anim_P2R1_side[]= {
            "gge_swap_anim_P2R1_side",
            "gesture"            
        };
        gge_swap_anim_P2R2_side[]= {
            "gge_swap_anim_P2R2_side",
            "gesture"            
        };
        gge_swap_anim_PLR[]= {
            "gge_swap_anim_PLR",
            "gesture"            
        };
        gge_swap_anim_RLR[]= {
            "gge_swap_anim_RLR",
            "gesture"            
        };
        gge_swap_anim_BD[]= {
            "gge_swap_anim_BD",
            "gesture"            
        };
        gge_swap_anim_BU[]= {
            "gge_swap_anim_BU",
            "gesture"            
        };
        gge_swap_anim_LD[]= {
            "gge_swap_anim_LD",
            "gesture"            
        };
        gge_swap_anim_LU[]= {
            "gge_swap_anim_LU",
            "gesture"            
        };

        
        
        
    };
};

class CfgGesturesMale {
    class default;
    class States {

        class gge_swap_anim_R2P1: default {
            // Was passenger_inside_5aimtopistol
            file = "\A3\cargoposes_F_heli\anim\passenger_inside_5aimtopistol.rtm";
            looped=0;
            speed=2.5;
            mask="handsWeapon";
            disableWeapons=1;
            disableWeaponsLong=1;
            weaponLowered=0;
            showWeaponAim=0;
            showHandGun=0;
            canPullTrigger=0;
            canReload=1;
            terminal=0;
            limitGunMovement=0;
            preload=1;
            headBobMode=0;
            headBobStrength=0;
            interpolateTo[]={};
            rightHandIKCurve[]={0,1,0.05,0,0.95,0,1,1};
            leftHandIKCurve[]={0,1,0.05,0,0.95,0,1,1};
        };

        class gge_swap_anim_R2P1_side: gge_swap_anim_R2P1 {file = "z\TF47\addons\gge_swap\anim\R2H1.rtm"; speed=2.25;};

        // was passenger_inside_5aimtopistol_end
        class gge_swap_anim_R2P2: gge_swap_anim_R2P1 {file = "\A3\cargoposes_F_heli\anim\passenger_inside_5aimtopistol_end.rtm";rightHandIKCurve[]={0,0,1,1};leftHandIKCurve[]={0,0,1,1};};
        
        class gge_swap_anim_R2P2_side: gge_swap_anim_R2P1_side {file = "z\TF47\addons\gge_swap\anim\R2H2.rtm";rightHandIKCurve[]={0,0,1,1};leftHandIKCurve[]={0,0,1,1};};
        
        // was passenger_inside_5aimfrompistol
        class gge_swap_anim_P2R1: gge_swap_anim_R2P1 {file = "\A3\cargoposes_F_heli\anim\passenger_inside_5aimfrompistol.rtm";};
        
        class gge_swap_anim_P2R1_side: gge_swap_anim_R2P1_side {file = "z\TF47\addons\gge_swap\anim\H2R1.rtm";};
        // was passenger_inside_5aimfrompistol_end
        class gge_swap_anim_P2R2: gge_swap_anim_R2P1 {file = "\A3\cargoposes_F_heli\anim\passenger_inside_5aimfrompistol_end.rtm";rightHandIKCurve[]={0,0,1,1};leftHandIKCurve[]={0,0,1,1};};
        
        class gge_swap_anim_P2R2_side: gge_swap_anim_R2P1 {file = "z\TF47\addons\gge_swap\anim\H2R2.rtm";rightHandIKCurve[]={0,0,1,1};leftHandIKCurve[]={0,0,1,1};speed=1.8;};
        
        // was passenger_bench_1idlepistol
        class gge_swap_anim_PLR: gge_swap_anim_R2P1 {file = "\A3\cargoposes_F_heli\anim\passenger_bench_1idlepistol.rtm"; looped=1;};
        // was passenger_bench_1idlepistol1
        class gge_swap_anim_RLR: gge_swap_anim_R2P1 {file = "\A3\cargoposes_F_heli\anim\passenger_bench_1idlepistol1.rtm"; looped=1;};
        // was passenger_inside_3AimUnarmed_FromBinoc
        class gge_swap_anim_BD: gge_swap_anim_R2P1 {file = "\A3\cargoposes_F_heli\anim\passenger_inside_3AimUnarmed_FromBinoc.rtm"; rightHandIKCurve[]={0};leftHandIKCurve[]={0};speed=1;};
        // was passenger_inside_3AimUnarmed_ToBinoc_end
        class gge_swap_anim_BU: gge_swap_anim_R2P1 {file = "\A3\cargoposes_F_heli\anim\passenger_inside_3AimUnarmed_ToBinoc_end.rtm";rightHandIKCurve[]={0};leftHandIKCurve[]={0};speed=1;};
        // was a3\anims_f\data\anim\sdr\mov\erc\stp\ras\lnr\amovpercmstpsraswlnrdnon_amovpercmstpsraswrfldnon.rtm
        class gge_swap_anim_LD: gge_swap_anim_R2P1 {file = "a3\anims_f\data\anim\sdr\mov\erc\stp\ras\lnr\amovpercmstpsraswlnrdnon_amovpercmstpsraswrfldnon.rtm";rightHandIKCurve[]={0};leftHandIKCurve[]={0};speed=1;};
        // was a3\anims_f\data\anim\sdr\mov\erc\stp\ras\rfl\amovpercmstpsraswrfldnon_amovpercmstpsraswlnrdnon_end.rtm
        class gge_swap_anim_LU: gge_swap_anim_R2P1 {file = "a3\anims_f\data\anim\sdr\mov\erc\stp\ras\rfl\amovpercmstpsraswrfldnon_amovpercmstpsraswlnrdnon_end.rtm";rightHandIKCurve[]={0};leftHandIKCurve[]={0};speed=1;};    
        
    };
    class BlendAnims
    {
        gge_swap_mask_upperNoRightArm[]=
        {
            "Weapon",
            0,
            "Pelvis",
            0,
            "Spine",
            0,
            "Spine1",
            0,
            "Spine2",
            1,
            "Spine3",
            1,
            "Camera",
            0,
            "launcher",
            0,
            "weapon",
            0,
            "launcher",
            0,
            "neck",
            1,
            "neck1",
            0,
            "head",
            0,
            "LeftShoulder",
            1,
            "LeftArm",
            1,
            "LeftArmRoll",
            1,
            "LeftForeArm",
            1,
            "LeftForeArmRoll",
            1,
            "LeftHand",
            1,
            "RightShoulder",
            0,
            "RightArm",
            0,
            "RightArmRoll",
            0,
            "RightForeArm",
            0,
            "RightForeArmRoll",
            0,
            "RightHand",
            0,
            "LeftUpLeg",
            0,
            "LeftUpLegRoll",
            0,
            "LeftLeg",
            0,
            "LeftLegRoll",
            0,
            "LeftFoot",
            0,
            "LeftToeBase",
            0,
            "RightUpLeg",
            0,
            "RightUpLegRoll",
            0,
            "RightLeg",
            0,
            "RightLegRoll",
            0,
            "RightFoot",
            0,
            "RightToeBase",
            0,
            "LeftHandIndex1",
            1,
            "LeftHandIndex2",
            1,
            "LeftHandIndex3",
            1,
            "LeftHandMiddle1",
            1,
            "LeftHandMiddle2",
            1,
            "LeftHandMiddle3",
            1,
            "LeftHandPinky1",
            1,
            "LeftHandPinky2",
            1,
            "LeftHandPinky3",
            1,
            "LeftHankka3ing",
            1,
            "LeftHankka3ing1",
            1,
            "LeftHankka3ing2",
            1,
            "LeftHankka3ing3",
            1,
            "LeftHandThumb",
            1,
            "LeftHandThumb1",
            1,
            "LeftHandThumb2",
            1,
            "LeftHandThumb3",
            1,
            "RightHandIndex1",
            0,
            "RightHandIndex2",
            0,
            "RightHandIndex3",
            0,
            "RightHandMiddle1",
            0,
            "RightHandMiddle2",
            0,
            "RightHandMiddle3",
            0,
            "RightHandPinky1",
            0,
            "RightHandPinky2",
            0,
            "RightHandPinky3",
            0,
            "RightHankka3ing",
            0,
            "RightHankka3ing1",
            0,
            "RightHankka3ing2",
            0,
            "RightHankka3ing3",
            0,
            "RightHandThumb",
            0,
            "RightHandThumb1",
            0,
            "RightHandThumb2",
            0,
            "RightHandThumb3",
            0
        };
        
        gge_swap_mask_upperArmsOnly[]=
        {
            "Weapon",
            1,
            "Pelvis",
            0,
            "Spine",
            0,
            "Spine1",
            0,
            "Spine2",
            1,
            "Spine3",
            1,
            "Camera",
            0,
            "launcher",
            0,
            "weapon",
            1,
            "launcher",
            0,
            "neck",
            1,
            "neck1",
            0,
            "head",
            0,
            "LeftShoulder",
            1,
            "LeftArm",
            1,
            "LeftArmRoll",
            1,
            "LeftForeArm",
            1,
            "LeftForeArmRoll",
            1,
            "LeftHand",
            1,
            "RightShoulder",
            1,
            "RightArm",
            1,
            "RightArmRoll",
            1,
            "RightForeArm",
            1,
            "RightForeArmRoll",
            1,
            "RightHand",
            1,
            "LeftUpLeg",
            0,
            "LeftUpLegRoll",
            0,
            "LeftLeg",
            0,
            "LeftLegRoll",
            0,
            "LeftFoot",
            0,
            "LeftToeBase",
            0,
            "RightUpLeg",
            0,
            "RightUpLegRoll",
            0,
            "RightLeg",
            0,
            "RightLegRoll",
            0,
            "RightFoot",
            0,
            "RightToeBase",
            0,
            "LeftHandIndex1",
            1,
            "LeftHandIndex2",
            1,
            "LeftHandIndex3",
            1,
            "LeftHandMiddle1",
            1,
            "LeftHandMiddle2",
            1,
            "LeftHandMiddle3",
            1,
            "LeftHandPinky1",
            1,
            "LeftHandPinky2",
            1,
            "LeftHandPinky3",
            1,
            "LeftHankka3ing",
            1,
            "LeftHankka3ing1",
            1,
            "LeftHankka3ing2",
            1,
            "LeftHankka3ing3",
            1,
            "LeftHandThumb",
            1,
            "LeftHandThumb1",
            1,
            "LeftHandThumb2",
            1,
            "LeftHandThumb3",
            1,
            "RightHandIndex1",
            1,
            "RightHandIndex2",
            1,
            "RightHandIndex3",
            1,
            "RightHandMiddle1",
            1,
            "RightHandMiddle2",
            1,
            "RightHandMiddle3",
            1,
            "RightHandPinky1",
            1,
            "RightHandPinky2",
            1,
            "RightHandPinky3",
            1,
            "RightHankka3ing",
            1,
            "RightHankka3ing1",
            1,
            "RightHankka3ing2",
            1,
            "RightHankka3ing3",
            1,
            "RightHandThumb",
            1,
            "RightHandThumb1",
            1,
            "RightHandThumb2",
            1,
            "RightHandThumb3",
            1
        };
    };
};

#include "CfgEventHandlers.hpp"