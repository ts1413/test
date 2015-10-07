/*
 * File: Product2.c
 *
 * Code generated for Simulink model 'Product2'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:35 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Product2.h"
#include "Product2_private.h"

/* Exported block signals */
real_T Product2_In1_1;                 /* '<Root>/In1' */
real_T Product2_In2_1;                 /* '<Root>/In2' */
real_T Product2_In3_1;                 /* '<Root>/In3' */
real_T Product2_Product_1;             /* '<Root>/Product' */

/* Real-time model */
RT_MODEL_Product2_T Product2_M_;
RT_MODEL_Product2_T *const Product2_M = &Product2_M_;

/* Model step function */
void Product2_step(void)
{
  /* Product: '<Root>/Product' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In3'
   */
  Product2_Product_1 = Product2_In1_1 / Product2_In2_1 * Product2_In3_1;
}

/* Model initialize function */
void Product2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Product2_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Product2_Product_1 = 0.0;

  /* external inputs */
  Product2_In1_1 = 0.0;
  Product2_In2_1 = 0.0;
  Product2_In3_1 = 0.0;
}

/* Model terminate function */
void Product2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
