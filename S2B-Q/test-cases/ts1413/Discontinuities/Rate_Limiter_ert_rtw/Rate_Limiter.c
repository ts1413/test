/*
 * File: Rate_Limiter.c
 *
 * Code generated for Simulink model 'Rate_Limiter'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:22 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rate_Limiter.h"
#include "Rate_Limiter_private.h"

/* Exported block signals */
real_T Rate_Limiter_In1_1;             /* '<Root>/In1' */
real_T Rate_Limiter_RateLimiter_1;     /* '<Root>/RateLimiter' */

/* Block states (auto storage) */
D_Work_Rate_Limiter Rate_Limiter_DWork;

/* Real-time model */
RT_MODEL_Rate_Limiter Rate_Limiter_M_;
RT_MODEL_Rate_Limiter *const Rate_Limiter_M = &Rate_Limiter_M_;

/* Model step function */
void Rate_Limiter_step(void)
{
  real_T rateLimiterRate;

  /* RateLimiter: '<Root>/RateLimiter' incorporates:
   *  Inport: '<Root>/In1'
   */
  rateLimiterRate = Rate_Limiter_In1_1 - Rate_Limiter_DWork.PrevY;
  if (rateLimiterRate > 0.1) {
    Rate_Limiter_RateLimiter_1 = Rate_Limiter_DWork.PrevY + 0.1;
  } else if (rateLimiterRate < (-0.1)) {
    Rate_Limiter_RateLimiter_1 = Rate_Limiter_DWork.PrevY + (-0.1);
  } else {
    Rate_Limiter_RateLimiter_1 = Rate_Limiter_In1_1;
  }

  Rate_Limiter_DWork.PrevY = Rate_Limiter_RateLimiter_1;

  /* End of RateLimiter: '<Root>/RateLimiter' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Rate_Limiter_M->Timing.clockTick0++;
}

/* Model initialize function */
void Rate_Limiter_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Rate_Limiter_M, 0,
                sizeof(RT_MODEL_Rate_Limiter));

  /* block I/O */

  /* exported global signals */
  Rate_Limiter_RateLimiter_1 = 0.0;

  /* states (dwork) */
  Rate_Limiter_DWork.PrevY = 0.0;

  /* external inputs */
  Rate_Limiter_In1_1 = 0.0;

  /* InitializeConditions for RateLimiter: '<Root>/RateLimiter' */
  Rate_Limiter_DWork.PrevY = 0.0;
}

/* Model terminate function */
void Rate_Limiter_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
