/*
 * File: Width.c
 *
 * Code generated for Simulink model 'Width'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:07:55 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Width.h"
#include "Width_private.h"

/* Exported block signals */
real_T Width_In1_1;                    /* '<Root>/In1' */
real_T Width_Width_1;                  /* '<Root>/Width' */

/* Real-time model */
RT_MODEL_Width_T Width_M_;
RT_MODEL_Width_T *const Width_M = &Width_M_;

/* Model step function */
void Width_step(void)
{
  /* Width: '<Root>/Width' */
  Width_Width_1 = 1.0;
}

/* Model initialize function */
void Width_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Width_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Width_Width_1 = 0.0;

  /* external inputs */
  Width_In1_1 = 0.0;

  /* Start for Width: '<Root>/Width' */
  Width_Width_1 = 1.0;
}

/* Model terminate function */
void Width_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
