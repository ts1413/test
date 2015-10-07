/*
 * File: triggered_subsystem.c
 *
 * Code generated for Simulink model 'triggered_subsystem'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:42:20 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "triggered_subsystem.h"
#include "triggered_subsystem_private.h"

/* Exported block signals */
real_T triggered_subsystem_In1_1;      /* '<Root>/In1' */

/* Previous zero-crossings (trigger) states */
PrevZCX_triggered_subsystem_T triggered_subsystem_PrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU_triggered_subsystem_T triggered_subsystem_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_triggered_subsystem_T triggered_subsystem_Y;

/* Real-time model */
RT_MODEL_triggered_subsystem_T triggered_subsystem_M_;
RT_MODEL_triggered_subsystem_T *const triggered_subsystem_M =
  &triggered_subsystem_M_;

/* Model step function */
void triggered_subsystem_step(void)
{
  ZCEventType zcEvent;

  /* Outputs for Triggered SubSystem: '<Root>/TriggeredSubsystem' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  /* Inport: '<Root>/In2' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &triggered_subsystem_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (triggered_subsystem_U.triggered_subsystem_In2_1));
  if (zcEvent != NO_ZCEVENT) {
    /* Outport: '<Root>/Out1' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<S1>/In1'
     */
    triggered_subsystem_Y.Out1 = triggered_subsystem_In1_1;
  }

  /* End of Outputs for SubSystem: '<Root>/TriggeredSubsystem' */
}

/* Model initialize function */
void triggered_subsystem_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(triggered_subsystem_M, (NULL));

  /* external inputs */
  (void) memset((void *)&triggered_subsystem_U, 0,
                sizeof(ExtU_triggered_subsystem_T));
  triggered_subsystem_In1_1 = 0.0;

  /* external outputs */
  triggered_subsystem_Y.Out1 = 0.0;

  /* Start for Triggered SubSystem: '<Root>/TriggeredSubsystem' */
  /* VirtualOutportStart for Outport: '<Root>/Out1' incorporates:
   *  VirtualOutportStart for Outport: '<S1>/Out1'
   */
  triggered_subsystem_Y.Out1 = triggered_subsystem_P.Out1_Y0;

  /* End of Start for SubSystem: '<Root>/TriggeredSubsystem' */
  triggered_subsystem_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void triggered_subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
