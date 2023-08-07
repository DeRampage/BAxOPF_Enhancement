///// M3 MAAWS & M3E1 RAWS /////

class rhs_weap_maaws;
class launch_MRAWS_green_F;
class launch_MRAWS_olive_F;
class launch_MRAWS_sand_F;

class tf47_weap_maaws: rhs_weap_maaws
{
    displayName = "M3 MAAWS";
    
    ace_reloadlaunchers_enabled = 1;
    ace_overpressure_range = 25;
    ace_overpressure_priority = 1;
    ace_overpressure_damage = 0.6;
    ace_overpressure_angle = 45;
    
    mass = 209.439;
    
    magazines[] = { 
                    "tf47_mag_maaws_ffv401_adm",
                    "tf47_mag_maaws_ffv441d_he",
                    "tf47_mag_maaws_ffv469c_smoke",
                    "tf47_mag_maaws_ffv502_hedp",
                    "tf47_mag_maaws_ffv509_asm",
                    "tf47_mag_maaws_ffv545c_illum",
                    "tf47_mag_maaws_ffv551_heat",
                    "tf47_mag_maaws_ffv551c_heat",
                    "tf47_mag_maaws_ffv655_heat_cs",
                    "tf47_mag_maaws_ffv751_heat",
                    "tf47_mag_maaws_ffv756_mt"
                  };
    magazineWell[] = {};
};

class tf47_weap_raws_green: launch_MRAWS_green_F
{
    displayName = "M3E1 RAWS (Green)";
    baseWeapon = "tf47_weap_raws_green";
    
    ace_reloadlaunchers_enabled = 1;
    ace_overpressure_range = 25;
    ace_overpressure_priority = 1;
    ace_overpressure_damage = 0.6;
    ace_overpressure_angle = 45;
    
    mass = 154.324;
    
    magazines[] = { 
                    "tf47_mag_raws_ffv401_adm",
                    "tf47_mag_raws_ffv441d_he",
                    "tf47_mag_raws_ffv469c_smoke",
                    "tf47_mag_raws_ffv502_hedp",
                    "tf47_mag_raws_ffv509_asm",
                    "tf47_mag_raws_ffv545c_illum",
                    "tf47_mag_raws_ffv551_heat",
                    "tf47_mag_raws_ffv551c_heat",
                    "tf47_mag_raws_ffv655_heat_cs",
                    "tf47_mag_raws_ffv751_heat",
                    "tf47_mag_raws_ffv756_mt",
                    "tf47_mag_raws_gmm_hedp",
                    "tf47_mag_raws_gmm_at"
                  };
    magazineWell[] = {};
};

class tf47_weap_raws_olive: launch_MRAWS_olive_F
{
    displayName = "M3E1 RAWS (Olive)";
    baseWeapon = "tf47_weap_raws_olive";
    
    ace_reloadlaunchers_enabled = 1;
    ace_overpressure_range = 25;
    ace_overpressure_priority = 1;
    ace_overpressure_damage = 0.6;
    ace_overpressure_angle = 45;
    
    mass = 154.324;
    
    magazines[] = { 
                    "tf47_mag_raws_ffv401_adm",
                    "tf47_mag_raws_ffv441d_he",
                    "tf47_mag_raws_ffv469c_smoke",
                    "tf47_mag_raws_ffv502_hedp",
                    "tf47_mag_raws_ffv509_asm",
                    "tf47_mag_raws_ffv545c_illum",
                    "tf47_mag_raws_ffv551_heat",
                    "tf47_mag_raws_ffv551c_heat",
                    "tf47_mag_raws_ffv655_heat_cs",
                    "tf47_mag_raws_ffv751_heat",
                    "tf47_mag_raws_ffv756_mt",
                    "tf47_mag_raws_gmm_hedp",
                    "tf47_mag_raws_gmm_at"
                  };
    magazineWell[] = {};
};

class tf47_weap_raws_sand: launch_MRAWS_sand_F
{
    displayName = "M3E1 RAWS (Sand)";
    baseWeapon = "tf47_weap_raws_sand";
    
    ace_reloadlaunchers_enabled = 1;
    ace_overpressure_range = 25;
    ace_overpressure_priority = 1;
    ace_overpressure_damage = 0.6;
    ace_overpressure_angle = 45;
    
    mass = 154.324;
    
    magazines[] = { 
                    "tf47_mag_raws_ffv401_adm",
                    "tf47_mag_raws_ffv441d_he",
                    "tf47_mag_raws_ffv469c_smoke",
                    "tf47_mag_raws_ffv502_hedp",
                    "tf47_mag_raws_ffv509_asm",
                    "tf47_mag_raws_ffv545c_illum",
                    "tf47_mag_raws_ffv551_heat",
                    "tf47_mag_raws_ffv551c_heat",
                    "tf47_mag_raws_ffv655_heat_cs",
                    "tf47_mag_raws_ffv751_heat",
                    "tf47_mag_raws_ffv756_mt",
                    "tf47_mag_raws_gmm_hedp",
                    "tf47_mag_raws_gmm_at"
                  };
    magazineWell[] = {};
};
