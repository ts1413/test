/*
 * File: Signal_Conversion_VBus.c
 *
 * Code generated for Simulink model 'Signal_Conversion_VBus'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 01:47:34 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Signal_Conversion_VBus.h"
#include "Signal_Conversion_VBus_private.h"

/* Exported block signals */
real_T Signal_Conversion_VBus_In1_1;   /* '<Root>/In1' */

/* Block signals (auto storage) */
B_Signal_Conversion_VBus_T Signal_Conversion_VBus_B;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Signal_Conversion_VBus_T Signal_Conversion_VBus_Y;

/* Real-time model */
RT_MODEL_Signal_Conversion_VB_T Signal_Conversion_VBus_M_;
RT_MODEL_Signal_Conversion_VB_T *const Signal_Conversion_VBus_M =
  &Signal_Conversion_VBus_M_;

/* Model step function */
void Signal_Conversion_VBus_step(void)
{
  /* BusCreator: '<Root>/BusCreator' incorporates:
   *  Inport: '<Root>/In1'
   */
  Signal_Conversion_VBus_B.Signal_Conversion_VBus_BusCreat.a =
    Signal_Conversion_VBus_In1_1;

  /* Outport: '<Root>/Out1' */
  Signal_Conversion_VBus_Y.Out1 =
    Signal_Conversion_VBus_B.Signal_Conversion_VBus_BusCreat.a;
}

/* Model initialize function */
void Signal_Conversion_VBus_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Signal_Conversion_VBus_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Signal_Conversion_VBus_B), 0,
                sizeof(B_Signal_Conversion_VBus_T));

  /* external inputs */
  Signal_Conversion_VBus_In1_1 = 0.0;

  /* external outputs */
  Signal_Conversion_VBus_Y.Out1 = 0.0;
}

/* Model terminate function */
void Signal_Conversion_VBus_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
