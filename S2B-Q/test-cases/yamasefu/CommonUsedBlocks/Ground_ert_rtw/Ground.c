/*
 * File: Ground.c
 *
 * Code generated for Simulink model 'Ground'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ground.h"
#include "Ground_private.h"

/* Real-time model */
RT_MODEL_Ground_T Ground_M_;
RT_MODEL_Ground_T *const Ground_M = &Ground_M_;

/* Model step function */
void Ground_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Ground_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Ground_M, (NULL));
}

/* Model terminate function */
void Ground_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
