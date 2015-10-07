/*
 * File: Subtract.c
 *
 * Code generated for Simulink model 'Subtract'.
 *
 * Model version                  : 1.85
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:40:46 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subtract.h"
#include "Subtract_private.h"

/* Exported block signals */
real_T Subtract_In1_1;                 /* '<Root>/In1' */
real_T Subtract_In2_1;                 /* '<Root>/In2' */
real_T Subtract_Subtract_1;            /* '<Root>/Subtract' */

/* Real-time model */
RT_MODEL_Subtract Subtract_M_;
RT_MODEL_Subtract *const Subtract_M = &Subtract_M_;

/* Model step function */
void Subtract_step(void)
{
  /* Sum: '<Root>/Subtract' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  Subtract_Subtract_1 = Subtract_In1_1 - Subtract_In2_1;
}

/* Model initialize function */
void Subtract_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Subtract_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Subtract_Subtract_1 = 0.0;

  /* external inputs */
  Subtract_In1_1 = 0.0;
  Subtract_In2_1 = 0.0;
}

/* Model terminate function */
void Subtract_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
