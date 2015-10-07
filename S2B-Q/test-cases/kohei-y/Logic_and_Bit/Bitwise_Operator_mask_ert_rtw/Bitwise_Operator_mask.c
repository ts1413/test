/*
 * File: Bitwise_Operator_mask.c
 *
 * Code generated for Simulink model 'Bitwise_Operator_mask'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:46:35 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Bitwise_Operator_mask.h"
#include "Bitwise_Operator_mask_private.h"

/* Exported block signals */
int8_T Bitwise_Operator_mask_In1_1;    /* '<Root>/In1' */
int8_T Bitwise_Operator_mask_BitwiseOperator_1;/* '<Root>/BitwiseOperator' */

/* Real-time model */
RT_MODEL_Bitwise_Operator_mas_T Bitwise_Operator_mask_M_;
RT_MODEL_Bitwise_Operator_mas_T *const Bitwise_Operator_mask_M =
  &Bitwise_Operator_mask_M_;

/* Model step function */
void Bitwise_Operator_mask_step(void)
{
  /* S-Function (sfix_bitop): '<Root>/BitwiseOperator' incorporates:
   *  Inport: '<Root>/In1'
   */
  Bitwise_Operator_mask_BitwiseOperator_1 = (int8_T)(Bitwise_Operator_mask_In1_1
    & Bitwise_Operator_mask_P.BitwiseOperator_BitMask);
}

/* Model initialize function */
void Bitwise_Operator_mask_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Bitwise_Operator_mask_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Bitwise_Operator_mask_BitwiseOperator_1 = 0;

  /* external inputs */
  Bitwise_Operator_mask_In1_1 = 0;
}

/* Model terminate function */
void Bitwise_Operator_mask_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
