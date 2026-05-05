#ifndef POSICIONH10_H_
#define POSICIONH10_H_
#include "rtwtypes.h"
#include "PosicionH10_types.h"
#include <cstring>

class PosicionH10 final
{
 public:
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
             rty_I_referencia[4], real_T rty_Pos[5]);
  void step0();
  PosicionH10();
  ~PosicionH10();
 private:
  DW_PosicionH10_T PosicionH10_DW;
  RT_MODEL_PosicionH10_T PosicionH10_M;
};

#endif

