/*
 * File: MinMax.c
 *
 * Code generated for Simulink model 'MinMax'.
 *
 * Model version                  : 1.80
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:40:16 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MinMax.h"
#include "MinMax_private.h"

/* Exported block signals */
real_T MinMax_In1_1;                   /* '<Root>/In1' */
real_T MinMax_In2_1;                   /* '<Root>/In2' */
real_T MinMax_MinMax_1;                /* '<Root>/MinMax' */

/* Real-time model */
RT_MODEL_MinMax MinMax_M_;
RT_MODEL_MinMax *const MinMax_M = &MinMax_M_;

/* Model step function */
void MinMax_step(void)
{
  real_T u0;
  real_T u1;

  /* MinMax: '<Root>/MinMax' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  u0 = MinMax_In1_1;
  u1 = MinMax_In2_1;
  if ((u0 <= u1) || rtIsNaN(u1)) {
    u1 = u0;
  }

  MinMax_MinMax_1 = u1;

  /* End of MinMax: '<Root>/MinMax' */
}

/* Model initialize function */
void MinMax_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(MinMax_M, (NULL));

  /* block I/O */

  /* exported global signals */
  MinMax_MinMax_1 = 0.0;

  /* external inputs */
  MinMax_In1_1 = 0.0;
  MinMax_In2_1 = 0.0;
}

/* Model terminate function */
void MinMax_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
