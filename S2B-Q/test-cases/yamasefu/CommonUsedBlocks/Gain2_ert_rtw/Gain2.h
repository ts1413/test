/*
 * File: Gain2.h
 *
 * Code generated for Simulink model 'Gain2'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:54:51 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Gain2_h_
#define RTW_HEADER_Gain2_h_
#include <stddef.h>
#ifndef Gain2_COMMON_INCLUDES_
# define Gain2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Gain2_COMMON_INCLUDES_ */

#include "Gain2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_Gain2_T_ {
  real_T Gain_Gain[2];                 /* Expression: [2,2]
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Gain2_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Gain2_T Gain2_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Gain2_In1_1;             /* '<Root>/In1' */
extern real_T Gain2_VectorConcatenate_1[2];/* '<Root>/VectorConcatenate' */
extern real_T Gain2_Gain_1;            /* '<Root>/Gain' */

/* Model entry point functions */
extern void Gain2_initialize(void);
extern void Gain2_step(void);
extern void Gain2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Gain2_T *const Gain2_M;

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
 * '<Root>' : 'Gain2'
 */
#endif                                 /* RTW_HEADER_Gain2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
