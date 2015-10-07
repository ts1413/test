/*
 * File: ditital_clock.c
 *
 * Code generated for Simulink model 'ditital_clock'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sat Oct  3 23:53:23 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ditital_clock.h"
#include "ditital_clock_private.h"

/* Exported block signals */
real_T ditital_clock_DigitalClock_1;   /* '<Root>/DigitalClock' */

/* Real-time model */
RT_MODEL_ditital_clock_T ditital_clock_M_;
RT_MODEL_ditital_clock_T *const ditital_clock_M = &ditital_clock_M_;

/* Model step function */
void ditital_clock_step(void)
{
  /* DigitalClock: '<Root>/DigitalClock' */
  ditital_clock_DigitalClock_1 = ((ditital_clock_M->Timing.clockTick0) );

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ditital_clock_M->Timing.clockTick0++;
}

/* Model initialize function */
void ditital_clock_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ditital_clock_M, 0,
                sizeof(RT_MODEL_ditital_clock_T));

  /* block I/O */

  /* exported global signals */
  ditital_clock_DigitalClock_1 = 0.0;
}

/* Model terminate function */
void ditital_clock_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
