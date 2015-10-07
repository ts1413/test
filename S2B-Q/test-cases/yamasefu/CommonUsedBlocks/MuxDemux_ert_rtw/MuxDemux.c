/*
 * File: MuxDemux.c
 *
 * Code generated for Simulink model 'MuxDemux'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:24 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MuxDemux.h"
#include "MuxDemux_private.h"

/* Exported block signals */
real_T MuxDemux_In1_1;                 /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_MuxDemux_T MuxDemux_M_;
RT_MODEL_MuxDemux_T *const MuxDemux_M = &MuxDemux_M_;

/* Model step function */
void MuxDemux_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void MuxDemux_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(MuxDemux_M, (NULL));

  /* external inputs */
  MuxDemux_In1_1 = 0.0;
}

/* Model terminate function */
void MuxDemux_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
