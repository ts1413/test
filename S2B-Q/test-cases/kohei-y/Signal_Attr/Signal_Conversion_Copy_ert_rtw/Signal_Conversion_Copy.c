/*
 * File: Signal_Conversion_Copy.c
 *
 * Code generated for Simulink model 'Signal_Conversion_Copy'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:06:17 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Signal_Conversion_Copy.h"
#include "Signal_Conversion_Copy_private.h"

/* Exported block signals */
real_T Signal_Conversion_Copy_In1_1;   /* '<Root>/In1' */
real_T Signal_Conversion_Copy_SignalConversion_1;/* '<Root>/SignalConversion' */

/* Real-time model */
RT_MODEL_Signal_Conversion_Co_T Signal_Conversion_Copy_M_;
RT_MODEL_Signal_Conversion_Co_T *const Signal_Conversion_Copy_M =
  &Signal_Conversion_Copy_M_;

/* Model step function */
void Signal_Conversion_Copy_step(void)
{
  /* SignalConversion: '<Root>/SignalConversion' incorporates:
   *  Inport: '<Root>/In1'
   */
  Signal_Conversion_Copy_SignalConversion_1 = Signal_Conversion_Copy_In1_1;
}

/* Model initialize function */
void Signal_Conversion_Copy_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Signal_Conversion_Copy_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Signal_Conversion_Copy_SignalConversion_1 = 0.0;

  /* external inputs */
  Signal_Conversion_Copy_In1_1 = 0.0;
}

/* Model terminate function */
void Signal_Conversion_Copy_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
