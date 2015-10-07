/*
 * File: s_function.c
 *
 * Code generated for Simulink model 's_function'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:25 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "s_function.h"
#include "s_function_private.h"

/* Exported block signals */
real_T s_function_In1_1;               /* '<Root>/In1' */
real_T s_function_S_Function_1;        /* '<Root>/S_Function' */

/* Real-time model */
RT_MODEL_s_function_T s_function_M_;
RT_MODEL_s_function_T *const s_function_M = &s_function_M_;

/* Model step function */
void s_function_step(void)
{
  /* S-Function (testest): '<Root>/S_Function' */
  testest_Outputs_wrapper(&s_function_In1_1, &s_function_S_Function_1 );
}

/* Model initialize function */
void s_function_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(s_function_M, (NULL));

  /* block I/O */

  /* exported global signals */
  s_function_S_Function_1 = 0.0;

  /* external inputs */
  s_function_In1_1 = 0.0;
}

/* Model terminate function */
void s_function_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
