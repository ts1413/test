/*
 * File: model.h
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:42:07 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_model_h_
#define RTW_HEADER_model_h_
#include <stddef.h>
#include <string.h>
#ifndef model_COMMON_INCLUDES_
# define model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* model_COMMON_INCLUDES_ */

#include "model_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Child system includes */
#include "inport_outport.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  MdlrefDW_inport_outport_T Model_DWORK1;/* '<Root>/Model' */
} DW_model_T;

/* Real-time Model Data Structure */
struct tag_RTM_model_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_model_T model_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T model_In1_1;             /* '<Root>/In1' */
extern real_T model_Model_1;           /* '<Root>/Model' */

/* Model entry point functions */
extern void model_initialize(void);
extern void model_step(void);
extern void model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_model_T *const model_M;

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
 * '<Root>' : 'model'
 */
#endif                                 /* RTW_HEADER_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
