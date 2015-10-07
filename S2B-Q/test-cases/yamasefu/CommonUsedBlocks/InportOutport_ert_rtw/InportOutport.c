/*
 * File: InportOutport.c
 *
 * Code generated for Simulink model 'InportOutport'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:13 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "InportOutport.h"
#include "InportOutport_private.h"

/* Exported block signals */
real_T InportOutport_In1_1;            /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_InportOutport_T InportOutport_M_;
RT_MODEL_InportOutport_T *const InportOutport_M = &InportOutport_M_;

/* Model step function */
void InportOutport_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void InportOutport_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(InportOutport_M, (NULL));

  /* external inputs */
  InportOutport_In1_1 = 0.0;
}

/* Model terminate function */
void InportOutport_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
