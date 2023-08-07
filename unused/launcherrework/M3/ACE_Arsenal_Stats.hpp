class statBase;

class ffv751 : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'Tandem HEAT Round penetrating around 600 mm RHA'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv751_heat' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv751_heat')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv756 : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'Multi Target Round capable of penetrating light armor and delivering a HE Warhead through walls'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv756_mt' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv756_mt')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv655 : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'Tandem HEAT Round penetrating around 500 mm RHA for Closed Spaces aka nearly no Backblast'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv655_heat_cs' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv655_heat_cs')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv551c : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'HEAT round with enhanced post penetration effect penetrating around 400 mm RHA'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv551c_heat' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv551c_heat')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv551 : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'HEAT round penetrating around 350 mm RHA'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv551_heat' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv551_heat')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv545c : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'Illumination Round to light up a whole town'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv545c_illum' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv545c_illum')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv509 : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'Anti Structure Munition able to deliver a HE Warhead through walls'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv509_asm' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv509_asm')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv502 : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'HEDP Round able to handle Infantry and light armor alike'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv502_hedp' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv502_hedp')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv469c : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'IR Smoke Round to break LOS, Smoke is not safe to inhale'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv469c_smoke' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv469c_smoke')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv441d : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'HE round with set-able Airburst'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv441d_he' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv441d_he')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class ffv401 : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'Area Defense Munition sending out around 1100 submunitions, able to penetrate up tp lightly armored vehicles'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_maaws_ffv401_adm' || ((configName (_this select 1)) == 'tf47_mag_raws_ffv401_adm')"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class gmm_hedp : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'Laser Guided Missile for the M3E1 with a HEDP Warhead'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_raws_gmm_hedp'"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};

class gmm_at : statBase {
    scope = 2; // Only scope 2 show up in arsenal, scope 1 is used for base classes.
    displayName = "Ammo Description"; // Title of the stat.
    priority = 10; // A higher value means the stat will be displayed higher on the page.
    showText = 1; // 0 disabled; 1 enabled;
    textStatement = "'Laser Guided Missile for the M3E1 with an Tandem HEAT Warhead penetrating around 600 mm RHA'"; // statement evaluated to set the text entry, can return anything.
    condition = "(configName (_this select 1)) == 'tf47_mag_raws_gmm_at'"; // Condition for the stats to be displayed, default is true if not defined, needs to return a BOOL.
    tabs[] = {{}, {4}};
};