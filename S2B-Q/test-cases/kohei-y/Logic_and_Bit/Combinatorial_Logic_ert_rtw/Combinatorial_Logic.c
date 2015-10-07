/*
 * File: Combinatorial_Logic.c
 *
 * Code generated for Simulink model 'Combinatorial_Logic'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:40:13 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Combinatorial_Logic.h"
#include "Combinatorial_Logic_private.h"

/* Exported block signals */
boolean_T Combinatorial_Logic_In1_1[3];/* '<Root>/In1' */
boolean_T Combinatorial_Logic_CombinatorialLogic_1[2];/* '<Root>/CombinatorialLogic' */

/* Real-time model */
RT_MODEL_Combinatorial_Logic_T Combinatorial_Logic_M_;
RT_MODEL_Combinatorial_Logic_T *const Combinatorial_Logic_M =
  &Combinatorial_Logic_M_;

/* Model step function */
void Combinatorial_Logic_step(void)
{
  int32_T rowIdx;

  /* CombinatorialLogic: '<Root>/CombinatorialLogic' incorporates:
   *  Inport: '<Root>/In1'
   */
  rowIdx = Combinatorial_Logic_In1_1[0U];
  rowIdx = (int32_T)(((uint32_T)rowIdx << 1) + Combinatorial_Logic_In1_1[1U]);
  rowIdx = (int32_T)(((uint32_T)rowIdx << 1) + Combinatorial_Logic_In1_1[2U]);
  Combinatorial_Logic_CombinatorialLogic_1[0U] =
    Combinatorial_Logic_P.CombinatorialLogic_table[(uint32_T)rowIdx];
  Combinatorial_Logic_CombinatorialLogic_1[1U] =
    Combinatorial_Logic_P.CombinatorialLogic_table[rowIdx + 8U];
}

/* Model initialize function */
void Combinatorial_Logic_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Combinatorial_Logic_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Combinatorial_Logic_CombinatorialLogic_1[0] = false;
  Combinatorial_Logic_CombinatorialLogic_1[1] = false;

  /* external inputs */
  (void) memset(Combinatorial_Logic_In1_1, 0,
                3U*sizeof(boolean_T));
}

/* Model terminate function */
void Combinatorial_Logic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
