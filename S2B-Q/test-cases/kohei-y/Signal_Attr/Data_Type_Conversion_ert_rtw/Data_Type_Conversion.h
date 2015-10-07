/*
 * File: Data_Type_Conversion.h
 *
 * Code generated for Simulink model 'Data_Type_Conversion'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:40:54 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Data_Type_Conversion_h_
#define RTW_HEADER_Data_Type_Conversion_h_
#include <math.h>
#include <stddef.h>
#ifndef Data_Type_Conversion_COMMON_INCLUDES_
# define Data_Type_Conversion_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Data_Type_Conversion_COMMON_INCLUDES_ */

#include "Data_Type_Conversion_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Data_Type_Conversion_T {
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
extern real_T Data_Type_Conversion_In1_1;/* '<Root>/In1' */
extern int32_T Data_Type_Conversion_DataTypeConversion_1;/* '<Root>/DataTypeConversion' */

/* Model entry point functions */
extern void Data_Type_Conversion_initialize(void);
extern void Data_Type_Conversion_step(void);
extern void Data_Type_Conversion_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Data_Type_Conversion_T *const Data_Type_Conversion_M;

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
 * '<Root>' : 'Data_Type_Conversion'
 */
#endif                                 /* RTW_HEADER_Data_Type_Conversion_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */