/*
 * File: Switch.c
 *
 * Code generated for Simulink model 'Switch'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:26 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Switch.h"
#include "Switch_private.h"

/* Exported block signals */
real_T Switch_In1_1;                   /* '<Root>/In1' */
real_T Switch_In2_1;                   /* '<Root>/In2' */
real_T Switch_In3_1;                   /* '<Root>/In3' */
real_T Switch_Switch_1;                /* '<Root>/Switch' */

/* Real-time model */
RT_MODEL_Switch_T Switch_M_;
RT_MODEL_Switch_T *const Switch_M = &Switch_M_;

/* Model step function */
void Switch_step(void)
{
  /* Switch: '<Root>/Switch' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In3'
   */
  if (Switch_In2_1 >= Switch_P.Switch_Threshold) {
    Switch_Switch_1 = Switch_In1_1;
  } else {
    Switch_Switch_1 = Switch_In3_1;
  }

  /* End of Switch: '<Root>/Switch' */
}

/* Model initialize function */
void Switch_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Switch_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Switch_Switch_1 = 0.0;

  /* external inputs */
  Switch_In1_1 = 0.0;
  Switch_In2_1 = 0.0;
  Switch_In3_1 = 0.0;
}

/* Model terminate function */
void Switch_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
