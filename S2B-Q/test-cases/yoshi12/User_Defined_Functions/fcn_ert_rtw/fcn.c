/*
 * File: fcn.c
 *
 * Code generated for Simulink model 'fcn'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:19 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fcn.h"
#include "fcn_private.h"

/* Exported block signals */
real_T fcn_In1_1;                      /* '<Root>/In1' */
real_T fcn_Fcn_1;                      /* '<Root>/Fcn' */

/* Real-time model */
RT_MODEL_fcn_T fcn_M_;
RT_MODEL_fcn_T *const fcn_M = &fcn_M_;

/* Model step function */
void fcn_step(void)
{
  /* Fcn: '<Root>/Fcn' incorporates:
   *  Inport: '<Root>/In1'
   */
  fcn_Fcn_1 = fcn_In1_1 * 5.0;
}

/* Model initialize function */
void fcn_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(fcn_M, (NULL));

  /* block I/O */

  /* exported global signals */
  fcn_Fcn_1 = 0.0;

  /* external inputs */
  fcn_In1_1 = 0.0;
}

/* Model terminate function */
void fcn_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
