/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASEPL_
#define _ASEPL_
#ifdef __cplusplus
extern "C" {
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define ERR_ASEPL_BASE 31340U
 #define ERR_ASEPL_CN_ONLY 31343U
 #define ERR_ASEPL_MN_ONLY 31342U
 #define ERR_ASEPL_WRONG_DEVICE 31341U
 #define ERR_ASEPL_ACCESS_FAILED 31344U
 #define ERR_ASEPL_NOT_IMPLEMENTED 31399U
#else
 _IEC_CONST unsigned short ERR_ASEPL_BASE = 31340U;
 _IEC_CONST unsigned short ERR_ASEPL_CN_ONLY = 31343U;
 _IEC_CONST unsigned short ERR_ASEPL_MN_ONLY = 31342U;
 _IEC_CONST unsigned short ERR_ASEPL_WRONG_DEVICE = 31341U;
 _IEC_CONST unsigned short ERR_ASEPL_ACCESS_FAILED = 31344U;
 _IEC_CONST unsigned short ERR_ASEPL_NOT_IMPLEMENTED = 31399U;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct EPL_I_TYPE
{	unsigned long init;
	unsigned long hdl;
	unsigned long st;
	unsigned long errInfo;
	unsigned long size;
	unsigned char bus;
	unsigned char sl;
	unsigned char ss;
	unsigned char if_;
	unsigned char nd;
	unsigned long tid;
} EPL_I_TYPE;

typedef struct EplSDORead
{
	/* VAR_INPUT (analog) */
	plcstring (*pDevice);
	unsigned char node;
	unsigned short index;
	unsigned char subindex;
	unsigned long pData;
	unsigned long datalen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long errorinfo;
	unsigned long readlen;
	/* VAR (analog) */
	struct EPL_I_TYPE intern;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EplSDORead_typ;

typedef struct EplSDOWrite
{
	/* VAR_INPUT (analog) */
	plcstring (*pDevice);
	unsigned char node;
	unsigned short index;
	unsigned char subindex;
	unsigned long pData;
	unsigned long datalen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long errorinfo;
	/* VAR (analog) */
	struct EPL_I_TYPE intern;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EplSDOWrite_typ;

typedef struct EplGetLocalNodeID
{
	/* VAR_INPUT (analog) */
	plcstring (*pDevice);
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char nodeid;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EplGetLocalNodeID_typ;



/* Prototyping of functions and function blocks */
void EplSDORead(struct EplSDORead* inst);
void EplSDOWrite(struct EplSDOWrite* inst);
void EplGetLocalNodeID(struct EplGetLocalNodeID* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASEPL_ */

