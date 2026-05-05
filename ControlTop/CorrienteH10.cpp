#include "CorrienteH10.h"
#include "rtwtypes.h"

void CorrienteH10::step(const real_T rtu_CorrienteRefHEMS[4], const real_T
  rtu_I_real_hems[4], real_T rty_V_HEMS[4])
{
  real_T Integrator;
  real_T Integrator_f;
  real_T Integrator_f_tmp;
  real_T Integrator_p;
  real_T Integrator_p_tmp;
  real_T Integrator_tmp;
  real_T rtb_DeadZone;
  int8_T tmp;
  int8_T tmp_0;
  CorrienteH10_B.Saturation_i = rtu_CorrienteRefHEMS[0] - rtu_I_real_hems[0];
  CorrienteH10_B.Saturation = 11.4773 * CorrienteH10_B.Saturation_i;
  CorrienteH10_B.Saturation_e = CorrienteH10_B.Saturation +
    CorrienteH10_DW.Integrator_DSTATE;
  if (CorrienteH10_B.Saturation_e > 350.0) {
    CorrienteH10_B.Saturation_e -= 350.0;
  } else if (CorrienteH10_B.Saturation_e >= -350.0) {
    CorrienteH10_B.Saturation_e = 0.0;
  } else {
    CorrienteH10_B.Saturation_e -= -350.0;
  }

  CorrienteH10_B.Saturation_i *= 208.3333;
  if (CorrienteH10_B.Saturation_e > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH10_B.Saturation_i > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH10_B.Saturation_e != 0.0) && (tmp == tmp_0)) {
    CorrienteH10_B.Saturation_i = 0.0;
  }

  Integrator_tmp = 0.00025 * CorrienteH10_B.Saturation_i;
  Integrator = Integrator_tmp + CorrienteH10_DW.Integrator_DSTATE;
  if (Integrator > 350.0) {
    Integrator = 350.0;
  } else if (Integrator < -350.0) {
    Integrator = -350.0;
  }

  CorrienteH10_B.Saturation_e = rtu_CorrienteRefHEMS[1] - rtu_I_real_hems[1];
  CorrienteH10_B.Saturation_i = 11.4773 * CorrienteH10_B.Saturation_e;
  CorrienteH10_B.Saturation_f = CorrienteH10_B.Saturation_i +
    CorrienteH10_DW.Integrator_DSTATE_e;
  if (CorrienteH10_B.Saturation_f > 350.0) {
    CorrienteH10_B.Saturation_f -= 350.0;
  } else if (CorrienteH10_B.Saturation_f >= -350.0) {
    CorrienteH10_B.Saturation_f = 0.0;
  } else {
    CorrienteH10_B.Saturation_f -= -350.0;
  }

  CorrienteH10_B.Saturation_e *= 208.3333;
  if (CorrienteH10_B.Saturation_f > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH10_B.Saturation_e > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH10_B.Saturation_f != 0.0) && (tmp == tmp_0)) {
    CorrienteH10_B.Saturation_e = 0.0;
  }

  Integrator_f_tmp = 0.00025 * CorrienteH10_B.Saturation_e;
  Integrator_f = Integrator_f_tmp + CorrienteH10_DW.Integrator_DSTATE_e;
  if (Integrator_f > 350.0) {
    Integrator_f = 350.0;
  } else if (Integrator_f < -350.0) {
    Integrator_f = -350.0;
  }

  CorrienteH10_B.Saturation_f = rtu_CorrienteRefHEMS[2] - rtu_I_real_hems[2];
  CorrienteH10_B.Saturation_e = 11.4773 * CorrienteH10_B.Saturation_f;
  CorrienteH10_B.IntegralGain = CorrienteH10_B.Saturation_e +
    CorrienteH10_DW.Integrator_DSTATE_o;
  if (CorrienteH10_B.IntegralGain > 350.0) {
    CorrienteH10_B.IntegralGain -= 350.0;
  } else if (CorrienteH10_B.IntegralGain >= -350.0) {
    CorrienteH10_B.IntegralGain = 0.0;
  } else {
    CorrienteH10_B.IntegralGain -= -350.0;
  }

  CorrienteH10_B.Saturation_f *= 208.3333;
  if (CorrienteH10_B.IntegralGain > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH10_B.Saturation_f > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((CorrienteH10_B.IntegralGain != 0.0) && (tmp == tmp_0)) {
    CorrienteH10_B.Saturation_f = 0.0;
  }

  Integrator_p_tmp = 0.00025 * CorrienteH10_B.Saturation_f;
  Integrator_p = Integrator_p_tmp + CorrienteH10_DW.Integrator_DSTATE_o;
  if (Integrator_p > 350.0) {
    Integrator_p = 350.0;
  } else if (Integrator_p < -350.0) {
    Integrator_p = -350.0;
  }

  CorrienteH10_B.IntegralGain = rtu_CorrienteRefHEMS[3] - rtu_I_real_hems[3];
  CorrienteH10_B.Saturation_f = 11.4773 * CorrienteH10_B.IntegralGain;
  rtb_DeadZone = CorrienteH10_B.Saturation_f +
    CorrienteH10_DW.Integrator_DSTATE_m;
  if (rtb_DeadZone > 350.0) {
    rtb_DeadZone -= 350.0;
  } else if (rtb_DeadZone >= -350.0) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= -350.0;
  }

  CorrienteH10_B.IntegralGain *= 208.3333;
  if (rtb_DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (CorrienteH10_B.IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((rtb_DeadZone != 0.0) && (tmp == tmp_0)) {
    CorrienteH10_B.IntegralGain = 0.0;
  }

  CorrienteH10_B.IntegralGain *= 0.00025;
  rtb_DeadZone = CorrienteH10_B.IntegralGain +
    CorrienteH10_DW.Integrator_DSTATE_m;
  if (rtb_DeadZone > 350.0) {
    rtb_DeadZone = 350.0;
  } else if (rtb_DeadZone < -350.0) {
    rtb_DeadZone = -350.0;
  }

  CorrienteH10_B.Saturation += Integrator;
  if (CorrienteH10_B.Saturation > 350.0) {
    rty_V_HEMS[0] = 350.0;
  } else if (CorrienteH10_B.Saturation < -350.0) {
    rty_V_HEMS[0] = -350.0;
  } else {
    rty_V_HEMS[0] = CorrienteH10_B.Saturation;
  }

  CorrienteH10_B.Saturation = CorrienteH10_B.Saturation_i + Integrator_f;
  if (CorrienteH10_B.Saturation > 350.0) {
    rty_V_HEMS[1] = 350.0;
  } else if (CorrienteH10_B.Saturation < -350.0) {
    rty_V_HEMS[1] = -350.0;
  } else {
    rty_V_HEMS[1] = CorrienteH10_B.Saturation;
  }

  CorrienteH10_B.Saturation = CorrienteH10_B.Saturation_e + Integrator_p;
  if (CorrienteH10_B.Saturation > 350.0) {
    rty_V_HEMS[2] = 350.0;
  } else if (CorrienteH10_B.Saturation < -350.0) {
    rty_V_HEMS[2] = -350.0;
  } else {
    rty_V_HEMS[2] = CorrienteH10_B.Saturation;
  }

  CorrienteH10_B.Saturation = CorrienteH10_B.Saturation_f + rtb_DeadZone;
  if (CorrienteH10_B.Saturation > 350.0) {
    rty_V_HEMS[3] = 350.0;
  } else if (CorrienteH10_B.Saturation < -350.0) {
    rty_V_HEMS[3] = -350.0;
  } else {
    rty_V_HEMS[3] = CorrienteH10_B.Saturation;
  }

  CorrienteH10_DW.Integrator_DSTATE = Integrator_tmp + Integrator;
  if (CorrienteH10_DW.Integrator_DSTATE > 350.0) {
    CorrienteH10_DW.Integrator_DSTATE = 350.0;
  } else if (CorrienteH10_DW.Integrator_DSTATE < -350.0) {
    CorrienteH10_DW.Integrator_DSTATE = -350.0;
  }

  CorrienteH10_DW.Integrator_DSTATE_e = Integrator_f_tmp + Integrator_f;
  if (CorrienteH10_DW.Integrator_DSTATE_e > 350.0) {
    CorrienteH10_DW.Integrator_DSTATE_e = 350.0;
  } else if (CorrienteH10_DW.Integrator_DSTATE_e < -350.0) {
    CorrienteH10_DW.Integrator_DSTATE_e = -350.0;
  }

  CorrienteH10_DW.Integrator_DSTATE_o = Integrator_p_tmp + Integrator_p;
  if (CorrienteH10_DW.Integrator_DSTATE_o > 350.0) {
    CorrienteH10_DW.Integrator_DSTATE_o = 350.0;
  } else if (CorrienteH10_DW.Integrator_DSTATE_o < -350.0) {
    CorrienteH10_DW.Integrator_DSTATE_o = -350.0;
  }

  CorrienteH10_DW.Integrator_DSTATE_m = CorrienteH10_B.IntegralGain +
    rtb_DeadZone;
  if (CorrienteH10_DW.Integrator_DSTATE_m > 350.0) {
    CorrienteH10_DW.Integrator_DSTATE_m = 350.0;
  } else if (CorrienteH10_DW.Integrator_DSTATE_m < -350.0) {
    CorrienteH10_DW.Integrator_DSTATE_m = -350.0;
  }
}

const char_T* CorrienteH10::RT_MODEL_CorrienteH10_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void CorrienteH10::RT_MODEL_CorrienteH10_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** CorrienteH10::RT_MODEL_CorrienteH10_T::getErrorStatusPointer()
  const
{
  return errorStatus;
}

void CorrienteH10::RT_MODEL_CorrienteH10_T::setErrorStatusPointer(const char_T**
  aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

CorrienteH10::CorrienteH10() :
  CorrienteH10_B(),
  CorrienteH10_DW(),
  CorrienteH10_M()
{
}

CorrienteH10::~CorrienteH10() = default;
CorrienteH10::RT_MODEL_CorrienteH10_T * CorrienteH10::getRTM()
{
  return (&CorrienteH10_M);
}
