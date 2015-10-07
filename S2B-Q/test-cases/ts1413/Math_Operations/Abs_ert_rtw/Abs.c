/*
 * File: Abs.c
 *
 * Code generated for Simulink model 'Abs'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:36 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Abs.h"
#include "Abs_private.h"

/* Exported block signals */
real_T Abs_In1_1;                      /* '<Root>/In1' */
real_T Abs_Abs_1;                      /* '<Root>/Abs' */

/* Real-time model */
RT_MODEL_Abs Abs_M_;
RT_MODEL_Abs *const Abs_M = &Abs_M_;

/* Model step function */
void Abs_step(void)
{
  /* Abs: '<Root>/Abs' incorporates:
   *  Inport: '<Root>/In1'
   */
  Abs_Abs_1 = fabs(Abs_In1_1);
}

/* Model initialize function */
void Abs_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Abs_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Abs_Abs_1 = 0.0;

  /* external inputs */
  Abs_In1_1 = 0.0;
}

/* Model terminate function */
void Abs_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
