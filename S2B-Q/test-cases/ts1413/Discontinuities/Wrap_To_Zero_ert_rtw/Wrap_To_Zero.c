/*
 * File: Wrap_To_Zero.c
 *
 * Code generated for Simulink model 'Wrap_To_Zero'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:41 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Wrap_To_Zero.h"
#include "Wrap_To_Zero_private.h"

/* Exported block signals */
real_T Wrap_To_Zero_In1_1;             /* '<Root>/In1' */

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Wrap_To_Zero Wrap_To_Zero_Y;

/* Real-time model */
RT_MODEL_Wrap_To_Zero Wrap_To_Zero_M_;
RT_MODEL_Wrap_To_Zero *const Wrap_To_Zero_M = &Wrap_To_Zero_M_;

/* Model step function */
void Wrap_To_Zero_step(void)
{
  /* Switch: '<S1>/FixPt Switch' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (Wrap_To_Zero_In1_1 > 255.0) {
    /* Outport: '<Root>/Out1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    Wrap_To_Zero_Y.Out1 = 0.0;
  } else {
    /* Outport: '<Root>/Out1' */
    Wrap_To_Zero_Y.Out1 = Wrap_To_Zero_In1_1;
  }

  /* End of Switch: '<S1>/FixPt Switch' */
}

/* Model initialize function */
void Wrap_To_Zero_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Wrap_To_Zero_M, (NULL));

  /* external inputs */
  Wrap_To_Zero_In1_1 = 0.0;

  /* external outputs */
  Wrap_To_Zero_Y.Out1 = 0.0;
}

/* Model terminate function */
void Wrap_To_Zero_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
