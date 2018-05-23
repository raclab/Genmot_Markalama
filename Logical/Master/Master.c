/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Master
 * File: Master.c
 * Author: Coder
 * Created: September 22, 2013
 ********************************************************************
 * Implementation of program Master
 ********************************************************************/

#include <bur/plctypes.h>
#include "edge.h"
#include "operator.h"



#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
#define W_POWER_ON						0
#define W_START							10 

#define W_XSW_ON						300 // X REF
#define W_XSW_OFF						301

#define W_YSW_ON						310 // Y REF
#define W_YSW_OFF						311

#define W_GRXSW_ON						320 // GRX REF
#define W_GRXSW_OFF						321

#define W_GRZSW_ON						330 // GRZ REF
#define W_GRZSW_OFF						331

#define W_GRYSW_ON						340 // GRY REF
#define W_GRYSW_OFF						350
#define W_GRYSTART_POS					351
#define W_GRYSTART_POSOK				352
#define W_GRYSTART_OK					353

#define W_GC1SW_ON						360
#define W_GC1SW_OFF						361

#define W_GC2SW_ON						370
#define W_GC2SW_OFF						371

#define W_START_MARK					399
#define W_XY_OTO						400 
#define W_XY_OTO_OK 					410
#define W_ZOTO_OK						420
#define W_HATCH_OK						430   /// MARKALAMA ADIMLARI
#define W_BARCODE_OK					440
#define W_ZUP_START						450
#define W_Y_DON							455
#define W_KONV_ILERLE					456
#define W_C_BEKLE	 					460
#define W_PROSES_BITIR					470

#define W_START_AL						497
#define W_AL_X_BASLANGIC				498
#define W_AL_X_BASLANGICOK				499
#define W_AL_Z_IN						500
#define W_AL_Z_OK						510
#define W_AL_VALF						520
#define W_AL_Z_CIK						530
#define W_AL_Z_CIKOK					540
#define W_AL_X_GIT						550   /// KRANK ALMA ADIMLARI
#define W_AL_X_GITOK					560
#define W_AL_Z_KOY						570
#define W_AL_Z_KOYOK					580
#define W_AL_VALF_AC					590
#define W_AL_Z_BITIR					600
#define W_AL_Z_BITIROK					610
#define W_AL_KONV						620
#define W_AL_STEPBITIR					630
#define W_AL_STEPBITIR_2				640

#define W_START_KOY						699
#define W_KOY_KONV_X_BASLANGIC			700
#define W_KOY_KONV_X_BASLANGICOK		710
#define W_KOY_KONV_Z_IN					720
#define W_KOY_KONV_Z_OK					730
#define W_KOY_KONV_VALF_AC				740
#define W_KOY_KONV_Z_CIK				750
#define W_KOY_KONV_Z_CIKOK				760
#define W_KOY_SEPET_X_GIT				770  /// KRANK KOYMA ADIMLARI
#define W_KOY_SEPET_X_GITOK				780
#define W_KOY_SEPET_Z_IN				790
#define W_KOY_SEPET_Z_IN_OK				800
#define W_KOY_SEPET_VALF_AC				810
#define W_KOY_SEPET_Z_BITIR				820
#define W_KOY_SEPET_Z_BITIROK			830
#define W_KOY_KONV_START				840
#define W_KOY_KONV_STARTOK				850

#define W_BASLANGIC_DON					900
#define W_BASLANGIC_DONOK				910

#define W_KC_ILERI 						1000
#define W_MARK_START					1100
#define W_KC_BITIR						1200
	


_LOCAL TON_typ TON_01;      /* instance variable of TON */
_LOCAL TON_typ TON_02;      /* instance variable of TON */
_LOCAL TON_typ TON_03;      /* instance variable of TON */
_LOCAL TON_typ TON_04;      /* instance variable of TON */
_LOCAL TON_typ TON_05;      /* instance variable of TON */
_LOCAL TON_typ TON_06;
_LOCAL TON_typ TON_07;
_LOCAL TON_typ TON_08;
_LOCAL TON_typ TON_09;
_LOCAL TON_typ TON_10;






_LOCAL UINT X_RefStep;
_LOCAL UINT Y_RefStep;
_LOCAL UINT Z_RefStep;
_LOCAL UINT HatchAdedi; // Tek seferde yuzey temizleyemedigi icin
_LOCAL UINT GRX_RefStep;
_LOCAL UINT GRZ_RefStep;
_LOCAL UINT GC1_RefStep;
_LOCAL UINT GC2_RefStep;
_LOCAL UINT GRY_RefStep;

_LOCAL UINT Otomatik_Step;
_LOCAL UINT Krank_Al_Step; // Otomatik Stepler
_LOCAL UINT Krank_Koy_Step;
_LOCAL UINT Krank_Koy_Hazir_Step;
_LOCAL UINT Manuel_Step ;

_LOCAL BOOL X_HomeOk;
_LOCAL BOOL X_HomePos;
_LOCAL BOOL X_HomeNeg;

_LOCAL BOOL Y_HomeOk;
_LOCAL BOOL Y_HomePos;
_LOCAL BOOL Y_HomeNeg;

_LOCAL BOOL Z_HomeOk;   // Z Eksen referansini 1045 uzerinden eksen taskiyla yapar.
_LOCAL BOOL A_HomeOk;

_LOCAL BOOL GRX_HomeOk;
_LOCAL BOOL GRX_HomePos;
_LOCAL BOOL GRX_HomeNeg;

_LOCAL BOOL GRY_HomeOk;
_LOCAL BOOL GRY_HomePos;
_LOCAL BOOL GRY_HomeNeg;

_LOCAL BOOL GRZ_HomeOk;
_LOCAL BOOL GRZ_HomePos;
_LOCAL BOOL GRZ_HomeNeg;

// GC1 Eksen referansini 1045 uzerinden eksen taskiyla yapar.


// GC2 Eksen referansini 1045 uzerinden eksen taskiyla yapar.


_LOCAL BOOL Lazer_Start;
_LOCAL BOOL Lazer_Barcode; /// Otomatik_Step adiminda.
_LOCAL BOOL Lazer_Hatch;


_LOCAL UINT Markalama_Sayici;
_LOCAL UINT Krank_Al_Sayici; // 7 Sefer Islem Yapmak Icin
_LOCAL UINT Krank_Al_Sayici_Yatay;
_LOCAL UINT Krank_Al_Sayici_Dikey;
_LOCAL BOOL Krank_Al_Sepeti_Bos;

_LOCAL UINT Krank_Koy_Sayici;
_LOCAL UINT Krank_Koy_Sayici_Yatay;
_LOCAL UINT Krank_Koy_Sayici_Dikey;


_LOCAL BOOL Krank_Al_Ok ;
_LOCAL BOOL Ilk_Markalama_Ok;
_LOCAL BOOL Markalama_Bitti;
_LOCAL BOOL Krank_Koy_Hazir;
_LOCAL BOOL Krank_Koy_Ok;
_LOCAL BOOL Markalama_Konumunda;

_LOCAL BOOL Pause;
_LOCAL BOOL GRX_Stop_Biti;
_LOCAL BOOL RY_Stop_Biti;
_LOCAL BOOL GRZ_Stop_Biti;
_LOCAL BOOL Krank_Al_Bitti_Biti;
_LOCAL BOOL Krank_Koy_Basladi_Biti;







void _INIT MasterINIT(void)
{
	

}

