/*
 * File: IC.h
 *
 * Code generated for Simulink model 'IC'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:41:00 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IC_h_
#define RTW_HEADER_IC_h_
#include <stddef.h>
#include <string.h>
#ifndef IC_COMMON_INCLUDES_
# define IC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* IC_COMMON_INCLUDES_ */

#include "IC_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  boolean_T IC_FirstOutputTime;        /* '<Root>/IC' */
} DW_IC_T;

/* Parameters (auto storage) */
struct P_IC_T_ {
  real_T IC_Value;                     /* Expression: 100
                                        * Referenced by: '<Root>/IC'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_IC_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_IC_T IC_P;

/* Block states (auto storage) */
extern DW_IC_T IC_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T IC_In1_1;                /* '<Root>/In1' */
extern real_T IC_IC_1;                 /* '<Root>/IC' */

/* Model entry point functions */
extern void IC_initialize(void);
extern void IC_step(void);
extern void IC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_IC_T *const IC_M;

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
 * '<Root>' : 'IC'
 */
#endif                                 /* RTW_HEADER_IC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
