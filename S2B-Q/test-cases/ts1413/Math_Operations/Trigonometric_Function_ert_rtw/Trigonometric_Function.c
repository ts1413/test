/*
 * File: Trigonometric_Function.c
 *
 * Code generated for Simulink model 'Trigonometric_Function'.
 *
 * Model version                  : 1.98
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:08:38 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Trigonometric_Function.h"
#include "Trigonometric_Function_private.h"

/* Exported block signals */
real_T Trigonometric_Function_In1_1;   /* '<Root>/In1' */
real_T Trigonometric_Function_TrigonometricFunction_1;/* '<Root>/TrigonometricFunction' */

/* Real-time model */
RT_MODEL_Trigonometric_Function Trigonometric_Function_M_;
RT_MODEL_Trigonometric_Function *const Trigonometric_Function_M =
  &Trigonometric_Function_M_;

/* Model step function */
void Trigonometric_Function_step(void)
{
  /* Trigonometry: '<Root>/TrigonometricFunction' incorporates:
   *  Inport: '<Root>/In1'
   */
  Trigonometric_Function_TrigonometricFunction_1 = sin
    (Trigonometric_Function_In1_1);
}

/* Model initialize function */
void Trigonometric_Function_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Trigonometric_Function_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Trigonometric_Function_TrigonometricFunction_1 = 0.0;

  /* external inputs */
  Trigonometric_Function_In1_1 = 0.0;
}

/* Model terminate function */
void Trigonometric_Function_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
