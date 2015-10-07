/*
 * File: for_iterator_subsystem.c
 *
 * Code generated for Simulink model 'for_iterator_subsystem'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sat Oct  3 23:52:48 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "for_iterator_subsystem.h"
#include "for_iterator_subsystem_private.h"

/* Exported block signals */
int8_T for_iterator_subsystem_In1_1;   /* '<Root>/In1' */
int16_T for_iterator_subsystem_ForIteratorSubsystem_Product_1;/* '<S1>/Product' */
int8_T for_iterator_subsystem_ForIteratorSubsystem_ForIterator_1;/* '<S1>/ForIterator' */

/* Real-time model */
RT_MODEL_for_iterator_subsyst_T for_iterator_subsystem_M_;
RT_MODEL_for_iterator_subsyst_T *const for_iterator_subsystem_M =
  &for_iterator_subsystem_M_;

/* Model step function */
void for_iterator_subsystem_step(void)
{
  int8_T s1_iter;

  /* Outputs for Iterator SubSystem: '<Root>/ForIteratorSubsystem' incorporates:
   *  ForIterator: '<S1>/ForIterator'
   */
  for (s1_iter = 1; s1_iter <=
       for_iterator_subsystem_P.ForIterator_IterationLimit; s1_iter++) {
    for_iterator_subsystem_ForIteratorSubsystem_ForIterator_1 = s1_iter;

    /* Product: '<S1>/Product' incorporates:
     *  Inport: '<Root>/In1'
     */
    for_iterator_subsystem_ForIteratorSubsystem_Product_1 = (int16_T)
      (for_iterator_subsystem_ForIteratorSubsystem_ForIterator_1 *
       for_iterator_subsystem_In1_1);
  }

  /* End of Outputs for SubSystem: '<Root>/ForIteratorSubsystem' */
}

/* Model initialize function */
void for_iterator_subsystem_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(for_iterator_subsystem_M, (NULL));

  /* block I/O */

  /* exported global signals */
  for_iterator_subsystem_ForIteratorSubsystem_Product_1 = 0;
  for_iterator_subsystem_ForIteratorSubsystem_ForIterator_1 = 0;

  /* external inputs */
  for_iterator_subsystem_In1_1 = 0;

  /* Start for Iterator SubSystem: '<Root>/ForIteratorSubsystem' */
  /* VirtualOutportStart for Outport: '<S1>/Out1' */
  for_iterator_subsystem_ForIteratorSubsystem_Product_1 =
    for_iterator_subsystem_P.Out1_Y0;

  /* End of Start for SubSystem: '<Root>/ForIteratorSubsystem' */
}

/* Model terminate function */
void for_iterator_subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
