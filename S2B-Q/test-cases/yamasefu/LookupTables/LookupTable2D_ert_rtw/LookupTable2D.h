/*
 * File: LookupTable2D.h
 *
 * Code generated for Simulink model 'LookupTable2D'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:57:05 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LookupTable2D_h_
#define RTW_HEADER_LookupTable2D_h_
#include <stddef.h>
#ifndef LookupTable2D_COMMON_INCLUDES_
# define LookupTable2D_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LookupTable2D_COMMON_INCLUDES_ */

#include "LookupTable2D_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_LookupTable2D_T_ {
  real_T _DLookupTable_tableData[9];   /* Expression: [4 5 6;16 19 20;10 18 23]
                                        * Referenced by: '<Root>/2_DLookupTable'
                                        */
  real_T _DLookupTable_bp01Data[3];    /* Expression: [1:3]
                                        * Referenced by: '<Root>/2_DLookupTable'
                                        */
  real_T _DLookupTable_bp02Data[3];    /* Expression: [1:3]
                                        * Referenced by: '<Root>/2_DLookupTable'
                                        */
  uint32_T _DLookupTable_maxIndex[2];  /* Computed Parameter: _DLookupTable_maxIndex
                                        * Referenced by: '<Root>/2_DLookupTable'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LookupTable2D_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_LookupTable2D_T LookupTable2D_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T LookupTable2D_In1_1;     /* '<Root>/In1' */
extern real_T LookupTable2D_In2_1;     /* '<Root>/In2' */
extern real_T LookupTable2D_2_DLookupTable_1;/* '<Root>/2_DLookupTable' */

/* Model entry point functions */
extern void LookupTable2D_initialize(void);
extern void LookupTable2D_step(void);
extern void LookupTable2D_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LookupTable2D_T *const LookupTable2D_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LookupTable2D'
 */
#endif                                 /* RTW_HEADER_LookupTable2D_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
