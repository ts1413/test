/*
 * File: DataTypeConversion2.c
 *
 * Code generated for Simulink model 'DataTypeConversion2'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:54:34 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DataTypeConversion2.h"
#include "DataTypeConversion2_private.h"

/* Exported block signals */
real_T DataTypeConversion2_In1_1;      /* '<Root>/In1' */
real_T DataTypeConversion2_DataTypeConversion_1;/* '<Root>/DataTypeConversion' */

/* Real-time model */
RT_MODEL_DataTypeConversion2_T DataTypeConversion2_M_;
RT_MODEL_DataTypeConversion2_T *const DataTypeConversion2_M =
  &DataTypeConversion2_M_;

/* Model step function */
void DataTypeConversion2_step(void)
{
  /* DataTypeConversion: '<Root>/DataTypeConversion' incorporates:
   *  Inport: '<Root>/In1'
   */
  DataTypeConversion2_DataTypeConversion_1 = DataTypeConversion2_In1_1;
}

/* Model initialize function */
void DataTypeConversion2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(DataTypeConversion2_M, (NULL));

  /* block I/O */

  /* exported global signals */
  DataTypeConversion2_DataTypeConversion_1 = 0.0;

  /* external inputs */
  DataTypeConversion2_In1_1 = 0.0;
}

/* Model terminate function */
void DataTypeConversion2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
