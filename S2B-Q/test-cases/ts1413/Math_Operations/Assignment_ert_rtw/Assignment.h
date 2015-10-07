/*
 * File: Assignment.h
 *
 * Code generated for Simulink model 'Assignment'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:48 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment_h_
#define RTW_HEADER_Assignment_h_
#include <stddef.h>
#ifndef Assignment_COMMON_INCLUDES_
# define Assignment_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Assignment_COMMON_INCLUDES_ */

#include "Assignment_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Assignment {
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
extern real_T Assignment_In1_1;        /* '<Root>/In1' */
extern real_T Assignment_Constant_1[4];/* '<Root>/Constant' */
extern real_T Assignment_Assignment_1[4];/* '<Root>/Assignment' */

/* Model entry point functions */
extern void Assignment_initialize(void);
extern void Assignment_step(void);
extern void Assignment_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment *const Assignment_M;

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
 * '<Root>' : 'Assignment'
 */
#endif                                 /* RTW_HEADER_Assignment_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */