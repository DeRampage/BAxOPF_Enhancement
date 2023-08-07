/**
    Created by Vestarr

    Loads the compatible items from the config
    
    Parameters: None
    Returns: Array
        0 - Array of attachment classnames
        1 - Array of offsets to corresponding classnames
 */


private '_attachmentConfigClasses';
private '_attachmentClasses';

// load compatible attachments from config
_attachmentConfigClasses = 'true' configClasses (configFile >> 'BettIR_Config' >> 'CompatibleAttachments');
_attachmentClasses = [];
_attachmentOffsets = [];

{
    _attachmentClassName = configName _x;
    if (!('__base_' in _attachmentClassName)) then {
        _attachmentClasses pushBack (toLower _attachmentClassName);

        _offset = getArray (_x >> 'offset');

        _attachmentOffsets pushBack _offset;
    };
} foreach _attachmentConfigClasses;


[_attachmentClasses, _attachmentOffsets];
