/*
 * File: dsm.h
 *
 * Code generated for Simulink model 'dsm'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 02:23:28 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_dsm_h_
#define RTW_HEADER_dsm_h_
#include <stddef.h>
#include <string.h>
#ifndef dsm_COMMON_INCLUDES_
# define dsm_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* dsm_COMMON_INCLUDES_ */

#include "dsm_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Data;                         /* '<Root>/DataStoreMemory' */
} DW_dsm_T;

/* Parameters (auto storage) */
struct P_dsm_T_ {
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/DataStoreMemory'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_dsm_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_dsm_T dsm_P;

/* Block states (auto storage) */
extern DW_dsm_T dsm_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T dsm_In1_1;               /* '<Root>/In1' */
extern real_T dsm_DataStoreRead_1;     /* '<Root>/DataStoreRead' */

/* Model entry point functions */
extern void dsm_initialize(void);
extern void dsm_step(void);
extern void dsm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_dsm_T *const dsm_M;

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
 * '<Root>' : 'dsm'
 */
#endif                                 /* RTW_HEADER_dsm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
