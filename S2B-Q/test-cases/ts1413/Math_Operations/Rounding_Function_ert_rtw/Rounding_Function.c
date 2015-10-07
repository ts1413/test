/*
 * File: Rounding_Function.c
 *
 * Code generated for Simulink model 'Rounding_Function'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:40:34 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rounding_Function.h"
#include "Rounding_Function_private.h"

/* Exported block signals */
real_T Rounding_Function_In1_1;        /* '<Root>/In1' */
real_T Rounding_Function_RoundingFunction_1;/* '<Root>/RoundingFunction' */

/* Real-time model */
RT_MODEL_Rounding_Function Rounding_Function_M_;
RT_MODEL_Rounding_Function *const Rounding_Function_M = &Rounding_Function_M_;

/* Model step function */
void Rounding_Function_step(void)
{
  /* Rounding: '<Root>/RoundingFunction' incorporates:
   *  Inport: '<Root>/In1'
   */
  Rounding_Function_RoundingFunction_1 = floor(Rounding_Function_In1_1);
}

/* Model initialize function */
void Rounding_Function_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Rounding_Function_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Rounding_Function_RoundingFunction_1 = 0.0;

  /* external inputs */
  Rounding_Function_In1_1 = 0.0;
}

/* Model terminate function */
void Rounding_Function_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
