/*
 * File: SubsystemAtomic.c
 *
 * Code generated for Simulink model 'SubsystemAtomic'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:10 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SubsystemAtomic.h"
#include "SubsystemAtomic_private.h"

/* Exported block signals */
real_T SubsystemAtomic_In1_1;          /* '<Root>/In1' */

/* External outputs (root outports fed by signals with auto storage) */
ExtY_SubsystemAtomic_T SubsystemAtomic_Y;

/* Real-time model */
RT_MODEL_SubsystemAtomic_T SubsystemAtomic_M_;
RT_MODEL_SubsystemAtomic_T *const SubsystemAtomic_M = &SubsystemAtomic_M_;

/* Model step function */
void SubsystemAtomic_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<S1>/In1'
   */
  SubsystemAtomic_Y.Out1 = SubsystemAtomic_In1_1;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model initialize function */
void SubsystemAtomic_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SubsystemAtomic_M, (NULL));

  /* external inputs */
  SubsystemAtomic_In1_1 = 0.0;

  /* external outputs */
  SubsystemAtomic_Y.Out1 = 0.0;
}

/* Model terminate function */
void SubsystemAtomic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
