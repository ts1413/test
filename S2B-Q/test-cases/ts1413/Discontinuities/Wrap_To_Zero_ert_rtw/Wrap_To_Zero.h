/*
 * File: Wrap_To_Zero.h
 *
 * Code generated for Simulink model 'Wrap_To_Zero'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:41 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wrap_To_Zero_h_
#define RTW_HEADER_Wrap_To_Zero_h_
#include <stddef.h>
#ifndef Wrap_To_Zero_COMMON_INCLUDES_
# define Wrap_To_Zero_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Wrap_To_Zero_COMMON_INCLUDES_ */

#include "Wrap_To_Zero_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExternalOutputs_Wrap_To_Zero;

/* Real-time Model Data Structure */
struct tag_RTM_Wrap_To_Zero {
  const char_T * volatile errorStatus;
};

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Wrap_To_Zero Wrap_To_Zero_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Wrap_To_Zero_In1_1;      /* '<Root>/In1' */

/* Model entry point functions */
extern void Wrap_To_Zero_initialize(void);
extern void Wrap_To_Zero_step(void);
extern void Wrap_To_Zero_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Wrap_To_Zero *const Wrap_To_Zero_M;

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
 * '<Root>' : 'Wrap_To_Zero'
 * '<S1>'   : 'Wrap_To_Zero/WrapToZero'
 */
#endif                                 /* RTW_HEADER_Wrap_To_Zero_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
