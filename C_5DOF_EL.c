/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: C_5DOF_EL.c
 *
 * Code generated for Simulink model 'C_5DOF_EL'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Apr 16 14:47:10 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "C_5DOF_EL.h"
#include "rtwtypes.h"
#include <math.h>
#include "C_5DOF_EL_private.h"
#include <string.h>

/* Block signals (default storage) */
B_C_5DOF_EL_T C_5DOF_EL_B;

/* Block states (default storage) */
DW_C_5DOF_EL_T C_5DOF_EL_DW;

/* External inputs (root inport signals with default storage) */
ExtU_C_5DOF_EL_T C_5DOF_EL_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_C_5DOF_EL_T C_5DOF_EL_Y;

/* Real-time model */
static RT_MODEL_C_5DOF_EL_T C_5DOF_EL_M_;
RT_MODEL_C_5DOF_EL_T *const C_5DOF_EL_M = &C_5DOF_EL_M_;
static void rate_monotonic_scheduler(void);
real_T look2_binlcpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 1.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void C_5DOF_EL_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(C_5DOF_EL_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  C_5DOF_EL_M->Timing.RateInteraction.TID0_1 =
    (C_5DOF_EL_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (C_5DOF_EL_M->Timing.TaskCounters.TID[1])++;
  if ((C_5DOF_EL_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    C_5DOF_EL_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void C_5DOF_EL_step0(void)             /* Sample time: [0.0005s, 0.0s] */
{
  real_T Integrator;
  real_T Integrator_a;
  real_T Integrator_a_tmp;
  real_T Integrator_am;
  real_T Integrator_am_tmp;
  real_T Integrator_c;
  real_T Integrator_c_tmp;
  real_T Integrator_f;
  real_T Integrator_f_tmp;
  real_T Integrator_j;
  real_T Integrator_j3;
  real_T Integrator_j3_tmp;
  real_T Integrator_j_tmp;
  real_T Integrator_k;
  real_T Integrator_k_tmp;
  real_T Integrator_l;
  real_T Integrator_l_tmp;
  real_T Integrator_tmp;
  real_T rtb_DeadZone;
  real_T rtb_IntegralGain;
  real_T rtb_Saturation;
  real_T rtb_Saturation_ag;
  real_T rtb_Saturation_b;
  real_T rtb_Saturation_c;
  real_T rtb_Saturation_e;
  real_T rtb_Saturation_gw;
  real_T rtb_Saturation_i5;
  real_T rtb_Saturation_j;
  real_T rtb_Saturation_n;
  real_T rtb_Saturation_og;
  int32_T i;
  int8_T tmp_0;
  int8_T tmp_1;
  boolean_T tmp;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<S6>/RT_Iref_HEMS' incorporates:
   *  RateTransition: '<S4>/RT_Iref_EMS'
   */
  tmp = C_5DOF_EL_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_B.RT_Iref_HEMS[0] = C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[0];
    C_5DOF_EL_B.RT_Iref_HEMS[1] = C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[1];
    C_5DOF_EL_B.RT_Iref_HEMS[2] = C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[2];
    C_5DOF_EL_B.RT_Iref_HEMS[3] = C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[3];
  }

  /* End of RateTransition: '<S6>/RT_Iref_HEMS' */

  /* Gain: '<S385>/Proportional Gain' incorporates:
   *  Sum: '<S6>/Sum'
   */
  rtb_Saturation = 22.9546 * C_5DOF_EL_B.RT_Iref_HEMS[0];

  /* Sum: '<S390>/Sum Fdbk' */
  rtb_Saturation_n = rtb_Saturation + C_5DOF_EL_DW.Integrator_DSTATE;

  /* DeadZone: '<S372>/DeadZone' */
  if (rtb_Saturation_n > 400.0) {
    rtb_Saturation_n -= 400.0;
  } else if (rtb_Saturation_n >= -400.0) {
    rtb_Saturation_n = 0.0;
  } else {
    rtb_Saturation_n -= -400.0;
  }

  /* End of DeadZone: '<S372>/DeadZone' */

  /* Gain: '<S377>/Integral Gain' incorporates:
   *  Sum: '<S6>/Sum'
   */
  rtb_Saturation_ag = 208.3333 * C_5DOF_EL_B.RT_Iref_HEMS[0];

  /* Switch: '<S370>/Switch1' incorporates:
   *  Constant: '<S370>/Clamping_zero'
   *  Constant: '<S370>/Constant'
   *  Constant: '<S370>/Constant2'
   *  RelationalOperator: '<S370>/fix for DT propagation issue'
   */
  if (rtb_Saturation_n > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S370>/Switch2' incorporates:
   *  Constant: '<S370>/Clamping_zero'
   *  Constant: '<S370>/Constant3'
   *  Constant: '<S370>/Constant4'
   *  RelationalOperator: '<S370>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_ag > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S370>/Switch' incorporates:
   *  Constant: '<S370>/Clamping_zero'
   *  Constant: '<S370>/Constant1'
   *  Logic: '<S370>/AND3'
   *  RelationalOperator: '<S370>/Equal1'
   *  RelationalOperator: '<S370>/Relational Operator'
   *  Switch: '<S370>/Switch1'
   *  Switch: '<S370>/Switch2'
   */
  if ((rtb_Saturation_n != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_ag = 0.0;
  }

  /* End of Switch: '<S370>/Switch' */

  /* DiscreteIntegrator: '<S380>/Integrator' */
  Integrator_tmp = 0.00025 * rtb_Saturation_ag;

  /* DiscreteIntegrator: '<S380>/Integrator' */
  Integrator = Integrator_tmp + C_5DOF_EL_DW.Integrator_DSTATE;

  /* DiscreteIntegrator: '<S380>/Integrator' */
  if (Integrator > 400.0) {
    /* DiscreteIntegrator: '<S380>/Integrator' */
    Integrator = 400.0;
  } else if (Integrator < -400.0) {
    /* DiscreteIntegrator: '<S380>/Integrator' */
    Integrator = -400.0;
  }

  /* Gain: '<S439>/Proportional Gain' incorporates:
   *  Sum: '<S6>/Sum1'
   */
  rtb_Saturation_ag = 22.9546 * C_5DOF_EL_B.RT_Iref_HEMS[1];

  /* Sum: '<S444>/Sum Fdbk' */
  rtb_Saturation_j = rtb_Saturation_ag + C_5DOF_EL_DW.Integrator_DSTATE_b;

  /* DeadZone: '<S426>/DeadZone' */
  if (rtb_Saturation_j > 400.0) {
    rtb_Saturation_j -= 400.0;
  } else if (rtb_Saturation_j >= -400.0) {
    rtb_Saturation_j = 0.0;
  } else {
    rtb_Saturation_j -= -400.0;
  }

  /* End of DeadZone: '<S426>/DeadZone' */

  /* Gain: '<S431>/Integral Gain' incorporates:
   *  Sum: '<S6>/Sum1'
   */
  rtb_Saturation_n = 208.3333 * C_5DOF_EL_B.RT_Iref_HEMS[1];

  /* Switch: '<S424>/Switch1' incorporates:
   *  Constant: '<S424>/Clamping_zero'
   *  Constant: '<S424>/Constant'
   *  Constant: '<S424>/Constant2'
   *  RelationalOperator: '<S424>/fix for DT propagation issue'
   */
  if (rtb_Saturation_j > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S424>/Switch2' incorporates:
   *  Constant: '<S424>/Clamping_zero'
   *  Constant: '<S424>/Constant3'
   *  Constant: '<S424>/Constant4'
   *  RelationalOperator: '<S424>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_n > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S424>/Switch' incorporates:
   *  Constant: '<S424>/Clamping_zero'
   *  Constant: '<S424>/Constant1'
   *  Logic: '<S424>/AND3'
   *  RelationalOperator: '<S424>/Equal1'
   *  RelationalOperator: '<S424>/Relational Operator'
   *  Switch: '<S424>/Switch1'
   *  Switch: '<S424>/Switch2'
   */
  if ((rtb_Saturation_j != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_n = 0.0;
  }

  /* End of Switch: '<S424>/Switch' */

  /* DiscreteIntegrator: '<S434>/Integrator' */
  Integrator_k_tmp = 0.00025 * rtb_Saturation_n;

  /* DiscreteIntegrator: '<S434>/Integrator' */
  Integrator_k = Integrator_k_tmp + C_5DOF_EL_DW.Integrator_DSTATE_b;

  /* DiscreteIntegrator: '<S434>/Integrator' */
  if (Integrator_k > 400.0) {
    /* DiscreteIntegrator: '<S434>/Integrator' */
    Integrator_k = 400.0;
  } else if (Integrator_k < -400.0) {
    /* DiscreteIntegrator: '<S434>/Integrator' */
    Integrator_k = -400.0;
  }

  /* Gain: '<S493>/Proportional Gain' incorporates:
   *  Sum: '<S6>/Sum2'
   */
  rtb_Saturation_n = 22.9546 * C_5DOF_EL_B.RT_Iref_HEMS[2];

  /* Sum: '<S498>/Sum Fdbk' */
  rtb_Saturation_og = rtb_Saturation_n + C_5DOF_EL_DW.Integrator_DSTATE_n;

  /* DeadZone: '<S480>/DeadZone' */
  if (rtb_Saturation_og > 400.0) {
    rtb_Saturation_og -= 400.0;
  } else if (rtb_Saturation_og >= -400.0) {
    rtb_Saturation_og = 0.0;
  } else {
    rtb_Saturation_og -= -400.0;
  }

  /* End of DeadZone: '<S480>/DeadZone' */

  /* Gain: '<S485>/Integral Gain' incorporates:
   *  Sum: '<S6>/Sum2'
   */
  rtb_Saturation_j = 208.3333 * C_5DOF_EL_B.RT_Iref_HEMS[2];

  /* Switch: '<S478>/Switch1' incorporates:
   *  Constant: '<S478>/Clamping_zero'
   *  Constant: '<S478>/Constant'
   *  Constant: '<S478>/Constant2'
   *  RelationalOperator: '<S478>/fix for DT propagation issue'
   */
  if (rtb_Saturation_og > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S478>/Switch2' incorporates:
   *  Constant: '<S478>/Clamping_zero'
   *  Constant: '<S478>/Constant3'
   *  Constant: '<S478>/Constant4'
   *  RelationalOperator: '<S478>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_j > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S478>/Switch' incorporates:
   *  Constant: '<S478>/Clamping_zero'
   *  Constant: '<S478>/Constant1'
   *  Logic: '<S478>/AND3'
   *  RelationalOperator: '<S478>/Equal1'
   *  RelationalOperator: '<S478>/Relational Operator'
   *  Switch: '<S478>/Switch1'
   *  Switch: '<S478>/Switch2'
   */
  if ((rtb_Saturation_og != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_j = 0.0;
  }

  /* End of Switch: '<S478>/Switch' */

  /* DiscreteIntegrator: '<S488>/Integrator' */
  Integrator_c_tmp = 0.00025 * rtb_Saturation_j;

  /* DiscreteIntegrator: '<S488>/Integrator' */
  Integrator_c = Integrator_c_tmp + C_5DOF_EL_DW.Integrator_DSTATE_n;

  /* DiscreteIntegrator: '<S488>/Integrator' */
  if (Integrator_c > 400.0) {
    /* DiscreteIntegrator: '<S488>/Integrator' */
    Integrator_c = 400.0;
  } else if (Integrator_c < -400.0) {
    /* DiscreteIntegrator: '<S488>/Integrator' */
    Integrator_c = -400.0;
  }

  /* Gain: '<S547>/Proportional Gain' incorporates:
   *  Sum: '<S6>/Sum3'
   */
  rtb_Saturation_j = 22.9546 * C_5DOF_EL_B.RT_Iref_HEMS[3];

  /* Sum: '<S552>/Sum Fdbk' */
  rtb_Saturation_i5 = rtb_Saturation_j + C_5DOF_EL_DW.Integrator_DSTATE_e;

  /* DeadZone: '<S534>/DeadZone' */
  if (rtb_Saturation_i5 > 400.0) {
    rtb_Saturation_i5 -= 400.0;
  } else if (rtb_Saturation_i5 >= -400.0) {
    rtb_Saturation_i5 = 0.0;
  } else {
    rtb_Saturation_i5 -= -400.0;
  }

  /* End of DeadZone: '<S534>/DeadZone' */

  /* Gain: '<S539>/Integral Gain' incorporates:
   *  Sum: '<S6>/Sum3'
   */
  rtb_Saturation_og = 208.3333 * C_5DOF_EL_B.RT_Iref_HEMS[3];

  /* Switch: '<S532>/Switch1' incorporates:
   *  Constant: '<S532>/Clamping_zero'
   *  Constant: '<S532>/Constant'
   *  Constant: '<S532>/Constant2'
   *  RelationalOperator: '<S532>/fix for DT propagation issue'
   */
  if (rtb_Saturation_i5 > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S532>/Switch2' incorporates:
   *  Constant: '<S532>/Clamping_zero'
   *  Constant: '<S532>/Constant3'
   *  Constant: '<S532>/Constant4'
   *  RelationalOperator: '<S532>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_og > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S532>/Switch' incorporates:
   *  Constant: '<S532>/Clamping_zero'
   *  Constant: '<S532>/Constant1'
   *  Logic: '<S532>/AND3'
   *  RelationalOperator: '<S532>/Equal1'
   *  RelationalOperator: '<S532>/Relational Operator'
   *  Switch: '<S532>/Switch1'
   *  Switch: '<S532>/Switch2'
   */
  if ((rtb_Saturation_i5 != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_og = 0.0;
  }

  /* End of Switch: '<S532>/Switch' */

  /* DiscreteIntegrator: '<S542>/Integrator' */
  Integrator_a_tmp = 0.00025 * rtb_Saturation_og;

  /* DiscreteIntegrator: '<S542>/Integrator' */
  Integrator_a = Integrator_a_tmp + C_5DOF_EL_DW.Integrator_DSTATE_e;

  /* DiscreteIntegrator: '<S542>/Integrator' */
  if (Integrator_a > 400.0) {
    /* DiscreteIntegrator: '<S542>/Integrator' */
    Integrator_a = 400.0;
  } else if (Integrator_a < -400.0) {
    /* DiscreteIntegrator: '<S542>/Integrator' */
    Integrator_a = -400.0;
  }

  /* RateTransition: '<S4>/RT_Iref_EMS' */
  if (tmp) {
    /* RateTransition: '<S4>/RT_Iref_EMS' */
    for (i = 0; i < 6; i++) {
      C_5DOF_EL_B.RT_Iref_EMS[i] = C_5DOF_EL_DW.RT_Iref_EMS_Buffer0[i];
    }

    /* End of RateTransition: '<S4>/RT_Iref_EMS' */
  }

  /* Gain: '<S56>/Proportional Gain' incorporates:
   *  Sum: '<S4>/Sum'
   */
  rtb_Saturation_og = 0.5039 * C_5DOF_EL_B.RT_Iref_EMS[0];

  /* Sum: '<S61>/Sum Fdbk' */
  rtb_Saturation_gw = rtb_Saturation_og + C_5DOF_EL_DW.Integrator_DSTATE_i;

  /* DeadZone: '<S43>/DeadZone' */
  if (rtb_Saturation_gw > 400.0) {
    rtb_Saturation_gw -= 400.0;
  } else if (rtb_Saturation_gw >= -400.0) {
    rtb_Saturation_gw = 0.0;
  } else {
    rtb_Saturation_gw -= -400.0;
  }

  /* End of DeadZone: '<S43>/DeadZone' */

  /* Gain: '<S48>/Integral Gain' incorporates:
   *  Sum: '<S4>/Sum'
   */
  rtb_Saturation_i5 = 416.6667 * C_5DOF_EL_B.RT_Iref_EMS[0];

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S41>/Clamping_zero'
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant2'
   *  RelationalOperator: '<S41>/fix for DT propagation issue'
   */
  if (rtb_Saturation_gw > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S41>/Clamping_zero'
   *  Constant: '<S41>/Constant3'
   *  Constant: '<S41>/Constant4'
   *  RelationalOperator: '<S41>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_i5 > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Clamping_zero'
   *  Constant: '<S41>/Constant1'
   *  Logic: '<S41>/AND3'
   *  RelationalOperator: '<S41>/Equal1'
   *  RelationalOperator: '<S41>/Relational Operator'
   *  Switch: '<S41>/Switch1'
   *  Switch: '<S41>/Switch2'
   */
  if ((rtb_Saturation_gw != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_i5 = 0.0;
  }

  /* End of Switch: '<S41>/Switch' */

  /* DiscreteIntegrator: '<S51>/Integrator' */
  Integrator_f_tmp = 0.00025 * rtb_Saturation_i5;

  /* DiscreteIntegrator: '<S51>/Integrator' */
  Integrator_f = Integrator_f_tmp + C_5DOF_EL_DW.Integrator_DSTATE_i;

  /* DiscreteIntegrator: '<S51>/Integrator' */
  if (Integrator_f > 400.0) {
    /* DiscreteIntegrator: '<S51>/Integrator' */
    Integrator_f = 400.0;
  } else if (Integrator_f < -400.0) {
    /* DiscreteIntegrator: '<S51>/Integrator' */
    Integrator_f = -400.0;
  }

  /* Gain: '<S110>/Proportional Gain' incorporates:
   *  Sum: '<S4>/Sum1'
   */
  rtb_Saturation_i5 = 0.5039 * C_5DOF_EL_B.RT_Iref_EMS[1];

  /* Sum: '<S115>/Sum Fdbk' */
  rtb_Saturation_b = rtb_Saturation_i5 + C_5DOF_EL_DW.Integrator_DSTATE_e2;

  /* DeadZone: '<S97>/DeadZone' */
  if (rtb_Saturation_b > 400.0) {
    rtb_Saturation_b -= 400.0;
  } else if (rtb_Saturation_b >= -400.0) {
    rtb_Saturation_b = 0.0;
  } else {
    rtb_Saturation_b -= -400.0;
  }

  /* End of DeadZone: '<S97>/DeadZone' */

  /* Gain: '<S102>/Integral Gain' incorporates:
   *  Sum: '<S4>/Sum1'
   */
  rtb_Saturation_gw = 416.6667 * C_5DOF_EL_B.RT_Iref_EMS[1];

  /* Switch: '<S95>/Switch1' incorporates:
   *  Constant: '<S95>/Clamping_zero'
   *  Constant: '<S95>/Constant'
   *  Constant: '<S95>/Constant2'
   *  RelationalOperator: '<S95>/fix for DT propagation issue'
   */
  if (rtb_Saturation_b > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S95>/Switch2' incorporates:
   *  Constant: '<S95>/Clamping_zero'
   *  Constant: '<S95>/Constant3'
   *  Constant: '<S95>/Constant4'
   *  RelationalOperator: '<S95>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_gw > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S95>/Clamping_zero'
   *  Constant: '<S95>/Constant1'
   *  Logic: '<S95>/AND3'
   *  RelationalOperator: '<S95>/Equal1'
   *  RelationalOperator: '<S95>/Relational Operator'
   *  Switch: '<S95>/Switch1'
   *  Switch: '<S95>/Switch2'
   */
  if ((rtb_Saturation_b != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_gw = 0.0;
  }

  /* End of Switch: '<S95>/Switch' */

  /* DiscreteIntegrator: '<S105>/Integrator' */
  Integrator_j_tmp = 0.00025 * rtb_Saturation_gw;

  /* DiscreteIntegrator: '<S105>/Integrator' */
  Integrator_j = Integrator_j_tmp + C_5DOF_EL_DW.Integrator_DSTATE_e2;

  /* DiscreteIntegrator: '<S105>/Integrator' */
  if (Integrator_j > 400.0) {
    /* DiscreteIntegrator: '<S105>/Integrator' */
    Integrator_j = 400.0;
  } else if (Integrator_j < -400.0) {
    /* DiscreteIntegrator: '<S105>/Integrator' */
    Integrator_j = -400.0;
  }

  /* Gain: '<S164>/Proportional Gain' incorporates:
   *  Sum: '<S4>/Sum2'
   */
  rtb_Saturation_gw = 0.5039 * C_5DOF_EL_B.RT_Iref_EMS[2];

  /* Sum: '<S169>/Sum Fdbk' */
  rtb_Saturation_c = rtb_Saturation_gw + C_5DOF_EL_DW.Integrator_DSTATE_p;

  /* DeadZone: '<S151>/DeadZone' */
  if (rtb_Saturation_c > 400.0) {
    rtb_Saturation_c -= 400.0;
  } else if (rtb_Saturation_c >= -400.0) {
    rtb_Saturation_c = 0.0;
  } else {
    rtb_Saturation_c -= -400.0;
  }

  /* End of DeadZone: '<S151>/DeadZone' */

  /* Gain: '<S156>/Integral Gain' incorporates:
   *  Sum: '<S4>/Sum2'
   */
  rtb_Saturation_b = 416.6667 * C_5DOF_EL_B.RT_Iref_EMS[2];

  /* Switch: '<S149>/Switch1' incorporates:
   *  Constant: '<S149>/Clamping_zero'
   *  Constant: '<S149>/Constant'
   *  Constant: '<S149>/Constant2'
   *  RelationalOperator: '<S149>/fix for DT propagation issue'
   */
  if (rtb_Saturation_c > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S149>/Switch2' incorporates:
   *  Constant: '<S149>/Clamping_zero'
   *  Constant: '<S149>/Constant3'
   *  Constant: '<S149>/Constant4'
   *  RelationalOperator: '<S149>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_b > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S149>/Clamping_zero'
   *  Constant: '<S149>/Constant1'
   *  Logic: '<S149>/AND3'
   *  RelationalOperator: '<S149>/Equal1'
   *  RelationalOperator: '<S149>/Relational Operator'
   *  Switch: '<S149>/Switch1'
   *  Switch: '<S149>/Switch2'
   */
  if ((rtb_Saturation_c != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_b = 0.0;
  }

  /* End of Switch: '<S149>/Switch' */

  /* DiscreteIntegrator: '<S159>/Integrator' */
  Integrator_am_tmp = 0.00025 * rtb_Saturation_b;

  /* DiscreteIntegrator: '<S159>/Integrator' */
  Integrator_am = Integrator_am_tmp + C_5DOF_EL_DW.Integrator_DSTATE_p;

  /* DiscreteIntegrator: '<S159>/Integrator' */
  if (Integrator_am > 400.0) {
    /* DiscreteIntegrator: '<S159>/Integrator' */
    Integrator_am = 400.0;
  } else if (Integrator_am < -400.0) {
    /* DiscreteIntegrator: '<S159>/Integrator' */
    Integrator_am = -400.0;
  }

  /* Gain: '<S218>/Proportional Gain' incorporates:
   *  Sum: '<S4>/Sum3'
   */
  rtb_Saturation_b = 0.5039 * C_5DOF_EL_B.RT_Iref_EMS[3];

  /* Sum: '<S223>/Sum Fdbk' */
  rtb_Saturation_e = rtb_Saturation_b + C_5DOF_EL_DW.Integrator_DSTATE_l;

  /* DeadZone: '<S205>/DeadZone' */
  if (rtb_Saturation_e > 400.0) {
    rtb_Saturation_e -= 400.0;
  } else if (rtb_Saturation_e >= -400.0) {
    rtb_Saturation_e = 0.0;
  } else {
    rtb_Saturation_e -= -400.0;
  }

  /* End of DeadZone: '<S205>/DeadZone' */

  /* Gain: '<S210>/Integral Gain' incorporates:
   *  Sum: '<S4>/Sum3'
   */
  rtb_Saturation_c = 416.6667 * C_5DOF_EL_B.RT_Iref_EMS[3];

  /* Switch: '<S203>/Switch1' incorporates:
   *  Constant: '<S203>/Clamping_zero'
   *  Constant: '<S203>/Constant'
   *  Constant: '<S203>/Constant2'
   *  RelationalOperator: '<S203>/fix for DT propagation issue'
   */
  if (rtb_Saturation_e > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S203>/Switch2' incorporates:
   *  Constant: '<S203>/Clamping_zero'
   *  Constant: '<S203>/Constant3'
   *  Constant: '<S203>/Constant4'
   *  RelationalOperator: '<S203>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_c > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S203>/Switch' incorporates:
   *  Constant: '<S203>/Clamping_zero'
   *  Constant: '<S203>/Constant1'
   *  Logic: '<S203>/AND3'
   *  RelationalOperator: '<S203>/Equal1'
   *  RelationalOperator: '<S203>/Relational Operator'
   *  Switch: '<S203>/Switch1'
   *  Switch: '<S203>/Switch2'
   */
  if ((rtb_Saturation_e != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_c = 0.0;
  }

  /* End of Switch: '<S203>/Switch' */

  /* DiscreteIntegrator: '<S213>/Integrator' */
  Integrator_l_tmp = 0.00025 * rtb_Saturation_c;

  /* DiscreteIntegrator: '<S213>/Integrator' */
  Integrator_l = Integrator_l_tmp + C_5DOF_EL_DW.Integrator_DSTATE_l;

  /* DiscreteIntegrator: '<S213>/Integrator' */
  if (Integrator_l > 400.0) {
    /* DiscreteIntegrator: '<S213>/Integrator' */
    Integrator_l = 400.0;
  } else if (Integrator_l < -400.0) {
    /* DiscreteIntegrator: '<S213>/Integrator' */
    Integrator_l = -400.0;
  }

  /* Gain: '<S272>/Proportional Gain' incorporates:
   *  Sum: '<S4>/Sum4'
   */
  rtb_Saturation_c = 0.5039 * C_5DOF_EL_B.RT_Iref_EMS[4];

  /* Sum: '<S277>/Sum Fdbk' */
  rtb_IntegralGain = rtb_Saturation_c + C_5DOF_EL_DW.Integrator_DSTATE_g;

  /* DeadZone: '<S259>/DeadZone' */
  if (rtb_IntegralGain > 400.0) {
    rtb_IntegralGain -= 400.0;
  } else if (rtb_IntegralGain >= -400.0) {
    rtb_IntegralGain = 0.0;
  } else {
    rtb_IntegralGain -= -400.0;
  }

  /* End of DeadZone: '<S259>/DeadZone' */

  /* Gain: '<S264>/Integral Gain' incorporates:
   *  Sum: '<S4>/Sum4'
   */
  rtb_Saturation_e = 416.6667 * C_5DOF_EL_B.RT_Iref_EMS[4];

  /* Switch: '<S257>/Switch1' incorporates:
   *  Constant: '<S257>/Clamping_zero'
   *  Constant: '<S257>/Constant'
   *  Constant: '<S257>/Constant2'
   *  RelationalOperator: '<S257>/fix for DT propagation issue'
   */
  if (rtb_IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S257>/Switch2' incorporates:
   *  Constant: '<S257>/Clamping_zero'
   *  Constant: '<S257>/Constant3'
   *  Constant: '<S257>/Constant4'
   *  RelationalOperator: '<S257>/fix for DT propagation issue1'
   */
  if (rtb_Saturation_e > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S257>/Switch' incorporates:
   *  Constant: '<S257>/Clamping_zero'
   *  Constant: '<S257>/Constant1'
   *  Logic: '<S257>/AND3'
   *  RelationalOperator: '<S257>/Equal1'
   *  RelationalOperator: '<S257>/Relational Operator'
   *  Switch: '<S257>/Switch1'
   *  Switch: '<S257>/Switch2'
   */
  if ((rtb_IntegralGain != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Saturation_e = 0.0;
  }

  /* End of Switch: '<S257>/Switch' */

  /* DiscreteIntegrator: '<S267>/Integrator' */
  Integrator_j3_tmp = 0.00025 * rtb_Saturation_e;

  /* DiscreteIntegrator: '<S267>/Integrator' */
  Integrator_j3 = Integrator_j3_tmp + C_5DOF_EL_DW.Integrator_DSTATE_g;

  /* DiscreteIntegrator: '<S267>/Integrator' */
  if (Integrator_j3 > 400.0) {
    /* DiscreteIntegrator: '<S267>/Integrator' */
    Integrator_j3 = 400.0;
  } else if (Integrator_j3 < -400.0) {
    /* DiscreteIntegrator: '<S267>/Integrator' */
    Integrator_j3 = -400.0;
  }

  /* Gain: '<S326>/Proportional Gain' incorporates:
   *  Sum: '<S4>/Sum5'
   */
  rtb_Saturation_e = 0.5039 * C_5DOF_EL_B.RT_Iref_EMS[5];

  /* Sum: '<S331>/Sum Fdbk' */
  rtb_DeadZone = rtb_Saturation_e + C_5DOF_EL_DW.Integrator_DSTATE_be;

  /* DeadZone: '<S313>/DeadZone' */
  if (rtb_DeadZone > 400.0) {
    rtb_DeadZone -= 400.0;
  } else if (rtb_DeadZone >= -400.0) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= -400.0;
  }

  /* End of DeadZone: '<S313>/DeadZone' */

  /* Gain: '<S318>/Integral Gain' incorporates:
   *  Sum: '<S4>/Sum5'
   */
  rtb_IntegralGain = 416.6667 * C_5DOF_EL_B.RT_Iref_EMS[5];

  /* Switch: '<S311>/Switch1' incorporates:
   *  Constant: '<S311>/Clamping_zero'
   *  Constant: '<S311>/Constant'
   *  Constant: '<S311>/Constant2'
   *  RelationalOperator: '<S311>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S311>/Switch2' incorporates:
   *  Constant: '<S311>/Clamping_zero'
   *  Constant: '<S311>/Constant3'
   *  Constant: '<S311>/Constant4'
   *  RelationalOperator: '<S311>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S311>/Switch' incorporates:
   *  Constant: '<S311>/Clamping_zero'
   *  Constant: '<S311>/Constant1'
   *  Logic: '<S311>/AND3'
   *  RelationalOperator: '<S311>/Equal1'
   *  RelationalOperator: '<S311>/Relational Operator'
   *  Switch: '<S311>/Switch1'
   *  Switch: '<S311>/Switch2'
   */
  if ((rtb_DeadZone != 0.0) && (tmp_0 == tmp_1)) {
    rtb_IntegralGain = 0.0;
  }

  /* End of Switch: '<S311>/Switch' */

  /* DiscreteIntegrator: '<S321>/Integrator' */
  rtb_IntegralGain *= 0.00025;

  /* DiscreteIntegrator: '<S321>/Integrator' */
  rtb_DeadZone = rtb_IntegralGain + C_5DOF_EL_DW.Integrator_DSTATE_be;

  /* DiscreteIntegrator: '<S321>/Integrator' */
  if (rtb_DeadZone > 400.0) {
    /* DiscreteIntegrator: '<S321>/Integrator' */
    rtb_DeadZone = 400.0;
  } else if (rtb_DeadZone < -400.0) {
    /* DiscreteIntegrator: '<S321>/Integrator' */
    rtb_DeadZone = -400.0;
  }

  /* Sum: '<S389>/Sum' */
  rtb_Saturation += Integrator;

  /* Saturate: '<S387>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[0] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[0] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[0] = rtb_Saturation;
  }

  /* End of Saturate: '<S387>/Saturation' */

  /* Sum: '<S443>/Sum' */
  rtb_Saturation = rtb_Saturation_ag + Integrator_k;

  /* Saturate: '<S441>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[1] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[1] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[1] = rtb_Saturation;
  }

  /* End of Saturate: '<S441>/Saturation' */

  /* Sum: '<S497>/Sum' */
  rtb_Saturation = rtb_Saturation_n + Integrator_c;

  /* Saturate: '<S495>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[2] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[2] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[2] = rtb_Saturation;
  }

  /* End of Saturate: '<S495>/Saturation' */

  /* Sum: '<S551>/Sum' */
  rtb_Saturation = rtb_Saturation_j + Integrator_a;

  /* Saturate: '<S549>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[3] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[3] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[3] = rtb_Saturation;
  }

  /* End of Saturate: '<S549>/Saturation' */

  /* Sum: '<S60>/Sum' */
  rtb_Saturation = rtb_Saturation_og + Integrator_f;

  /* Saturate: '<S58>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[4] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[4] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[4] = rtb_Saturation;
  }

  /* End of Saturate: '<S58>/Saturation' */

  /* Sum: '<S114>/Sum' */
  rtb_Saturation = rtb_Saturation_i5 + Integrator_j;

  /* Saturate: '<S112>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[5] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[5] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[5] = rtb_Saturation;
  }

  /* End of Saturate: '<S112>/Saturation' */

  /* Sum: '<S168>/Sum' */
  rtb_Saturation = rtb_Saturation_gw + Integrator_am;

  /* Saturate: '<S166>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[6] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[6] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[6] = rtb_Saturation;
  }

  /* End of Saturate: '<S166>/Saturation' */

  /* Sum: '<S222>/Sum' */
  rtb_Saturation = rtb_Saturation_b + Integrator_l;

  /* Saturate: '<S220>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[7] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[7] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[7] = rtb_Saturation;
  }

  /* End of Saturate: '<S220>/Saturation' */

  /* Sum: '<S276>/Sum' */
  rtb_Saturation = rtb_Saturation_c + Integrator_j3;

  /* Saturate: '<S274>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[8] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[8] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[8] = rtb_Saturation;
  }

  /* End of Saturate: '<S274>/Saturation' */

  /* Sum: '<S330>/Sum' */
  rtb_Saturation = rtb_Saturation_e + rtb_DeadZone;

  /* Saturate: '<S328>/Saturation' */
  if (rtb_Saturation > 400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[9] = 400.0;
  } else if (rtb_Saturation < -400.0) {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[9] = -400.0;
  } else {
    /* Outport: '<Root>/Corrientes' */
    C_5DOF_EL_Y.Corrientes[9] = rtb_Saturation;
  }

  /* End of Saturate: '<S328>/Saturation' */

  /* Update for DiscreteIntegrator: '<S380>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE = Integrator_tmp + Integrator;
  if (C_5DOF_EL_DW.Integrator_DSTATE > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S434>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_b = Integrator_k_tmp + Integrator_k;
  if (C_5DOF_EL_DW.Integrator_DSTATE_b > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_b = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_b < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_b = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S488>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_n = Integrator_c_tmp + Integrator_c;
  if (C_5DOF_EL_DW.Integrator_DSTATE_n > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_n = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_n < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_n = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S542>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_e = Integrator_a_tmp + Integrator_a;
  if (C_5DOF_EL_DW.Integrator_DSTATE_e > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_e = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_e < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_e = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S51>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_i = Integrator_f_tmp + Integrator_f;
  if (C_5DOF_EL_DW.Integrator_DSTATE_i > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_i = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_i < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_i = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S105>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_e2 = Integrator_j_tmp + Integrator_j;
  if (C_5DOF_EL_DW.Integrator_DSTATE_e2 > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_e2 = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_e2 < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_e2 = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S159>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_p = Integrator_am_tmp + Integrator_am;
  if (C_5DOF_EL_DW.Integrator_DSTATE_p > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_p = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_p < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_p = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S213>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_l = Integrator_l_tmp + Integrator_l;
  if (C_5DOF_EL_DW.Integrator_DSTATE_l > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_l = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_l < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_l = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S267>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_g = Integrator_j3_tmp + Integrator_j3;
  if (C_5DOF_EL_DW.Integrator_DSTATE_g > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_g = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_g < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_g = -400.0;
  }

  /* Update for DiscreteIntegrator: '<S321>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_be = rtb_IntegralGain + rtb_DeadZone;
  if (C_5DOF_EL_DW.Integrator_DSTATE_be > 400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_be = 400.0;
  } else if (C_5DOF_EL_DW.Integrator_DSTATE_be < -400.0) {
    C_5DOF_EL_DW.Integrator_DSTATE_be = -400.0;
  }
}

/* Model step function for TID1 */
void C_5DOF_EL_step1(void)             /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_uz[5];
  real_T rtb_u[5];
  real_T rtb_Yaw[3];
  real_T rtb_TmpSignalConversionAtSFun_f[3];
  real_T b[8];
  real_T rtb_TmpSignalConversionAtKin_EM[6];
  real_T tmp[6];
  real_T tmp_0[4];
  real_T rtb_AG_mm_idx_0;
  real_T rtb_AG_mm_idx_1;
  real_T rtb_Sum_HEMS_idx_0;
  real_T rtb_Sum_HEMS_idx_1;
  real_T rtb_Sum_HEMS_idx_2;
  real_T rtb_b0_Roll;
  real_T rtb_b0_Z;
  real_T s;
  real_T smax;
  real_T tmp_1;
  real_T tmp_2;
  int32_T c_k;
  int32_T i;
  int32_T ijA;
  int32_T jA;
  int32_T jj;
  int32_T kAcol;
  int32_T n;
  int8_T ipiv[5];
  int8_T ipiv_0;
  static const real_T h[5] = { 0.0, -1.0, 0.21748, 1.0093, 0.0 };

  static const real_T g[5] = { 0.0, -1.0, -0.21748, 1.0093, 0.0 };

  static const real_T f[5] = { 0.0, -1.0, 0.21748, -1.0093, 0.0 };

  static const real_T e[5] = { 0.0, -1.0, -0.21748, -1.0093, 0.0 };

  static const real_T b_H_tmp[5] = { 1.0, 0.0, -0.18782, 0.0, 1.0095 };

  static const real_T H_tmp[5] = { 1.0, 0.0, -0.18782, 0.0, -1.0095 };

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/Ag'
   */
  if (!C_5DOF_EL_DW.H_pseudo_not_empty) {
    for (i = 0; i < 5; i++) {
      jj = i << 3;
      C_5DOF_EL_B.H[jj] = h[i];
      C_5DOF_EL_B.H[jj + 1] = g[i];
      C_5DOF_EL_B.H[jj + 2] = f[i];
      C_5DOF_EL_B.H[jj + 3] = e[i];
      C_5DOF_EL_B.H[jj + 4] = b_H_tmp[i];
      C_5DOF_EL_B.H[jj + 5] = b_H_tmp[i];
      C_5DOF_EL_B.H[jj + 6] = H_tmp[i];
      C_5DOF_EL_B.H[jj + 7] = H_tmp[i];
    }

    for (i = 0; i < 5; i++) {
      for (jj = 0; jj < 5; jj++) {
        tmp_1 = 0.0;
        for (n = 0; n < 8; n++) {
          tmp_1 += C_5DOF_EL_B.H[(jj << 3) + n] * C_5DOF_EL_B.H[(i << 3) + n];
        }

        C_5DOF_EL_B.A[jj + 5 * i] = tmp_1;
      }
    }

    for (i = 0; i < 8; i++) {
      for (jj = 0; jj < 5; jj++) {
        C_5DOF_EL_DW.H_pseudo[jj + 5 * i] = C_5DOF_EL_B.H[(jj << 3) + i];
      }
    }

    for (i = 0; i < 5; i++) {
      ipiv[i] = (int8_T)(i + 1);
    }

    for (i = 0; i < 4; i++) {
      jj = i * 6;
      n = 6 - i;
      jA = 0;
      smax = fabs(C_5DOF_EL_B.A[jj]);
      for (c_k = 2; c_k < n; c_k++) {
        s = fabs(C_5DOF_EL_B.A[(jj + c_k) - 1]);
        if (s > smax) {
          jA = c_k - 1;
          smax = s;
        }
      }

      if (C_5DOF_EL_B.A[jj + jA] != 0.0) {
        if (jA != 0) {
          n = i + jA;
          ipiv[i] = (int8_T)(n + 1);
          for (jA = 0; jA < 5; jA++) {
            c_k = jA * 5 + i;
            smax = C_5DOF_EL_B.A[c_k];
            kAcol = jA * 5 + n;
            C_5DOF_EL_B.A[c_k] = C_5DOF_EL_B.A[kAcol];
            C_5DOF_EL_B.A[kAcol] = smax;
          }
        }

        n = (jj - i) + 5;
        for (jA = jj + 2; jA <= n; jA++) {
          C_5DOF_EL_B.A[jA - 1] /= C_5DOF_EL_B.A[jj];
        }
      }

      n = 3 - i;
      jA = jj + 7;
      for (c_k = 0; c_k <= n; c_k++) {
        tmp_1 = C_5DOF_EL_B.A[(c_k * 5 + jj) + 5];
        if (tmp_1 != 0.0) {
          kAcol = (jA - i) + 3;
          for (ijA = jA; ijA <= kAcol; ijA++) {
            C_5DOF_EL_B.A[ijA - 1] += C_5DOF_EL_B.A[((jj + ijA) - jA) + 1] *
              -tmp_1;
          }
        }

        jA += 5;
      }

      ipiv_0 = ipiv[i];
      if (i + 1 != ipiv_0) {
        for (n = 0; n < 8; n++) {
          jA = 5 * n + i;
          smax = C_5DOF_EL_DW.H_pseudo[jA];
          jj = (5 * n + ipiv_0) - 1;
          C_5DOF_EL_DW.H_pseudo[jA] = C_5DOF_EL_DW.H_pseudo[jj];
          C_5DOF_EL_DW.H_pseudo[jj] = smax;
        }
      }
    }

    for (n = 0; n < 8; n++) {
      jA = 5 * n;
      for (c_k = 0; c_k < 5; c_k++) {
        kAcol = 5 * c_k;
        i = c_k + jA;
        if (C_5DOF_EL_DW.H_pseudo[i] != 0.0) {
          for (ijA = c_k + 2; ijA < 6; ijA++) {
            jj = (ijA + jA) - 1;
            C_5DOF_EL_DW.H_pseudo[jj] -= C_5DOF_EL_B.A[(ijA + kAcol) - 1] *
              C_5DOF_EL_DW.H_pseudo[i];
          }
        }
      }
    }

    for (n = 0; n < 8; n++) {
      jA = 5 * n;
      for (c_k = 4; c_k >= 0; c_k--) {
        kAcol = 5 * c_k;
        i = c_k + jA;
        tmp_1 = C_5DOF_EL_DW.H_pseudo[i];
        if (tmp_1 != 0.0) {
          C_5DOF_EL_DW.H_pseudo[i] = tmp_1 / C_5DOF_EL_B.A[c_k + kAcol];
          for (ijA = 0; ijA < c_k; ijA++) {
            jj = ijA + jA;
            C_5DOF_EL_DW.H_pseudo[jj] -= C_5DOF_EL_B.A[ijA + kAcol] *
              C_5DOF_EL_DW.H_pseudo[i];
          }
        }
      }
    }

    C_5DOF_EL_DW.H_pseudo_not_empty = true;
  }

  b[0] = C_5DOF_EL_U.Ag[0] - 0.09974F;
  b[1] = C_5DOF_EL_U.Ag[1] - 0.09974F;
  b[2] = C_5DOF_EL_U.Ag[2] - 0.09974F;
  b[3] = C_5DOF_EL_U.Ag[3] - 0.09974F;
  b[4] = (C_5DOF_EL_U.Ag[4] - 0.277F) + 0.1347F;
  b[5] = (-C_5DOF_EL_U.Ag[5] + 0.277F) - 0.1347F;
  b[6] = (C_5DOF_EL_U.Ag[6] - 0.277F) + 0.1347F;
  b[7] = (-C_5DOF_EL_U.Ag[7] + 0.277F) - 0.1347F;
  for (i = 0; i < 5; i++) {
    rtb_u[i] = 0.0;
  }

  for (i = 0; i < 8; i++) {
    tmp_1 = b[i];
    for (jj = 0; jj < 5; jj++) {
      rtb_u[jj] += C_5DOF_EL_DW.H_pseudo[5 * i + jj] * tmp_1;
    }
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  smax = sin(rtb_u[2]);
  s = 0.191 * smax;
  rtb_AG_mm_idx_1 = 0.6475 * sin(rtb_u[3]);
  rtb_Sum_HEMS_idx_0 = rtb_u[1] - s;
  C_5DOF_EL_B.airgaps_actuadores[0] = fabs(rtb_Sum_HEMS_idx_0 - rtb_AG_mm_idx_1);
  s += rtb_u[1];
  C_5DOF_EL_B.airgaps_actuadores[1] = fabs(s - rtb_AG_mm_idx_1);
  C_5DOF_EL_B.airgaps_actuadores[2] = fabs(rtb_Sum_HEMS_idx_0 + rtb_AG_mm_idx_1);
  C_5DOF_EL_B.airgaps_actuadores[3] = fabs(s + rtb_AG_mm_idx_1);
  s = 0.268 - 0.261 * cos(rtb_u[4]);
  rtb_AG_mm_idx_1 = 0.788 * sin(rtb_u[4]);
  smax *= 0.20255;
  rtb_Sum_HEMS_idx_0 = s + rtb_u[0];
  C_5DOF_EL_B.airgaps_actuadores[4] = fabs((rtb_Sum_HEMS_idx_0 + rtb_AG_mm_idx_1)
    - smax);
  s -= rtb_u[0];
  C_5DOF_EL_B.airgaps_actuadores[5] = fabs((s - rtb_AG_mm_idx_1) + smax);
  C_5DOF_EL_B.airgaps_actuadores[6] = fabs(rtb_Sum_HEMS_idx_0 - smax);
  C_5DOF_EL_B.airgaps_actuadores[7] = fabs(s + smax);
  C_5DOF_EL_B.airgaps_actuadores[8] = fabs((rtb_Sum_HEMS_idx_0 - rtb_AG_mm_idx_1)
    - smax);
  C_5DOF_EL_B.airgaps_actuadores[9] = fabs((s + rtb_AG_mm_idx_1) + smax);

  /* Gain: '<S4>/AG_mm' */
  for (i = 0; i < 6; i++) {
    rtb_TmpSignalConversionAtKin_EM[i] = C_5DOF_EL_B.airgaps_actuadores[i + 4] *
      1000.0;
  }

  /* End of Gain: '<S4>/AG_mm' */

  /* DiscreteStateSpace: '<S4>/Y' */
  {
    rtb_Yaw[0] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[0];
    rtb_Yaw[1] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[1];
    rtb_Yaw[2] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[2];
  }

  /* Gain: '<S4>/b0_Y' incorporates:
   *  Constant: '<S4>/Ref_Y'
   *  Gain: '<S4>/Kd_Y'
   *  Gain: '<S4>/Kp_Y'
   *  Sum: '<S4>/Sum2_Y'
   *  Sum: '<S4>/Sum3_Y'
   *  Sum: '<S4>/SumErr_Y'
   */
  smax = (((0.0 - rtb_Yaw[0]) * 400.0 - 80.0 * rtb_Yaw[1]) - rtb_Yaw[2]) * 250.0;

  /* DiscreteStateSpace: '<S4>/Yaw' */
  {
    rtb_Yaw[0] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[0];
    rtb_Yaw[1] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[1];
    rtb_Yaw[2] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[2];
  }

  /* SignalConversion generated from: '<S8>/ SFunction ' incorporates:
   *  Constant: '<S4>/Ref_Yaw'
   *  Gain: '<S4>/Fy_x2'
   *  Gain: '<S4>/Kd_Yaw'
   *  Gain: '<S4>/Kp_Yaw'
   *  Gain: '<S4>/Mz_x2'
   *  Gain: '<S4>/b0_Yaw'
   *  MATLAB Function: '<S4>/Mezclador'
   *  Sum: '<S4>/Sum2_Yaw'
   *  Sum: '<S4>/Sum3_Yaw'
   *  Sum: '<S4>/SumErr_Yaw'
   */
  s = 2.0 * smax;
  smax = (((0.0 - rtb_Yaw[0]) * 400.0 - 80.0 * rtb_Yaw[1]) - rtb_Yaw[2]) *
    29.297 * 2.0;

  /* MATLAB Function: '<S4>/Mezclador' */
  tmp_1 = -0.16666666666666666 * s;
  tmp_2 = -0.30266343825665859 * smax;

  /* Saturate: '<S4>/Sat_I' incorporates:
   *  Lookup_n-D: '<S4>/InvLUT_1'
   *  MATLAB Function: '<S4>/Mezclador'
   */
  tmp[0] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[0], tmp_1 + tmp_2,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled19,
    C_5DOF_EL_ConstP.pooled17, C_5DOF_EL_ConstP.pooled31, 13U);

  /* MATLAB Function: '<S4>/Mezclador' */
  rtb_b0_Roll = 0.16666666666666666 * s;
  smax *= 0.30266343825665859;

  /* Saturate: '<S4>/Sat_I' incorporates:
   *  Lookup_n-D: '<S4>/InvLUT_2'
   *  Lookup_n-D: '<S4>/InvLUT_3'
   *  Lookup_n-D: '<S4>/InvLUT_4'
   *  Lookup_n-D: '<S4>/InvLUT_5'
   *  Lookup_n-D: '<S4>/InvLUT_6'
   *  MATLAB Function: '<S4>/Mezclador'
   */
  tmp[1] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[1], rtb_b0_Roll + smax,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled19,
    C_5DOF_EL_ConstP.pooled17, C_5DOF_EL_ConstP.pooled31, 13U);
  tmp[2] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[2], tmp_1,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled19,
    C_5DOF_EL_ConstP.pooled17, C_5DOF_EL_ConstP.pooled31, 13U);
  tmp[3] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[3], rtb_b0_Roll,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled19,
    C_5DOF_EL_ConstP.pooled17, C_5DOF_EL_ConstP.pooled31, 13U);
  tmp[4] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[4], tmp_1 + smax,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled19,
    C_5DOF_EL_ConstP.pooled17, C_5DOF_EL_ConstP.pooled31, 13U);
  tmp[5] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[5], rtb_b0_Roll + tmp_2,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled19,
    C_5DOF_EL_ConstP.pooled17, C_5DOF_EL_ConstP.pooled31, 13U);
  for (i = 0; i < 6; i++) {
    smax = tmp[i];
    if (smax > 50.0) {
      /* RateTransition: '<S4>/RT_Iref_EMS' */
      C_5DOF_EL_DW.RT_Iref_EMS_Buffer0[i] = 50.0;
    } else if (smax < 0.0) {
      /* RateTransition: '<S4>/RT_Iref_EMS' */
      C_5DOF_EL_DW.RT_Iref_EMS_Buffer0[i] = 0.0;
    } else {
      /* RateTransition: '<S4>/RT_Iref_EMS' */
      C_5DOF_EL_DW.RT_Iref_EMS_Buffer0[i] = smax;
    }
  }

  /* Gain: '<S5>/AG_HEMS_mm' */
  rtb_AG_mm_idx_0 = 1000.0 * C_5DOF_EL_B.airgaps_actuadores[0];
  rtb_AG_mm_idx_1 = 1000.0 * C_5DOF_EL_B.airgaps_actuadores[1];
  s = 1000.0 * C_5DOF_EL_B.airgaps_actuadores[2];
  smax = 1000.0 * C_5DOF_EL_B.airgaps_actuadores[3];

  /* SignalConversion generated from: '<S5>/Kin_HEMS' incorporates:
   *  Lookup_n-D: '<S5>/LUT_HEMS_1'
   *  Lookup_n-D: '<S5>/LUT_HEMS_2'
   *  Lookup_n-D: '<S5>/LUT_HEMS_3'
   *  Lookup_n-D: '<S5>/LUT_HEMS_4'
   */
  tmp_0[0] = look2_binlcpw(rtb_AG_mm_idx_0, 0.0, C_5DOF_EL_ConstP.pooled24,
    C_5DOF_EL_ConstP.pooled25, C_5DOF_EL_ConstP.pooled23,
    C_5DOF_EL_ConstP.pooled33, 14U);
  tmp_0[1] = look2_binlcpw(rtb_AG_mm_idx_1, 0.0, C_5DOF_EL_ConstP.pooled24,
    C_5DOF_EL_ConstP.pooled25, C_5DOF_EL_ConstP.pooled23,
    C_5DOF_EL_ConstP.pooled33, 14U);
  tmp_0[2] = look2_binlcpw(s, 0.0, C_5DOF_EL_ConstP.pooled24,
    C_5DOF_EL_ConstP.pooled25, C_5DOF_EL_ConstP.pooled23,
    C_5DOF_EL_ConstP.pooled33, 14U);
  tmp_0[3] = look2_binlcpw(smax, 0.0, C_5DOF_EL_ConstP.pooled24,
    C_5DOF_EL_ConstP.pooled25, C_5DOF_EL_ConstP.pooled23,
    C_5DOF_EL_ConstP.pooled33, 14U);

  /* Gain: '<S5>/Kin_HEMS' incorporates:
   *  SignalConversion generated from: '<S339>/ SFunction '
   */
  rtb_TmpSignalConversionAtSFun_f[0] = 0.0;
  rtb_TmpSignalConversionAtSFun_f[1] = 0.0;
  rtb_TmpSignalConversionAtSFun_f[2] = 0.0;
  rtb_Sum_HEMS_idx_0 = rtb_TmpSignalConversionAtSFun_f[0];
  rtb_Sum_HEMS_idx_1 = rtb_TmpSignalConversionAtSFun_f[1];
  rtb_Sum_HEMS_idx_2 = rtb_TmpSignalConversionAtSFun_f[2];
  for (i = 0; i < 4; i++) {
    tmp_1 = tmp_0[i];
    rtb_Sum_HEMS_idx_0 += C_5DOF_EL_ConstP.Kin_HEMS_Gain[3 * i] * tmp_1;
    rtb_Sum_HEMS_idx_1 += C_5DOF_EL_ConstP.Kin_HEMS_Gain[3 * i + 1] * tmp_1;
    rtb_Sum_HEMS_idx_2 += C_5DOF_EL_ConstP.Kin_HEMS_Gain[3 * i + 2] * tmp_1;
  }

  rtb_TmpSignalConversionAtSFun_f[2] = rtb_Sum_HEMS_idx_2;
  rtb_TmpSignalConversionAtSFun_f[1] = rtb_Sum_HEMS_idx_1;
  rtb_TmpSignalConversionAtSFun_f[0] = rtb_Sum_HEMS_idx_0;

  /* End of Gain: '<S5>/Kin_HEMS' */

  /* Sum: '<S5>/Sum_HEMS' */
  rtb_Sum_HEMS_idx_0 = rtb_TmpSignalConversionAtSFun_f[0];
  rtb_Sum_HEMS_idx_1 = rtb_TmpSignalConversionAtSFun_f[1];
  rtb_Sum_HEMS_idx_2 = rtb_TmpSignalConversionAtSFun_f[2];

  /* DiscreteStateSpace: '<S6>/Z' */
  {
    rtb_TmpSignalConversionAtSFun_f[0] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[0];
    rtb_TmpSignalConversionAtSFun_f[1] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[1];
    rtb_TmpSignalConversionAtSFun_f[2] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[2];
  }

  /* Gain: '<S6>/b0_Z' incorporates:
   *  Constant: '<S6>/Ref_Z'
   *  Gain: '<S6>/Kd_Z'
   *  Gain: '<S6>/Kp_Z'
   *  Sum: '<S6>/Sum2_Z'
   *  Sum: '<S6>/Sum3_Z'
   *  Sum: '<S6>/SumErr_Z'
   */
  rtb_b0_Z = (((0.01643 - rtb_TmpSignalConversionAtSFun_f[0]) * 900.0 - 60.0 *
               rtb_TmpSignalConversionAtSFun_f[1]) -
              rtb_TmpSignalConversionAtSFun_f[2]) * 250.0;

  /* DiscreteStateSpace: '<S6>/Roll' */
  {
    rtb_TmpSignalConversionAtSFun_f[0] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE[0];
    rtb_TmpSignalConversionAtSFun_f[1] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE[1];
    rtb_TmpSignalConversionAtSFun_f[2] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE[2];
  }

  /* Gain: '<S6>/b0_Roll' incorporates:
   *  Constant: '<S6>/Ref_Roll'
   *  Gain: '<S6>/Kd_Roll'
   *  Gain: '<S6>/Kp_Roll'
   *  Sum: '<S6>/Sum2_Roll'
   *  Sum: '<S6>/Sum3_Roll'
   *  Sum: '<S6>/SumErr_Roll'
   */
  rtb_b0_Roll = (((0.0 - rtb_TmpSignalConversionAtSFun_f[0]) * 1225.0 - 70.0 *
                  rtb_TmpSignalConversionAtSFun_f[1]) -
                 rtb_TmpSignalConversionAtSFun_f[2]) * 43.082;

  /* DiscreteStateSpace: '<S6>/Pitch' */
  {
    rtb_TmpSignalConversionAtSFun_f[0] = (1.0)*C_5DOF_EL_DW.Pitch_DSTATE[0];
    rtb_TmpSignalConversionAtSFun_f[1] = (1.0)*C_5DOF_EL_DW.Pitch_DSTATE[1];
    rtb_TmpSignalConversionAtSFun_f[2] = (1.0)*C_5DOF_EL_DW.Pitch_DSTATE[2];
  }

  /* Sum: '<S6>/SumErr_Pitch' */
  tmp_1 = rtb_TmpSignalConversionAtSFun_f[0];

  /* Gain: '<S6>/Kd_Pitch' */
  tmp_2 = rtb_TmpSignalConversionAtSFun_f[1];

  /* SignalConversion generated from: '<S339>/ SFunction ' incorporates:
   *  Constant: '<S6>/Ref_Pitch'
   *  Gain: '<S6>/Kd_Pitch'
   *  Gain: '<S6>/Kp_Pitch'
   *  Gain: '<S6>/b0_Pitch'
   *  MATLAB Function: '<S6>/Mezclador'
   *  Sum: '<S6>/Sum2_Pitch'
   *  Sum: '<S6>/Sum3_Pitch'
   *  Sum: '<S6>/SumErr_Pitch'
   */
  rtb_TmpSignalConversionAtSFun_f[0] = rtb_b0_Z;
  rtb_TmpSignalConversionAtSFun_f[1] = rtb_b0_Roll;
  rtb_TmpSignalConversionAtSFun_f[2] = (((0.0 - tmp_1) * 1225.0 - 70.0 * tmp_2)
    - rtb_TmpSignalConversionAtSFun_f[2]) * 26.887;

  /* MATLAB Function: '<S6>/Mezclador' */
  rtb_b0_Roll = -0.25 * rtb_TmpSignalConversionAtSFun_f[0];
  rtb_b0_Z = 1.3089005235602094 * rtb_TmpSignalConversionAtSFun_f[1];
  tmp_1 = 0.36764705882352938 * rtb_TmpSignalConversionAtSFun_f[2];
  tmp_2 = rtb_b0_Roll + rtb_b0_Z;

  /* Lookup_n-D: '<S6>/InvLUT_1' incorporates:
   *  Gain: '<S6>/AG_mm'
   *  MATLAB Function: '<S6>/Mezclador'
   */
  rtb_AG_mm_idx_0 = look2_binlcpw(rtb_AG_mm_idx_0, tmp_2 + tmp_1,
    C_5DOF_EL_ConstP.pooled24, C_5DOF_EL_ConstP.pooled30,
    C_5DOF_EL_ConstP.pooled29, C_5DOF_EL_ConstP.pooled34, 14U);

  /* MATLAB Function: '<S6>/Mezclador' */
  rtb_b0_Roll -= rtb_b0_Z;

  /* Lookup_n-D: '<S6>/InvLUT_2' incorporates:
   *  Gain: '<S6>/AG_mm'
   *  MATLAB Function: '<S6>/Mezclador'
   */
  rtb_AG_mm_idx_1 = look2_binlcpw(rtb_AG_mm_idx_1, rtb_b0_Roll + tmp_1,
    C_5DOF_EL_ConstP.pooled24, C_5DOF_EL_ConstP.pooled30,
    C_5DOF_EL_ConstP.pooled29, C_5DOF_EL_ConstP.pooled34, 14U);

  /* Lookup_n-D: '<S6>/InvLUT_3' incorporates:
   *  Gain: '<S6>/AG_mm'
   *  MATLAB Function: '<S6>/Mezclador'
   */
  s = look2_binlcpw(s, tmp_2 - tmp_1, C_5DOF_EL_ConstP.pooled24,
                    C_5DOF_EL_ConstP.pooled30, C_5DOF_EL_ConstP.pooled29,
                    C_5DOF_EL_ConstP.pooled34, 14U);

  /* Lookup_n-D: '<S6>/InvLUT_4' incorporates:
   *  Gain: '<S6>/AG_mm'
   *  MATLAB Function: '<S6>/Mezclador'
   */
  smax = look2_binlcpw(smax, rtb_b0_Roll - tmp_1, C_5DOF_EL_ConstP.pooled24,
                       C_5DOF_EL_ConstP.pooled30, C_5DOF_EL_ConstP.pooled29,
                       C_5DOF_EL_ConstP.pooled34, 14U);

  /* Saturate: '<S6>/Sat_I' incorporates:
   *  Lookup_n-D: '<S6>/InvLUT_1'
   *  Lookup_n-D: '<S6>/InvLUT_2'
   *  Lookup_n-D: '<S6>/InvLUT_3'
   *  Lookup_n-D: '<S6>/InvLUT_4'
   */
  if (rtb_AG_mm_idx_0 > 50.0) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[0] = 50.0;
  } else if (rtb_AG_mm_idx_0 < -50.0) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[0] = -50.0;
  } else {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[0] = rtb_AG_mm_idx_0;
  }

  if (rtb_AG_mm_idx_1 > 50.0) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[1] = 50.0;
  } else if (rtb_AG_mm_idx_1 < -50.0) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[1] = -50.0;
  } else {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[1] = rtb_AG_mm_idx_1;
  }

  if (s > 50.0) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[2] = 50.0;
  } else if (s < -50.0) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[2] = -50.0;
  } else {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[2] = s;
  }

  if (smax > 50.0) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[3] = 50.0;
  } else if (smax < -50.0) {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[3] = -50.0;
  } else {
    /* RateTransition: '<S6>/RT_Iref_HEMS' */
    C_5DOF_EL_DW.RT_Iref_HEMS_Buffer0[3] = smax;
  }

  /* End of Saturate: '<S6>/Sat_I' */
  for (i = 0; i < 5; i++) {
    /* UnitDelay: '<S2>/uz' */
    rtb_uz[i] = C_5DOF_EL_DW.uz_DSTATE[i];
  }

  /* Update for DiscreteStateSpace: '<S4>/Y' */
  {
    real_T xnew[3];
    xnew[0] = (0.85719882183949758)*C_5DOF_EL_DW.Y_DSTATE[0]
      + (0.00092859941091974875)*C_5DOF_EL_DW.Y_DSTATE[1]
      + (4.6429970545987424E-7)*C_5DOF_EL_DW.Y_DSTATE[2];
    xnew[0] += (0.14280117816050261)*rtb_u[0] + (1.8571988218394976E-9)*rtb_uz[3];
    xnew[1] = (-7.0225330450806)*C_5DOF_EL_DW.Y_DSTATE[0]
      + (0.99648873347745981)*C_5DOF_EL_DW.Y_DSTATE[1]
      + (0.00099824436673872957)*C_5DOF_EL_DW.Y_DSTATE[2];
    xnew[1] += (7.0225330450805989)*rtb_u[0] + (3.9929774669549195E-6)*rtb_uz[3];
    xnew[2] = (-116.07492636496859)*C_5DOF_EL_DW.Y_DSTATE[0]
      + (-0.058037463182484296)*C_5DOF_EL_DW.Y_DSTATE[1]
      + (0.99997098126840867)*C_5DOF_EL_DW.Y_DSTATE[2];
    xnew[2] += (116.07492636496858)*rtb_u[0] + (-1.1607492636496859E-7)*rtb_uz[3];
    (void) memcpy(&C_5DOF_EL_DW.Y_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S4>/Yaw' */
  {
    real_T xnew[3];
    xnew[0] = (0.85719882183949758)*C_5DOF_EL_DW.Yaw_DSTATE[0]
      + (0.00092859941091974875)*C_5DOF_EL_DW.Yaw_DSTATE[1]
      + (4.6429970545987424E-7)*C_5DOF_EL_DW.Yaw_DSTATE[2];
    xnew[0] += (0.14280117816050261)*rtb_u[4] + (1.5848028994773337E-8)*rtb_uz[4];
    xnew[1] = (-7.0225330450806)*C_5DOF_EL_DW.Yaw_DSTATE[0]
      + (0.99648873347745981)*C_5DOF_EL_DW.Yaw_DSTATE[1]
      + (0.00099824436673872957)*C_5DOF_EL_DW.Yaw_DSTATE[2];
    xnew[1] += (7.0225330450805989)*rtb_u[4] + (3.4073262338762669E-5)*rtb_uz[4];
    xnew[2] = (-116.07492636496859)*C_5DOF_EL_DW.Yaw_DSTATE[0]
      + (-0.058037463182484296)*C_5DOF_EL_DW.Yaw_DSTATE[1]
      + (0.99997098126840867)*C_5DOF_EL_DW.Yaw_DSTATE[2];
    xnew[2] += (116.07492636496858)*rtb_u[4] + (-9.9050181217333332E-7)*rtb_uz[4];
    (void) memcpy(&C_5DOF_EL_DW.Yaw_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S6>/Z' */
  {
    real_T xnew[3];
    xnew[0] = (0.75259320810981811)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (0.000876296604054912)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (4.3814830202746851E-7)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[0] += (0.24740679189018189)*rtb_u[1] + (1.7525932081098171E-9)*rtb_uz[0];
    xnew[1] = (-21.613417590712306)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (0.98919329120464383)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (0.000994596645602322)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[1] += (21.613417590712306)*rtb_u[1] + (3.9783865824092869E-6)*rtb_uz[0];
    xnew[2] = (-638.82022435602892)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (-0.31941011217801363)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (0.99984029494391125)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[2] += (638.82022435602892)*rtb_u[1] + (-6.388202243560248E-7)*rtb_uz[0];
    (void) memcpy(&C_5DOF_EL_DW.Z_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S6>/Roll' */
  {
    real_T xnew[3];
    xnew[0] = (0.75259320810981811)*C_5DOF_EL_DW.Roll_DSTATE[0]
      + (0.000876296604054912)*C_5DOF_EL_DW.Roll_DSTATE[1]
      + (4.3814830202746851E-7)*C_5DOF_EL_DW.Roll_DSTATE[2];
    xnew[0] += (0.24740679189018189)*rtb_u[2] + (1.0170101249418672E-8)*rtb_uz[1];
    xnew[1] = (-21.613417590712306)*C_5DOF_EL_DW.Roll_DSTATE[0]
      + (0.98919329120464383)*C_5DOF_EL_DW.Roll_DSTATE[1]
      + (0.000994596645602322)*C_5DOF_EL_DW.Roll_DSTATE[2];
    xnew[1] += (21.613417590712306)*rtb_u[2] + (2.3086129836180353E-5)*rtb_uz[1];
    xnew[2] = (-638.82022435602892)*C_5DOF_EL_DW.Roll_DSTATE[0]
      + (-0.31941011217801363)*C_5DOF_EL_DW.Roll_DSTATE[1]
      + (0.99984029494391125)*C_5DOF_EL_DW.Roll_DSTATE[2];
    xnew[2] += (638.82022435602892)*rtb_u[2] + (-3.7070019054130953E-6)*rtb_uz[1];
    (void) memcpy(&C_5DOF_EL_DW.Roll_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S6>/Pitch' */
  {
    real_T xnew[3];
    xnew[0] = (0.75259320810981811)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (0.000876296604054912)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (4.3814830202746851E-7)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[0] += (0.24740679189018189)*rtb_u[3] + (1.629591631745635E-8)*rtb_uz[2];
    xnew[1] = (-21.613417590712306)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (0.98919329120464383)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (0.000994596645602322)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[1] += (21.613417590712306)*rtb_u[3] + (3.69917300406264E-5)*rtb_uz[2];
    xnew[2] = (-638.82022435602892)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (-0.31941011217801363)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (0.99984029494391125)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[2] += (638.82022435602892)*rtb_u[3] + (-5.9398614977128325E-6)*rtb_uz[2];
    (void) memcpy(&C_5DOF_EL_DW.Pitch_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* SignalConversion generated from: '<S5>/Kin_EMS' incorporates:
   *  Gain: '<S5>/AG_EMS_mm'
   *  Lookup_n-D: '<S5>/LUT_EMS_1'
   *  Lookup_n-D: '<S5>/LUT_EMS_2'
   *  Lookup_n-D: '<S5>/LUT_EMS_3'
   *  Lookup_n-D: '<S5>/LUT_EMS_4'
   *  Lookup_n-D: '<S5>/LUT_EMS_5'
   *  Lookup_n-D: '<S5>/LUT_EMS_6'
   */
  tmp[0] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[0], 0.0,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled22,
    C_5DOF_EL_ConstP.pooled21, C_5DOF_EL_ConstP.pooled32, 13U);
  tmp[1] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[1], 0.0,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled22,
    C_5DOF_EL_ConstP.pooled21, C_5DOF_EL_ConstP.pooled32, 13U);
  tmp[2] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[2], 0.0,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled22,
    C_5DOF_EL_ConstP.pooled21, C_5DOF_EL_ConstP.pooled32, 13U);
  tmp[3] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[3], 0.0,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled22,
    C_5DOF_EL_ConstP.pooled21, C_5DOF_EL_ConstP.pooled32, 13U);
  tmp[4] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[4], 0.0,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled22,
    C_5DOF_EL_ConstP.pooled21, C_5DOF_EL_ConstP.pooled32, 13U);
  tmp[5] = look2_binlcpw(rtb_TmpSignalConversionAtKin_EM[5], 0.0,
    C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled22,
    C_5DOF_EL_ConstP.pooled21, C_5DOF_EL_ConstP.pooled32, 13U);

  /* Gain: '<S5>/Kin_EMS' */
  rtb_AG_mm_idx_0 = 0.0;
  rtb_AG_mm_idx_1 = 0.0;
  for (i = 0; i < 6; i++) {
    tmp_1 = tmp[i];
    jj = i << 1;
    rtb_AG_mm_idx_0 += C_5DOF_EL_ConstP.Kin_EMS_Gain[jj] * tmp_1;
    rtb_AG_mm_idx_1 += C_5DOF_EL_ConstP.Kin_EMS_Gain[jj + 1] * tmp_1;
  }

  /* End of Gain: '<S5>/Kin_EMS' */

  /* Update for UnitDelay: '<S2>/uz' */
  C_5DOF_EL_DW.uz_DSTATE[0] = rtb_Sum_HEMS_idx_0;
  C_5DOF_EL_DW.uz_DSTATE[1] = rtb_Sum_HEMS_idx_1;
  C_5DOF_EL_DW.uz_DSTATE[2] = rtb_Sum_HEMS_idx_2;
  C_5DOF_EL_DW.uz_DSTATE[3] = rtb_AG_mm_idx_0;
  C_5DOF_EL_DW.uz_DSTATE[4] = rtb_AG_mm_idx_1;
}

/* Model initialize function */
void C_5DOF_EL_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)C_5DOF_EL_M, 0,
                sizeof(RT_MODEL_C_5DOF_EL_T));

  /* block I/O */
  (void) memset(((void *) &C_5DOF_EL_B), 0,
                sizeof(B_C_5DOF_EL_T));

  /* states (dwork) */
  (void) memset((void *)&C_5DOF_EL_DW, 0,
                sizeof(DW_C_5DOF_EL_T));

  /* InitializeConditions for DiscreteIntegrator: '<S380>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S434>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_b = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S488>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_n = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S542>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_e = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_i = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_e2 = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_p = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S213>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_l = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S267>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_g = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S321>/Integrator' */
  C_5DOF_EL_DW.Integrator_DSTATE_be = 0.0;

  /* InitializeConditions for DiscreteStateSpace: '<S4>/Y' */
  C_5DOF_EL_DW.Y_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Y_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Y_DSTATE[2] = (0.0);

  /* InitializeConditions for DiscreteStateSpace: '<S4>/Yaw' */
  C_5DOF_EL_DW.Yaw_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Yaw_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Yaw_DSTATE[2] = (0.0);

  /* InitializeConditions for DiscreteStateSpace: '<S6>/Z' */
  C_5DOF_EL_DW.Z_DSTATE[0] = (0.0225);
  C_5DOF_EL_DW.Z_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Z_DSTATE[2] = (0.0);

  /* InitializeConditions for DiscreteStateSpace: '<S6>/Roll' */
  C_5DOF_EL_DW.Roll_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Roll_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Roll_DSTATE[2] = (0.0);

  /* InitializeConditions for DiscreteStateSpace: '<S6>/Pitch' */
  C_5DOF_EL_DW.Pitch_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Pitch_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Pitch_DSTATE[2] = (0.0);

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
  C_5DOF_EL_DW.H_pseudo_not_empty = false;
}

/* Model terminate function */
void C_5DOF_EL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
