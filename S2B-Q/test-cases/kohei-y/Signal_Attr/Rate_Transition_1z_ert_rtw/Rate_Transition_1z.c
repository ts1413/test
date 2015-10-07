/*
 * File: Rate_Transition_1z.c
 *
 * Code generated for Simulink model 'Rate_Transition_1z'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:06:21 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rate_Transition_1z.h"
#include "Rate_Transition_1z_private.h"

/* Exported block signals */
real_T Rate_Transition_Copy_In1_1;     /* '<Root>/In1' */
real_T Rate_Transition_Copy_RateTransition_1;/* '<Root>/RateTransition' */

/* Block states (auto storage) */
DW_Rate_Transition_1z_T Rate_Transition_1z_DW;

/* Real-time model */
RT_MODEL_Rate_Transition_1z_T Rate_Transition_1z_M_;
RT_MODEL_Rate_Transition_1z_T *const Rate_Transition_1z_M =
  &Rate_Transition_1z_M_;

/* Model step function for TID0 */
void Rate_Transition_1z_step0(void)    /* Sample time: [0.1s, 0.0s] */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [0.5s, 0.0s]  */
  (Rate_Transition_1z_M->Timing.RateInteraction.TID0_1)++;
  if ((Rate_Transition_1z_M->Timing.RateInteraction.TID0_1) > 4) {
    Rate_Transition_1z_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<Root>/RateTransition' */
  if (Rate_Transition_1z_M->Timing.RateInteraction.TID0_1 == 1) {
    Rate_Transition_Copy_RateTransition_1 =
      Rate_Transition_1z_DW.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<Root>/RateTransition' */
}

/* Model step function for TID1 */
void Rate_Transition_1z_step1(void)    /* Sample time: [0.5s, 0.0s] */
{
  /* Update for RateTransition: '<Root>/RateTransition' incorporates:
   *  Update for Inport: '<Root>/In1'
   */
  Rate_Transition_1z_DW.RateTransition_Buffer0 = Rate_Transition_Copy_In1_1;
}

/* Model initialize function */
void Rate_Transition_1z_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Rate_Transition_1z_M, 0,
                sizeof(RT_MODEL_Rate_Transition_1z_T));

  /* block I/O */

  /* exported global signals */
  Rate_Transition_Copy_RateTransition_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&Rate_Transition_1z_DW, 0,
                sizeof(DW_Rate_Transition_1z_T));

  /* external inputs */
  Rate_Transition_Copy_In1_1 = 0.0;

  /* InitializeConditions for RateTransition: '<Root>/RateTransition' */
  Rate_Transition_1z_DW.RateTransition_Buffer0 =
    Rate_Transition_1z_P.RateTransition_X0;
}

/* Model terminate function */
void Rate_Transition_1z_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
