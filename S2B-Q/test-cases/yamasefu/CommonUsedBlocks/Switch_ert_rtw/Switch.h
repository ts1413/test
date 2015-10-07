/*
 * File: Switch.h
 *
 * Code generated for Simulink model 'Switch'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:26 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Switch_h_
#define RTW_HEADER_Switch_h_
#include <stddef.h>
#ifndef Switch_COMMON_INCLUDES_
# define Switch_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Switch_COMMON_INCLUDES_ */

#include "Switch_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_Switch_T_ {
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Switch_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Switch_T Switch_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Switch_In1_1;            /* '<Root>/In1' */
extern real_T Switch_In2_1;            /* '<Root>/In2' */
extern real_T Switch_In3_1;            /* '<Root>/In3' */
extern real_T Switch_Switch_1;         /* '<Root>/Switch' */

/* Model entry point functions */
extern void Switch_initialize(void);
extern void Switch_step(void);
extern void Switch_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Switch_T *const Switch_M;

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
 * '<Root>' : 'Switch'
 */
#endif                                 /* RTW_HEADER_Switch_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
