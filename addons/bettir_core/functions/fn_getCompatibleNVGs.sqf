/**
    Created by Vestarr

    Loads the compatible items from the config
    
    Parameters: None
    Returns: Array
        0 - Array of nvg classnames
        1 - Array of offsets to corresponding nvgs
 */


private '_nvgConfigClasses';
private '_nvgClasses';

// load compatible nvgs from config
_nvgConfigClasses = 'true' configClasses (configFile >> 'BettIR_Config' >> 'CompatibleNightvisionGoggles');
_nvgClasses = [];
_nvgOffsets = [];

{
    _nvgClassName = configName _x;
    if (!('__base_' in _nvgClassName)) then {
        _nvgClasses pushBack (toLower _nvgClassName);

        _offset = getArray (_x >> 'offset');

        _nvgOffsets pushBack _offset;
    };
} foreach _nvgConfigClasses;


[_nvgClasses, _nvgOffsets];
