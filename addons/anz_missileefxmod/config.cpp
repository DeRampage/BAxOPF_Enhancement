class CfgPatches {
    class ANZ_MissileEfxMod {
        author = "ANZACSAS Steve";
        name = "Missile Efx Mod";
        requiredAddons[] = {"A3_Data_F", "A3_Data_F_ParticleEffects", "A3_Data_F_Jets", "A3_Data_F_Sams"};
        requiredVersion = 0.1;
        units[] = {};
        weapons[] = {};
    };
};

class CfgVideoOptions {
    class Particles {
        class Low {
            text = $STR_A3_OPTIONS_LOW;
            particlesSoftLimit = 7000;
            particlesHardLimit = 9000;
            smokeGenMinDist = 50;
            smokeGenMaxDist = 200;
            smokeSizeCoef = 2;
            smokeIntervalCoef = 4;
            smokeZoomCoef = 1.42857;
            highQualityShader = 0;
            numFullSizeParticles = 20;
        };
        
        class Normal {
            text = $STR_A3_OPTIONS_STANDARD;
            particlesSoftLimit = 10000;
            particlesHardLimit = 12000;
            smokeGenMinDist = 100;
            smokeGenMaxDist = 1400;
            smokeSizeCoef = 2;
            smokeIntervalCoef = 4;
            //smokeZoomCoef = 1.42857;
                        smokeZoomCoef = 0.2;
            highQualityShader = 1;
            numFullSizeParticles = 40;
        };
        
        class High {
            text = $STR_A3_OPTIONS_HIGH;
            particlesSoftLimit = 13000;
            particlesHardLimit = 19000;
            smokeGenMinDist = 200;
            smokeGenMaxDist = 3000;
            smokeSizeCoef = 2;
            smokeIntervalCoef = 3;
            //smokeZoomCoef = 0.82857;
                        smokeZoomCoef = 0.1;
            highQualityShader = 1;
            numFullSizeParticles = 60;
        };
    };
};

class CfgCloudlets {
    class Default;
        class MLRSFired1 : Default {
        //interval = 0.089;
                interval = 0.08;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 13;
        particleFSLoop = 0;
        angleVar = 360;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 2;
                //moveVelocity[] = {"5*directionX", "5*directionY", "5*directionZ"};
                moveVelocity[] = {"15*directionX", "5*directionY", "5*directionZ"};
        rotationVelocity = 1;
        weight = 1.20;
        volume = 0.85;
        rubbing = 0.4;
        size[] = {3, 5};
        color[] = {{0.5, 0.5, 0.5, 0.22}, {0.5, 0.5, 0.5, 0.12}, {0.5, 0.5, 0.5, 0.08}, {0.5, 0.5, 0.5, 0.05}, {0.5, 0.5, 0.5, 0.01}};
        animationSpeed[] = {1000};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        animationSpeedCoef = 1;
        colorCoef[] = {1, 1, 1, 1};
        sizeCoef = 1;
        position[] = {"positionX", "positionY", "positionZ"};
        lifeTimeVar = 1;
        positionVar[] = {0.5, 0.5, 0.5};
        MoveVelocityVar[] = {3.5, 3.5, 3.5};
        rotationVelocityVar = 10;
        sizeVar = 0;
        colorVar[] = {0, 0, 0, 0.0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };

    class FX_MissileTrail_SAM_LongRange : Default {
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        interval = 0.0026;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 10;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.52;
        volume = 1;
        rubbing = 0.4;
        size[] = {3, 8};
        color[] = {{0.8, 0.8, 0.8, 0.8}, {0.9, 0.9, 0.9, 0.4}, {1, 1, 1, 0}};
        animationSpeed[] = {1};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        lifeTimeVar = 0.3;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {0.4, 0.4, 0.4};
        rotationVelocityVar = 20;
        sizeVar = 0.2;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
    
    class FX_MissileTrail_SAM : Default {
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        interval = 0.0026;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 10;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1.7;
        rubbing = 0.5;
        size[] = {2, 6};
        color[] = {{0.8, 0.8, 0.8, 0.8}, {0.9, 0.9, 0.9, 0.4}, {1, 1, 1, 0}};
        animationSpeed[] = {1};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        lifeTimeVar = 0.1;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {0.4, 0.4, 0.4};
        rotationVelocityVar = 20;
        sizeVar = 0.3;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };

