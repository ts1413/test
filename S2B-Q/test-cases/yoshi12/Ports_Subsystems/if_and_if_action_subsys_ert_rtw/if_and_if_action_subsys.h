/*
 * File: if_and_if_action_subsys.h
 *
 * Code generated for Simulink model 'if_and_if_action_subsys'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sat Oct  3 23:52:57 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_if_and_if_action_subsys_h_
#define RTW_HEADER_if_and_if_action_subsys_h_
#include <stddef.h>
#ifndef if_and_if_action_subsys_COMMON_INCLUDES_
# define if_and_if_action_subsys_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* if_and_if_action_subsys_COMMON_INCLUDES_ */

#include "if_and_if_action_subsys_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_if_and_if_action_subsys_T_ {
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
struct tag_RTM_if_and_if_action_subs_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_if_and_if_action_subsys_T if_and_if_action_subsys_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T if_and_if_action_subsys_In1_1;/* '<Root>/In1' */
extern real_T if_and_if_action_subsys_Constant1_1;/* '<Root>/Constant1' */
extern real_T if_and_if_action_subsys_Constant_1;/* '<Root>/Constant' */
extern real_T if_and_if_action_subsys_Merge_1;/* '<Root>/Merge' */

/* Model entry point functions */
extern void if_and_if_action_subsys_initialize(void);
extern void if_and_if_action_subsys_step(void);
extern void if_and_if_action_subsys_terminate(void);

/* Real-time Model object */
extern RT_MODEL_if_and_if_action_sub_T *const if_and_if_action_subsys_M;

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
 * '<Root>' : 'if_and_if_action_subsys'
 * '<S1>'   : 'if_and_if_action_subsys/IfActionSubsystem'
 * '<S2>'   : 'if_and_if_action_subsys/IfActionSubsystem1'
 */
#endif                                 /* RTW_HEADER_if_and_if_action_subsys_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
