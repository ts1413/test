/*
 * File: Sum2.c
 *
 * Code generated for Simulink model 'Sum2'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:21 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Sum2.h"
#include "Sum2_private.h"

/* Exported block signals */
real_T Sum2_In1_1;                     /* '<Root>/In1' */
real_T Sum2_In2_1;                     /* '<Root>/In2' */
real_T Sum2_In3_1;                     /* '<Root>/In3' */
real_T Sum2_In4_1;                     /* '<Root>/In4' */
real_T Sum2_Sum_1;                     /* '<Root>/Sum' */

/* Real-time model */
RT_MODEL_Sum2_T Sum2_M_;
RT_MODEL_Sum2_T *const Sum2_M = &Sum2_M_;

/* Model step function */
void Sum2_step(void)
{
  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In3'
   *  Inport: '<Root>/In4'
   */
  Sum2_Sum_1 = ((Sum2_In1_1 + Sum2_In2_1) - Sum2_In3_1) - Sum2_In4_1;
}

/* Model initialize function */
void Sum2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Sum2_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Sum2_Sum_1 = 0.0;

  /* external inputs */
  Sum2_In1_1 = 0.0;
  Sum2_In2_1 = 0.0;
  Sum2_In3_1 = 0.0;
  Sum2_In4_1 = 0.0;
}

/* Model terminate function */
void Sum2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
