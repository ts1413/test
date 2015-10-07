/*
 * File: Detect_Change_FrameBase.c
 *
 * Code generated for Simulink model 'Detect_Change_FrameBase'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sat Oct  3 23:49:54 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Detect_Change_FrameBase.h"
#include "Detect_Change_FrameBase_private.h"

/* Exported block signals */
real_T Detect_Change_FrameBase_In1_1;  /* '<Root>/In1' */

/* Block signals (auto storage) */
B_Detect_Change_FrameBase_T Detect_Change_FrameBase_B;

/* Block states (auto storage) */
DW_Detect_Change_FrameBase_T Detect_Change_FrameBase_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Detect_Change_FrameBase_T Detect_Change_FrameBase_Y;

/* Real-time model */
RT_MODEL_Detect_Change_FrameB_T Detect_Change_FrameBase_M_;
RT_MODEL_Detect_Change_FrameB_T *const Detect_Change_FrameBase_M =
  &Detect_Change_FrameBase_M_;

/* Model step function */
void Detect_Change_FrameBase_step(void)
{
  /* UnitDelay: '<S1>/Delay Input1' */
  Detect_Change_FrameBase_B.Uk1 = Detect_Change_FrameBase_DW.DelayInput1_DSTATE;

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  RelationalOperator: '<S1>/FixPt Relational Operator'
   */
  Detect_Change_FrameBase_Y.Out1 = (Detect_Change_FrameBase_In1_1 !=
    Detect_Change_FrameBase_B.Uk1);

  /* Update for UnitDelay: '<S1>/Delay Input1' incorporates:
   *  Inport: '<Root>/In1'
   */
  Detect_Change_FrameBase_DW.DelayInput1_DSTATE = Detect_Change_FrameBase_In1_1;
}

/* Model initialize function */
void Detect_Change_FrameBase_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Detect_Change_FrameBase_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Detect_Change_FrameBase_B), 0,
                sizeof(B_Detect_Change_FrameBase_T));

  /* states (dwork) */
  (void) memset((void *)&Detect_Change_FrameBase_DW, 0,
                sizeof(DW_Detect_Change_FrameBase_T));

  /* external inputs */
  Detect_Change_FrameBase_In1_1 = 0.0;

  /* external outputs */
  Detect_Change_FrameBase_Y.Out1 = false;

  /* InitializeConditions for UnitDelay: '<S1>/Delay Input1' */
  Detect_Change_FrameBase_DW.DelayInput1_DSTATE =
    Detect_Change_FrameBase_P.DetectChange_vinit;
}

/* Model terminate function */
void Detect_Change_FrameBase_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
