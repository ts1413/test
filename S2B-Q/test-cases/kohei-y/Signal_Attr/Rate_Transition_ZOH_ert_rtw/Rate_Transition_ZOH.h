/*
 * File: Rate_Transition_ZOH.h
 *
 * Code generated for Simulink model 'Rate_Transition_ZOH'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:41:18 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rate_Transition_ZOH_h_
#define RTW_HEADER_Rate_Transition_ZOH_h_
#include <string.h>
#ifndef Rate_Transition_ZOH_COMMON_INCLUDES_
# define Rate_Transition_ZOH_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Rate_Transition_ZOH_COMMON_INCLUDES_ */

#include "Rate_Transition_ZOH_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_Rate_Transition_ZOH_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
};

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Rate_Transition_ZOH_In1_1;/* '<Root>/In1' */
extern real_T Rate_Transition_ZOH_RateTransition_1;/* '<Root>/RateTransition' */

/* Model entry point functions */
extern void Rate_Transition_ZOH_initialize(void);
extern void Rate_Transition_ZOH_step0(void);
extern void Rate_Transition_ZOH_step1(void);
extern void Rate_Transition_ZOH_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rate_Transition_ZOH_T *const Rate_Transition_ZOH_M;

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
 * '<Root>' : 'Rate_Transition_ZOH'
 */
#endif                                 /* RTW_HEADER_Rate_Transition_ZOH_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
