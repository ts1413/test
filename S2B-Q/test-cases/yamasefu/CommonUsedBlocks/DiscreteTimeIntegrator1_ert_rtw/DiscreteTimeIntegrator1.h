/*
 * File: DiscreteTimeIntegrator1.h
 *
 * Code generated for Simulink model 'DiscreteTimeIntegrator1'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Oct  1 15:33:29 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DiscreteTimeIntegrator1_h_
#define RTW_HEADER_DiscreteTimeIntegrator1_h_
#include <string.h>
#ifndef DiscreteTimeIntegrator1_COMMON_INCLUDES_
# define DiscreteTimeIntegrator1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DiscreteTimeIntegrator1_COMMON_INCLUDES_ */

#include "DiscreteTimeIntegrator1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Discrete_TimeIntegrator_DSTATE;/* '<Root>/Discrete_TimeIntegrator' */
  uint8_T Discrete_TimeIntegrator_IC_LOAD;/* '<Root>/Discrete_TimeIntegrator' */
} DW_DiscreteTimeIntegrator1_T;

/* Parameters (auto storage) */
struct P_DiscreteTimeIntegrator1_T_ {
  real_T Discrete_TimeIntegrator_gainval;/* Computed Parameter: Discrete_TimeIntegrator_gainval
                                          * Referenced by: '<Root>/Discrete_TimeIntegrator'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_DiscreteTimeIntegrato_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_DiscreteTimeIntegrator1_T DiscreteTimeIntegrator1_P;

/* Block states (auto storage) */
extern DW_DiscreteTimeIntegrator1_T DiscreteTimeIntegrator1_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T DiscreteTimeIntegrator1_In1_1;/* '<Root>/In1' */
extern real_T DiscreteTimeIntegrator1_In3_1;/* '<Root>/In3' */
extern real_T DiscreteTimeIntegrator1_Discrete_TimeIntegrator_1;/* '<Root>/Discrete_TimeIntegrator' */

/* Model entry point functions */
extern void DiscreteTimeIntegrator1_initialize(void);
extern void DiscreteTimeIntegrator1_step(void);
extern void DiscreteTimeIntegrator1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DiscreteTimeIntegrat_T *const DiscreteTimeIntegrator1_M;

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
 * '<Root>' : 'DiscreteTimeIntegrator1'
 */
#endif                                 /* RTW_HEADER_DiscreteTimeIntegrator1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
