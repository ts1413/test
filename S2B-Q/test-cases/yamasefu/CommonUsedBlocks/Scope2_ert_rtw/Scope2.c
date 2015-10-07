/*
 * File: Scope2.c
 *
 * Code generated for Simulink model 'Scope2'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:58 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Scope2.h"
#include "Scope2_private.h"

/* Block states (auto storage) */
DW_Scope2_T Scope2_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Scope2_T Scope2_U;

/* Real-time model */
RT_MODEL_Scope2_T Scope2_M_;
RT_MODEL_Scope2_T *const Scope2_M = &Scope2_M_;

/* Model step function */
void Scope2_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Scope2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Scope2_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Scope2_DW, 0,
                sizeof(DW_Scope2_T));

  /* external inputs */
  Scope2_U.In1 = 0.0;
}

/* Model terminate function */
void Scope2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
