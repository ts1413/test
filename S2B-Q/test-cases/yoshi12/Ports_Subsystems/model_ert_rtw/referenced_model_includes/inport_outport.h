/*
 * File: inport_outport.h
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

#ifndef RTW_HEADER_inport_outport_h_
#define RTW_HEADER_inport_outport_h_
#ifndef inport_outport_COMMON_INCLUDES_
# define inport_outport_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* inport_outport_COMMON_INCLUDES_ */

#include "inport_outport_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Real-time Model Data Structure */
struct tag_RTM_inport_outport_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_inport_outport_T rtm;
} MdlrefDW_inport_outport_T;

/* Model reference registration function */
extern void inport_outport_initialize(const char_T **rt_errorStatus,
  RT_MODEL_inport_outport_T *const inport_outport_M);
extern void inport_outport(const real_T *rtu_In1, real_T *rty_Out1);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'inport_outport'
 */
#endif                                 /* RTW_HEADER_inport_outport_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
