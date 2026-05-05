#ifndef CONTROLH10_1_H_
#define CONTROLH10_1_H_
#include "rtwtypes.h"
#include "CONTROLH10_1_types.h"
#include "ControlDeCorrienteH10REF.h"
#include <cstring>

class CONTROLH10_1 final
{
 public:
  struct B_CONTROLH10_1_T {
    real_T b_A[12];
    real_T estados[5];
    real_T RT1[4];
    real_T dv[4];
    real_T b_B[4];
    real_T Switch[4];
    real_T ControlDeCorriente[4];
    real_T q[3];
    real_T Kin_HEMS[3];
    real_T tau[3];
    real_T work[3];
    real_T vn1[3];
    real_T vn2[3];
    real_T rotx;
    real_T rotz;
    real_T rtb_Kin_HEMS_m;
    real_T rtb_Kin_HEMS_c;
    real_T rtb_Kin_HEMS_k;
    real_T rtb_airgaps_actuadores_idx_0;
    real_T rtb_airgaps_actuadores_idx_1;
    real_T rtb_airgaps_actuadores_idx_2;
    real_T rtb_airgaps_actuadores_idx_3;
    real_T unnamed_idx_0_tmp;
    real_T unnamed_idx_1_tmp;
    real_T unnamed_idx_2_tmp;
    real_T unnamed_idx_3_tmp;
    real_T rtb_Kin_HEMS_tmp;
    real_T scale;
    real_T absxk;
    real_T t;
    real_T smax;
    real_T scale_c;
    real_T absxk_b;
  };

  struct DW_CONTROLH10_1_T {
    real_T uz_DSTATE[3];
    real_T Z_DSTATE[3];
    real_T Roll_DSTATE[3];
    real_T Pitch_DSTATE[3];
    real_T RT1_Buffer0[4];
    real_T RT_Buffer[4];
  };

  struct ExtU_CONTROLH10_1_T {
    real_T Sensores[8];
    real_T I_HEMS[4];
    real_T RefZ;
    real_T ManualLevitacin;
    real_T CorrienteManual;
  };

  struct ExtY_CONTROLH10_1_T {
    real_T V[10];
    real_T GapsLoclaes[4];
    real_T Estados[5];
  };

  struct RT_MODEL_CONTROLH10_1_T {
    const char_T *errorStatus;
    struct {
      struct {
        uint32_T TID[2];
        uint32_T cLimit[2];
      } TaskCounters;

      struct {
        uint32_T TID0_1;
        boolean_T b_TID0_1;
      } RateInteraction;
    } Timing;

    boolean_T StepTask(int32_T idx) const;
    uint32_T &CounterLimit(int32_T idx);
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus);
    uint32_T &TaskCounter(int32_T idx);
    const char_T** getErrorStatusPointer();
  };

  CONTROLH10_1(CONTROLH10_1 const&) = delete;
  CONTROLH10_1& operator= (CONTROLH10_1 const&) & = delete;
  CONTROLH10_1(CONTROLH10_1 &&) = delete;
  CONTROLH10_1& operator= (CONTROLH10_1 &&) = delete;
  CONTROLH10_1::RT_MODEL_CONTROLH10_1_T * getRTM();
  void setExternalInputs(const ExtU_CONTROLH10_1_T *pExtU_CONTROLH10_1_T)
  {
    CONTROLH10_1_U = *pExtU_CONTROLH10_1_T;
  }

  const ExtY_CONTROLH10_1_T &getExternalOutputs() const
  {
    return CONTROLH10_1_Y;
  }

  void initialize();
  void step0();
  void step1();
  static void terminate();
  CONTROLH10_1();
  ~CONTROLH10_1();
 private:
  ExtU_CONTROLH10_1_T CONTROLH10_1_U;
  ExtY_CONTROLH10_1_T CONTROLH10_1_Y;
  B_CONTROLH10_1_T CONTROLH10_1_B;
  DW_CONTROLH10_1_T CONTROLH10_1_DW;
  real_T CONTROLH10_1_xnrm2_l2M7eLKH(int32_T n, const real_T x[12], int32_T ix0);
  void CONTROLH10_1_mldivide_l89k28gF(const real_T A[12], const real_T B[4],
    real_T Y[3]);
  ControlDeCorrienteH10REF ControlDeCorrienteMDLOBJ1;
  RT_MODEL_CONTROLH10_1_T CONTROLH10_1_M;
};

#endif

