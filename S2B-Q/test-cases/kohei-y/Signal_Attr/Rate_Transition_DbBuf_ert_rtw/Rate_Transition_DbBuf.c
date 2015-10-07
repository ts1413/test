/*
 * File: Rate_Transition_DbBuf.c
 *
 * Code generated for Simulink model 'Rate_Transition_DbBuf'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 02:22:47 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rate_Transition_DbBuf.h"
#include "Rate_Transition_DbBuf_private.h"

/* Exported block signals */
real_T Rate_Transition_DbBuf_In1_1;    /* '<Root>/In1' */
real_T Rate_Transition_DbBuf_RateTransition_1;/* '<Root>/RateTransition' */

/* Block states (auto storage) */
DW_Rate_Transition_DbBuf_T Rate_Transition_DbBuf_DW;

/* Real-time model */
RT_MODEL_Rate_Transition_DbBu_T Rate_Transition_DbBuf_M_;
RT_MODEL_Rate_Transition_DbBu_T *const Rate_Transition_DbBuf_M =
  &Rate_Transition_DbBuf_M_;

/* Model step function for TID0 */
void Rate_Transition_DbBuf_step0(void) /* Sample time: [0.1s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void Rate_Transition_DbBuf_step1(void) /* Sample time: [0.2s, 0.0s] */
{
  /* RateTransition: '<Root>/RateTransition' */
  Rate_Transition_DbBuf_RateTransition_1 =
    Rate_Transition_DbBuf_DW.RateTransition_Buffer[Rate_Transition_DbBuf_DW.RateTransition_ActiveBufIdx];
}

/* Model step function for TID2 */
void Rate_Transition_DbBuf_step2(void) /* Sample time: [0.3s, 0.0s] */
{
  /* Update for RateTransition: '<Root>/RateTransition' incorporates:
   *  Update for Inport: '<Root>/In1'
   */
  Rate_Transition_DbBuf_DW.RateTransition_Buffer[Rate_Transition_DbBuf_DW.RateTransition_ActiveBufIdx
    == 0] = Rate_Transition_DbBuf_In1_1;
  Rate_Transition_DbBuf_DW.RateTransition_ActiveBufIdx = (int8_T)
    (Rate_Transition_DbBuf_DW.RateTransition_ActiveBufIdx == 0);
}

/* Model initialize function */
void Rate_Transition_DbBuf_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Rate_Transition_DbBuf_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Rate_Transition_DbBuf_RateTransition_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&Rate_Transition_DbBuf_DW, 0,
                sizeof(DW_Rate_Transition_DbBuf_T));

  /* external inputs */
  Rate_Transition_DbBuf_In1_1 = 0.0;

  /* InitializeConditions for RateTransition: '<Root>/RateTransition' */
  Rate_Transition_DbBuf_DW.RateTransition_Buffer[0] =
    Rate_Transition_DbBuf_P.RateTransition_X0;
}

/* Model terminate function */
void Rate_Transition_DbBuf_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
