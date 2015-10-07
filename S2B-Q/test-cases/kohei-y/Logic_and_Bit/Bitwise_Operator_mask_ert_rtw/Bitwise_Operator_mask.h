/*
 * File: Bitwise_Operator_mask.h
 *
 * Code generated for Simulink model 'Bitwise_Operator_mask'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:46:35 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Bitwise_Operator_mask_h_
#define RTW_HEADER_Bitwise_Operator_mask_h_
#include <stddef.h>
#ifndef Bitwise_Operator_mask_COMMON_INCLUDES_
# define Bitwise_Operator_mask_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Bitwise_Operator_mask_COMMON_INCLUDES_ */

#include "Bitwise_Operator_mask_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_Bitwise_Operator_mask_T_ {
  int8_T BitwiseOperator_BitMask;      /* Mask Parameter: BitwiseOperator_BitMask
                                        * Referenced by: '<Root>/BitwiseOperator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Bitwise_Operator_mask_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Bitwise_Operator_mask_T Bitwise_Operator_mask_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern int8_T Bitwise_Operator_mask_In1_1;/* '<Root>/In1' */
extern int8_T Bitwise_Operator_mask_BitwiseOperator_1;/* '<Root>/BitwiseOperator' */

/* Model entry point functions */
extern void Bitwise_Operator_mask_initialize(void);
extern void Bitwise_Operator_mask_step(void);
extern void Bitwise_Operator_mask_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Bitwise_Operator_mas_T *const Bitwise_Operator_mask_M;

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
 * '<Root>' : 'Bitwise_Operator_mask'
 */
#endif                                 /* RTW_HEADER_Bitwise_Operator_mask_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
