/*
 * File: Transfer_Fcn_First_Order.h
 *
 * Code generated for Simulink model 'Transfer_Fcn_First_Order'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 13:39:11 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Transfer_Fcn_First_Order_h_
#define RTW_HEADER_Transfer_Fcn_First_Order_h_
#include <stddef.h>
#ifndef Transfer_Fcn_First_Order_COMMON_INCLUDES_
# define Transfer_Fcn_First_Order_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Transfer_Fcn_First_Order_COMMON_INCLUDES_ */

#include "Transfer_Fcn_First_Order_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Yk1;                          /* '<S1>/UD' */
  real_T Yk1Uk;                        /* '<S1>/Diff' */
  real_T PoleYk1Uk;                    /* '<S1>/Gain' */
} BlockIO_Transfer_Fcn_First_Orde;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
} D_Work_Transfer_Fcn_First_Order;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExternalOutputs_Transfer_Fcn_Fi;

/* Real-time Model Data Structure */
struct tag_RTM_Transfer_Fcn_First_Orde {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_Transfer_Fcn_First_Orde Transfer_Fcn_First_Order_B;

/* Block states (auto storage) */
extern D_Work_Transfer_Fcn_First_Order Transfer_Fcn_First_Order_DWork;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Transfer_Fcn_Fi Transfer_Fcn_First_Order_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Transfer_Fcn_First_Order_In1_1;/* '<Root>/In1' */

/* Model entry point functions */
extern void Transfer_Fcn_First_Order_initialize(void);
extern void Transfer_Fcn_First_Order_step(void);
extern void Transfer_Fcn_First_Order_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Transfer_Fcn_First_Ord *const Transfer_Fcn_First_Order_M;

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
 * '<Root>' : 'Transfer_Fcn_First_Order'
 * '<S1>'   : 'Transfer_Fcn_First_Order/TransferFcnFirstOrder'
 */
#endif                                 /* RTW_HEADER_Transfer_Fcn_First_Order_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
