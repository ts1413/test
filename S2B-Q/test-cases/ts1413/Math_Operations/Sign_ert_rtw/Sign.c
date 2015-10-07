/*
 * File: Sign.c
 *
 * Code generated for Simulink model 'Sign'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:40:40 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Sign.h"
#include "Sign_private.h"

/* Exported block signals */
real_T Sign_In1_1;                     /* '<Root>/In1' */
real_T Sign_Sign_1;                    /* '<Root>/Sign' */

/* Real-time model */
RT_MODEL_Sign Sign_M_;
RT_MODEL_Sign *const Sign_M = &Sign_M_;

/* Model step function */
void Sign_step(void)
{
  real_T u;

  /* Signum: '<Root>/Sign' incorporates:
   *  Inport: '<Root>/In1'
   */
  u = Sign_In1_1;
  if (u < 0.0) {
    Sign_Sign_1 = -1.0;
  } else if (u > 0.0) {
    Sign_Sign_1 = 1.0;
  } else if (u == 0.0) {
    Sign_Sign_1 = 0.0;
  } else {
    Sign_Sign_1 = u;
  }

  /* End of Signum: '<Root>/Sign' */
}

/* Model initialize function */
void Sign_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Sign_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Sign_Sign_1 = 0.0;

  /* external inputs */
  Sign_In1_1 = 0.0;
}

/* Model terminate function */
void Sign_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
