/*
 * File: Chart.h
 *
 * Code generated for Simulink model 'Chart'.
 *
 * Model version                  : 1.78
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sat Oct  3 23:52:31 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Chart_h_
#define RTW_HEADER_Chart_h_
#include <stddef.h>
#include <string.h>
#ifndef Chart_COMMON_INCLUDES_
# define Chart_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Chart_COMMON_INCLUDES_ */

#include "Chart_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_Chart;          /* '<Root>/Chart' */
  uint8_T is_c3_Chart;                 /* '<Root>/Chart' */
} D_Work_Chart;

/* Real-time Model Data Structure */
struct tag_RTM_Chart {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern D_Work_Chart Chart_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Chart_In1_1;             /* '<Root>/In1' */
extern real_T Chart_Chart_SFunction_out;/* '<Root>/Chart' */

/* Model entry point functions */
extern void Chart_initialize(void);
extern void Chart_step(void);
extern void Chart_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Chart *const Chart_M;

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
 * '<Root>' : 'Chart'
 * '<S1>'   : 'Chart/Chart'
 */
#endif                                 /* RTW_HEADER_Chart_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
