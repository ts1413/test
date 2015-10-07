/*
 * File: LookupTable1D6.c
 *
 * Code generated for Simulink model 'LookupTable1D6'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:56:59 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LookupTable1D6.h"
#include "LookupTable1D6_private.h"

/* Exported block signals */
real_T LookupTable1D6_In1_1;           /* '<Root>/In1' */
real_T LookupTable1D6_1_DLookupTable_1;/* '<Root>/1_DLookupTable' */

/* Real-time model */
RT_MODEL_LookupTable1D6_T LookupTable1D6_M_;
RT_MODEL_LookupTable1D6_T *const LookupTable1D6_M = &LookupTable1D6_M_;
uint32_T plook_evenx(real_T u, real_T bp0, real_T bpSpace, uint32_T maxIndex,
                     real_T *fraction)
{
  uint32_T bpIndex;
  real_T uAdjust;
  real_T invSpc;
  real_T fbpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = (u - bp0) / bpSpace;
  } else {
    uAdjust = u - bp0;
    invSpc = 1.0 / bpSpace;
    fbpIndex = uAdjust * invSpc;
    if (fbpIndex >= maxIndex) {
      bpIndex = maxIndex - 1U;
      *fraction = (uAdjust - (real_T)(maxIndex - 1U) * bpSpace) * invSpc;
    } else {
      bpIndex = (uint32_T)fbpIndex;
      *fraction = (uAdjust - (real_T)bpIndex * bpSpace) * invSpc;
    }
  }

  return bpIndex;
}

real_T intrp1d_l_pw(uint32_T bpIndex, real_T frac, const real_T table[])
{
  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[bpIndex + 1U] - table[bpIndex]) * frac + table[bpIndex];
}

/* Model step function */
void LookupTable1D6_step(void)
{
  uint32_T bpIdx;
  real_T frac;

  /* Lookup_n-D: '<Root>/1_DLookupTable' incorporates:
   *  Inport: '<Root>/In1'
   */
  bpIdx = plook_evenx(LookupTable1D6_In1_1,
                      LookupTable1D6_P._DLookupTable_bp01Data[0],
                      LookupTable1D6_P._DLookupTable_bp01Data[1] -
                      LookupTable1D6_P._DLookupTable_bp01Data[0], 10U, &frac);
  LookupTable1D6_1_DLookupTable_1 = intrp1d_l_pw(bpIdx, frac,
    LookupTable1D6_P._DLookupTable_tableData);
}

/* Model initialize function */
void LookupTable1D6_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(LookupTable1D6_M, (NULL));

  /* block I/O */

  /* exported global signals */
  LookupTable1D6_1_DLookupTable_1 = 0.0;

  /* external inputs */
  LookupTable1D6_In1_1 = 0.0;
}

/* Model terminate function */
void LookupTable1D6_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
