/*
 * File: enable_subsystem.c
 *
 * Code generated for Simulink model 'enable_subsystem'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:31 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "enable_subsystem.h"
#include "enable_subsystem_private.h"

/* Exported block signals */
real_T enable_subsystem_In1_1;         /* '<Root>/In1' */
real_T enable_subsystem_In2_1;         /* '<Root>/In2' */

/* External outputs (root outports fed by signals with auto storage) */
ExtY_enable_subsystem_T enable_subsystem_Y;

/* Real-time model */
RT_MODEL_enable_subsystem_T enable_subsystem_M_;
RT_MODEL_enable_subsystem_T *const enable_subsystem_M = &enable_subsystem_M_;

/* Model step function */
void enable_subsystem_step(void)
{
  /* Outputs for Enabled SubSystem: '<Root>/EnabledSubsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* Inport: '<Root>/In2' */
  if (enable_subsystem_In2_1 > 0.0) {
    /* Outport: '<Root>/Out1' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<S1>/In1'
     */
    enable_subsystem_Y.Out1 = enable_subsystem_In1_1;
  }

  /* End of Inport: '<Root>/In2' */
  /* End of Outputs for SubSystem: '<Root>/EnabledSubsystem' */
}

/* Model initialize function */
void enable_subsystem_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(enable_subsystem_M, (NULL));

  /* external inputs */
  enable_subsystem_In1_1 = 0.0;
  enable_subsystem_In2_1 = 0.0;

  /* external outputs */
  enable_subsystem_Y.Out1 = 0.0;

  /* Start for Enabled SubSystem: '<Root>/EnabledSubsystem' */
  /* VirtualOutportStart for Outport: '<Root>/Out1' incorporates:
   *  VirtualOutportStart for Outport: '<S1>/Out1'
   */
  enable_subsystem_Y.Out1 = enable_subsystem_P.Out1_Y0;

  /* End of Start for SubSystem: '<Root>/EnabledSubsystem' */
}

/* Model terminate function */
void enable_subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
