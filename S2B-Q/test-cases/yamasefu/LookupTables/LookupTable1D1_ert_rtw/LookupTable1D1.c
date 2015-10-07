/*
 * File: LookupTable1D1.c
 *
 * Code generated for Simulink model 'LookupTable1D1'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:43 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LookupTable1D1.h"
#include "LookupTable1D1_private.h"

/* Exported block signals */
real_T LookupTable1D1_In1_1;           /* '<Root>/In1' */
real_T LookupTable1D1_1_DLookupTable_1;/* '<Root>/1_DLookupTable' */

/* Real-time model */
RT_MODEL_LookupTable1D1_T LookupTable1D1_M_;
RT_MODEL_LookupTable1D1_T *const LookupTable1D1_M = &LookupTable1D1_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Model step function */
void LookupTable1D1_step(void)
{
  /* Lookup_n-D: '<Root>/1_DLookupTable' incorporates:
   *  Inport: '<Root>/In1'
   */
  LookupTable1D1_1_DLookupTable_1 = look1_binlxpw(LookupTable1D1_In1_1,
    LookupTable1D1_P._DLookupTable_bp01Data,
    LookupTable1D1_P._DLookupTable_tableData, 10U);
}

/* Model initialize function */
void LookupTable1D1_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(LookupTable1D1_M, (NULL));

  /* block I/O */

  /* exported global signals */
  LookupTable1D1_1_DLookupTable_1 = 0.0;

  /* external inputs */
  LookupTable1D1_In1_1 = 0.0;
}

/* Model terminate function */
void LookupTable1D1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
