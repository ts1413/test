/*
 * File: Bus_Selector.c
 *
 * Code generated for Simulink model 'Bus_Selector'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:35:33 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Bus_Selector.h"
#include "Bus_Selector_private.h"

/* Exported block signals */
real_T Bus_Selector_In1_x;             /* '<Root>/In1' */
real_T Bus_Selector_In2_y;             /* '<Root>/In2' */

/* Real-time model */
RT_MODEL_Bus_Selector_T Bus_Selector_M_;
RT_MODEL_Bus_Selector_T *const Bus_Selector_M = &Bus_Selector_M_;

/* Model step function */
void Bus_Selector_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Bus_Selector_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Bus_Selector_M, (NULL));

  /* external inputs */
  Bus_Selector_In1_x = 0.0;
  Bus_Selector_In2_y = 0.0;
}

/* Model terminate function */
void Bus_Selector_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
