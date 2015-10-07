/*
 * File: Terminator.h
 *
 * Code generated for Simulink model 'Terminator'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:32 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Terminator_h_
#define RTW_HEADER_Terminator_h_
#include <stddef.h>
#ifndef Terminator_COMMON_INCLUDES_
# define Terminator_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Terminator_COMMON_INCLUDES_ */

#include "Terminator_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Terminator_T {
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
extern real_T Terminator_In1_1;        /* '<Root>/In1' */

/* Model entry point functions */
extern void Terminator_initialize(void);
extern void Terminator_step(void);
extern void Terminator_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Terminator_T *const Terminator_M;

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
 * '<Root>' : 'Terminator'
 */
#endif                                 /* RTW_HEADER_Terminator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */