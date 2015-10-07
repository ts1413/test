/*
 * File: Divide.c
 *
 * Code generated for Simulink model 'Divide'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:59 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Divide.h"
#include "Divide_private.h"

/* Exported block signals */
real_T Divide_In1_1;                   /* '<Root>/In1' */
real_T Divide_Constant_1;              /* '<Root>/Constant' */
real_T Divide_Divide_1;                /* '<Root>/Divide' */

/* Real-time model */
RT_MODEL_Divide Divide_M_;
RT_MODEL_Divide *const Divide_M = &Divide_M_;

/* Model step function */
void Divide_step(void)
{
  /* Product: '<Root>/Divide' incorporates:
   *  Inport: '<Root>/In1'
   */
  Divide_Divide_1 = Divide_In1_1 / Divide_Constant_1;
}

/* Model initialize function */
void Divide_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Divide_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Divide_Constant_1 = 10.0;
  Divide_Divide_1 = 0.0;

  /* external inputs */
  Divide_In1_1 = 0.0;

  /* ConstCode for Constant: '<Root>/Constant' */
  Divide_Constant_1 = 10.0;
}

/* Model terminate function */
void Divide_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
