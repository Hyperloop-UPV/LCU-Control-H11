#ifndef POSICIONH10_H_
#define POSICIONH10_H_
#include "rtwtypes.h"
#include "PosicionH10_types.h"
#include <cstring>

class PosicionH10 final
{
 public:
  struct B_PosicionH10_T {
    real_T b_A[12];
    real_T lower[4];
    real_T upper[4];
  };

  struct DW_PosicionH10_T {
    real_T uz_DSTATE[3];
    real_T Z_DSTATE[3];
    real_T Roll_DSTATE[3];
    real_T Pitch_DSTATE[3];
  };

  struct RT_MODEL_PosicionH10_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  void init();
  PosicionH10(PosicionH10 const&) = delete;
  PosicionH10& operator= (PosicionH10 const&) & = delete;
  PosicionH10(PosicionH10 &&) = delete;
  PosicionH10& operator= (PosicionH10 &&) = delete;
  PosicionH10::RT_MODEL_PosicionH10_T * getRTM();
  void step1(const real_T rtu_airgaps_sensores[8], const real_T *rtu_RefZ, const
             real_T rtu_I_HEMS[4], real_T rty_GapsLoclaes[4], real_T
             rty_I_referencia[4], real_T rty_Pos[5], real_T rty_Fe[3], real_T
             rty_Fa[4], real_T rty_Ef[3], real_T rty_P[3], real_T rty_R[3],
             real_T rty_Zz[3], real_T rty_Fe_L[3]);
  void step0();
  PosicionH10();
  ~PosicionH10();
 private:
  B_PosicionH10_T PosicionH10_B;
  DW_PosicionH10_T PosicionH10_DW;
  void PosicionH10_mldivide_l89k28gF(const real_T A[12], const real_T B[4],
    real_T Y[3]);
  void PosicionH10_local_add_limited(const real_T Fa[4], const real_T step[4],
    const real_T lower[4], const real_T upper[4], real_T Fa_new[4], real_T
    *alpha);
  RT_MODEL_PosicionH10_T PosicionH10_M;
};

#endif

