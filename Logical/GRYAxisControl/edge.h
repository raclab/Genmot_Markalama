/*
	edge.h

	Macros for Edgedetection. This macros uses a special feature of the GNU compiler:
	"Statements and Declarations in Expressions" see more details in GNU-Documentation
	So they may not work with other compilers.

	EDGEPOS  return 1 at positive transition of signal, in all other cases 0 is returned
	EDGENEG  return 1 at negative transition of signal, in all other cases 0 is returned
	EDGEPOS  return 1 at positive and negative transition of signal, in all other cases 0 is returned
*/

#ifndef __EDGE_H__
#define __EDGE_H__



#define EDGEPOS(variable) ({static plcbit __oldval=0; plcbit result; \
                            if (variable && !__oldval)               \
                              result=1;                              \
                            else                                     \
                              result=0;                              \
                              __oldval=variable;                     \
                              result;                                \
                           })

#define EDGENEG(variable) ({static plcbit __oldval=0; plcbit result; \
                            if (!variable && __oldval)               \
                              result=1;                              \
                            else                                     \
                              result=0;                              \
                              __oldval=variable;                     \
                              result;                                \
                           })

#define EDGE(variable)    ({static plcbit __oldval=0; plcbit result; \
                            if (variable != __oldval)                \
                              result=1;                              \
                            else                                     \
                              result=0;                              \
                              __oldval=variable;                     \
                              result;                                \
                           })

#endif /*__EDGE_H__*/


