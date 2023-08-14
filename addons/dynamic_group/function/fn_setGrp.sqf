/* 
    author: -SONIC-
    
    description:
        Apply Frequenz on Btn click.
    parameter:
        nothing
    return
        nothing
    example
        na
        
*/

disableSerialization; 

params ["_ctrl"];

private _editradifreq = (ctrlParent _ctrl) displayCtrl 1400;

private _textradifreq = ctrlText _editradifreq;

group player setVariable ["TF47_core_Marker_Sql_Freq_Intern",_textradifreq];

closeDialog 0;