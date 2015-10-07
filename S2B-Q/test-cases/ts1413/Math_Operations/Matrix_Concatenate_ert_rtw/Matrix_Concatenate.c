/*
 * File: Matrix_Concatenate.c
 *
 * Code generated for Simulink model 'Matrix_Concatenate'.
 *
 * Model version                  : 1.79
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:40:11 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Matrix_Concatenate.h"
#include "Matrix_Concatenate_private.h"

/* Exported block signals */
real_T Matrix_Concatenate_In1_1[2];    /* '<Root>/In1' */
real_T Matrix_Concatenate_In2_1[2];    /* '<Root>/In2' */
real_T Matrix_Concatenate_MatrixConcatenate_1[4];/* '<Root>/MatrixConcatenate' */

/* Real-time model */
RT_MODEL_Matrix_Concatenate Matrix_Concatenate_M_;
RT_MODEL_Matrix_Concatenate *const Matrix_Concatenate_M = &Matrix_Concatenate_M_;

/* Model step function */
void Matrix_Concatenate_step(void)
{
  /* SignalConversion: '<Root>/ConcatBufferAtMatrixConcatenateIn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  Matrix_Concatenate_MatrixConcatenate_1[0] = Matrix_Concatenate_In1_1[0];
  Matrix_Concatenate_MatrixConcatenate_1[1] = Matrix_Concatenate_In1_1[1];

  /* SignalConversion: '<Root>/ConcatBufferAtMatrixConcatenateIn2' incorporates:
   *  Inport: '<Root>/In2'
   */
  Matrix_Concatenate_MatrixConcatenate_1[2] = Matrix_Concatenate_In2_1[0];
  Matrix_Concatenate_MatrixConcatenate_1[3] = Matrix_Concatenate_In2_1[1];
}

/* Model initialize function */
void Matrix_Concatenate_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Matrix_Concatenate_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Matrix_Concatenate_MatrixConcatenate_1[0] = 0.0;
  Matrix_Concatenate_MatrixConcatenate_1[1] = 0.0;
  Matrix_Concatenate_MatrixConcatenate_1[2] = 0.0;
  Matrix_Concatenate_MatrixConcatenate_1[3] = 0.0;

  /* external inputs */
  Matrix_Concatenate_In1_1[0] = 0.0;
  Matrix_Concatenate_In1_1[1] = 0.0;
  Matrix_Concatenate_In2_1[0] = 0.0;
  Matrix_Concatenate_In2_1[1] = 0.0;
}

/* Model terminate function */
void Matrix_Concatenate_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
