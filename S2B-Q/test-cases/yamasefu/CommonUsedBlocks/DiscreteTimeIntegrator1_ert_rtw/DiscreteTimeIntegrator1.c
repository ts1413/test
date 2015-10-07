/*
 * File: DiscreteTimeIntegrator1.c
 *
 * Code generated for Simulink model 'DiscreteTimeIntegrator1'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Oct  1 15:33:29 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DiscreteTimeIntegrator1.h"
#include "DiscreteTimeIntegrator1_private.h"

/* Exported block signals */
real_T DiscreteTimeIntegrator1_In1_1;  /* '<Root>/In1' */
real_T DiscreteTimeIntegrator1_In3_1;  /* '<Root>/In3' */
real_T DiscreteTimeIntegrator1_Discrete_TimeIntegrator_1;/* '<Root>/Discrete_TimeIntegrator' */

/* Block states (auto storage) */
DW_DiscreteTimeIntegrator1_T DiscreteTimeIntegrator1_DW;

/* Real-time model */
RT_MODEL_DiscreteTimeIntegrat_T DiscreteTimeIntegrator1_M_;
RT_MODEL_DiscreteTimeIntegrat_T *const DiscreteTimeIntegrator1_M =
  &DiscreteTimeIntegrator1_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (DiscreteTimeIntegrator1_M->Timing.TaskCounters.TID[1])++;
  if ((DiscreteTimeIntegrator1_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    DiscreteTimeIntegrator1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void DiscreteTimeIntegrator1_step(void)
{
  if (DiscreteTimeIntegrator1_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' incorporates:
     *  Inport: '<Root>/In3'
     */
    if (DiscreteTimeIntegrator1_DW.Discrete_TimeIntegrator_IC_LOAD != 0) {
      DiscreteTimeIntegrator1_DW.Discrete_TimeIntegrator_DSTATE =
        DiscreteTimeIntegrator1_In3_1;
    }

    DiscreteTimeIntegrator1_Discrete_TimeIntegrator_1 =
      DiscreteTimeIntegrator1_DW.Discrete_TimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' */

    /* Update for DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' incorporates:
     *  Update for Inport: '<Root>/In1'
     */
    DiscreteTimeIntegrator1_DW.Discrete_TimeIntegrator_IC_LOAD = 0U;
    DiscreteTimeIntegrator1_DW.Discrete_TimeIntegrator_DSTATE +=
      DiscreteTimeIntegrator1_P.Discrete_TimeIntegrator_gainval *
      DiscreteTimeIntegrator1_In1_1;
  }

  rate_scheduler();
}

/* Model initialize function */
void DiscreteTimeIntegrator1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)DiscreteTimeIntegrator1_M, 0,
                sizeof(RT_MODEL_DiscreteTimeIntegrat_T));

  /* block I/O */

  /* exported global signals */
  DiscreteTimeIntegrator1_Discrete_TimeIntegrator_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&DiscreteTimeIntegrator1_DW, 0,
                sizeof(DW_DiscreteTimeIntegrator1_T));

  /* external inputs */
  DiscreteTimeIntegrator1_In1_1 = 0.0;
  DiscreteTimeIntegrator1_In3_1 = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete_TimeIntegrator' */
  DiscreteTimeIntegrator1_DW.Discrete_TimeIntegrator_IC_LOAD = 1U;
}

/* Model terminate function */
void DiscreteTimeIntegrator1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
