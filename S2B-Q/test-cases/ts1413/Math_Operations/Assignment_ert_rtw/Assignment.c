/*
 * File: Assignment.c
 *
 * Code generated for Simulink model 'Assignment'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:48 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment.h"
#include "Assignment_private.h"

/* Exported block signals */
real_T Assignment_In1_1;               /* '<Root>/In1' */
real_T Assignment_Constant_1[4];       /* '<Root>/Constant' */
real_T Assignment_Assignment_1[4];     /* '<Root>/Assignment' */

/* Real-time model */
RT_MODEL_Assignment Assignment_M_;
RT_MODEL_Assignment *const Assignment_M = &Assignment_M_;

/* Model step function */
void Assignment_step(void)
{
  /* Assignment: '<Root>/Assignment' incorporates:
   *  Inport: '<Root>/In1'
   */
  Assignment_Assignment_1[0] = Assignment_Constant_1[0];
  Assignment_Assignment_1[1] = Assignment_Constant_1[1];
  Assignment_Assignment_1[2] = Assignment_Constant_1[2];
  Assignment_Assignment_1[3] = Assignment_Constant_1[3];
  Assignment_Assignment_1[2] = Assignment_In1_1;
}

/* Model initialize function */
void Assignment_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Assignment_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Assignment_Constant_1[0] = 0.0;
  Assignment_Constant_1[1] = 0.0;
  Assignment_Constant_1[2] = 0.0;
  Assignment_Constant_1[3] = 0.0;
  Assignment_Assignment_1[0] = 0.0;
  Assignment_Assignment_1[1] = 0.0;
  Assignment_Assignment_1[2] = 0.0;
  Assignment_Assignment_1[3] = 0.0;

  /* external inputs */
  Assignment_In1_1 = 0.0;

  /* ConstCode for Constant: '<Root>/Constant' */
  Assignment_Constant_1[0] = 0.0;
  Assignment_Constant_1[1] = 0.0;
  Assignment_Constant_1[2] = 0.0;
  Assignment_Constant_1[3] = 0.0;
}

/* Model terminate function */
void Assignment_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