       class CruiseMissile: Default
    {
        interval=0.003;
        circleRadius=0;
        circleVelocity[]={0,0,0};
        angleVar=1;
        particleFSLoop=0;
        particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth=16;
        particleFSIndex=12;
        particleFSFrameCount=8;
        animationName="";
        particleType="Billboard";
        timerPeriod=1;
        lifeTime=13;
        moveVelocity[]={0,0,0};
        rotationVelocity=1;
        weight=1;
        volume=1.2;
        rubbing=0.5;
        size[]={2,6,10.8000002};
        color[]=
        {
            {0.5,0.5,0.5,0.1},
            {0.60000002,0.60000002,0.60000002,0.059999999},
            {0.69999999,0.69999999,0.69999999,0.039999999},
            {0.80000001,0.80000001,0.80000001,0.0049999999},
            {0.89999998,0.89999998,0.89999998,0.003}
        };
        animationSpeed[]={5};
        randomDirectionPeriod=0.1;
        randomDirectionIntensity=0.1;
        onTimerScript="";
        beforeDestroyScript="";
        blockAIVisibility=0;
        lifeTimeVar=5.1999998;
        positionVar[]={0.30000001,0.30000001,0.30000001};
        MoveVelocityVar[]={1.8,1.8,1.8};
        rotationVelocityVar=20;
        sizeVar=0.15000001;
        colorVar[]={0,0,0,0};
        randomDirectionPeriodVar=0;
        randomDirectionIntensityVar=0;
    };
    class CruiseMissileMed: Default
    {
        interval=0.005;
        circleRadius=0;
        circleVelocity[]={0,0,0};
        angleVar=1;
        particleFSLoop=0;
        particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth=16;
        particleFSIndex=12;
        particleFSFrameCount=8;
        animationName="";
        particleType="Billboard";
        timerPeriod=1;
        lifeTime=8;
        moveVelocity[]={0,0,0};
        rotationVelocity=1;
        weight=1;
        volume=0.80000001;
        rubbing=0.5;
        size[]={2,4,8.8000002};
        color[]=
        {
            {0.5,0.5,0.5,0.07},
            {0.60000002,0.60000002,0.60000002,0.02},
            {0.69999999,0.69999999,0.69999999,0.0099999998},
            {0.80000001,0.80000001,0.80000001,0.0049999999},
            {0.89999998,0.89999998,0.89999998,0.003}
        };
        animationSpeed[]={5};
        randomDirectionPeriod=0.1;
        randomDirectionIntensity=0.1;
        onTimerScript="";
        beforeDestroyScript="";
        blockAIVisibility=0;
        lifeTimeVar=5.1999998;
        positionVar[]={0.30000001,0.30000001,0.30000001};
        MoveVelocityVar[]={0.40000001,0.40000001,0.40000001};
        rotationVelocityVar=20;
        sizeVar=0.15000001;
        colorVar[]={0,0,0,0};
        randomDirectionPeriodVar=0;
        randomDirectionIntensityVar=0;
    };

        class ArtilleryShell1 : Default {
        interval = 0.0030;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal_02";
        particleFSNtieth = 8;
        particleFSIndex = 0;
        particleFSFrameCount = 1;
        particleFSLoop = 0;
        angleVar = 1;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 18;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.2;
        volume = 0.75;
        rubbing = 0.2;
        //size[] = {0.6, 1.8, 2.5};
                size[] = {0.6, 1.0, 1.5};
        //sizeCoef = 1;
                sizeCoef = 0.75;
        //color[] = {{0.5, 0.5, 0.5, 0.14}, {0.6, 0.6, 0.6, 0.06}, {0.7, 0.7, 0.7, 0.02}, {0.8, 0.8, 0.8, 0.006}, {0.9, 0.9, 0.9, 0.001}};
                 color[] = {{0.8, 0.8, 0.8, 0.8}, {0.9, 0.9, 0.9, 0.4}, {1, 1, 1, 0}};
        colorCoef[] = {1, 1, 1, 1};
        animationSpeed[] = {5};
        animationSpeedCoef = 1;
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        blockAIVisibility = 0;
        lifeTimeVar = 0.2;
        positionVar[] = {0.08, 0.08, 0.08};
        MoveVelocityVar[] = {0.3, 0.3, 0.3};
        rotationVelocityVar = 20;
        //sizeVar = 0.15;
                sizeVar = 0.11;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };

