/*
 * File: LogicalOperator.c
 *
 * Code generated for Simulink model 'LogicalOperator'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:19 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LogicalOperator.h"
#include "LogicalOperator_private.h"

/* Exported block signals */
boolean_T LogicalOperator_In1_1;       /* '<Root>/In1' */
boolean_T LogicalOperator_In2_1;       /* '<Root>/In2' */
boolean_T LogicalOperator_LogicalOperator_1;/* '<Root>/LogicalOperator' */

/* Real-time model */
RT_MODEL_LogicalOperator_T LogicalOperator_M_;
RT_MODEL_LogicalOperator_T *const LogicalOperator_M = &LogicalOperator_M_;

/* Model step function */
void LogicalOperator_step(void)
{
  /* Logic: '<Root>/LogicalOperator' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  LogicalOperator_LogicalOperator_1 = (LogicalOperator_In1_1 &&
    LogicalOperator_In2_1);
}

/* Model initialize function */
void LogicalOperator_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(LogicalOperator_M, (NULL));

  /* block I/O */

  /* exported global signals */
  LogicalOperator_LogicalOperator_1 = false;

  /* external inputs */
  LogicalOperator_In1_1 = false;
  LogicalOperator_In2_1 = false;
}

/* Model terminate function */
void LogicalOperator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
