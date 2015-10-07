/*
 * File: Discrete_Transfer_Fcn.c
 *
 * Code generated for Simulink model 'Discrete_Transfer_Fcn'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:59 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Discrete_Transfer_Fcn.h"
#include "Discrete_Transfer_Fcn_private.h"

/* Exported block signals */
real_T Discrete_Transfer_Fcn_In1_1;    /* '<Root>/In1' */
real_T Discrete_Transfer_Fcn_DiscreteTransferFcn_1;/* '<Root>/DiscreteTransferFcn' */

/* Block states (auto storage) */
D_Work_Discrete_Transfer_Fcn Discrete_Transfer_Fcn_DWork;

/* Real-time model */
RT_MODEL_Discrete_Transfer_Fcn Discrete_Transfer_Fcn_M_;
RT_MODEL_Discrete_Transfer_Fcn *const Discrete_Transfer_Fcn_M =
  &Discrete_Transfer_Fcn_M_;

/* Model step function */
void Discrete_Transfer_Fcn_step(void)
{
  real_T denAccum;

  /* DiscreteTransferFcn: '<Root>/DiscreteTransferFcn' */
  denAccum = 1.0 * Discrete_Transfer_Fcn_DWork.DiscreteTransferFcn_states;
  Discrete_Transfer_Fcn_DiscreteTransferFcn_1 = denAccum;

  /* Update for DiscreteTransferFcn: '<Root>/DiscreteTransferFcn' incorporates:
   *  Update for Inport: '<Root>/In1'
   */
  denAccum = Discrete_Transfer_Fcn_In1_1;
  denAccum -= 0.5 * Discrete_Transfer_Fcn_DWork.DiscreteTransferFcn_states;
  denAccum /= 1.0;
  Discrete_Transfer_Fcn_DWork.DiscreteTransferFcn_states = denAccum;
}

/* Model initialize function */
void Discrete_Transfer_Fcn_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Discrete_Transfer_Fcn_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Discrete_Transfer_Fcn_DiscreteTransferFcn_1 = 0.0;

  /* states (dwork) */
  Discrete_Transfer_Fcn_DWork.DiscreteTransferFcn_states = 0.0;

  /* external inputs */
  Discrete_Transfer_Fcn_In1_1 = 0.0;
}

/* Model terminate function */
void Discrete_Transfer_Fcn_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
