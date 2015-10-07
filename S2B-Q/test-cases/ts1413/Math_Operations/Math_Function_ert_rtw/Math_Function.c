/*
 * File: Math_Function.c
 *
 * Code generated for Simulink model 'Math_Function'.
 *
 * Model version                  : 1.92
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:08:06 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Math_Function.h"
#include "Math_Function_private.h"

/* Exported block signals */
real_T Math_Function_In1_1;            /* '<Root>/In1' */
real_T Math_Function_MathFunction_1;   /* '<Root>/MathFunction' */

/* Real-time model */
RT_MODEL_Math_Function Math_Function_M_;
RT_MODEL_Math_Function *const Math_Function_M = &Math_Function_M_;

/* Model step function */
void Math_Function_step(void)
{
  /* Math: '<Root>/MathFunction' incorporates:
   *  Inport: '<Root>/In1'
   *
   * About '<Root>/MathFunction':
   *  Operator: exp
   */
  Math_Function_MathFunction_1 = exp(Math_Function_In1_1);
}

/* Model initialize function */
void Math_Function_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Math_Function_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Math_Function_MathFunction_1 = 0.0;

  /* external inputs */
  Math_Function_In1_1 = 0.0;
}

/* Model terminate function */
void Math_Function_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
