params ["_logic"];

if (isServer) then
 {
addMissionEventHandler ["HandleDisconnect", {
    params ["_unit", "_id", "_uid", "_name"];
     {
     if (_x isKindOf 'kif_handset') then
         {
          deletevehicle ((ropeAttachedObjects _x) select 0);
          deletevehicle ((ropes _x) select 0);
          deletevehicle _x;
         };
    if (_x isKindOf 'man') then
         {    deletevehicle _x; }; 
     } foreach (attachedObjects _unit);
     
    {
    if ((_x isKindOf "tf_telephone") or (_x isKindOf "tf_field_phone")) then    {    player unlinkItem _x;};
    } count (assignedItems player);  
     
    true
    }];
 };


if (!isNull _logic) then 
    {
    KIF_Radio_Logic = _logic;
    };