/*
 * File: Sum1.c
 *
 * Code generated for Simulink model 'Sum1'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:15 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Sum1.h"
#include "Sum1_private.h"

/* Exported block signals */
real_T Sum1_In1_1;                     /* '<Root>/In1' */
real_T Sum1_Sum_1;                     /* '<Root>/Sum' */

/* Real-time model */
RT_MODEL_Sum1_T Sum1_M_;
RT_MODEL_Sum1_T *const Sum1_M = &Sum1_M_;

/* Model step function */
void Sum1_step(void)
{
  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/In1'
   */
  Sum1_Sum_1 = Sum1_In1_1 + Sum1_In1_1;
}

/* Model initialize function */
void Sum1_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Sum1_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Sum1_Sum_1 = 0.0;

  /* external inputs */
  Sum1_In1_1 = 0.0;
}

/* Model terminate function */
void Sum1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
