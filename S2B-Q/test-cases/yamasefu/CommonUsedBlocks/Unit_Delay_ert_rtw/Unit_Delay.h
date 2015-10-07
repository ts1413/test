/*
 * File: Unit_Delay.h
 *
 * Code generated for Simulink model 'Unit_Delay'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Oct  5 16:09:49 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Unit_Delay_h_
#define RTW_HEADER_Unit_Delay_h_
#include <stddef.h>
#include <string.h>
#ifndef Unit_Delay_COMMON_INCLUDES_
# define Unit_Delay_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Unit_Delay_COMMON_INCLUDES_ */

#include "Unit_Delay_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/UnitDelay' */
} DW_Unit_Delay_T;

/* Parameters (auto storage) */
struct P_Unit_Delay_T_ {
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/UnitDelay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Unit_Delay_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Unit_Delay_T Unit_Delay_P;

/* Block states (auto storage) */
extern DW_Unit_Delay_T Unit_Delay_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Unit_Delay_In1_1;        /* '<Root>/In1' */
extern real_T Unit_Delay_UnitDelay_1;  /* '<Root>/UnitDelay' */

/* Model entry point functions */
extern void Unit_Delay_initialize(void);
extern void Unit_Delay_step(void);
extern void Unit_Delay_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Unit_Delay_T *const Unit_Delay_M;

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
 * '<Root>' : 'Unit_Delay'
 */
#endif                                 /* RTW_HEADER_Unit_Delay_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
