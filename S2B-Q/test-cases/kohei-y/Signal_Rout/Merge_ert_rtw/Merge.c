/*
 * File: Merge.c
 *
 * Code generated for Simulink model 'Merge'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:06:52 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Merge.h"
#include "Merge_private.h"

/* Exported block signals */
real_T Merge_In1_1;                    /* '<Root>/In1' */
real_T Merge_Constant1_1;              /* '<Root>/Constant1' */
real_T Merge_Constant_1;               /* '<Root>/Constant' */
real_T Merge_Merge_1;                  /* '<Root>/Merge' */

/* Real-time model */
RT_MODEL_Merge_T Merge_M_;
RT_MODEL_Merge_T *const Merge_M = &Merge_M_;

/*
 * Output and update for action system:
 *    '<Root>/IfActionSubsystem'
 *    '<Root>/IfActionSubsystem1'
 */
void Merge_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S1>/In1' */
  *rty_Out1 = rtu_In1;
}

/* Model step function */
void Merge_step(void)
{
  /* Constant: '<Root>/Constant1' */
  Merge_Constant1_1 = Merge_P.Constant1_Value;

  /* Constant: '<Root>/Constant' */
  Merge_Constant_1 = Merge_P.Constant_Value;

  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (Merge_In1_1 > 0.0) {
    /* Outputs for IfAction SubSystem: '<Root>/IfActionSubsystem' incorporates:
     *  ActionPort: '<S1>/ActionPort'
     */
    Merge_IfActionSubsystem(Merge_Constant_1, &Merge_Merge_1);

    /* End of Outputs for SubSystem: '<Root>/IfActionSubsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/IfActionSubsystem1' incorporates:
     *  ActionPort: '<S2>/ActionPort'
     */
    Merge_IfActionSubsystem(Merge_Constant1_1, &Merge_Merge_1);

    /* End of Outputs for SubSystem: '<Root>/IfActionSubsystem1' */
  }

  /* End of If: '<Root>/If' */
}

/* Model initialize function */
void Merge_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Merge_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Merge_Constant1_1 = 0.0;
  Merge_Constant_1 = 0.0;
  Merge_Merge_1 = 0.0;

  /* external inputs */
  Merge_In1_1 = 0.0;

  /* Start for Merge: '<Root>/Merge' */
  Merge_Merge_1 = Merge_P.Merge_InitialOutput;
}

/* Model terminate function */
void Merge_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
