/*
 * File: Gain1.c
 *
 * Code generated for Simulink model 'Gain1'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:54:45 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Gain1.h"
#include "Gain1_private.h"

/* Exported block signals */
real_T Gain1_In1_1;                    /* '<Root>/In1' */
real_T Gain1_Gain_1;                   /* '<Root>/Gain' */

/* Real-time model */
RT_MODEL_Gain1_T Gain1_M_;
RT_MODEL_Gain1_T *const Gain1_M = &Gain1_M_;

/* Model step function */
void Gain1_step(void)
{
  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain1_Gain_1 = Gain1_P.Gain_Gain * Gain1_In1_1;
}

/* Model initialize function */
void Gain1_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Gain1_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Gain1_Gain_1 = 0.0;

  /* external inputs */
  Gain1_In1_1 = 0.0;
}

/* Model terminate function */
void Gain1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
