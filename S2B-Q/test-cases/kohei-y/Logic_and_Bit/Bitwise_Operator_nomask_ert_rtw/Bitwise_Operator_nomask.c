/*
 * File: Bitwise_Operator_nomask.c
 *
 * Code generated for Simulink model 'Bitwise_Operator_nomask'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:05:32 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Bitwise_Operator_nomask.h"
#include "Bitwise_Operator_nomask_private.h"

/* Exported block signals */
int8_T Bitwise_Operator_nomask_In1_1;  /* '<Root>/In1' */
int8_T Bitwise_Operator_nomask_BitwiseOperator_1;/* '<Root>/BitwiseOperator' */

/* Real-time model */
RT_MODEL_Bitwise_Operator_nom_T Bitwise_Operator_nomask_M_;
RT_MODEL_Bitwise_Operator_nom_T *const Bitwise_Operator_nomask_M =
  &Bitwise_Operator_nomask_M_;

/* Model step function */
void Bitwise_Operator_nomask_step(void)
{
  /* S-Function (sfix_bitop): '<Root>/BitwiseOperator' incorporates:
   *  Inport: '<Root>/In1'
   */
  Bitwise_Operator_nomask_BitwiseOperator_1 = (int8_T)
    ~Bitwise_Operator_nomask_In1_1;
}

/* Model initialize function */
void Bitwise_Operator_nomask_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Bitwise_Operator_nomask_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Bitwise_Operator_nomask_BitwiseOperator_1 = 0;

  /* external inputs */
  Bitwise_Operator_nomask_In1_1 = 0;
}

/* Model terminate function */
void Bitwise_Operator_nomask_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
