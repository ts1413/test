/*
 * File: ZeroOrder_Hold.c
 *
 * Code generated for Simulink model 'ZeroOrder_Hold'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:30 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ZeroOrder_Hold.h"
#include "ZeroOrder_Hold_private.h"

/* Exported block signals */
real_T ZeroOrder_Hold_In1_1;           /* '<Root>/In1' */
real_T ZeroOrder_Hold_Zero_OrderHold_1;/* '<Root>/Zero_OrderHold' */

/* Real-time model */
RT_MODEL_ZeroOrder_Hold ZeroOrder_Hold_M_;
RT_MODEL_ZeroOrder_Hold *const ZeroOrder_Hold_M = &ZeroOrder_Hold_M_;

/* Model step function */
void ZeroOrder_Hold_step(void)
{
  /* ZeroOrderHold: '<Root>/Zero_OrderHold' incorporates:
   *  Inport: '<Root>/In1'
   */
  ZeroOrder_Hold_Zero_OrderHold_1 = ZeroOrder_Hold_In1_1;
}

/* Model initialize function */
void ZeroOrder_Hold_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ZeroOrder_Hold_M, (NULL));

  /* block I/O */

  /* exported global signals */
  ZeroOrder_Hold_Zero_OrderHold_1 = 0.0;

  /* external inputs */
  ZeroOrder_Hold_In1_1 = 0.0;
}

/* Model terminate function */
void ZeroOrder_Hold_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
