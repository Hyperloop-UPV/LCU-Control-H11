/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlDeCorriente.c
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

#include "ControlDeCorriente.h"
#include "rtwtypes.h"

/* System initialize for atomic system: '<S2>/ControlDeCorriente' */
void C_5_ControlDeCorriente_Init(DW_ControlDeCorriente_C_5DOF__T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S379>/Integrator' */
  localDW->Integrator_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S433>/Integrator' */
  localDW->Integrator_DSTATE_o = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S487>/Integrator' */
  localDW->Integrator_DSTATE_c = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S541>/Integrator' */
  localDW->Integrator_DSTATE_om = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S55>/Integrator' */
  localDW->Integrator_DSTATE_b = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' */
  localDW->Integrator_DSTATE_bd = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S163>/Integrator' */
  localDW->Integrator_DSTATE_p = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator' */
  localDW->Integrator_DSTATE_g = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S271>/Integrator' */
  localDW->Integrator_DSTATE_gi = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S325>/Integrator' */
  localDW->Integrator_DSTATE_px = 0.0;
}

/* Output and update for atomic system: '<S2>/ControlDeCorriente' */
void C_5DOF_E_ControlDeCorriente(const real_T rtu_CorrienteRefHEMS[4], const
  real_T rtu_I_real_hems[4], const real_T rtu_I_real_ems[6], const real_T
  rtu_CorrienteRefEMS[6], real_T *rty_V_HEMS, real_T *rty_V_HEMS_l, real_T
  *rty_V_HEMS_j, real_T *rty_V_HEMS_d, real_T *rty_V_EMS, real_T *rty_V_EMS_p,
  real_T *rty_V_EMS_d, real_T *rty_V_EMS_f, real_T *rty_V_EMS_g, real_T
  *rty_V_EMS_dd, B_ControlDeCorriente_C_5DOF_E_T *localB,
  DW_ControlDeCorriente_C_5DOF__T *localDW)
{
  real_T Integrator_a_tmp;
  real_T Integrator_e_tmp;
  real_T Integrator_f_tmp;
  real_T Integrator_k_tmp;
  real_T Integrator_m_tmp;
  real_T Integrator_p_tmp;
  real_T Integrator_pa_tmp;
  int8_T tmp;
  int8_T tmp_0;

  /* Sum: '<S4>/Sum6' */
  *rty_V_HEMS_l = rtu_CorrienteRefHEMS[0] - rtu_I_real_hems[0];

  /* Gain: '<S384>/Proportional Gain' */
  *rty_V_HEMS = 22.9546 * *rty_V_HEMS_l;

  /* Sum: '<S389>/Sum Fdbk' */
  *rty_V_HEMS_j = *rty_V_HEMS + localDW->Integrator_DSTATE;

  /* DeadZone: '<S371>/DeadZone' */
  if (*rty_V_HEMS_j > 400.0) {
    *rty_V_HEMS_j -= 400.0;
  } else if (*rty_V_HEMS_j >= -400.0) {
    *rty_V_HEMS_j = 0.0;
  } else {
    *rty_V_HEMS_j -= -400.0;
  }

  /* End of DeadZone: '<S371>/DeadZone' */

  /* Gain: '<S376>/Integral Gain' */
  *rty_V_HEMS_l *= 208.3333;

  /* Switch: '<S369>/Switch1' incorporates:
   *  Constant: '<S369>/Clamping_zero'
   *  Constant: '<S369>/Constant'
   *  Constant: '<S369>/Constant2'
   *  RelationalOperator: '<S369>/fix for DT propagation issue'
   */
  if (*rty_V_HEMS_j > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S369>/Switch2' incorporates:
   *  Constant: '<S369>/Clamping_zero'
   *  Constant: '<S369>/Constant3'
   *  Constant: '<S369>/Constant4'
   *  RelationalOperator: '<S369>/fix for DT propagation issue1'
   */
  if (*rty_V_HEMS_l > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S369>/Switch' incorporates:
   *  Constant: '<S369>/Clamping_zero'
   *  Constant: '<S369>/Constant1'
   *  Logic: '<S369>/AND3'
   *  RelationalOperator: '<S369>/Equal1'
   *  RelationalOperator: '<S369>/Relational Operator'
   *  Switch: '<S369>/Switch1'
   *  Switch: '<S369>/Switch2'
   */
  if ((*rty_V_HEMS_j != 0.0) && (tmp == tmp_0)) {
    *rty_V_HEMS_l = 0.0;
  }

  /* End of Switch: '<S369>/Switch' */

  /* DiscreteIntegrator: '<S379>/Integrator' */
  localB->Integrator_tmp = 0.00025 * *rty_V_HEMS_l;

  /* DiscreteIntegrator: '<S379>/Integrator' */
  localB->Integrator = localB->Integrator_tmp + localDW->Integrator_DSTATE;

  /* DiscreteIntegrator: '<S379>/Integrator' */
  if (localB->Integrator > 400.0) {
    /* DiscreteIntegrator: '<S379>/Integrator' */
    localB->Integrator = 400.0;
  } else if (localB->Integrator < -400.0) {
    /* DiscreteIntegrator: '<S379>/Integrator' */
    localB->Integrator = -400.0;
  }

  /* Sum: '<S388>/Sum' */
  *rty_V_HEMS += localB->Integrator;

  /* Saturate: '<S386>/Saturation' */
  if (*rty_V_HEMS > 400.0) {
    *rty_V_HEMS = 400.0;
  } else if (*rty_V_HEMS < -400.0) {
    *rty_V_HEMS = -400.0;
  }

  /* End of Saturate: '<S386>/Saturation' */

  /* Sum: '<S4>/Sum7' */
  *rty_V_HEMS_j = rtu_CorrienteRefHEMS[1] - rtu_I_real_hems[1];

  /* Gain: '<S438>/Proportional Gain' */
  *rty_V_HEMS_l = 22.9546 * *rty_V_HEMS_j;

  /* Sum: '<S443>/Sum Fdbk' */
  *rty_V_HEMS_d = *rty_V_HEMS_l + localDW->Integrator_DSTATE_o;

  /* DeadZone: '<S425>/DeadZone' */
  if (*rty_V_HEMS_d > 400.0) {
    *rty_V_HEMS_d -= 400.0;
  } else if (*rty_V_HEMS_d >= -400.0) {
    *rty_V_HEMS_d = 0.0;
  } else {
    *rty_V_HEMS_d -= -400.0;
  }

  /* End of DeadZone: '<S425>/DeadZone' */

  /* Gain: '<S430>/Integral Gain' */
  *rty_V_HEMS_j *= 208.3333;

  /* Switch: '<S423>/Switch1' incorporates:
   *  Constant: '<S423>/Clamping_zero'
   *  Constant: '<S423>/Constant'
   *  Constant: '<S423>/Constant2'
   *  RelationalOperator: '<S423>/fix for DT propagation issue'
   */
  if (*rty_V_HEMS_d > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S423>/Switch2' incorporates:
   *  Constant: '<S423>/Clamping_zero'
   *  Constant: '<S423>/Constant3'
   *  Constant: '<S423>/Constant4'
   *  RelationalOperator: '<S423>/fix for DT propagation issue1'
   */
  if (*rty_V_HEMS_j > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S423>/Switch' incorporates:
   *  Constant: '<S423>/Clamping_zero'
   *  Constant: '<S423>/Constant1'
   *  Logic: '<S423>/AND3'
   *  RelationalOperator: '<S423>/Equal1'
   *  RelationalOperator: '<S423>/Relational Operator'
   *  Switch: '<S423>/Switch1'
   *  Switch: '<S423>/Switch2'
   */
  if ((*rty_V_HEMS_d != 0.0) && (tmp == tmp_0)) {
    *rty_V_HEMS_j = 0.0;
  }

  /* End of Switch: '<S423>/Switch' */

  /* DiscreteIntegrator: '<S433>/Integrator' */
  localB->Integrator_d_tmp = 0.00025 * *rty_V_HEMS_j;

  /* DiscreteIntegrator: '<S433>/Integrator' */
  localB->Integrator_d = localB->Integrator_d_tmp + localDW->Integrator_DSTATE_o;

  /* DiscreteIntegrator: '<S433>/Integrator' */
  if (localB->Integrator_d > 400.0) {
    /* DiscreteIntegrator: '<S433>/Integrator' */
    localB->Integrator_d = 400.0;
  } else if (localB->Integrator_d < -400.0) {
    /* DiscreteIntegrator: '<S433>/Integrator' */
    localB->Integrator_d = -400.0;
  }

  /* Sum: '<S442>/Sum' */
  *rty_V_HEMS_l += localB->Integrator_d;

  /* Saturate: '<S440>/Saturation' */
  if (*rty_V_HEMS_l > 400.0) {
    *rty_V_HEMS_l = 400.0;
  } else if (*rty_V_HEMS_l < -400.0) {
    *rty_V_HEMS_l = -400.0;
  }

  /* End of Saturate: '<S440>/Saturation' */

  /* Sum: '<S4>/Sum8' */
  *rty_V_HEMS_d = rtu_CorrienteRefHEMS[2] - rtu_I_real_hems[2];

  /* Gain: '<S492>/Proportional Gain' */
  *rty_V_HEMS_j = 22.9546 * *rty_V_HEMS_d;

  /* Sum: '<S497>/Sum Fdbk' */
  *rty_V_EMS = *rty_V_HEMS_j + localDW->Integrator_DSTATE_c;

  /* DeadZone: '<S479>/DeadZone' */
  if (*rty_V_EMS > 400.0) {
    *rty_V_EMS -= 400.0;
  } else if (*rty_V_EMS >= -400.0) {
    *rty_V_EMS = 0.0;
  } else {
    *rty_V_EMS -= -400.0;
  }

  /* End of DeadZone: '<S479>/DeadZone' */

  /* Gain: '<S484>/Integral Gain' */
  *rty_V_HEMS_d *= 208.3333;

  /* Switch: '<S477>/Switch1' incorporates:
   *  Constant: '<S477>/Clamping_zero'
   *  Constant: '<S477>/Constant'
   *  Constant: '<S477>/Constant2'
   *  RelationalOperator: '<S477>/fix for DT propagation issue'
   */
  if (*rty_V_EMS > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S477>/Switch2' incorporates:
   *  Constant: '<S477>/Clamping_zero'
   *  Constant: '<S477>/Constant3'
   *  Constant: '<S477>/Constant4'
   *  RelationalOperator: '<S477>/fix for DT propagation issue1'
   */
  if (*rty_V_HEMS_d > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S477>/Switch' incorporates:
   *  Constant: '<S477>/Clamping_zero'
   *  Constant: '<S477>/Constant1'
   *  Logic: '<S477>/AND3'
   *  RelationalOperator: '<S477>/Equal1'
   *  RelationalOperator: '<S477>/Relational Operator'
   *  Switch: '<S477>/Switch1'
   *  Switch: '<S477>/Switch2'
   */
  if ((*rty_V_EMS != 0.0) && (tmp == tmp_0)) {
    *rty_V_HEMS_d = 0.0;
  }

  /* End of Switch: '<S477>/Switch' */

  /* DiscreteIntegrator: '<S487>/Integrator' */
  Integrator_k_tmp = 0.00025 * *rty_V_HEMS_d;

  /* DiscreteIntegrator: '<S487>/Integrator' */
  localB->Integrator_k = Integrator_k_tmp + localDW->Integrator_DSTATE_c;

  /* DiscreteIntegrator: '<S487>/Integrator' */
  if (localB->Integrator_k > 400.0) {
    /* DiscreteIntegrator: '<S487>/Integrator' */
    localB->Integrator_k = 400.0;
  } else if (localB->Integrator_k < -400.0) {
    /* DiscreteIntegrator: '<S487>/Integrator' */
    localB->Integrator_k = -400.0;
  }

  /* Sum: '<S496>/Sum' */
  *rty_V_HEMS_j += localB->Integrator_k;

  /* Saturate: '<S494>/Saturation' */
  if (*rty_V_HEMS_j > 400.0) {
    *rty_V_HEMS_j = 400.0;
  } else if (*rty_V_HEMS_j < -400.0) {
    *rty_V_HEMS_j = -400.0;
  }

  /* End of Saturate: '<S494>/Saturation' */

  /* Sum: '<S4>/Sum9' */
  *rty_V_EMS = rtu_CorrienteRefHEMS[3] - rtu_I_real_hems[3];

  /* Gain: '<S546>/Proportional Gain' */
  *rty_V_HEMS_d = 22.9546 * *rty_V_EMS;

  /* Sum: '<S551>/Sum Fdbk' */
  *rty_V_EMS_p = *rty_V_HEMS_d + localDW->Integrator_DSTATE_om;

  /* DeadZone: '<S533>/DeadZone' */
  if (*rty_V_EMS_p > 400.0) {
    *rty_V_EMS_p -= 400.0;
  } else if (*rty_V_EMS_p >= -400.0) {
    *rty_V_EMS_p = 0.0;
  } else {
    *rty_V_EMS_p -= -400.0;
  }

  /* End of DeadZone: '<S533>/DeadZone' */

  /* Gain: '<S538>/Integral Gain' */
  *rty_V_EMS *= 208.3333;

  /* Switch: '<S531>/Switch1' incorporates:
   *  Constant: '<S531>/Clamping_zero'
   *  Constant: '<S531>/Constant'
   *  Constant: '<S531>/Constant2'
   *  RelationalOperator: '<S531>/fix for DT propagation issue'
   */
  if (*rty_V_EMS_p > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S531>/Switch2' incorporates:
   *  Constant: '<S531>/Clamping_zero'
   *  Constant: '<S531>/Constant3'
   *  Constant: '<S531>/Constant4'
   *  RelationalOperator: '<S531>/fix for DT propagation issue1'
   */
  if (*rty_V_EMS > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S531>/Switch' incorporates:
   *  Constant: '<S531>/Clamping_zero'
   *  Constant: '<S531>/Constant1'
   *  Logic: '<S531>/AND3'
   *  RelationalOperator: '<S531>/Equal1'
   *  RelationalOperator: '<S531>/Relational Operator'
   *  Switch: '<S531>/Switch1'
   *  Switch: '<S531>/Switch2'
   */
  if ((*rty_V_EMS_p != 0.0) && (tmp == tmp_0)) {
    *rty_V_EMS = 0.0;
  }

  /* End of Switch: '<S531>/Switch' */

  /* DiscreteIntegrator: '<S541>/Integrator' */
  Integrator_p_tmp = 0.00025 * *rty_V_EMS;

  /* DiscreteIntegrator: '<S541>/Integrator' */
  localB->Integrator_p = Integrator_p_tmp + localDW->Integrator_DSTATE_om;

  /* DiscreteIntegrator: '<S541>/Integrator' */
  if (localB->Integrator_p > 400.0) {
    /* DiscreteIntegrator: '<S541>/Integrator' */
    localB->Integrator_p = 400.0;
  } else if (localB->Integrator_p < -400.0) {
    /* DiscreteIntegrator: '<S541>/Integrator' */
    localB->Integrator_p = -400.0;
  }

  /* Sum: '<S550>/Sum' */
  *rty_V_HEMS_d += localB->Integrator_p;

  /* Saturate: '<S548>/Saturation' */
  if (*rty_V_HEMS_d > 400.0) {
    *rty_V_HEMS_d = 400.0;
  } else if (*rty_V_HEMS_d < -400.0) {
    *rty_V_HEMS_d = -400.0;
  }

  /* End of Saturate: '<S548>/Saturation' */

  /* Sum: '<S4>/Sum' */
  *rty_V_EMS_p = rtu_CorrienteRefEMS[0] - rtu_I_real_ems[0];

  /* Gain: '<S60>/Proportional Gain' */
  *rty_V_EMS = 0.5039 * *rty_V_EMS_p;

  /* Sum: '<S65>/Sum Fdbk' */
  *rty_V_EMS_d = *rty_V_EMS + localDW->Integrator_DSTATE_b;

  /* DeadZone: '<S47>/DeadZone' */
  if (*rty_V_EMS_d > 400.0) {
    *rty_V_EMS_d -= 400.0;
  } else if (*rty_V_EMS_d >= -400.0) {
    *rty_V_EMS_d = 0.0;
  } else {
    *rty_V_EMS_d -= -400.0;
  }

  /* End of DeadZone: '<S47>/DeadZone' */

  /* Gain: '<S52>/Integral Gain' */
  *rty_V_EMS_p *= 416.6667;

  /* Switch: '<S45>/Switch1' incorporates:
   *  Constant: '<S45>/Clamping_zero'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/Constant2'
   *  RelationalOperator: '<S45>/fix for DT propagation issue'
   */
  if (*rty_V_EMS_d > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S45>/Switch2' incorporates:
   *  Constant: '<S45>/Clamping_zero'
   *  Constant: '<S45>/Constant3'
   *  Constant: '<S45>/Constant4'
   *  RelationalOperator: '<S45>/fix for DT propagation issue1'
   */
  if (*rty_V_EMS_p > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Clamping_zero'
   *  Constant: '<S45>/Constant1'
   *  Logic: '<S45>/AND3'
   *  RelationalOperator: '<S45>/Equal1'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  Switch: '<S45>/Switch1'
   *  Switch: '<S45>/Switch2'
   */
  if ((*rty_V_EMS_d != 0.0) && (tmp == tmp_0)) {
    *rty_V_EMS_p = 0.0;
  }

  /* End of Switch: '<S45>/Switch' */

  /* DiscreteIntegrator: '<S55>/Integrator' */
  Integrator_pa_tmp = 0.00025 * *rty_V_EMS_p;

  /* DiscreteIntegrator: '<S55>/Integrator' */
  localB->Integrator_pa = Integrator_pa_tmp + localDW->Integrator_DSTATE_b;

  /* DiscreteIntegrator: '<S55>/Integrator' */
  if (localB->Integrator_pa > 400.0) {
    /* DiscreteIntegrator: '<S55>/Integrator' */
    localB->Integrator_pa = 400.0;
  } else if (localB->Integrator_pa < -400.0) {
    /* DiscreteIntegrator: '<S55>/Integrator' */
    localB->Integrator_pa = -400.0;
  }

  /* Sum: '<S64>/Sum' */
  *rty_V_EMS += localB->Integrator_pa;

  /* Saturate: '<S62>/Saturation' */
  if (*rty_V_EMS > 400.0) {
    *rty_V_EMS = 400.0;
  } else if (*rty_V_EMS < -400.0) {
    *rty_V_EMS = -400.0;
  }

  /* End of Saturate: '<S62>/Saturation' */

  /* Sum: '<S4>/Sum1' */
  *rty_V_EMS_d = rtu_CorrienteRefEMS[1] - rtu_I_real_ems[1];

  /* Gain: '<S114>/Proportional Gain' */
  *rty_V_EMS_p = 0.5039 * *rty_V_EMS_d;

  /* Sum: '<S119>/Sum Fdbk' */
  *rty_V_EMS_f = *rty_V_EMS_p + localDW->Integrator_DSTATE_bd;

  /* DeadZone: '<S101>/DeadZone' */
  if (*rty_V_EMS_f > 400.0) {
    *rty_V_EMS_f -= 400.0;
  } else if (*rty_V_EMS_f >= -400.0) {
    *rty_V_EMS_f = 0.0;
  } else {
    *rty_V_EMS_f -= -400.0;
  }

  /* End of DeadZone: '<S101>/DeadZone' */

  /* Gain: '<S106>/Integral Gain' */
  *rty_V_EMS_d *= 416.6667;

  /* Switch: '<S99>/Switch1' incorporates:
   *  Constant: '<S99>/Clamping_zero'
   *  Constant: '<S99>/Constant'
   *  Constant: '<S99>/Constant2'
   *  RelationalOperator: '<S99>/fix for DT propagation issue'
   */
  if (*rty_V_EMS_f > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S99>/Switch2' incorporates:
   *  Constant: '<S99>/Clamping_zero'
   *  Constant: '<S99>/Constant3'
   *  Constant: '<S99>/Constant4'
   *  RelationalOperator: '<S99>/fix for DT propagation issue1'
   */
  if (*rty_V_EMS_d > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Clamping_zero'
   *  Constant: '<S99>/Constant1'
   *  Logic: '<S99>/AND3'
   *  RelationalOperator: '<S99>/Equal1'
   *  RelationalOperator: '<S99>/Relational Operator'
   *  Switch: '<S99>/Switch1'
   *  Switch: '<S99>/Switch2'
   */
  if ((*rty_V_EMS_f != 0.0) && (tmp == tmp_0)) {
    *rty_V_EMS_d = 0.0;
  }

  /* End of Switch: '<S99>/Switch' */

  /* DiscreteIntegrator: '<S109>/Integrator' */
  Integrator_m_tmp = 0.00025 * *rty_V_EMS_d;

  /* DiscreteIntegrator: '<S109>/Integrator' */
  localB->Integrator_m = Integrator_m_tmp + localDW->Integrator_DSTATE_bd;

  /* DiscreteIntegrator: '<S109>/Integrator' */
  if (localB->Integrator_m > 400.0) {
    /* DiscreteIntegrator: '<S109>/Integrator' */
    localB->Integrator_m = 400.0;
  } else if (localB->Integrator_m < -400.0) {
    /* DiscreteIntegrator: '<S109>/Integrator' */
    localB->Integrator_m = -400.0;
  }

  /* Sum: '<S118>/Sum' */
  *rty_V_EMS_p += localB->Integrator_m;

  /* Saturate: '<S116>/Saturation' */
  if (*rty_V_EMS_p > 400.0) {
    *rty_V_EMS_p = 400.0;
  } else if (*rty_V_EMS_p < -400.0) {
    *rty_V_EMS_p = -400.0;
  }

  /* End of Saturate: '<S116>/Saturation' */

  /* Sum: '<S4>/Sum2' */
  *rty_V_EMS_f = rtu_CorrienteRefEMS[2] - rtu_I_real_ems[2];

  /* Gain: '<S168>/Proportional Gain' */
  *rty_V_EMS_d = 0.5039 * *rty_V_EMS_f;

  /* Sum: '<S173>/Sum Fdbk' */
  *rty_V_EMS_g = *rty_V_EMS_d + localDW->Integrator_DSTATE_p;

  /* DeadZone: '<S155>/DeadZone' */
  if (*rty_V_EMS_g > 400.0) {
    *rty_V_EMS_g -= 400.0;
  } else if (*rty_V_EMS_g >= -400.0) {
    *rty_V_EMS_g = 0.0;
  } else {
    *rty_V_EMS_g -= -400.0;
  }

  /* End of DeadZone: '<S155>/DeadZone' */

  /* Gain: '<S160>/Integral Gain' */
  *rty_V_EMS_f *= 416.6667;

  /* Switch: '<S153>/Switch1' incorporates:
   *  Constant: '<S153>/Clamping_zero'
   *  Constant: '<S153>/Constant'
   *  Constant: '<S153>/Constant2'
   *  RelationalOperator: '<S153>/fix for DT propagation issue'
   */
  if (*rty_V_EMS_g > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S153>/Switch2' incorporates:
   *  Constant: '<S153>/Clamping_zero'
   *  Constant: '<S153>/Constant3'
   *  Constant: '<S153>/Constant4'
   *  RelationalOperator: '<S153>/fix for DT propagation issue1'
   */
  if (*rty_V_EMS_f > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S153>/Switch' incorporates:
   *  Constant: '<S153>/Clamping_zero'
   *  Constant: '<S153>/Constant1'
   *  Logic: '<S153>/AND3'
   *  RelationalOperator: '<S153>/Equal1'
   *  RelationalOperator: '<S153>/Relational Operator'
   *  Switch: '<S153>/Switch1'
   *  Switch: '<S153>/Switch2'
   */
  if ((*rty_V_EMS_g != 0.0) && (tmp == tmp_0)) {
    *rty_V_EMS_f = 0.0;
  }

  /* End of Switch: '<S153>/Switch' */

  /* DiscreteIntegrator: '<S163>/Integrator' */
  Integrator_a_tmp = 0.00025 * *rty_V_EMS_f;

  /* DiscreteIntegrator: '<S163>/Integrator' */
  localB->Integrator_a = Integrator_a_tmp + localDW->Integrator_DSTATE_p;

  /* DiscreteIntegrator: '<S163>/Integrator' */
  if (localB->Integrator_a > 400.0) {
    /* DiscreteIntegrator: '<S163>/Integrator' */
    localB->Integrator_a = 400.0;
  } else if (localB->Integrator_a < -400.0) {
    /* DiscreteIntegrator: '<S163>/Integrator' */
    localB->Integrator_a = -400.0;
  }

  /* Sum: '<S172>/Sum' */
  *rty_V_EMS_d += localB->Integrator_a;

  /* Saturate: '<S170>/Saturation' */
  if (*rty_V_EMS_d > 400.0) {
    *rty_V_EMS_d = 400.0;
  } else if (*rty_V_EMS_d < -400.0) {
    *rty_V_EMS_d = -400.0;
  }

  /* End of Saturate: '<S170>/Saturation' */

  /* Sum: '<S4>/Sum3' */
  *rty_V_EMS_g = rtu_CorrienteRefEMS[3] - rtu_I_real_ems[3];

  /* Gain: '<S222>/Proportional Gain' */
  *rty_V_EMS_f = 0.5039 * *rty_V_EMS_g;

  /* Sum: '<S227>/Sum Fdbk' */
  *rty_V_EMS_dd = *rty_V_EMS_f + localDW->Integrator_DSTATE_g;

  /* DeadZone: '<S209>/DeadZone' */
  if (*rty_V_EMS_dd > 400.0) {
    *rty_V_EMS_dd -= 400.0;
  } else if (*rty_V_EMS_dd >= -400.0) {
    *rty_V_EMS_dd = 0.0;
  } else {
    *rty_V_EMS_dd -= -400.0;
  }

  /* End of DeadZone: '<S209>/DeadZone' */

  /* Gain: '<S214>/Integral Gain' */
  *rty_V_EMS_g *= 416.6667;

  /* Switch: '<S207>/Switch1' incorporates:
   *  Constant: '<S207>/Clamping_zero'
   *  Constant: '<S207>/Constant'
   *  Constant: '<S207>/Constant2'
   *  RelationalOperator: '<S207>/fix for DT propagation issue'
   */
  if (*rty_V_EMS_dd > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S207>/Switch2' incorporates:
   *  Constant: '<S207>/Clamping_zero'
   *  Constant: '<S207>/Constant3'
   *  Constant: '<S207>/Constant4'
   *  RelationalOperator: '<S207>/fix for DT propagation issue1'
   */
  if (*rty_V_EMS_g > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S207>/Switch' incorporates:
   *  Constant: '<S207>/Clamping_zero'
   *  Constant: '<S207>/Constant1'
   *  Logic: '<S207>/AND3'
   *  RelationalOperator: '<S207>/Equal1'
   *  RelationalOperator: '<S207>/Relational Operator'
   *  Switch: '<S207>/Switch1'
   *  Switch: '<S207>/Switch2'
   */
  if ((*rty_V_EMS_dd != 0.0) && (tmp == tmp_0)) {
    *rty_V_EMS_g = 0.0;
  }

  /* End of Switch: '<S207>/Switch' */

  /* DiscreteIntegrator: '<S217>/Integrator' */
  Integrator_f_tmp = 0.00025 * *rty_V_EMS_g;

  /* DiscreteIntegrator: '<S217>/Integrator' */
  localB->Integrator_f = Integrator_f_tmp + localDW->Integrator_DSTATE_g;

  /* DiscreteIntegrator: '<S217>/Integrator' */
  if (localB->Integrator_f > 400.0) {
    /* DiscreteIntegrator: '<S217>/Integrator' */
    localB->Integrator_f = 400.0;
  } else if (localB->Integrator_f < -400.0) {
    /* DiscreteIntegrator: '<S217>/Integrator' */
    localB->Integrator_f = -400.0;
  }

  /* Sum: '<S226>/Sum' */
  *rty_V_EMS_f += localB->Integrator_f;

  /* Saturate: '<S224>/Saturation' */
  if (*rty_V_EMS_f > 400.0) {
    *rty_V_EMS_f = 400.0;
  } else if (*rty_V_EMS_f < -400.0) {
    *rty_V_EMS_f = -400.0;
  }

  /* End of Saturate: '<S224>/Saturation' */

  /* Sum: '<S4>/Sum4' */
  *rty_V_EMS_dd = rtu_CorrienteRefEMS[4] - rtu_I_real_ems[4];

  /* Gain: '<S276>/Proportional Gain' */
  *rty_V_EMS_g = 0.5039 * *rty_V_EMS_dd;

  /* Sum: '<S281>/Sum Fdbk' */
  localB->IntegralGain = *rty_V_EMS_g + localDW->Integrator_DSTATE_gi;

  /* DeadZone: '<S263>/DeadZone' */
  if (localB->IntegralGain > 400.0) {
    localB->IntegralGain -= 400.0;
  } else if (localB->IntegralGain >= -400.0) {
    localB->IntegralGain = 0.0;
  } else {
    localB->IntegralGain -= -400.0;
  }

  /* End of DeadZone: '<S263>/DeadZone' */

  /* Gain: '<S268>/Integral Gain' */
  *rty_V_EMS_dd *= 416.6667;

  /* Switch: '<S261>/Switch1' incorporates:
   *  Constant: '<S261>/Clamping_zero'
   *  Constant: '<S261>/Constant'
   *  Constant: '<S261>/Constant2'
   *  RelationalOperator: '<S261>/fix for DT propagation issue'
   */
  if (localB->IntegralGain > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S261>/Switch2' incorporates:
   *  Constant: '<S261>/Clamping_zero'
   *  Constant: '<S261>/Constant3'
   *  Constant: '<S261>/Constant4'
   *  RelationalOperator: '<S261>/fix for DT propagation issue1'
   */
  if (*rty_V_EMS_dd > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S261>/Switch' incorporates:
   *  Constant: '<S261>/Clamping_zero'
   *  Constant: '<S261>/Constant1'
   *  Logic: '<S261>/AND3'
   *  RelationalOperator: '<S261>/Equal1'
   *  RelationalOperator: '<S261>/Relational Operator'
   *  Switch: '<S261>/Switch1'
   *  Switch: '<S261>/Switch2'
   */
  if ((localB->IntegralGain != 0.0) && (tmp == tmp_0)) {
    *rty_V_EMS_dd = 0.0;
  }

  /* End of Switch: '<S261>/Switch' */

  /* DiscreteIntegrator: '<S271>/Integrator' */
  Integrator_e_tmp = 0.00025 * *rty_V_EMS_dd;

  /* DiscreteIntegrator: '<S271>/Integrator' */
  localB->Integrator_e = Integrator_e_tmp + localDW->Integrator_DSTATE_gi;

  /* DiscreteIntegrator: '<S271>/Integrator' */
  if (localB->Integrator_e > 400.0) {
    /* DiscreteIntegrator: '<S271>/Integrator' */
    localB->Integrator_e = 400.0;
  } else if (localB->Integrator_e < -400.0) {
    /* DiscreteIntegrator: '<S271>/Integrator' */
    localB->Integrator_e = -400.0;
  }

  /* Sum: '<S280>/Sum' */
  *rty_V_EMS_g += localB->Integrator_e;

  /* Saturate: '<S278>/Saturation' */
  if (*rty_V_EMS_g > 400.0) {
    *rty_V_EMS_g = 400.0;
  } else if (*rty_V_EMS_g < -400.0) {
    *rty_V_EMS_g = -400.0;
  }

  /* End of Saturate: '<S278>/Saturation' */

  /* Sum: '<S4>/Sum5' */
  localB->IntegralGain = rtu_CorrienteRefEMS[5] - rtu_I_real_ems[5];

  /* Gain: '<S330>/Proportional Gain' */
  *rty_V_EMS_dd = 0.5039 * localB->IntegralGain;

  /* Sum: '<S335>/Sum Fdbk' */
  localB->DeadZone = *rty_V_EMS_dd + localDW->Integrator_DSTATE_px;

  /* DeadZone: '<S317>/DeadZone' */
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  /* End of DeadZone: '<S317>/DeadZone' */

  /* Gain: '<S322>/Integral Gain' */
  localB->IntegralGain *= 416.6667;

  /* Switch: '<S315>/Switch1' incorporates:
   *  Constant: '<S315>/Clamping_zero'
   *  Constant: '<S315>/Constant'
   *  Constant: '<S315>/Constant2'
   *  RelationalOperator: '<S315>/fix for DT propagation issue'
   */
  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S315>/Switch2' incorporates:
   *  Constant: '<S315>/Clamping_zero'
   *  Constant: '<S315>/Constant3'
   *  Constant: '<S315>/Constant4'
   *  RelationalOperator: '<S315>/fix for DT propagation issue1'
   */
  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S315>/Switch' incorporates:
   *  Constant: '<S315>/Clamping_zero'
   *  Constant: '<S315>/Constant1'
   *  Logic: '<S315>/AND3'
   *  RelationalOperator: '<S315>/Equal1'
   *  RelationalOperator: '<S315>/Relational Operator'
   *  Switch: '<S315>/Switch1'
   *  Switch: '<S315>/Switch2'
   */
  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  /* End of Switch: '<S315>/Switch' */

  /* DiscreteIntegrator: '<S325>/Integrator' */
  localB->IntegralGain *= 0.00025;

  /* DiscreteIntegrator: '<S325>/Integrator' */
  localB->DeadZone = localB->IntegralGain + localDW->Integrator_DSTATE_px;

  /* DiscreteIntegrator: '<S325>/Integrator' */
  if (localB->DeadZone > 400.0) {
    /* DiscreteIntegrator: '<S325>/Integrator' */
    localB->DeadZone = 400.0;
  } else if (localB->DeadZone < -400.0) {
    /* DiscreteIntegrator: '<S325>/Integrator' */
    localB->DeadZone = -400.0;
  }

  /* Sum: '<S334>/Sum' */
  *rty_V_EMS_dd += localB->DeadZone;

  /* Saturate: '<S332>/Saturation' */
  if (*rty_V_EMS_dd > 400.0) {
    *rty_V_EMS_dd = 400.0;
  } else if (*rty_V_EMS_dd < -400.0) {
    *rty_V_EMS_dd = -400.0;
  }

  /* End of Saturate: '<S332>/Saturation' */

  /* Update for DiscreteIntegrator: '<S379>/Integrator' */
  localDW->Integrator_DSTATE = localB->Integrator_tmp + localB->Integrator;
  if (localDW->Integrator_DSTATE > 400.0) {
    localDW->Integrator_DSTATE = 400.0;
  } else if (localDW->Integrator_DSTATE < -400.0) {
    localDW->Integrator_DSTATE = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S433>/Integrator' */
  localDW->Integrator_DSTATE_o = localB->Integrator_d_tmp + localB->Integrator_d;
  if (localDW->Integrator_DSTATE_o > 400.0) {
    localDW->Integrator_DSTATE_o = 400.0;
  } else if (localDW->Integrator_DSTATE_o < -400.0) {
    localDW->Integrator_DSTATE_o = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S487>/Integrator' */
  localDW->Integrator_DSTATE_c = Integrator_k_tmp + localB->Integrator_k;
  if (localDW->Integrator_DSTATE_c > 400.0) {
    localDW->Integrator_DSTATE_c = 400.0;
  } else if (localDW->Integrator_DSTATE_c < -400.0) {
    localDW->Integrator_DSTATE_c = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S541>/Integrator' */
  localDW->Integrator_DSTATE_om = Integrator_p_tmp + localB->Integrator_p;
  if (localDW->Integrator_DSTATE_om > 400.0) {
    localDW->Integrator_DSTATE_om = 400.0;
  } else if (localDW->Integrator_DSTATE_om < -400.0) {
    localDW->Integrator_DSTATE_om = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S55>/Integrator' */
  localDW->Integrator_DSTATE_b = Integrator_pa_tmp + localB->Integrator_pa;
  if (localDW->Integrator_DSTATE_b > 400.0) {
    localDW->Integrator_DSTATE_b = 400.0;
  } else if (localDW->Integrator_DSTATE_b < -400.0) {
    localDW->Integrator_DSTATE_b = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S109>/Integrator' */
  localDW->Integrator_DSTATE_bd = Integrator_m_tmp + localB->Integrator_m;
  if (localDW->Integrator_DSTATE_bd > 400.0) {
    localDW->Integrator_DSTATE_bd = 400.0;
  } else if (localDW->Integrator_DSTATE_bd < -400.0) {
    localDW->Integrator_DSTATE_bd = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S163>/Integrator' */
  localDW->Integrator_DSTATE_p = Integrator_a_tmp + localB->Integrator_a;
  if (localDW->Integrator_DSTATE_p > 400.0) {
    localDW->Integrator_DSTATE_p = 400.0;
  } else if (localDW->Integrator_DSTATE_p < -400.0) {
    localDW->Integrator_DSTATE_p = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S217>/Integrator' */
  localDW->Integrator_DSTATE_g = Integrator_f_tmp + localB->Integrator_f;
  if (localDW->Integrator_DSTATE_g > 400.0) {
    localDW->Integrator_DSTATE_g = 400.0;
  } else if (localDW->Integrator_DSTATE_g < -400.0) {
    localDW->Integrator_DSTATE_g = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S271>/Integrator' */
  localDW->Integrator_DSTATE_gi = Integrator_e_tmp + localB->Integrator_e;
  if (localDW->Integrator_DSTATE_gi > 400.0) {
    localDW->Integrator_DSTATE_gi = 400.0;
  } else if (localDW->Integrator_DSTATE_gi < -400.0) {
    localDW->Integrator_DSTATE_gi = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S325>/Integrator' */
  localDW->Integrator_DSTATE_px = localB->IntegralGain + localB->DeadZone;
  if (localDW->Integrator_DSTATE_px > 400.0) {
    localDW->Integrator_DSTATE_px = 400.0;
  } else if (localDW->Integrator_DSTATE_px < -400.0) {
    localDW->Integrator_DSTATE_px = -400.0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
