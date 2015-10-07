/*
 * File: Product1.c
 *
 * Code generated for Simulink model 'Product1'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:30 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Product1.h"
#include "Product1_private.h"

/* Exported block signals */
real_T Product1_In1_1;                 /* '<Root>/In1' */
real_T Product1_Product_1;             /* '<Root>/Product' */

/* Real-time model */
RT_MODEL_Product1_T Product1_M_;
RT_MODEL_Product1_T *const Product1_M = &Product1_M_;

/* Model step function */
void Product1_step(void)
{
  /* Product: '<Root>/Product' incorporates:
   *  Inport: '<Root>/In1'
   */
  Product1_Product_1 = Product1_In1_1 * Product1_In1_1;
}

/* Model initialize function */
void Product1_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Product1_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Product1_Product_1 = 0.0;

  /* external inputs */
  Product1_In1_1 = 0.0;
}

/* Model terminate function */
void Product1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