    class Missile0 : Default {
        interval = 0.002;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 2.8;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1;
        volume = 0.8;
        rubbing = 0.5;
        size[] = {1, 2.8, 4};
        sizeCoef = 1;
        color[] = {{0.7, 0.7, 0.7, 0.18}, {0.75, 0.75, 0.75, 0.06}, {0.8, 0.8, 0.8, 0}};
        colorCoef[] = {1.2, 1.2, 1.2, 1.2};
        animationSpeed[] = {1};
        animationSpeedCoef = 1;
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        blockAIVisibility = 0;
        lifeTimeVar = 0.8;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {1, 1, 1};
        rotationVelocityVar = 20;
        sizeVar = 0.4;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };

    class MissileManualEffects1 : Default {
        interval = 0.0015;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 6;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1;
        rubbing = 0.9;
        size[] = {1, 2.5, 2.5};
        sizeCoef = 1;
        color[] = {{0.5, 0.5, 0.5, 0.07}, {0.6, 0.6, 0.6, 0.02}, {0.7, 0.7, 0.7, 0.01}, {0.8, 0.8, 0.8, 0.005}, {0.9, 0.9, 0.9, 0.003}};
        colorCoef[] = {1, 1, 1, 1};
        animationSpeed[] = {1};
        animationSpeedCoef = 1;
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        blockAIVisibility = 0;
        lifeTimeVar = 1;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {1, 1, 1};
        rotationVelocityVar = 20;
        sizeVar = 0.3;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };

    class Missile1 : Default {
        interval = 0.0027;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 8;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1;
        rubbing = 0.9;
        size[] = {2, 2};
        sizeCoef = 1;
        color[] = {{0.3, 0.3, 0.3, 0.18}, {0.4, 0.4, 0.4, 0.06}, {0.8, 0.8, 0.8, 0}};
        colorCoef[] = {1, 1, 1, 1};
        animationSpeed[] = {1};
        animationSpeedCoef = 1;
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        blockAIVisibility = 0;
        lifeTimeVar = 0.3;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {1, 1, 1};
        rotationVelocityVar = 20;
        sizeVar = 0.3;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
    
    class Missile2 : Default {
        interval = 0.0027;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 8;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1;
        rubbing = 0.5;
        size[] = {2.0, 2.0};
        color[] = {{0.5, 0.5, 0.5, 0.07}, {0.6, 0.6, 0.6, 0.02}, {0.7, 0.7, 0.7, 0.01}, {0.8, 0.8, 0.8, 0.005}, {0.9, 0.9, 0.9, 0.003}};
        animationSpeed[] = {5};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        lifeTimeVar = 0.25;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {0.4, 0.4, 0.4};
        rotationVelocityVar = 20;
        sizeVar = 0.3;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
    
    class Missile2Med : Default {
        interval = 0.0027;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 8;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1;
        rubbing = 1;
        size[] = {2.0, 2.0};
        color[] = {{0.5, 0.5, 0.5, 0.07}, {0.6, 0.6, 0.6, 0.02}, {0.7, 0.7, 0.7, 0.01}, {0.8, 0.8, 0.8, 0.005}, {0.9, 0.9, 0.9, 0.003}};
        animationSpeed[] = {5};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        lifeTimeVar = 0.5;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {0.4, 0.4, 0.4};
        rotationVelocityVar = 20;
        sizeVar = 0.2;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
    
    class Missile3 : Default {
        interval = 0.0027;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 8;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1;
        rubbing = 1;
        size[] = {2.2, 2.2};
        //color[] = {{0.5, 0.5, 0.5, 0.07}, {0.6, 0.6, 0.6, 0.02}, {0.7, 0.7, 0.7, 0.01}, {0.8, 0.8, 0.8, 0.005}, {0.9, 0.9, 0.9, 0.003}};
                color[] = {{0.8, 0.8, 0.8, 0.8}, {0.9, 0.9, 0.9, 0.4}, {1, 1, 1, 0}};
        animationSpeed[] = {5};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        lifeTimeVar = 0.3;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {0.4, 0.4, 0.4};
        rotationVelocityVar = 20;
        sizeVar = 0.3;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
    
    class Missile3Med : Default {
        interval = 0.0027;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 8;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1;
        rubbing = 1;
        size[] = {1.7, 1.7};
        color[] = {{0.5, 0.5, 0.5, 0.07}, {0.6, 0.6, 0.6, 0.02}, {0.7, 0.7, 0.7, 0.01}, {0.8, 0.8, 0.8, 0.005}, {0.9, 0.9, 0.9, 0.003}};
        animationSpeed[] = {5};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        lifeTimeVar = 0.5;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {0.4, 0.4, 0.4};
        rotationVelocityVar = 20;
        sizeVar = 0.2;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
    
