(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * File: Global.typ
 * Author: Coder
 * Created: September 22, 2013
 ********************************************************************
 * Global data types of project ASILAPC910
 ********************************************************************)

TYPE
	EksenHizlari_typ : 	STRUCT 
		X_JogVelocity : REAL;
		Y_JogVelocity : REAL;
		Z_JogVelocity : REAL;
		A_JogVelocity : REAL;
		GRX_JogVelocity : REAL;
		GRY_JogVelocity : REAL;
		GRZ_JogVelocity : REAL;
		GC1_JogVelocity : REAL;
		X_PosVelocity : REAL;
		Y_PosVelocity : REAL;
		Z_PosVelocity : REAL;
		A_PosVelocity : REAL;
		GRX_PosVelocity : REAL;
		GRY_PosVelocity : REAL;
		GRZ_PosVelocity : REAL;
		GC1_PosVelocity : REAL;
	END_STRUCT;
	actual_pos_typ : 	STRUCT 
		RX_Actual_Pos : REAL;
		RY_Actual_Pos : REAL;
		RZ_Actual_Pos : REAL;
		RA_Actual_Pos : REAL;
		GRX_Actual_Pos : REAL;
		GRZ_Actual_Pos : REAL;
		GC1_Actual_Pos : REAL;
		GC2_Actual_Pos : REAL;
		GRY_Actual_Pos : REAL;
	END_STRUCT;
	retain_typ : 	STRUCT 
		RX_MarkalamaKonumu : REAL;
		RY_MarkalamaKonumu : REAL;
		RZ_MarkalamaKonumu : REAL;
		GRX_KrankKoymaKonumu : REAL;
		GRZ_KrankKoymaKonumu : REAL;
		GRX_KrankAlmaKonumu : REAL;
		GRZ_KrankAlmaKonumu : REAL;
		RA_MarkalamaKonumu : REAL;
		Hatch_Adedi : INT;
		GRX_KrankAlma_Konumu_2 : REAL;
		GRZ_KrankAlma_Konumu_2 : REAL;
		GRX_KrankKoyma_Konumu_2 : REAL;
		GRZ_KrankKoyma_Konumu_2 : REAL;
		Yatay_Sira_Miktari : USINT;
		Dikey_Sira_Miktari : USINT;
		Yatay_Sira_Araligi : REAL;
		Dikey_Sira_Araligi : REAL;
		GRY_KrankAlma_Konumu : REAL;
		GRX_Position : REAL;
		GRZ_Position : REAL;
	END_STRUCT;
	automat_axisState_typ : 	STRUCT  (*axis state structure*)
		Disabled : BOOL; (*if set, axis is in state Disabled*)
		StandStill : BOOL; (*if set, axis is in state StandsStill*)
		Homing : BOOL; (*if set, axis is in state Homing*)
		Stopping : BOOL; (*if set, axis is in state Stopping*)
		DiscreteMotion : BOOL; (*if set, axis is in state DiscreteMotion*)
		ContinuousMotion : BOOL; (*if set, axis is in state ContinuousMotion*)
		SynchronizedMotion : BOOL; (*if set, axis is in state SynchronizedMotion*)
		ErrorStop : BOOL; (*if set, axis is in state ErrorStop*)
	END_STRUCT;
	automat_command_typ : 	STRUCT  (*command structure*)
		Power : BOOL; (*switch on the controller*)
		Home : BOOL; (*reference the axis*)
		MoveAbsolute : BOOL; (*move to an defined position*)
		MoveAdditive : BOOL; (*move a defiened distance*)
		MoveVelocity : BOOL; (*start a movement with a defiened velocity*)
		Halt : BOOL; (*stop every active movement*)
		Stop : BOOL; (*stop every active movement as long as is set*)
		MoveJogPos : BOOL; (*move in positive direction as long as is set*)
		MoveJogNeg : BOOL; (*move in negative direction as long as is set*)
		StartSlave : BOOL; (*start coupling beetween master and slave*)
		StopSlave : BOOL; (*stop coupling between master and slave*)
		GearInPos : BOOL;
		GearOut : BOOL;
		ErrorAcknowledge : BOOL; (*reset active errors*)
	END_STRUCT;
	automat_parameter_typ : 	STRUCT  (*parameter structure*)
		Position : REAL; (*target-position for MoveAbsolute-Command*)
		Distance : REAL; (*distance for MoveAdditive-Command*)
		Velocity : REAL; (*velocity for MoveVelocity-Command*)
		Direction : USINT; (*direction for commanded movements*)
		Acceleration : REAL; (*acceleration for commanded movements*)
		Deceleration : REAL; (*deceleration for commanded movements*)
		HomePosition : REAL; (*target-position for referencing the axis*)
		HomeMode : USINT; (*homing mode*)
		JogVelocity : REAL; (*velocity for jogging movement*)
	END_STRUCT;
	automat_status_typ : 	STRUCT  (*status structure*)
		ErrorID : UINT; (*ErrorID of any occured error*)
		ErrorText : ARRAY[0..3]OF STRING[79]; (*Error Text*)
		ActPosition : REAL; (*actual position of the axis*)
		ActVelocity : REAL; (*actual velocity of the axis*)
		DriveStatus : MC_DRIVESTATUS_TYP; (*actual status of the axis*)
	END_STRUCT;
	automat_typ : 	STRUCT  (*control structure*)
		Command : automat_command_typ; (*command structure*)
		Parameter : automat_parameter_typ; (*parameter structure*)
		Status : automat_status_typ; (*status structure*)
		AxisState : automat_axisState_typ; (*axis state structure*)
		Speed : axis_speed_typ;
	END_STRUCT;
	axis_speed_typ : 	STRUCT 
		Manual_Speed : REAL;
		Acceleration : REAL;
		Deceleration : REAL;
		Automatic_Speed : REAL;
		AccelerationOverride : REAL;
		VelocityOverride : REAL;
	END_STRUCT;
	basic_axisState_typ : 	STRUCT  (*axis state structure*)
		Disabled : BOOL; (*if set, axis is in state Disabled*)
		StandStill : BOOL; (*if set, axis is in state StandsStill*)
		Homing : BOOL; (*if set, axis is in state Homing*)
		Stopping : BOOL; (*if set, axis is in state Stopping*)
		DiscreteMotion : BOOL; (*if set, axis is in state DiscreteMotion*)
		ContinuousMotion : BOOL; (*if set, axis is in state ContinuousMotion*)
		SynchronizedMotion : BOOL; (*if set, axis is in state SynchronizedMotion*)
		ErrorStop : BOOL; (*if set, axis is in state ErrorStop*)
	END_STRUCT;
	basic_command_typ : 	STRUCT  (*command structure*)
		Power : BOOL; (*switch on the controller*)
		Home : BOOL; (*reference the axis*)
		MoveAbsolute : BOOL; (*move to an defined position*)
		MoveAdditive : BOOL; (*move a defiened distance*)
		MoveVelocity : BOOL; (*start a movement with a defiened velocity*)
		Halt : BOOL; (*stop every active movement once*)
		Stop : BOOL; (*stop every active movement as long as set*)
		MoveJogPos : BOOL; (*move in positive direction as long as is set*)
		MoveJogNeg : BOOL; (*move in negative direction as long as is set*)
		ErrorAcknowledge : BOOL; (*reset active errors*)
	END_STRUCT;
	basic_parameter_typ : 	STRUCT  (*parameter structure*)
		Position : REAL; (*target-position for MoveAbsolute-Command*)
		Distance : REAL; (*distance for MoveAdditive-Command*)
		Velocity : REAL; (*velocity for MoveVelocity-Command*)
		Direction : USINT; (*direction for commanded movements*)
		Acceleration : REAL; (*acceleration for commanded movements*)
		Deceleration : REAL; (*deceleration for commanded movements*)
		HomePosition : REAL; (*target-position for referencing the axis*)
		HomeMode : USINT; (*homing mode*)
		JogVelocity : REAL; (*velocity for jogging movement*)
	END_STRUCT;
	basic_status_typ : 	STRUCT  (*status structure*)
		ErrorID : UINT; (*ErrorID of any occured error*)
		ErrorText : ARRAY[0..3]OF STRING[79]; (*Error Text*)
		ActPosition : REAL; (*actual position of the axis*)
		ActVelocity : REAL; (*actual velocity of the axis*)
		DriveStatus : MC_DRIVESTATUS_TYP; (*actual status of the axis*)
	END_STRUCT;
	basic_typ : 	STRUCT  (*control structure*)
		Command : basic_command_typ; (*command structure*)
		Parameter : basic_parameter_typ; (*parameter structure*)
		Status : basic_status_typ; (*status structure*)
		AxisState : basic_axisState_typ; (*axis state structure*)
		Speed : axis_speed_typ;
	END_STRUCT;
	Config_setup_typ : 	STRUCT 
		LanguageIndex : USINT;
		SubnetMask : ARRAY[0..3]OF USINT;
		IPAddress : ARRAY[0..3]OF USINT;
		Broadcast : ARRAY[0..3]OF USINT;
		Gateway : ARRAY[0..3]OF USINT;
		CmdWriteFile : BOOL;
	END_STRUCT;
	DateTimeStructure_typ : 	STRUCT 
		year : UINT;
		month : USINT;
		day : USINT;
		wday : USINT;
		hour : USINT;
		minute : USINT;
		second : USINT;
		millisec : UINT;
		microsec : UINT;
	END_STRUCT;
	digitalinput_typ : 	STRUCT 
		Acil_Stop : BOOL;
		X_PosLimit : BOOL;
		X_NegLimit : BOOL;
		X_RefSensor : BOOL;
		Y_NegLimit : BOOL;
		Y_PosLimit : BOOL;
		Y_RefSensor : BOOL;
		Lazer_IsBitti : BOOL;
		GRX_NegLimit : BOOL;
		GRX_RefSensor : BOOL;
		GRX_PosLimit : BOOL;
		GRZ_RefSensor : BOOL;
		GRZ_NegLimit : BOOL;
		GRZ_PosLimit : BOOL;
		GC1_NegLimit : BOOL;
		GC1_RefSensor : BOOL;
		GC1_PosLimit : BOOL;
		GC2_NegLimit : BOOL;
		GC2_RefSensor : BOOL;
		GC2_PosLimit : BOOL;
		GRY_NegLimit : BOOL;
		GRY_PosLimit : BOOL;
		RAnahtarKonumu1 : BOOL;
		RAnahtarKonumu2 : BOOL;
		RAnahtarKonumu3 : BOOL;
		RAnahtarKonumu4 : BOOL;
		R_JoySag : BOOL;
		R_JoySol : BOOL;
		R_Input1 : BOOL;
		LAnahtarKonumu1 : BOOL;
		LAnahtarKonumu2 : BOOL;
		LAnahtarKonumu3 : BOOL;
		LAnahtarKonumu4 : BOOL;
		L_JoySag : BOOL;
		L_JoySol : BOOL;
		L_Input1 : BOOL;
	END_STRUCT;
	digitaloutput_typ : 	STRUCT 
		Lazer_Start : BOOL;
		Lazer_Stop : BOOL;
		Lazer_Pointer : BOOL;
		Lazer_Hatch : BOOL;
		Lazer_Barcode : BOOL;
		Konveyor_Ileri : BOOL;
		Konveyor_Geri : BOOL;
		Kripper_Ac : BOOL;
		Kripper_Kapat : BOOL;
	END_STRUCT;
	hmi_ipconfig : 	STRUCT 
		EthernetDevice : STRING[10];
		OptionVolatile : UDINT;
		TcpIpReady : USINT;
		IPAddress : ARRAY[0..3]OF USINT;
		SubnetMask : ARRAY[0..3]OF USINT;
		Broadcast : ARRAY[0..3]OF USINT;
		Gateway : ARRAY[0..3]OF USINT;
		EthernetBaudrate : USINT;
		AddressChanged : USINT;
		ReadTcpIp : USINT;
		UpdateTcpIp : USINT;
		ErrorDuringOperation : UINT;
		NodeNumber : USINT;
		cmdLanguageUp : BOOL;
		cmdLanguageDown : BOOL;
		LanguageIndex : USINT;
		LockLanguageUpButton : USINT;
		ActualDateTime : DateTimeStructure_typ;
		DateTimeChanged : USINT;
	END_STRUCT;
	parametreler_typ : 	STRUCT 
		X_JogPos : BOOL;
		X_JogNeg : BOOL;
		Y_JogPos : BOOL;
		Y_JogNeg : BOOL;
		Z_JogPos : BOOL;
		Z_JogNeg : BOOL;
		A_JogPos : BOOL;
		A_JogNeg : BOOL;
		X_HomeStart : BOOL;
		Y_HomeStart : BOOL;
		A_HomeStart : BOOL;
		Z_HomeStart : BOOL;
		Alarm_Reset : BOOL;
		Lazer_Start : BOOL;
		Lazer_Stop : BOOL;
		Markalamaya_Git : BOOL;
		X_HomeOk : BOOL;
		Y_HomeOk : BOOL;
		Z_HomeOk : BOOL;
		A_HomeOk : BOOL;
		GRX_JogPos : BOOL;
		GRX_JogNeg : BOOL;
		GRX_HomeStart : BOOL;
		GRX_HomeOk : BOOL;
		GRZ_JogPos : BOOL;
		GRZ_JogNeg : BOOL;
		GRZ_HomeStart : BOOL;
		GRZ_HomeOk : BOOL;
		GC1_HomeStart : BOOL;
		GC1_HomeOk : BOOL;
		GC2_JogPos : BOOL;
		GC2_JogNeg : BOOL;
		GC2_HomeStart : BOOL;
		GC2_HomeOk : BOOL;
		GC1_JogPos : BOOL;
		GC1_JogNeg : BOOL;
		Krank_Al : BOOL;
		Krank_Koy : BOOL;
		Konveyor_Ileri_Buton : BOOL;
		Konveyor_Geri_Buton : BOOL;
		Markalama_Ok : BOOL;
		GRY_HomeStart : BOOL;
		GRY_HomeOk : BOOL;
		GRY_JogNeg : BOOL;
		GRY_JogPos : BOOL;
		Markalama_Start : BOOL;
		Kripper_Ac : BOOL;
		Kripper_Kapat : BOOL;
		Markalama_Ok_Delphi : BOOL;
	END_STRUCT;
	time_typ : 	STRUCT 
		XStationLeft : ARRAY[0..9]OF REAL;
		XStationFree : ARRAY[0..9]OF REAL;
		ZStationUp : ARRAY[0..9]OF REAL;
		ZStationDown : ARRAY[0..9]OF REAL;
		Time : ARRAY[0..9]OF UINT;
		TimeUp : ARRAY[0..9]OF UINT;
	END_STRUCT;
END_TYPE
