#include "CorrienteH11.h"
#include "rtwtypes.h"

void CorrienteH11::step(const real_T rtu_I_real_hems[4], const real_T
  rtu_I_real_ems[6], const real_T rtu_CorrrienteRef[10], real_T rty_V_HEMS[4],
  real_T rty_V_EMS[6])
{
  real_T Integrator_h_tmp;
  real_T Integrator_j_tmp;
  real_T Integrator_k_tmp;
  real_T Integrator_l_tmp;
  real_T Integrator_m_tmp;
  real_T Integrator_p_tmp;
  real_T Integrator_pj_tmp;
  int8_T tmp;
  int8_T tmp_0;
  CorrienteH11_B.Saturation_i = rtu_CorrrienteRef[0] - rtu_I_real_hems[0];
  CorrienteH11_B.Saturation = 15.0 * CorrienteH11_B.Saturation_i;
  CorrienteH11_B.Saturation_e = CorrienteH11_B.Saturation +
    CorrienteH11_DW.Integrator_DSTATE;
  if (CorrienteH11_B.Saturation_e > 350.0) {
    CorrienteH11_B.Saturation_e -= 350.0;
  } else if (CorrienteH11_B.Saturation_e >= -350.0) {
    CorrienteH11_B.Saturation_e = 0.0;
  } else {
    CorrienteH11_B.Saturation_e -= -350.0;
  }

  CorrienteH11_B.Saturation_i *= 208.3333;
  if (CorrienteH11_B.Saturation_e > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_i > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.Saturation_e != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_i = 0.0;
  }

  CorrienteH11_B.Integrator_tmp = 0.00025 * CorrienteH11_B.Saturation_i;
  CorrienteH11_B.Integrator = CorrienteH11_B.Integrator_tmp +
    CorrienteH11_DW.Integrator_DSTATE;
  if (CorrienteH11_B.Integrator > 350.0) {
    CorrienteH11_B.Integrator = 350.0;
  } else if (CorrienteH11_B.Integrator < -350.0) {
    CorrienteH11_B.Integrator = -350.0;
  }

  CorrienteH11_B.Saturation_e = rtu_CorrrienteRef[1] - rtu_I_real_hems[1];
  CorrienteH11_B.Saturation_i = 15.0 * CorrienteH11_B.Saturation_e;
  CorrienteH11_B.Saturation_f = CorrienteH11_B.Saturation_i +
    CorrienteH11_DW.Integrator_DSTATE_e;
  if (CorrienteH11_B.Saturation_f > 350.0) {
    CorrienteH11_B.Saturation_f -= 350.0;
  } else if (CorrienteH11_B.Saturation_f >= -350.0) {
    CorrienteH11_B.Saturation_f = 0.0;
  } else {
    CorrienteH11_B.Saturation_f -= -350.0;
  }

  CorrienteH11_B.Saturation_e *= 208.3333;
  if (CorrienteH11_B.Saturation_f > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_e > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.Saturation_f != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_e = 0.0;
  }

  CorrienteH11_B.Integrator_f_tmp = 0.00025 * CorrienteH11_B.Saturation_e;
  CorrienteH11_B.Integrator_f = CorrienteH11_B.Integrator_f_tmp +
    CorrienteH11_DW.Integrator_DSTATE_e;
  if (CorrienteH11_B.Integrator_f > 350.0) {
    CorrienteH11_B.Integrator_f = 350.0;
  } else if (CorrienteH11_B.Integrator_f < -350.0) {
    CorrienteH11_B.Integrator_f = -350.0;
  }

  CorrienteH11_B.Saturation_f = rtu_CorrrienteRef[2] - rtu_I_real_hems[2];
  CorrienteH11_B.Saturation_e = 15.0 * CorrienteH11_B.Saturation_f;
  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_e +
    CorrienteH11_DW.Integrator_DSTATE_o;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    CorrienteH11_B.Saturation_j -= 350.0;
  } else if (CorrienteH11_B.Saturation_j >= -350.0) {
    CorrienteH11_B.Saturation_j = 0.0;
  } else {
    CorrienteH11_B.Saturation_j -= -350.0;
  }

  CorrienteH11_B.Saturation_f *= 208.3333;
  if (CorrienteH11_B.Saturation_j > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_f > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.Saturation_j != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_f = 0.0;
  }

  Integrator_p_tmp = 0.00025 * CorrienteH11_B.Saturation_f;
  CorrienteH11_B.Integrator_p = Integrator_p_tmp +
    CorrienteH11_DW.Integrator_DSTATE_o;
  if (CorrienteH11_B.Integrator_p > 350.0) {
    CorrienteH11_B.Integrator_p = 350.0;
  } else if (CorrienteH11_B.Integrator_p < -350.0) {
    CorrienteH11_B.Integrator_p = -350.0;
  }

  CorrienteH11_B.Saturation_j = rtu_CorrrienteRef[3] - rtu_I_real_hems[3];
  CorrienteH11_B.Saturation_f = 15.0 * CorrienteH11_B.Saturation_j;
  CorrienteH11_B.Saturation_p = CorrienteH11_B.Saturation_f +
    CorrienteH11_DW.Integrator_DSTATE_m;
  if (CorrienteH11_B.Saturation_p > 350.0) {
    CorrienteH11_B.Saturation_p -= 350.0;
  } else if (CorrienteH11_B.Saturation_p >= -350.0) {
    CorrienteH11_B.Saturation_p = 0.0;
  } else {
    CorrienteH11_B.Saturation_p -= -350.0;
  }

  CorrienteH11_B.Saturation_j *= 208.3333;
  if (CorrienteH11_B.Saturation_p > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_j > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.Saturation_p != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_j = 0.0;
  }

  Integrator_k_tmp = 0.00025 * CorrienteH11_B.Saturation_j;
  CorrienteH11_B.Integrator_k = Integrator_k_tmp +
    CorrienteH11_DW.Integrator_DSTATE_m;
  if (CorrienteH11_B.Integrator_k > 350.0) {
    CorrienteH11_B.Integrator_k = 350.0;
  } else if (CorrienteH11_B.Integrator_k < -350.0) {
    CorrienteH11_B.Integrator_k = -350.0;
  }

  CorrienteH11_B.Saturation_p = rtu_CorrrienteRef[4] - rtu_I_real_ems[0];
  CorrienteH11_B.Saturation_j = 5.0 * CorrienteH11_B.Saturation_p;
  CorrienteH11_B.Saturation_g = CorrienteH11_B.Saturation_j +
    CorrienteH11_DW.Integrator_DSTATE_a;
  if (CorrienteH11_B.Saturation_g > 350.0) {
    CorrienteH11_B.Saturation_g -= 350.0;
  } else if (CorrienteH11_B.Saturation_g >= -350.0) {
    CorrienteH11_B.Saturation_g = 0.0;
  } else {
    CorrienteH11_B.Saturation_g -= -350.0;
  }

  CorrienteH11_B.Saturation_p *= 0.7;
  if (CorrienteH11_B.Saturation_g > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_p > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.Saturation_g != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_p = 0.0;
  }

  Integrator_j_tmp = 0.00025 * CorrienteH11_B.Saturation_p;
  CorrienteH11_B.Integrator_j = Integrator_j_tmp +
    CorrienteH11_DW.Integrator_DSTATE_a;
  if (CorrienteH11_B.Integrator_j > 350.0) {
    CorrienteH11_B.Integrator_j = 350.0;
  } else if (CorrienteH11_B.Integrator_j < -350.0) {
    CorrienteH11_B.Integrator_j = -350.0;
  }

  CorrienteH11_B.Saturation_g = rtu_CorrrienteRef[5] - rtu_I_real_ems[1];
  CorrienteH11_B.Saturation_p = 5.0 * CorrienteH11_B.Saturation_g;
  CorrienteH11_B.Saturation_gq = CorrienteH11_B.Saturation_p +
    CorrienteH11_DW.Integrator_DSTATE_f;
  if (CorrienteH11_B.Saturation_gq > 350.0) {
    CorrienteH11_B.Saturation_gq -= 350.0;
  } else if (CorrienteH11_B.Saturation_gq >= -350.0) {
    CorrienteH11_B.Saturation_gq = 0.0;
  } else {
    CorrienteH11_B.Saturation_gq -= -350.0;
  }

  CorrienteH11_B.Saturation_g *= 0.7;
  if (CorrienteH11_B.Saturation_gq > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_g > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.Saturation_gq != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_g = 0.0;
  }

  Integrator_m_tmp = 0.00025 * CorrienteH11_B.Saturation_g;
  CorrienteH11_B.Integrator_m = Integrator_m_tmp +
    CorrienteH11_DW.Integrator_DSTATE_f;
  if (CorrienteH11_B.Integrator_m > 350.0) {
    CorrienteH11_B.Integrator_m = 350.0;
  } else if (CorrienteH11_B.Integrator_m < -350.0) {
    CorrienteH11_B.Integrator_m = -350.0;
  }

  CorrienteH11_B.Saturation_gq = rtu_CorrrienteRef[6] - rtu_I_real_ems[2];
  CorrienteH11_B.Saturation_g = 5.0 * CorrienteH11_B.Saturation_gq;
  CorrienteH11_B.Saturation_er = CorrienteH11_B.Saturation_g +
    CorrienteH11_DW.Integrator_DSTATE_j;
  if (CorrienteH11_B.Saturation_er > 350.0) {
    CorrienteH11_B.Saturation_er -= 350.0;
  } else if (CorrienteH11_B.Saturation_er >= -350.0) {
    CorrienteH11_B.Saturation_er = 0.0;
  } else {
    CorrienteH11_B.Saturation_er -= -350.0;
  }

  CorrienteH11_B.Saturation_gq *= 0.7;
  if (CorrienteH11_B.Saturation_er > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_gq > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.Saturation_er != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_gq = 0.0;
  }

  Integrator_pj_tmp = 0.00025 * CorrienteH11_B.Saturation_gq;
  CorrienteH11_B.Integrator_pj = Integrator_pj_tmp +
    CorrienteH11_DW.Integrator_DSTATE_j;
  if (CorrienteH11_B.Integrator_pj > 350.0) {
    CorrienteH11_B.Integrator_pj = 350.0;
  } else if (CorrienteH11_B.Integrator_pj < -350.0) {
    CorrienteH11_B.Integrator_pj = -350.0;
  }

  CorrienteH11_B.Saturation_er = rtu_CorrrienteRef[7] - rtu_I_real_ems[3];
  CorrienteH11_B.Saturation_gq = 5.0 * CorrienteH11_B.Saturation_er;
  CorrienteH11_B.Saturation_o = CorrienteH11_B.Saturation_gq +
    CorrienteH11_DW.Integrator_DSTATE_k;
  if (CorrienteH11_B.Saturation_o > 350.0) {
    CorrienteH11_B.Saturation_o -= 350.0;
  } else if (CorrienteH11_B.Saturation_o >= -350.0) {
    CorrienteH11_B.Saturation_o = 0.0;
  } else {
    CorrienteH11_B.Saturation_o -= -350.0;
  }

  CorrienteH11_B.Saturation_er *= 0.7;
  if (CorrienteH11_B.Saturation_o > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_er > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.Saturation_o != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_er = 0.0;
  }

  Integrator_h_tmp = 0.00025 * CorrienteH11_B.Saturation_er;
  CorrienteH11_B.Integrator_h = Integrator_h_tmp +
    CorrienteH11_DW.Integrator_DSTATE_k;
  if (CorrienteH11_B.Integrator_h > 350.0) {
    CorrienteH11_B.Integrator_h = 350.0;
  } else if (CorrienteH11_B.Integrator_h < -350.0) {
    CorrienteH11_B.Integrator_h = -350.0;
  }

  CorrienteH11_B.Saturation_o = rtu_CorrrienteRef[8] - rtu_I_real_ems[4];
  CorrienteH11_B.Saturation_er = 5.0 * CorrienteH11_B.Saturation_o;
  CorrienteH11_B.IntegralGain = CorrienteH11_B.Saturation_er +
    CorrienteH11_DW.Integrator_DSTATE_b;
  if (CorrienteH11_B.IntegralGain > 350.0) {
    CorrienteH11_B.IntegralGain -= 350.0;
  } else if (CorrienteH11_B.IntegralGain >= -350.0) {
    CorrienteH11_B.IntegralGain = 0.0;
  } else {
    CorrienteH11_B.IntegralGain -= -350.0;
  }

  CorrienteH11_B.Saturation_o *= 0.7;
  if (CorrienteH11_B.IntegralGain > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.Saturation_o > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.IntegralGain != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.Saturation_o = 0.0;
  }

  Integrator_l_tmp = 0.00025 * CorrienteH11_B.Saturation_o;
  CorrienteH11_B.Integrator_l = Integrator_l_tmp +
    CorrienteH11_DW.Integrator_DSTATE_b;
  if (CorrienteH11_B.Integrator_l > 350.0) {
    CorrienteH11_B.Integrator_l = 350.0;
  } else if (CorrienteH11_B.Integrator_l < -350.0) {
    CorrienteH11_B.Integrator_l = -350.0;
  }

  CorrienteH11_B.IntegralGain = rtu_CorrrienteRef[9] - rtu_I_real_ems[5];
  CorrienteH11_B.Saturation_o = 5.0 * CorrienteH11_B.IntegralGain;
  CorrienteH11_B.DeadZone = CorrienteH11_B.Saturation_o +
    CorrienteH11_DW.Integrator_DSTATE_j2;
  if (CorrienteH11_B.DeadZone > 350.0) {
    CorrienteH11_B.DeadZone -= 350.0;
  } else if (CorrienteH11_B.DeadZone >= -350.0) {
    CorrienteH11_B.DeadZone = 0.0;
  } else {
    CorrienteH11_B.DeadZone -= -350.0;
  }

  CorrienteH11_B.IntegralGain *= 0.7;
  if (CorrienteH11_B.DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH11_B.IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH11_B.DeadZone != 0.0) && (tmp == tmp_0)) {
    CorrienteH11_B.IntegralGain = 0.0;
  }

  CorrienteH11_B.IntegralGain *= 0.00025;
  CorrienteH11_B.DeadZone = CorrienteH11_B.IntegralGain +
    CorrienteH11_DW.Integrator_DSTATE_j2;
  if (CorrienteH11_B.DeadZone > 350.0) {
    CorrienteH11_B.DeadZone = 350.0;
  } else if (CorrienteH11_B.DeadZone < -350.0) {
    CorrienteH11_B.DeadZone = -350.0;
  }

  CorrienteH11_B.Saturation_j += CorrienteH11_B.Integrator_j;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_EMS[0] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_EMS[0] = -350.0;
  } else {
    rty_V_EMS[0] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_p +
    CorrienteH11_B.Integrator_m;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_EMS[1] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_EMS[1] = -350.0;
  } else {
    rty_V_EMS[1] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_g +
    CorrienteH11_B.Integrator_pj;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_EMS[2] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_EMS[2] = -350.0;
  } else {
    rty_V_EMS[2] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_gq +
    CorrienteH11_B.Integrator_h;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_EMS[3] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_EMS[3] = -350.0;
  } else {
    rty_V_EMS[3] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_er +
    CorrienteH11_B.Integrator_l;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_EMS[4] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_EMS[4] = -350.0;
  } else {
    rty_V_EMS[4] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_o +
    CorrienteH11_B.DeadZone;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_EMS[5] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_EMS[5] = -350.0;
  } else {
    rty_V_EMS[5] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation +
    CorrienteH11_B.Integrator;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_HEMS[0] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_HEMS[0] = -350.0;
  } else {
    rty_V_HEMS[0] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_i +
    CorrienteH11_B.Integrator_f;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_HEMS[1] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_HEMS[1] = -350.0;
  } else {
    rty_V_HEMS[1] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_e +
    CorrienteH11_B.Integrator_p;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_HEMS[2] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_HEMS[2] = -350.0;
  } else {
    rty_V_HEMS[2] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_B.Saturation_j = CorrienteH11_B.Saturation_f +
    CorrienteH11_B.Integrator_k;
  if (CorrienteH11_B.Saturation_j > 350.0) {
    rty_V_HEMS[3] = 350.0;
  } else if (CorrienteH11_B.Saturation_j < -350.0) {
    rty_V_HEMS[3] = -350.0;
  } else {
    rty_V_HEMS[3] = CorrienteH11_B.Saturation_j;
  }

  CorrienteH11_DW.Integrator_DSTATE = CorrienteH11_B.Integrator_tmp +
    CorrienteH11_B.Integrator;
  if (CorrienteH11_DW.Integrator_DSTATE > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_e = CorrienteH11_B.Integrator_f_tmp +
    CorrienteH11_B.Integrator_f;
  if (CorrienteH11_DW.Integrator_DSTATE_e > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_e = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_e < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_e = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_o = Integrator_p_tmp +
    CorrienteH11_B.Integrator_p;
  if (CorrienteH11_DW.Integrator_DSTATE_o > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_o = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_o < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_o = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_m = Integrator_k_tmp +
    CorrienteH11_B.Integrator_k;
  if (CorrienteH11_DW.Integrator_DSTATE_m > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_m = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_m < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_m = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_a = Integrator_j_tmp +
    CorrienteH11_B.Integrator_j;
  if (CorrienteH11_DW.Integrator_DSTATE_a > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_a = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_a < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_a = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_f = Integrator_m_tmp +
    CorrienteH11_B.Integrator_m;
  if (CorrienteH11_DW.Integrator_DSTATE_f > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_f = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_f < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_f = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_j = Integrator_pj_tmp +
    CorrienteH11_B.Integrator_pj;
  if (CorrienteH11_DW.Integrator_DSTATE_j > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_j = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_j < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_j = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_k = Integrator_h_tmp +
    CorrienteH11_B.Integrator_h;
  if (CorrienteH11_DW.Integrator_DSTATE_k > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_k = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_k < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_k = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_b = Integrator_l_tmp +
    CorrienteH11_B.Integrator_l;
  if (CorrienteH11_DW.Integrator_DSTATE_b > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_b = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_b < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_b = -350.0;
  }

  CorrienteH11_DW.Integrator_DSTATE_j2 = CorrienteH11_B.IntegralGain +
    CorrienteH11_B.DeadZone;
  if (CorrienteH11_DW.Integrator_DSTATE_j2 > 350.0) {
    CorrienteH11_DW.Integrator_DSTATE_j2 = 350.0;
  } else if (CorrienteH11_DW.Integrator_DSTATE_j2 < -350.0) {
    CorrienteH11_DW.Integrator_DSTATE_j2 = -350.0;
  }
}

const char_T* CorrienteH11::RT_MODEL_CorrienteH11_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void CorrienteH11::RT_MODEL_CorrienteH11_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** CorrienteH11::RT_MODEL_CorrienteH11_T::getErrorStatusPointer()
  const
{
  return errorStatus;
}

void CorrienteH11::RT_MODEL_CorrienteH11_T::setErrorStatusPointer(const char_T**
  aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

CorrienteH11::CorrienteH11() :
  CorrienteH11_B(),
  CorrienteH11_DW(),
  CorrienteH11_M()
{
}

CorrienteH11::~CorrienteH11() = default;
CorrienteH11::RT_MODEL_CorrienteH11_T * CorrienteH11::getRTM()
{
  return (&CorrienteH11_M);
}
