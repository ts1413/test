/*
 * File: while_iterator_subsystem.c
 *
 * Code generated for Simulink model 'while_iterator_subsystem'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:42:26 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "while_iterator_subsystem.h"
#include "while_iterator_subsystem_private.h"

/* Exported block signals */
boolean_T while_iterator_subsystem_In1_1;/* '<Root>/In1' */
boolean_T while_iterator_subsystem_In2_1;/* '<Root>/In2' */

/* External outputs (root outports fed by signals with auto storage) */
ExtY_while_iterator_subsystem_T while_iterator_subsystem_Y;

/* Real-time model */
RT_MODEL_while_iterator_subsy_T while_iterator_subsystem_M_;
RT_MODEL_while_iterator_subsy_T *const while_iterator_subsystem_M =
  &while_iterator_subsystem_M_;

/* Model step function */
void while_iterator_subsystem_step(void)
{
  int32_T s1_iter;
  boolean_T loopCond;

  /* Outputs for Iterator SubSystem: '<Root>/WhileIteratorSubsystem' incorporates:
   *  WhileIterator: '<S1>/WhileIterator'
   */
  s1_iter = 1;

  /* Inport: '<Root>/In2' */
  loopCond = while_iterator_subsystem_In2_1;
  while (loopCond && (s1_iter <= 5)) {
    /* Outport: '<Root>/Out1' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<S1>/In1'
     */
    while_iterator_subsystem_Y.Out1 = while_iterator_subsystem_In1_1;
    loopCond = while_iterator_subsystem_Y.Out1;
    s1_iter++;
  }

  /* End of Outputs for SubSystem: '<Root>/WhileIteratorSubsystem' */
}

/* Model initialize function */
void while_iterator_subsystem_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(while_iterator_subsystem_M, (NULL));

  /* external inputs */
  while_iterator_subsystem_In1_1 = false;
  while_iterator_subsystem_In2_1 = false;

  /* external outputs */
  while_iterator_subsystem_Y.Out1 = false;

  /* Start for Iterator SubSystem: '<Root>/WhileIteratorSubsystem' */
  /* VirtualOutportStart for Outport: '<Root>/Out1' incorporates:
   *  VirtualOutportStart for Outport: '<S1>/Out1'
   */
  while_iterator_subsystem_Y.Out1 = while_iterator_subsystem_P.Out1_Y0;

  /* End of Start for SubSystem: '<Root>/WhileIteratorSubsystem' */
}

/* Model terminate function */
void while_iterator_subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
