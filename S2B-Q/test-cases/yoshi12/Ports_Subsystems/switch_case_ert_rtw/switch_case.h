/*
 * File: switch_case.h
 *
 * Code generated for Simulink model 'switch_case'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:42:14 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_switch_case_h_
#define RTW_HEADER_switch_case_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef switch_case_COMMON_INCLUDES_
# define switch_case_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* switch_case_COMMON_INCLUDES_ */

#include "switch_case_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<Root>/SwitchCaseActionSubsystem' */
typedef struct {
  real_T In1;                          /* '<S1>/In1' */
} B_SwitchCaseActionSubsystem_s_T;

/* Block signals (auto storage) */
typedef struct {
  B_SwitchCaseActionSubsystem_s_T SwitchCaseActionSubsystem1;/* '<Root>/SwitchCaseActionSubsystem1' */
  B_SwitchCaseActionSubsystem_s_T SwitchCaseActionSubsystem;/* '<Root>/SwitchCaseActionSubsystem' */
} B_switch_case_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
} ExtY_switch_case_T;

/* Parameters for system: '<Root>/SwitchCaseActionSubsystem' */
struct P_SwitchCaseActionSubsystem_s_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
};

/* Parameters (auto storage) */
struct P_switch_case_T_ {
  real_T Constant1_Value;              /* Expression: -5
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
                                        */
  P_SwitchCaseActionSubsystem_s_T SwitchCaseActionSubsystem1;/* '<Root>/SwitchCaseActionSubsystem1' */
  P_SwitchCaseActionSubsystem_s_T SwitchCaseActionSubsystem;/* '<Root>/SwitchCaseActionSubsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_switch_case_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_switch_case_T switch_case_P;

/* Block signals (auto storage) */
extern B_switch_case_T switch_case_B;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_switch_case_T switch_case_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T switch_case_In1_1;       /* '<Root>/In1' */
extern real_T switch_case_Constant1_1; /* '<Root>/Constant1' */
extern real_T switch_case_Constant_1;  /* '<Root>/Constant' */

/* Model entry point functions */
extern void switch_case_initialize(void);
extern void switch_case_step(void);
extern void switch_case_terminate(void);

/* Real-time Model object */
extern RT_MODEL_switch_case_T *const switch_case_M;

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
 * '<Root>' : 'switch_case'
 * '<S1>'   : 'switch_case/SwitchCaseActionSubsystem'
 * '<S2>'   : 'switch_case/SwitchCaseActionSubsystem1'
 */
#endif                                 /* RTW_HEADER_switch_case_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
