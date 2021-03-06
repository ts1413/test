/*
 * File: for_each_subsystem.h
 *
 * Code generated for Simulink model 'for_each_subsystem'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:37 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_for_each_subsystem_h_
#define RTW_HEADER_for_each_subsystem_h_
#include <stddef.h>
#ifndef for_each_subsystem_COMMON_INCLUDES_
# define for_each_subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* for_each_subsystem_COMMON_INCLUDES_ */

#include "for_each_subsystem_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_for_each_subsystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_for_each_subsystem_T {
  const char_T * volatile errorStatus;
};

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_for_each_subsystem_T for_each_subsystem_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T for_each_subsystem_In1_1;/* '<Root>/In1' */

/* Model entry point functions */
extern void for_each_subsystem_initialize(void);
extern void for_each_subsystem_step(void);
extern void for_each_subsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_for_each_subsystem_T *const for_each_subsystem_M;

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
 * '<Root>' : 'for_each_subsystem'
 * '<S1>'   : 'for_each_subsystem/ForEachSubsystem'
 */
#endif                                 /* RTW_HEADER_for_each_subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
