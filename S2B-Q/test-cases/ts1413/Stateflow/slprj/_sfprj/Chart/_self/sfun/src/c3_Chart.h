#ifndef __c3_Chart_h__
#define __c3_Chart_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_ChartInstanceStruct
#define typedef_SFc3_ChartInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_False;
  uint8_T c3_tp_True;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_Chart;
  uint8_T c3_is_c3_Chart;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_ChartInstanceStruct;

#endif                                 /*typedef_SFc3_ChartInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Chart_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Chart_get_check_sum(mxArray *plhs[]);
extern void c3_Chart_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
