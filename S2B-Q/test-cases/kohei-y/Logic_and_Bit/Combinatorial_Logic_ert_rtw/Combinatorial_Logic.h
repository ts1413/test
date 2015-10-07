/*
 * File: Combinatorial_Logic.h
 *
 * Code generated for Simulink model 'Combinatorial_Logic'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:40:13 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Combinatorial_Logic_h_
#define RTW_HEADER_Combinatorial_Logic_h_
#include <stddef.h>
#include <string.h>
#ifndef Combinatorial_Logic_COMMON_INCLUDES_
# define Combinatorial_Logic_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Combinatorial_Logic_COMMON_INCLUDES_ */

#include "Combinatorial_Logic_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_Combinatorial_Logic_T_ {
  boolean_T CombinatorialLogic_table[16];/* Computed Parameter: CombinatorialLogic_table
                                          * Referenced by: '<Root>/CombinatorialLogic'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_Combinatorial_Logic_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Combinatorial_Logic_T Combinatorial_Logic_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T Combinatorial_Logic_In1_1[3];/* '<Root>/In1' */
extern boolean_T Combinatorial_Logic_CombinatorialLogic_1[2];/* '<Root>/CombinatorialLogic' */

/* Model entry point functions */
extern void Combinatorial_Logic_initialize(void);
extern void Combinatorial_Logic_step(void);
extern void Combinatorial_Logic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Combinatorial_Logic_T *const Combinatorial_Logic_M;

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
 * '<Root>' : 'Combinatorial_Logic'
 */
#endif                                 /* RTW_HEADER_Combinatorial_Logic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
