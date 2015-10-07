/*
 * File: Prelookup.h
 *
 * Code generated for Simulink model 'Prelookup'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:57:37 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Prelookup_h_
#define RTW_HEADER_Prelookup_h_
#include <stddef.h>
#include <string.h>
#ifndef Prelookup_COMMON_INCLUDES_
# define Prelookup_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Prelookup_COMMON_INCLUDES_ */

#include "Prelookup_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Prelookup_Prelookup_2;        /* '<Root>/Prelookup' */
} B_Prelookup_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Prelookup_In1_1;              /* '<Root>/In1' */
} ExtU_Prelookup_T;

/* Parameters (auto storage) */
struct P_Prelookup_T_ {
  real_T Prelookup_BreakpointsData[11];/* Expression: [10;20;30;40;50;60;70;80;90;100;110]
                                        * Referenced by: '<Root>/Prelookup'
                                        */
  real_T InterpolationUsingPrelookup_Tab[11];/* Expression: sqrt([1:11])
                                              * Referenced by: '<Root>/InterpolationUsingPrelookup'
                                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_Prelookup_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Prelookup_T Prelookup_P;

/* Block signals (auto storage) */
extern B_Prelookup_T Prelookup_B;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Prelookup_T Prelookup_U;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Prelookup_InterpolationUsingPrelookup_1;/* '<Root>/InterpolationUsingPrelookup' */
extern uint32_T Prelookup_Prelookup_1; /* '<Root>/Prelookup' */

/* Model entry point functions */
extern void Prelookup_initialize(void);
extern void Prelookup_step(void);
extern void Prelookup_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Prelookup_T *const Prelookup_M;

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
 * '<Root>' : 'Prelookup'
 */
#endif                                 /* RTW_HEADER_Prelookup_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
