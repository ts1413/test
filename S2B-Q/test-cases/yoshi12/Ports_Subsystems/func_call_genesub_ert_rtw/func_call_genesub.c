/*
 * File: func_call_genesub.c
 *
 * Code generated for Simulink model 'func_call_genesub'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:49 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "func_call_genesub.h"
#include "func_call_genesub_private.h"

/* Exported block signals */
real_T func_call_genesub_In1_1;        /* '<Root>/In1' */

/* External outputs (root outports fed by signals with auto storage) */
ExtY_func_call_genesub_T func_call_genesub_Y;

/* Real-time model */
RT_MODEL_func_call_genesub_T func_call_genesub_M_;
RT_MODEL_func_call_genesub_T *const func_call_genesub_M = &func_call_genesub_M_;

/* Model step function */
void func_call_genesub_step(void)
{
  /* S-Function (fcncallgen): '<Root>/Function_CallGenerator' incorporates:
   *  SubSystem: '<Root>/Function_CallSubsystem'
   */
  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<S1>/In1'
   */
  func_call_genesub_Y.Out1 = func_call_genesub_In1_1;
}

/* Model initialize function */
void func_call_genesub_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(func_call_genesub_M, (NULL));

  /* external inputs */
  func_call_genesub_In1_1 = 0.0;

  /* external outputs */
  func_call_genesub_Y.Out1 = 0.0;

  /* Start for S-Function (fcncallgen): '<Root>/Function_CallGenerator' incorporates:
   *  Start for SubSystem: '<Root>/Function_CallSubsystem'
   */
  /* VirtualOutportStart for Outport: '<Root>/Out1' incorporates:
   *  VirtualOutportStart for Outport: '<S1>/Out1'
   */
  func_call_genesub_Y.Out1 = func_call_genesub_P.Out1_Y0;
}

/* Model terminate function */
void func_call_genesub_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
