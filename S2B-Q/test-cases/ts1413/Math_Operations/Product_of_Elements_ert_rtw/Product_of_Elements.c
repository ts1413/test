/*
 * File: Product_of_Elements.c
 *
 * Code generated for Simulink model 'Product_of_Elements'.
 *
 * Model version                  : 1.89
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:08:16 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Product_of_Elements.h"
#include "Product_of_Elements_private.h"

/* Exported block signals */
real_T Product_of_Elements_In1_1;      /* '<Root>/In1' */
real_T Product_of_Elements_ProductofElements_1;/* '<Root>/ProductofElements' */

/* Real-time model */
RT_MODEL_Product_of_Elements Product_of_Elements_M_;
RT_MODEL_Product_of_Elements *const Product_of_Elements_M =
  &Product_of_Elements_M_;

/* Model step function */
void Product_of_Elements_step(void)
{
  /* Product: '<Root>/ProductofElements' incorporates:
   *  Inport: '<Root>/In1'
   */
  Product_of_Elements_ProductofElements_1 = Product_of_Elements_In1_1;
}

/* Model initialize function */
void Product_of_Elements_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Product_of_Elements_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Product_of_Elements_ProductofElements_1 = 0.0;

  /* external inputs */
  Product_of_Elements_In1_1 = 0.0;
}

/* Model terminate function */
void Product_of_Elements_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
