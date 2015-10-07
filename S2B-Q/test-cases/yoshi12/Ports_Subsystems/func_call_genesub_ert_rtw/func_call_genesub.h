/*
 * File: func_call_genesub.h
 *
 * Code generated for Simulink model 'func_call_genesub'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:41:49 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_func_call_genesub_h_
#define RTW_HEADER_func_call_genesub_h_
#include <stddef.h>
#ifndef func_call_genesub_COMMON_INCLUDES_
# define func_call_genesub_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* func_call_genesub_COMMON_INCLUDES_ */

#include "func_call_genesub_types.h"

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
} ExtY_func_call_genesub_T;

/* Parameters (auto storage) */
struct P_func_call_genesub_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_func_call_genesub_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_func_call_genesub_T func_call_genesub_P;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_func_call_genesub_T func_call_genesub_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T func_call_genesub_In1_1; /* '<Root>/In1' */

/* Model entry point functions */
extern void func_call_genesub_initialize(void);
extern void func_call_genesub_step(void);
extern void func_call_genesub_terminate(void);

/* Real-time Model object */
extern RT_MODEL_func_call_genesub_T *const func_call_genesub_M;

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
 * '<Root>' : 'func_call_genesub'
 * '<S1>'   : 'func_call_genesub/Function_CallSubsystem'
 */
#endif                                 /* RTW_HEADER_func_call_genesub_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
