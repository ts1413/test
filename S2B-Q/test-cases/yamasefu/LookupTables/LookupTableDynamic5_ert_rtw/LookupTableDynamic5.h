/*
 * File: LookupTableDynamic5.h
 *
 * Code generated for Simulink model 'LookupTableDynamic5'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:57:29 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LookupTableDynamic5_h_
#define RTW_HEADER_LookupTableDynamic5_h_
#include <stddef.h>
#ifndef LookupTableDynamic5_COMMON_INCLUDES_
# define LookupTableDynamic5_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LookupTableDynamic5_COMMON_INCLUDES_ */

#include "LookupTableDynamic5_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_LookupTableDynamic5_T_ {
  real_T Constant_Value[3];            /* Expression: [1,2,3]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value[3];           /* Expression: [10,20,30]
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LookupTableDynamic5_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_LookupTableDynamic5_T LookupTableDynamic5_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T LookupTableDynamic5_In1_1;/* '<Root>/In1' */
extern real_T LookupTableDynamic5_Constant_1[3];/* '<Root>/Constant' */
extern real_T LookupTableDynamic5_Constant1_1[3];/* '<Root>/Constant1' */
extern real_T LookupTableDynamic5_LookupTableDynamic_1;/* '<Root>/LookupTableDynamic' */

/* Model entry point functions */
extern void LookupTableDynamic5_initialize(void);
extern void LookupTableDynamic5_step(void);
extern void LookupTableDynamic5_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LookupTableDynamic5_T *const LookupTableDynamic5_M;

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
 * '<Root>' : 'LookupTableDynamic5'
 */
#endif                                 /* RTW_HEADER_LookupTableDynamic5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
