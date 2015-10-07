/*
 * File: Add.c
 *
 * Code generated for Simulink model 'Add'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:42 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Add.h"
#include "Add_private.h"

/* Exported block signals */
real_T Add_In1_1;                      /* '<Root>/In1' */
real_T Add_In2_1;                      /* '<Root>/In2' */
real_T Add_Add_1;                      /* '<Root>/Add' */

/* Real-time model */
RT_MODEL_Add Add_M_;
RT_MODEL_Add *const Add_M = &Add_M_;

/* Model step function */
void Add_step(void)
{
  /* Sum: '<Root>/Add' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  Add_Add_1 = Add_In1_1 + Add_In2_1;
}

/* Model initialize function */
void Add_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Add_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Add_Add_1 = 0.0;

  /* external inputs */
  Add_In1_1 = 0.0;
  Add_In2_1 = 0.0;
}

/* Model terminate function */
void Add_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
