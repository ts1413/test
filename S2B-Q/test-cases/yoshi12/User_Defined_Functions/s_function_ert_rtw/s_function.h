/*
 * File: s_function.h
 *
 * Code generated for Simulink model 's_function'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:25 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_s_function_h_
#define RTW_HEADER_s_function_h_
#include <stddef.h>
#ifndef s_function_COMMON_INCLUDES_
# define s_function_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* s_function_COMMON_INCLUDES_ */

#include "s_function_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_s_function_T {
  const char_T * volatile errorStatus;
};

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T s_function_In1_1;        /* '<Root>/In1' */
extern real_T s_function_S_Function_1; /* '<Root>/S_Function' */

/* Model entry point functions */
extern void s_function_initialize(void);
extern void s_function_step(void);
extern void s_function_terminate(void);

/* Real-time Model object */
extern RT_MODEL_s_function_T *const s_function_M;

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
 * '<Root>' : 's_function'
 */
#endif                                 /* RTW_HEADER_s_function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
