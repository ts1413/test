/*
 * File: Discrete_Derivative.c
 *
 * Code generated for Simulink model 'Discrete_Derivative'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:53 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Discrete_Derivative.h"
#include "Discrete_Derivative_private.h"

/* Exported block signals */
real_T Discrete_Derivative_In1_1;      /* '<Root>/In1' */

/* Block signals (auto storage) */
BlockIO_Discrete_Derivative Discrete_Derivative_B;

/* Block states (auto storage) */
D_Work_Discrete_Derivative Discrete_Derivative_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Discrete_Deriva Discrete_Derivative_Y;

/* Real-time model */
RT_MODEL_Discrete_Derivative Discrete_Derivative_M_;
RT_MODEL_Discrete_Derivative *const Discrete_Derivative_M =
  &Discrete_Derivative_M_;

/* Model step function */
void Discrete_Derivative_step(void)
{
  /* SampleTimeMath: '<S1>/TSamp' incorporates:
   *  Inport: '<Root>/In1'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Discrete_Derivative_B.TSamp = Discrete_Derivative_In1_1 * 10.0;

  /* UnitDelay: '<S1>/UD' */
  Discrete_Derivative_B.Uk1 = Discrete_Derivative_DWork.UD_DSTATE;

  /* Outport: '<Root>/Out1' incorporates:
   *  Sum: '<S1>/Diff'
   */
  Discrete_Derivative_Y.Out1 = Discrete_Derivative_B.TSamp -
    Discrete_Derivative_B.Uk1;

  /* Update for UnitDelay: '<S1>/UD' */
  Discrete_Derivative_DWork.UD_DSTATE = Discrete_Derivative_B.TSamp;
}

/* Model initialize function */
void Discrete_Derivative_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Discrete_Derivative_M, (NULL));

  /* block I/O */
  {
    Discrete_Derivative_B.TSamp = 0.0;
    Discrete_Derivative_B.Uk1 = 0.0;
  }

  /* states (dwork) */
  Discrete_Derivative_DWork.UD_DSTATE = 0.0;

  /* external inputs */
  Discrete_Derivative_In1_1 = 0.0;

  /* external outputs */
  Discrete_Derivative_Y.Out1 = 0.0;
}

/* Model terminate function */
void Discrete_Derivative_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
