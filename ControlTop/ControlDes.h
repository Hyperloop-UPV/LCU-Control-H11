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
    real_T gaps_out[8];
    real_T g_e[6];
    real_T EMS_B_ESO_State[6];
    real_T g_v[4];
    real_T b_B[4];
    real_T theta_v[3];
    real_T theta_l[3];
    real_T tau[3];
    real_T work[3];
    real_T vn1[3];
    real_T vn2[3];
    real_T TmpSignalConversionAtBInpor[2];
    real_T TmpSignalConversionAtBInp_l[2];
    real_T TmpSignalConversionAtBIn_lx[2];
    real_T TmpSignalConversionAtBI_lx1[2];
    real_T TmpSignalConversionAtB_lx1d[2];
    real_T TmpSignalConversionAt_lx1de[2];
    real_T TmpSignalConversionA_lx1deh[2];
    real_T TmpSignalConversion_lx1deh0[2];
    real_T TmpSignalConversio_lx1deh0q[2];
    real_T TmpSignalConversi_lx1deh0qz[2];
    real_T y;
    real_T rotz;
    real_T Sat_I_gm;
    real_T Sat_I_j;
    real_T Sat_I_m;
    real_T Sat_I_h;
    real_T Div_p;
    real_T Sat_I_o;
    real_T Sat_I_g;
    real_T Sat_I_b;
    real_T Sat_I_mk;
    real_T Sat_I_mx;
    real_T u0;
    real_T rtb_EMS_A_ESO_State_idx_0;
    real_T rtb_EMS_A_ESO_State_idx_1;
    real_T rtb_EMS_A_ESO_State_idx_2;
    real_T rtb_EMS_A_ESO_State_idx_0_m;
    real_T rtb_EMS_A_ESO_State_idx_1_c;
    real_T rtb_EMS_A_ESO_State_idx_2_k;
    real_T rtb_EMS_A_ESO_State_idx_0_c;
    real_T rtb_EMS_A_ESO_State_idx_1_b;
    real_T rtb_EMS_A_ESO_State_idx_2_p;
    real_T rtb_HEMS_A_ESO_State_idx_1;
    real_T rtb_HEMS_A_ESO_State_idx_2;
    real_T rtb_EMS_A_ESO_State_idx_0_cv;
    real_T rtb_EMS_A_ESO_State_idx_1_f;
    real_T rtb_EMS_A_ESO_State_idx_2_g;
    real_T g_v_idx_0;
    real_T g_v_idx_1;
    real_T g_v_idx_2;
    real_T g_v_idx_3;
    real_T rtb_EMS_B_ESO_State_g;
    real_T rtb_EMS_B_ESO_State_m;
    real_T rtb_EMS_B_ESO_State_n;
    real_T rtb_EMS_B_ESO_State_p;
    real_T rtb_EMS_B_ESO_State_l;
    real_T rtb_EMS_B_ESO_State_j;
    real_T rtb_EMS_B_ESO_State_d;
    real_T rtb_EMS_B_ESO_State_gu;
    real_T rtb_EMS_B_ESO_State_ld;
    real_T rtb_EMS_B_ESO_State_dh;
    real_T g_e_d;
    real_T g_e_l;
    real_T g_e_o;
    real_T rtb_EMS_B_ESO_State_b;
    real_T rtb_EMS_B_ESO_State_nu;
    real_T rtb_EMS_B_ESO_State_bs;
    real_T scale;
    real_T absxk;
    real_T t;
    real_T smax;
    real_T scale_l;
    real_T absxk_h;
    real_T t_b;
    real_T a;
    int32_T i;
    int32_T i_d;
    int32_T rankA;
    uint32_T accumulatedData_tmp;
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
    real_T x1[4];
    real_T x2[4];
    real_T y1[4];
    real_T y2[4];
    boolean_T initialized_not_empty;
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
            rtu_I_Hems[4], const real_T rtu_I_EMS[6], const uint8_T
            *rtu_Ganancia_HEMS, const uint8_T *rtu_Ganancia_EMS, const boolean_T
            *rtu_Vibra, real_T rty_Estados[5], real_T rty_R1[3], real_T rty_R2[3],
            real_T rty_R3[3], real_T rty_R4[3], real_T rty_Fa[4], real_T
            rty_CorrienteDeReferencia[10], real_T rty_airgaps_actuadores[10]);
  ControlDes();
  ~ControlDes();
 private:
  B_ControlDes_T ControlDes_B;
  DW_ControlDes_T ControlDes_DW;
  real_T ControlDes_xnrm2_l2M7eLKH(int32_T n, const real_T x[12], int32_T ix0);
  real_T ControlDes_rt_hypotd(real_T u0, real_T u1);
  void ControlDes_mldivide_l89k28gF(const real_T A[12], const real_T B[4],
    real_T Y[3]);
  RT_MODEL_ControlDes_T ControlDes_M;
};

#endif

