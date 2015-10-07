/*
 * File: Reshape.c
 *
 * Code generated for Simulink model 'Reshape'.
 *
 * Model version                  : 1.82
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:40:28 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Reshape.h"
#include "Reshape_private.h"

/* Exported block signals */
real_T Reshape_In1_1;                  /* '<Root>/In1' */
real_T Reshape_Reshape_1;              /* '<Root>/Reshape' */

/* Real-time model */
RT_MODEL_Reshape Reshape_M_;
RT_MODEL_Reshape *const Reshape_M = &Reshape_M_;

/* Model step function */
void Reshape_step(void)
{
  /* Reshape: '<Root>/Reshape' incorporates:
   *  Inport: '<Root>/In1'
   */
  Reshape_Reshape_1 = Reshape_In1_1;
}

/* Model initialize function */
void Reshape_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Reshape_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Reshape_Reshape_1 = 0.0;

  /* external inputs */
  Reshape_In1_1 = 0.0;
}

/* Model terminate function */
void Reshape_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
