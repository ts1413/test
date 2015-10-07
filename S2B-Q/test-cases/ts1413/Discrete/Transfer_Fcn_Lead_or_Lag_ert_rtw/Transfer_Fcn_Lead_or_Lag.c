/*
 * File: Transfer_Fcn_Lead_or_Lag.c
 *
 * Code generated for Simulink model 'Transfer_Fcn_Lead_or_Lag'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:18 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Transfer_Fcn_Lead_or_Lag.h"
#include "Transfer_Fcn_Lead_or_Lag_private.h"

/* Exported block signals */
real_T Transfer_Fcn_Lead_or_Lag_In1_1; /* '<Root>/In1' */

/* Block signals (auto storage) */
BlockIO_Transfer_Fcn_Lead_or_La Transfer_Fcn_Lead_or_Lag_B;

/* Block states (auto storage) */
D_Work_Transfer_Fcn_Lead_or_Lag Transfer_Fcn_Lead_or_Lag_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Transfer_Fcn_Le Transfer_Fcn_Lead_or_Lag_Y;

/* Real-time model */
RT_MODEL_Transfer_Fcn_Lead_or_L Transfer_Fcn_Lead_or_Lag_M_;
RT_MODEL_Transfer_Fcn_Lead_or_L *const Transfer_Fcn_Lead_or_Lag_M =
  &Transfer_Fcn_Lead_or_Lag_M_;

/* Model step function */
void Transfer_Fcn_Lead_or_Lag_step(void)
{
  /* UnitDelay: '<S1>/Delay Input' */
  Transfer_Fcn_Lead_or_Lag_B.Uk1 =
    Transfer_Fcn_Lead_or_Lag_DWork.DelayInput_DSTATE;

  /* Gain: '<S1>/GainZero' */
  Transfer_Fcn_Lead_or_Lag_B.ZeroUk1 = 0.75 * Transfer_Fcn_Lead_or_Lag_B.Uk1;

  /* UnitDelay: '<S1>/Delay Output' */
  Transfer_Fcn_Lead_or_Lag_B.Yk1 =
    Transfer_Fcn_Lead_or_Lag_DWork.DelayOutput_DSTATE;

  /* Gain: '<S1>/GainPole' */
  Transfer_Fcn_Lead_or_Lag_B.PoleYk1 = 0.95 * Transfer_Fcn_Lead_or_Lag_B.Yk1;

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/In1'
   */
  Transfer_Fcn_Lead_or_Lag_B.PoleYk1UkZeroUk1 = (Transfer_Fcn_Lead_or_Lag_In1_1
    - Transfer_Fcn_Lead_or_Lag_B.ZeroUk1) + Transfer_Fcn_Lead_or_Lag_B.PoleYk1;

  /* Outport: '<Root>/Out1' incorporates:
   *  DataTypeConversion: '<S1>/Downcast'
   */
  Transfer_Fcn_Lead_or_Lag_Y.Out1 = Transfer_Fcn_Lead_or_Lag_B.PoleYk1UkZeroUk1;

  /* Update for UnitDelay: '<S1>/Delay Input' incorporates:
   *  Inport: '<Root>/In1'
   */
  Transfer_Fcn_Lead_or_Lag_DWork.DelayInput_DSTATE =
    Transfer_Fcn_Lead_or_Lag_In1_1;

  /* Update for UnitDelay: '<S1>/Delay Output' */
  Transfer_Fcn_Lead_or_Lag_DWork.DelayOutput_DSTATE =
    Transfer_Fcn_Lead_or_Lag_Y.Out1;
}

/* Model initialize function */
void Transfer_Fcn_Lead_or_Lag_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Transfer_Fcn_Lead_or_Lag_M, (NULL));

  /* block I/O */
  {
    Transfer_Fcn_Lead_or_Lag_B.Uk1 = 0.0;
    Transfer_Fcn_Lead_or_Lag_B.ZeroUk1 = 0.0;
    Transfer_Fcn_Lead_or_Lag_B.Yk1 = 0.0;
    Transfer_Fcn_Lead_or_Lag_B.PoleYk1 = 0.0;
    Transfer_Fcn_Lead_or_Lag_B.PoleYk1UkZeroUk1 = 0.0;
  }

  /* states (dwork) */
  Transfer_Fcn_Lead_or_Lag_DWork.DelayInput_DSTATE = 0.0;
  Transfer_Fcn_Lead_or_Lag_DWork.DelayOutput_DSTATE = 0.0;

  /* external inputs */
  Transfer_Fcn_Lead_or_Lag_In1_1 = 0.0;

  /* external outputs */
  Transfer_Fcn_Lead_or_Lag_Y.Out1 = 0.0;
}

/* Model terminate function */
void Transfer_Fcn_Lead_or_Lag_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
