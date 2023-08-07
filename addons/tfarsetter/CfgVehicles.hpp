class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class TF47_Menu {
                class ADDON {
                    condition = QUOTE(true);
                    displayName = "TFAR Setter";
                    EXCEPTIONS;
                    icon = ICON_ROOT;

                    class GVAR(saveBase) {
                        condition = QUOTE(call TFAR_fnc_haveSWRadio || call TFAR_fnc_haveLRRadio);
                        displayName = "Save";
                        EXCEPTIONS;
                        icon = ICON_SAVE;
                        insertChildren = QUOTE(_player call FUNC(interactSaveSR));

                        class GVAR(saveFromLRtoLR) {
                            condition = QUOTE(GVAR(enableLRInteractions) && {!isNil {_player call TFAR_fnc_backpackLR}});
                            displayName = "from LR to LR";
                            EXCEPTIONS;
                            icon = ICON_LR;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(false,true,false)],true)] call FUNC(profileMenusSave));
                        };

                        class GVAR(saveFromVLRtoLR) {
                            condition = QUOTE(GVAR(enableVLRInteractions) && {(objectParent _player) call TFAR_fnc_hasVehicleRadio});
                            displayName = "from VLR to LR";
                            EXCEPTIONS;
                            icon = ICON_LR;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(false,true,false)],false)] call FUNC(profileMenusSave));
                        };

                        class GVAR(saveFromLRtoVLR) {
                            condition = QUOTE(GVAR(enableLRInteractions) && {!isNil {_player call TFAR_fnc_backpackLR}});
                            displayName = "from LR to VLR";
                            EXCEPTIONS;
                            icon = ICON_VLR;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(false,false,true)],false)] call FUNC(profileMenusSave));
                        };

                        class GVAR(saveFromVLRtoVLR) {
                            condition = QUOTE(GVAR(enableVLRInteractions) && {(objectParent _player) call TFAR_fnc_hasVehicleRadio});
                            displayName = "from VLR to VLR";
                            EXCEPTIONS;
                            icon = ICON_VLR;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(false,false,true)],true)] call FUNC(profileMenusSave));
                        };

                        class GVAR(saveSRAndFromLRtoLR) {
                            condition = QUOTE(GVAR(enableSRAndLRInteractions) && {call TFAR_fnc_haveSWRadio} && {!isNil {_player call TFAR_fnc_backpackLR}});
                            displayName = "SR and from LR to LR";
                            EXCEPTIONS;
                            icon = ICON_ROOT;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(true,true,false)],true)] call FUNC(profileMenusSave));
                        };

                        class GVAR(saveAll) {
                            condition = QUOTE(GVAR(enableAllInteractions) && {call TFAR_fnc_haveSWRadio} && {!isNil {_player call TFAR_fnc_backpackLR}} && {(objectParent _player) call TFAR_fnc_hasVehicleRadio});
                            displayName = "All";
                            EXCEPTIONS;
                            icon = ICON_ROOT;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(true,true,true)],true)] call FUNC(profileMenusSave));
                        };
                    };

                    class GVAR(loadBase) {
                        condition = QUOTE(call TFAR_fnc_haveSWRadio || call TFAR_fnc_haveLRRadio);
                        displayName = "Load";
                        EXCEPTIONS;
                        icon = ICON_LOAD;
                        insertChildren = QUOTE(_player call FUNC(interactLoadSR));

                        class GVAR(loadFromLRToLR) {
                            condition = QUOTE(GVAR(enableLRInteractions) && {!isNil {_player call TFAR_fnc_backpackLR}});
                            displayName = "from LR to LR";
                            EXCEPTIONS;
                            icon = ICON_LR;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(false,true,false)],true)] call FUNC(profileMenusLoad));
                        };

                        class GVAR(loadFromVLRToLR) {
                            condition = QUOTE(GVAR(enableLRInteractions) && {!isNil {_player call TFAR_fnc_backpackLR}});
                            displayName = "from VLR to LR";
                            EXCEPTIONS;
                            icon = ICON_LR;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(false,false,true)],false)] call FUNC(profileMenusLoad));
                        };

                        class GVAR(loadFromLRToVLR) {
                            condition = QUOTE(GVAR(enableVLRInteractions) && {(objectParent _player) call TFAR_fnc_hasVehicleRadio});
                            displayName = "from LR to VLR";
                            EXCEPTIONS;
                            icon = ICON_VLR;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(false,true,false)],false)] call FUNC(profileMenusLoad));
                        };

                        class GVAR(loadFromVLRToVLR) {
                            condition = QUOTE(GVAR(enableVLRInteractions) && {(objectParent _player) call TFAR_fnc_hasVehicleRadio});
                            displayName = "from VLR to VLR";
                            EXCEPTIONS;
                            icon = ICON_VLR;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(false,false,true)],true)] call FUNC(profileMenusLoad));
                        };

                        class GVAR(loadFromSRAndFromLRToLR) {
                            condition = QUOTE(GVAR(enableSRAndLRInteractions) && {call TFAR_fnc_haveSWRadio} && {!isNil {_player call TFAR_fnc_backpackLR}});
                            displayName = "SR and from LR to LR";
                            EXCEPTIONS;
                            icon = ICON_ROOT;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(true,true,false)],true)] call FUNC(profileMenusLoad));
                        };

                        class GVAR(loadAll) {
                            condition = QUOTE(GVAR(enableAllInteractions) && {call TFAR_fnc_haveSWRadio} && {!isNil {_player call TFAR_fnc_backpackLR}} && {(objectParent _player) call TFAR_fnc_hasVehicleRadio});
                            displayName = "All";
                            EXCEPTIONS;
                            icon = ICON_ROOT;
                            insertChildren = QUOTE([ARR_3(_player,[ARR_3(true,true,true)],true)] call FUNC(profileMenusLoad));
                        };
                    };

                    class GVAR(deleteProfile) {
                         condition = QUOTE(GETPRVAR(QUOTE(QGVAR(profileNames)),[]) isNotEqualTo []);
                         displayName = "Delete Profile";
                         EXCEPTIONS;
                         icon = ICON_DELETE;
                         statement = QUOTE(call FUNC(deleteProfile));
                    };

                    class GVAR(newProfile) {
                         condition = QUOTE(true);
                         displayName = "Create/Import Profile";
                         EXCEPTIONS;
                         icon = ICON_ADD;
                         statement = QUOTE(call FUNC(createNewProfile));
                    };

                    class GVAR(exportProfile) {
                         condition = QUOTE(GETPRVAR(QUOTE(QGVAR(profileNames)),[]) isNotEqualTo []);
                         displayName = "Export Profile";
                         EXCEPTIONS;
                         icon = ICON_ADD;
                         statement = QUOTE(call FUNC(exportProfile));
                    };
                };
            };
        };
    };
};