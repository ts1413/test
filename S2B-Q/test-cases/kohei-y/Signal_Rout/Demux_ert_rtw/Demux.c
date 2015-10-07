/*
 * File: Demux.c
 *
 * Code generated for Simulink model 'Demux'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:35:39 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Demux.h"
#include "Demux_private.h"

/* Exported block signals */
real_T Demux_In1_1[2];                 /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_Demux_T Demux_M_;
RT_MODEL_Demux_T *const Demux_M = &Demux_M_;

/* Model step function */
void Demux_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Demux_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Demux_M, (NULL));

  /* external inputs */
  (void) memset(Demux_In1_1, 0,
                2U*sizeof(real_T));
}

/* Model terminate function */
void Demux_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
