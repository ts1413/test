/*
 * File: Compare_to_Zero.h
 *
 * Code generated for Simulink model 'Compare_to_Zero'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:51:02 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Compare_to_Zero_h_
#define RTW_HEADER_Compare_to_Zero_h_
#include <stddef.h>
#ifndef Compare_to_Zero_COMMON_INCLUDES_
# define Compare_to_Zero_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Compare_to_Zero_COMMON_INCLUDES_ */

#include "Compare_to_Zero_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T Out1;                      /* '<Root>/Out1' */
} ExtY_Compare_to_Zero_T;

/* Parameters (auto storage) */
struct P_Compare_to_Zero_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Compare_to_Zero_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Compare_to_Zero_T Compare_to_Zero_P;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Compare_to_Zero_T Compare_to_Zero_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Compare_to_Zero_In1_1;   /* '<Root>/In1' */

/* Model entry point functions */
extern void Compare_to_Zero_initialize(void);
extern void Compare_to_Zero_step(void);
extern void Compare_to_Zero_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Compare_to_Zero_T *const Compare_to_Zero_M;

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
 * '<Root>' : 'Compare_to_Zero'
 * '<S1>'   : 'Compare_to_Zero/CompareToZero'
 */
#endif                                 /* RTW_HEADER_Compare_to_Zero_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
