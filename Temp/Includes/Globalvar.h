/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1507557600_1_
#define _BUR_1507557600_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_GLOBAL plcbit GRXHomeOk;
_GLOBAL plcbit GRZHomeOk;
_GLOBAL plcbit GC1HomeOk;
_GLOBAL plcbit GC2HomeOk;
_GLOBAL plcbit GZ1HomeOk;
_GLOBAL plcbit GX3HomeOk;
_GLOBAL plcbit GX2HomeOk;
_GLOBAL plcbit GX1HomeOk;
_GLOBAL unsigned long Sifre_Temp;
_GLOBAL unsigned long Sifre_Temp_Screen;
_GLOBAL plcbit Sifre_Sistem_Giris;
_GLOBAL unsigned long Sifre_Sistem;
_GLOBAL plcbit Sifre_Error;
_GLOBAL plcbit Sifre_Ayarlar_Giris;
_GLOBAL plcstring user_message[41];
_GLOBAL unsigned long Sifre_Ayarlar;
_GLOBAL plcstring Passwordler[1];
_GLOBAL unsigned long service_password;
_GLOBAL unsigned char Screen;
_GLOBAL plcstring programname[10];
_GLOBAL plcstring prgname[10];
_GLOBAL struct parametreler_typ Parametreler_0;
_GLOBAL unsigned long operator_password;
_GLOBAL struct automat_typ Power2Axis;
_GLOBAL struct ACP10AXIS_typ PowerSp2;
_GLOBAL struct automat_typ Power1Axis;
_GLOBAL struct ACP10AXIS_typ PowerSp1;
_GLOBAL struct ACP10AXIS_typ GRY_Axis;
_GLOBAL struct automat_typ GRYAxis;
_GLOBAL struct automat_typ GRZAxis;
_GLOBAL struct ACP10AXIS_typ GRZ_Axis;
_GLOBAL struct automat_typ GRXAxis;
_GLOBAL struct ACP10AXIS_typ GRX_Axis;
_GLOBAL struct automat_typ GC2Axis;
_GLOBAL struct ACP10AXIS_typ GC2_Axis;
_GLOBAL struct automat_typ GC1Axis;
_GLOBAL struct ACP10AXIS_typ GC1_Axis;
_GLOBAL struct automat_typ GZ1Axis;
_GLOBAL struct ACP10AXIS_typ GZ1_Axis;
_GLOBAL struct automat_typ GX3Axis;
_GLOBAL struct ACP10AXIS_typ GX3_Axis;
_GLOBAL struct automat_typ GX2Axis;
_GLOBAL struct ACP10AXIS_typ GX2_Axis;
_GLOBAL struct automat_typ GX1Axis;
_GLOBAL struct ACP10AXIS_typ GX1_Axis;
_GLOBAL struct digitaloutput_typ DQ;
_GLOBAL struct digitalinput_typ DI;
_GLOBAL plcbit alarmbits[64];
_GLOBAL unsigned short admin_status_group2;
_GLOBAL unsigned short admin_status_group;
_GLOBAL unsigned long admin_password;
_GLOBAL struct retain_typ Retain;
_GLOBAL struct actual_pos_typ Actual_Pos;
_GLOBAL struct EksenHizlari_typ Eksen_Hizlari;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1507557600_1_ */

