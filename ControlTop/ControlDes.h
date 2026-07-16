#ifndef CONTROLDES_H_
#define CONTROLDES_H_
#include "rtwtypes.h"
#include "ControlDes_types.h"
#include <cstring>

class ControlDes final
{
 public:
  struct B_ControlDes_T {
    real_T b_A[12];
    real_T g_e[6];
    real_T g_v[4];
    real_T b_B[4];
    real_T theta_v[3];
    real_T theta_l[3];
    real_T tau[3];
    real_T work[3];
    real_T vn1[3];
    real_T vn2[3];
    real_T TmpSignalConversionAtBInpor[2];
    real_T TmpSignalConversionAtBInp_i[2];
    real_T TmpSignalConversionAtBIn_iz[2];
    real_T TmpSignalConversionAtBI_izx[2];
    real_T TmpSignalConversionAtB_izxo[2];
    real_T TmpSignalConversionAt_izxof[2];
    real_T TmpSignalConversionA_izxofb[2];
    real_T TmpSignalConversion_izxofbo[2];
    real_T TmpSignalConversio_izxofbou[2];
    real_T TmpSignalConversi_izxofbouj[2];
    real_T rotz;
    real_T b_accumulatedData;
    real_T Div;
    real_T Sat_I_m;
    real_T Sat_I_h;
    real_T Sat_I_o;
    real_T Sat_I_g;
    real_T Sat_I_b;
    real_T Sat_I_j;
    real_T Sat_I_mk;
    real_T Sat_I_mx;
    real_T u0;
    real_T u0_m;
    real_T d;
    real_T d1;
    real_T d2;
    real_T unnamed_idx_0;
    real_T unnamed_idx_1;
    real_T unnamed_idx_2;
    real_T unnamed_idx_0_c;
    real_T unnamed_idx_1_k;
    real_T unnamed_idx_2_c;
    real_T unnamed_idx_0_b;
    real_T unnamed_idx_1_p;
    real_T unnamed_idx_2_cv;
    real_T unnamed_idx_0_f;
    real_T unnamed_idx_1_g;
    real_T unnamed_idx_2_g;
    real_T unnamed_idx_0_m;
    real_T unnamed_idx_1_n;
    real_T unnamed_idx_2_p;
    real_T unnamed_idx_0_l;
    real_T unnamed_idx_1_j;
    real_T unnamed_idx_2_d;
    real_T g_v_idx_0;
    real_T g_v_idx_1;
    real_T g_v_idx_2;
    real_T g_v_idx_3;
    real_T d3;
    real_T d4;
    real_T d5;
    real_T d6;
    real_T d7;
    real_T d8;
    real_T d9;
    real_T d10;
    real_T d11;
    real_T d12;
    real_T g_v_idx_0_tmp;
    real_T g_v_idx_1_tmp;
    real_T d13;
    real_T scale;
    real_T absxk;
    real_T t;
    real_T smax;
    real_T scale_g;
    real_T absxk_l;
  };

  struct DW_ControlDes_T {
    real_T State_DSTATE[3];
    real_T UnitDelay_DSTATE;
    real_T State_DSTATE_e[3];
    real_T UnitDelay_DSTATE_i;
    real_T State_DSTATE_j[3];
    real_T UnitDelay_DSTATE_m;
    real_T State_DSTATE_k[3];
    real_T UnitDelay_DSTATE_g;
    real_T State_DSTATE_f[3];
    real_T UnitDelay_DSTATE_mu;
    real_T State_DSTATE_g[3];
    real_T UnitDelay_DSTATE_n;
    real_T State_DSTATE_fj[3];
    real_T UnitDelay_DSTATE_gq;
    real_T State_DSTATE_n[3];
    real_T UnitDelay_DSTATE_p;
    real_T State_DSTATE_b[3];
    real_T UnitDelay_DSTATE_ne;
    real_T State_DSTATE_m[3];
    real_T UnitDelay_DSTATE_b;
  };

  struct RT_MODEL_ControlDes_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  void init(real_T rty_R4[3]);
  ControlDes(ControlDes const&) = delete;
  ControlDes& operator= (ControlDes const&) & = delete;
  ControlDes(ControlDes &&) = delete;
  ControlDes& operator= (ControlDes &&) = delete;
  ControlDes::RT_MODEL_ControlDes_T * getRTM();
  void step(const real_T rtu_Sensores[8], const real_T *rtu_RefZ, const real_T
            rtu_I_Hems[4], const real_T rtu_I_EMS[6], real_T rty_Estados[5],
            real_T rty_R1[3], real_T rty_R2[3], real_T rty_R3[3], real_T rty_R4
            [3], real_T rty_Fa[4], real_T rty_CorrienteDeReferencia[10], real_T
            rty_airgaps_actuadores[10]);
  ControlDes();
  ~ControlDes();
 private:
  B_ControlDes_T ControlDes_B;
  DW_ControlDes_T ControlDes_DW;
  real_T ControlDes_xnrm2_l2M7eLKH(int32_T n, const real_T x[12], int32_T ix0);
  void ControlDes_mldivide_l89k28gF(const real_T A[12], const real_T B[4],
    real_T Y[3]);
  RT_MODEL_ControlDes_T ControlDes_M;
};

#endif

