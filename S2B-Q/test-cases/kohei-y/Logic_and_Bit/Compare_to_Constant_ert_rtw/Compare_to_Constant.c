/*
 * File: Compare_to_Constant.c
 *
 * Code generated for Simulink model 'Compare_to_Constant'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:40:19 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Compare_to_Constant.h"
#include "Compare_to_Constant_private.h"

/* Exported block signals */
real_T Compare_to_Constant_In1_1;      /* '<Root>/In1' */

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Compare_to_Constant_T Compare_to_Constant_Y;

/* Real-time model */
RT_MODEL_Compare_to_Constant_T Compare_to_Constant_M_;
RT_MODEL_Compare_to_Constant_T *const Compare_to_Constant_M =
  &Compare_to_Constant_M_;

/* Model step function */
void Compare_to_Constant_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/In1'
   *  RelationalOperator: '<S1>/Compare'
   */
  Compare_to_Constant_Y.Out1 = (Compare_to_Constant_In1_1 <=
    Compare_to_Constant_P.CompareToConstant_const);
}

/* Model initialize function */
void Compare_to_Constant_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Compare_to_Constant_M, (NULL));

  /* external inputs */
  Compare_to_Constant_In1_1 = 0.0;

  /* external outputs */
  Compare_to_Constant_Y.Out1 = false;
}

/* Model terminate function */
void Compare_to_Constant_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
