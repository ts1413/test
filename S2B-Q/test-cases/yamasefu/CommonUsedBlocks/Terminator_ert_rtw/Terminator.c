/*
 * File: Terminator.c
 *
 * Code generated for Simulink model 'Terminator'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:32 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Terminator.h"
#include "Terminator_private.h"

/* Exported block signals */
real_T Terminator_In1_1;               /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_Terminator_T Terminator_M_;
RT_MODEL_Terminator_T *const Terminator_M = &Terminator_M_;

/* Model step function */
void Terminator_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Terminator_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Terminator_M, (NULL));

  /* external inputs */
  Terminator_In1_1 = 0.0;
}

/* Model terminate function */
void Terminator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
