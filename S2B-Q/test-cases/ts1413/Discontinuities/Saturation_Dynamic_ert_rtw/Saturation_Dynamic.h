/*
 * File: Saturation_Dynamic.h
 *
 * Code generated for Simulink model 'Saturation_Dynamic'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:38:34 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Saturation_Dynamic_h_
#define RTW_HEADER_Saturation_Dynamic_h_
#include <stddef.h>
#include <string.h>
#ifndef Saturation_Dynamic_COMMON_INCLUDES_
# define Saturation_Dynamic_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Saturation_Dynamic_COMMON_INCLUDES_ */

#include "Saturation_Dynamic_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Switch;                       /* '<S1>/Switch' */
  boolean_T LowerRelop1;               /* '<S1>/LowerRelop1' */
  boolean_T UpperRelop;                /* '<S1>/UpperRelop' */
} BlockIO_Saturation_Dynamic;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExternalOutputs_Saturation_Dyna;

/* Real-time Model Data Structure */
struct tag_RTM_Saturation_Dynamic {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_Saturation_Dynamic Saturation_Dynamic_B;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Saturation_Dyna Saturation_Dynamic_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Saturation_Dynamic_In1_1;/* '<Root>/In1' */
extern real_T Saturation_Dynamic_In2_1;/* '<Root>/In2' */
extern real_T Saturation_Dynamic_In3_1;/* '<Root>/In3' */

/* Model entry point functions */
extern void Saturation_Dynamic_initialize(void);
extern void Saturation_Dynamic_step(void);
extern void Saturation_Dynamic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Saturation_Dynamic *const Saturation_Dynamic_M;

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
 * '<Root>' : 'Saturation_Dynamic'
 * '<S1>'   : 'Saturation_Dynamic/SaturationDynamic'
 */
#endif                                 /* RTW_HEADER_Saturation_Dynamic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
