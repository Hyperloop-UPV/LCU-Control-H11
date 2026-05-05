#ifndef CORRIENTEH10_H_
#define CORRIENTEH10_H_
#include "rtwtypes.h"
#include "CorrienteH10_types.h"
#include <cstring>

class CorrienteH10 final
{
 public:
  struct B_CorrienteH10_T {
    real_T Saturation_i;
    real_T Saturation;
    real_T Saturation_e;
    real_T Saturation_f;
    real_T IntegralGain;
  };

  struct DW_CorrienteH10_T {
    real_T Integrator_DSTATE;
    real_T Integrator_DSTATE_e;
    real_T Integrator_DSTATE_o;
    real_T Integrator_DSTATE_m;
  };

  struct RT_MODEL_CorrienteH10_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  CorrienteH10(CorrienteH10 const&) = delete;
  CorrienteH10& operator= (CorrienteH10 const&) & = delete;
  CorrienteH10(CorrienteH10 &&) = delete;
  CorrienteH10& operator= (CorrienteH10 &&) = delete;
  CorrienteH10::RT_MODEL_CorrienteH10_T * getRTM();
  void step(const real_T rtu_CorrienteRefHEMS[4], const real_T rtu_I_real_hems[4],
            real_T rty_V_HEMS[4]);
  CorrienteH10();
  ~CorrienteH10();
 private:
  B_CorrienteH10_T CorrienteH10_B;
  DW_CorrienteH10_T CorrienteH10_DW;
  RT_MODEL_CorrienteH10_T CorrienteH10_M;
};

#endif

