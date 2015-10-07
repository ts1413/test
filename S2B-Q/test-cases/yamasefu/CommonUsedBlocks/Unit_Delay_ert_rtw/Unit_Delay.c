/*
 * File: Unit_Delay.c
 *
 * Code generated for Simulink model 'Unit_Delay'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:09:49 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Unit_Delay.h"
#include "Unit_Delay_private.h"

/* Exported block signals */
real_T Unit_Delay_In1_1;               /* '<Root>/In1' */
real_T Unit_Delay_UnitDelay_1;         /* '<Root>/UnitDelay' */

/* Block states (auto storage) */
DW_Unit_Delay_T Unit_Delay_DW;

/* Real-time model */
RT_MODEL_Unit_Delay_T Unit_Delay_M_;
RT_MODEL_Unit_Delay_T *const Unit_Delay_M = &Unit_Delay_M_;

/* Model step function */
void Unit_Delay_step(void)
{
  /* UnitDelay: '<Root>/UnitDelay' */
  Unit_Delay_UnitDelay_1 = Unit_Delay_DW.UnitDelay_DSTATE;

  /* Update for UnitDelay: '<Root>/UnitDelay' incorporates:
   *  Update for Inport: '<Root>/In1'
   */
  Unit_Delay_DW.UnitDelay_DSTATE = Unit_Delay_In1_1;
}

/* Model initialize function */
void Unit_Delay_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Unit_Delay_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Unit_Delay_UnitDelay_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&Unit_Delay_DW, 0,
                sizeof(DW_Unit_Delay_T));

  /* external inputs */
  Unit_Delay_In1_1 = 0.0;

  /* InitializeConditions for UnitDelay: '<Root>/UnitDelay' */
  Unit_Delay_DW.UnitDelay_DSTATE = Unit_Delay_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void Unit_Delay_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
