/*
 * File: Hit_Crossing.h
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

#ifndef RTW_HEADER_Hit_Crossing_h_
#define RTW_HEADER_Hit_Crossing_h_
#include <stddef.h>
#include <string.h>
#ifndef Hit_Crossing_COMMON_INCLUDES_
# define Hit_Crossing_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Hit_Crossing_COMMON_INCLUDES_ */

#include "Hit_Crossing_types.h"
#include "rt_zcfcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int_T HitCrossing_MODE;              /* '<Root>/HitCrossing' */
} D_Work_Hit_Crossing;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<Root>/HitCrossing' */
} PrevZCSigStates_Hit_Crossing;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T Out1;                      /* '<Root>/Out1' */
} ExternalOutputs_Hit_Crossing;

/* Real-time Model Data Structure */
struct tag_RTM_Hit_Crossing {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern D_Work_Hit_Crossing Hit_Crossing_DWork;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Hit_Crossing Hit_Crossing_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Hit_Crossing_In1_1;      /* '<Root>/In1' */

/* Model entry point functions */
extern void Hit_Crossing_initialize(void);
extern void Hit_Crossing_step(void);
extern void Hit_Crossing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Hit_Crossing *const Hit_Crossing_M;

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
 * '<Root>' : 'Hit_Crossing'
 */
#endif                                 /* RTW_HEADER_Hit_Crossing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
