/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADRCPOLE_private.h
 *
 * Code generated for Simulink model 'ADRCPOLE'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Mar  8 00:33:23 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ADRCPOLE_private_h_
#define ADRCPOLE_private_h_
#include "rtwtypes.h"
#include "ADRCPOLE.h"
#include "ADRCPOLE_types.h"

extern void ADRCPOLE_Simulink1_Init(DW_Simulink1_ADRCPOLE_T *localDW);
extern void ADRCPOLE_Simulink1(real_T rtu_ref_out, real_T rtu_y_out, real_T
  *rty_u_out, real_T rty_Out1[3], DW_Simulink1_ADRCPOLE_T *localDW);
extern void ADRCPOLE_Simulink1_k_Init(DW_Simulink1_ADRCPOLE_i_T *localDW);
extern void ADRCPOLE_Simulink1_m(real_T rtu_ref_out, real_T rtu_y_out, real_T
  *rty_u_out, real_T rty_Out1[3], DW_Simulink1_ADRCPOLE_i_T *localDW);

#endif                                 /* ADRCPOLE_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
