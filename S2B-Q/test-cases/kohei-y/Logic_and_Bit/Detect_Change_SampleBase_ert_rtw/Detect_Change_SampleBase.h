/*
 * File: Detect_Change_SampleBase.h
 *
 * Code generated for Simulink model 'Detect_Change_SampleBase'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 02:22:28 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Detect_Change_SampleBase_h_
#define RTW_HEADER_Detect_Change_SampleBase_h_
#include <stddef.h>
#include <string.h>
#ifndef Detect_Change_SampleBase_COMMON_INCLUDES_
# define Detect_Change_SampleBase_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Detect_Change_SampleBase_COMMON_INCLUDES_ */

#include "Detect_Change_SampleBase_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Uk1;                          /* '<S1>/Delay Input1' */
} B_Detect_Change_SampleBase_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S1>/Delay Input1' */
} DW_Detect_Change_SampleBase_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T Out1;                      /* '<Root>/Out1' */
} ExtY_Detect_Change_SampleBase_T;

/* Parameters (auto storage) */
struct P_Detect_Change_SampleBase_T_ {
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S1>/Delay Input1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Detect_Change_SampleB_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Detect_Change_SampleBase_T Detect_Change_SampleBase_P;

/* Block signals (auto storage) */
extern B_Detect_Change_SampleBase_T Detect_Change_SampleBase_B;

/* Block states (auto storage) */
extern DW_Detect_Change_SampleBase_T Detect_Change_SampleBase_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Detect_Change_SampleBase_T Detect_Change_SampleBase_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Detect_Change_SampleBase_In1_1;/* '<Root>/In1' */

/* Model entry point functions */
extern void Detect_Change_SampleBase_initialize(void);
extern void Detect_Change_SampleBase_step(void);
extern void Detect_Change_SampleBase_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Detect_Change_Sample_T *const Detect_Change_SampleBase_M;

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
 * '<Root>' : 'Detect_Change_SampleBase'
 * '<S1>'   : 'Detect_Change_SampleBase/DetectChange'
 */
#endif                                 /* RTW_HEADER_Detect_Change_SampleBase_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
