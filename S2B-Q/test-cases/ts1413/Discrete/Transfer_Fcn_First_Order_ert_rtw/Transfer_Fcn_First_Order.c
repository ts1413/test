/*
 * File: Transfer_Fcn_First_Order.c
 *
 * Code generated for Simulink model 'Transfer_Fcn_First_Order'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:11 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Transfer_Fcn_First_Order.h"
#include "Transfer_Fcn_First_Order_private.h"

/* Exported block signals */
real_T Transfer_Fcn_First_Order_In1_1; /* '<Root>/In1' */

/* Block signals (auto storage) */
BlockIO_Transfer_Fcn_First_Orde Transfer_Fcn_First_Order_B;

/* Block states (auto storage) */
D_Work_Transfer_Fcn_First_Order Transfer_Fcn_First_Order_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Transfer_Fcn_Fi Transfer_Fcn_First_Order_Y;

/* Real-time model */
RT_MODEL_Transfer_Fcn_First_Ord Transfer_Fcn_First_Order_M_;
RT_MODEL_Transfer_Fcn_First_Ord *const Transfer_Fcn_First_Order_M =
  &Transfer_Fcn_First_Order_M_;

/* Model step function */
void Transfer_Fcn_First_Order_step(void)
{
  /* UnitDelay: '<S1>/UD' */
  Transfer_Fcn_First_Order_B.Yk1 = Transfer_Fcn_First_Order_DWork.UD_DSTATE;

  /* Sum: '<S1>/Diff' incorporates:
   *  Inport: '<Root>/In1'
   */
  Transfer_Fcn_First_Order_B.Yk1Uk = Transfer_Fcn_First_Order_B.Yk1 -
    Transfer_Fcn_First_Order_In1_1;

  /* Gain: '<S1>/Gain' */
  Transfer_Fcn_First_Order_B.PoleYk1Uk = 0.95 * Transfer_Fcn_First_Order_B.Yk1Uk;

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Sum: '<S1>/Sum'
   */
  Transfer_Fcn_First_Order_Y.Out1 = Transfer_Fcn_First_Order_B.PoleYk1Uk +
    Transfer_Fcn_First_Order_In1_1;

  /* Update for UnitDelay: '<S1>/UD' */
  Transfer_Fcn_First_Order_DWork.UD_DSTATE = Transfer_Fcn_First_Order_Y.Out1;
}

/* Model initialize function */
void Transfer_Fcn_First_Order_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Transfer_Fcn_First_Order_M, (NULL));

  /* block I/O */
  {
    Transfer_Fcn_First_Order_B.Yk1 = 0.0;
    Transfer_Fcn_First_Order_B.Yk1Uk = 0.0;
    Transfer_Fcn_First_Order_B.PoleYk1Uk = 0.0;
  }

  /* states (dwork) */
  Transfer_Fcn_First_Order_DWork.UD_DSTATE = 0.0;

  /* external inputs */
  Transfer_Fcn_First_Order_In1_1 = 0.0;

  /* external outputs */
  Transfer_Fcn_First_Order_Y.Out1 = 0.0;
}

/* Model terminate function */
void Transfer_Fcn_First_Order_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
