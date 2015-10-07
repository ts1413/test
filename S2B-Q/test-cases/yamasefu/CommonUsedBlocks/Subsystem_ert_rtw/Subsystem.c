/*
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:04 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subsystem.h"
#include "Subsystem_private.h"

/* Exported block signals */
real_T Subsystem_In1_1;                /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;

/* Model step function */
void Subsystem_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Subsystem_M, (NULL));

  /* external inputs */
  Subsystem_In1_1 = 0.0;
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
