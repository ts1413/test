/*
 * File: Rate_Transition_ZOH.c
 *
 * Code generated for Simulink model 'Rate_Transition_ZOH'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:41:18 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rate_Transition_ZOH.h"
#include "Rate_Transition_ZOH_private.h"

/* Exported block signals */
real_T Rate_Transition_ZOH_In1_1;      /* '<Root>/In1' */
real_T Rate_Transition_ZOH_RateTransition_1;/* '<Root>/RateTransition' */

/* Real-time model */
RT_MODEL_Rate_Transition_ZOH_T Rate_Transition_ZOH_M_;
RT_MODEL_Rate_Transition_ZOH_T *const Rate_Transition_ZOH_M =
  &Rate_Transition_ZOH_M_;

/* Model step function for TID0 */
void Rate_Transition_ZOH_step0(void)   /* Sample time: [0.1s, 0.0s] */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [0.2s, 0.0s]  */
  (Rate_Transition_ZOH_M->Timing.RateInteraction.TID0_1)++;
  if ((Rate_Transition_ZOH_M->Timing.RateInteraction.TID0_1) > 1) {
    Rate_Transition_ZOH_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<Root>/RateTransition' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (Rate_Transition_ZOH_M->Timing.RateInteraction.TID0_1 == 1) {
    Rate_Transition_ZOH_RateTransition_1 = Rate_Transition_ZOH_In1_1;
  }

  /* End of RateTransition: '<Root>/RateTransition' */
}

/* Model step function for TID1 */
void Rate_Transition_ZOH_step1(void)   /* Sample time: [0.2s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Rate_Transition_ZOH_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Rate_Transition_ZOH_M, 0,
                sizeof(RT_MODEL_Rate_Transition_ZOH_T));

  /* block I/O */

  /* exported global signals */
  Rate_Transition_ZOH_RateTransition_1 = 0.0;

  /* external inputs */
  Rate_Transition_ZOH_In1_1 = 0.0;
}

/* Model terminate function */
void Rate_Transition_ZOH_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
