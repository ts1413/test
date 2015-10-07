/*
 * File: Sum_of_elements.h
 *
 * Code generated for Simulink model 'Sum_of_elements'.
 *
 * Model version                  : 1.91
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:08:32 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Sum_of_elements_h_
#define RTW_HEADER_Sum_of_elements_h_
#include <stddef.h>
#ifndef Sum_of_elements_COMMON_INCLUDES_
# define Sum_of_elements_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Sum_of_elements_COMMON_INCLUDES_ */

#include "Sum_of_elements_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Sum_of_elements {
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
extern real_T Sum_of_elements_In1_1;   /* '<Root>/In1' */
extern real_T Sum_of_elements_SumofElements_1;/* '<Root>/SumofElements' */

/* Model entry point functions */
extern void Sum_of_elements_initialize(void);
extern void Sum_of_elements_step(void);
extern void Sum_of_elements_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Sum_of_elements *const Sum_of_elements_M;

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
 * '<Root>' : 'Sum_of_elements'
 */
#endif                                 /* RTW_HEADER_Sum_of_elements_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
