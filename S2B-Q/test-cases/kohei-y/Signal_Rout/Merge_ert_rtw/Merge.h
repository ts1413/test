/*
 * File: Merge.h
 *
 * Code generated for Simulink model 'Merge'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:06:52 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Merge_h_
#define RTW_HEADER_Merge_h_
#include <stddef.h>
#ifndef Merge_COMMON_INCLUDES_
# define Merge_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Merge_COMMON_INCLUDES_ */

#include "Merge_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_Merge_T_ {
  real_T Constant1_Value;              /* Expression: -5
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Merge_InitialOutput;          /* Expression: 0
                                        * Referenced by: '<Root>/Merge'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Merge_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Merge_T Merge_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Merge_In1_1;             /* '<Root>/In1' */
extern real_T Merge_Constant1_1;       /* '<Root>/Constant1' */
extern real_T Merge_Constant_1;        /* '<Root>/Constant' */
extern real_T Merge_Merge_1;           /* '<Root>/Merge' */

/* Model entry point functions */
extern void Merge_initialize(void);
extern void Merge_step(void);
extern void Merge_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Merge_T *const Merge_M;

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
 * '<Root>' : 'Merge'
 * '<S1>'   : 'Merge/IfActionSubsystem'
 * '<S2>'   : 'Merge/IfActionSubsystem1'
 */
#endif                                 /* RTW_HEADER_Merge_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
