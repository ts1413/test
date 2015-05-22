/* Copyright (C) Your Company Name */
/*
 * @generated with QGen Code Generator 1.0.1 (20150118)
 * Command line arguments: Fibonacci.slx -s epsgd -t Fibonacci_types.txt -l c -c
*/

#include "fibonacci.h"

static GAREAL Fn_1_memory;
static GAREAL Fn_memory;
static void Fibonacci_initStates (void);
void Fibonacci_init (void) {
   (void) Fibonacci_initStates ();
}
void Fibonacci_initStates (void) {
   /* Block Fibonacci/Fn_1 */
   Fn_1_memory = 0.0;
   /* End Block Fibonacci/Fn_1 */

   /* Block Fibonacci/Fn */
   Fn_memory = 1.0;
   /* End Block Fibonacci/Fn */

}
void Fibonacci_comp
  (GAREAL Out1,
   GAREAL approximate_golden_ratio,
   GAREAL error)
{
   GAREAL Fn_1_out1;
   GAREAL Fn_out1;
   GAREAL Golden_ratio_out1;
   GAREAL Saturation_out1;
   GAREAL Divide_out1;
   GAREAL Subtract_out1;
   GAREAL Abs_out1;
   GAREAL Gain_out1;
   GAREAL Add_out1;

   /* Block Fibonacci/Fn_1 */
   Fn_1_out1 = Fn_1_memory;
   /* End Block Fibonacci/Fn_1 */

   /* Block Fibonacci/Fn */
   Fn_out1 = Fn_memory;
   /* End Block Fibonacci/Fn */

   /* Block Fibonacci/Golden_ratio */
   Golden_ratio_out1 = (1.0 + (ga_sqrt_gareal (5.0))) / 2.0;
   /* End Block Fibonacci/Golden_ratio */

   /* Block Fibonacci/Saturation */
   if (Fn_1_out1 < 1.0) {
      Saturation_out1 = 1.0;
   }
   else {
      if (Fn_1_out1 > 1000000.0) {
         Saturation_out1 = 1000000.0;
      }
      else {
         Saturation_out1 = Fn_1_out1;
      }
   }
   /* End Block Fibonacci/Saturation */

   /* Block Fibonacci/Out1 */
   Out1 = Fn_out1;
   /* End Block Fibonacci/Out1 */

   /* Block Fibonacci/Divide */
   Divide_out1 = Fn_out1 / Saturation_out1;
   /* End Block Fibonacci/Divide */

   /* Block Fibonacci/approximate_golden_ratio */
   approximate_golden_ratio = Divide_out1;
   /* End Block Fibonacci/approximate_golden_ratio */

   /* Block Fibonacci/Subtract */
   Subtract_out1 = Divide_out1 - Golden_ratio_out1;
   /* End Block Fibonacci/Subtract */

   /* Block Fibonacci/Abs */
   Abs_out1 = ga_abs_gareal (Subtract_out1);
   /* End Block Fibonacci/Abs */

   /* Block Fibonacci/Gain */
   Gain_out1 = (2.0 / (1.0 + (ga_sqrt_gareal (5.0)))) * Abs_out1;
   /* End Block Fibonacci/Gain */

   /* Block Fibonacci/error */
   error = Gain_out1;
   /* End Block Fibonacci/error */

   /* Block Fibonacci/Add */
   Add_out1 = Fn_out1 + Fn_1_out1;
   /* End Block Fibonacci/Add */

   /* update Fibonacci/Fn_1 */
   Fn_1_memory = Fn_out1;
   /* End update Fibonacci/Fn_1 */

   /* update Fibonacci/Fn */
   Fn_memory = Add_out1;
   /* End update Fibonacci/Fn */

}
/*  @EOF  */
