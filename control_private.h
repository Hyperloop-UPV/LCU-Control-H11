/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_private.h
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.108
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr  7 22:36:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef control_private_h_
#define control_private_h_
#include "rtwtypes.h"
#include "control_types.h"
#include "control.h"

extern real32_T look2_iflf_binlcpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride);

#endif                                 /* control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
