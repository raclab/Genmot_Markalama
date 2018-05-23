/*******************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * PROGRAM: Automat
 * File: autoamt.c
 * Author: Bernecker + Rainer
 * Created: December 01, 2009
 ********************************************************************
 * Implementation of Program Automat
 ********************************************************************/

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
#include <string.h>

#define STATE_WAIT              0
#define STATE_POWER_ON          1
#define STATE_HOME              2

#define STATE_READY             10
#define STATE_HALT              11
#define STATE_STOP              12
#define STATE_JOG_POSITIVE      13
#define STATE_JOG_NEGATIVE      14
#define STATE_MOVE_ABSOLUTE     15
#define STATE_MOVE_ADDITIVE     16
#define STATE_MOVE_VELOCITY     17

#define STATE_DOWNLOAD_CAM_OBJ  20
#define STATE_AUTOMAT_INIT      30
#define STATE_AUTOMAT_START     31
#define STATE_AUTOMAT_STOP      32
#define STATE_PHASING           33
#define STATE_GEAR_INPOS        40
#define STATE_GEAR_OUT          50

#define STATE_ERROR_AXIS        100
#define STATE_ERROR             101
#define STATE_ERROR_RESET       102


_INIT void automat_init(void)
{
	/* get axis object */
	//Axis1Obj = (UDINT)&gAxis01;  /*Master Axis*/
	Axis2Obj = (UDINT)&PowerSp2;  /*Slave Axis*/

	AxisStep = STATE_WAIT;  /* start step */

	Power2Axis.Parameter.Velocity              = 35000;  /*velocity for movement*/
	Power2Axis.Parameter.Acceleration          = 50000;  /*acceleration for movement*/
	Power2Axis.Parameter.Deceleration          = 50000;  /*deceleration for movement*/
	Power2Axis.Parameter.JogVelocity           = 20000;   /*velocity for jogging */

}

