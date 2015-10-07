/*
 * File: DataTypeConversion2.h
 *
 * Code generated for Simulink model 'DataTypeConversion2'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:54:34 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DataTypeConversion2_h_
#define RTW_HEADER_DataTypeConversion2_h_
#include <stddef.h>
#ifndef DataTypeConversion2_COMMON_INCLUDES_
# define DataTypeConversion2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DataTypeConversion2_COMMON_INCLUDES_ */

#include "DataTypeConversion2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_DataTypeConversion2_T {
  const char_T * volatile errorStatus;
};

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T DataTypeConversion2_In1_1;/* '<Root>/In1' */
extern real_T DataTypeConversion2_DataTypeConversion_1;/* '<Root>/DataTypeConversion' */

/* Model entry point functions */
extern void DataTypeConversion2_initialize(void);
extern void DataTypeConversion2_step(void);
extern void DataTypeConversion2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DataTypeConversion2_T *const DataTypeConversion2_M;

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
 * '<Root>' : 'DataTypeConversion2'
 */
#endif                                 /* RTW_HEADER_DataTypeConversion2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
