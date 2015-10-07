/*
 * File: VectorConcatenate.c
 *
 * Code generated for Simulink model 'VectorConcatenate'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:38 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VectorConcatenate.h"
#include "VectorConcatenate_private.h"

/* Exported block signals */
real_T VectorConcatenate_In1_1;        /* '<Root>/In1' */
real_T VectorConcatenate_VectorConcatenate_1[2];/* '<Root>/VectorConcatenate' */

/* Real-time model */
RT_MODEL_VectorConcatenate_T VectorConcatenate_M_;
RT_MODEL_VectorConcatenate_T *const VectorConcatenate_M = &VectorConcatenate_M_;

/* Model step function */
void VectorConcatenate_step(void)
{
  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  VectorConcatenate_VectorConcatenate_1[0] = VectorConcatenate_In1_1;

  /* SignalConversion: '<Root>/ConcatBufferAtVectorConcatenateIn2' incorporates:
   *  Inport: '<Root>/In1'
   */
  VectorConcatenate_VectorConcatenate_1[1] = VectorConcatenate_In1_1;
}

/* Model initialize function */
void VectorConcatenate_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(VectorConcatenate_M, (NULL));

  /* block I/O */

  /* exported global signals */
  VectorConcatenate_VectorConcatenate_1[0] = 0.0;
  VectorConcatenate_VectorConcatenate_1[1] = 0.0;

  /* external inputs */
  VectorConcatenate_In1_1 = 0.0;
}

/* Model terminate function */
void VectorConcatenate_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
