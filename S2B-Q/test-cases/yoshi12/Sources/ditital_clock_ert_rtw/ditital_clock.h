/*
 * File: ditital_clock.h
 *
 * Code generated for Simulink model 'ditital_clock'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sat Oct  3 23:53:23 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ditital_clock_h_
#define RTW_HEADER_ditital_clock_h_
#include <string.h>
#ifndef ditital_clock_COMMON_INCLUDES_
# define ditital_clock_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ditital_clock_COMMON_INCLUDES_ */

#include "ditital_clock_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_ditital_clock_T {
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

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T ditital_clock_DigitalClock_1;/* '<Root>/DigitalClock' */

/* Model entry point functions */
extern void ditital_clock_initialize(void);
extern void ditital_clock_step(void);
extern void ditital_clock_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ditital_clock_T *const ditital_clock_M;

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
 * '<Root>' : 'ditital_clock'
 */
#endif                                 /* RTW_HEADER_ditital_clock_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
