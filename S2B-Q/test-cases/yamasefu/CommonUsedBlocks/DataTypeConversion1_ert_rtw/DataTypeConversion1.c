/*
 * File: DataTypeConversion1.c
 *
 * Code generated for Simulink model 'DataTypeConversion1'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:54:28 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DataTypeConversion1.h"
#include "DataTypeConversion1_private.h"

/* Exported block signals */
real_T DataTypeConversion1_In1_1;      /* '<Root>/In1' */
real_T DataTypeConversion1_DataTypeConversion_1;/* '<Root>/DataTypeConversion' */

/* Real-time model */
RT_MODEL_DataTypeConversion1_T DataTypeConversion1_M_;
RT_MODEL_DataTypeConversion1_T *const DataTypeConversion1_M =
  &DataTypeConversion1_M_;

/* Model step function */
void DataTypeConversion1_step(void)
{
  /* DataTypeConversion: '<Root>/DataTypeConversion' incorporates:
   *  Inport: '<Root>/In1'
   */
  DataTypeConversion1_DataTypeConversion_1 = DataTypeConversion1_In1_1;
}

/* Model initialize function */
void DataTypeConversion1_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(DataTypeConversion1_M, (NULL));

  /* block I/O */

  /* exported global signals */
  DataTypeConversion1_DataTypeConversion_1 = 0.0;

  /* external inputs */
  DataTypeConversion1_In1_1 = 0.0;
}

/* Model terminate function */
void DataTypeConversion1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
