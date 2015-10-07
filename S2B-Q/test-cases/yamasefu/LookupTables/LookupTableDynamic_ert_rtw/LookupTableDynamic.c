/*
 * File: LookupTableDynamic.c
 *
 * Code generated for Simulink model 'LookupTableDynamic'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:57:10 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LookupTableDynamic.h"
#include "LookupTableDynamic_private.h"

/* Exported block signals */
real_T LookupTableDynamic_In1_1;       /* '<Root>/In1' */
real_T LookupTableDynamic_Constant_1[3];/* '<Root>/Constant' */
real_T LookupTableDynamic_Constant1_1[3];/* '<Root>/Constant1' */
real_T LookupTableDynamic_LookupTableDynamic_1;/* '<Root>/LookupTableDynamic' */

/* Real-time model */
RT_MODEL_LookupTableDynamic_T LookupTableDynamic_M_;
RT_MODEL_LookupTableDynamic_T *const LookupTableDynamic_M =
  &LookupTableDynamic_M_;

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup Utility LookUp_real_T_real_T */
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den = den - pUData[iLeft];
      num = u;
      num = num - pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

/* Model step function */
void LookupTableDynamic_step(void)
{
  /* Constant: '<Root>/Constant' */
  LookupTableDynamic_Constant_1[0] = LookupTableDynamic_P.Constant_Value[0];
  LookupTableDynamic_Constant_1[1] = LookupTableDynamic_P.Constant_Value[1];
  LookupTableDynamic_Constant_1[2] = LookupTableDynamic_P.Constant_Value[2];

  /* Constant: '<Root>/Constant1' */
  LookupTableDynamic_Constant1_1[0] = LookupTableDynamic_P.Constant1_Value[0];
  LookupTableDynamic_Constant1_1[1] = LookupTableDynamic_P.Constant1_Value[1];
  LookupTableDynamic_Constant1_1[2] = LookupTableDynamic_P.Constant1_Value[2];

  /* Dynamic Look-Up Table Block: '<Root>/LookupTableDynamic'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(LookupTableDynamic_LookupTableDynamic_1),
                       &LookupTableDynamic_Constant1_1[0],
                       LookupTableDynamic_In1_1, &LookupTableDynamic_Constant_1
                       [0], 2U);
}

/* Model initialize function */
void LookupTableDynamic_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(LookupTableDynamic_M, (NULL));

  /* block I/O */

  /* exported global signals */
  LookupTableDynamic_Constant_1[0] = 0.0;
  LookupTableDynamic_Constant_1[1] = 0.0;
  LookupTableDynamic_Constant_1[2] = 0.0;
  LookupTableDynamic_Constant1_1[0] = 0.0;
  LookupTableDynamic_Constant1_1[1] = 0.0;
  LookupTableDynamic_Constant1_1[2] = 0.0;
  LookupTableDynamic_LookupTableDynamic_1 = 0.0;

  /* external inputs */
  LookupTableDynamic_In1_1 = 0.0;

  /* Start for Constant: '<Root>/Constant' */
  LookupTableDynamic_Constant_1[0] = LookupTableDynamic_P.Constant_Value[0];
  LookupTableDynamic_Constant_1[1] = LookupTableDynamic_P.Constant_Value[1];
  LookupTableDynamic_Constant_1[2] = LookupTableDynamic_P.Constant_Value[2];

  /* Start for Constant: '<Root>/Constant1' */
  LookupTableDynamic_Constant1_1[0] = LookupTableDynamic_P.Constant1_Value[0];
  LookupTableDynamic_Constant1_1[1] = LookupTableDynamic_P.Constant1_Value[1];
  LookupTableDynamic_Constant1_1[2] = LookupTableDynamic_P.Constant1_Value[2];
}

/* Model terminate function */
void LookupTableDynamic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
