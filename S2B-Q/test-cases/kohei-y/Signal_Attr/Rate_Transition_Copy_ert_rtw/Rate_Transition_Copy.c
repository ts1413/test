/*
 * File: Rate_Transition_Copy.c
 *
 * Code generated for Simulink model 'Rate_Transition_Copy'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:06:04 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rate_Transition_Copy.h"
#include "Rate_Transition_Copy_private.h"

/* Exported block signals */
real_T Rate_Transition_Copy_In1_1;     /* '<Root>/In1' */
real_T Rate_Transition_Copy_RateTransition_1;/* '<Root>/RateTransition' */

/* Real-time model */
RT_MODEL_Rate_Transition_Copy_T Rate_Transition_Copy_M_;
RT_MODEL_Rate_Transition_Copy_T *const Rate_Transition_Copy_M =
  &Rate_Transition_Copy_M_;

/* Model step function */
void Rate_Transition_Copy_step(void)
{
  /* RateTransition: '<Root>/RateTransition' incorporates:
   *  Inport: '<Root>/In1'
   */
  Rate_Transition_Copy_RateTransition_1 = Rate_Transition_Copy_In1_1;
}

/* Model initialize function */
void Rate_Transition_Copy_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Rate_Transition_Copy_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Rate_Transition_Copy_RateTransition_1 = 0.0;

  /* external inputs */
  Rate_Transition_Copy_In1_1 = 0.0;
}

/* Model terminate function */
void Rate_Transition_Copy_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
