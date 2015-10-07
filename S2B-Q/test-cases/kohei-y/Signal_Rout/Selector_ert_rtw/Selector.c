/*
 * File: Selector.c
 *
 * Code generated for Simulink model 'Selector'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:36:54 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Selector.h"
#include "Selector_private.h"

/* Exported block signals */
real_T Selector_In1_1[3];              /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_Selector_T Selector_M_;
RT_MODEL_Selector_T *const Selector_M = &Selector_M_;

/* Model step function */
void Selector_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Selector_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Selector_M, (NULL));

  /* external inputs */
  (void) memset(Selector_In1_1, 0,
                3U*sizeof(real_T));
}

/* Model terminate function */
void Selector_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
