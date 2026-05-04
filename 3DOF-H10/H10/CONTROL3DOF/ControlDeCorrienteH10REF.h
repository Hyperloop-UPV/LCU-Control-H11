#ifndef CONTROLDECORRIENTEH10REF_H_
#define CONTROLDECORRIENTEH10REF_H_
#include "rtwtypes.h"
#include "ControlDeCorrienteH10REF_types.h"
#include <cstring>

class ControlDeCorrienteH10REF final
{
 public:
  struct B_ControlDeCorrienteH10REF_T {
    real_T Saturation_c;
    real_T Saturation;
    real_T Saturation_l;
    real_T Saturation_b;
    real_T IntegralGain;
  };

  struct DW_ControlDeCorrienteH10REF_T {
    real_T Integrator_DSTATE;
    real_T Integrator_DSTATE_o;
    real_T Integrator_DSTATE_o2;
    real_T Integrator_DSTATE_oz;
  };

  struct RT_MODEL_ControlDeCorrienteH1_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  ControlDeCorrienteH10REF(ControlDeCorrienteH10REF const&) = delete;
  ControlDeCorrienteH10REF& operator= (ControlDeCorrienteH10REF const&) & =
    delete;
  ControlDeCorrienteH10REF(ControlDeCorrienteH10REF &&) = delete;
  ControlDeCorrienteH10REF& operator= (ControlDeCorrienteH10REF &&) = delete;
  ControlDeCorrienteH10REF::RT_MODEL_ControlDeCorrienteH1_T * getRTM();
  void step(const real_T rtu_CorrienteRefHEMS[4], const real_T rtu_I_real_hems[4],
            real_T rty_V_HEMS[4]);
  ControlDeCorrienteH10REF();
  ~ControlDeCorrienteH10REF();
 private:
  B_ControlDeCorrienteH10REF_T ControlDeCorrienteH10REF_B;
  DW_ControlDeCorrienteH10REF_T ControlDeCorrienteH10REF_DW;
  RT_MODEL_ControlDeCorrienteH1_T ControlDeCorrienteH10REF_M;
};

#endif

