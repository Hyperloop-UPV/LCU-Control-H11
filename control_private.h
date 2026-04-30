/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_private.h
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Apr 30 22:43:24 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef control_private_h_
#define control_private_h_
#include "rtwtypes.h"
#include "control.h"
#include "control_types.h"

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern void control_Simulink2(real32_T rtu_ref_out, real32_T rtu_y_out, real32_T
  *rty_u_out, real32_T rty_Out1[3], DW_Simulink2_control_T *localDW);

#endif                                 /* control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
