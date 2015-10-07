/*
 * File: Relay.c
 *
 * Code generated for Simulink model 'Relay'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:28 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Relay.h"
#include "Relay_private.h"

/* Exported block signals */
real_T Relay_In1_1;                    /* '<Root>/In1' */
real_T Relay_Relay_1;                  /* '<Root>/Relay' */

/* Block states (auto storage) */
D_Work_Relay Relay_DWork;

/* Real-time model */
RT_MODEL_Relay Relay_M_;
RT_MODEL_Relay *const Relay_M = &Relay_M_;

/* Model step function */
void Relay_step(void)
{
  /* Relay: '<Root>/Relay' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (Relay_In1_1 >= 2.2204460492503131E-16) {
    Relay_DWork.Relay_Mode = true;
  } else {
    if (Relay_In1_1 <= 2.2204460492503131E-16) {
      Relay_DWork.Relay_Mode = false;
    }
  }

  if (Relay_DWork.Relay_Mode) {
    Relay_Relay_1 = 1.0;
  } else {
    Relay_Relay_1 = 0.0;
  }

  /* End of Relay: '<Root>/Relay' */
}

/* Model initialize function */
void Relay_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Relay_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Relay_Relay_1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&Relay_DWork, 0,
                sizeof(D_Work_Relay));

  /* external inputs */
  Relay_In1_1 = 0.0;
}

/* Model terminate function */
void Relay_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
