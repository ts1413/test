/*
 * File: LookupTable1D6_private.h
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

#ifndef RTW_HEADER_LookupTable1D6_private_h_
#define RTW_HEADER_LookupTable1D6_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern uint32_T plook_evenx(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex, real_T *fraction);
extern real_T intrp1d_l_pw(uint32_T bpIndex, real_T frac, const real_T table[]);

#endif                                 /* RTW_HEADER_LookupTable1D6_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
