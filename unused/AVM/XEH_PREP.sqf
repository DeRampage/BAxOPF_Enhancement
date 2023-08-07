// Utility
PREP(openMedicalMenu);
PREP(isMedic);
PREP(getVersion);

// Shared Actions
PREP(getBloodPressure);
PREP(getHeartRate);
PREP(hasLowHR);
PREP(displayHR);
PREP(hasLowBP);
PREP(displayBP);
PREP(getTotalIV);

// Incapacitated
PREP(buildIncapacitatedPassengerActions);
PREP(unloadPatient);
PREP(unloadAllWithCondition);
PREP(unloadPatientForceHandler);

// Counts (Cached)
PREP(countIncapacitated);
PREP(countUnstable);
PREP(countStable);

// Stable Actions
PREP(buildStablePassengerActions);
PREP(buildStableActions);
PREP(isStable);
PREP(getOpenWounds);
PREP(needsBandage);
PREP(getNumberOfWoundsToBandage);
PREP(getStitchableWounds);
PREP(getFractures);
PREP(hasFractures);
PREP(getNumberOfFractures);
PREP(getStitchedWounds);
PREP(hasTourniquets);
PREP(getNumberOfTourniquets);

// Unstable Actions
PREP(buildUnstablePassengerActions);
PREP(buildUnstableActions);
PREP(isUnstable);
PREP(isBleeding);
PREP(isCardiacArrest);
PREP(isUnconscious);
PREP(hasLegFractures);
PREP(getNumberOfLegFractures);

// KAT Integration
PREP(kat_isUnstable);
PREP(kat_getAirwayObstruction);
PREP(kat_getAirwayOcclusion);
PREP(kat_getAirwayStatus);
PREP(kat_getHemoPneumothorax);
PREP(kat_getPneumothorax);
PREP(kat_getTensionPneumothorax);

// Caching
PREP(cachedLocalisationCall);
PREP(cachedResult);