/*
 * File: IC.c
 *
 * Code generated for Simulink model 'IC'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:41:00 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IC.h"
#include "IC_private.h"

/* Exported block signals */
real_T IC_In1_1;                       /* '<Root>/In1' */
real_T IC_IC_1;                        /* '<Root>/IC' */

/* Block states (auto storage) */
DW_IC_T IC_DW;

/* Real-time model */
RT_MODEL_IC_T IC_M_;
RT_MODEL_IC_T *const IC_M = &IC_M_;

/* Model step function */
void IC_step(void)
{
  /* InitialCondition: '<Root>/IC' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (IC_DW.IC_FirstOutputTime) {
    IC_DW.IC_FirstOutputTime = false;
    IC_IC_1 = IC_P.IC_Value;
  } else {
    IC_IC_1 = IC_In1_1;
  }

  /* End of InitialCondition: '<Root>/IC' */
}

/* Model initialize function */
void IC_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(IC_M, (NULL));

  /* block I/O */

  /* exported global signals */
  IC_IC_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&IC_DW, 0,
                sizeof(DW_IC_T));

  /* external inputs */
  IC_In1_1 = 0.0;

  /* Start for InitialCondition: '<Root>/IC' */
  IC_DW.IC_FirstOutputTime = true;
}

/* Model terminate function */
void IC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
