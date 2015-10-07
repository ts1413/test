/*
 * File: Display.c
 *
 * Code generated for Simulink model 'Display'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:42:32 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Display.h"
#include "Display_private.h"

/* Exported block signals */
real_T Display_In1_1;                  /* '<Root>/In1' */

/* Real-time model */
RT_MODEL_Display_T Display_M_;
RT_MODEL_Display_T *const Display_M = &Display_M_;

/* Model step function */
void Display_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Display_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Display_M, (NULL));

  /* external inputs */
  Display_In1_1 = 0.0;
}

/* Model terminate function */
void Display_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
