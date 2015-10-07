/*
 * File: LookupTable1D2.c
 *
 * Code generated for Simulink model 'LookupTable1D2'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:48 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LookupTable1D2.h"
#include "LookupTable1D2_private.h"

/* Exported block signals */
real_T LookupTable1D2_In1_1;           /* '<Root>/In1' */
real_T LookupTable1D2_1_DLookupTable_1;/* '<Root>/1_DLookupTable' */

/* Real-time model */
RT_MODEL_LookupTable1D2_T LookupTable1D2_M_;
RT_MODEL_LookupTable1D2_T *const LookupTable1D2_M = &LookupTable1D2_M_;
uint32_T plook_u32d_bincka(real_T u, const real_T bp[], uint32_T maxIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  while (iRght - iLeft > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      iLeft = bpIdx;
    }

    bpIdx = (iRght + iLeft) >> 1U;
  }

  return iLeft;
}

/* Model step function */
void LookupTable1D2_step(void)
{
  uint32_T bpIdx;

  /* Lookup_n-D: '<Root>/1_DLookupTable' incorporates:
   *  Inport: '<Root>/In1'
   */
  bpIdx = plook_u32d_bincka(LookupTable1D2_In1_1,
    LookupTable1D2_P._DLookupTable_bp01Data, 10U);
  LookupTable1D2_1_DLookupTable_1 =
    LookupTable1D2_P._DLookupTable_tableData[bpIdx];
}

/* Model initialize function */
void LookupTable1D2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(LookupTable1D2_M, (NULL));

  /* block I/O */

  /* exported global signals */
  LookupTable1D2_1_DLookupTable_1 = 0.0;

  /* external inputs */
  LookupTable1D2_In1_1 = 0.0;
}

/* Model terminate function */
void LookupTable1D2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
