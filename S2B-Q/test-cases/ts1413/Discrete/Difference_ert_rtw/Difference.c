/*
 * File: Difference.c
 *
 * Code generated for Simulink model 'Difference'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:47 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Difference.h"
#include "Difference_private.h"

/* Exported block signals */
real_T Difference_In1_1;               /* '<Root>/In1' */

/* Block signals (auto storage) */
BlockIO_Difference Difference_B;

/* Block states (auto storage) */
D_Work_Difference Difference_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Difference Difference_Y;

/* Real-time model */
RT_MODEL_Difference Difference_M_;
RT_MODEL_Difference *const Difference_M = &Difference_M_;

/* Model step function */
void Difference_step(void)
{
  /* UnitDelay: '<S1>/UD' */
  Difference_B.Uk1 = Difference_DWork.UD_DSTATE;

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Sum: '<S1>/Diff'
   */
  Difference_Y.Out1 = Difference_In1_1 - Difference_B.Uk1;

  /* Update for UnitDelay: '<S1>/UD' incorporates:
   *  Inport: '<Root>/In1'
   */
  Difference_DWork.UD_DSTATE = Difference_In1_1;
}

/* Model initialize function */
void Difference_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Difference_M, (NULL));

  /* block I/O */
  {
    Difference_B.Uk1 = 0.0;
  }

  /* states (dwork) */
  Difference_DWork.UD_DSTATE = 0.0;

  /* external inputs */
  Difference_In1_1 = 0.0;

  /* external outputs */
  Difference_Y.Out1 = 0.0;
}

/* Model terminate function */
void Difference_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