void _CYCLIC MasterCYCLIC(void)
{
	
	// GR ile belirttigimiz Robot Eksenleri R ile belirttigimiz Lazer Servolari
	
	///////////////////////////////////// POWER ///////////////////////////////////////////////
	Power1Axis.Command.Power = DI.Acil_Stop ;
	GX2Axis.Command.Power = DI.Acil_Stop ; /// X EKSENI ///
	GX3Axis.Command.Power = DI.Acil_Stop ; /// Y EKSENI ///
	GZ1Axis.Command.Power = DI.Acil_Stop ; /// Z EKSENI ///
	GX1Axis.Command.Power = DI.Acil_Stop ; /// A EKSENI ///
	GC1Axis.Command.Power = DI.Acil_Stop ; /// C1 EKSENI ///
	GC2Axis.Command.Power = DI.Acil_Stop ; /// C2 EKSENI ///
	GRZAxis.Command.Power = DI.Acil_Stop ; /// GRZ EKSENI ///
	GRXAxis.Command.Power = DI.Acil_Stop ; /// GRX EKSENI ///
	GRYAxis.Command.Power = DI.Acil_Stop ; /// GRY EKSENI ///
	
	
	//////////////////////////////// ERROR ID /////////////////////////////////////////////
	if (GX2Axis.Status.ErrorID != 0)
		{	
		GX2Axis.Command.MoveJogPos = 0;
		GX2Axis.Command.MoveJogNeg = 0;
		Parametreler_0.X_JogPos = 0;
		Parametreler_0.X_JogNeg = 0;
		Parametreler_0.X_HomeStart = 0;				/// X Ekseni
		X_HomePos = 0;
		X_HomeNeg = 0;
		X_HomeOk = 0;
		GX2Axis.Command.MoveAbsolute = 0;
		GX2Axis.Command.ErrorAcknowledge = 1;

	}
	
	if (GX3Axis.Status.ErrorID != 0 )
		{
		GX3Axis.Command.MoveJogPos = 0;
		GX3Axis.Command.MoveJogNeg = 0;
		Parametreler_0.Y_JogPos = 0;
		Parametreler_0.Y_JogNeg = 0;				//// Y EKSENI
		Parametreler_0.Y_HomeStart = 0;
		Y_HomePos = 0;
		Y_HomeNeg = 0;
		Y_HomeOk = 0;
		GX3Axis.Command.MoveAbsolute = 0;
		GX3Axis.Command.ErrorAcknowledge = 1;
	}
	
	if (GZ1Axis.Status.ErrorID != 0)
		{
		GZ1Axis.Command.MoveJogPos = 0;
		GZ1Axis.Command.MoveJogNeg = 0;
		GZ1Axis.Command.Home = 0;					//// Z EKSENI
		Parametreler_0.Z_HomeStart = 0 ;
		Z_HomeOk = 0;
		GZ1Axis.Command.MoveAbsolute = 0;
		GZ1Axis.Command.ErrorAcknowledge = 1;
	}
	
	if (GX1Axis.Status.ErrorID != 0)
		{
		GX1Axis.Command.MoveJogPos = 0;
		GX1Axis.Command.MoveJogNeg = 0;				/// A EKSENI
		Parametreler_0.A_HomeStart = 0;
		GX1Axis.Command.ErrorAcknowledge = 1;
	}
	
	if ((GC1Axis.Status.ErrorID != 0) || (GC2Axis.Status.ErrorID != 0))
		{
		GC1Axis.Command.MoveJogPos = 0;
		GC1Axis.Command.MoveJogNeg = 0;
		GC1Axis.Command.Home = 0;
		Parametreler_0.GC1_JogPos = 0;			/// GC1 EKSENI
		Parametreler_0.GC1_JogNeg = 0;
		Parametreler_0.GC1_HomeStart = 0;
		GC1Axis.Command.MoveAbsolute = 0;
		Parametreler_0.GC1_HomeOk = 0;
		
		GC2Axis.Command.MoveJogPos = 0;
		GC2Axis.Command.MoveJogNeg = 0;
		GC2Axis.Command.Home = 0;
		Parametreler_0.GC2_JogPos = 0;			/// GC2 EKSENI
		Parametreler_0.GC2_JogNeg = 0;
		Parametreler_0.GC2_HomeStart = 0;
		GC2Axis.Command.MoveAbsolute = 0;
		
		Parametreler_0.GC2_HomeOk = 0;
		GC1Axis.Command.ErrorAcknowledge = 1;
		GC2Axis.Command.ErrorAcknowledge = 1;
	}
	
	if ((GRXAxis.Status.ErrorID != 0) || (GRXAxis.Command.Stop))
		{
		GRXAxis.Command.MoveJogNeg = 0;
		GRXAxis.Command.MoveJogPos = 0;
		GRX_RefStep = 0;
		GRX_HomePos = 0;						/// GRX EKSENI
		GRX_HomeNeg = 0;
		GRX_HomeOk = 0;
		Parametreler_0.GRX_JogNeg = 0;
		Parametreler_0.GRX_JogPos = 0;
		Parametreler_0.GRX_HomeStart = 0;
		GRXAxis.Command.MoveAbsolute = 0;
		GRXAxis.Command.ErrorAcknowledge = 1;
	}
	
	if ((GRYAxis.Status.ErrorID != 0) || (GRYAxis.Command.Stop))
		{
		GRYAxis.Command.MoveJogNeg = 0;
		GRYAxis.Command.MoveJogPos = 0;
		GRY_RefStep = 0;
		GRY_HomePos = 0;						/// GRY EKSENI
		GRY_HomeNeg = 0;
		GRY_HomeOk = 0;
		Parametreler_0.GRY_JogNeg = 0;
		Parametreler_0.GRY_JogPos = 0;
		Parametreler_0.GRY_HomeStart = 0;		
		GRYAxis.Command.MoveAbsolute = 0;
		Parametreler_0.GRY_HomeOk = 0;
		GRYAxis.Command.ErrorAcknowledge = 1;
	}
	
	if ((GRZAxis.Status.ErrorID != 0) || (GRZAxis.Command.Stop))
		{
		GRZAxis.Command.MoveJogNeg = 0;
		GRZAxis.Command.MoveJogPos = 0;
		GRZ_RefStep = 0;
		GRZ_HomePos = 0;						/// GRZ EKSENI
		GRZ_HomeNeg = 0;
		GRZ_HomeOk = 0;
		Parametreler_0.GRZ_JogNeg = 0;
		Parametreler_0.GRZ_JogPos = 0;
		Parametreler_0.GRZ_HomeStart = 0;		
		GRZAxis.Command.MoveAbsolute = 0;
		GRZAxis.Command.ErrorAcknowledge = 1;
		}
	
	
	////////////////////////////////////////////////////////
	
	if (!GC1Axis.Command.Power || !GC2Axis.Command.Power || !GC1Axis.Status.DriveStatus.HomingOk || !GC2Axis.Status.DriveStatus.HomingOk)
	{
		GC2Axis.Command.GearInPos = 0;
	}
	if (!GC2Axis.AxisState.SynchronizedMotion && GC1Axis.Status.DriveStatus.HomingOk && GC2Axis.Status.DriveStatus.HomingOk)
	{
		GC2Axis.Command.GearInPos = 1;	
	}
	
	
	
	
	////////////////////////////////// ALARM RESET ////////////////////////////////////////////
	
	GX2Axis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// X EKSENI ///
	GX3Axis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// Y EKSENI ///
	GZ1Axis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// Z EKSENI ///
	GX1Axis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// A EKSENI ///
	GC1Axis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// C1 EKSENI ///
	GC2Axis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// C2 EKSENI ///
	GRXAxis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// XR EKSENI ///
	GRZAxis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// ZR EKSENI ///
	GRYAxis.Command.ErrorAcknowledge = Parametreler_0.Alarm_Reset ; /// GRY EKSENI
	
	if (GRXAxis.Command.ErrorAcknowledge)
	{GRXAxis.Command.Stop = 0;}
	
	if (Parametreler_0.Alarm_Reset) {Parametreler_0.Alarm_Reset = 0 ;}   ///Delphide Set Kalmasin diye
	
	////////////////////////////////// HOME OK ///////////////////////////////////////////////
	
	Parametreler_0.X_HomeOk = X_HomeOk ;
	Parametreler_0.Y_HomeOk = Y_HomeOk ;
	Parametreler_0.Z_HomeOk = Z_HomeOk ;
	Parametreler_0.A_HomeOk = A_HomeOk ;
	Parametreler_0.GRX_HomeOk = GRX_HomeOk ;
	Parametreler_0.GRY_HomeOk = GRY_HomeOk ;
	Parametreler_0.GRZ_HomeOk = GRZ_HomeOk ;
	Parametreler_0.GC1_HomeOk = GC1Axis.Status.DriveStatus.HomingOk;
	Parametreler_0.GC2_HomeOk = GC2Axis.Status.DriveStatus.HomingOk;
	
	//////////////////////////////////// TIMERLAR /////////////////////////////////////////////
	
	TON (&TON_01) ;
	TON_01.PT = 2000 ;
	TON (&TON_02) ;
	TON_02.PT = 200 ;
	TON(&TON_03) ;
	TON_03.PT = 200 ;
	TON(&TON_04) ;
	TON_04.PT = 1000 ;  // KRANK AL 
	TON(&TON_05) ;
	TON_05.PT = 1000 ; // KRANK AL
	TON(&TON_06) ;
	TON_06.PT = 1000 ; // KRANK KOY
	TON(&TON_07) ;
	TON_07.PT = 1000 ; // KRANK KOY
	TON(&TON_08);
	TON_08.PT = 1000;	// GRY REF SONRASI GECIKME
	
	
	if (TON_01.Q) {TON_01.IN = 0;}
	if (TON_02.Q) {TON_02.IN = 0;}
	if (TON_03.Q) {TON_03.IN = 0;}
	if (TON_04.Q) {TON_04.IN = 0;}
	if (TON_05.Q) {TON_05.IN = 0;}
	//	if (TON_06.Q) {TON_06.IN = 0;}
	//	if (TON_07.Q) {TON_07.IN = 0;}
	if (TON_08.Q) {TON_08.IN = 0;}
	
	//////////////////// AKTIF POS LARI EKRANDA GOSTERME (mm cinsinden) ///////////////////////
	
	Actual_Pos.RX_Actual_Pos = GX2Axis.Status.ActPosition / 40 ;    /// 10bin git dedik 250mm gitti 
	Actual_Pos.RY_Actual_Pos = GX3Axis.Status.ActPosition / 55.5555556 ; /// 10 bin git dedik 180mm gitti
	Actual_Pos.RZ_Actual_Pos = GZ1Axis.Status.ActPosition / 250 ;	/// 5bin git dedik 20 mm gitti 
	Actual_Pos.GRX_Actual_Pos = GRXAxis.Status.ActPosition / 289.046272 ; /// 10 bin git dedik 33 mm gitti  */ 291.936708
	Actual_Pos.GRY_Actual_Pos = GRYAxis.Status.ActPosition / 1000 ;	/// 100 bin git dedik 100mm gitti
	Actual_Pos.GRZ_Actual_Pos = GRZAxis.Status.ActPosition / 451.167836 ; /// 10 bin git dedik 19 mm gitti 457.935354
	Actual_Pos.GC1_Actual_Pos = GC1Axis.Status.ActPosition / 8.3333333; /// Bin git dedik 120 mm gitti
	Actual_Pos.GC2_Actual_Pos = GC2Axis.Status.ActPosition / 11.4942529 ; /// Bin git dedik 87 mm gitti
	
	
	///////////////// HEDEF POZISYONLARI EKRANDA GOSTERME /////////////////////////
	
	Retain.GRX_Position  = GRXAxis.Parameter.Position / 289.046272 ; 
	Retain.GRZ_Position = GRZAxis.Parameter.Position / 451.167836;
	
	///////////////// EKSEN HIZLARI ////////////////////////////////
	if (X_HomeOk) {GX2Axis.Parameter.JogVelocity = Eksen_Hizlari.X_JogVelocity;} /// 10000
	if (Y_HomeOk) {GX3Axis.Parameter.JogVelocity = Eksen_Hizlari.Y_JogVelocity;} /// 10000
	if (Z_HomeOk) {GZ1Axis.Parameter.JogVelocity = Eksen_Hizlari.Z_JogVelocity;} /// 5000
	GX1Axis.Parameter.JogVelocity = Eksen_Hizlari.A_JogVelocity; /// 5000
	if (GRX_HomeOk) {GRXAxis.Parameter.JogVelocity = Eksen_Hizlari.GRX_JogVelocity;} /// 20000
	if (GRY_HomeOk) {GRYAxis.Parameter.JogVelocity = Eksen_Hizlari.GRY_JogVelocity;} /// 10000
	if (GRZ_HomeOk) {GRZAxis.Parameter.JogVelocity = Eksen_Hizlari.GRZ_JogVelocity;} /// 40000
	if (GC1Axis.Status.DriveStatus.HomingOk && GC2Axis.Status.DriveStatus.HomingOk)
	{GC1Axis.Parameter.JogVelocity = Eksen_Hizlari.GC1_JogVelocity;}	///2000}
	
	
	
	GX2Axis.Parameter.Velocity = Eksen_Hizlari.X_PosVelocity; 	/// 10000
	GX3Axis.Parameter.Velocity = Eksen_Hizlari.Y_PosVelocity; 	/// 10000
	GZ1Axis.Parameter.Velocity = Eksen_Hizlari.Z_PosVelocity; 	/// 10000
	GX1Axis.Parameter.Velocity = Eksen_Hizlari.A_PosVelocity;	/// 10000
	GRXAxis.Parameter.Velocity = Eksen_Hizlari.GRX_PosVelocity;	/// 50000
	GRYAxis.Parameter.Velocity = Eksen_Hizlari.GRY_PosVelocity;	/// 10000
	GRZAxis.Parameter.Velocity = Eksen_Hizlari.GRZ_PosVelocity;	/// 40000
	GC1Axis.Parameter.Velocity = Eksen_Hizlari.GC1_PosVelocity;	/// 2000
	
	
	
	
	////////////////////////////////// EKSENLER MANUEL //////////////////////////////////////////
	
	if (GX2Axis.Command.Power) //// X Ekseni
	{
		GX2Axis.Command.MoveJogPos = (Parametreler_0.X_JogPos | X_HomePos | (DI.LAnahtarKonumu1 & DI.L_JoySag)) & !DI.X_PosLimit ;
		GX2Axis.Command.MoveJogNeg = (Parametreler_0.X_JogNeg | X_HomeNeg | (DI.LAnahtarKonumu1 & DI.L_JoySol)) & !DI.X_NegLimit;
	}
	
	if (GX3Axis.Command.Power) /// Y Ekseni
	{
		GX3Axis.Command.MoveJogPos = (Parametreler_0.Y_JogPos | Y_HomePos | (DI.LAnahtarKonumu2 & DI.L_JoySag)) & !DI.Y_PosLimit;
		GX3Axis.Command.MoveJogNeg = (Parametreler_0.Y_JogNeg | Y_HomeNeg | (DI.LAnahtarKonumu2 & DI.L_JoySol)) & !DI.Y_NegLimit;
	}
	
	if (GZ1Axis.Command.Power) /// Z Ekseni
	{
		GZ1Axis.Command.MoveJogPos = Parametreler_0.Z_JogPos | (DI.LAnahtarKonumu3 & DI.L_JoySag);
		GZ1Axis.Command.MoveJogNeg = Parametreler_0.Z_JogNeg | (DI.LAnahtarKonumu3 & DI.L_JoySol);
	}
	
	if (GX1Axis.Command.Power) /// A Ekseni
	{
		GX1Axis.Command.MoveJogPos = Parametreler_0.A_JogPos | (DI.LAnahtarKonumu4 & DI.L_JoySag);
		GX1Axis.Command.MoveJogNeg = Parametreler_0.A_JogNeg | (DI.LAnahtarKonumu4 & DI.L_JoySol);	
	}
	
	if (GRXAxis.Command.Power) //// GRX Ekseni
	{
		GRXAxis.Command.MoveJogPos = (Parametreler_0.GRX_JogPos | GRX_HomePos | (DI.RAnahtarKonumu1 & DI.R_JoySag)) & !DI.GRX_PosLimit;
		GRXAxis.Command.MoveJogNeg = (Parametreler_0.GRX_JogNeg | GRX_HomeNeg | (DI.RAnahtarKonumu1 & DI.R_JoySol)) & !DI.GRX_NegLimit;
	}
	
	if (GRYAxis.Command.Power) //// GRY Ekseni
	{
		GRYAxis.Command.MoveJogPos = (Parametreler_0.GRY_JogPos | GRY_HomePos | (DI.RAnahtarKonumu2 & DI.R_JoySag)) & !DI.GRX_PosLimit;
		GRYAxis.Command.MoveJogNeg = (Parametreler_0.GRY_JogNeg | GRY_HomeNeg | (DI.RAnahtarKonumu2 & DI.R_JoySol)) /* & !DI.GRX_NegLimit*/;
	}
	
	if (GRZAxis.Command.Power) //// GRZ Ekseni
	{
		GRZAxis.Command.MoveJogPos = (Parametreler_0.GRZ_JogPos | GRZ_HomePos | (DI.RAnahtarKonumu3 & DI.R_JoySag)) & !DI.GRZ_PosLimit ;
		GRZAxis.Command.MoveJogNeg = (Parametreler_0.GRZ_JogNeg | GRZ_HomeNeg | (DI.RAnahtarKonumu3 & DI.R_JoySol)) & !DI.GRZ_NegLimit;
	}
	
	if (GC1Axis.Command.Power) //// GC1 Ekseni
	{
	
		GC1Axis.Command.MoveJogPos = Parametreler_0.GC1_JogPos  ;
		GC1Axis.Command.MoveJogNeg = Parametreler_0.GC1_JogNeg ;
	}
	
	if (GC2Axis.Command.Power) //// GC2 Ekseni
	{
		
	
		GC2Axis.Command.MoveJogPos = Parametreler_0.GC2_JogPos  ;
		GC2Axis.Command.MoveJogNeg = Parametreler_0.GC2_JogNeg ;
	}
	
	
	///////////////////////// KONVEYOR KRANK GENISLIGI ICIN ACILMA KAPANMA //////////////////////////////////////	
	
	DQ.Konveyor_Geri = Parametreler_0.Konveyor_Geri_Buton ;	
	DQ.Konveyor_Ileri = Parametreler_0.Konveyor_Ileri_Buton ;
	
	/////////////////////////////////////// KRIPPER ACMA KAPATMA ////////////////////////////////////////////////
	
	DQ.Kripper_Ac = Parametreler_0.Kripper_Ac & !Parametreler_0.Kripper_Kapat;
	DQ.Kripper_Kapat = Parametreler_0.Kripper_Kapat & !Parametreler_0.Kripper_Ac;
	
	/////////////////////////////////////// EKSEN LIMITLERI ILE STOP ////////////////////////////////////////////

	if (((DI.X_NegLimit) || (GX2Axis.Status.ActPosition < -50.0)) && (X_HomeOk)) 	// X Ekseni Limit Switch Ile Stop
	{
		if((!GX2Axis.AxisState.StandStill) && (!GX2Axis.AxisState.Stopping))
		{
			GX2Axis.Command.MoveJogNeg = 0;
		}
	}
	if (DI.X_PosLimit) // X Ekseni Limit Switch Ile Stop
	{
		if((!GX2Axis.AxisState.StandStill) && (!GX2Axis.AxisState.Stopping))
		{
			GX2Axis.Command.MoveJogPos = 0;
		}
	}
	
	if (DI.Y_NegLimit || ((GX3Axis.Status.ActPosition < -3800.0) && (Y_HomeOk)))  // Y Ekseni Limit Switch Ile Stop
	{
		if((!GX3Axis.AxisState.StandStill) && (!GX3Axis.AxisState.Stopping))
		{
			GX3Axis.Command.MoveJogNeg = 0;
		}
	}
	if (DI.Y_PosLimit || ((GRXAxis.Status.ActPosition > 1157.0 * 289.046272) && (GRXAxis.Status.ActPosition <3700.0*289.046272))) // Y Ekseni Limit Switch Ile Stop
	{
		if((!GX3Axis.AxisState.StandStill) && (!GX3Axis.AxisState.Stopping))
		{
			GX3Axis.Command.MoveJogPos = 0;
		}
	}
	
	if ((DI.GRX_NegLimit) || (GRX_Stop_Biti) || (Actual_Pos.GRZ_Actual_Pos < -1000.0)) // GRX EKSENI
	{
		if((!GRXAxis.AxisState.StandStill) && (!GRXAxis.AxisState.Stopping))
		{
			GRXAxis.Command.MoveJogNeg = 0;
		}
	}
	if ((DI.GRX_PosLimit) || (GRX_Stop_Biti)  || (Actual_Pos.GRZ_Actual_Pos < -1000.0)) // GRX EKSENI
	{
		if((!GRXAxis.AxisState.StandStill) && (!GRXAxis.AxisState.Stopping))
		{
			GRXAxis.Command.MoveJogPos = 0;
		}	
	}
	if ((DI.GRY_NegLimit && GRY_HomeOk) || RY_Stop_Biti) // GRY EKSENI
	{
		if((!GRYAxis.AxisState.StandStill) && (!GRYAxis.AxisState.Stopping))
		{
			GRYAxis.Command.MoveJogNeg = 0;
		}	
	}
	if (DI.GRY_PosLimit || RY_Stop_Biti) //GRY EKSENI
	{
		if((!GRYAxis.AxisState.StandStill) && (!GRYAxis.AxisState.Stopping))
		{
			GRYAxis.Command.MoveJogPos = 0;
		}	
	}	
		
	if (DI.GRZ_NegLimit || GRZ_Stop_Biti) // GRZ EKSENI
	{
		if((!GRZAxis.AxisState.StandStill) && (!GRZAxis.AxisState.Stopping))
		{
			GRZAxis.Command.MoveJogNeg = 0;
		}	
	}
	if (DI.GRZ_PosLimit || GRZ_Stop_Biti) //GRZ EKSENI
	{
		if((!GRZAxis.AxisState.StandStill) && (!GRZAxis.AxisState.Stopping))
		{
			GRZAxis.Command.MoveJogPos = 0;
		}	
	}

	
	///////////////////////////////// GRX HAREKETI ICIN GUVENLI MESAFELER //////////////////////////////////////////////
	
	if ((GRXAxis.Status.ActPosition > 1157.0 * 289.046272) && (GRXAxis.Status.ActPosition <3700.0*289.046272) && ((GX3Axis.Status.ActPosition > 10.0 * 55.5555556) || GRZAxis.Status.ActPosition < (-10.0 * 451.167836)))
	{
		GRX_Stop_Biti = 1;
	}
	else
	{
		GRX_Stop_Biti = 0;
	}
	
	//////////////////////////////// RY HAREKETI ICIN GUVENLI MESAFELER ////////////////////////////////////////////////
	
	if((GRXAxis.Status.ActPosition > 1157.0 * 289.046272) && (GRXAxis.Status.ActPosition < 3700.0*289.046272) && (GX3Axis.Status.ActPosition > 10.0 * 55.5555556) && (GX3Axis.Command.MoveJogPos || (GX3Axis.Command.MoveAbsolute && (GX3Axis.Parameter.Position > 0))))
	{
		RY_Stop_Biti = 1;	
	}
	else
	{
		RY_Stop_Biti = 0;
	}
	
	//////////////////////////////////////// GRZ HAREKETI ICIN GUVENLI MESAFELER //////////////////////////////////////
	
	if (((GRXAxis.Status.ActPosition > 1157.0 * 289.046272) && (GRXAxis.Status.ActPosition < 3700.0*289.046272) && (GRZAxis.Command.MoveJogNeg || (GRZAxis.Command.MoveAbsolute && GRZAxis.Parameter.Position < 0.0)))
		|| (GRZ_HomeOk && GRZAxis.Status.ActPosition > 5.0 * 451.167836 && (GRZAxis.Command.MoveJogPos || (GRZAxis.Command.MoveAbsolute && GRZAxis.Parameter.Position > 5.0 * 451.167836) ))
		|| ((GRXAxis.Status.ActPosition > 600.0 * 289.046272) && (GRXAxis.Status.ActPosition < 4999.0*289.046272) && GRZ_HomeOk && (GRZAxis.Status.ActPosition < -955.0 * 451.167836) && (GRZAxis.Command.MoveJogNeg || (GRZAxis.Command.MoveAbsolute && GRZAxis.Parameter.Position < -850.0 * 451.167836))))
	{
		GRZ_Stop_Biti = 1;	
	}
	else
	{
		GRZ_Stop_Biti = 0;
	}
	
	////////////////////////////////////// LAZER ////////////////////////////////////////////////
	
	//	DQ.Lazer_Hatch = Parametreler_0.Lazer_Hatch | Lazer_Hatch; //// JOBID 1 
			
	//	DQ.Lazer_Barcode = Parametreler_0.Lazer_Barcode | Lazer_Barcode;  /// Barcode u yazdirmak icin sic lazer in jobid 3 e baglanmasi lazim
	/// ve in 1 ve in 2 pinlerine enerji gelmesi lazim
	//	DQ.Lazer_Pointer = Parametreler_0.Lazer_Pointer ;
	
	//	if (DQ.Lazer_Hatch | DQ.Lazer_Barcode)
	//	{
	DQ.Lazer_Start = Parametreler_0.Lazer_Start | Lazer_Start;
	DQ.Lazer_Stop = Parametreler_0.Lazer_Stop;
	//	}
	
	if ((DQ.Lazer_Hatch | DQ.Lazer_Barcode) && Parametreler_0.Lazer_Start)
	{
		TON_02.IN = 1;
	}
	
	if (TON_02.Q) { Parametreler_0.Lazer_Start = 0;}
	
	
	if ((DQ.Lazer_Hatch | DQ.Lazer_Barcode) && Parametreler_0.Lazer_Stop)
	{
		TON_03.IN = 1;
	}
	
	if (TON_03.Q) {Parametreler_0.Lazer_Stop = 0;}
	
	
	
	//////////////////////////////////// ACIL STOP //////////////////////////////////////////////
	
	if (!DI.Acil_Stop)		
	{
		GX2Axis.Command.MoveJogPos = 0;
		GX2Axis.Command.MoveJogNeg = 0;
		Parametreler_0.X_JogPos = 0;
		Parametreler_0.X_JogNeg = 0;
		Parametreler_0.X_HomeStart = 0;				/// X Ekseni
		X_HomePos = 0;
		X_HomeNeg = 0;
		X_HomeOk = 0;
		GX2Axis.Command.MoveAbsolute = 0;
		
		GX3Axis.Command.MoveJogPos = 0;
		GX3Axis.Command.MoveJogNeg = 0;
		Parametreler_0.Y_JogPos = 0;
		Parametreler_0.Y_JogNeg = 0;				//// Y EKSENI
		Parametreler_0.Y_HomeStart = 0;
		Y_HomePos = 0;
		Y_HomeNeg = 0;
		Y_HomeOk = 0;
		GX3Axis.Command.MoveAbsolute = 0;
		
		GZ1Axis.Command.MoveJogPos = 0;
		GZ1Axis.Command.MoveJogNeg = 0;
		GZ1Axis.Command.Home = 0;					//// Z EKSENI
		Parametreler_0.Z_HomeStart = 0 ;
		Z_HomeOk = 0;
		GZ1Axis.Command.MoveAbsolute = 0;
		
		GX1Axis.Command.MoveJogPos = 0;
		GX1Axis.Command.MoveJogNeg = 0;				/// A EKSENI
		Parametreler_0.A_HomeStart = 0;
		
		DQ.Lazer_Barcode = 0;
		DQ.Lazer_Hatch = 0;
		DQ.Lazer_Start = 0;
		
		Lazer_Start = 0;
		Lazer_Hatch = 0;
		Lazer_Barcode = 0;
		
		//		Parametreler_0.Lazer_Pointer = 0;
		Parametreler_0.Lazer_Start = 0;
		Parametreler_0.Lazer_Stop = 0;
		//		Parametreler_0.Lazer_Hatch = 0;
		//		Parametreler_0.Lazer_Barcode = 0;
		
		Otomatik_Step = 0;
		X_RefStep = 0;
		Y_RefStep = 0;
		
		GRXAxis.Command.MoveJogNeg = 0;
		GRXAxis.Command.MoveJogPos = 0;
		GRX_RefStep = 0;
		GRX_HomePos = 0;						/// GRX EKSENI
		GRX_HomeNeg = 0;
		GRX_HomeOk = 0;
		Parametreler_0.GRX_JogNeg = 0;
		Parametreler_0.GRX_JogPos = 0;
		Parametreler_0.GRX_HomeStart = 0;
		GRXAxis.Command.MoveAbsolute = 0;
		
		
		GRYAxis.Command.MoveJogNeg = 0;
		GRYAxis.Command.MoveJogPos = 0;
		GRY_RefStep = 0;
		GRY_HomePos = 0;						/// GRY EKSENI
		GRY_HomeNeg = 0;
		GRY_HomeOk = 0;
		Parametreler_0.GRY_JogNeg = 0;
		Parametreler_0.GRY_JogPos = 0;
		Parametreler_0.GRY_HomeStart = 0 ;		
		GRYAxis.Command.MoveAbsolute = 0;
		Parametreler_0.GRY_HomeOk = 0;
		
		
		GRZAxis.Command.MoveJogNeg = 0;
		GRZAxis.Command.MoveJogPos = 0;
		GRZ_RefStep = 0;
		GRZ_HomePos = 0;						/// GRZ EKSENI
		GRZ_HomeNeg = 0;
		GRZ_HomeOk = 0;
		Parametreler_0.GRZ_JogNeg = 0;
		Parametreler_0.GRZ_JogPos = 0;
		Parametreler_0.GRZ_HomeStart = 0 ;		
		GRZAxis.Command.MoveAbsolute = 0;	
		
		
		GC1Axis.Command.MoveJogPos = 0;
		GC1Axis.Command.MoveJogNeg = 0;
		GC1Axis.Command.Home = 0;
		Parametreler_0.GC1_JogPos = 0;			/// GC1 EKSENI
		Parametreler_0.GC1_JogNeg = 0;
		Parametreler_0.GC1_HomeStart = 0;
		GC1Axis.Command.MoveAbsolute = 0;
		Parametreler_0.GC1_HomeOk = 0;
		
		GC2Axis.Command.MoveJogPos = 0;
		GC2Axis.Command.MoveJogNeg = 0;
		GC2Axis.Command.Home = 0;
		Parametreler_0.GC2_JogPos = 0;			/// GC2 EKSENI
		Parametreler_0.GC2_JogNeg = 0;
		Parametreler_0.GC2_HomeStart = 0;
		GC2Axis.Command.MoveAbsolute = 0;
		
		Parametreler_0.GC2_HomeOk = 0;
		
		Krank_Al_Step = 0;		
		Krank_Koy_Step = 0;		
		Markalama_Bitti = 0 ;
		Krank_Al_Sayici = 0 ;
		Krank_Al_Sayici_Yatay = 0;
		Krank_Al_Sayici_Dikey = 0;
		Krank_Koy_Sayici = 0;
		Krank_Koy_Sayici_Yatay = 0;
		Krank_Koy_Sayici_Dikey = 0;
		
		
		Parametreler_0.Konveyor_Geri_Buton = 0 ;
		Parametreler_0.Konveyor_Ileri_Buton = 0;
		DQ.Konveyor_Geri = 0;
		DQ.Konveyor_Ileri = 0;
		
		Markalama_Konumunda = 0;
		Parametreler_0.Markalama_Start = 0;
		Krank_Al_Bitti_Biti = 0;
		Krank_Koy_Basladi_Biti = 0;
		
		
		DQ.Lazer_Start = 0;
		
	}
	
	
	
	////////////////////////////////// X EKSENI HOME ////////////////////////////////////////////	
	
	switch (X_RefStep)
	{
		case W_POWER_ON: //0
			
			if (DI.Acil_Stop)
			{
				X_RefStep = W_START;
			}
			
			break;
		case W_START: //10
		
			if (Parametreler_0.X_HomeStart)			
			{
				GX2Axis.Parameter.JogVelocity = 5000;
				Parametreler_0.X_HomeStart = 0;
				X_HomeNeg = 1;
				X_HomeOk = 0;
				GX2Axis.Command.Home = 0;
				// GX2Axis.Speed.VelocityOverride = 0.2;
				X_RefStep = W_XSW_ON;
			}
			
			break;
		
		case W_XSW_ON: //300
		
			if (DI.X_NegLimit)
			{
				X_HomeNeg = 0;
				
				if(GX2Axis.AxisState.StandStill)
				{
					GX2Axis.Parameter.JogVelocity = 1000;
					X_HomePos = 1;
					X_RefStep = W_XSW_OFF;
				}
			}
			break;
		
		case W_XSW_OFF: //301
		
			if (!DI.X_NegLimit)
			{
				X_HomePos = 0;
				
				if (GX2Axis.AxisState.StandStill)
				{
					GX2Axis.Parameter.JogVelocity = 10000;
					GX2Axis.Command.Home = 1;
					X_HomeOk = 1;
					GX2_Axis.limit.parameter.neg_sw_end = -100.0;		
					//  GX2Axis.Speed.VelocityOverride = 0.5;
					X_RefStep = W_POWER_ON;
				}		
			}
			
			break;	
	}
	
	////////////////////////////////// Y EKSENI HOME ////////////////////////////////////////////
	
	switch (Y_RefStep)
	{
		case W_POWER_ON: //0
			if (DI.Acil_Stop)
			{
				Y_RefStep = W_START;	
			}
			
			break;
		
		case W_START: //10
			
			if (Parametreler_0.Y_HomeStart)
			{
				GX3Axis.Parameter.JogVelocity = 5000;
				Parametreler_0.Y_HomeStart = 0;
				Y_HomeNeg = 1;
				Y_HomeOk = 0;
				GX3Axis.Command.Home = 0;
				Y_RefStep = W_YSW_ON;
			}
			
			break;
		
		case W_YSW_ON: //310
		
			if (DI.Y_RefSensor)
			{
				Y_HomeNeg = 0;
				
				if (GX3Axis.AxisState.StandStill)
				{
					GX3Axis.Parameter.JogVelocity = 1000;
					Y_HomePos = 1;
					Y_RefStep = W_YSW_OFF;		
				}
			}
			
			break;
				
		case W_YSW_OFF: //311
			
			if (!DI.Y_RefSensor)
			{
				Y_HomePos = 0;
				
				if (GX3Axis.AxisState.StandStill)
				{	
					GX3Axis.Parameter.JogVelocity = 10000;
					GX3Axis.Command.Home = 1;
					Y_HomeOk = 1;
					Y_RefStep = W_POWER_ON;
				}
			}
			
			break;
	}
	
	////////////////////////////////// Z EKSENI HOME ////////////////////////////////////////////

	if (GZ1Axis.Command.Power)
	{
		if (Parametreler_0.Z_HomeStart)
		{
			Parametreler_0.Z_HomeStart = 0;
			GZ1Axis.Command.Home = 1;
			Z_HomeOk = 0;
		}
	
		if (EDGENEG(GZ1Axis.Command.Home))
		{
			Z_HomeOk = 1;			
		}		
	}
	
	////////////////////////////////// A EKSENI HOME ////////////////////////////////////////////
	

	
	///////////////////////////////// GRX EKSENI HOME ///////////////////////////////////////////
	
	switch (GRX_RefStep)
	{
		case W_POWER_ON: //0
			if (DI.Acil_Stop)
			{
				GRX_RefStep = W_START;	
			}
			
			break;
		
		case W_START: //10
			
			if (Parametreler_0.GRX_HomeStart )
			{
				Parametreler_0.GRX_HomeStart = 0;
				GRXAxis.Parameter.JogVelocity = 20000;
				GRX_HomeNeg = 1;
				GRX_HomeOk = 0;
				GRXAxis.Command.Home = 0;
				GRX_RefStep = W_GRXSW_ON;
			}
			
			break;
		
		case W_GRXSW_ON: //320
		
			if (DI.GRX_RefSensor)
			{
				GRX_HomeNeg = 0;
				
				if (GRXAxis.AxisState.StandStill)
				{
					GRXAxis.Parameter.JogVelocity = 5000;
					GRX_HomePos = 1;
					GRX_RefStep = W_GRXSW_OFF;		
				}
			}
			
			break;
				
		case W_GRXSW_OFF: //321
			
			if (!DI.GRX_RefSensor)
			{
				GRX_HomePos = 0;
				
				if (GRXAxis.AxisState.StandStill)
				{		
					GRXAxis.Command.Home = 1;
					GRXAxis.Parameter.JogVelocity = 40000;
					GRX_HomeOk = 1;
					GRX_RefStep = W_POWER_ON;
				}
			}
			
			break;
	}
	
	
	////////////////////////////////// GRY EKSENI HOME ////////////////////////////////////////////
	
	switch (GRY_RefStep)
	{
		case W_POWER_ON: //0
			if (DI.Acil_Stop)
			{
				GRY_RefStep = W_START;	
			}
			
			break;
		
		case W_START: //10
			
			if (Parametreler_0.GRY_HomeStart)
			{
				GRYAxis.Parameter.JogVelocity = 10000;
				Parametreler_0.GRY_HomeStart = 0;
				GRY_HomeNeg = 1;
				GRY_HomeOk = 0;
				GRYAxis.Command.Home = 0;
				GRY_RefStep = W_GRYSW_ON;
			}
			
			break;
		
		case W_GRYSW_ON: //340
		
			if (DI.GRY_NegLimit)
			{
				GRY_HomeNeg = 0;
				
				if (GRYAxis.AxisState.StandStill)
				{
					GRYAxis.Parameter.JogVelocity = 2000;
					GRY_HomePos = 1;
					GRY_RefStep = W_GRYSW_OFF;		
				}
			}
			
			break;
				
		case W_GRYSW_OFF: //350
			
			if (!DI.GRY_NegLimit)
			{
				GRY_HomePos = 0;
				
				if (GRYAxis.AxisState.StandStill)
				{
					GRYAxis.Parameter.JogVelocity = 10000;
					GRYAxis.Command.Home = 1;
					GRY_HomeOk = 1;
					TON_08.IN = 1;					
					GRY_RefStep = W_GRYSTART_POS;
				}
			}
			
			break;
		
		case W_GRYSTART_POS:   //351
		
			if (TON_08.Q)
			{
				GRYAxis.Parameter.Position = Retain.GRY_KrankAlma_Konumu * 1000;
				GRYAxis.Command.MoveAbsolute = 1;		
				GRY_RefStep = W_GRYSTART_POSOK;
			}
			break;
		
		case W_GRYSTART_POSOK: //352
		
			if (!GRYAxis.AxisState.StandStill)
			{		
				GRY_RefStep = W_GRYSTART_OK;		
			}
			break;
		
		case W_GRYSTART_OK: //353
		
			if (GRYAxis.AxisState.StandStill)
			{
				GRYAxis.Command.MoveAbsolute = 0;
				GRY_RefStep = W_POWER_ON;		
			}
			
			break;		
	}
	
	
	
	///////////////////////////////// GRZ EKSENI HOME ///////////////////////////////////////////
	
	switch (GRZ_RefStep)
	{
		case W_POWER_ON: //0
			if (DI.Acil_Stop)
			{
				GRZ_RefStep = W_START;	
			}
			
			break;
		
		case W_START: //10
			
			if (Parametreler_0.GRZ_HomeStart )
			{
				GRZAxis.Parameter.JogVelocity = 10000;
				Parametreler_0.GRZ_HomeStart = 0;
				GRZ_HomePos = 1;
				GRZ_HomeOk = 0;
				GRZAxis.Command.Home = 0;
				GRZ_RefStep = W_GRZSW_ON;
			}
			
			break;
		
		case W_GRZSW_ON: //330
		
			if (DI.GRZ_RefSensor)
			{
				GRZ_HomePos = 0;
				
				if (GRZAxis.AxisState.StandStill)
				{
					GRZ_HomeNeg = 1;
					GRZAxis.Parameter.JogVelocity = 1000;
					GRZ_RefStep = W_GRZSW_OFF;		
				}
			}
			
			break;
				
		case W_GRZSW_OFF: //331
			
			if (!DI.GRZ_RefSensor)
			{
				GRZ_HomeNeg = 0;
				
				if (GRZAxis.AxisState.StandStill)
				{
					GRZAxis.Parameter.JogVelocity = 40000;
					GRZAxis.Command.Home = 1;
					GRZ_HomeOk = 1;
					GRZ_RefStep = W_POWER_ON;
				}
			}
			
			break;
	}	
	
	////////////////////////////// GC1 HOME ////////////////////////////////////////////////////
	
	if (GC1Axis.Command.Power)
	{
		if (Parametreler_0.GC1_HomeStart)
		{
			GC2Axis.Command.GearInPos = 0;
			Parametreler_0.GC1_HomeStart = 0;
			Parametreler_0.GC1_HomeOk = 0;
			GC1Axis.Command.Home = 1;
		}
			
	}
	
	
	
	////////////////////////////// GC2 HOME ////////////////////////////////////////////////////
	
	
	if (GC2Axis.Command.Power)
	{
		if (Parametreler_0.GC2_HomeStart)
		{
			GC2Axis.Command.GearInPos = 0;
			Parametreler_0.GC2_HomeStart = 0;
			Parametreler_0.GC2_HomeOk = 0;
			GC2Axis.Command.Home = 1;
		}
	}
		
	////////////////////////////// KRANK AL PROSESI ////////////////////////////////////////////
	
	switch (Krank_Al_Step)
	{
		
		case W_POWER_ON: // 0
		
			if (GRZ_HomeOk & GRX_HomeOk & GC1Axis.Status.DriveStatus.HomingOk & GC2Axis.Status.DriveStatus.HomingOk)
			{	

				Krank_Al_Step = W_START ;	
			}
			else 
				
				Krank_Al_Step = W_POWER_ON;
			
			break;
		
		
		case W_START: // 10
			
			Krank_Al_Step = W_START_AL;
			
			break;
		
			
		case W_START_AL: // 497
			if ((Parametreler_0.Krank_Al) && (GC1Axis.Status.ActPosition == 0.0) && (GC1Axis.AxisState.StandStill))		
			{
				GC1Axis.Command.MoveAbsolute = 0;
				Parametreler_0.Krank_Al = 0;
				Parametreler_0.Kripper_Kapat = 0;
				GRXAxis.Parameter.Position = ((Retain.GRX_KrankAlmaKonumu) + (Krank_Al_Sayici_Yatay * (Retain.Yatay_Sira_Araligi))) * 289.046272;
				GRXAxis.Command.MoveAbsolute = 1;
				Krank_Al_Step = W_AL_X_BASLANGIC;		
			}
			break;
		
		case W_AL_X_BASLANGIC: // 498
			if (!GRXAxis.AxisState.StandStill)
			{
				GRXAxis.Command.MoveAbsolute = 0;
				Krank_Al_Step = W_AL_X_BASLANGICOK;	
			}
			break;
		
		case W_AL_X_BASLANGICOK: // 499
			if (GRXAxis.AxisState.StandStill)	
			{

				Parametreler_0.Kripper_Ac = 1;
				GRZAxis.Parameter.Position = ((Retain.GRZ_KrankAlmaKonumu) + (Krank_Al_Sayici_Dikey * (-Retain.Dikey_Sira_Araligi))) * 451.167836;
				GRZAxis.Command.MoveAbsolute = 1;
				Krank_Al_Step = W_AL_Z_IN;
			}
			
			break;

		case W_AL_Z_IN: // 500
			if (!GRZAxis.AxisState.StandStill)
			{
				Parametreler_0.Kripper_Ac = 0;
				GRZAxis.Command.MoveAbsolute = 0 * 451.167836 ;
				Krank_Al_Step = W_AL_Z_OK;	
			}
			
			break;
		
		case W_AL_Z_OK: // 510
			if (GRZAxis.AxisState.StandStill)		
			{	
				TON_04.IN = 1;
				Parametreler_0.Kripper_Kapat = 1;
				Krank_Al_Step = W_AL_VALF ;	
			}
			
			break;
		
		case W_AL_VALF: // 520
			if (TON_04.Q)
			{
				GRZAxis.Parameter.Position = (-250.0 * 451.167836);
				GRZAxis.Command.MoveAbsolute = 1;
				Krank_Al_Step = W_AL_Z_CIK;	
			}
			
			break;
		
		case W_AL_Z_CIK: // 530
			if (!GRZAxis.AxisState.StandStill)
			{
				GRZAxis.Command.MoveAbsolute = 0;
				Krank_Al_Step = W_AL_Z_CIKOK;	
			}
			
			break;

		case W_AL_Z_CIKOK: // 540
			if (GRZAxis.AxisState.StandStill)
			{
				GRXAxis.Parameter.Position = Retain.GRX_KrankKoymaKonumu * 289.046272 ;
				GRXAxis.Command.MoveAbsolute = 1;
				Krank_Al_Step = W_AL_X_GIT;	
			}
			
			break;
		
		case W_AL_X_GIT: // 550
			if (!GRXAxis.AxisState.StandStill)
			{	
				GRXAxis.Command.MoveAbsolute = 0;
				Krank_Al_Step = W_AL_X_GITOK;	
			}
			
			break;
		
		case W_AL_X_GITOK: // 560		
			if (GRXAxis.AxisState.StandStill)		
			{	
				GRZAxis.Parameter.Position = Retain.GRZ_KrankKoymaKonumu * 451.167836 ;
				GRZAxis.Command.MoveAbsolute = 1;
				Krank_Al_Step = W_AL_Z_KOY;	
			}
			
			break;

		case W_AL_Z_KOY: // 570
			if (!GRZAxis.AxisState.StandStill)		
			{	
				GRZAxis.Command.MoveAbsolute = 0;
				Krank_Al_Step = W_AL_Z_KOYOK;	
			}
			
			break;
	
		case W_AL_Z_KOYOK: // 580
			if (GRZAxis.AxisState.StandStill)	
			{
				Parametreler_0.Kripper_Kapat = 0 ;
				Parametreler_0.Kripper_Ac = 1;
				TON_05.IN = 1;
				Krank_Al_Step = W_AL_VALF_AC;
			}
			
			break;

		case W_AL_VALF_AC: // 590		
			if (TON_05.Q)		
			{
				GRZAxis.Parameter.Position = 0.0 * 451.167836 ;
				GRZAxis.Command.MoveAbsolute = 1;
				Krank_Al_Step = W_AL_Z_BITIR;	
			}
			
			break;

		case W_AL_Z_BITIR: // 600
			if (!GRZAxis.AxisState.StandStill)	
			{	
				Parametreler_0.Kripper_Ac = 0;
				GRZAxis.Command.MoveAbsolute = 0;
				Krank_Al_Sayici  ++ ;	
				Krank_Al_Sayici_Yatay ++;
				Krank_Al_Step = W_AL_Z_BITIROK;	
			}
			
			break;
		

		
		case W_AL_Z_BITIROK: // 610		
			if (GRZAxis.AxisState.StandStill)		
			{	
					
				if (Krank_Al_Sayici_Yatay >= (Retain.Yatay_Sira_Miktari))
				{
					Krank_Al_Sayici_Yatay = 0;
					Krank_Al_Sayici_Dikey ++;
				}
				if (Krank_Al_Sayici >= 9 )
				{
					Krank_Al_Sayici = 0;
					Krank_Al_Sayici_Yatay = 0;
					Krank_Al_Sayici_Dikey = 0;		
				}
				
								
				GC1Axis.Parameter.Velocity = 2000;
				GC1Axis.Parameter.Position = 14500.0;
				GC1Axis.Command.MoveAbsolute = 1;
				Parametreler_0.Markalama_Ok = 0;
				Parametreler_0.Markalamaya_Git = 1;  ////
				Krank_Al_Step = W_AL_KONV;	
			}
			
			break;
		
		case W_AL_KONV: // 620
			if (!GC1Axis.AxisState.StandStill)
			{
				GC1Axis.Command.MoveAbsolute = 0;
				Krank_Al_Step = W_AL_STEPBITIR;	
			}
			
			break;
		
		case W_AL_STEPBITIR: // 630		
			if (GC1Axis.AxisState.StandStill )	
			{			
	//			Parametreler_0.Markalamaya_Git = 1;
				Krank_Al_Step = W_START_AL ;
			}	
			
			break;	
		
	}
	
	
	////////////////////////////// MARKALAMA KONUMUNA GIT ///////////////////////////////////////
	
	switch (Otomatik_Step)
	{
		case W_POWER_ON: ///0
			
			if (X_HomeOk && Y_HomeOk && Z_HomeOk && DI.Acil_Stop)
			{		
				Otomatik_Step = W_START;
			}
		
			break;
		
		case W_START: /// 10
			
			Otomatik_Step = W_START_MARK;
			
			break;
			
			
		case W_START_MARK: // 399			
			if (Parametreler_0.Markalamaya_Git)
			{
				Parametreler_0.Markalamaya_Git = 0;
				Parametreler_0.Markalama_Ok = 0;
				Markalama_Bitti = 0 ;
				if (Retain.RX_MarkalamaKonumu != GX2Axis.Status.ActPosition)
				{
					GX2Axis.Parameter.Position = Retain.RX_MarkalamaKonumu * 40.0 ;  /// Ekranda mm cinsinden gostermek icin  X Ekseni
					GX2Axis.Command.MoveAbsolute = 1;
				}
				GX3Axis.Parameter.Position = Retain.RY_MarkalamaKonumu * 55.5555556 ; /// Ekranda mm cinsinden gostermek icin Y Ekseni
				GX3Axis.Command.MoveAbsolute = 1;
				Otomatik_Step = W_XY_OTO;

			}
			break;
		
		case W_XY_OTO: //400
			
			if ((((!GX2Axis.AxisState.StandStill) && (GX2Axis.Command.MoveAbsolute)) || (!GX2Axis.Command.MoveAbsolute)) && !GX3Axis.AxisState.StandStill)
			{
				GX2Axis.Command.MoveAbsolute = 0;
				GX3Axis.Command.MoveAbsolute = 0;
				Parametreler_0.Markalamaya_Git = 0;
				Otomatik_Step = W_XY_OTO_OK;
			}
			break;   
		
		case W_XY_OTO_OK: //410
		
			if (GX3Axis.AxisState.StandStill && GX2Axis.AxisState.StandStill)
			{
				GZ1Axis.Parameter.Position = Retain.RZ_MarkalamaKonumu * 250.0 ; /// Ekranda mm cinsinden gostermek icin
				GZ1Axis.Command.MoveAbsolute = 1;
				
				if ((!GZ1Axis.AxisState.StandStill) /* && (GZ1Axis.Status.ActPosition <= 50)*/ )
				{
					Otomatik_Step = W_ZOTO_OK; ///////
				}	
			}
			
			break;
			
		case W_ZOTO_OK: //420
							
			if (GZ1Axis.AxisState.StandStill && (GC1Axis.Status.ActPosition == 14500.0) && (GC1Axis.AxisState.StandStill))
			{
				GC1Axis.Command.MoveAbsolute = 0;
				Parametreler_0.Markalama_Start = 1;
				TON_01.IN = 1;

				if (TON_01.Q)
				{						
					if (DI.Lazer_IsBitti)
					{		
						DQ.Lazer_Start = 0;
						Parametreler_0.Markalama_Start = 0;	
						Otomatik_Step = W_ZUP_START;

					}
				}		
			}
	
			break;
		

		case W_ZUP_START: //450			
			if (!DI.Lazer_IsBitti)
			{
				Parametreler_0.Markalama_Ok = 1;
				Parametreler_0.Markalama_Ok_Delphi = 1;
				//		Lazer_Hatch = 0;
				//		Lazer_Barcode = 0;
	//			if ((Krank_Al_Sayici >= 9 )
	//			{
	//				Markalama_Konumunda = 0;
					GZ1Axis.Parameter.Position = 0.0;
					GZ1Axis.Command.MoveAbsolute = 1;
					GX3Axis.Parameter.Position = (0.0 * 55.5555556) ;
					GX3Axis.Command.MoveAbsolute = 1;
					Otomatik_Step = W_Y_DON ;
	//			}
	//			else
	//			{
	//				Otomatik_Step =	W_PROSES_BITIR;
	//			}
					
			}
			break;
		
		case W_Y_DON: //455
			
			if (!GZ1Axis.AxisState.StandStill &&  !GX3Axis.AxisState.StandStill )
			{
				GX3Axis.Command.MoveAbsolute = 0 ;
				GZ1Axis.Command.MoveAbsolute = 0;
				Otomatik_Step = W_PROSES_BITIR;		
			}
			break;
						
		
		case W_PROSES_BITIR: //470
		
			if (GZ1Axis.AxisState.StandStill && GX3Axis.AxisState.StandStill)		
			{
				Markalama_Bitti = 1;
				Parametreler_0.Krank_Koy = 1;
				
				GC1Axis.Parameter.Velocity = 2000;
				GC1Axis.Parameter.Position = 29000;
				GC1Axis.Command.MoveAbsolute = 1;
				
				
				//		Markalama_Sayici ++ ;
			
				//		if (Markalama_Sayici == 1)
				//		{
					
				//			Parametreler_0.Krank_Al = 1;
				//			Otomatik_Step = W_POWER_ON;
				//		}
						
				
				
				//		else
				//		{
				Otomatik_Step = W_POWER_ON;
					
				//		}
			}
			break;
	}
	
	
	
	
	
	


	////////////////////////////////// KRANK KOY PROSESI ///////////////////////////////////////////
		
	switch (Krank_Koy_Step)
	
	{
	
		case W_POWER_ON:   ///  0
		
			if (GRZ_HomeOk & GRX_HomeOk & GC1Axis.Status.DriveStatus.HomingOk & GC2Axis.Status.DriveStatus.HomingOk)
			{	
				//	GRXAxis.Parameter.Velocity = 30000;
				//	GRZAxis.Parameter.Velocity = 30000;
				Krank_Koy_Step = W_START ;
			}
			break;
		
		case W_START: // 10
			
			Krank_Koy_Sayici = 0;
			Krank_Koy_Step = W_START_KOY;
			
			break;
			
		case W_START_KOY: // 699

			if (Parametreler_0.Krank_Koy)
			{
				GRXAxis.Parameter.Position = Retain.GRX_KrankAlma_Konumu_2 * 289.046272;
				GRXAxis.Command.MoveAbsolute = 1;
				Parametreler_0.Krank_Koy = 0;
				Krank_Koy_Step = W_KOY_KONV_X_BASLANGIC ;
			}
			break;
		
		case W_KOY_KONV_X_BASLANGIC: // 700
		
			if (!GRXAxis.AxisState.StandStill)		
			{
				GRXAxis.Command.MoveAbsolute = 0 ;
				Krank_Koy_Step = W_KOY_KONV_X_BASLANGICOK;
			}
			
			break;

		
		case W_KOY_KONV_X_BASLANGICOK: // 710

			if (GRXAxis.AxisState.StandStill && (GC1Axis.Status.ActPosition == 29000) && (GC1Axis.AxisState.StandStill))
			{
				Parametreler_0.Kripper_Ac = 1;
				GC1Axis.Command.MoveAbsolute = 0;			
				GRZAxis.Parameter.Position = Retain.GRZ_KrankAlma_Konumu_2 * 451.167836 ;
				GRZAxis.Command.MoveAbsolute = 1;
				Krank_Koy_Step = W_KOY_KONV_Z_IN ;
			}

			break;
		
		case W_KOY_KONV_Z_IN: //720
		
			
			if (!GRZAxis.AxisState.StandStill)		
			{
				GRZAxis.Command.MoveAbsolute = 0;
					
				Krank_Koy_Step = W_KOY_KONV_Z_OK;	
			}
			
			break;
			
		case W_KOY_KONV_Z_OK:  // 730

			
			if (GRZAxis.AxisState.StandStill)		
			{
				Parametreler_0.Kripper_Ac = 0;
				Parametreler_0.Kripper_Kapat = 1;
				TON_06.IN = 1;	
				Krank_Koy_Step = W_KOY_KONV_VALF_AC ;
			}
			break;
			
		case W_KOY_KONV_VALF_AC: // 740
			
			if (TON_06.Q)
			{
				GRZAxis.Parameter.Position = (-250.0 * 451.167836);
				GRZAxis.Command.MoveAbsolute = 1;
				TON_06.IN = 0;
		
				Krank_Koy_Step = W_KOY_KONV_Z_CIK;
			}
			
			break;
			
		case W_KOY_KONV_Z_CIK: //750			
			if (!GRZAxis.AxisState.StandStill)
			{
				GRZAxis.Command.MoveAbsolute = 0;	
					
				Krank_Koy_Step = W_KOY_KONV_Z_CIKOK;
			}
			break;
			
		case W_KOY_KONV_Z_CIKOK: //760
			
			if (GRZAxis.AxisState.StandStill)		
			{
				GC1Axis.Parameter.Velocity = 2000;
				GC1Axis.Parameter.Position = 0.0;
				GC1Axis.Command.MoveAbsolute = 1;
				GRXAxis.Parameter.Position = (Retain.GRX_KrankKoyma_Konumu_2 + (Krank_Koy_Sayici_Yatay * (Retain.Yatay_Sira_Araligi))) * 289.046272;
				GRXAxis.Command.MoveAbsolute = 1;
				Pause = 0;
				Krank_Koy_Step = W_KOY_SEPET_X_GIT;
			
			}
			break;
			
		case W_KOY_SEPET_X_GIT:			
			if (!GRXAxis.AxisState.StandStill)		
			{
				GRXAxis.Command.MoveAbsolute = 0;
				Krank_Koy_Step = W_KOY_SEPET_X_GITOK;		
			}
			
			break;
			
		case W_KOY_SEPET_X_GITOK: //780
			
			if (GRXAxis.AxisState.StandStill)		
			{
				GRZAxis.Parameter.Position = (Retain.GRZ_KrankKoyma_Konumu_2 + (Krank_Koy_Sayici_Dikey * (Retain.Dikey_Sira_Araligi))) * 451.167836;
				GRZAxis.Command.MoveAbsolute = 1;
				Krank_Koy_Step = W_KOY_SEPET_Z_IN; 		
			}
			break;
			
		case W_KOY_SEPET_Z_IN: // 790

			
			if (!GRZAxis.AxisState.StandStill)
			{
				GRZAxis.Command.MoveAbsolute = 0;	
				Krank_Koy_Step = W_KOY_SEPET_Z_IN_OK;		
			}
			
			break;
			
		case W_KOY_SEPET_Z_IN_OK: //800

			
			if (GRZAxis.AxisState.StandStill)		
			{
				Parametreler_0.Kripper_Kapat = 0;
				Parametreler_0.Kripper_Ac = 1;
				TON_07.IN = 1;	
				Krank_Koy_Step = W_KOY_SEPET_VALF_AC ;
			}
			
			break;
			
		case W_KOY_SEPET_VALF_AC: //810
			
			if (TON_07.Q)		
			{	
				GRZAxis.Parameter.Position = (0.0 * 451.167836) ;
				GRZAxis.Command.MoveAbsolute = 1;
				TON_07.IN = 0;
				Krank_Koy_Step = W_KOY_SEPET_Z_BITIR;
			}
		
			break;
			
		case W_KOY_SEPET_Z_BITIR: //820

			if (!GRZAxis.AxisState.StandStill)	
			{	
				Parametreler_0.Kripper_Ac = 0;
				GRZAxis.Command.MoveAbsolute = 0;
				Krank_Koy_Sayici ++ ;
				Krank_Koy_Sayici_Yatay ++ ;
				Krank_Koy_Step = W_KOY_SEPET_Z_BITIROK;	
			}
			
			break;
			
		case W_KOY_SEPET_Z_BITIROK: // 830
			
			if (GRZAxis.AxisState.StandStill)		
			{
					
				
				if (Krank_Koy_Sayici_Yatay >= Retain.Yatay_Sira_Miktari)
				{
					Krank_Koy_Sayici_Yatay = 0;
					Krank_Koy_Sayici_Dikey ++;
				
				}
				
				if (Krank_Koy_Sayici >= (Retain.Yatay_Sira_Miktari * Retain.Dikey_Sira_Miktari))
				{
					Krank_Koy_Sayici_Dikey = 0;
								
				}
				
				if (Krank_Koy_Sayici < 9 && Parametreler_0.Markalama_Ok)
				{
					Parametreler_0.Krank_Al = 1;
				}
					GRXAxis.Command.MoveAbsolute = 1;
					GRXAxis.Parameter.Position = 0.0;
					Krank_Koy_Step = W_BASLANGIC_DON;
				

			}
			break;
			
		
		case W_BASLANGIC_DON:		//900
			if (!GRXAxis.AxisState.StandStill)
			{
				
				GRXAxis.Command.MoveAbsolute = 0;
				Krank_Koy_Step = W_BASLANGIC_DONOK;
			}
			break;
		
		case W_BASLANGIC_DONOK:		//910
			if (GRXAxis.AxisState.StandStill)	
			{
				if (Krank_Koy_Sayici >= 9)
				{
					Krank_Al_Bitti_Biti = 0;
					Krank_Koy_Basladi_Biti = 0;
					Krank_Koy_Sayici = 0;
					Krank_Koy_Sayici_Yatay = 0;
					Krank_Koy_Sayici_Dikey = 0;
				}
				Krank_Koy_Step = W_START_KOY;
			}		
			break;
	}
	

			


	
	
	
}


