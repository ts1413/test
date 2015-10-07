/*
 * File: Constant.c
 *
 * Code generated for Simulink model 'Constant'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 17:55:29 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Constant.h"
#include "Constant_private.h"

/* Exported block signals */
real_T Constant_Constant_1;            /* '<Root>/Constant' */

/* Real-time model */
RT_MODEL_Constant_T Constant_M_;
RT_MODEL_Constant_T *const Constant_M = &Constant_M_;

/* Model step function */
void Constant_step(void)
{
  /* Constant: '<Root>/Constant' */
  Constant_Constant_1 = Constant_P.Constant_Value;
}

/* Model initialize function */
void Constant_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Constant_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Constant_Constant_1 = 0.0;
}

/* Model terminate function */
void Constant_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
