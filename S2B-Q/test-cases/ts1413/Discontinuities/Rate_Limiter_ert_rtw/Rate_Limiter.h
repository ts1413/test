/*
 * File: Rate_Limiter.h
 *
 * Code generated for Simulink model 'Rate_Limiter'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:22 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rate_Limiter_h_
#define RTW_HEADER_Rate_Limiter_h_
#include <string.h>
#ifndef Rate_Limiter_COMMON_INCLUDES_
# define Rate_Limiter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Rate_Limiter_COMMON_INCLUDES_ */

#include "Rate_Limiter_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T PrevY;                        /* '<Root>/RateLimiter' */
} D_Work_Rate_Limiter;

/* Real-time Model Data Structure */
struct tag_RTM_Rate_Limiter {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block states (auto storage) */
extern D_Work_Rate_Limiter Rate_Limiter_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Rate_Limiter_In1_1;      /* '<Root>/In1' */
extern real_T Rate_Limiter_RateLimiter_1;/* '<Root>/RateLimiter' */

/* Model entry point functions */
extern void Rate_Limiter_initialize(void);
extern void Rate_Limiter_step(void);
extern void Rate_Limiter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rate_Limiter *const Rate_Limiter_M;

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
 * '<Root>' : 'Rate_Limiter'
 */
#endif                                 /* RTW_HEADER_Rate_Limiter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
