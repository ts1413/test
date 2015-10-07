/*
 * File: RelationalOperator.c
 *
 * Code generated for Simulink model 'RelationalOperator'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:41 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RelationalOperator.h"
#include "RelationalOperator_private.h"

/* Exported block signals */
real_T RelationalOperator_In1_1;       /* '<Root>/In1' */
real_T RelationalOperator_In2_1;       /* '<Root>/In2' */
boolean_T RelationalOperator_RelationalOperator_1;/* '<Root>/RelationalOperator' */

/* Real-time model */
RT_MODEL_RelationalOperator_T RelationalOperator_M_;
RT_MODEL_RelationalOperator_T *const RelationalOperator_M =
  &RelationalOperator_M_;

/* Model step function */
void RelationalOperator_step(void)
{
  /* RelationalOperator: '<Root>/RelationalOperator' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  RelationalOperator_RelationalOperator_1 = (RelationalOperator_In1_1 <=
    RelationalOperator_In2_1);
}

/* Model initialize function */
void RelationalOperator_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(RelationalOperator_M, (NULL));

  /* block I/O */

  /* exported global signals */
  RelationalOperator_RelationalOperator_1 = false;

  /* external inputs */
  RelationalOperator_In1_1 = 0.0;
  RelationalOperator_In2_1 = 0.0;
}

/* Model terminate function */
void RelationalOperator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
