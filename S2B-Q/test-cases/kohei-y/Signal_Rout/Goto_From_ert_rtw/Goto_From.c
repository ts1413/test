/*
 * File: Goto_From.c
 *
 * Code generated for Simulink model 'Goto_From'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:35:45 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Goto_From.h"
#include "Goto_From_private.h"

/* Exported block signals */
real_T Goto_From_In1_1;                /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_Goto_From_T Goto_From_M_;
RT_MODEL_Goto_From_T *const Goto_From_M = &Goto_From_M_;

/* Model step function */
void Goto_From_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Goto_From_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Goto_From_M, (NULL));

  /* external inputs */
  Goto_From_In1_1 = 0.0;
}

/* Model terminate function */
void Goto_From_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
