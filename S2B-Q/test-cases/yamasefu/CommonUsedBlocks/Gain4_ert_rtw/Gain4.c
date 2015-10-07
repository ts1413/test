/*
 * File: Gain4.c
 *
 * Code generated for Simulink model 'Gain4'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:02 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Gain4.h"
#include "Gain4_private.h"

/* Exported block signals */
real_T Gain4_In1_1;                    /* '<Root>/In1' */
real_T Gain4_VectorConcatenate_1[2];   /* '<Root>/VectorConcatenate' */
real_T Gain4_Gain_1;                   /* '<Root>/Gain' */

/* Real-time model */
RT_MODEL_Gain4_T Gain4_M_;
RT_MODEL_Gain4_T *const Gain4_M = &Gain4_M_;

/* Model step function */
void Gain4_step(void)
{
  real_T tmp;

  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain4_VectorConcatenate_1[0] = Gain4_In1_1;

  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn2' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain4_VectorConcatenate_1[1] = Gain4_In1_1;

  /* Gain: '<Root>/Gain' */
  tmp = Gain4_P.Gain_Gain[0] * Gain4_VectorConcatenate_1[0];
  tmp += Gain4_P.Gain_Gain[1] * Gain4_VectorConcatenate_1[1];
  Gain4_Gain_1 = tmp;
}

/* Model initialize function */
void Gain4_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Gain4_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Gain4_VectorConcatenate_1[0] = 0.0;
  Gain4_VectorConcatenate_1[1] = 0.0;
  Gain4_Gain_1 = 0.0;

  /* external inputs */
  Gain4_In1_1 = 0.0;
}

/* Model terminate function */
void Gain4_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
