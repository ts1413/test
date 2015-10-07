/*
 * File: Rate_Transition_Buf.c
 *
 * Code generated for Simulink model 'Rate_Transition_Buf'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:06:15 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rate_Transition_Buf.h"
#include "Rate_Transition_Buf_private.h"

/* Exported block signals */
real_T Rate_Transition_DbBuf_In1_1;    /* '<Root>/In1' */
real_T Rate_Transition_DbBuf_RateTransition_1;/* '<Root>/RateTransition' */

/* Block states (auto storage) */
DW_Rate_Transition_Buf_T Rate_Transition_Buf_DW;

/* Real-time model */
RT_MODEL_Rate_Transition_Buf_T Rate_Transition_Buf_M_;
RT_MODEL_Rate_Transition_Buf_T *const Rate_Transition_Buf_M =
  &Rate_Transition_Buf_M_;

/* Model step function for TID0 */
void Rate_Transition_Buf_step0(void)   /* Sample time: [0.1s, 0.0s] */
{
  /* RateTransition: '<Root>/RateTransition' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (!(Rate_Transition_Buf_DW.RateTransition_semaphoreTaken != 0)) {
    Rate_Transition_Buf_DW.RateTransition_Buffer0 = Rate_Transition_DbBuf_In1_1;
  }

  /* End of RateTransition: '<Root>/RateTransition' */
}

/* Model step function for TID1 */
void Rate_Transition_Buf_step1(void)   /* Sample time: [0.2s, 0.0s] */
{
  /* RateTransition: '<Root>/RateTransition' */
  Rate_Transition_Buf_DW.RateTransition_semaphoreTaken = 1;
  Rate_Transition_DbBuf_RateTransition_1 =
    Rate_Transition_Buf_DW.RateTransition_Buffer0;
  Rate_Transition_Buf_DW.RateTransition_semaphoreTaken = 0;
}

/* Model initialize function */
void Rate_Transition_Buf_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Rate_Transition_Buf_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Rate_Transition_DbBuf_RateTransition_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&Rate_Transition_Buf_DW, 0,
                sizeof(DW_Rate_Transition_Buf_T));

  /* external inputs */
  Rate_Transition_DbBuf_In1_1 = 0.0;
}

/* Model terminate function */
void Rate_Transition_Buf_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
