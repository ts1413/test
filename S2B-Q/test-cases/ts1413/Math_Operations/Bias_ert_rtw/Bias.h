/*
 * File: Bias.h
 *
 * Code generated for Simulink model 'Bias'.
 *
 * Model version                  : 1.73
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:53 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Bias_h_
#define RTW_HEADER_Bias_h_
#include <stddef.h>
#ifndef Bias_COMMON_INCLUDES_
# define Bias_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Bias_COMMON_INCLUDES_ */

#include "Bias_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Bias {
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
extern real_T Bias_In1_1;              /* '<Root>/In1' */
extern real_T Bias_Bias_1;             /* '<Root>/Bias' */

/* Model entry point functions */
extern void Bias_initialize(void);
extern void Bias_step(void);
extern void Bias_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Bias *const Bias_M;

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
 * '<Root>' : 'Bias'
 */
#endif                                 /* RTW_HEADER_Bias_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
