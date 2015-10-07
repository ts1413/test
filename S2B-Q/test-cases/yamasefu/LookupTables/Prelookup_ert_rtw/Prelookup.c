/*
 * File: Prelookup.c
 *
 * Code generated for Simulink model 'Prelookup'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:57:37 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Prelookup.h"
#include "Prelookup_private.h"

/* Exported block signals */
real_T Prelookup_InterpolationUsingPrelookup_1;/* '<Root>/InterpolationUsingPrelookup' */
uint32_T Prelookup_Prelookup_1;        /* '<Root>/Prelookup' */

/* Block signals (auto storage) */
B_Prelookup_T Prelookup_B;

/* External inputs (root inport signals with auto storage) */
ExtU_Prelookup_T Prelookup_U;

/* Real-time model */
RT_MODEL_Prelookup_T Prelookup_M_;
RT_MODEL_Prelookup_T *const Prelookup_M = &Prelookup_M_;
uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
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
void Prelookup_step(void)
{
  real_T frac;
  uint32_T bpIndex;

  /* PreLookup: '<Root>/Prelookup' incorporates:
   *  Inport: '<Root>/In1'
   */
  Prelookup_Prelookup_1 = plook_binx(Prelookup_U.Prelookup_In1_1,
    Prelookup_P.Prelookup_BreakpointsData, 10U,
    &Prelookup_B.Prelookup_Prelookup_2);

  /* Interpolation_n-D: '<Root>/InterpolationUsingPrelookup' */
  frac = Prelookup_B.Prelookup_Prelookup_2;
  bpIndex = Prelookup_Prelookup_1;
  Prelookup_InterpolationUsingPrelookup_1 = intrp1d_l_pw(bpIndex, frac,
    Prelookup_P.InterpolationUsingPrelookup_Tab);
}

/* Model initialize function */
void Prelookup_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Prelookup_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Prelookup_B), 0,
                sizeof(B_Prelookup_T));

  /* exported global signals */
  Prelookup_InterpolationUsingPrelookup_1 = 0.0;
  Prelookup_Prelookup_1 = 0U;

  /* external inputs */
  Prelookup_U.Prelookup_In1_1 = 0.0;
}

/* Model terminate function */
void Prelookup_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
