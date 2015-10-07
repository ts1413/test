/*
 * File: Discrete_Derivative.h
 *
 * Code generated for Simulink model 'Discrete_Derivative'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:53 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Discrete_Derivative_h_
#define RTW_HEADER_Discrete_Derivative_h_
#include <stddef.h>
#ifndef Discrete_Derivative_COMMON_INCLUDES_
# define Discrete_Derivative_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Discrete_Derivative_COMMON_INCLUDES_ */

#include "Discrete_Derivative_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T TSamp;                        /* '<S1>/TSamp' */
  real_T Uk1;                          /* '<S1>/UD' */
} BlockIO_Discrete_Derivative;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
} D_Work_Discrete_Derivative;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExternalOutputs_Discrete_Deriva;

/* Real-time Model Data Structure */
struct tag_RTM_Discrete_Derivative {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_Discrete_Derivative Discrete_Derivative_B;

/* Block states (auto storage) */
extern D_Work_Discrete_Derivative Discrete_Derivative_DWork;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Discrete_Deriva Discrete_Derivative_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Discrete_Derivative_In1_1;/* '<Root>/In1' */

/* Model entry point functions */
extern void Discrete_Derivative_initialize(void);
extern void Discrete_Derivative_step(void);
extern void Discrete_Derivative_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Discrete_Derivative *const Discrete_Derivative_M;

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
 * '<Root>' : 'Discrete_Derivative'
 * '<S1>'   : 'Discrete_Derivative/DiscreteDerivative'
 */
#endif                                 /* RTW_HEADER_Discrete_Derivative_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
