/*
 * File: Difference.h
 *
 * Code generated for Simulink model 'Difference'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:47 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Difference_h_
#define RTW_HEADER_Difference_h_
#include <stddef.h>
#ifndef Difference_COMMON_INCLUDES_
# define Difference_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Difference_COMMON_INCLUDES_ */

#include "Difference_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Uk1;                          /* '<S1>/UD' */
} BlockIO_Difference;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
} D_Work_Difference;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExternalOutputs_Difference;

/* Real-time Model Data Structure */
struct tag_RTM_Difference {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_Difference Difference_B;

/* Block states (auto storage) */
extern D_Work_Difference Difference_DWork;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Difference Difference_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Difference_In1_1;        /* '<Root>/In1' */

/* Model entry point functions */
extern void Difference_initialize(void);
extern void Difference_step(void);
extern void Difference_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Difference *const Difference_M;

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
 * '<Root>' : 'Difference'
 * '<S1>'   : 'Difference/Difference'
 */
#endif                                 /* RTW_HEADER_Difference_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
