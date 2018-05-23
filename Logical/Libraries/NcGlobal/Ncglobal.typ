TYPE
	NCDA_DATMO_typ : STRUCT
		name	: ARRAY[0..11] OF USINT ;
		type	: USINT ;
		mem_type	: USINT ;
	END_STRUCT;
	NCDA_MDDIR_typ : STRUCT
		count	: UINT ;
		free_ram	: UDINT ;
		free_prom	: UDINT ;
		data_modul	: ARRAY[0..99] OF NCDA_DATMO_typ ;
	END_STRUCT;
	NCDA_TPREC_typ : STRUCT
		length	: REAL ;
		radius	: REAL ;
		offset	: ARRAY[0..2] OF REAL ;
	END_STRUCT;
	NCDA_TPTAB_typ : STRUCT
		record_cnt	: UINT ;
		startindex	: UINT ;
		record	: ARRAY[0..254] OF NCDA_TPREC_typ ;
	END_STRUCT;
	NCDA_RPTAB_typ : STRUCT
		r_par_cnt	: UINT ;
		startindex	: UINT ;
		r_par	: ARRAY[0..999] OF REAL ;
	END_STRUCT;
	NCDA_ZPREC_typ : STRUCT
		offset	: ARRAY[0..2] OF REAL ;
	END_STRUCT;
	NCDA_ZPTAB_typ : STRUCT
		record_cnt	: UINT ;
		startindex	: UINT ;
		record	: ARRAY[0..199] OF NCDA_ZPREC_typ ;
	END_STRUCT;
END_TYPE