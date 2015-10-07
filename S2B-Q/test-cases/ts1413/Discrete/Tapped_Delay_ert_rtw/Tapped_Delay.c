/*
 * File: Tapped_Delay.c
 *
 * Code generated for Simulink model 'Tapped_Delay'.
 *
 * Model version                  : 1.73
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:05 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Tapped_Delay.h"
#include "Tapped_Delay_private.h"

/* Exported block signals */
real_T Tapped_Delay_In1_1;             /* '<Root>/In1' */
real_T Tapped_Delay_TappedDelay_1[4];  /* '<Root>/TappedDelay' */

/* Block states (auto storage) */
D_Work_Tapped_Delay Tapped_Delay_DWork;

/* Real-time model */
RT_MODEL_Tapped_Delay Tapped_Delay_M_;
RT_MODEL_Tapped_Delay *const Tapped_Delay_M = &Tapped_Delay_M_;

/* Model step function */
void Tapped_Delay_step(void)
{
  /* S-Function (sfix_udelay): '<Root>/TappedDelay' */
  Tapped_Delay_TappedDelay_1[0] = Tapped_Delay_DWork.TappedDelay_X[0];
  Tapped_Delay_TappedDelay_1[1] = Tapped_Delay_DWork.TappedDelay_X[1];
  Tapped_Delay_TappedDelay_1[2] = Tapped_Delay_DWork.TappedDelay_X[2];
  Tapped_Delay_TappedDelay_1[3] = Tapped_Delay_DWork.TappedDelay_X[3];

  /* Update for S-Function (sfix_udelay): '<Root>/TappedDelay' incorporates:
   *  Update for Inport: '<Root>/In1'
   */
  Tapped_Delay_DWork.TappedDelay_X[0] = Tapped_Delay_DWork.TappedDelay_X[1];
  Tapped_Delay_DWork.TappedDelay_X[1] = Tapped_Delay_DWork.TappedDelay_X[2];
  Tapped_Delay_DWork.TappedDelay_X[2] = Tapped_Delay_DWork.TappedDelay_X[3];
  Tapped_Delay_DWork.TappedDelay_X[3] = Tapped_Delay_In1_1;
}

/* Model initialize function */
void Tapped_Delay_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Tapped_Delay_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Tapped_Delay_TappedDelay_1[0] = 0.0;
  Tapped_Delay_TappedDelay_1[1] = 0.0;
  Tapped_Delay_TappedDelay_1[2] = 0.0;
  Tapped_Delay_TappedDelay_1[3] = 0.0;

  /* states (dwork) */
  Tapped_Delay_DWork.TappedDelay_X[0] = 0.0;
  Tapped_Delay_DWork.TappedDelay_X[1] = 0.0;
  Tapped_Delay_DWork.TappedDelay_X[2] = 0.0;
  Tapped_Delay_DWork.TappedDelay_X[3] = 0.0;

  /* external inputs */
  Tapped_Delay_In1_1 = 0.0;

  /* InitializeConditions for S-Function (sfix_udelay): '<Root>/TappedDelay' */
  Tapped_Delay_DWork.TappedDelay_X[0] = 0.0;
  Tapped_Delay_DWork.TappedDelay_X[1] = 0.0;
  Tapped_Delay_DWork.TappedDelay_X[2] = 0.0;
  Tapped_Delay_DWork.TappedDelay_X[3] = 0.0;
}

/* Model terminate function */
void Tapped_Delay_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
