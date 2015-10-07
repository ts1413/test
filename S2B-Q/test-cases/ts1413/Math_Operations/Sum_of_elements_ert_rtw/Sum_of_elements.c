/*
 * File: Sum_of_elements.c
 *
 * Code generated for Simulink model 'Sum_of_elements'.
 *
 * Model version                  : 1.91
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:08:32 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Sum_of_elements.h"
#include "Sum_of_elements_private.h"

/* Exported block signals */
real_T Sum_of_elements_In1_1;          /* '<Root>/In1' */
real_T Sum_of_elements_SumofElements_1;/* '<Root>/SumofElements' */

/* Real-time model */
RT_MODEL_Sum_of_elements Sum_of_elements_M_;
RT_MODEL_Sum_of_elements *const Sum_of_elements_M = &Sum_of_elements_M_;

/* Model step function */
void Sum_of_elements_step(void)
{
  real_T tmp;

  /* Sum: '<Root>/SumofElements' incorporates:
   *  Inport: '<Root>/In1'
   */
  tmp = Sum_of_elements_In1_1;
  Sum_of_elements_SumofElements_1 = tmp;
}

/* Model initialize function */
void Sum_of_elements_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Sum_of_elements_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Sum_of_elements_SumofElements_1 = 0.0;

  /* external inputs */
  Sum_of_elements_In1_1 = 0.0;
}

/* Model terminate function */
void Sum_of_elements_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
