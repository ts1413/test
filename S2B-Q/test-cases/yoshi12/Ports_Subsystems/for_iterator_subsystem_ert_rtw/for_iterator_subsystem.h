/*
 * File: for_iterator_subsystem.h
 *
 * Code generated for Simulink model 'for_iterator_subsystem'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sat Oct  3 23:52:48 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_for_iterator_subsystem_h_
#define RTW_HEADER_for_iterator_subsystem_h_
#include <stddef.h>
#ifndef for_iterator_subsystem_COMMON_INCLUDES_
# define for_iterator_subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* for_iterator_subsystem_COMMON_INCLUDES_ */

#include "for_iterator_subsystem_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_for_iterator_subsystem_T_ {
  int16_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
  int8_T ForIterator_IterationLimit;   /* Computed Parameter: ForIterator_IterationLimit
                                        * Referenced by: '<S1>/ForIterator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_for_iterator_subsyste_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_for_iterator_subsystem_T for_iterator_subsystem_P;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern int8_T for_iterator_subsystem_In1_1;/* '<Root>/In1' */
extern int16_T for_iterator_subsystem_ForIteratorSubsystem_Product_1;/* '<S1>/Product' */
extern int8_T for_iterator_subsystem_ForIteratorSubsystem_ForIterator_1;/* '<S1>/ForIterator' */

/* Model entry point functions */
extern void for_iterator_subsystem_initialize(void);
extern void for_iterator_subsystem_step(void);
extern void for_iterator_subsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_for_iterator_subsyst_T *const for_iterator_subsystem_M;

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
 * '<Root>' : 'for_iterator_subsystem'
 * '<S1>'   : 'for_iterator_subsystem/ForIteratorSubsystem'
 */
#endif                                 /* RTW_HEADER_for_iterator_subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
