
#define AUR_GET_MASTER(OBJ) OBJ getVariable "TF47_AUR_MASTER_Anchor_object"
#define AUR_SET_MASTER(OBJ,MASTER) OBJ setVariable ["TF47_AUR_MASTER_Anchor_object", MASTER, True]

#define AUR_GET_ENDPOINT_LEADER(OBJ)   ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_leader_endpoint")
#define AUR_GET_RAPPEL_DEVICE(OBJ)     ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_rappel_device")
#define AUR_GET_ENDPOINT_TOP(OBJ)      ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_top_endpoint")
#define AUR_GET_RAPPEL_DEVICE2(OBJ)    ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_rappel_device2")
#define AUR_GET_ENDPOINT_BOTTOM(OBJ)   ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_bottom_endpoint")
#define AUR_GET_ROPE_TOP(OBJ)          ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_Rope_top")
#define AUR_GET_ROPE_BOTTOM(OBJ)       ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_Rope_bottom")
#define AUR_GET_ROPE_LEADER(OBJ)       ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_Rope_leader")
#define AUR_GET_ROPE_LENGTH(OBJ)       ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_Rope_length")

#define AUR_CLEAR_MASTER(OBJ) OBJ setVariable ["TF47_AUR_MASTER_Anchor_object", nil]
#define AUR_CLEAR_ENDPOINT_LEADER(OBJ)   (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_leader_endpoint", nil]
#define AUR_CLEAR_RAPPEL_DEVICE(OBJ)     (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_rappel_device", nil] 
#define AUR_CLEAR_ENDPOINT_TOP(OBJ)      (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_top_endpoint", nil] 
#define AUR_CLEAR_RAPPEL_DEVICE2(OBJ)    (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_rappel_device2", nil]
#define AUR_CLEAR_ENDPOINT_BOTTOM(OBJ)   (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_bottom_endpoint", nil]
#define AUR_CLEAR_ROPE_TOP(OBJ)          (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_Rope_top", nil]
#define AUR_CLEAR_ROPE_BOTTOM(OBJ)       (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_Rope_bottom", nil]
#define AUR_CLEAR_ROPE_LEADER(OBJ)       (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_Rope_leader", nil]
#define AUR_CLEAR_ROPE_LENGTH(OBJ)       (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_Rope_length", nil]

#define AUR_SET_ENDPOINT_LEADER(OBJ, VALUE)   ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_leader_endpoint", VALUE, True] )
#define AUR_SET_RAPPEL_DEVICE(OBJ, VALUE)     ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_rappel_device", VALUE, True]   )
#define AUR_SET_ENDPOINT_TOP(OBJ, VALUE)      ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_top_endpoint", VALUE, True]    )
#define AUR_SET_RAPPEL_DEVICE2(OBJ, VALUE)    ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_rappel_device2", VALUE, True]  )
#define AUR_SET_ENDPOINT_BOTTOM(OBJ, VALUE)   ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_bottom_endpoint", VALUE, True] )
#define AUR_SET_ROPE_TOP(OBJ, VALUE)          ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_Rope_top", VALUE, True]        )
#define AUR_SET_ROPE_BOTTOM(OBJ, VALUE)       ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_Rope_bottom", VALUE, True]     )
#define AUR_SET_ROPE_LEADER(OBJ, VALUE)       ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_Rope_leader", VALUE, True]     )
#define AUR_SET_ROPE_LENGTH(OBJ, VALUE)       ((AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_Rope_length", VALUE, True]     )






//whether a rappel system is in use (bool), set on the system master object. system is in use when someone has the rope in their hands or is rappelling.
#define AUR_SET_USE_STATUS(OBJ, status)       (AUR_GET_MASTER(OBJ)) setVariable  ["TF47_AUR_IN_USE", status, True]
#define AUR_GET_USE_STATUS(OBJ)       ((AUR_GET_MASTER(OBJ)) getVariable  ["TF47_AUR_IN_USE", False])

//Set on the player/unit holding the rope directly, NOT on the master object.
#define AUR_SET_STATUS_HOLDING_ROPE(OBJ, status)       OBJ setVariable  ["TF47_AUR_HOLDING_ROPE", status, True]
#define AUR_GET_STATUS_HOLDING_ROPE(OBJ)       (OBJ getVariable  ["TF47_AUR_HOLDING_ROPE", False])

//set directly on any rope that is part of a rappelling system (any rope that is created by this mod)
#define AUR_SET_STATUS_ROPE(OBJ, status)       OBJ setVariable  ["TF47_AUR_IS_RAPPELLING_ROPE", status, True]
#define AUR_GET_STATUS_ROPE(OBJ)       (OBJ getVariable  ["TF47_AUR_IS_RAPPELLING_ROPE", False])

//set directly on a unit while it is rappelling (bool)
#define AUR_SET_RAPPELLING_STATUS(OBJ, status)       OBJ setVariable  ["TF47_AUR_IS_RAPPELLING", status, True]
#define AUR_GET_RAPPELLING_STATUS(OBJ)       (OBJ getVariable  ["TF47_AUR_IS_RAPPELLING", False])

//AUR_TIE_IN_POINT_STATUS: 0 or unset: not a tie in point, 1: a tie in point at the top or origin end of the rope (located at the "rappel point", 2: tie in point at the bottom end of the rope.
#define AUR_GET_TIE_IN_POINT_STATUS(OBJ)       (OBJ getVariable  ["TF47_AUR_IS_TIE_IN_POINT", 0])
#define AUR_SET_TIE_IN_POINT_STATUS(OBJ, status)       OBJ setVariable  ["TF47_AUR_IS_TIE_IN_POINT", status, True]


//NOT USED
#define AUR_GET_LENGTH_TOP(OBJ)         ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_length_top")
//NOT USED
#define AUR_GET_LENGTH_BOTTOM(OBJ)      ((AUR_GET_MASTER(OBJ)) getVariable  "TF47_AUR_length_bottom")
//Length of the "leader" rope (from the anchor to the rappel point). this length of rope is removed from the available rope when calculating top and bottom rope lengths
#define AUR_GET_LENGTH_LEADER(OBJ)      (ropeLength (AUR_GET_ROPE_LEADER(OBJ)) )
//Total rope length minu the leader length
#define AUR_GET_LENGTH_AVAILABLE(OBJ)   ((AUR_GET_ROPE_LENGTH(OBJ)) - AUR_GET_LENGTH_LEADER(OBJ))


//clears the use state of the system and clears the master on the unit disconnecting.
#define AUR_ON_DISCONNECT(OBJ)          (AUR_SET_USE_STATUS(OBJ,False)); (AUR_SET_MASTER(OBJ, Nil))

//whether a player has an ascender in their inventory
#define AUR_HAS_ASCENDER(OBJ)  ("AUR_AscenderDevice" in ((weapons OBJ) + (items OBJ)))
