#ifndef CONTROLTOP_H_
#define CONTROLTOP_H_
#include "rtwtypes.h"
#include "ControlTop_types.h"
#include "CorrienteH11.h"
#include "ControlDes.h"

class ControlTop final
{
 public:
  struct B_ControlTop_T {
    real_T TmpRTBAtSwitchInport1[10];
  };

  struct DW_ControlTop_T {
    real_T UnitDelay_DSTATE;
    real_T TmpRTBAtModel1Inport3_Buffer[4];
    real_T TmpRTBAtModel1Inport4_Buffer[6];
    real_T TmpRTBAtSwitchInport1_Buffer0[10];
    real_T ref;
    real_T s;
    real_T c;
    real_T durs[319];
    real_T gains[319];
    real_T sinInc[319];
    real_T cosInc[319];
    uint32_T note_idx;
    uint32_T sample_in_note;
    boolean_T ref_not_empty;
  };

  struct ExtU_ControlTop_T {
    real_T Sensores[8];
    real_T I[10];
    real_T RefZ;
    real_T ManualLevitacin;
    real_T CorrienteManual[10];
    real_T RampaStep;
    real_T enable;
    real_T ABSOLUTECINEMA;
    real_T amp_A;
  };

  struct ExtY_ControlTop_T {
    real_T Voltages[10];
    real_T CorrienteReferencia[10];
    real_T Referencia;
    real_T A[8];
    real_T Estados[5];
    real_T GL[10];
  };

  struct RT_MODEL_ControlTop_T {
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

  ControlTop(ControlTop const&) = delete;
  ControlTop& operator= (ControlTop const&) & = delete;
  ControlTop(ControlTop &&) = delete;
  ControlTop& operator= (ControlTop &&) = delete;
  ControlTop::RT_MODEL_ControlTop_T * getRTM();
  void setExternalInputs(const ExtU_ControlTop_T *pExtU_ControlTop_T)
  {
    ControlTop_U = *pExtU_ControlTop_T;
  }

  const ExtY_ControlTop_T &getExternalOutputs() const
  {
    return ControlTop_Y;
  }

  void initialize();
  void step0();
  void step1();
  static void terminate();
  ControlTop();
  ~ControlTop();
 private:
  ExtU_ControlTop_T ControlTop_U;
  ExtY_ControlTop_T ControlTop_Y;
  B_ControlTop_T ControlTop_B;
  DW_ControlTop_T ControlTop_DW;
  CorrienteH11 ControlDeCorrienteMDLOBJ1;
  ControlDes Model1MDLOBJ2;
  RT_MODEL_ControlTop_T ControlTop_M;
};

#endif

