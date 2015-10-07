/*
 * File: dsm.c
 *
 * Code generated for Simulink model 'dsm'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 02:23:28 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dsm.h"
#include "dsm_private.h"

/* Exported block signals */
real_T dsm_In1_1;                      /* '<Root>/In1' */
real_T dsm_DataStoreRead_1;            /* '<Root>/DataStoreRead' */

/* Block states (auto storage) */
DW_dsm_T dsm_DW;

/* Real-time model */
RT_MODEL_dsm_T dsm_M_;
RT_MODEL_dsm_T *const dsm_M = &dsm_M_;

/* Model step function */
void dsm_step(void)
{
  /* DataStoreWrite: '<Root>/DataStoreWrite' incorporates:
   *  Inport: '<Root>/In1'
   */
  dsm_DW.Data = dsm_In1_1;

  /* DataStoreRead: '<Root>/DataStoreRead' */
  dsm_DataStoreRead_1 = dsm_DW.Data;
}

/* Model initialize function */
void dsm_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(dsm_M, (NULL));

  /* block I/O */

  /* exported global signals */
  dsm_DataStoreRead_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&dsm_DW, 0,
                sizeof(DW_dsm_T));

  /* external inputs */
  dsm_In1_1 = 0.0;

  /* Start for DataStoreMemory: '<Root>/DataStoreMemory' */
  dsm_DW.Data = dsm_P.DataStoreMemory_InitialValue;
}

/* Model terminate function */
void dsm_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
