/*
 * File: Gain2.c
 *
 * Code generated for Simulink model 'Gain2'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:54:51 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Gain2.h"
#include "Gain2_private.h"

/* Exported block signals */
real_T Gain2_In1_1;                    /* '<Root>/In1' */
real_T Gain2_VectorConcatenate_1[2];   /* '<Root>/VectorConcatenate' */
real_T Gain2_Gain_1;                   /* '<Root>/Gain' */

/* Real-time model */
RT_MODEL_Gain2_T Gain2_M_;
RT_MODEL_Gain2_T *const Gain2_M = &Gain2_M_;

/* Model step function */
void Gain2_step(void)
{
  real_T tmp;

  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain2_VectorConcatenate_1[0] = Gain2_In1_1;

  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn2' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain2_VectorConcatenate_1[1] = Gain2_In1_1;

  /* Gain: '<Root>/Gain' */
  tmp = Gain2_P.Gain_Gain[0] * Gain2_VectorConcatenate_1[0];
  tmp += Gain2_P.Gain_Gain[1] * Gain2_VectorConcatenate_1[1];
  Gain2_Gain_1 = tmp;
}

/* Model initialize function */
void Gain2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Gain2_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Gain2_VectorConcatenate_1[0] = 0.0;
  Gain2_VectorConcatenate_1[1] = 0.0;
  Gain2_Gain_1 = 0.0;

  /* external inputs */
  Gain2_In1_1 = 0.0;
}

/* Model terminate function */
void Gain2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
