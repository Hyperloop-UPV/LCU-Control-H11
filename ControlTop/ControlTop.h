#ifndef CONTROLTOP_H_
#define CONTROLTOP_H_
#include "rtwtypes.h"
#include "ControlTop_types.h"
#include "CorrienteH10.h"
#include "PosicionH10.h"

class ControlTop final
{
 public:
  struct B_ControlTop_T {
    real_T RT1[4];
    real_T RT_l[4];
    real_T airgaps_actuadores[4];
    real_T ControlPosicin_o2[4];
    real_T estados[5];
  };

  struct DW_ControlTop_T {
    real_T RT1_Buffer0[4];
    real_T RT_Buffer[4];
  };

  struct ExtU_ControlTop_T {
    real_T Sensores[8];
    real_T I_HEMS[4];
    real_T RefZ;
    real_T ManualLevitacin;
    real_T CorrienteManual;
  };

  struct ExtY_ControlTop_T {
    real_T Voltages[10];
    real_T GapsLocales[4];
    real_T Estados[5];
    real_T CorrienteReferencia[4];
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
  CorrienteH10 ControlDeCorrienteMDLOBJ1;
  PosicionH10 ControlPosici_nMDLOBJ2;
  RT_MODEL_ControlTop_T ControlTop_M;
};

#endif

