/*
 * File: LookupTableDynamic3.c
 *
 * Code generated for Simulink model 'LookupTableDynamic3'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:57:17 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LookupTableDynamic3.h"
#include "LookupTableDynamic3_private.h"

/* Exported block signals */
real_T LookupTableDynamic3_In1_1;      /* '<Root>/In1' */
real_T LookupTableDynamic3_Constant_1[3];/* '<Root>/Constant' */
real_T LookupTableDynamic3_Constant1_1[3];/* '<Root>/Constant1' */
real_T LookupTableDynamic3_LookupTableDynamic_1;/* '<Root>/LookupTableDynamic' */

/* Real-time model */
RT_MODEL_LookupTableDynamic3_T LookupTableDynamic3_M_;
RT_MODEL_LookupTableDynamic3_T *const LookupTableDynamic3_M =
  &LookupTableDynamic3_M_;

/* Lookup Binary Search Utility BINARYSEARCH_real_T_Near_iL */
void BINARYSEARCH_real_T_Near_iL(uint32_T *piLeft, real_T u, const real_T *pData,
  uint32_T iHi)
{
  uint32_T iRght;

  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  iRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    iRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( iRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + iRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        iRght = i;
      } else {
        *piLeft = i;
      }
    }

    /* Adjust the left index, if necessary, so that it always gives */
    /* the index of the data point nearest the current input value. */
    {
      real_T diffLeft, diffRght;
      diffLeft = u - pData[*piLeft];
      diffRght = pData[iRght] - u;
      if (diffRght <= diffLeft ) {
        *piLeft = iRght;
      }
    }
  }
}

/* Model step function */
void LookupTableDynamic3_step(void)
{
  /* Constant: '<Root>/Constant' */
  LookupTableDynamic3_Constant_1[0] = LookupTableDynamic3_P.Constant_Value[0];
  LookupTableDynamic3_Constant_1[1] = LookupTableDynamic3_P.Constant_Value[1];
  LookupTableDynamic3_Constant_1[2] = LookupTableDynamic3_P.Constant_Value[2];

  /* Constant: '<Root>/Constant1' */
  LookupTableDynamic3_Constant1_1[0] = LookupTableDynamic3_P.Constant1_Value[0];
  LookupTableDynamic3_Constant1_1[1] = LookupTableDynamic3_P.Constant1_Value[1];
  LookupTableDynamic3_Constant1_1[2] = LookupTableDynamic3_P.Constant1_Value[2];

  /* Dynamic Look-Up Table Block: '<Root>/LookupTableDynamic'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Nearest
   *
   */
  {
    uint32_T iLeft;
    BINARYSEARCH_real_T_Near_iL( &(iLeft), LookupTableDynamic3_In1_1,
      &LookupTableDynamic3_Constant_1[0], 2U);
    LookupTableDynamic3_LookupTableDynamic_1 =
      LookupTableDynamic3_Constant1_1[iLeft];
  }
}

/* Model initialize function */
void LookupTableDynamic3_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(LookupTableDynamic3_M, (NULL));

  /* block I/O */

  /* exported global signals */
  LookupTableDynamic3_Constant_1[0] = 0.0;
  LookupTableDynamic3_Constant_1[1] = 0.0;
  LookupTableDynamic3_Constant_1[2] = 0.0;
  LookupTableDynamic3_Constant1_1[0] = 0.0;
  LookupTableDynamic3_Constant1_1[1] = 0.0;
  LookupTableDynamic3_Constant1_1[2] = 0.0;
  LookupTableDynamic3_LookupTableDynamic_1 = 0.0;

  /* external inputs */
  LookupTableDynamic3_In1_1 = 0.0;

  /* Start for Constant: '<Root>/Constant' */
  LookupTableDynamic3_Constant_1[0] = LookupTableDynamic3_P.Constant_Value[0];
  LookupTableDynamic3_Constant_1[1] = LookupTableDynamic3_P.Constant_Value[1];
  LookupTableDynamic3_Constant_1[2] = LookupTableDynamic3_P.Constant_Value[2];

  /* Start for Constant: '<Root>/Constant1' */
  LookupTableDynamic3_Constant1_1[0] = LookupTableDynamic3_P.Constant1_Value[0];
  LookupTableDynamic3_Constant1_1[1] = LookupTableDynamic3_P.Constant1_Value[1];
  LookupTableDynamic3_Constant1_1[2] = LookupTableDynamic3_P.Constant1_Value[2];
}

/* Model terminate function */
void LookupTableDynamic3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
