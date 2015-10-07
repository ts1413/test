/*
 * File: Dead_Zone.h
 *
 * Code generated for Simulink model 'Dead_Zone'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:10 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Dead_Zone_h_
#define RTW_HEADER_Dead_Zone_h_
#include <stddef.h>
#ifndef Dead_Zone_COMMON_INCLUDES_
# define Dead_Zone_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Dead_Zone_COMMON_INCLUDES_ */

#include "Dead_Zone_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Dead_Zone {
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
extern real_T Dead_Zone_In1_1;         /* '<Root>/In1' */
extern real_T Dead_Zone_DeadZone_1;    /* '<Root>/DeadZone' */

/* Model entry point functions */
extern void Dead_Zone_initialize(void);
extern void Dead_Zone_step(void);
extern void Dead_Zone_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Dead_Zone *const Dead_Zone_M;

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
 * '<Root>' : 'Dead_Zone'
 */
#endif                                 /* RTW_HEADER_Dead_Zone_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
