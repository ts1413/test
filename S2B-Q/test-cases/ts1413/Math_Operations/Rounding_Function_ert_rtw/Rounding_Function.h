/*
 * File: Rounding_Function.h
 *
 * Code generated for Simulink model 'Rounding_Function'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:40:34 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rounding_Function_h_
#define RTW_HEADER_Rounding_Function_h_
#include <math.h>
#include <stddef.h>
#ifndef Rounding_Function_COMMON_INCLUDES_
# define Rounding_Function_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Rounding_Function_COMMON_INCLUDES_ */

#include "Rounding_Function_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Rounding_Function {
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
extern real_T Rounding_Function_In1_1; /* '<Root>/In1' */
extern real_T Rounding_Function_RoundingFunction_1;/* '<Root>/RoundingFunction' */

/* Model entry point functions */
extern void Rounding_Function_initialize(void);
extern void Rounding_Function_step(void);
extern void Rounding_Function_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rounding_Function *const Rounding_Function_M;

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
 * '<Root>' : 'Rounding_Function'
 */
#endif                                 /* RTW_HEADER_Rounding_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
