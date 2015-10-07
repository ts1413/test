/*
 * File: if_and_if_action_subsys.c
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

#include "if_and_if_action_subsys.h"
#include "if_and_if_action_subsys_private.h"

/* Exported block signals */
real_T if_and_if_action_subsys_In1_1;  /* '<Root>/In1' */
real_T if_and_if_action_subsys_Constant1_1;/* '<Root>/Constant1' */
real_T if_and_if_action_subsys_Constant_1;/* '<Root>/Constant' */
real_T if_and_if_action_subsys_Merge_1;/* '<Root>/Merge' */

/* Real-time model */
RT_MODEL_if_and_if_action_sub_T if_and_if_action_subsys_M_;
RT_MODEL_if_and_if_action_sub_T *const if_and_if_action_subsys_M =
  &if_and_if_action_subsys_M_;

/*
 * Output and update for action system:
 *    '<Root>/IfActionSubsystem'
 *    '<Root>/IfActionSubsystem1'
 */
void if_and_if_act_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S1>/In1' */
  *rty_Out1 = rtu_In1;
}

/* Model step function */
void if_and_if_action_subsys_step(void)
{
  /* Constant: '<Root>/Constant1' */
  if_and_if_action_subsys_Constant1_1 =
    if_and_if_action_subsys_P.Constant1_Value;

  /* Constant: '<Root>/Constant' */
  if_and_if_action_subsys_Constant_1 = if_and_if_action_subsys_P.Constant_Value;

  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (if_and_if_action_subsys_In1_1 > 0.0) {
    /* Outputs for IfAction SubSystem: '<Root>/IfActionSubsystem' incorporates:
     *  ActionPort: '<S1>/ActionPort'
     */
    if_and_if_act_IfActionSubsystem(if_and_if_action_subsys_Constant_1,
      &if_and_if_action_subsys_Merge_1);

    /* End of Outputs for SubSystem: '<Root>/IfActionSubsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/IfActionSubsystem1' incorporates:
     *  ActionPort: '<S2>/ActionPort'
     */
    if_and_if_act_IfActionSubsystem(if_and_if_action_subsys_Constant1_1,
      &if_and_if_action_subsys_Merge_1);

    /* End of Outputs for SubSystem: '<Root>/IfActionSubsystem1' */
  }

  /* End of If: '<Root>/If' */
}

/* Model initialize function */
void if_and_if_action_subsys_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(if_and_if_action_subsys_M, (NULL));

  /* block I/O */

  /* exported global signals */
  if_and_if_action_subsys_Constant1_1 = 0.0;
  if_and_if_action_subsys_Constant_1 = 0.0;
  if_and_if_action_subsys_Merge_1 = 0.0;

  /* external inputs */
  if_and_if_action_subsys_In1_1 = 0.0;

  /* Start for Merge: '<Root>/Merge' */
  if_and_if_action_subsys_Merge_1 =
    if_and_if_action_subsys_P.Merge_InitialOutput;
}

/* Model terminate function */
void if_and_if_action_subsys_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
