/*
 * File: Gain3.c
 *
 * Code generated for Simulink model 'Gain3'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:54:56 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Gain3.h"
#include "Gain3_private.h"

/* Exported block signals */
real_T Gain3_In1_1;                    /* '<Root>/In1' */
real_T Gain3_VectorConcatenate_1[2];   /* '<Root>/VectorConcatenate' */
real_T Gain3_Gain_1[4];                /* '<Root>/Gain' */

/* Real-time model */
RT_MODEL_Gain3_T Gain3_M_;
RT_MODEL_Gain3_T *const Gain3_M = &Gain3_M_;

/* Model step function */
void Gain3_step(void)
{
  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain3_VectorConcatenate_1[0] = Gain3_In1_1;

  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn2' incorporates:
   *  Inport: '<Root>/In1'
   */
  Gain3_VectorConcatenate_1[1] = Gain3_In1_1;

  /* Gain: '<Root>/Gain' */
  Gain3_Gain_1[0] = Gain3_VectorConcatenate_1[0] * Gain3_P.Gain_Gain[0];
  Gain3_Gain_1[2] = Gain3_VectorConcatenate_1[0] * Gain3_P.Gain_Gain[1];
  Gain3_Gain_1[1] = Gain3_VectorConcatenate_1[1] * Gain3_P.Gain_Gain[0];
  Gain3_Gain_1[3] = Gain3_VectorConcatenate_1[1] * Gain3_P.Gain_Gain[1];
}

/* Model initialize function */
void Gain3_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Gain3_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Gain3_VectorConcatenate_1[0] = 0.0;
  Gain3_VectorConcatenate_1[1] = 0.0;
  Gain3_Gain_1[0] = 0.0;
  Gain3_Gain_1[1] = 0.0;
  Gain3_Gain_1[2] = 0.0;
  Gain3_Gain_1[3] = 0.0;

  /* external inputs */
  Gain3_In1_1 = 0.0;
}

/* Model terminate function */
void Gain3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
