/*
 * File: for_each_subsystem.c
 *
 * Code generated for Simulink model 'for_each_subsystem'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:37 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "for_each_subsystem.h"
#include "for_each_subsystem_private.h"

/* Exported block signals */
real_T for_each_subsystem_In1_1;       /* '<Root>/In1' */

/* External outputs (root outports fed by signals with auto storage) */
ExtY_for_each_subsystem_T for_each_subsystem_Y;

/* Real-time model */
RT_MODEL_for_each_subsystem_T for_each_subsystem_M_;
RT_MODEL_for_each_subsystem_T *const for_each_subsystem_M =
  &for_each_subsystem_M_;

/* Model step function */
void for_each_subsystem_step(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_ImpSel_InsertedFor_In1_at_o;

  /* Outputs for Iterator SubSystem: '<Root>/ForEachSubsystem' incorporates:
   *  ForEach: '<S1>/ForEach'
   */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* ForEachSliceSelector: '<S1>/ImpSel_InsertedFor_In1_at_outport_0' incorporates:
     *  Inport: '<Root>/In1'
     */
    rtb_ImpSel_InsertedFor_In1_at_o = for_each_subsystem_In1_1;

    /* Outport: '<Root>/Out1' incorporates:
     *  ForEachSliceAssignment: '<S1>/ImpAsg_InsertedFor_Out1_at_inport_0'
     */
    for_each_subsystem_Y.Out1 = rtb_ImpSel_InsertedFor_In1_at_o;
  }

  /* End of Outputs for SubSystem: '<Root>/ForEachSubsystem' */
}

/* Model initialize function */
void for_each_subsystem_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(for_each_subsystem_M, (NULL));

  /* external inputs */
  for_each_subsystem_In1_1 = 0.0;

  /* external outputs */
  for_each_subsystem_Y.Out1 = 0.0;
}

/* Model terminate function */
void for_each_subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
