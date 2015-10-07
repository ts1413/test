/*
 * File: Dead_Zone.c
 *
 * Code generated for Simulink model 'Dead_Zone'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:10 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Dead_Zone.h"
#include "Dead_Zone_private.h"

/* Exported block signals */
real_T Dead_Zone_In1_1;                /* '<Root>/In1' */
real_T Dead_Zone_DeadZone_1;           /* '<Root>/DeadZone' */

/* Real-time model */
RT_MODEL_Dead_Zone Dead_Zone_M_;
RT_MODEL_Dead_Zone *const Dead_Zone_M = &Dead_Zone_M_;

/* Model step function */
void Dead_Zone_step(void)
{
  /* DeadZone: '<Root>/DeadZone' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (Dead_Zone_In1_1 > 0.5) {
    Dead_Zone_DeadZone_1 = Dead_Zone_In1_1 - 0.5;
  } else if (Dead_Zone_In1_1 >= (-0.5)) {
    Dead_Zone_DeadZone_1 = 0.0;
  } else {
    Dead_Zone_DeadZone_1 = Dead_Zone_In1_1 - (-0.5);
  }

  /* End of DeadZone: '<Root>/DeadZone' */
}

/* Model initialize function */
void Dead_Zone_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Dead_Zone_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Dead_Zone_DeadZone_1 = 0.0;

  /* external inputs */
  Dead_Zone_In1_1 = 0.0;
}

/* Model terminate function */
void Dead_Zone_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
