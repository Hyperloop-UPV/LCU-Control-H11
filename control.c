/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control.c
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.108
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr  7 22:36:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "control.h"
#include "rtwtypes.h"
#include "control_private.h"

/* Block signals (default storage) */
B_control_T control_B;

/* Block states (default storage) */
DW_control_T control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_control_T control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_control_T control_Y;

/* Real-time model */
static RT_MODEL_control_T control_M_;
RT_MODEL_control_T *const control_M = &control_M_;
static void rate_monotonic_scheduler(void);
real32_T look2_iflf_binlcpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  real32_T fractions[2];
  real32_T frac;
  real32_T yL_0d0;
  real32_T yL_0d1;
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
    frac = 0.0F;
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
    frac = 1.0F;
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
    frac = 0.0F;
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
    frac = 1.0F;
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
void control_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(control_M, 1));
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
  control_M->Timing.RateInteraction.TID0_1 = (control_M->
    Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (control_M->Timing.TaskCounters.TID[1])++;
  if ((control_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    control_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void control_step0(void)               /* Sample time: [0.0005s, 0.0s] */
{
  real32_T rtb_DeadZone;
  real32_T rtb_ErrorCorriente;
  real32_T rtb_LUT_Dir_I2F;
  real32_T rtb_ProportionalGain;
  int8_T tmp_0;
  int8_T tmp_1;
  boolean_T tmp;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Gain: '<S1>/m2mm' incorporates:
   *  Inport: '<Root>/Gap'
   */
  rtb_LUT_Dir_I2F = 1000.0F * control_U.Gap;

  /* RateTransition generated from: '<S1>/SumRef' incorporates:
   *  RateTransition generated from: '<S1>/ESO'
   *  RateTransition generated from: '<S1>/SumCtrl'
   *  RateTransition generated from: '<S1>/SumV'
   */
  tmp = control_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    /* RateTransition generated from: '<S1>/SumRef' */
    control_B.TmpRTBAtSumRefInport2 = control_DW.TmpRTBAtSumRefInport2_Buffer0;

    /* RateTransition generated from: '<S1>/SumV' */
    control_B.TmpRTBAtSumVInport2 = control_DW.TmpRTBAtSumVInport2_Buffer0;

    /* RateTransition generated from: '<S1>/SumCtrl' */
    control_B.TmpRTBAtSumCtrlInport2 = control_DW.TmpRTBAtSumCtrlInport2_Buffer0;
  }

  /* End of RateTransition generated from: '<S1>/SumRef' */

  /* Gain: '<S1>/InvB0' incorporates:
   *  Gain: '<S1>/Kp'
   *  Inport: '<Root>/Referencia'
   *  Sum: '<S1>/SumCtrl'
   *  Sum: '<S1>/SumRef'
   *  Sum: '<S1>/SumV'
   */
  rtb_DeadZone = (((control_U.Referencia - control_B.TmpRTBAtSumRefInport2) *
                   900.0F - control_B.TmpRTBAtSumVInport2) -
                  control_B.TmpRTBAtSumCtrlInport2) * -40.0F;

  /* Lookup_n-D: '<S1>/LUT_Inv_F2I' incorporates:
   *  DeadZone: '<S31>/DeadZone'
   *  Lookup_n-D: '<S1>/LUT_Dir_I2F'
   */
  rtb_DeadZone = look2_iflf_binlcpw(rtb_LUT_Dir_I2F, rtb_DeadZone,
    control_ConstP.pooled2, control_ConstP.LUT_Inv_F2I_bp02Data,
    control_ConstP.LUT_Inv_F2I_tableData, control_ConstP.LUT_Inv_F2I_maxIndex,
    14U);

  /* Saturate: '<S1>/Sat_I' */
  rtb_ErrorCorriente = rtb_DeadZone;

  /* UnitDelay: '<S1>/Unit Delay' */
  rtb_DeadZone = control_DW.UnitDelay_DSTATE;

  /* Saturate: '<S1>/Sat_I' */
  if (rtb_ErrorCorriente > 50.0F) {
    rtb_ErrorCorriente = 50.0F;
  } else if (rtb_ErrorCorriente < -50.0F) {
    rtb_ErrorCorriente = -50.0F;
  }

  /* Sum: '<S1>/Add2' incorporates:
   *  Saturate: '<S1>/Sat_I'
   */
  rtb_ErrorCorriente -= rtb_DeadZone;

  /* Lookup_n-D: '<S1>/LUT_Dir_I2F' incorporates:
   *  DeadZone: '<S31>/DeadZone'
   */
  rtb_LUT_Dir_I2F = look2_iflf_binlcpw(rtb_LUT_Dir_I2F, rtb_DeadZone,
    control_ConstP.pooled2, control_ConstP.LUT_Dir_I2F_bp02Data,
    control_ConstP.LUT_Dir_I2F_tableData, control_ConstP.LUT_Dir_I2F_maxIndex,
    14U);

  /* Sum: '<S49>/Sum Fdbk' */
  rtb_DeadZone = rtb_ErrorCorriente + control_DW.Integrator_DSTATE;

  /* Gain: '<S38>/Proportional Gain' */
  rtb_DeadZone *= 10.0F;

  /* DeadZone: '<S31>/DeadZone' */
  if (rtb_DeadZone > 80.0F) {
    rtb_DeadZone -= 80.0F;
  } else if (rtb_DeadZone >= -80.0F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -80.0F;
  }

  /* End of DeadZone: '<S31>/DeadZone' */

  /* Gain: '<S36>/Integral Gain' */
  rtb_ProportionalGain = 200.0F * rtb_ErrorCorriente;

  /* Switch: '<S29>/Switch3' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant6'
   *  Constant: '<S29>/Constant7'
   *  RelationalOperator: '<S29>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S29>/Switch2' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant4'
   *  Constant: '<S29>/Constant5'
   *  RelationalOperator: '<S29>/fix for DT propagation issue1'
   */
  if (rtb_ProportionalGain > 0.0F) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant1'
   *  Logic: '<S29>/AND3'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  Switch: '<S29>/Switch2'
   *  Switch: '<S29>/Switch3'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp_0 == tmp_1)) {
    rtb_ProportionalGain = 0.0F;
  }

  /* End of Switch: '<S29>/Switch' */

  /* DiscreteIntegrator: '<S39>/Integrator' */
  rtb_DeadZone = 0.00025F * rtb_ProportionalGain;

  /* DiscreteIntegrator: '<S39>/Integrator' */
  rtb_ProportionalGain = rtb_DeadZone + control_DW.Integrator_DSTATE;

  /* DiscreteIntegrator: '<S39>/Integrator' */
  if (rtb_ProportionalGain > 80.0F) {
    /* DiscreteIntegrator: '<S39>/Integrator' */
    rtb_ProportionalGain = 80.0F;
  } else if (rtb_ProportionalGain < -80.0F) {
    /* DiscreteIntegrator: '<S39>/Integrator' */
    rtb_ProportionalGain = -80.0F;
  }

  /* RateTransition generated from: '<S1>/ESO' incorporates:
   *  Inport: '<Root>/Gap'
   */
  if (tmp) {
    control_DW.TmpRTBAtESOInport1_Buffer[0] = rtb_LUT_Dir_I2F;
    control_DW.TmpRTBAtESOInport1_Buffer[1] = control_U.Gap;
  }

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Inport: '<Root>/corriente_real'
   */
  control_DW.UnitDelay_DSTATE = control_U.corriente_real;

  /* Update for DiscreteIntegrator: '<S39>/Integrator' */
  control_DW.Integrator_DSTATE = rtb_DeadZone + rtb_ProportionalGain;
  if (control_DW.Integrator_DSTATE > 80.0F) {
    control_DW.Integrator_DSTATE = 80.0F;
  } else if (control_DW.Integrator_DSTATE < -80.0F) {
    control_DW.Integrator_DSTATE = -80.0F;
  }

  /* Gain: '<S37>/Proportional Gain' incorporates:
   *  Sum: '<S48>/Sum'
   */
  control_Y.Voltage = (rtb_ErrorCorriente + rtb_ProportionalGain) * 10.0F;

  /* Saturate: '<S46>/Saturation' */
  if (control_Y.Voltage > 80.0F) {
    /* Gain: '<S37>/Proportional Gain' incorporates:
     *  Outport: '<Root>/Voltage'
     */
    control_Y.Voltage = 80.0F;
  } else if (control_Y.Voltage < -80.0F) {
    /* Gain: '<S37>/Proportional Gain' incorporates:
     *  Outport: '<Root>/Voltage'
     */
    control_Y.Voltage = -80.0F;
  }

  /* End of Saturate: '<S46>/Saturation' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model step function for TID1 */
void control_step1(void)               /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_TmpRTBAtESOInport1[2];
  real32_T rtb_ESO[3];
  real32_T rtb_Kd;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* RateTransition generated from: '<S1>/ESO' */
  rtb_TmpRTBAtESOInport1[0] = control_DW.TmpRTBAtESOInport1_Buffer[0];
  rtb_TmpRTBAtESOInport1[1] = control_DW.TmpRTBAtESOInport1_Buffer[1];

  /* DiscreteStateSpace: '<S1>/ESO' */
  {
    rtb_ESO[0] = (0.87629658F)*control_DW.ESO_DSTATE[0] + (0.000438148301F)*
      control_DW.ESO_DSTATE[1]
      + (2.19074153E-7F)*control_DW.ESO_DSTATE[2];
    rtb_ESO[0] += (-5.47685364E-9F)*rtb_TmpRTBAtESOInport1[0] + (0.123703398F)*
      rtb_TmpRTBAtESOInport1[1];
    rtb_ESO[1] = (-10.8067083F)*control_DW.ESO_DSTATE[0] + (0.99459666F)*
      control_DW.ESO_DSTATE[1]
      + (0.000497298315F)*control_DW.ESO_DSTATE[2];
    rtb_ESO[1] += (-1.24324579E-5F)*rtb_TmpRTBAtESOInport1[0] + (10.8067083F)*
      rtb_TmpRTBAtESOInport1[1];
    rtb_ESO[2] = (-319.410126F)*control_DW.ESO_DSTATE[0] + (-0.159705058F)*
      control_DW.ESO_DSTATE[1]
      + (0.99992013F)*control_DW.ESO_DSTATE[2];
    rtb_ESO[2] += (1.99631313E-6F)*rtb_TmpRTBAtESOInport1[0] + (319.410126F)*
      rtb_TmpRTBAtESOInport1[1];
  }

  /* Gain: '<S1>/Kd' */
  rtb_Kd = 60.0F * rtb_ESO[1];

  /* RateTransition generated from: '<S1>/SumCtrl' */
  control_DW.TmpRTBAtSumCtrlInport2_Buffer0 = rtb_ESO[2];

  /* RateTransition generated from: '<S1>/SumRef' */
  control_DW.TmpRTBAtSumRefInport2_Buffer0 = rtb_ESO[0];

  /* RateTransition generated from: '<S1>/SumV' */
  control_DW.TmpRTBAtSumVInport2_Buffer0 = rtb_Kd;

  /* Update for DiscreteStateSpace: '<S1>/ESO' */
  {
    real32_T xnew[3];
    xnew[0] = (0.752593219F)*control_DW.ESO_DSTATE[0] + (0.000876296603F)*
      control_DW.ESO_DSTATE[1]
      + (4.38148305E-7F)*control_DW.ESO_DSTATE[2];
    xnew[0] += (-1.09537073E-8F)*rtb_TmpRTBAtESOInport1[0] + (0.247406796F)*
      rtb_TmpRTBAtESOInport1[1];
    xnew[1] = (-21.6134167F)*control_DW.ESO_DSTATE[0] + (0.98919332F)*
      control_DW.ESO_DSTATE[1]
      + (0.00099459663F)*control_DW.ESO_DSTATE[2];
    xnew[1] += (-2.48649158E-5F)*rtb_TmpRTBAtESOInport1[0] + (21.6134167F)*
      rtb_TmpRTBAtESOInport1[1];
    xnew[2] = (-638.820251F)*control_DW.ESO_DSTATE[0] + (-0.319410115F)*
      control_DW.ESO_DSTATE[1]
      + (0.999840319F)*control_DW.ESO_DSTATE[2];
    xnew[2] += (3.99262626E-6F)*rtb_TmpRTBAtESOInport1[0] + (638.820251F)*
      rtb_TmpRTBAtESOInport1[1];
    (void) memcpy(&control_DW.ESO_DSTATE[0], xnew,
                  sizeof(real32_T)*3);
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model initialize function */
void control_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */

  /* InitializeConditions for DiscreteStateSpace: '<S1>/ESO' */
  control_DW.ESO_DSTATE[0] = (0.0225F);
  control_DW.ESO_DSTATE[1] = (0.0F);
  control_DW.ESO_DSTATE[2] = (0.0F);

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
}

/* Model terminate function */
void control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
