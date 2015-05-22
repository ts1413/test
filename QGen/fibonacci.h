/* Copyright (C) Your Company Name */
/*
 * @generated with QGen Code Generator 1.0.1 (20150118)
 * Command line arguments: Fibonacci.slx -s epsgd -t Fibonacci_types.txt -l c -c
*/

#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "ga_types.h"
#include "ga_math.h"

extern void Fibonacci_init (void);
extern void Fibonacci_comp
  (GAREAL Out1,
   GAREAL approximate_golden_ratio,
   GAREAL error);

#endif
/*  @EOF  */
