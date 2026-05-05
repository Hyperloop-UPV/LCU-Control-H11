#include "ControlDeCorrienteH10REF.h"
#include "rtwtypes.h"

void ControlDeCorrienteH10REF::step(const real_T rtu_CorrienteRefHEMS[4], const
  real_T rtu_I_real_hems[4], real_T rty_V_HEMS[4])
{
  real_T Integrator;
  real_T Integrator_j;
  real_T Integrator_j_tmp;
  real_T Integrator_n;
  real_T Integrator_n_tmp;
  real_T Integrator_tmp;
  real_T rtb_DeadZone;
  int8_T tmp;
  int8_T tmp_0;
  ControlDeCorrienteH10REF_B.Saturation_c = rtu_CorrienteRefHEMS[0] -
    rtu_I_real_hems[0];
  ControlDeCorrienteH10REF_B.Saturation = 11.4773 *
    ControlDeCorrienteH10REF_B.Saturation_c;
  ControlDeCorrienteH10REF_B.Saturation_l =
    ControlDeCorrienteH10REF_B.Saturation +
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE;
  if (ControlDeCorrienteH10REF_B.Saturation_l > 400.0) {
    ControlDeCorrienteH10REF_B.Saturation_l -= 400.0;
  } else if (ControlDeCorrienteH10REF_B.Saturation_l >= -400.0) {
    ControlDeCorrienteH10REF_B.Saturation_l = 0.0;
  } else {
    ControlDeCorrienteH10REF_B.Saturation_l -= -400.0;
  }

  ControlDeCorrienteH10REF_B.Saturation_c *= 208.3333;
  if (ControlDeCorrienteH10REF_B.Saturation_l > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (ControlDeCorrienteH10REF_B.Saturation_c > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((ControlDeCorrienteH10REF_B.Saturation_l != 0.0) && (tmp == tmp_0)) {
    ControlDeCorrienteH10REF_B.Saturation_c = 0.0;
  }

  Integrator_tmp = 0.00025 * ControlDeCorrienteH10REF_B.Saturation_c;
  Integrator = Integrator_tmp + ControlDeCorrienteH10REF_DW.Integrator_DSTATE;
  if (Integrator > 400.0) {
    Integrator = 400.0;
  } else if (Integrator < -400.0) {
    Integrator = -400.0;
  }

  ControlDeCorrienteH10REF_B.Saturation_l = rtu_CorrienteRefHEMS[1] -
    rtu_I_real_hems[1];
  ControlDeCorrienteH10REF_B.Saturation_c = 11.4773 *
    ControlDeCorrienteH10REF_B.Saturation_l;
  ControlDeCorrienteH10REF_B.Saturation_b =
    ControlDeCorrienteH10REF_B.Saturation_c +
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o;
  if (ControlDeCorrienteH10REF_B.Saturation_b > 400.0) {
    ControlDeCorrienteH10REF_B.Saturation_b -= 400.0;
  } else if (ControlDeCorrienteH10REF_B.Saturation_b >= -400.0) {
    ControlDeCorrienteH10REF_B.Saturation_b = 0.0;
  } else {
    ControlDeCorrienteH10REF_B.Saturation_b -= -400.0;
  }

  ControlDeCorrienteH10REF_B.Saturation_l *= 208.3333;
  if (ControlDeCorrienteH10REF_B.Saturation_b > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (ControlDeCorrienteH10REF_B.Saturation_l > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((ControlDeCorrienteH10REF_B.Saturation_b != 0.0) && (tmp == tmp_0)) {
    ControlDeCorrienteH10REF_B.Saturation_l = 0.0;
  }

  Integrator_j_tmp = 0.00025 * ControlDeCorrienteH10REF_B.Saturation_l;
  Integrator_j = Integrator_j_tmp +
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o;
  if (Integrator_j > 400.0) {
    Integrator_j = 400.0;
  } else if (Integrator_j < -400.0) {
    Integrator_j = -400.0;
  }

  ControlDeCorrienteH10REF_B.Saturation_b = rtu_CorrienteRefHEMS[2] -
    rtu_I_real_hems[2];
  ControlDeCorrienteH10REF_B.Saturation_l = 11.4773 *
    ControlDeCorrienteH10REF_B.Saturation_b;
  ControlDeCorrienteH10REF_B.IntegralGain =
    ControlDeCorrienteH10REF_B.Saturation_l +
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o2;
  if (ControlDeCorrienteH10REF_B.IntegralGain > 400.0) {
    ControlDeCorrienteH10REF_B.IntegralGain -= 400.0;
  } else if (ControlDeCorrienteH10REF_B.IntegralGain >= -400.0) {
    ControlDeCorrienteH10REF_B.IntegralGain = 0.0;
  } else {
    ControlDeCorrienteH10REF_B.IntegralGain -= -400.0;
  }

  ControlDeCorrienteH10REF_B.Saturation_b *= 208.3333;
  if (ControlDeCorrienteH10REF_B.IntegralGain > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (ControlDeCorrienteH10REF_B.Saturation_b > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((ControlDeCorrienteH10REF_B.IntegralGain != 0.0) && (tmp == tmp_0)) {
    ControlDeCorrienteH10REF_B.Saturation_b = 0.0;
  }

  Integrator_n_tmp = 0.00025 * ControlDeCorrienteH10REF_B.Saturation_b;
  Integrator_n = Integrator_n_tmp +
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o2;
  if (Integrator_n > 400.0) {
    Integrator_n = 400.0;
  } else if (Integrator_n < -400.0) {
    Integrator_n = -400.0;
  }

  ControlDeCorrienteH10REF_B.IntegralGain = rtu_CorrienteRefHEMS[3] -
    rtu_I_real_hems[3];
  ControlDeCorrienteH10REF_B.Saturation_b = 11.4773 *
    ControlDeCorrienteH10REF_B.IntegralGain;
  rtb_DeadZone = ControlDeCorrienteH10REF_B.Saturation_b +
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_oz;
  if (rtb_DeadZone > 400.0) {
    rtb_DeadZone -= 400.0;
  } else if (rtb_DeadZone >= -400.0) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= -400.0;
  }

  ControlDeCorrienteH10REF_B.IntegralGain *= 208.3333;
  if (rtb_DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (ControlDeCorrienteH10REF_B.IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if ((rtb_DeadZone != 0.0) && (tmp == tmp_0)) {
    ControlDeCorrienteH10REF_B.IntegralGain = 0.0;
  }

  ControlDeCorrienteH10REF_B.IntegralGain *= 0.00025;
  rtb_DeadZone = ControlDeCorrienteH10REF_B.IntegralGain +
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_oz;
  if (rtb_DeadZone > 400.0) {
    rtb_DeadZone = 400.0;
  } else if (rtb_DeadZone < -400.0) {
    rtb_DeadZone = -400.0;
  }

  ControlDeCorrienteH10REF_B.Saturation += Integrator;
  if (ControlDeCorrienteH10REF_B.Saturation > 400.0) {
    rty_V_HEMS[0] = 400.0;
  } else if (ControlDeCorrienteH10REF_B.Saturation < -400.0) {
    rty_V_HEMS[0] = -400.0;
  } else {
    rty_V_HEMS[0] = ControlDeCorrienteH10REF_B.Saturation;
  }

  ControlDeCorrienteH10REF_B.Saturation =
    ControlDeCorrienteH10REF_B.Saturation_c + Integrator_j;
  if (ControlDeCorrienteH10REF_B.Saturation > 400.0) {
    rty_V_HEMS[1] = 400.0;
  } else if (ControlDeCorrienteH10REF_B.Saturation < -400.0) {
    rty_V_HEMS[1] = -400.0;
  } else {
    rty_V_HEMS[1] = ControlDeCorrienteH10REF_B.Saturation;
  }

  ControlDeCorrienteH10REF_B.Saturation =
    ControlDeCorrienteH10REF_B.Saturation_l + Integrator_n;
  if (ControlDeCorrienteH10REF_B.Saturation > 400.0) {
    rty_V_HEMS[2] = 400.0;
  } else if (ControlDeCorrienteH10REF_B.Saturation < -400.0) {
    rty_V_HEMS[2] = -400.0;
  } else {
    rty_V_HEMS[2] = ControlDeCorrienteH10REF_B.Saturation;
  }

  ControlDeCorrienteH10REF_B.Saturation =
    ControlDeCorrienteH10REF_B.Saturation_b + rtb_DeadZone;
  if (ControlDeCorrienteH10REF_B.Saturation > 400.0) {
    rty_V_HEMS[3] = 400.0;
  } else if (ControlDeCorrienteH10REF_B.Saturation < -400.0) {
    rty_V_HEMS[3] = -400.0;
  } else {
    rty_V_HEMS[3] = ControlDeCorrienteH10REF_B.Saturation;
  }

  ControlDeCorrienteH10REF_DW.Integrator_DSTATE = Integrator_tmp + Integrator;
  if (ControlDeCorrienteH10REF_DW.Integrator_DSTATE > 400.0) {
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE = 400.0;
  } else if (ControlDeCorrienteH10REF_DW.Integrator_DSTATE < -400.0) {
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE = -400.0;
  }

  ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o = Integrator_j_tmp +
    Integrator_j;
  if (ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o > 400.0) {
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o = 400.0;
  } else if (ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o < -400.0) {
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o = -400.0;
  }

  ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o2 = Integrator_n_tmp +
    Integrator_n;
  if (ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o2 > 400.0) {
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o2 = 400.0;
  } else if (ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o2 < -400.0) {
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_o2 = -400.0;
  }

  ControlDeCorrienteH10REF_DW.Integrator_DSTATE_oz =
    ControlDeCorrienteH10REF_B.IntegralGain + rtb_DeadZone;
  if (ControlDeCorrienteH10REF_DW.Integrator_DSTATE_oz > 400.0) {
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_oz = 400.0;
  } else if (ControlDeCorrienteH10REF_DW.Integrator_DSTATE_oz < -400.0) {
    ControlDeCorrienteH10REF_DW.Integrator_DSTATE_oz = -400.0;
  }
}

const char_T* ControlDeCorrienteH10REF::RT_MODEL_ControlDeCorrienteH1_T::
  getErrorStatus() const
{
  return (*(errorStatus));
}

void ControlDeCorrienteH10REF::RT_MODEL_ControlDeCorrienteH1_T::setErrorStatus(
  const char_T* const aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** ControlDeCorrienteH10REF::RT_MODEL_ControlDeCorrienteH1_T::
  getErrorStatusPointer() const
{
  return errorStatus;
}

void ControlDeCorrienteH10REF::RT_MODEL_ControlDeCorrienteH1_T::
  setErrorStatusPointer(const char_T** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

ControlDeCorrienteH10REF::ControlDeCorrienteH10REF() :
  ControlDeCorrienteH10REF_B(),
  ControlDeCorrienteH10REF_DW(),
  ControlDeCorrienteH10REF_M()
{
}

ControlDeCorrienteH10REF::~ControlDeCorrienteH10REF() = default;
ControlDeCorrienteH10REF::RT_MODEL_ControlDeCorrienteH1_T
  * ControlDeCorrienteH10REF::getRTM()
{
  return (&ControlDeCorrienteH10REF_M);
}
