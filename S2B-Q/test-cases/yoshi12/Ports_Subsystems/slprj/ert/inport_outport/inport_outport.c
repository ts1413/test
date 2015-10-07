/*
 * File: inport_outport.c
 *
 * Code generated for Simulink model 'inport_outport'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:54:02 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "inport_outport.h"
#include "inport_outport_private.h"

/* Output and update for referenced model: 'inport_outport' */
void inport_outport(const real_T *rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<Root>/In1' */
  *rty_Out1 = *rtu_In1;
}

/* Model initialize function */
void inport_outport_initialize(const char_T **rt_errorStatus,
  RT_MODEL_inport_outport_T *const inport_outport_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(inport_outport_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
