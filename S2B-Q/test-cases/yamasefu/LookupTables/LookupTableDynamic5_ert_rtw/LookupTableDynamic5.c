/*
 * File: LookupTableDynamic5.c
 *
 * Code generated for Simulink model 'LookupTableDynamic5'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:57:29 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LookupTableDynamic5.h"
#include "LookupTableDynamic5_private.h"

/* Exported block signals */
real_T LookupTableDynamic5_In1_1;      /* '<Root>/In1' */
real_T LookupTableDynamic5_Constant_1[3];/* '<Root>/Constant' */
real_T LookupTableDynamic5_Constant1_1[3];/* '<Root>/Constant1' */
real_T LookupTableDynamic5_LookupTableDynamic_1;/* '<Root>/LookupTableDynamic' */

/* Real-time model */
RT_MODEL_LookupTableDynamic5_T LookupTableDynamic5_M_;
RT_MODEL_LookupTableDynamic5_T *const LookupTableDynamic5_M =
  &LookupTableDynamic5_M_;

/* Lookup Binary Search Utility BINARYSEARCH_real_T_Above_iR */
void BINARYSEARCH_real_T_Above_iR(uint32_T *piRght, real_T u, const real_T
  *pData, uint32_T iHi)
{
  uint32_T iLeft;

  /* Find the location of current input value in the data table. */
  iLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    iLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - iLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (iLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint < CurrentValue <= RightDataPoint */
      if (u <= pData[i] ) {
        *piRght = i;
      } else {
        iLeft = i;
      }
    }
  }
}

/* Model step function */
void LookupTableDynamic5_step(void)
{
  /* Constant: '<Root>/Constant' */
  LookupTableDynamic5_Constant_1[0] = LookupTableDynamic5_P.Constant_Value[0];
  LookupTableDynamic5_Constant_1[1] = LookupTableDynamic5_P.Constant_Value[1];
  LookupTableDynamic5_Constant_1[2] = LookupTableDynamic5_P.Constant_Value[2];

  /* Constant: '<Root>/Constant1' */
  LookupTableDynamic5_Constant1_1[0] = LookupTableDynamic5_P.Constant1_Value[0];
  LookupTableDynamic5_Constant1_1[1] = LookupTableDynamic5_P.Constant1_Value[1];
  LookupTableDynamic5_Constant1_1[2] = LookupTableDynamic5_P.Constant1_Value[2];

  /* Dynamic Look-Up Table Block: '<Root>/LookupTableDynamic'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Above
   *
   */
  {
    uint32_T iRght;
    BINARYSEARCH_real_T_Above_iR( &(iRght), LookupTableDynamic5_In1_1,
      &LookupTableDynamic5_Constant_1[0], 2U);
    LookupTableDynamic5_LookupTableDynamic_1 =
      LookupTableDynamic5_Constant1_1[iRght];
  }
}

/* Model initialize function */
void LookupTableDynamic5_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(LookupTableDynamic5_M, (NULL));

  /* block I/O */

  /* exported global signals */
  LookupTableDynamic5_Constant_1[0] = 0.0;
  LookupTableDynamic5_Constant_1[1] = 0.0;
  LookupTableDynamic5_Constant_1[2] = 0.0;
  LookupTableDynamic5_Constant1_1[0] = 0.0;
  LookupTableDynamic5_Constant1_1[1] = 0.0;
  LookupTableDynamic5_Constant1_1[2] = 0.0;
  LookupTableDynamic5_LookupTableDynamic_1 = 0.0;

  /* external inputs */
  LookupTableDynamic5_In1_1 = 0.0;

  /* Start for Constant: '<Root>/Constant' */
  LookupTableDynamic5_Constant_1[0] = LookupTableDynamic5_P.Constant_Value[0];
  LookupTableDynamic5_Constant_1[1] = LookupTableDynamic5_P.Constant_Value[1];
  LookupTableDynamic5_Constant_1[2] = LookupTableDynamic5_P.Constant_Value[2];

  /* Start for Constant: '<Root>/Constant1' */
  LookupTableDynamic5_Constant1_1[0] = LookupTableDynamic5_P.Constant1_Value[0];
  LookupTableDynamic5_Constant1_1[1] = LookupTableDynamic5_P.Constant1_Value[1];
  LookupTableDynamic5_Constant1_1[2] = LookupTableDynamic5_P.Constant1_Value[2];
}

/* Model terminate function */
void LookupTableDynamic5_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
