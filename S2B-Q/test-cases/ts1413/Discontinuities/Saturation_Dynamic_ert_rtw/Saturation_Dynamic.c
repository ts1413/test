/*
 * File: Saturation_Dynamic.c
 *
 * Code generated for Simulink model 'Saturation_Dynamic'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:34 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Saturation_Dynamic.h"
#include "Saturation_Dynamic_private.h"

/* Exported block signals */
real_T Saturation_Dynamic_In1_1;       /* '<Root>/In1' */
real_T Saturation_Dynamic_In2_1;       /* '<Root>/In2' */
real_T Saturation_Dynamic_In3_1;       /* '<Root>/In3' */

/* Block signals (auto storage) */
BlockIO_Saturation_Dynamic Saturation_Dynamic_B;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Saturation_Dyna Saturation_Dynamic_Y;

/* Real-time model */
RT_MODEL_Saturation_Dynamic Saturation_Dynamic_M_;
RT_MODEL_Saturation_Dynamic *const Saturation_Dynamic_M = &Saturation_Dynamic_M_;

/* Model step function */
void Saturation_Dynamic_step(void)
{
  /* RelationalOperator: '<S1>/LowerRelop1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  Saturation_Dynamic_B.LowerRelop1 = (Saturation_Dynamic_In1_1 >
    Saturation_Dynamic_In2_1);

  /* RelationalOperator: '<S1>/UpperRelop' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In3'
   */
  Saturation_Dynamic_B.UpperRelop = (Saturation_Dynamic_In1_1 <
    Saturation_Dynamic_In3_1);

  /* Switch: '<S1>/Switch' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In3'
   */
  if (Saturation_Dynamic_B.UpperRelop) {
    Saturation_Dynamic_B.Switch = Saturation_Dynamic_In3_1;
  } else {
    Saturation_Dynamic_B.Switch = Saturation_Dynamic_In1_1;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Switch: '<S1>/Switch2' */
  if (Saturation_Dynamic_B.LowerRelop1) {
    /* Outport: '<Root>/Out1' incorporates:
     *  Inport: '<Root>/In2'
     */
    Saturation_Dynamic_Y.Out1 = Saturation_Dynamic_In2_1;
  } else {
    /* Outport: '<Root>/Out1' */
    Saturation_Dynamic_Y.Out1 = Saturation_Dynamic_B.Switch;
  }

  /* End of Switch: '<S1>/Switch2' */
}

/* Model initialize function */
void Saturation_Dynamic_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Saturation_Dynamic_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Saturation_Dynamic_B), 0,
                sizeof(BlockIO_Saturation_Dynamic));

  {
    Saturation_Dynamic_B.Switch = 0.0;
  }

  /* external inputs */
  Saturation_Dynamic_In1_1 = 0.0;
  Saturation_Dynamic_In2_1 = 0.0;
  Saturation_Dynamic_In3_1 = 0.0;

  /* external outputs */
  Saturation_Dynamic_Y.Out1 = 0.0;
}

/* Model terminate function */
void Saturation_Dynamic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
