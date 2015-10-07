/*
 * File: Signal_Conversion_Bus.c
 *
 * Code generated for Simulink model 'Signal_Conversion_Bus'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 01:50:56 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Signal_Conversion_Bus.h"
#include "Signal_Conversion_Bus_private.h"

/* Exported block signals */
real_T Signal_Conversion_Bus_In1_1;    /* '<Root>/In1' */

/* Block signals (auto storage) */
B_Signal_Conversion_Bus_T Signal_Conversion_Bus_B;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Signal_Conversion_Bus_T Signal_Conversion_Bus_Y;

/* Real-time model */
RT_MODEL_Signal_Conversion_Bu_T Signal_Conversion_Bus_M_;
RT_MODEL_Signal_Conversion_Bu_T *const Signal_Conversion_Bus_M =
  &Signal_Conversion_Bus_M_;

/* Model step function */
void Signal_Conversion_Bus_step(void)
{
  /* BusCreator: '<Root>/SignalConversion' incorporates:
   *  Inport: '<Root>/In1'
   */
  Signal_Conversion_Bus_B.SignalConversion_BusCreator_1.a =
    Signal_Conversion_Bus_In1_1;

  /* Outport: '<Root>/Out1' */
  Signal_Conversion_Bus_Y.Out1 =
    Signal_Conversion_Bus_B.SignalConversion_BusCreator_1.a;
}

/* Model initialize function */
void Signal_Conversion_Bus_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Signal_Conversion_Bus_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Signal_Conversion_Bus_B), 0,
                sizeof(B_Signal_Conversion_Bus_T));

  /* external inputs */
  Signal_Conversion_Bus_In1_1 = 0.0;

  /* external outputs */
  Signal_Conversion_Bus_Y.Out1 = 0.0;
}

/* Model terminate function */
void Signal_Conversion_Bus_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
