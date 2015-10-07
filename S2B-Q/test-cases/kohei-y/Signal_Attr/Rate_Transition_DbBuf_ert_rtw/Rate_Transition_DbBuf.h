/*
 * File: Rate_Transition_DbBuf.h
 *
 * Code generated for Simulink model 'Rate_Transition_DbBuf'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 02:22:47 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rate_Transition_DbBuf_h_
#define RTW_HEADER_Rate_Transition_DbBuf_h_
#include <stddef.h>
#include <string.h>
#ifndef Rate_Transition_DbBuf_COMMON_INCLUDES_
# define Rate_Transition_DbBuf_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Rate_Transition_DbBuf_COMMON_INCLUDES_ */

#include "Rate_Transition_DbBuf_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T RateTransition_Buffer[2];     /* '<Root>/RateTransition' */
  int8_T RateTransition_ActiveBufIdx;  /* '<Root>/RateTransition' */
} DW_Rate_Transition_DbBuf_T;

/* Parameters (auto storage) */
struct P_Rate_Transition_DbBuf_T_ {
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<Root>/RateTransition'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Rate_Transition_DbBuf_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Rate_Transition_DbBuf_T Rate_Transition_DbBuf_P;

/* Block states (auto storage) */
extern DW_Rate_Transition_DbBuf_T Rate_Transition_DbBuf_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Rate_Transition_DbBuf_In1_1;/* '<Root>/In1' */
extern real_T Rate_Transition_DbBuf_RateTransition_1;/* '<Root>/RateTransition' */

/* Model entry point functions */
extern void Rate_Transition_DbBuf_initialize(void);
extern void Rate_Transition_DbBuf_step0(void);
extern void Rate_Transition_DbBuf_step1(void);
extern void Rate_Transition_DbBuf_step2(void);
extern void Rate_Transition_DbBuf_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rate_Transition_DbBu_T *const Rate_Transition_DbBuf_M;

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
 * '<Root>' : 'Rate_Transition_DbBuf'
 */
#endif                                 /* RTW_HEADER_Rate_Transition_DbBuf_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
