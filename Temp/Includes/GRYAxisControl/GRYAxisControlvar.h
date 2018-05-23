/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1506063276_2_
#define _BUR_1506063276_2_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_LOCAL struct MC_BR_CyclicRead MC_BR_CyclicRead_0;
_LOCAL struct MC_SetOverride MC_SetOverride_0;
_LOCAL struct MC_GearOut MC_GearOut_0;
_LOCAL struct MC_GearInPos MC_GearInPos_0;
_LOCAL float ShiftFactor;
_LOCAL struct MC_BR_Phasing MC_BR_Phasing_0;
_LOCAL float SlaveFactor;
_LOCAL struct MC_BR_DownloadCamProfileObj MC_BR_DownloadCamProfileObj_0;
_LOCAL struct MC_Halt MC_Halt_0;
_LOCAL struct MC_BR_ReadDriveStatus MC_BR_ReadDriveStatus_0;
_LOCAL struct MC_ReadActualVelocity MC_ReadActualVelocity_0;
_LOCAL struct MC_ReadActualPosition MC_ReadActualPosition_0;
_LOCAL struct MC_ReadStatus MC_ReadStatus_0;
_LOCAL struct MC_Reset MC_Reset_0;
_LOCAL struct MC_ReadAxisError MC_ReadAxisError_0;
_LOCAL struct MC_BR_AutControl MC_BR_AutControl_0;
_LOCAL struct MC_BR_InitAutData MC_BR_InitAutData_0;
_LOCAL struct MC_MoveAdditive MC_MoveAdditive_0;
_LOCAL struct MC_MoveAbsolute MC_MoveAbsolute_0;
_LOCAL struct MC_MoveVelocity MC_MoveVelocity_0;
_LOCAL struct MC_Stop MC_Stop_0;
_LOCAL struct MC_Home MC_Home_0;
_LOCAL struct MC_Power MC_Power_0;
_LOCAL struct MC_AUTDATA_TYP AutData;
_LOCAL unsigned char AxisStep;
_LOCAL unsigned long Axis2Obj;
_LOCAL unsigned long Axis1Obj;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/GRYAxisControl/GRYAxisControl.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Acp10_MC/acp10_mc.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1506063276_2_ */

