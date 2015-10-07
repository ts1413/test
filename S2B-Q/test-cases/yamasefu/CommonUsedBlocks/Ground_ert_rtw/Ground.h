/*
 * File: Ground.h
 *
 * Code generated for Simulink model 'Ground'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Ground_h_
#define RTW_HEADER_Ground_h_
#include <stddef.h>
#ifndef Ground_COMMON_INCLUDES_
# define Ground_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Ground_COMMON_INCLUDES_ */

#include "Ground_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Ground_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void Ground_initialize(void);
extern void Ground_step(void);
extern void Ground_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Ground_T *const Ground_M;

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
 * '<Root>' : 'Ground'
 */
#endif                                 /* RTW_HEADER_Ground_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
