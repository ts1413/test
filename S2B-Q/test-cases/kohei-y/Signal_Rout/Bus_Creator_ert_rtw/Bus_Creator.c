/*
 * File: Bus_Creator.c
 *
 * Code generated for Simulink model 'Bus_Creator'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:32:58 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Bus_Creator.h"
#include "Bus_Creator_private.h"

/* Exported block signals */
real_T Bus_Creator_In1_x;              /* '<Root>/In1' */
real_T Bus_Creator_In2_y;              /* '<Root>/In2' */

/* Real-time model */
RT_MODEL_Bus_Creator_T Bus_Creator_M_;
RT_MODEL_Bus_Creator_T *const Bus_Creator_M = &Bus_Creator_M_;

/* Model step function */
void Bus_Creator_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Bus_Creator_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Bus_Creator_M, (NULL));

  /* external inputs */
  Bus_Creator_In1_x = 0.0;
  Bus_Creator_In2_y = 0.0;
}

/* Model terminate function */
void Bus_Creator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
