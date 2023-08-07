/**
    Created by Vestarr

    Event handler for the Nightvision ON/OFF
    
    Parameters: Array
        0 - _isOn <BOOLEAN> - is nightvision on or off?
    Returns: None


    Example: [true] spawn TF47_fnc_handleVisionModeChange
 */


params ['_isOn'];

if (_isOn) then {
    // if Night Vision mode has just been toggled on,
    // let's first start with a fresh list of units
    [] call TF47_fnc_updateUnitList;
    BettIR_UnitList_LastUpdate = time;

    // the vision mode might have changed already, in such case let's avoid going any further because bugs ¯\_(ツ)_/¯
    if (currentVisionMode player != 1) exitWith {};

    BettIR_EachFrameHandlerId = addMissionEventHandler ['EachFrame', 
    {
        {
            // if the illuminator isn't on, let's make sure it doesn't show up
            if (!(_x getVariable ["BettIR_nvg_illuminator_on", false])) then {
                _lightObject = _x getVariable ["BettIR_nvg_illuminator_object", objNull];
                
                if (!(isNull _lightObject)) then {
                    deleteVehicle _lightObject; 
                    _x setVariable ["BettIR_nvg_illuminator_object", objNull, false];
                };
            } else {
                // get the current unit light object
                _lightObject = _x getVariable ['BettIR_nvg_illuminator_object', objNull];
                if (isObjectHidden _lightObject) then {
                    _lightObject hideObject false;
                };

                if (_lightObject != objNull) then {
                    // get the direction of the view camera
                    _dir = getCameraViewDirection _x;
                    // get the eye position of the unit (local)
                    _eyePos = _x selectionPosition ['head', 'Memory'];
                    _xDir = _dir select 0;
                    _yDir = _dir select 1;
                    _zDir = _dir select 2;
                    _pitchCoef = if (_zDir < 0) then {-1} else {1};
                    _pitch = asin _zDir; // zDir is essentially a sine of the pitch

                    // get the offset of the goggles light
                    _nvgOffset = _x getVariable ['BettIR_nvg_illuminator_offset', [0,0,0]];
                    _offsetX = _nvgOffset select 0;
                    _offsetY = _nvgOffset select 1;
                    _offsetZ = _nvgOffset select 2;

                    // after tons of trial and error, this is a relatively reliable and precise 
                    // way of calculating the coordinates from the dir vector and the offset vector
                    _offset = [_offsetX, _offsetY * cos (_pitch), _offsetZ + (_offsetY * _zDir)];

                    // add the offset vector to the eye position
                    _eyePos = _eyePos vectorAdd _offset;
                    _nvgLightPos = _x modelToWorldWorld _eyePos;

                    _lightObject setPosASL _nvgLightPos;
                    _lightObject setVectorDirAndUp [
                        _dir,
                        [_pitchCoef * _yDir, _pitchCoef * _xDir, _zDir]
                    ];
                };
            };

            // same as the above for the weapon illuminator
            if (!(_x getVariable ["BettIR_weapon_illuminator_on", false])) then {
                _lightObject = _x getVariable ["BettIR_weapon_illuminator_object", objNull];
                
                if (!(isNull _lightObject)) then {
                    deleteVehicle _lightObject; 
                    _x setVariable ["BettIR_weapon_illuminator_object", objNull, false];
                };
            } else {
                _light = _x getVariable ["BettIR_weapon_illuminator_object", objNull];
                if (isObjectHidden _light) then {
                    _light hideObject false;
                };

                if ((_light != objNull) && (primaryWeapon _x) == (currentWeapon _x)) then {
                    // get the gun position from proxy, it's still a weird position but it's better than nothing
                    _gunPos = _x selectionPosition ['proxy:\a3\characters_f\proxies\weapon.001', "Memory"];

                    // get the direction vector of the weapon
                    _dir = (_x weaponDirection (currentWeapon _x));
                    _xDir = _dir select 0;
                    _yDir = _dir select 1;
                    _zDir = _dir select 2;

                    // calculate the offset
                    _nvgOffset = _x getVariable ['BettIR_weapon_illuminator_offset', [0,0,0]];
                    _offsetX = _nvgOffset select 0;
                    _offsetY = _nvgOffset select 1;
                    _offsetZ = _nvgOffset select 2;

                    _pitch = asin _zDir;
                    _offset = [_offsetX, _offsetY * cos (_pitch), _offsetZ + (_offsetY * _zDir)];

                    // add the local offset to the local weapon position
                    _illumPos = _gunPos vectorAdd _offset;

                    // calculate the global position from local coordinates
                    _muzzlePos = _x modelToWorldWorld _illumPos;
                    _light setPosASL _muzzlePos;

                    // needed to determine the rotation for vectorUp 
                    _pitchCoef = if (_zDir < 0) then {-1} else {1};
                    // apply rotations
                    _light setVectorDirAndUp [
                        _dir,
                        [_pitchCoef * _yDir, _pitchCoef * _xDir, _zDir]
                    ];
                } else {
                    [_x] call TF47_fnc_weaponIlluminatorOff;
                };
            };
        } forEach BettIR_UnitList;

        if (time > BettIR_UnitList_LastUpdate + BettIR_UnitList_UpdateInterval) then {
            BettIR_UnitList_LastUpdate = time;
            [] spawn TF47_fnc_updateUnitList;
        };

    }];
} else {
    // if Nightvision has just been toggled off, clean up the objects and handlers
    if (BettIR_EachFrameHandlerId != -1) then {
        removeMissionEventHandler ["EachFrame", BettIR_EachFrameHandlerId];
    };

    // gives the engine a minimal delay to avoid errors
    sleep 0.01;

    {
        // check if the player has a nvg illuminator, then clean it up
        _lightObject = _x getVariable ["BettIR_nvg_illuminator_object", objNull];
        if (_lightObject != objNull) then { deleteVehicle _lightObject; };
        _x setVariable ["BettIR_nvg_illuminator_object", objNull, false];

        // check if the player has a weapon illuminator, then clean it up
        _lightObject = _x getVariable ["BettIR_weapon_illuminator_object", objNull];
        if (_lightObject != objNull) then { deleteVehicle _lightObject; };
        _x setVariable ["BettIR_weapon_illuminator_object", objNull, false];
    } forEach BettIR_UnitList;


    // clean up the other lights in the scene, including my own
    _lights = allMissionObjects "BettIR_Illuminator_NVG";
    { deleteVehicle _x } forEach _lights;

    _lights = allMissionObjects "BettIR_Illuminator_Weapon";
    { deleteVehicle _x } forEach _lights;

    // clean up the list of units again
    BettIR_UnitList = [];
};