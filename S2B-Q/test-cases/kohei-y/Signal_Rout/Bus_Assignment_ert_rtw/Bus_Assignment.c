/*
 * File: Bus_Assignment.c
 *
 * Code generated for Simulink model 'Bus_Assignment'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:31:15 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Bus_Assignment.h"
#include "Bus_Assignment_private.h"

/* Exported block signals */
real_T Bus_Assignment_In1_x;           /* '<Root>/In1' */
real_T Bus_Assignment_In2_y;           /* '<Root>/In2' */
real_T Bus_Assignment_Constant_1;      /* '<Root>/Constant' */

/* Real-time model */
RT_MODEL_Bus_Assignment_T Bus_Assignment_M_;
RT_MODEL_Bus_Assignment_T *const Bus_Assignment_M = &Bus_Assignment_M_;

/* Model step function */
void Bus_Assignment_step(void)
{
  /* Constant: '<Root>/Constant' */
  Bus_Assignment_Constant_1 = Bus_Assignment_P.Constant_Value;
}

/* Model initialize function */
void Bus_Assignment_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Bus_Assignment_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Bus_Assignment_Constant_1 = 0.0;

  /* external inputs */
  Bus_Assignment_In1_x = 0.0;
  Bus_Assignment_In2_y = 0.0;
}

/* Model terminate function */
void Bus_Assignment_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
