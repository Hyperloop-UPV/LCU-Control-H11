#include "ControlTop.h"
#include "rtwtypes.h"
#include "CorrienteH10.h"
#include "PosicionH10.h"

void ControlTop::step0()
{
  real_T rtb_ControlDeCorriente[4];
  real_T rtb_Switch[4];
  int32_T i;
  (&ControlTop_M)->Timing.RateInteraction.b_TID0_1 = ((&ControlTop_M)
    ->Timing.RateInteraction.TID0_1 == 0);
  ((&ControlTop_M)->Timing.RateInteraction.TID0_1)++;
  if (((&ControlTop_M)->Timing.RateInteraction.TID0_1) > 1) {
    (&ControlTop_M)->Timing.RateInteraction.TID0_1 = 0;
  }

  if ((&ControlTop_M)->Timing.RateInteraction.TID0_1 == 1) {
    ControlTop_B.RT1[0] = ControlTop_DW.RT1_Buffer0[0];
    ControlTop_B.RT1[1] = ControlTop_DW.RT1_Buffer0[1];
    ControlTop_B.RT1[2] = ControlTop_DW.RT1_Buffer0[2];
    ControlTop_B.RT1[3] = ControlTop_DW.RT1_Buffer0[3];
  }

  if (ControlTop_U.ManualLevitacin >= 0.5) {
    rtb_Switch[0] = ControlTop_B.RT1[0];
    rtb_Switch[1] = ControlTop_B.RT1[1];
    rtb_Switch[2] = ControlTop_B.RT1[2];
    rtb_Switch[3] = ControlTop_B.RT1[3];
  } else {
    rtb_Switch[0] = ControlTop_U.CorrienteManual;
    rtb_Switch[1] = ControlTop_U.CorrienteManual;
    rtb_Switch[2] = ControlTop_U.CorrienteManual;
    rtb_Switch[3] = ControlTop_U.CorrienteManual;
  }

  ControlDeCorrienteMDLOBJ1.step(&rtb_Switch[0], &ControlTop_U.I_HEMS[0],
    &rtb_ControlDeCorriente[0]);
  ControlTop_Y.Voltages[0] = rtb_ControlDeCorriente[0];
  ControlTop_Y.Voltages[1] = rtb_ControlDeCorriente[1];
  ControlTop_Y.Voltages[2] = rtb_ControlDeCorriente[2];
  ControlTop_Y.Voltages[3] = rtb_ControlDeCorriente[3];
  for (i = 0; i < 6; i++) {
    ControlTop_Y.Voltages[i + 4] = 0.0;
  }

  ControlTop_Y.CorrienteReferencia[0] = rtb_Switch[0];
  ControlTop_Y.CorrienteReferencia[1] = rtb_Switch[1];
  ControlTop_Y.CorrienteReferencia[2] = rtb_Switch[2];
  ControlTop_Y.CorrienteReferencia[3] = rtb_Switch[3];
  ControlPosici_nMDLOBJ2.step0();
  if ((&ControlTop_M)->Timing.RateInteraction.TID0_1 == 1) {
    ControlTop_DW.RT_Buffer[0] = ControlTop_U.I_HEMS[0];
    ControlTop_DW.RT_Buffer[1] = ControlTop_U.I_HEMS[1];
    ControlTop_DW.RT_Buffer[2] = ControlTop_U.I_HEMS[2];
    ControlTop_DW.RT_Buffer[3] = ControlTop_U.I_HEMS[3];
  }
}

void ControlTop::step1()
{
  int32_T i;
  ControlTop_B.RT_l[0] = ControlTop_DW.RT_Buffer[0];
  ControlTop_B.RT_l[1] = ControlTop_DW.RT_Buffer[1];
  ControlTop_B.RT_l[2] = ControlTop_DW.RT_Buffer[2];
  ControlTop_B.RT_l[3] = ControlTop_DW.RT_Buffer[3];
  ControlPosici_nMDLOBJ2.step1(&ControlTop_U.Sensores[0], &ControlTop_U.RefZ,
    &ControlTop_B.RT_l[0], &ControlTop_B.airgaps_actuadores[0],
    &ControlTop_B.ControlPosicin_o2[0], &ControlTop_B.estados[0]);
  ControlTop_Y.GapsLocales[0] = ControlTop_B.airgaps_actuadores[0];
  ControlTop_Y.GapsLocales[1] = ControlTop_B.airgaps_actuadores[1];
  ControlTop_Y.GapsLocales[2] = ControlTop_B.airgaps_actuadores[2];
  ControlTop_Y.GapsLocales[3] = ControlTop_B.airgaps_actuadores[3];
  for (i = 0; i < 5; i++) {
    ControlTop_Y.Estados[i] = ControlTop_B.estados[i];
  }

  ControlTop_DW.RT1_Buffer0[0] = ControlTop_B.ControlPosicin_o2[0];
  ControlTop_DW.RT1_Buffer0[1] = ControlTop_B.ControlPosicin_o2[1];
  ControlTop_DW.RT1_Buffer0[2] = ControlTop_B.ControlPosicin_o2[2];
  ControlTop_DW.RT1_Buffer0[3] = ControlTop_B.ControlPosicin_o2[3];
}

void ControlTop::initialize()
{
  ((&ControlTop_M))->Timing.TaskCounters.cLimit[0] = 1;
  ((&ControlTop_M))->Timing.TaskCounters.cLimit[1] = 2;
  ControlDeCorrienteMDLOBJ1.getRTM()->setErrorStatusPointer((&ControlTop_M)
    ->getErrorStatusPointer());
  ControlPosici_nMDLOBJ2.getRTM()->setErrorStatusPointer((&ControlTop_M)
    ->getErrorStatusPointer());
  ControlPosici_nMDLOBJ2.init();
}

void ControlTop::terminate()
{
}

boolean_T ControlTop::RT_MODEL_ControlTop_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

uint32_T &ControlTop::RT_MODEL_ControlTop_T::CounterLimit(int32_T idx)
{
  return (Timing.TaskCounters.cLimit[(idx)]);
}

const char_T* ControlTop::RT_MODEL_ControlTop_T::getErrorStatus() const
{
  return (errorStatus);
}

void ControlTop::RT_MODEL_ControlTop_T::setErrorStatus(const char_T* const
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

uint32_T &ControlTop::RT_MODEL_ControlTop_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

const char_T** ControlTop::RT_MODEL_ControlTop_T::getErrorStatusPointer()
{
  return &errorStatus;
}

ControlTop::ControlTop() :
  ControlTop_U(),
  ControlTop_Y(),
  ControlTop_B(),
  ControlTop_DW(),
  ControlTop_M()
{
}

ControlTop::~ControlTop() = default;
ControlTop::RT_MODEL_ControlTop_T * ControlTop::getRTM()
{
  return (&ControlTop_M);
}
