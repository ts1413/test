/*
 * File: Scope2.h
 *
 * Code generated for Simulink model 'Scope2'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:55:58 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Scope2_h_
#define RTW_HEADER_Scope2_h_
#include <stddef.h>
#include <string.h>
#ifndef Scope2_COMMON_INCLUDES_
# define Scope2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Scope2_COMMON_INCLUDES_ */

#include "Scope2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_Scope2_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_Scope2_T;

/* Real-time Model Data Structure */
struct tag_RTM_Scope2_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_Scope2_T Scope2_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Scope2_T Scope2_U;

/* Model entry point functions */
extern void Scope2_initialize(void);
extern void Scope2_step(void);
extern void Scope2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Scope2_T *const Scope2_M;

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
 * '<Root>' : 'Scope2'
 */
#endif                                 /* RTW_HEADER_Scope2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
