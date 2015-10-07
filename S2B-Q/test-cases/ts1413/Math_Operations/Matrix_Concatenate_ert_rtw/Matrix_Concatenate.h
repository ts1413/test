/*
 * File: Matrix_Concatenate.h
 *
 * Code generated for Simulink model 'Matrix_Concatenate'.
 *
 * Model version                  : 1.79
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:40:11 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Matrix_Concatenate_h_
#define RTW_HEADER_Matrix_Concatenate_h_
#include <stddef.h>
#ifndef Matrix_Concatenate_COMMON_INCLUDES_
# define Matrix_Concatenate_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Matrix_Concatenate_COMMON_INCLUDES_ */

#include "Matrix_Concatenate_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Matrix_Concatenate {
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
extern real_T Matrix_Concatenate_In1_1[2];/* '<Root>/In1' */
extern real_T Matrix_Concatenate_In2_1[2];/* '<Root>/In2' */
extern real_T Matrix_Concatenate_MatrixConcatenate_1[4];/* '<Root>/MatrixConcatenate' */

/* Model entry point functions */
extern void Matrix_Concatenate_initialize(void);
extern void Matrix_Concatenate_step(void);
extern void Matrix_Concatenate_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Matrix_Concatenate *const Matrix_Concatenate_M;

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
 * '<Root>' : 'Matrix_Concatenate'
 */
#endif                                 /* RTW_HEADER_Matrix_Concatenate_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
