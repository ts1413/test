/*
 * File: Multiport_Switch.h
 *
 * Code generated for Simulink model 'Multiport_Switch'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:36:02 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Multiport_Switch_h_
#define RTW_HEADER_Multiport_Switch_h_
#include <stddef.h>
#ifndef Multiport_Switch_COMMON_INCLUDES_
# define Multiport_Switch_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Multiport_Switch_COMMON_INCLUDES_ */

#include "Multiport_Switch_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Multiport_Switch_T {
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
extern real_T Multiport_Switch_In1_1;  /* '<Root>/In1' */
extern real_T Multiport_Switch_In2_1;  /* '<Root>/In2' */
extern real_T Multiport_Switch_In3_1;  /* '<Root>/In3' */
extern real_T Multiport_Switch_In4_1;  /* '<Root>/In4' */
extern real_T Multiport_Switch_MultiportSwitch_1;/* '<Root>/MultiportSwitch' */

/* Model entry point functions */
extern void Multiport_Switch_initialize(void);
extern void Multiport_Switch_step(void);
extern void Multiport_Switch_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Multiport_Switch_T *const Multiport_Switch_M;

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
 * '<Root>' : 'Multiport_Switch'
 */
#endif                                 /* RTW_HEADER_Multiport_Switch_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
