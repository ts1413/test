/*
 * File: Data_Type_Conversion.c
 *
 * Code generated for Simulink model 'Data_Type_Conversion'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Sep 29 10:40:54 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Data_Type_Conversion.h"
#include "Data_Type_Conversion_private.h"

/* Exported block signals */
real_T Data_Type_Conversion_In1_1;     /* '<Root>/In1' */
int32_T Data_Type_Conversion_DataTypeConversion_1;/* '<Root>/DataTypeConversion' */

/* Real-time model */
RT_MODEL_Data_Type_Conversion_T Data_Type_Conversion_M_;
RT_MODEL_Data_Type_Conversion_T *const Data_Type_Conversion_M =
  &Data_Type_Conversion_M_;

/* Model step function */
void Data_Type_Conversion_step(void)
{
  real_T tmp;

  /* DataTypeConversion: '<Root>/DataTypeConversion' incorporates:
   *  Inport: '<Root>/In1'
   */
  tmp = floor(Data_Type_Conversion_In1_1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  Data_Type_Conversion_DataTypeConversion_1 = tmp < 0.0 ? -(int32_T)(uint32_T)
    -tmp : (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/DataTypeConversion' */
}

/* Model initialize function */
void Data_Type_Conversion_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Data_Type_Conversion_M, (NULL));

  /* block I/O */

  /* exported global signals */
  Data_Type_Conversion_DataTypeConversion_1 = 0;

  /* external inputs */
  Data_Type_Conversion_In1_1 = 0.0;
}

/* Model terminate function */
void Data_Type_Conversion_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
