//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ControlDeCorriente.cpp
//
// Code generated for Simulink model 'C_5DOF_EL'.
//
// Model version                  : 1.82
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Thu Apr 16 19:58:10 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtwtypes.h"
#include "C_5DOF_EL_types.h"
#include "C_5DOF_EL.h"
#include "ControlDeCorriente.h"

// Output and update for atomic system: '<S1>/ControlDeCorriente'
void C_5DOF_EL::C_5DOF_E_ControlDeCorriente(const real_T rtu_CorrienteRefHEMS[4],
  const HEMS *rtu_I_real_hems, const EMS *rtu_I_real_ems, const real_T
  rtu_CorrienteRefEMS[6], B_ControlDeCorriente_C_5DOF_E_T *localB,
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

  // Sum: '<S3>/Sum6'
  localB->DeadZone = rtu_CorrienteRefHEMS[0] - rtu_I_real_hems->I_HEMS1;

  // Gain: '<S383>/Proportional Gain'
  localB->Sum = 22.9546 * localB->DeadZone;

  // Sum: '<S388>/Sum Fdbk'
  localB->IntegralGain = localB->Sum + localDW->Integrator_DSTATE;

  // DeadZone: '<S370>/DeadZone'
  if (localB->IntegralGain > 400.0) {
    localB->IntegralGain -= 400.0;
  } else if (localB->IntegralGain >= -400.0) {
    localB->IntegralGain = 0.0;
  } else {
    localB->IntegralGain -= -400.0;
  }

  // End of DeadZone: '<S370>/DeadZone'

  // Gain: '<S375>/Integral Gain'
  localB->DeadZone *= 208.3333;

  // Switch: '<S368>/Switch1' incorporates:
  //   Constant: '<S368>/Clamping_zero'
  //   Constant: '<S368>/Constant'
  //   Constant: '<S368>/Constant2'
  //   RelationalOperator: '<S368>/fix for DT propagation issue'

  if (localB->IntegralGain > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S368>/Switch2' incorporates:
  //   Constant: '<S368>/Clamping_zero'
  //   Constant: '<S368>/Constant3'
  //   Constant: '<S368>/Constant4'
  //   RelationalOperator: '<S368>/fix for DT propagation issue1'

  if (localB->DeadZone > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S368>/Switch' incorporates:
  //   Constant: '<S368>/Clamping_zero'
  //   Constant: '<S368>/Constant1'
  //   Logic: '<S368>/AND3'
  //   RelationalOperator: '<S368>/Equal1'
  //   RelationalOperator: '<S368>/Relational Operator'
  //   Switch: '<S368>/Switch1'
  //   Switch: '<S368>/Switch2'

  if ((localB->IntegralGain != 0.0) && (tmp == tmp_0)) {
    localB->DeadZone = 0.0;
  }

  // End of Switch: '<S368>/Switch'

  // DiscreteIntegrator: '<S378>/Integrator'
  localB->Integrator_tmp = 0.00025 * localB->DeadZone;

  // DiscreteIntegrator: '<S378>/Integrator'
  localB->Integrator = localB->Integrator_tmp + localDW->Integrator_DSTATE;

  // DiscreteIntegrator: '<S378>/Integrator'
  if (localB->Integrator > 400.0) {
    // DiscreteIntegrator: '<S378>/Integrator'
    localB->Integrator = 400.0;
  } else if (localB->Integrator < -400.0) {
    // DiscreteIntegrator: '<S378>/Integrator'
    localB->Integrator = -400.0;
  }

  // Sum: '<S387>/Sum'
  localB->Sum += localB->Integrator;

  // Saturate: '<S385>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S385>/Saturation'
    localB->Saturation = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S385>/Saturation'
    localB->Saturation = -400.0;
  } else {
    // Saturate: '<S385>/Saturation'
    localB->Saturation = localB->Sum;
  }

  // End of Saturate: '<S385>/Saturation'

  // Sum: '<S3>/Sum7'
  localB->IntegralGain = rtu_CorrienteRefHEMS[1] - rtu_I_real_hems->I_HEMS2;

  // Gain: '<S437>/Proportional Gain'
  localB->Sum = 22.9546 * localB->IntegralGain;

  // Sum: '<S442>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_o;

  // DeadZone: '<S424>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S424>/DeadZone'

  // Gain: '<S429>/Integral Gain'
  localB->IntegralGain *= 208.3333;

  // Switch: '<S422>/Switch1' incorporates:
  //   Constant: '<S422>/Clamping_zero'
  //   Constant: '<S422>/Constant'
  //   Constant: '<S422>/Constant2'
  //   RelationalOperator: '<S422>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S422>/Switch2' incorporates:
  //   Constant: '<S422>/Clamping_zero'
  //   Constant: '<S422>/Constant3'
  //   Constant: '<S422>/Constant4'
  //   RelationalOperator: '<S422>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S422>/Switch' incorporates:
  //   Constant: '<S422>/Clamping_zero'
  //   Constant: '<S422>/Constant1'
  //   Logic: '<S422>/AND3'
  //   RelationalOperator: '<S422>/Equal1'
  //   RelationalOperator: '<S422>/Relational Operator'
  //   Switch: '<S422>/Switch1'
  //   Switch: '<S422>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  // End of Switch: '<S422>/Switch'

  // DiscreteIntegrator: '<S432>/Integrator'
  localB->Integrator_d_tmp = 0.00025 * localB->IntegralGain;

  // DiscreteIntegrator: '<S432>/Integrator'
  localB->Integrator_d = localB->Integrator_d_tmp + localDW->Integrator_DSTATE_o;

  // DiscreteIntegrator: '<S432>/Integrator'
  if (localB->Integrator_d > 400.0) {
    // DiscreteIntegrator: '<S432>/Integrator'
    localB->Integrator_d = 400.0;
  } else if (localB->Integrator_d < -400.0) {
    // DiscreteIntegrator: '<S432>/Integrator'
    localB->Integrator_d = -400.0;
  }

  // Sum: '<S441>/Sum'
  localB->Sum += localB->Integrator_d;

  // Saturate: '<S439>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S439>/Saturation'
    localB->Saturation_h = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S439>/Saturation'
    localB->Saturation_h = -400.0;
  } else {
    // Saturate: '<S439>/Saturation'
    localB->Saturation_h = localB->Sum;
  }

  // End of Saturate: '<S439>/Saturation'

  // Sum: '<S3>/Sum8'
  localB->IntegralGain = rtu_CorrienteRefHEMS[2] - rtu_I_real_hems->I_HEMS3;

  // Gain: '<S491>/Proportional Gain'
  localB->Sum = 22.9546 * localB->IntegralGain;

  // Sum: '<S496>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_c;

  // DeadZone: '<S478>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S478>/DeadZone'

  // Gain: '<S483>/Integral Gain'
  localB->IntegralGain *= 208.3333;

  // Switch: '<S476>/Switch1' incorporates:
  //   Constant: '<S476>/Clamping_zero'
  //   Constant: '<S476>/Constant'
  //   Constant: '<S476>/Constant2'
  //   RelationalOperator: '<S476>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S476>/Switch2' incorporates:
  //   Constant: '<S476>/Clamping_zero'
  //   Constant: '<S476>/Constant3'
  //   Constant: '<S476>/Constant4'
  //   RelationalOperator: '<S476>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S476>/Switch' incorporates:
  //   Constant: '<S476>/Clamping_zero'
  //   Constant: '<S476>/Constant1'
  //   Logic: '<S476>/AND3'
  //   RelationalOperator: '<S476>/Equal1'
  //   RelationalOperator: '<S476>/Relational Operator'
  //   Switch: '<S476>/Switch1'
  //   Switch: '<S476>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  // End of Switch: '<S476>/Switch'

  // DiscreteIntegrator: '<S486>/Integrator'
  Integrator_k_tmp = 0.00025 * localB->IntegralGain;

  // DiscreteIntegrator: '<S486>/Integrator'
  localB->Integrator_k = Integrator_k_tmp + localDW->Integrator_DSTATE_c;

  // DiscreteIntegrator: '<S486>/Integrator'
  if (localB->Integrator_k > 400.0) {
    // DiscreteIntegrator: '<S486>/Integrator'
    localB->Integrator_k = 400.0;
  } else if (localB->Integrator_k < -400.0) {
    // DiscreteIntegrator: '<S486>/Integrator'
    localB->Integrator_k = -400.0;
  }

  // Sum: '<S495>/Sum'
  localB->Sum += localB->Integrator_k;

  // Saturate: '<S493>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S493>/Saturation'
    localB->Saturation_f = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S493>/Saturation'
    localB->Saturation_f = -400.0;
  } else {
    // Saturate: '<S493>/Saturation'
    localB->Saturation_f = localB->Sum;
  }

  // End of Saturate: '<S493>/Saturation'

  // Sum: '<S3>/Sum9'
  localB->IntegralGain = rtu_CorrienteRefHEMS[3] - rtu_I_real_hems->I_HEMS4;

  // Gain: '<S545>/Proportional Gain'
  localB->Sum = 22.9546 * localB->IntegralGain;

  // Sum: '<S550>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_om;

  // DeadZone: '<S532>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S532>/DeadZone'

  // Gain: '<S537>/Integral Gain'
  localB->IntegralGain *= 208.3333;

  // Switch: '<S530>/Switch1' incorporates:
  //   Constant: '<S530>/Clamping_zero'
  //   Constant: '<S530>/Constant'
  //   Constant: '<S530>/Constant2'
  //   RelationalOperator: '<S530>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S530>/Switch2' incorporates:
  //   Constant: '<S530>/Clamping_zero'
  //   Constant: '<S530>/Constant3'
  //   Constant: '<S530>/Constant4'
  //   RelationalOperator: '<S530>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S530>/Switch' incorporates:
  //   Constant: '<S530>/Clamping_zero'
  //   Constant: '<S530>/Constant1'
  //   Logic: '<S530>/AND3'
  //   RelationalOperator: '<S530>/Equal1'
  //   RelationalOperator: '<S530>/Relational Operator'
  //   Switch: '<S530>/Switch1'
  //   Switch: '<S530>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  // End of Switch: '<S530>/Switch'

  // DiscreteIntegrator: '<S540>/Integrator'
  Integrator_p_tmp = 0.00025 * localB->IntegralGain;

  // DiscreteIntegrator: '<S540>/Integrator'
  localB->Integrator_p = Integrator_p_tmp + localDW->Integrator_DSTATE_om;

  // DiscreteIntegrator: '<S540>/Integrator'
  if (localB->Integrator_p > 400.0) {
    // DiscreteIntegrator: '<S540>/Integrator'
    localB->Integrator_p = 400.0;
  } else if (localB->Integrator_p < -400.0) {
    // DiscreteIntegrator: '<S540>/Integrator'
    localB->Integrator_p = -400.0;
  }

  // Sum: '<S549>/Sum'
  localB->Sum += localB->Integrator_p;

  // Saturate: '<S547>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S547>/Saturation'
    localB->Saturation_d = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S547>/Saturation'
    localB->Saturation_d = -400.0;
  } else {
    // Saturate: '<S547>/Saturation'
    localB->Saturation_d = localB->Sum;
  }

  // End of Saturate: '<S547>/Saturation'

  // Sum: '<S3>/Sum'
  localB->IntegralGain = rtu_CorrienteRefEMS[0] - rtu_I_real_ems->I_EMS5;

  // Gain: '<S59>/Proportional Gain'
  localB->Sum = 0.5039 * localB->IntegralGain;

  // Sum: '<S64>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_b;

  // DeadZone: '<S46>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S46>/DeadZone'

  // Gain: '<S51>/Integral Gain'
  localB->IntegralGain *= 416.6667;

  // Switch: '<S44>/Switch1' incorporates:
  //   Constant: '<S44>/Clamping_zero'
  //   Constant: '<S44>/Constant'
  //   Constant: '<S44>/Constant2'
  //   RelationalOperator: '<S44>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S44>/Switch2' incorporates:
  //   Constant: '<S44>/Clamping_zero'
  //   Constant: '<S44>/Constant3'
  //   Constant: '<S44>/Constant4'
  //   RelationalOperator: '<S44>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S44>/Switch' incorporates:
  //   Constant: '<S44>/Clamping_zero'
  //   Constant: '<S44>/Constant1'
  //   Logic: '<S44>/AND3'
  //   RelationalOperator: '<S44>/Equal1'
  //   RelationalOperator: '<S44>/Relational Operator'
  //   Switch: '<S44>/Switch1'
  //   Switch: '<S44>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  // End of Switch: '<S44>/Switch'

  // DiscreteIntegrator: '<S54>/Integrator'
  Integrator_pa_tmp = 0.00025 * localB->IntegralGain;

  // DiscreteIntegrator: '<S54>/Integrator'
  localB->Integrator_pa = Integrator_pa_tmp + localDW->Integrator_DSTATE_b;

  // DiscreteIntegrator: '<S54>/Integrator'
  if (localB->Integrator_pa > 400.0) {
    // DiscreteIntegrator: '<S54>/Integrator'
    localB->Integrator_pa = 400.0;
  } else if (localB->Integrator_pa < -400.0) {
    // DiscreteIntegrator: '<S54>/Integrator'
    localB->Integrator_pa = -400.0;
  }

  // Sum: '<S63>/Sum'
  localB->Sum += localB->Integrator_pa;

  // Saturate: '<S61>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S61>/Saturation'
    localB->Saturation_k = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S61>/Saturation'
    localB->Saturation_k = -400.0;
  } else {
    // Saturate: '<S61>/Saturation'
    localB->Saturation_k = localB->Sum;
  }

  // End of Saturate: '<S61>/Saturation'

  // Sum: '<S3>/Sum1'
  localB->IntegralGain = rtu_CorrienteRefEMS[1] - rtu_I_real_ems->I_EMS6;

  // Gain: '<S113>/Proportional Gain'
  localB->Sum = 0.5039 * localB->IntegralGain;

  // Sum: '<S118>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_bd;

  // DeadZone: '<S100>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S100>/DeadZone'

  // Gain: '<S105>/Integral Gain'
  localB->IntegralGain *= 416.6667;

  // Switch: '<S98>/Switch1' incorporates:
  //   Constant: '<S98>/Clamping_zero'
  //   Constant: '<S98>/Constant'
  //   Constant: '<S98>/Constant2'
  //   RelationalOperator: '<S98>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S98>/Switch2' incorporates:
  //   Constant: '<S98>/Clamping_zero'
  //   Constant: '<S98>/Constant3'
  //   Constant: '<S98>/Constant4'
  //   RelationalOperator: '<S98>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S98>/Switch' incorporates:
  //   Constant: '<S98>/Clamping_zero'
  //   Constant: '<S98>/Constant1'
  //   Logic: '<S98>/AND3'
  //   RelationalOperator: '<S98>/Equal1'
  //   RelationalOperator: '<S98>/Relational Operator'
  //   Switch: '<S98>/Switch1'
  //   Switch: '<S98>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  // End of Switch: '<S98>/Switch'

  // DiscreteIntegrator: '<S108>/Integrator'
  Integrator_m_tmp = 0.00025 * localB->IntegralGain;

  // DiscreteIntegrator: '<S108>/Integrator'
  localB->Integrator_m = Integrator_m_tmp + localDW->Integrator_DSTATE_bd;

  // DiscreteIntegrator: '<S108>/Integrator'
  if (localB->Integrator_m > 400.0) {
    // DiscreteIntegrator: '<S108>/Integrator'
    localB->Integrator_m = 400.0;
  } else if (localB->Integrator_m < -400.0) {
    // DiscreteIntegrator: '<S108>/Integrator'
    localB->Integrator_m = -400.0;
  }

  // Sum: '<S117>/Sum'
  localB->Sum += localB->Integrator_m;

  // Saturate: '<S115>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S115>/Saturation'
    localB->Saturation_dd = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S115>/Saturation'
    localB->Saturation_dd = -400.0;
  } else {
    // Saturate: '<S115>/Saturation'
    localB->Saturation_dd = localB->Sum;
  }

  // End of Saturate: '<S115>/Saturation'

  // Sum: '<S3>/Sum2'
  localB->IntegralGain = rtu_CorrienteRefEMS[2] - rtu_I_real_ems->I_EMS7;

  // Gain: '<S167>/Proportional Gain'
  localB->Sum = 0.5039 * localB->IntegralGain;

  // Sum: '<S172>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_p;

  // DeadZone: '<S154>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S154>/DeadZone'

  // Gain: '<S159>/Integral Gain'
  localB->IntegralGain *= 416.6667;

  // Switch: '<S152>/Switch1' incorporates:
  //   Constant: '<S152>/Clamping_zero'
  //   Constant: '<S152>/Constant'
  //   Constant: '<S152>/Constant2'
  //   RelationalOperator: '<S152>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S152>/Switch2' incorporates:
  //   Constant: '<S152>/Clamping_zero'
  //   Constant: '<S152>/Constant3'
  //   Constant: '<S152>/Constant4'
  //   RelationalOperator: '<S152>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S152>/Switch' incorporates:
  //   Constant: '<S152>/Clamping_zero'
  //   Constant: '<S152>/Constant1'
  //   Logic: '<S152>/AND3'
  //   RelationalOperator: '<S152>/Equal1'
  //   RelationalOperator: '<S152>/Relational Operator'
  //   Switch: '<S152>/Switch1'
  //   Switch: '<S152>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  // End of Switch: '<S152>/Switch'

  // DiscreteIntegrator: '<S162>/Integrator'
  Integrator_a_tmp = 0.00025 * localB->IntegralGain;

  // DiscreteIntegrator: '<S162>/Integrator'
  localB->Integrator_a = Integrator_a_tmp + localDW->Integrator_DSTATE_p;

  // DiscreteIntegrator: '<S162>/Integrator'
  if (localB->Integrator_a > 400.0) {
    // DiscreteIntegrator: '<S162>/Integrator'
    localB->Integrator_a = 400.0;
  } else if (localB->Integrator_a < -400.0) {
    // DiscreteIntegrator: '<S162>/Integrator'
    localB->Integrator_a = -400.0;
  }

  // Sum: '<S171>/Sum'
  localB->Sum += localB->Integrator_a;

  // Saturate: '<S169>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S169>/Saturation'
    localB->Saturation_o = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S169>/Saturation'
    localB->Saturation_o = -400.0;
  } else {
    // Saturate: '<S169>/Saturation'
    localB->Saturation_o = localB->Sum;
  }

  // End of Saturate: '<S169>/Saturation'

  // Sum: '<S3>/Sum3'
  localB->IntegralGain = rtu_CorrienteRefEMS[3] - rtu_I_real_ems->I_EMS8;

  // Gain: '<S221>/Proportional Gain'
  localB->Sum = 0.5039 * localB->IntegralGain;

  // Sum: '<S226>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_g;

  // DeadZone: '<S208>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S208>/DeadZone'

  // Gain: '<S213>/Integral Gain'
  localB->IntegralGain *= 416.6667;

  // Switch: '<S206>/Switch1' incorporates:
  //   Constant: '<S206>/Clamping_zero'
  //   Constant: '<S206>/Constant'
  //   Constant: '<S206>/Constant2'
  //   RelationalOperator: '<S206>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S206>/Switch2' incorporates:
  //   Constant: '<S206>/Clamping_zero'
  //   Constant: '<S206>/Constant3'
  //   Constant: '<S206>/Constant4'
  //   RelationalOperator: '<S206>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S206>/Switch' incorporates:
  //   Constant: '<S206>/Clamping_zero'
  //   Constant: '<S206>/Constant1'
  //   Logic: '<S206>/AND3'
  //   RelationalOperator: '<S206>/Equal1'
  //   RelationalOperator: '<S206>/Relational Operator'
  //   Switch: '<S206>/Switch1'
  //   Switch: '<S206>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  // End of Switch: '<S206>/Switch'

  // DiscreteIntegrator: '<S216>/Integrator'
  Integrator_f_tmp = 0.00025 * localB->IntegralGain;

  // DiscreteIntegrator: '<S216>/Integrator'
  localB->Integrator_f = Integrator_f_tmp + localDW->Integrator_DSTATE_g;

  // DiscreteIntegrator: '<S216>/Integrator'
  if (localB->Integrator_f > 400.0) {
    // DiscreteIntegrator: '<S216>/Integrator'
    localB->Integrator_f = 400.0;
  } else if (localB->Integrator_f < -400.0) {
    // DiscreteIntegrator: '<S216>/Integrator'
    localB->Integrator_f = -400.0;
  }

  // Sum: '<S225>/Sum'
  localB->Sum += localB->Integrator_f;

  // Saturate: '<S223>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S223>/Saturation'
    localB->Saturation_p = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S223>/Saturation'
    localB->Saturation_p = -400.0;
  } else {
    // Saturate: '<S223>/Saturation'
    localB->Saturation_p = localB->Sum;
  }

  // End of Saturate: '<S223>/Saturation'

  // Sum: '<S3>/Sum4'
  localB->IntegralGain = rtu_CorrienteRefEMS[4] - rtu_I_real_ems->I_EMS9;

  // Gain: '<S275>/Proportional Gain'
  localB->Sum = 0.5039 * localB->IntegralGain;

  // Sum: '<S280>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_gi;

  // DeadZone: '<S262>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S262>/DeadZone'

  // Gain: '<S267>/Integral Gain'
  localB->IntegralGain *= 416.6667;

  // Switch: '<S260>/Switch1' incorporates:
  //   Constant: '<S260>/Clamping_zero'
  //   Constant: '<S260>/Constant'
  //   Constant: '<S260>/Constant2'
  //   RelationalOperator: '<S260>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S260>/Switch2' incorporates:
  //   Constant: '<S260>/Clamping_zero'
  //   Constant: '<S260>/Constant3'
  //   Constant: '<S260>/Constant4'
  //   RelationalOperator: '<S260>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S260>/Switch' incorporates:
  //   Constant: '<S260>/Clamping_zero'
  //   Constant: '<S260>/Constant1'
  //   Logic: '<S260>/AND3'
  //   RelationalOperator: '<S260>/Equal1'
  //   RelationalOperator: '<S260>/Relational Operator'
  //   Switch: '<S260>/Switch1'
  //   Switch: '<S260>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->IntegralGain = 0.0;
  }

  // End of Switch: '<S260>/Switch'

  // DiscreteIntegrator: '<S270>/Integrator'
  Integrator_e_tmp = 0.00025 * localB->IntegralGain;

  // DiscreteIntegrator: '<S270>/Integrator'
  localB->Integrator_e = Integrator_e_tmp + localDW->Integrator_DSTATE_gi;

  // DiscreteIntegrator: '<S270>/Integrator'
  if (localB->Integrator_e > 400.0) {
    // DiscreteIntegrator: '<S270>/Integrator'
    localB->Integrator_e = 400.0;
  } else if (localB->Integrator_e < -400.0) {
    // DiscreteIntegrator: '<S270>/Integrator'
    localB->Integrator_e = -400.0;
  }

  // Sum: '<S279>/Sum'
  localB->Sum += localB->Integrator_e;

  // Saturate: '<S277>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S277>/Saturation'
    localB->Saturation_oe = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S277>/Saturation'
    localB->Saturation_oe = -400.0;
  } else {
    // Saturate: '<S277>/Saturation'
    localB->Saturation_oe = localB->Sum;
  }

  // End of Saturate: '<S277>/Saturation'

  // Sum: '<S3>/Sum5'
  localB->IntegralGain = rtu_CorrienteRefEMS[5] - rtu_I_real_ems->I_EMS10;

  // Gain: '<S329>/Proportional Gain'
  localB->Sum = 0.5039 * localB->IntegralGain;

  // Sum: '<S334>/Sum Fdbk'
  localB->DeadZone = localB->Sum + localDW->Integrator_DSTATE_px;

  // DeadZone: '<S316>/DeadZone'
  if (localB->DeadZone > 400.0) {
    localB->DeadZone -= 400.0;
  } else if (localB->DeadZone >= -400.0) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone -= -400.0;
  }

  // End of DeadZone: '<S316>/DeadZone'

  // Gain: '<S321>/Integral Gain'
  localB->IntegralGain *= 416.6667;

  // Switch: '<S314>/Switch1' incorporates:
  //   Constant: '<S314>/Clamping_zero'
  //   Constant: '<S314>/Constant'
  //   Constant: '<S314>/Constant2'
  //   RelationalOperator: '<S314>/fix for DT propagation issue'

  if (localB->DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S314>/Switch2' incorporates:
  //   Constant: '<S314>/Clamping_zero'
  //   Constant: '<S314>/Constant3'
  //   Constant: '<S314>/Constant4'
  //   RelationalOperator: '<S314>/fix for DT propagation issue1'

  if (localB->IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S314>/Switch' incorporates:
  //   Constant: '<S314>/Clamping_zero'
  //   Constant: '<S314>/Constant1'
  //   Logic: '<S314>/AND3'
  //   RelationalOperator: '<S314>/Equal1'
  //   RelationalOperator: '<S314>/Relational Operator'
  //   Switch: '<S314>/Switch1'
  //   Switch: '<S314>/Switch2'

  if ((localB->DeadZone != 0.0) && (tmp == tmp_0)) {
    localB->DeadZone = 0.0;
  } else {
    localB->DeadZone = localB->IntegralGain;
  }

  // End of Switch: '<S314>/Switch'

  // DiscreteIntegrator: '<S324>/Integrator'
  localB->DeadZone *= 0.00025;

  // DiscreteIntegrator: '<S324>/Integrator'
  localB->IntegralGain = localB->DeadZone + localDW->Integrator_DSTATE_px;

  // DiscreteIntegrator: '<S324>/Integrator'
  if (localB->IntegralGain > 400.0) {
    // DiscreteIntegrator: '<S324>/Integrator'
    localB->IntegralGain = 400.0;
  } else if (localB->IntegralGain < -400.0) {
    // DiscreteIntegrator: '<S324>/Integrator'
    localB->IntegralGain = -400.0;
  }

  // Sum: '<S333>/Sum'
  localB->Sum += localB->IntegralGain;

  // Saturate: '<S331>/Saturation'
  if (localB->Sum > 400.0) {
    // Saturate: '<S331>/Saturation'
    localB->Saturation_j = 400.0;
  } else if (localB->Sum < -400.0) {
    // Saturate: '<S331>/Saturation'
    localB->Saturation_j = -400.0;
  } else {
    // Saturate: '<S331>/Saturation'
    localB->Saturation_j = localB->Sum;
  }

  // End of Saturate: '<S331>/Saturation'

  // Update for DiscreteIntegrator: '<S378>/Integrator'
  localDW->Integrator_DSTATE = localB->Integrator_tmp + localB->Integrator;
  if (localDW->Integrator_DSTATE > 400.0) {
    localDW->Integrator_DSTATE = 400.0;
  } else if (localDW->Integrator_DSTATE < -400.0) {
    localDW->Integrator_DSTATE = -400.0;
  }

  // Update for DiscreteIntegrator: '<S432>/Integrator'
  localDW->Integrator_DSTATE_o = localB->Integrator_d_tmp + localB->Integrator_d;
  if (localDW->Integrator_DSTATE_o > 400.0) {
    localDW->Integrator_DSTATE_o = 400.0;
  } else if (localDW->Integrator_DSTATE_o < -400.0) {
    localDW->Integrator_DSTATE_o = -400.0;
  }

  // Update for DiscreteIntegrator: '<S486>/Integrator'
  localDW->Integrator_DSTATE_c = Integrator_k_tmp + localB->Integrator_k;
  if (localDW->Integrator_DSTATE_c > 400.0) {
    localDW->Integrator_DSTATE_c = 400.0;
  } else if (localDW->Integrator_DSTATE_c < -400.0) {
    localDW->Integrator_DSTATE_c = -400.0;
  }

  // Update for DiscreteIntegrator: '<S540>/Integrator'
  localDW->Integrator_DSTATE_om = Integrator_p_tmp + localB->Integrator_p;
  if (localDW->Integrator_DSTATE_om > 400.0) {
    localDW->Integrator_DSTATE_om = 400.0;
  } else if (localDW->Integrator_DSTATE_om < -400.0) {
    localDW->Integrator_DSTATE_om = -400.0;
  }

  // Update for DiscreteIntegrator: '<S54>/Integrator'
  localDW->Integrator_DSTATE_b = Integrator_pa_tmp + localB->Integrator_pa;
  if (localDW->Integrator_DSTATE_b > 400.0) {
    localDW->Integrator_DSTATE_b = 400.0;
  } else if (localDW->Integrator_DSTATE_b < -400.0) {
    localDW->Integrator_DSTATE_b = -400.0;
  }

  // Update for DiscreteIntegrator: '<S108>/Integrator'
  localDW->Integrator_DSTATE_bd = Integrator_m_tmp + localB->Integrator_m;
  if (localDW->Integrator_DSTATE_bd > 400.0) {
    localDW->Integrator_DSTATE_bd = 400.0;
  } else if (localDW->Integrator_DSTATE_bd < -400.0) {
    localDW->Integrator_DSTATE_bd = -400.0;
  }

  // Update for DiscreteIntegrator: '<S162>/Integrator'
  localDW->Integrator_DSTATE_p = Integrator_a_tmp + localB->Integrator_a;
  if (localDW->Integrator_DSTATE_p > 400.0) {
    localDW->Integrator_DSTATE_p = 400.0;
  } else if (localDW->Integrator_DSTATE_p < -400.0) {
    localDW->Integrator_DSTATE_p = -400.0;
  }

  // Update for DiscreteIntegrator: '<S216>/Integrator'
  localDW->Integrator_DSTATE_g = Integrator_f_tmp + localB->Integrator_f;
  if (localDW->Integrator_DSTATE_g > 400.0) {
    localDW->Integrator_DSTATE_g = 400.0;
  } else if (localDW->Integrator_DSTATE_g < -400.0) {
    localDW->Integrator_DSTATE_g = -400.0;
  }

  // Update for DiscreteIntegrator: '<S270>/Integrator'
  localDW->Integrator_DSTATE_gi = Integrator_e_tmp + localB->Integrator_e;
  if (localDW->Integrator_DSTATE_gi > 400.0) {
    localDW->Integrator_DSTATE_gi = 400.0;
  } else if (localDW->Integrator_DSTATE_gi < -400.0) {
    localDW->Integrator_DSTATE_gi = -400.0;
  }

  // Update for DiscreteIntegrator: '<S324>/Integrator'
  localDW->Integrator_DSTATE_px = localB->DeadZone + localB->IntegralGain;
  if (localDW->Integrator_DSTATE_px > 400.0) {
    localDW->Integrator_DSTATE_px = 400.0;
  } else if (localDW->Integrator_DSTATE_px < -400.0) {
    localDW->Integrator_DSTATE_px = -400.0;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
