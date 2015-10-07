/*
 * File: Shift_Arithmetic_Dlg.c
 *
 * Code generated for Simulink model 'Shift_Arithmetic_Dlg'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:40:43 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Shift_Arithmetic_Dlg.h"
#include "Shift_Arithmetic_Dlg_private.h"

/* Exported block signals */
real_T Shift_Arithmetic_Dlg_In1_1;     /* '<Root>/In1' */
real_T Shift_Arithmetic_Dlg_ShiftArithmetic_1;/* '<Root>/ShiftArithmetic' */

/* Real-time model */
RT_MODEL_Shift_Arithmetic_Dlg_T Shift_Arithmetic_Dlg_M_;
RT_MODEL_Shift_Arithmetic_Dlg_T *const Shift_Arithmetic_Dlg_M =
  &Shift_Arithmetic_Dlg_M_;

/* Model step function */
void Shift_Arithmetic_Dlg_step(void)
{
  /* ArithShift: '<Root>/ShiftArithmetic' incorporates:
   *  Inport: '<Root>/In1'
   */
  Shift_Arithmetic_Dlg_ShiftArithmetic_1 = ldexp(Shift_Arithmetic_Dlg_In1_1,
    (int32_T)(-8));
}

/* Model initialize function */
void Shift_Arithmetic_Dlg_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Shift_Arithmetic_Dlg_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Shift_Arithmetic_Dlg_ShiftArithmetic_1 = 0.0;

  /* external inputs */
  Shift_Arithmetic_Dlg_In1_1 = 0.0;
}

/* Model terminate function */
void Shift_Arithmetic_Dlg_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
