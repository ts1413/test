/*
 * File: Saturation.c
 *
 * Code generated for Simulink model 'Saturation'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:47 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Saturation.h"
#include "Saturation_private.h"

/* Exported block signals */
real_T Saturation_In1_1;               /* '<Root>/In1' */
real_T Saturation_Saturation_1;        /* '<Root>/Saturation' */

/* Real-time model */
RT_MODEL_Saturation_T Saturation_M_;
RT_MODEL_Saturation_T *const Saturation_M = &Saturation_M_;

/* Model step function */
void Saturation_step(void)
{
  real_T u0;
  real_T u1;
  real_T u2;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/In1'
   */
  u0 = Saturation_In1_1;
  u1 = Saturation_P.Saturation_LowerSat;
  u2 = Saturation_P.Saturation_UpperSat;
  if (u0 > u2) {
    Saturation_Saturation_1 = u2;
  } else if (u0 < u1) {
    Saturation_Saturation_1 = u1;
  } else {
    Saturation_Saturation_1 = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */
}

/* Model initialize function */
void Saturation_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Saturation_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Saturation_Saturation_1 = 0.0;

  /* external inputs */
  Saturation_In1_1 = 0.0;
}

/* Model terminate function */
void Saturation_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
