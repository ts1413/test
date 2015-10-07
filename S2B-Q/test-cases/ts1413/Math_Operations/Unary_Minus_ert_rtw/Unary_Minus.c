/*
 * File: Unary_Minus.c
 *
 * Code generated for Simulink model 'Unary_Minus'.
 *
 * Model version                  : 1.90
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:03 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Unary_Minus.h"
#include "Unary_Minus_private.h"

/* Exported block signals */
real_T Unary_Minus_In1_1;              /* '<Root>/In1' */
real_T Unary_Minus_UnaryMinus_1;       /* '<Root>/UnaryMinus' */

/* Real-time model */
RT_MODEL_Unary_Minus Unary_Minus_M_;
RT_MODEL_Unary_Minus *const Unary_Minus_M = &Unary_Minus_M_;

/* Model step function */
void Unary_Minus_step(void)
{
  /* UnaryMinus: '<Root>/UnaryMinus' incorporates:
   *  Inport: '<Root>/In1'
   */
  Unary_Minus_UnaryMinus_1 = -Unary_Minus_In1_1;
}

/* Model initialize function */
void Unary_Minus_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Unary_Minus_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Unary_Minus_UnaryMinus_1 = 0.0;

  /* external inputs */
  Unary_Minus_In1_1 = 0.0;
}

/* Model terminate function */
void Unary_Minus_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
