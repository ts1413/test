/*
 * File: Signal_Conversion_Bus.h
 *
 * Code generated for Simulink model 'Signal_Conversion_Bus'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Oct  4 01:50:56 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Signal_Conversion_Bus_h_
#define RTW_HEADER_Signal_Conversion_Bus_h_
#include <stddef.h>
#include <string.h>
#ifndef Signal_Conversion_Bus_COMMON_INCLUDES_
# define Signal_Conversion_Bus_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Signal_Conversion_Bus_COMMON_INCLUDES_ */

#include "Signal_Conversion_Bus_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  BusObject SignalConversion_BusCreator_1;/* '<Root>/SignalConversion' */
} B_Signal_Conversion_Bus_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_Signal_Conversion_Bus_T;

/* Real-time Model Data Structure */
struct tag_RTM_Signal_Conversion_Bus_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_Signal_Conversion_Bus_T Signal_Conversion_Bus_B;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Signal_Conversion_Bus_T Signal_Conversion_Bus_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Signal_Conversion_Bus_In1_1;/* '<Root>/In1' */

/* Model entry point functions */
extern void Signal_Conversion_Bus_initialize(void);
extern void Signal_Conversion_Bus_step(void);
extern void Signal_Conversion_Bus_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Signal_Conversion_Bu_T *const Signal_Conversion_Bus_M;

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
 * '<Root>' : 'Signal_Conversion_Bus'
 */
#endif                                 /* RTW_HEADER_Signal_Conversion_Bus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
