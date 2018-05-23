/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1526904333_1_
#define _BUR_1526904333_1_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct EksenHizlari_typ
{	float X_JogVelocity;
	float Y_JogVelocity;
	float Z_JogVelocity;
	float A_JogVelocity;
	float GRX_JogVelocity;
	float GRY_JogVelocity;
	float GRZ_JogVelocity;
	float GC1_JogVelocity;
	float X_PosVelocity;
	float Y_PosVelocity;
	float Z_PosVelocity;
	float A_PosVelocity;
	float GRX_PosVelocity;
	float GRY_PosVelocity;
	float GRZ_PosVelocity;
	float GC1_PosVelocity;
} EksenHizlari_typ;

typedef struct actual_pos_typ
{	float RX_Actual_Pos;
	float RY_Actual_Pos;
	float RZ_Actual_Pos;
	float RA_Actual_Pos;
	float GRX_Actual_Pos;
	float GRZ_Actual_Pos;
	float GC1_Actual_Pos;
	float GC2_Actual_Pos;
	float GRY_Actual_Pos;
} actual_pos_typ;

typedef struct retain_typ
{	float RX_MarkalamaKonumu;
	float RY_MarkalamaKonumu;
	float RZ_MarkalamaKonumu;
	float GRX_KrankKoymaKonumu;
	float GRZ_KrankKoymaKonumu;
	float GRX_KrankAlmaKonumu;
	float GRZ_KrankAlmaKonumu;
	float RA_MarkalamaKonumu;
	signed short Hatch_Adedi;
	float GRX_KrankAlma_Konumu_2;
	float GRZ_KrankAlma_Konumu_2;
	float GRX_KrankKoyma_Konumu_2;
	float GRZ_KrankKoyma_Konumu_2;
	unsigned char Yatay_Sira_Miktari;
	unsigned char Dikey_Sira_Miktari;
	float Yatay_Sira_Araligi;
	float Dikey_Sira_Araligi;
	float GRY_KrankAlma_Konumu;
	float GRX_Position;
	float GRZ_Position;
} retain_typ;

typedef struct automat_axisState_typ
{	plcbit Disabled;
	plcbit StandStill;
	plcbit Homing;
	plcbit Stopping;
	plcbit DiscreteMotion;
	plcbit ContinuousMotion;
	plcbit SynchronizedMotion;
	plcbit ErrorStop;
} automat_axisState_typ;

typedef struct automat_command_typ
{	plcbit Power;
	plcbit Home;
	plcbit MoveAbsolute;
	plcbit MoveAdditive;
	plcbit MoveVelocity;
	plcbit Halt;
	plcbit Stop;
	plcbit MoveJogPos;
	plcbit MoveJogNeg;
	plcbit StartSlave;
	plcbit StopSlave;
	plcbit GearInPos;
	plcbit GearOut;
	plcbit ErrorAcknowledge;
} automat_command_typ;

typedef struct automat_parameter_typ
{	float Position;
	float Distance;
	float Velocity;
	unsigned char Direction;
	float Acceleration;
	float Deceleration;
	float HomePosition;
	unsigned char HomeMode;
	float JogVelocity;
} automat_parameter_typ;

typedef struct automat_status_typ
{	unsigned short ErrorID;
	plcstring ErrorText[4][80];
	float ActPosition;
	float ActVelocity;
	struct MC_DRIVESTATUS_TYP DriveStatus;
} automat_status_typ;

typedef struct axis_speed_typ
{	float Manual_Speed;
	float Acceleration;
	float Deceleration;
	float Automatic_Speed;
	float AccelerationOverride;
	float VelocityOverride;
} axis_speed_typ;

typedef struct automat_typ
{	struct automat_command_typ Command;
	struct automat_parameter_typ Parameter;
	struct automat_status_typ Status;
	struct automat_axisState_typ AxisState;
	struct axis_speed_typ Speed;
} automat_typ;

typedef struct basic_axisState_typ
{	plcbit Disabled;
	plcbit StandStill;
	plcbit Homing;
	plcbit Stopping;
	plcbit DiscreteMotion;
	plcbit ContinuousMotion;
	plcbit SynchronizedMotion;
	plcbit ErrorStop;
} basic_axisState_typ;

typedef struct basic_command_typ
{	plcbit Power;
	plcbit Home;
	plcbit MoveAbsolute;
	plcbit MoveAdditive;
	plcbit MoveVelocity;
	plcbit Halt;
	plcbit Stop;
	plcbit MoveJogPos;
	plcbit MoveJogNeg;
	plcbit ErrorAcknowledge;
} basic_command_typ;

typedef struct basic_parameter_typ
{	float Position;
	float Distance;
	float Velocity;
	unsigned char Direction;
	float Acceleration;
	float Deceleration;
	float HomePosition;
	unsigned char HomeMode;
	float JogVelocity;
} basic_parameter_typ;

typedef struct basic_status_typ
{	unsigned short ErrorID;
	plcstring ErrorText[4][80];
	float ActPosition;
	float ActVelocity;
	struct MC_DRIVESTATUS_TYP DriveStatus;
} basic_status_typ;

typedef struct basic_typ
{	struct basic_command_typ Command;
	struct basic_parameter_typ Parameter;
	struct basic_status_typ Status;
	struct basic_axisState_typ AxisState;
	struct axis_speed_typ Speed;
} basic_typ;