    class Missile4 : Default {
        interval = 0.0025;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 8;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1;
        rubbing = 1;
        size[] = {2.7, 3};
        color[] = {{0.8, 0.8, 0.8, 0.05}, {1, 1, 1, 0}};
        animationSpeed[] = {1};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        lifeTimeVar = 0.1;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {0.4, 0.4, 0.4};
        rotationVelocityVar = 20;
        sizeVar = 0.2;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
    
    class Missile5 : Default {
        interval = 0.0027;
        circleRadius = 0;
        circleVelocity[] = {0, 0, 0};
        angleVar = 1;
        particleFSLoop = 0;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 10;
        moveVelocity[] = {0, 0, 0};
        rotationVelocity = 1;
        weight = 1.24;
        volume = 1;
        rubbing = 1;
        size[] = {3, 7};
        color[] = {{0.8, 0.8, 0.8, 0.8}, {0.9, 0.9, 0.9, 0.4}, {1, 1, 1, 0}};
        animationSpeed[] = {1};
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        lifeTimeVar = 0.2;
        positionVar[] = {0.3, 0.3, 0.3};
        MoveVelocityVar[] = {0.4, 0.4, 0.4};
        rotationVelocityVar = 20;
        sizeVar = 0.2;
        colorVar[] = {0, 0, 0, 0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
};



class MissileEffects {
    class Light1 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1;
    };
};

class Missile1 {
    class Light1 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1;
    };
    
    class MissileEffects1 {
        simulation = "particles";
        type = "Missile1";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};

class Missile2 {
    class Light1 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1;
    };
    
    class Missile2 {
        simulation = "particles";
        type = "Missile2";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 2;
    };
    
    class Missile2Med {
        simulation = "particles";
        type = "Missile2Med";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 1;
    };
};

class Missile3 {
    class Light1 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1;
    };
    
    class Missile3 {
        simulation = "particles";
        type = "Missile3";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 2;
    };
    
    class Missile3Med {
        simulation = "particles";
        type = "Missile3Med";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 1;
    };
};

class Missile4 {
    class Light1 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.01;
        interval = 1;
        lifeTime = 1;
    };
    
    class Missile4 {
        simulation = "particles";
        type = "Missile4";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};

class Missile5 {
    class Light1 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1;
    };
    
    class Missile5 {
        simulation = "particles";
        type = "Missile5";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};



class FX_Missile_AA {
    class FX_Missile_AA_light_01 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1;
    };
    
    class FX_Plane_Missile_AA_high {
        simulation = "particles";
        type = "Missile3";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 2;
    };
    
    class FX_Plane_Missile_AA_medium {
        simulation = "particles";
        type = "Missile3";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 1;
    };
    
    class FX_Plane_Missile_AA_low {
        simulation = "particles";
        type = "Missile3";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 0;
    };
};

class FX_Missile_AG {
    class FX_Missile_AG_light_01 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1;
    };
    
    class FX_Plane_Missile_AG_high {
        simulation = "particles";
        type = "Missile4";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 2;
    };
    
    class FX_Plane_Missile_AG_medium {
        simulation = "particles";
        type = "Missile4";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 1;
    };
    
    class FX_Plane_Missile_AG_low {
        simulation = "particles";
        type = "Missile4";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 0;
    };
};

class FX_Missile_SAM {
    class FX_Missile_SAM_light_01 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1.5;
    };
    
    class FX_Plane_Missile_SAM_high {
        simulation = "particles";
        type = "FX_MissileTrail_SAM";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 2;
    };
    
    class FX_Plane_Missile_SAM_medium {
        simulation = "particles";
        type = "FX_MissileTrail_SAM";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 1;
    };
    
    class FX_Plane_Missile_SAM_low {
        simulation = "particles";
        type = "FX_MissileTrail_SAM";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 0;
    };
};

class FX_Missile_SAM_LongRange {
    class FX_Missile_SAM_light_01 {
        simulation = "light";
        type = "RocketLight";
        position[] = {0, 0, 0};
        intensity = 0.015;
        interval = 1;
        lifeTime = 1.5;
    };
    
    class FX_Plane_Missile_SAM_high {
        simulation = "particles";
        type = "FX_MissileTrail_SAM_LongRange";
        position[] = {0, 0, 0};
        intensity = 2;
        interval = 0.002;
        lifeTime = 1;
        qualityLevel = 2;
    };
    
    class FX_Plane_Missile_SAM_medium {
        simulation = "particles";
        type = "FX_MissileTrail_SAM_LongRange";
        position[] = {0, 0, 0};
        intensity = 1.4;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 1;
    };
    
