/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlDeCorriente.h
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

#ifndef ControlDeCorriente_h_
#define ControlDeCorriente_h_
#ifndef C_5DOF_EL_COMMON_INCLUDES_
#define C_5DOF_EL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* C_5DOF_EL_COMMON_INCLUDES_ */

/* Block signals for system '<S2>/ControlDeCorriente' */
typedef struct {
  real_T IntegralGain;                 /* '<S322>/Integral Gain' */
  real_T DeadZone;                     /* '<S317>/DeadZone' */
  real_T Integrator;
  real_T Integrator_d;
  real_T Integrator_k;
  real_T Integrator_p;
  real_T Integrator_pa;
  real_T Integrator_m;
  real_T Integrator_a;
  real_T Integrator_f;
  real_T Integrator_e;
  real_T Integrator_tmp;
  real_T Integrator_d_tmp;
} B_ControlDeCorriente_C_5DOF_E_T;

/* Block states (default storage) for system '<S2>/ControlDeCorriente' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S379>/Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S433>/Integrator' */
  real_T Integrator_DSTATE_c;          /* '<S487>/Integrator' */
  real_T Integrator_DSTATE_om;         /* '<S541>/Integrator' */
  real_T Integrator_DSTATE_b;          /* '<S55>/Integrator' */
  real_T Integrator_DSTATE_bd;         /* '<S109>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S163>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S217>/Integrator' */
  real_T Integrator_DSTATE_gi;         /* '<S271>/Integrator' */
  real_T Integrator_DSTATE_px;         /* '<S325>/Integrator' */
} DW_ControlDeCorriente_C_5DOF__T;

extern void C_5_ControlDeCorriente_Init(DW_ControlDeCorriente_C_5DOF__T *localDW);
extern void C_5DOF_E_ControlDeCorriente(const real_T rtu_CorrienteRefHEMS[4],
  const real_T rtu_I_real_hems[4], const real_T rtu_I_real_ems[6], const real_T
  rtu_CorrienteRefEMS[6], real_T *rty_V_HEMS, real_T *rty_V_HEMS_l, real_T
  *rty_V_HEMS_j, real_T *rty_V_HEMS_d, real_T *rty_V_EMS, real_T *rty_V_EMS_p,
  real_T *rty_V_EMS_d, real_T *rty_V_EMS_f, real_T *rty_V_EMS_g, real_T
  *rty_V_EMS_dd, B_ControlDeCorriente_C_5DOF_E_T *localB,
  DW_ControlDeCorriente_C_5DOF__T *localDW);

#endif                                 /* ControlDeCorriente_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
