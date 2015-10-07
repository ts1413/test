/*
 * File: Scope1.c
 *
 * Code generated for Simulink model 'Scope1'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:52 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Scope1.h"
#include "Scope1_private.h"

/* Block states (auto storage) */
DW_Scope1_T Scope1_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Scope1_T Scope1_U;

/* Real-time model */
RT_MODEL_Scope1_T Scope1_M_;
RT_MODEL_Scope1_T *const Scope1_M = &Scope1_M_;

/* Model step function */
void Scope1_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Scope1_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Scope1_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Scope1_DW, 0,
                sizeof(DW_Scope1_T));

  /* external inputs */
  Scope1_U.In1 = 0.0;
}

/* Model terminate function */
void Scope1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