    class FX_Plane_Missile_SAM_low {
        simulation = "particles";
        type = "FX_MissileTrail_SAM_LongRange";
        position[] = {0, 0, 0};
        intensity = 1.3;
        interval = 1;
        lifeTime = 1;
        qualityLevel = 0;
    };
};

class RocketBackEffectsRPG7 {
    class RocketBackfire1 {
        simulation = "particles";
        type = "RocketBackfireRPGNT";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1;
    };
    
    class RocketBacksmoke2 {
        simulation = "particles";
        type = "RocketBacksmokeRPG7";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1.2;
    };
    
    class RocketFrontsmoke {
        simulation = "particles";
        type = "RocketFrontsmokeRPG7";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1;
    };
};

class RocketBackEffectsNLAW {
    class RocketBackfire1 {
        simulation = "particles";
        type = "RocketBackfireNLAW";
        enabled = "(density interpolate [0.98,0.981,-1,1])";
        lifeTime = 1.1;
    };
    
    class RocketBacksmoke1 {
        simulation = "particles";
        type = "RocketBacksmokeNLAW";
        enabled = "(density interpolate [0.98,0.981,-1,1])";
        lifeTime = 1.2;
    };
};

class RocketBackEffectsRPG {
    class RocketBackfire1 {
        simulation = "particles";
        type = "RocketBackfireRPG";
        enabled = "(density interpolate [0.98,0.981,-1,1])";
        lifeTime = 1.1;
    };
    
    class RocketBacksmoke2 {
        simulation = "particles";
        type = "RocketBacksmokeRPG";
        enabled = "(density interpolate [0.98,0.981,-1,1])";
        lifeTime = 1.1;
    };
    
    class RocketFrontsmoke {
        simulation = "particles";
        type = "RocketFrontsmokeRPG";
        enabled = "(density interpolate [0.98,0.981,-1,1])";
        lifeTime = 1.2;
    };
};

class RocketBackEffectsRPGNT {
    class RocketBackfire1 {
        simulation = "particles";
        type = "RocketBackfireRPGNT";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1.1;
    };
    
    class RocketBacksmoke2 {
        simulation = "particles";
        type = "RocketBacksmokeRPGNT";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1.1;
    };
    
    class RocketFrontsmoke {
        simulation = "particles";
        type = "RocketFrontsmokeRPGNT";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1.2;
    };
};

class RocketBackEffectsNLAWNT {
    class RocketBackfire1 {
        simulation = "particles";
        type = "RocketBackfireSmallRPGNT";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1.1;
    };
    
    class RocketBacksmoke2 {
        simulation = "particles";
        type = "RocketBacksmokeRPGNT";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1.1;
    };
    
    class RocketFrontsmoke {
        simulation = "particles";
        type = "RocketFrontsmokeRPGNT";
        intensity = 1;
        interval = 0.1;
        lifeTime = 1.2;
    };
};

class BombCrater {
    class BombSmk1 {
        simulation = "particles";
        type = "BombSmk1";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.4;
    };
    
    class BombSmk2 {
        simulation = "particles";
        type = "BombSmk2";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.7;
    };
    
    class BombSmk3 {
        simulation = "particles";
        type = "BombSmk3";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 10;
    };
};

class CannonFire {
    class LightExp {
        simulation = "light";
        type = "ExploLight";
        position[] = {0, 1.5, 0};
        intensity = 0.15;
        interval = 1;
        lifeTime = 0.25;
    };
    
    class Smoke {
        simulation = "particles";
        type = "CannonSmoke";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
        lifeTime = 4;
    };
    
    class Flash {
        simulation = "particles";
        type = "CannonFlash";
        position[] = {0, 0, 0};
        intensity = 2;
        interval = 1;
        lifeTime = 1;
    };
};

class CfgAmmo {
    class M_Titan_AA;
    class M_Titan_AA_long : M_Titan_AA {
        effectsMissile = "FX_Missile_SAM_LongRange";
    };
};

class CruiseMissileLight
    {
        diffuse[]={1,0.25,0.050000001};
        color[]={1,0.60000002,0.30000001};
        ambient[]={0,0,0};
        brightness="20 * fireIntensity";
        size=3;
        intensity=29000;
        drawLight=1;
        blinking=0;
        dayLight=1;
        useFlare=1;
        flareSize=2.5;
        flareMaxDistance=2900;
        class Attenuation
        {
            start=0;
            constant=0;
            linear=0;
            quadratic=1;
            hardLimitStart=100;
            hardLimitEnd=200;
        };
    };
