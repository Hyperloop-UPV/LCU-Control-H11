/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rtmodel.h
 *
 * Code generated for Simulink model 'C_5DOF_EL'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Apr 16 16:40:05 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef rtmodel_h_
#define rtmodel_h_
#include "C_5DOF_EL.h"

/* Macros generated for backwards compatibility  */
#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((void*) 0)
#endif

/* Model wrapper function */
/* Use this function only if you need to maintain compatibility with an existing static main program. */
extern void C_5DOF_EL_step(int_T tid);

#endif                                 /* rtmodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
