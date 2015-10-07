/*
 * File: Bias.c
 *
 * Code generated for Simulink model 'Bias'.
 *
 * Model version                  : 1.73
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:53 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Bias.h"
#include "Bias_private.h"

/* Exported block signals */
real_T Bias_In1_1;                     /* '<Root>/In1' */
real_T Bias_Bias_1;                    /* '<Root>/Bias' */

/* Real-time model */
RT_MODEL_Bias Bias_M_;
RT_MODEL_Bias *const Bias_M = &Bias_M_;

/* Model step function */
void Bias_step(void)
{
  /* Bias: '<Root>/Bias' incorporates:
   *  Inport: '<Root>/In1'
   */
  Bias_Bias_1 = Bias_In1_1 + 10.0;
}

/* Model initialize function */
void Bias_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Bias_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Bias_Bias_1 = 0.0;

  /* external inputs */
  Bias_In1_1 = 0.0;
}

/* Model terminate function */
void Bias_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
