/*
 * File: Transfer_Fcn_Real_Zero.c
 *
 * Code generated for Simulink model 'Transfer_Fcn_Real_Zero'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:24 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Transfer_Fcn_Real_Zero.h"
#include "Transfer_Fcn_Real_Zero_private.h"

/* Exported block signals */
real_T Transfer_Fcn_Real_Zero_In1_1;   /* '<Root>/In1' */

/* Block signals (auto storage) */
BlockIO_Transfer_Fcn_Real_Zero Transfer_Fcn_Real_Zero_B;

/* Block states (auto storage) */
D_Work_Transfer_Fcn_Real_Zero Transfer_Fcn_Real_Zero_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Transfer_Fcn_Re Transfer_Fcn_Real_Zero_Y;

/* Real-time model */
RT_MODEL_Transfer_Fcn_Real_Zero Transfer_Fcn_Real_Zero_M_;
RT_MODEL_Transfer_Fcn_Real_Zero *const Transfer_Fcn_Real_Zero_M =
  &Transfer_Fcn_Real_Zero_M_;

/* Model step function */
void Transfer_Fcn_Real_Zero_step(void)
{
  /* UnitDelay: '<S1>/Delay Input' */
  Transfer_Fcn_Real_Zero_B.Uk1 = Transfer_Fcn_Real_Zero_DWork.DelayInput_DSTATE;

  /* Gain: '<S1>/GainZero' */
  Transfer_Fcn_Real_Zero_B.ZeroUk1 = 0.75 * Transfer_Fcn_Real_Zero_B.Uk1;

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Sum: '<S1>/Sum'
   */
  Transfer_Fcn_Real_Zero_Y.Out1 = Transfer_Fcn_Real_Zero_In1_1 -
    Transfer_Fcn_Real_Zero_B.ZeroUk1;

  /* Update for UnitDelay: '<S1>/Delay Input' incorporates:
   *  Inport: '<Root>/In1'
   */
  Transfer_Fcn_Real_Zero_DWork.DelayInput_DSTATE = Transfer_Fcn_Real_Zero_In1_1;
}

/* Model initialize function */
void Transfer_Fcn_Real_Zero_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Transfer_Fcn_Real_Zero_M, (NULL));

  /* block I/O */
  {
    Transfer_Fcn_Real_Zero_B.Uk1 = 0.0;
    Transfer_Fcn_Real_Zero_B.ZeroUk1 = 0.0;
  }

  /* states (dwork) */
  Transfer_Fcn_Real_Zero_DWork.DelayInput_DSTATE = 0.0;

  /* external inputs */
  Transfer_Fcn_Real_Zero_In1_1 = 0.0;

  /* external outputs */
  Transfer_Fcn_Real_Zero_Y.Out1 = 0.0;
}

/* Model terminate function */
void Transfer_Fcn_Real_Zero_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
