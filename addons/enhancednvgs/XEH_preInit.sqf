/*
 *    Author: PDT
 *    creates CBA settings
 *
 *    Arguments:
 *  None
 *
 *    Return Value:
 *    None
 *
 */

// ACE check
[
  "TF47_EnhancedNVGs_Using_ACE",
  "CHECKBOX",
  [
    "Use ACE color preset",
    "Enable if using ACE"
  ],
  "TF47 Enhanced NVGs",
  false
] call cba_settings_fnc_init;

// NVG effect select
[
  "TF47_EnhancedNVGs_NVG_Effect",
  "LIST",
  [
    "NVG Effect",
    "
    Green Phosphor (no effect).\n
    Modern Warfare (greenish tint WP)\n
    White Phosphor (White Phosphor)
    "
  ],
  "TF47 Enhanced NVGs",
  [
    [
      "",
      "GreenPhosphor",
      "WhitePhosphor",
      "MWPhosphor",
      "AmberPhosphor"
    ],
    [
      "None",
      "Green Phosphor",
      "White Phosphor",
      "Modern Warfare",
      "Amber Filter"
    ],
    0
  ]
] call cba_settings_fnc_init;

// NVG blacklist
[
  "TF47_EnhancedNVGs_NVG_Blacklist",
  "EDITBOX",
  [
    "Blacklisted NVG classnames", "Seperrate classnames by commas \nEg. className1, className2, className3, etc"
  ],
  "TF47 Enhanced NVGs",
  ""
] call cba_settings_fnc_init;
