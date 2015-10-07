/*
 * File: switch_case.c
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

#include "switch_case.h"
#include "switch_case_private.h"

/* Exported block signals */
real_T switch_case_In1_1;              /* '<Root>/In1' */
real_T switch_case_Constant1_1;        /* '<Root>/Constant1' */
real_T switch_case_Constant_1;         /* '<Root>/Constant' */

/* Block signals (auto storage) */
B_switch_case_T switch_case_B;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_switch_case_T switch_case_Y;

/* Real-time model */
RT_MODEL_switch_case_T switch_case_M_;
RT_MODEL_switch_case_T *const switch_case_M = &switch_case_M_;

/*
 * Start for action system:
 *    '<Root>/SwitchCaseActionSubsystem'
 *    '<Root>/SwitchCaseActionSubsystem1'
 */
void SwitchCaseActionSubsystem_Start(B_SwitchCaseActionSubsystem_s_T *localB,
  P_SwitchCaseActionSubsystem_s_T *localP)
{
  /* VirtualOutportStart for Outport: '<S1>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<Root>/SwitchCaseActionSubsystem'
 *    '<Root>/SwitchCaseActionSubsystem1'
 */
void switc_SwitchCaseActionSubsystem(real_T rtu_In1,
  B_SwitchCaseActionSubsystem_s_T *localB)
{
  /* Inport: '<S1>/In1' */
  localB->In1 = rtu_In1;
}

/* Model step function */
void switch_case_step(void)
{
  real_T u;

  /* Constant: '<Root>/Constant1' */
  switch_case_Constant1_1 = switch_case_P.Constant1_Value;

  /* Constant: '<Root>/Constant' */
  switch_case_Constant_1 = switch_case_P.Constant_Value;

  /* SwitchCase: '<Root>/SwitchCase' incorporates:
   *  Inport: '<Root>/In1'
   */
  u = switch_case_In1_1;
  if (u < 0.0) {
    u = ceil(u);
  } else {
    u = floor(u);
  }

  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 4.294967296E+9);
  }

  if ((u < 0.0 ? -(int32_T)(uint32_T)-u : (int32_T)(uint32_T)u) == 1) {
    /* Outputs for IfAction SubSystem: '<Root>/SwitchCaseActionSubsystem' incorporates:
     *  ActionPort: '<S1>/ActionPort'
     */
    switc_SwitchCaseActionSubsystem(switch_case_Constant_1,
      &switch_case_B.SwitchCaseActionSubsystem);

    /* End of Outputs for SubSystem: '<Root>/SwitchCaseActionSubsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/SwitchCaseActionSubsystem1' incorporates:
     *  ActionPort: '<S2>/ActionPort'
     */
    switc_SwitchCaseActionSubsystem(switch_case_Constant1_1,
      &switch_case_B.SwitchCaseActionSubsystem1);

    /* End of Outputs for SubSystem: '<Root>/SwitchCaseActionSubsystem1' */
  }

  /* End of SwitchCase: '<Root>/SwitchCase' */

  /* Outport: '<Root>/Out1' */
  switch_case_Y.Out1 = switch_case_B.SwitchCaseActionSubsystem.In1;

  /* Outport: '<Root>/Out2' */
  switch_case_Y.Out2 = switch_case_B.SwitchCaseActionSubsystem1.In1;
}

/* Model initialize function */
void switch_case_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(switch_case_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &switch_case_B), 0,
                sizeof(B_switch_case_T));

  /* exported global signals */
  switch_case_Constant1_1 = 0.0;
  switch_case_Constant_1 = 0.0;

  /* external inputs */
  switch_case_In1_1 = 0.0;

  /* external outputs */
  (void) memset((void *)&switch_case_Y, 0,
                sizeof(ExtY_switch_case_T));

  /* Start for IfAction SubSystem: '<Root>/SwitchCaseActionSubsystem' */
  SwitchCaseActionSubsystem_Start(&switch_case_B.SwitchCaseActionSubsystem,
    (P_SwitchCaseActionSubsystem_s_T *)&switch_case_P.SwitchCaseActionSubsystem);

  /* End of Start for SubSystem: '<Root>/SwitchCaseActionSubsystem' */

  /* Start for IfAction SubSystem: '<Root>/SwitchCaseActionSubsystem1' */
  SwitchCaseActionSubsystem_Start(&switch_case_B.SwitchCaseActionSubsystem1,
    (P_SwitchCaseActionSubsystem_s_T *)&switch_case_P.SwitchCaseActionSubsystem1);

  /* End of Start for SubSystem: '<Root>/SwitchCaseActionSubsystem1' */
}

/* Model terminate function */
void switch_case_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
