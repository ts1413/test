/*
 * File: Chart.c
 *
 * Code generated for Simulink model 'Chart'.
 *
 * Model version                  : 1.78
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sat Oct  3 23:52:31 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Chart.h"
#include "Chart_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Chart_IN_False                 ((uint8_T)1U)
#define Chart_IN_NO_ACTIVE_CHILD       ((uint8_T)0U)
#define Chart_IN_True                  ((uint8_T)2U)

/* Exported block signals */
real_T Chart_In1_1;                    /* '<Root>/In1' */
real_T Chart_Chart_SFunction_out;      /* '<Root>/Chart' */

/* Block states (auto storage) */
D_Work_Chart Chart_DWork;

/* Real-time model */
RT_MODEL_Chart Chart_M_;
RT_MODEL_Chart *const Chart_M = &Chart_M_;

/* Model step function */
void Chart_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/In1'
   */
  /* Gateway: Chart */
  /* During: Chart */
  if (Chart_DWork.is_active_c3_Chart == 0U) {
    /* Entry: Chart */
    Chart_DWork.is_active_c3_Chart = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:3' */
    if (Chart_In1_1 > 0.0) {
      /* Transition: '<S1>:7' */
      Chart_DWork.is_c3_Chart = Chart_IN_True;
    } else {
      if (Chart_In1_1 <= 0.0) {
        /* Transition: '<S1>:9' */
        Chart_DWork.is_c3_Chart = Chart_IN_False;
      }
    }
  } else if (Chart_DWork.is_c3_Chart == Chart_IN_False) {
    /* During 'False': '<S1>:2' */
    if (Chart_In1_1 > 0.0) {
      /* Transition: '<S1>:13' */
      Chart_DWork.is_c3_Chart = Chart_IN_True;
    } else {
      Chart_Chart_SFunction_out = 0.0;
    }
  } else {
    /* During 'True': '<S1>:1' */
    if (Chart_In1_1 <= 0.0) {
      /* Transition: '<S1>:11' */
      Chart_DWork.is_c3_Chart = Chart_IN_False;
    } else {
      Chart_Chart_SFunction_out = 1.0;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Chart_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Chart_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Chart_Chart_SFunction_out = 0.0;

  /* states (dwork) */
  (void) memset((void *)&Chart_DWork, 0,
                sizeof(D_Work_Chart));

  /* external inputs */
  Chart_In1_1 = 0.0;

  /* InitializeConditions for Chart: '<Root>/Chart' */
  Chart_DWork.is_active_c3_Chart = 0U;
  Chart_DWork.is_c3_Chart = Chart_IN_NO_ACTIVE_CHILD;
  Chart_Chart_SFunction_out = 0.0;
}

/* Model terminate function */
void Chart_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
