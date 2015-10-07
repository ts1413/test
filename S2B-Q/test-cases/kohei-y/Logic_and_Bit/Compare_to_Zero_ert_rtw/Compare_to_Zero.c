/*
 * File: Compare_to_Zero.c
 *
 * Code generated for Simulink model 'Compare_to_Zero'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:51:02 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Compare_to_Zero.h"
#include "Compare_to_Zero_private.h"

/* Exported block signals */
real_T Compare_to_Zero_In1_1;          /* '<Root>/In1' */

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Compare_to_Zero_T Compare_to_Zero_Y;

/* Real-time model */
RT_MODEL_Compare_to_Zero_T Compare_to_Zero_M_;
RT_MODEL_Compare_to_Zero_T *const Compare_to_Zero_M = &Compare_to_Zero_M_;

/* Model step function */
void Compare_to_Zero_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/In1'
   *  RelationalOperator: '<S1>/Compare'
   */
  Compare_to_Zero_Y.Out1 = (Compare_to_Zero_In1_1 <=
    Compare_to_Zero_P.Constant_Value);
}

/* Model initialize function */
void Compare_to_Zero_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Compare_to_Zero_M, (NULL));

  /* external inputs */
  Compare_to_Zero_In1_1 = 0.0;

  /* external outputs */
  Compare_to_Zero_Y.Out1 = false;
}

/* Model terminate function */
void Compare_to_Zero_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
