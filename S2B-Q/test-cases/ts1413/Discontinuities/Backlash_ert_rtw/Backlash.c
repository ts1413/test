/*
 * File: Backlash.c
 *
 * Code generated for Simulink model 'Backlash'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:05 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Backlash.h"
#include "Backlash_private.h"

/* Exported block signals */
real_T Backlash_In1_1;                 /* '<Root>/In1' */
real_T Backlash_Backlash_1;            /* '<Root>/Backlash' */

/* Block states (auto storage) */
D_Work_Backlash Backlash_DWork;

/* Real-time model */
RT_MODEL_Backlash Backlash_M_;
RT_MODEL_Backlash *const Backlash_M = &Backlash_M_;

/* Model step function */
void Backlash_step(void)
{
  real_T halfDeadBand;

  /* Backlash: '<Root>/Backlash' incorporates:
   *  Inport: '<Root>/In1'
   */
  halfDeadBand = 1.0 / 2.0;
  if (Backlash_In1_1 < Backlash_DWork.PrevY - halfDeadBand) {
    Backlash_Backlash_1 = Backlash_In1_1 + halfDeadBand;
  } else if (Backlash_In1_1 <= Backlash_DWork.PrevY + halfDeadBand) {
    Backlash_Backlash_1 = Backlash_DWork.PrevY;
  } else {
    Backlash_Backlash_1 = Backlash_In1_1 - halfDeadBand;
  }

  /* End of Backlash: '<Root>/Backlash' */

  /* Update for Backlash: '<Root>/Backlash' */
  Backlash_DWork.PrevY = Backlash_Backlash_1;
}

/* Model initialize function */
void Backlash_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Backlash_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Backlash_Backlash_1 = 0.0;

  /* states (dwork) */
  Backlash_DWork.PrevY = 0.0;

  /* external inputs */
  Backlash_In1_1 = 0.0;

  /* InitializeConditions for Backlash: '<Root>/Backlash' */
  Backlash_DWork.PrevY = 0.0;
}

/* Model terminate function */
void Backlash_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
