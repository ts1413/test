/*
 * File: Goto_Tag_Visibility.c
 *
 * Code generated for Simulink model 'Goto_Tag_Visibility'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:35:50 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Goto_Tag_Visibility.h"
#include "Goto_Tag_Visibility_private.h"

/* Exported block signals */
real_T Goto_Tag_Visibility_In1_1;      /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_Goto_Tag_Visibility_T Goto_Tag_Visibility_M_;
RT_MODEL_Goto_Tag_Visibility_T *const Goto_Tag_Visibility_M =
  &Goto_Tag_Visibility_M_;

/* Model step function */
void Goto_Tag_Visibility_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Goto_Tag_Visibility_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Goto_Tag_Visibility_M, (NULL));

  /* external inputs */
  Goto_Tag_Visibility_In1_1 = 0.0;
}

/* Model terminate function */
void Goto_Tag_Visibility_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
