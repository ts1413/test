/*
 * File: Shift_Arithmetic_Input.h
 *
 * Code generated for Simulink model 'Shift_Arithmetic_Input'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:40:49 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Shift_Arithmetic_Input_h_
#define RTW_HEADER_Shift_Arithmetic_Input_h_
#include <math.h>
#include <stddef.h>
#ifndef Shift_Arithmetic_Input_COMMON_INCLUDES_
# define Shift_Arithmetic_Input_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Shift_Arithmetic_Input_COMMON_INCLUDES_ */

#include "Shift_Arithmetic_Input_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Shift_Arithmetic_Inpu_T {
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
extern real_T Shift_Arithmetic_Input_In1_1;/* '<Root>/In1' */
extern real_T Shift_Arithmetic_Input_In2_1;/* '<Root>/In2' */
extern real_T Shift_Arithmetic_Input_ShiftArithmetic_1;/* '<Root>/ShiftArithmetic' */

/* Model entry point functions */
extern void Shift_Arithmetic_Input_initialize(void);
extern void Shift_Arithmetic_Input_step(void);
extern void Shift_Arithmetic_Input_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Shift_Arithmetic_Inp_T *const Shift_Arithmetic_Input_M;

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
 * '<Root>' : 'Shift_Arithmetic_Input'
 */
#endif                                 /* RTW_HEADER_Shift_Arithmetic_Input_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
