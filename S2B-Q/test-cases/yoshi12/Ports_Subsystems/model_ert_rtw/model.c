/*
 * File: model.c
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:42:07 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model.h"
#include "model_private.h"

/* Exported block signals */
real_T model_In1_1;                    /* '<Root>/In1' */
real_T model_Model_1;                  /* '<Root>/Model' */

/* Block states (auto storage) */
DW_model_T model_DW;

/* Real-time model */
RT_MODEL_model_T model_M_;
RT_MODEL_model_T *const model_M = &model_M_;

/* Model step function */
void model_step(void)
{
  /* ModelReference: '<Root>/Model' */
  inport_outport(&model_In1_1, &model_Model_1);
}

/* Model initialize function */
void model_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(model_M, (NULL));

  /* block I/O */

  /* exported global signals */
  model_Model_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&model_DW, 0,
                sizeof(DW_model_T));

  /* external inputs */
  model_In1_1 = 0.0;

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model' */
  inport_outport_initialize(rtmGetErrorStatusPointer(model_M),
    &(model_DW.Model_DWORK1.rtm));
}

/* Model terminate function */
void model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
