    params ["_msg",["_isSuccess",true]];
    if(!isNil "ExileClient_gui_notification_event_addNotification") then {
                if(_isSuccess) then {
                        ["Success", [_msg]] call ExileClient_gui_notification_event_addNotification; 
                } else {
                        ["Whoops", [_msg]] call ExileClient_gui_notification_event_addNotification; 
                };
    } else {
        hint _msg;
    };