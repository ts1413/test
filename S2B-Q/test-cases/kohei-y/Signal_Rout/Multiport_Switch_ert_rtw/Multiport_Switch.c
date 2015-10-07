/*
 * File: Multiport_Switch.c
 *
 * Code generated for Simulink model 'Multiport_Switch'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:36:02 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Multiport_Switch.h"
#include "Multiport_Switch_private.h"

/* Exported block signals */
real_T Multiport_Switch_In1_1;         /* '<Root>/In1' */
real_T Multiport_Switch_In2_1;         /* '<Root>/In2' */
real_T Multiport_Switch_In3_1;         /* '<Root>/In3' */
real_T Multiport_Switch_In4_1;         /* '<Root>/In4' */
real_T Multiport_Switch_MultiportSwitch_1;/* '<Root>/MultiportSwitch' */

/* Real-time model */
RT_MODEL_Multiport_Switch_T Multiport_Switch_M_;
RT_MODEL_Multiport_Switch_T *const Multiport_Switch_M = &Multiport_Switch_M_;

/* Model step function */
void Multiport_Switch_step(void)
{
  /* MultiPortSwitch: '<Root>/MultiportSwitch' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In3'
   *  Inport: '<Root>/In4'
   */
  switch ((int32_T)Multiport_Switch_In1_1) {
   case 1:
    Multiport_Switch_MultiportSwitch_1 = Multiport_Switch_In2_1;
    break;

   case 2:
    Multiport_Switch_MultiportSwitch_1 = Multiport_Switch_In3_1;
    break;

   default:
    Multiport_Switch_MultiportSwitch_1 = Multiport_Switch_In4_1;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/MultiportSwitch' */
}

/* Model initialize function */
void Multiport_Switch_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Multiport_Switch_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Multiport_Switch_MultiportSwitch_1 = 0.0;

  /* external inputs */
  Multiport_Switch_In1_1 = 0.0;
  Multiport_Switch_In2_1 = 0.0;
  Multiport_Switch_In3_1 = 0.0;
  Multiport_Switch_In4_1 = 0.0;
}

/* Model terminate function */
void Multiport_Switch_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