typedef struct Config_setup_typ
{	unsigned char LanguageIndex;
	unsigned char SubnetMask[4];
	unsigned char IPAddress[4];
	unsigned char Broadcast[4];
	unsigned char Gateway[4];
	plcbit CmdWriteFile;
} Config_setup_typ;

typedef struct DateTimeStructure_typ
{	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char wday;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned short millisec;
	unsigned short microsec;
} DateTimeStructure_typ;

typedef struct digitalinput_typ
{	plcbit Acil_Stop;
	plcbit X_PosLimit;
	plcbit X_NegLimit;
	plcbit X_RefSensor;
	plcbit Y_NegLimit;
	plcbit Y_PosLimit;
	plcbit Y_RefSensor;
	plcbit Lazer_IsBitti;
	plcbit GRX_NegLimit;
	plcbit GRX_RefSensor;
	plcbit GRX_PosLimit;
	plcbit GRZ_RefSensor;
	plcbit GRZ_NegLimit;
	plcbit GRZ_PosLimit;
	plcbit GC1_NegLimit;
	plcbit GC1_RefSensor;
	plcbit GC1_PosLimit;
	plcbit GC2_NegLimit;
	plcbit GC2_RefSensor;
	plcbit GC2_PosLimit;
	plcbit GRY_NegLimit;
	plcbit GRY_PosLimit;
	plcbit RAnahtarKonumu1;
	plcbit RAnahtarKonumu2;
	plcbit RAnahtarKonumu3;
	plcbit RAnahtarKonumu4;
	plcbit R_JoySag;
	plcbit R_JoySol;
	plcbit R_Input1;
	plcbit LAnahtarKonumu1;
	plcbit LAnahtarKonumu2;
	plcbit LAnahtarKonumu3;
	plcbit LAnahtarKonumu4;
	plcbit L_JoySag;
	plcbit L_JoySol;
	plcbit L_Input1;
} digitalinput_typ;

typedef struct digitaloutput_typ
{	plcbit Lazer_Start;
	plcbit Lazer_Stop;
	plcbit Lazer_Pointer;
	plcbit Lazer_Hatch;
	plcbit Lazer_Barcode;
	plcbit Konveyor_Ileri;
	plcbit Konveyor_Geri;
	plcbit Kripper_Ac;
	plcbit Kripper_Kapat;
} digitaloutput_typ;

typedef struct hmi_ipconfig
{	plcstring EthernetDevice[11];
	unsigned long OptionVolatile;
	unsigned char TcpIpReady;
	unsigned char IPAddress[4];
	unsigned char SubnetMask[4];
	unsigned char Broadcast[4];
	unsigned char Gateway[4];
	unsigned char EthernetBaudrate;
	unsigned char AddressChanged;
	unsigned char ReadTcpIp;
	unsigned char UpdateTcpIp;
	unsigned short ErrorDuringOperation;
	unsigned char NodeNumber;
	plcbit cmdLanguageUp;
	plcbit cmdLanguageDown;
	unsigned char LanguageIndex;
	unsigned char LockLanguageUpButton;
	struct DateTimeStructure_typ ActualDateTime;
	unsigned char DateTimeChanged;
} hmi_ipconfig;

typedef struct parametreler_typ
{	plcbit X_JogPos;
	plcbit X_JogNeg;
	plcbit Y_JogPos;
	plcbit Y_JogNeg;
	plcbit Z_JogPos;
	plcbit Z_JogNeg;
	plcbit A_JogPos;
	plcbit A_JogNeg;
	plcbit X_HomeStart;
	plcbit Y_HomeStart;
	plcbit A_HomeStart;
	plcbit Z_HomeStart;
	plcbit Alarm_Reset;
	plcbit Lazer_Start;
	plcbit Lazer_Stop;
	plcbit Markalamaya_Git;
	plcbit X_HomeOk;
	plcbit Y_HomeOk;
	plcbit Z_HomeOk;
	plcbit A_HomeOk;
	plcbit GRX_JogPos;
	plcbit GRX_JogNeg;
	plcbit GRX_HomeStart;
	plcbit GRX_HomeOk;
	plcbit GRZ_JogPos;
	plcbit GRZ_JogNeg;
	plcbit GRZ_HomeStart;
	plcbit GRZ_HomeOk;
	plcbit GC1_HomeStart;
	plcbit GC1_HomeOk;
	plcbit GC2_JogPos;
	plcbit GC2_JogNeg;
	plcbit GC2_HomeStart;
	plcbit GC2_HomeOk;
	plcbit GC1_JogPos;
	plcbit GC1_JogNeg;
	plcbit Krank_Al;
	plcbit Krank_Koy;
	plcbit Konveyor_Ileri_Buton;
	plcbit Konveyor_Geri_Buton;
	plcbit Markalama_Ok;
	plcbit GRY_HomeStart;
	plcbit GRY_HomeOk;
	plcbit GRY_JogNeg;
	plcbit GRY_JogPos;
	plcbit Markalama_Start;
	plcbit Kripper_Ac;
	plcbit Kripper_Kapat;
	plcbit Markalama_Ok_Delphi;
} parametreler_typ;

typedef struct time_typ
{	float XStationLeft[10];
	float XStationFree[10];
	float ZStationUp[10];
	float ZStationDown[10];
	unsigned short Time[10];
	unsigned short TimeUp[10];
} time_typ;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1526904333_1_ */

