/*
 * File: while_iterator_subsystem.h
 *
 * Code generated for Simulink model 'while_iterator_subsystem'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:42:26 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_while_iterator_subsystem_h_
#define RTW_HEADER_while_iterator_subsystem_h_
#include <stddef.h>
#ifndef while_iterator_subsystem_COMMON_INCLUDES_
# define while_iterator_subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* while_iterator_subsystem_COMMON_INCLUDES_ */

#include "while_iterator_subsystem_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T Out1;                      /* '<Root>/Out1' */
} ExtY_while_iterator_subsystem_T;

/* Parameters (auto storage) */
struct P_while_iterator_subsystem_T_ {
  boolean_T Out1_Y0;                   /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_while_iterator_subsys_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_while_iterator_subsystem_T while_iterator_subsystem_P;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_while_iterator_subsystem_T while_iterator_subsystem_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T while_iterator_subsystem_In1_1;/* '<Root>/In1' */
extern boolean_T while_iterator_subsystem_In2_1;/* '<Root>/In2' */

/* Model entry point functions */
extern void while_iterator_subsystem_initialize(void);
extern void while_iterator_subsystem_step(void);
extern void while_iterator_subsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_while_iterator_subsy_T *const while_iterator_subsystem_M;

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
 * '<Root>' : 'while_iterator_subsystem'
 * '<S1>'   : 'while_iterator_subsystem/WhileIteratorSubsystem'
 */
#endif                                 /* RTW_HEADER_while_iterator_subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