_CYCLIC void automat_cyclic(void)
{

	
/***************************************************************
        Control Sequence
***************************************************************/

/* status information is read before the step sequencer to attain a shorter reaction time */
/************************ MC_READSTATUS *************************/
	MC_ReadStatus_0.Enable = !MC_ReadStatus_0.Error;
	MC_ReadStatus_0.Axis = Axis2Obj;
	MC_ReadStatus(&MC_ReadStatus_0);
	Power2Axis.AxisState.Disabled             = MC_ReadStatus_0.Disabled;
	Power2Axis.AxisState.StandStill           = MC_ReadStatus_0.StandStill;
	Power2Axis.AxisState.Stopping             = MC_ReadStatus_0.Stopping;
	Power2Axis.AxisState.Homing               = MC_ReadStatus_0.Homing;
	Power2Axis.AxisState.DiscreteMotion       = MC_ReadStatus_0.DiscreteMotion;
	Power2Axis.AxisState.ContinuousMotion     = MC_ReadStatus_0.ContinuousMotion;
	Power2Axis.AxisState.SynchronizedMotion   = MC_ReadStatus_0.SynchronizedMotion;
	Power2Axis.AxisState.ErrorStop            = MC_ReadStatus_0.Errorstop;

	/********************MC_BR_READDRIVESTATUS***********************/
	MC_BR_ReadDriveStatus_0.Enable = !MC_BR_ReadDriveStatus_0.Error;
	MC_BR_ReadDriveStatus_0.Axis = Axis2Obj; 
	MC_BR_ReadDriveStatus_0.AdrDriveStatus = (UDINT)&(Power2Axis.Status.DriveStatus);
	MC_BR_ReadDriveStatus(&MC_BR_ReadDriveStatus_0);

	/******************** MC_READACTUALPOSITION *********************/
	MC_ReadActualPosition_0.Enable = (!MC_ReadActualPosition_0.Error);
	MC_ReadActualPosition_0.Axis = Axis2Obj;
	MC_ReadActualPosition(&MC_ReadActualPosition_0);
	if(MC_ReadActualPosition_0.Valid == 1)
	{
		Power2Axis.Status.ActPosition = MC_ReadActualPosition_0.Position;
	}

	/******************** MC_READACTUALVELOCITY *********************/
	MC_ReadActualVelocity_0.Enable = (!MC_ReadActualVelocity_0.Error);
	MC_ReadActualVelocity_0.Axis = Axis2Obj;
	MC_ReadActualVelocity(&MC_ReadActualVelocity_0);
	if(MC_ReadActualVelocity_0.Valid == 1)
	{
		Power2Axis.Status.ActVelocity = MC_ReadActualVelocity_0.Velocity;
	}
	
	/*********************** MC SET OVERRIDE *********************/
	MC_SetOverride_0.Enable = (!MC_SetOverride_0.Error);
	MC_SetOverride_0.AccFactor = Power2Axis.Speed.AccelerationOverride = 1.0;
	if ((Power2Axis.Speed.VelocityOverride < 2.0) && (Power2Axis.Speed.VelocityOverride > 0.0000001))
	{
		MC_SetOverride_0.VelFactor = Power2Axis.Speed.VelocityOverride;
	}
	MC_SetOverride_0.Axis=Axis2Obj;
	MC_SetOverride(&MC_SetOverride_0);


	/************************ MC_READAXISERROR **********************/
	MC_ReadAxisError_0.Enable = !MC_ReadAxisError_0.Error;
	MC_ReadAxisError_0.Axis = Axis2Obj;
	MC_ReadAxisError_0.DataAddress = (UDINT)&(Power2Axis.Status.ErrorText);
	MC_ReadAxisError_0.DataLength = sizeof(Power2Axis.Status.ErrorText);
	strcpy((void*)&MC_ReadAxisError_0.DataObjectName,"acp10etxen");
	MC_ReadAxisError(&MC_ReadAxisError_0);

	/* central monitoring of stop command attains a shorter reaction time in case of emergency stop */
	/******************CHECK for STOP COMMAND************************/
	if (Power2Axis.Command.Stop == 1)
	{
		if ((AxisStep >= STATE_READY) && (AxisStep < STATE_ERROR))   
		{
			/* reset all FB execute inputs we use */
			MC_Home_0.Execute = 0;
			MC_Stop_0.Execute = 0;
			MC_MoveAbsolute_0.Execute = 0;
			MC_MoveAdditive_0.Execute = 0;
			MC_MoveVelocity_0.Execute = 0;

			MC_BR_AutControl_0.Enable = 0;
			MC_BR_AutControl_0.Start = 0;
			MC_BR_AutControl_0.Stop = 0;

			MC_ReadAxisError_0.Acknowledge = 0;
			MC_Reset_0.Execute = 0;

			/* reset user commands */
			Power2Axis.Command.Stop = 0;
			Power2Axis.Command.Home = 0;
			Power2Axis.Command.MoveJogPos = 0;
			Power2Axis.Command.MoveJogNeg = 0;
			Power2Axis.Command.MoveVelocity = 0;
			Power2Axis.Command.MoveAbsolute = 0;
			Power2Axis.Command.MoveAdditive = 0;
			Power2Axis.Command.StopSlave = 0;
			Power2Axis.Command.StartSlave = 0;
            
			AxisStep = STATE_STOP;
		}
	}


	/**************** CHECK FOR GENERAL AXIS ERROR ******************/
	if ((MC_ReadAxisError_0.AxisErrorID != 0) && (MC_ReadAxisError_0.Valid == 1))
	{
		AxisStep = STATE_ERROR_AXIS;
	}
		/***************** CHECK IF POWER SHOULD BE OFF *******************/
	else if ((Power2Axis.Command.Power == 0) && (MC_ReadAxisError_0.Valid == 1))
	{
		if ((MC_ReadStatus_0.Errorstop == 1) && (MC_ReadStatus_0.Valid == 1))
		{
			AxisStep = STATE_ERROR_RESET;
		}
		else
		{
			AxisStep = STATE_WAIT;
		}
	}

	switch(AxisStep)
	{
		/******************** WAIT *************************/
		case STATE_WAIT:  /* STATE: Wait */
			if (Power2Axis.Command.Power == 1)
			{
				AxisStep = STATE_POWER_ON;
			}    
			else
			{
				MC_Power_0.Enable = 0;
			}

			/* reset all FB execute inputs we use */
			MC_Home_0.Execute = 0;
			MC_Stop_0.Execute = 0;
			MC_MoveAbsolute_0.Execute = 0;
			MC_MoveAdditive_0.Execute = 0;
			MC_MoveVelocity_0.Execute = 0;

			MC_BR_AutControl_0.Enable = 0;
			MC_BR_AutControl_0.Start = 0;
			MC_BR_AutControl_0.Stop = 0;

			MC_ReadAxisError_0.Acknowledge = 0;
			MC_Reset_0.Execute = 0;

			/* reset user commands */
			Power2Axis.Command.Stop = 0;
			Power2Axis.Command.Home = 0;
			Power2Axis.Command.MoveJogPos = 0;
			Power2Axis.Command.MoveJogNeg = 0;
			Power2Axis.Command.MoveVelocity = 0;
			Power2Axis.Command.MoveAbsolute = 0;
			Power2Axis.Command.MoveAdditive = 0;
			Power2Axis.Command.StopSlave = 0;
			Power2Axis.Command.StartSlave = 0;

			Power2Axis.Status.ErrorID = 0;
			break;

		/******************** POWER ON **********************/
		case STATE_POWER_ON:  /* STATE: Power on */
			MC_Power_0.Enable = 1;
			if (MC_Power_0.Status == 1)
			{
				AxisStep = STATE_READY;
			}
			/* if a power error occured go to error state */
			if (MC_Power_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_Power_0.ErrorID;
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** READY **********************/
		case STATE_READY:  /* STATE: Waiting for commands */
			if (Power2Axis.Command.Home == 1)
			{
				Power2Axis.Command.Home = 0;
				AxisStep = STATE_HOME;
			}
			else if (Power2Axis.Command.Stop == 1)
			{
				AxisStep = STATE_STOP;
			}
			else if (Power2Axis.Command.MoveJogPos == 1)
			{
				AxisStep = STATE_JOG_POSITIVE;
			}
			else if (Power2Axis.Command.MoveJogNeg == 1)
			{
				AxisStep = STATE_JOG_NEGATIVE;
			}
			else if (Power2Axis.Command.MoveAbsolute == 1)
			{
				AxisStep = STATE_MOVE_ABSOLUTE;
			}
			else if (Power2Axis.Command.MoveAdditive == 1)
			{
				Power2Axis.Command.MoveAdditive = 0;
				AxisStep = STATE_MOVE_ADDITIVE;
			}
			else if (Power2Axis.Command.MoveVelocity == 1)
			{
				Power2Axis.Command.MoveVelocity = 0;
				AxisStep = STATE_MOVE_VELOCITY;
			}
			else if (Power2Axis.Command.StartSlave == 1)
			{
				Power2Axis.Command.StartSlave = 0;
				AxisStep = STATE_AUTOMAT_INIT;
			}
			else if (Power2Axis.Command.GearInPos == 1)
			{
				Power2Axis.Command.GearInPos = 0;
				AxisStep = STATE_GEAR_INPOS;
			}
			else if (Power2Axis.Command.GearOut == 1)
			{
				Power2Axis.Command.GearOut = 0;
				AxisStep = STATE_GEAR_OUT;
			}	
			else if (Power2Axis.Command.Halt == 1)
			{
				Power2Axis.Command.Halt = 0;
				AxisStep = STATE_HALT;   
			}
			break;

		/******************** HOME **********************/
		case STATE_HOME:  /* STATE: start homing process */
			MC_Home_0.Position = Power2Axis.Parameter.HomePosition;
			MC_Home_0.HomingMode = Power2Axis.Parameter.HomeMode;
			MC_Home_0.Execute = 1;
			if (Power2Axis.Command.Stop == 1)
			{
				MC_Home_0.Execute = 0;
				AxisStep = STATE_STOP;
			}
			else if (MC_Home_0.Done == 1)
			{
				MC_Home_0.Execute = 0;
				//AxisStep = STATE_DOWNLOAD_CAM_OBJ;
				AxisStep = STATE_READY;
			}
			/* if a homing error occured go to error state */
			if (MC_Home_0.Error == 1)
			{
				MC_Home_0.Execute = 0;
				Power2Axis.Status.ErrorID = MC_Home_0.ErrorID;
				AxisStep = STATE_ERROR;
			}
			break;
    
		/************************HALT MOVEMENT**************************/    
		case STATE_HALT:    /* STATE: Stop the active movement */
			MC_Halt_0.Deceleration = Power2Axis.Parameter.Deceleration;
			MC_Halt_0.Execute = 1;
			if (MC_Halt_0.Done == 1)
			{
				MC_Halt_0.Execute = 0;
				AxisStep = STATE_READY;  
			}
			/*check if error occured */
			if (MC_Halt_0.Error == 1)
			{
				MC_Halt_0.Execute = 0;
				Power2Axis.Status.ErrorID = MC_Halt_0.ErrorID;
				AxisStep = STATE_ERROR;   
			}
			break;    

		/*********************** STOP MOVEMENT *************************/
		case STATE_STOP:  /* STATE: Stop movement as long as command is set */
			MC_Stop_0.Deceleration = Power2Axis.Parameter.Deceleration;
			MC_Stop_0.Execute = 1;
			/* if axis is stopped go to ready state */
			if ((MC_Stop_0.Done == 1) && (Power2Axis.Command.Stop == 0))
			{
				MC_Stop_0.Execute = 0;
				AxisStep = STATE_READY;
			}
			/* check if error occured */
			if (MC_Stop_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_Stop_0.ErrorID;
				MC_Stop_0.Execute = 0;
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** START JOG MOVEMENT POSITVE **********************/
		case STATE_JOG_POSITIVE:  /* STATE: Start jog movement in positive direction */
			MC_MoveVelocity_0.Velocity      = Power2Axis.Parameter.JogVelocity;
			MC_MoveVelocity_0.Acceleration  = Power2Axis.Parameter.Acceleration;
			MC_MoveVelocity_0.Deceleration  = Power2Axis.Parameter.Deceleration;
			MC_MoveVelocity_0.Direction     = mcPOSITIVE_DIR;
			MC_MoveVelocity_0.Execute = 1;
			if (Power2Axis.Command.Stop == 1)
			{
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_STOP;   
			}
			/* check if jog movement should be stopped */
			if (Power2Axis.Command.MoveJogPos == 0)
			{
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_HALT;
			}
			/* check if error occured */
			if (MC_MoveVelocity_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_MoveVelocity_0.ErrorID;
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** START JOG MOVEMENT NEGATIVE **********************/
		case STATE_JOG_NEGATIVE:  /* STATE: Start jog movement in negative direction */
			MC_MoveVelocity_0.Velocity      = Power2Axis.Parameter.JogVelocity;
			MC_MoveVelocity_0.Acceleration  = Power2Axis.Parameter.Acceleration;
			MC_MoveVelocity_0.Deceleration  = Power2Axis.Parameter.Deceleration;
			MC_MoveVelocity_0.Direction     = mcNEGATIVE_DIR;
			MC_MoveVelocity_0.Execute = 1;
			if (Power2Axis.Command.Stop == 1)
			{
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_STOP;   
			}
			/* check if jog movement should be stopped */
			if (Power2Axis.Command.MoveJogNeg == 0)
			{
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_HALT;
			}
			/* check if error occured */
			if (MC_MoveVelocity_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_MoveVelocity_0.ErrorID;
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** START ABSOLUTE MOVEMENT **********************/
		case STATE_MOVE_ABSOLUTE:  /* STATE: Start absolute movement */
			MC_MoveAbsolute_0.Position      = Power2Axis.Parameter.Position;
			MC_MoveAbsolute_0.Velocity      = Power2Axis.Parameter.Velocity;
			MC_MoveAbsolute_0.Acceleration  = Power2Axis.Parameter.Acceleration;
			MC_MoveAbsolute_0.Deceleration  = Power2Axis.Parameter.Deceleration;
			MC_MoveAbsolute_0.Direction     = Power2Axis.Parameter.Direction;
			MC_MoveAbsolute_0.Execute = 1;
			/* check if commanded position is reached */
			if (Power2Axis.Command.Stop == 1)
			{
				MC_MoveAbsolute_0.Execute = 0;
				Power2Axis.Command.MoveAbsolute = 0;
				AxisStep = STATE_STOP;
			}
			else if (Power2Axis.Command.Halt == 1)
			{
				Power2Axis.Command.Halt = 0;
				MC_MoveAbsolute_0.Execute = 0;
				Power2Axis.Command.MoveAbsolute = 0;
				AxisStep = STATE_HALT;   
			}
			else if (MC_MoveAbsolute_0.Done == 1)
			{
				MC_MoveAbsolute_0.Execute = 0;
				Power2Axis.Command.MoveAbsolute = 0;
				AxisStep = STATE_READY;
			}
			/* check if error occured */
			if (MC_MoveAbsolute_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_MoveAbsolute_0.ErrorID;
				MC_MoveAbsolute_0.Execute = 0;
				Power2Axis.Command.MoveAbsolute = 0;			
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** START ADDITIVE MOVEMENT **********************/
		case STATE_MOVE_ADDITIVE:  /* STATE: Start additive movement */
			MC_MoveAdditive_0.Distance      = Power2Axis.Parameter.Distance;
			MC_MoveAdditive_0.Velocity      = Power2Axis.Parameter.Velocity;
			MC_MoveAdditive_0.Acceleration  = Power2Axis.Parameter.Acceleration;
			MC_MoveAdditive_0.Deceleration  = Power2Axis.Parameter.Deceleration;
			MC_MoveAdditive_0.Execute = 1;
			/* check if commanded distance is reached */
			if (Power2Axis.Command.Stop == 1)
			{
				MC_MoveAdditive_0.Execute = 0;
				AxisStep = STATE_STOP;
			}
			else if (Power2Axis.Command.Halt == 1)
			{
				Power2Axis.Command.Halt = 0;
				MC_MoveAdditive_0.Execute = 0;
				AxisStep = STATE_HALT;   
			}
			else if (MC_MoveAdditive_0.Done == 1)
			{
				MC_MoveAdditive_0.Execute = 0;
				AxisStep = STATE_READY;
			}
			/* check if error occured */
			if (MC_MoveAdditive_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_MoveAdditive_0.ErrorID;
				MC_MoveAdditive_0.Execute = 0;
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** START VELOCITY MOVEMENT **********************/
		case STATE_MOVE_VELOCITY:  /* STATE: Start velocity movement */
			MC_MoveVelocity_0.Velocity      = Power2Axis.Parameter.Velocity;
			MC_MoveVelocity_0.Acceleration  = Power2Axis.Parameter.Acceleration;
			MC_MoveVelocity_0.Deceleration  = Power2Axis.Parameter.Deceleration;
			MC_MoveVelocity_0.Direction     = Power2Axis.Parameter.Direction;
			MC_MoveVelocity_0.Execute = 1;
			/* check if commanded velocity is reached */
			if (Power2Axis.Command.Stop == 1)
			{
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_STOP;
			}
			else if (Power2Axis.Command.Halt == 1)
			{
				Power2Axis.Command.Halt = 0;
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_HALT;
			}
			else if (MC_MoveVelocity_0.InVelocity == 1)
			{
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_READY;
			}
			/* check if error occured */
			if (MC_MoveVelocity_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_MoveVelocity_0.ErrorID;
				MC_MoveVelocity_0.Execute = 0;
				AxisStep = STATE_ERROR;
			}
			break;
		
		case STATE_DOWNLOAD_CAM_OBJ:
			/*************** DOWNLOAD CAM PROFILE OBJECT ****************/
			strcpy((void*)& MC_BR_DownloadCamProfileObj_0.DataObjectName, "IticiCam");
			MC_BR_DownloadCamProfileObj_0.Index = 1;
			MC_BR_DownloadCamProfileObj_0.Periodic = mcPERIODIC;
			MC_BR_DownloadCamProfileObj_0.Execute = 1;
			if (MC_BR_DownloadCamProfileObj_0.Done) 
			{
				MC_BR_DownloadCamProfileObj_0.Execute = 0;
				AxisStep = STATE_READY;
			}
			else if (MC_BR_DownloadCamProfileObj_0.Error)
			{
				Power2Axis.Status.ErrorID = MC_BR_DownloadCamProfileObj_0.ErrorID;
				MC_BR_DownloadCamProfileObj_0.Execute=0;
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** INITIALIZE AUTOMAT PARAMETER **********************/
		case STATE_AUTOMAT_INIT:  /* STATE: Initialize Automat parameter */
			
			/*general automat parameter*/
			AutData.Master				= Axis1Obj;
			AutData.StartPosition		= 0;
			AutData.StartInterval		= 0;
			AutData.MaxMasterVelocity	= 50000;
			AutData.MasterParID			= 412;

			/*Automat STATE 0 Basis State*/
			AutData.State[0].Event[0].Type		= ncS_START;
			AutData.State[0].Event[0].Attribute	= ncAT_ONCE;
			AutData.State[0].Event[0].NextState	= 1;


			/*Automat STATE 1 Standstill*/
			AutData.State[1].CamProfileIndex	= 0x0001;
			AutData.State[1].MasterFactor		= 1000;
			AutData.State[1].SlaveFactor		= 1000;
			AutData.State[1].CompMode			= ncOFF;
			AutData.State[1].Event[2].Type		= ncST_END;
			AutData.State[1].Event[2].Attribute	= ncST_END;
			AutData.State[1].Event[2].NextState	= 1;
    
			MC_BR_InitAutData_0.InitOptions.GlobalParams      = mcALL_PARAMS;
			MC_BR_InitAutData_0.InitOptions.StateIndex        = mcALL_STATES;
			MC_BR_InitAutData_0.InitOptions.EventIndex        = mcALL_EVENTS;
			MC_BR_InitAutData_0.InitOptions.MaxStatesPerCycle = 14;
			MC_BR_InitAutData_0.InitOptions.Force             = mcOFF;
			MC_BR_InitAutData_0.AdrAutData  = (UDINT)&(AutData);
			MC_BR_InitAutData_0.Execute     = 1;

			/*wait for initialization done */
			if (MC_BR_InitAutData_0.Done == 1)
			{
				MC_BR_InitAutData_0.Execute = 0;
				AxisStep = STATE_AUTOMAT_START;	
			}

			/*check if error occured */
			if (MC_BR_InitAutData_0.Error == 1)
			{
				MC_BR_InitAutData_0.Execute = 0;
				Power2Axis.Status.ErrorID = MC_BR_InitAutData_0.ErrorID;
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** ENABLE CAM-AUTOMAT **********************/
		case STATE_AUTOMAT_START:  /* STATE: Start Automat */

			MC_BR_AutControl_0.Enable = 1;
			MC_BR_AutControl_0.Start = 1;
			/* wait for Automat stop */
			if (Power2Axis.Command.Stop == 1)
			{
				MC_BR_AutControl_0.Enable = 0;
				MC_BR_AutControl_0.Start = 0;
				AxisStep = STATE_STOP;
			}
			else if (Power2Axis.Command.Halt == 1)
			{
				Power2Axis.Command.Halt = 0;
				MC_BR_AutControl_0.Enable = 0;
				MC_BR_AutControl_0.Start = 0;
				AxisStep = STATE_HALT;   
			}
			else if (Power2Axis.Command.StopSlave == 1)
			{
				Power2Axis.Command.StopSlave = 0;
				MC_BR_AutControl_0.Start = 0;
				AxisStep = STATE_AUTOMAT_STOP;
			}
			/* check if error occured */
			if (MC_BR_AutControl_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_BR_AutControl_0.ErrorID;
				MC_BR_AutControl_0.Enable = 0;
				MC_BR_AutControl_0.Start = 0;
				AxisStep = STATE_ERROR;
			}
			
			break;

		/******************** STOP CAM-AUTOMAT**********************/
		case STATE_AUTOMAT_STOP:  /* STATE: Stop CAM-Automat*/
			MC_BR_AutControl_0.Deceleration = Power2Axis.Parameter.Deceleration;
			MC_BR_AutControl_0.Stop = 1;
			/* check if automat is stopped */
			if (MC_BR_AutControl_0.Running == 0)
			{
				MC_BR_AutControl_0.Enable = 0;
				MC_BR_AutControl_0.Stop = 0;
				AxisStep = STATE_READY;
			}
			/* check if error occured */
			if (MC_BR_AutControl_0.Error == 1)
			{
				Power2Axis.Status.ErrorID = MC_BR_AutControl_0.ErrorID;
				MC_BR_AutControl_0.Enable = 0;
				MC_BR_AutControl_0.Stop = 0;
				AxisStep = STATE_ERROR;
			}
			break;
		
		/***************STATE_PHASING*******************/
		case STATE_PHASING:  /*phase shift, only seen on slave side*/
			MC_BR_Phasing_0.Enable = 1;
			MC_BR_Phasing_0.Shift  = 1;
			MC_BR_Phasing_0.Velocity = 10000;
			MC_BR_Phasing_0.Acceleration = 50000;
			MC_BR_Phasing_0.ApplicationMode = mcTIME_BASED;
			MC_BR_Phasing_0.ShiftMode = mcABSOLUTE;
			MC_BR_Phasing_0.InitData = 1;
      
			if (MC_BR_Phasing_0.ShiftAttained)
			{
				MC_BR_Phasing_0.InitData = 0;
			    MC_BR_Phasing_0.Enable = 0;
				AxisStep = STATE_AUTOMAT_START;
			}
			else if (MC_BR_Phasing_0.Error)
			{
				Power2Axis.Status.ErrorID = MC_BR_Phasing_0.ErrorID;
				MC_BR_Phasing_0.Enable = 0;
				AxisStep = STATE_ERROR;
			}
			break;

		/******************** GEAR IN POSITION ********************/
		case STATE_GEAR_INPOS:  /* engage slave and master with set gear ratio*/
			MC_GearInPos_0.RatioNumerator=1000;  /*1:2 Slave/Master ratio*/
			MC_GearInPos_0.RatioDenominator=2000;  /*1:2 Slave/Master ratio*/
			MC_GearInPos_0.Acceleration=50000;
			MC_GearInPos_0.MasterSyncPosition=1000;
			MC_GearInPos_0.SlaveSyncPosition=2000;
			MC_GearInPos_0.SyncMode=mcSHORTEST_WAY;
			MC_GearInPos_0.MasterStartDistance=1000;
			MC_GearInPos_0.Velocity=10000;
			MC_GearInPos_0.Acceleration=50000;
			MC_GearInPos_0.Execute=1;
			/*Return to wait state once slave is in gear*/
			if (MC_GearInPos_0.InSync)
			{
				MC_GearInPos_0.Execute=0;
				AxisStep = STATE_READY;
			}
			else if (MC_GearInPos_0.Error)
			{
				Power2Axis.Status.ErrorID = MC_GearInPos_0.ErrorID;
				MC_GearInPos_0.Execute=0;
				AxisStep = STATE_ERROR;
			}
			break;
		
		/******************** GEAR OUT*************************/
		case STATE_GEAR_OUT:
			MC_GearOut_0.Execute=1;
			/*Return to wait state once gear out is complete*/
			if (MC_GearOut_0.Done)
			{
				MC_GearOut_0.Execute=0;
				AxisStep = STATE_READY;
			}
			else if (MC_GearOut_0.Error)
			{
				Power2Axis.Status.ErrorID = MC_GearOut_0.ErrorID;
				MC_GearOut_0.Execute=0;
				AxisStep = STATE_ERROR;
			}
			break;
		
		/******************** FB-ERROR OCCURED *************************/
		case STATE_ERROR:  /* STATE: Error */
			/* check if FB indicates an axis error */
			if (MC_ReadAxisError_0.AxisErrorCount != 0)
			{
				AxisStep = STATE_ERROR_AXIS;
			}
			else
			{
				if (Power2Axis.Command.ErrorAcknowledge == 1)
				{
					Power2Axis.Command.ErrorAcknowledge = 0;
					Power2Axis.Status.ErrorID = 0;
					/* reset axis if it is in axis state ErrorStop */
					if ((MC_ReadStatus_0.Errorstop == 1) && (MC_ReadStatus_0.Valid == 1))
					{
						AxisStep = STATE_ERROR_RESET;
					}
					else
					{
						AxisStep = STATE_WAIT;
					}
				}
			}
			break;

		/******************** AXIS-ERROR OCCURED *************************/
		case STATE_ERROR_AXIS:  /* STATE: Axis Error */
			if (MC_ReadAxisError_0.Valid == 1)
			{
				if (MC_ReadAxisError_0.AxisErrorID != 0)
				{
					Power2Axis.Status.ErrorID = MC_ReadAxisError_0.AxisErrorID;
				}
				MC_ReadAxisError_0.Acknowledge = 0;
				if (Power2Axis.Command.ErrorAcknowledge == 1)
				{
					Power2Axis.Command.ErrorAcknowledge = 0;
					/* acknowledge axis error */
					if (MC_ReadAxisError_0.AxisErrorID != 0)
					{
						MC_ReadAxisError_0.Acknowledge = 1;
					}
				}
				if (MC_ReadAxisError_0.AxisErrorCount == 0)
				{
					Power2Axis.Status.ErrorID = 0;
					/* reset axis if it is in axis state ErrorStop */
					if ((MC_ReadStatus_0.Errorstop == 1) && (MC_ReadStatus_0.Valid == 1))
					{
						AxisStep = STATE_ERROR_RESET;
					}
					else
					{
						AxisStep = STATE_WAIT;
					}
				}
			}
			break;

		/******************** RESET DONE *************************/
		case STATE_ERROR_RESET:  /* STATE: Wait for reset done */
			MC_Reset_0.Execute = 1;
			/* reset MC_Power.Enable if this FB is in Error*/
			if(MC_Power_0.Error == 1)
			{
				MC_Power_0.Enable = 0;
			}
			if(MC_Reset_0.Done == 1)
			{
				MC_Reset_0.Execute = 0;
				AxisStep = STATE_WAIT;
			}
			else if(MC_Reset_0.Error == 1)
			{
				MC_Reset_0.Execute = 0;
				AxisStep = STATE_ERROR;   
			}
			break;
    
		/******************** SEQUENCE END *************************/
	}

/***************************************************************
        Function Block Calls
***************************************************************/

/************************** MC_POWER ****************************/
	MC_Power_0.Axis = Axis2Obj;  /* pointer to axis */
	MC_Power(&MC_Power_0);

	/************************** MC_HOME *****************************/
	MC_Home_0.Axis = Axis2Obj;
	MC_Home(&MC_Home_0);

	/********************** MC_MOVEABSOLUTE *************************/
	MC_MoveAbsolute_0.Axis = Axis2Obj;
	MC_MoveAbsolute(&MC_MoveAbsolute_0);

	/********************** MC_MOVEADDITIVE *************************/
	MC_MoveAdditive_0.Axis = Axis2Obj;
	MC_MoveAdditive(&MC_MoveAdditive_0);

	/********************** MC_MOVEVELOCITY *************************/
	MC_MoveVelocity_0.Axis = Axis2Obj;
	MC_MoveVelocity(&MC_MoveVelocity_0);
	
	/**********************MC_BR_DOWNLOAD CAM PROFILE************************/
	MC_BR_DownloadCamProfileObj_0.Axis = Axis2Obj;
	MC_BR_DownloadCamProfileObj(&MC_BR_DownloadCamProfileObj_0);

	/**********************MC_BR_INITAUTDATA************************/
	MC_BR_InitAutData_0.Slave = Axis2Obj;
	MC_BR_InitAutData(&MC_BR_InitAutData_0);

	/********************** MC_AUTCONTROL *************************/
	MC_BR_AutControl_0.Slave = Axis2Obj;
	MC_BR_AutControl(&MC_BR_AutControl_0);
	
	/************MC_BR_PHASING************/
	MC_BR_Phasing_0.Slave = Axis2Obj;
	MC_BR_Phasing(&MC_BR_Phasing_0);	

	/************************** MC_GEARIN POS***************************/
	MC_GearInPos_0.Master = Axis1Obj;  /*Master(virtual) axis*/
	MC_GearInPos_0.Slave = Axis2Obj;  /*Slave(real) axis*/
	MC_GearInPos(&MC_GearInPos_0);

	/************************** MC_GEAROUT **************************/
	MC_GearOut_0.Slave = Axis2Obj;  /*Slave(real) axis*/
	MC_GearOut(&MC_GearOut_0);

	/************************** MC_STOP *****************************/
	MC_Stop_0.Axis = Axis2Obj;
	MC_Stop(&MC_Stop_0);

	/**************************MC_HALT*******************************/
	MC_Halt_0.Axis = Axis2Obj;
	MC_Halt(&MC_Halt_0);

	/************************** MC_RESET ****************************/
	MC_Reset_0.Axis = Axis2Obj;
	MC_Reset(&MC_Reset_0);

}


