/*
 * File: Hit_Crossing.c
 *
 * Code generated for Simulink model 'Hit_Crossing'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:07:11 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Hit_Crossing.h"
#include "Hit_Crossing_private.h"

/* Exported block signals */
real_T Hit_Crossing_In1_1;             /* '<Root>/In1' */

/* Block states (auto storage) */
D_Work_Hit_Crossing Hit_Crossing_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_Hit_Crossing Hit_Crossing_PrevZCSigState;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Hit_Crossing Hit_Crossing_Y;

/* Real-time model */
RT_MODEL_Hit_Crossing Hit_Crossing_M_;
RT_MODEL_Hit_Crossing *const Hit_Crossing_M = &Hit_Crossing_M_;

/* Model step function */
void Hit_Crossing_step(void)
{
  ZCEventType zcEvent;

  /* HitCross: '<Root>/HitCrossing' incorporates:
   *  Inport: '<Root>/In1'
   */
  zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                     &Hit_Crossing_PrevZCSigState.HitCrossing_Input_ZCE,
                     (Hit_Crossing_In1_1 - 0.0));
  if (Hit_Crossing_DWork.HitCrossing_MODE == 0) {
    if (zcEvent != NO_ZCEVENT) {
      /* Outport: '<Root>/Out1' */
      Hit_Crossing_Y.Out1 = !Hit_Crossing_Y.Out1;
      Hit_Crossing_DWork.HitCrossing_MODE = 1;
    } else if (Hit_Crossing_Y.Out1) {
      if (Hit_Crossing_In1_1 != 0.0) {
        /* Outport: '<Root>/Out1' */
        Hit_Crossing_Y.Out1 = false;
      }
    } else {
      if (Hit_Crossing_In1_1 == 0.0) {
        /* Outport: '<Root>/Out1' */
        Hit_Crossing_Y.Out1 = true;
      }
    }
  } else {
    if (Hit_Crossing_In1_1 != 0.0) {
      /* Outport: '<Root>/Out1' */
      Hit_Crossing_Y.Out1 = false;
    }

    Hit_Crossing_DWork.HitCrossing_MODE = 0;
  }

  /* End of HitCross: '<Root>/HitCrossing' */
}

/* Model initialize function */
void Hit_Crossing_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Hit_Crossing_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Hit_Crossing_DWork, 0,
                sizeof(D_Work_Hit_Crossing));

  /* external inputs */
  Hit_Crossing_In1_1 = 0.0;

  /* external outputs */
  Hit_Crossing_Y.Out1 = false;
  Hit_Crossing_PrevZCSigState.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void Hit_Crossing_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
