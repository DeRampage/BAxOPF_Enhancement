params["_radio","_sound_to_attach"];

{deletevehicle _x } foreach (attachedObjects _radio); _sound = createSoundSource [_sound_to_attach, position _radio, [], 1]; _sound attachto [_radio,[0,0,0]]; [_radio,"radio_on_off"] remoteExec ["say3D",[0,-2] select isDedicated];