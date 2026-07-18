#ifndef CORRIENTEH11_H_
#define CORRIENTEH11_H_
#include "rtwtypes.h"
#include "CorrienteH11_types.h"
#include <cstring>

class CorrienteH11 final
{
 public:
  struct B_CorrienteH11_T {
    real_T Saturation_i;
    real_T Saturation;
    real_T Saturation_e;
    real_T Saturation_f;
    real_T Saturation_j;
    real_T Saturation_p;
    real_T Saturation_g;
    real_T Saturation_gq;
    real_T Saturation_er;
    real_T Saturation_o;
    real_T IntegralGain;
    real_T DeadZone;
    real_T Integrator;
    real_T Integrator_f;
    real_T Integrator_p;
    real_T Integrator_k;
    real_T Integrator_j;
    real_T Integrator_m;
    real_T Integrator_pj;
    real_T Integrator_h;
    real_T Integrator_l;
    real_T Integrator_tmp;
    real_T Integrator_f_tmp;
  };

  struct DW_CorrienteH11_T {
    real_T Integrator_DSTATE;
    real_T Integrator_DSTATE_e;
    real_T Integrator_DSTATE_o;
    real_T Integrator_DSTATE_m;
    real_T Integrator_DSTATE_a;
    real_T Integrator_DSTATE_f;
    real_T Integrator_DSTATE_j;
    real_T Integrator_DSTATE_k;
    real_T Integrator_DSTATE_b;
    real_T Integrator_DSTATE_j2;
  };

  struct RT_MODEL_CorrienteH11_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  CorrienteH11(CorrienteH11 const&) = delete;
  CorrienteH11& operator= (CorrienteH11 const&) & = delete;
  CorrienteH11(CorrienteH11 &&) = delete;
  CorrienteH11& operator= (CorrienteH11 &&) = delete;
  CorrienteH11::RT_MODEL_CorrienteH11_T * getRTM();
  void step(const real_T rtu_I_real_hems[4], const real_T rtu_I_real_ems[6],
            const real_T rtu_CorrrienteRef[10], real_T rty_V_HEMS[4], real_T
            rty_V_EMS[6]);
  CorrienteH11();
  ~CorrienteH11();
  const DW_CorrienteH11_T& get_dw() const { return CorrienteH11_DW; }
 private:
  B_CorrienteH11_T CorrienteH11_B;
  DW_CorrienteH11_T CorrienteH11_DW;
  RT_MODEL_CorrienteH11_T CorrienteH11_M;
};

#endif

