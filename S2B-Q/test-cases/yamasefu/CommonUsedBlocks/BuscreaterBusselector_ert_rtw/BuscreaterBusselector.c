/*
 * File: BuscreaterBusselector.c
 *
 * Code generated for Simulink model 'BuscreaterBusselector'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:44:23 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BuscreaterBusselector.h"
#include "BuscreaterBusselector_private.h"

/* Exported block signals */
real_T BuscreaterBusselector_In1_1;    /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_BuscreaterBusselecto_T BuscreaterBusselector_M_;
RT_MODEL_BuscreaterBusselecto_T *const BuscreaterBusselector_M =
  &BuscreaterBusselector_M_;

/* Model step function */
void BuscreaterBusselector_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void BuscreaterBusselector_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BuscreaterBusselector_M, (NULL));

  /* external inputs */
  BuscreaterBusselector_In1_1 = 0.0;
}

/* Model terminate function */
void BuscreaterBusselector_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
