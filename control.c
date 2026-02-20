/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control.c
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.86
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Feb 20 16:34:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "control.h"
#include "rtwtypes.h"

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
  real32_T rtb_UnitDelay;
  int8_T tmp_0;
  int8_T tmp_1;
  boolean_T tmp;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* RateTransition: '<S1>/Rate Transition' incorporates:
   *  RateTransition generated from: '<S1>/Unit Delay'
   */
  tmp = control_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    /* RateTransition: '<S1>/Rate Transition' */
    control_B.RateTransition = control_DW.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition' */

  /* Sum: '<S1>/Add2' incorporates:
   *  Inport: '<Root>/corriente_real'
   */
  rtb_ErrorCorriente = control_B.RateTransition - control_U.corriente_real;

  /* Gain: '<S39>/Proportional Gain' incorporates:
   *  Sum: '<S50>/Sum Fdbk'
   */
  rtb_DeadZone = (rtb_ErrorCorriente + control_DW.Integrator_DSTATE) * 20.0F;

  /* DeadZone: '<S32>/DeadZone' */
  if (rtb_DeadZone > 352.2F) {
    rtb_DeadZone -= 352.2F;
  } else if (rtb_DeadZone >= -352.2F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -352.2F;
  }

  /* End of DeadZone: '<S32>/DeadZone' */

  /* Gain: '<S37>/Integral Gain' */
  rtb_UnitDelay = 400.0F * rtb_ErrorCorriente;

  /* Switch: '<S30>/Switch3' incorporates:
   *  Constant: '<S30>/Clamping_zero'
   *  Constant: '<S30>/Constant6'
   *  Constant: '<S30>/Constant7'
   *  RelationalOperator: '<S30>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S30>/Switch2' incorporates:
   *  Constant: '<S30>/Clamping_zero'
   *  Constant: '<S30>/Constant4'
   *  Constant: '<S30>/Constant5'
   *  RelationalOperator: '<S30>/fix for DT propagation issue1'
   */
  if (rtb_UnitDelay > 0.0F) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Clamping_zero'
   *  Constant: '<S30>/Constant1'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  Switch: '<S30>/Switch2'
   *  Switch: '<S30>/Switch3'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp_0 == tmp_1)) {
    rtb_UnitDelay = 0.0F;
  }

  /* End of Switch: '<S30>/Switch' */

  /* DiscreteIntegrator: '<S40>/Integrator' */
  rtb_DeadZone = 0.00025F * rtb_UnitDelay;

  /* DiscreteIntegrator: '<S40>/Integrator' */
  rtb_UnitDelay = rtb_DeadZone + control_DW.Integrator_DSTATE;

  /* DiscreteIntegrator: '<S40>/Integrator' */
  if (rtb_UnitDelay > 352.2F) {
    /* DiscreteIntegrator: '<S40>/Integrator' */
    rtb_UnitDelay = 352.2F;
  } else if (rtb_UnitDelay < -352.2F) {
    /* DiscreteIntegrator: '<S40>/Integrator' */
    rtb_UnitDelay = -352.2F;
  }

  /* RateTransition generated from: '<S1>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  if (tmp) {
    control_DW.TmpRTBAtUnitDelayOutport1_Buffe = control_DW.UnitDelay_DSTATE;
  }

  /* Update for DiscreteIntegrator: '<S40>/Integrator' */
  control_DW.Integrator_DSTATE = rtb_DeadZone + rtb_UnitDelay;
  if (control_DW.Integrator_DSTATE > 352.2F) {
    control_DW.Integrator_DSTATE = 352.2F;
  } else if (control_DW.Integrator_DSTATE < -352.2F) {
    control_DW.Integrator_DSTATE = -352.2F;
  }

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Inport: '<Root>/corriente_real'
   */
  control_DW.UnitDelay_DSTATE = control_U.corriente_real;

  /* Gain: '<S38>/Proportional Gain' incorporates:
   *  Sum: '<S49>/Sum'
   */
  control_Y.Voltage = (rtb_ErrorCorriente + rtb_UnitDelay) * 20.0F;

  /* Saturate: '<S47>/Saturation' */
  if (control_Y.Voltage > 352.2F) {
    /* Gain: '<S38>/Proportional Gain' incorporates:
     *  Outport: '<Root>/Voltage'
     */
    control_Y.Voltage = 352.2F;
  } else if (control_Y.Voltage < -352.2F) {
    /* Gain: '<S38>/Proportional Gain' incorporates:
     *  Outport: '<Root>/Voltage'
     */
    control_Y.Voltage = -352.2F;
  }

  /* End of Saturate: '<S47>/Saturation' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model step function for TID1 */
void control_step1(void)               /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_TmpRTBAtUnitDelayOutport1;
  real32_T rtb_DiscreteStateSpace[3];
  real32_T rtb_Corrientedereferencia;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* RateTransition generated from: '<S1>/Unit Delay' */
  rtb_TmpRTBAtUnitDelayOutport1 = control_DW.TmpRTBAtUnitDelayOutport1_Buffe;

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem' */
  /* DiscreteStateSpace: '<S3>/Discrete State-Space' incorporates:
   *  Inport: '<Root>/Gap'
   */
  {
    rtb_DiscreteStateSpace[0] = (0.82784909F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.000413924543F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (2.0696227E-7F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[0] += (-4.13924539E-8F)*rtb_TmpRTBAtUnitDelayOutport1
      + (0.17215091F)*control_U.Gap;
    rtb_DiscreteStateSpace[1] = (-21.44067F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.989279687F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.000494639855F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[1] += (-9.89279652E-5F)*rtb_TmpRTBAtUnitDelayOutport1
      + (21.44067F)*control_U.Gap;
    rtb_DiscreteStateSpace[2] = (-909.392212F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (-0.454696119F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.999772668F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[2] += (4.54696128E-5F)*rtb_TmpRTBAtUnitDelayOutport1
      + (909.392212F)*control_U.Gap;
  }

  /* Update for DiscreteStateSpace: '<S3>/Discrete State-Space' incorporates:
   *  Inport: '<Root>/Gap'
   */
  {
    real32_T xnew[3];
    xnew[0] = (0.65569818F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.000827849086F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (4.13924539E-7F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[0] += (-8.27849078E-8F)*rtb_TmpRTBAtUnitDelayOutport1 + (0.34430182F)*
      control_U.Gap;
    xnew[1] = (-42.88134F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.978559315F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.00098927971F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[1] += (-0.00019785593F)*rtb_TmpRTBAtUnitDelayOutport1 + (42.88134F)*
      control_U.Gap;
    xnew[2] = (-1818.78442F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (-0.909392238F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.999545276F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[2] += (9.09392256E-5F)*rtb_TmpRTBAtUnitDelayOutport1 + (1818.78442F)*
      control_U.Gap;
    (void) memcpy(&control_DW.DiscreteStateSpace_DSTATE[0], xnew,
                  sizeof(real32_T)*3);
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* Gain: '<S1>/Gain' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Inport: '<Root>/Referencia'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum13'
   *  Sum: '<S1>/Sum5'
   */
  rtb_Corrientedereferencia = (((control_U.Referencia - rtb_DiscreteStateSpace[0])
    * 625.0F - 50.0F * rtb_DiscreteStateSpace[1]) - rtb_DiscreteStateSpace[2]) *
    -5.0F;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Corrientedereferencia > 50.0F) {
    rtb_Corrientedereferencia = 50.0F;
  } else if (rtb_Corrientedereferencia < -50.0F) {
    rtb_Corrientedereferencia = -50.0F;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* RateTransition: '<S1>/Rate Transition' */
  control_DW.RateTransition_Buffer0 = rtb_Corrientedereferencia;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/z3' */
  control_Y.z3 = rtb_DiscreteStateSpace[2];

  /* Outport: '<Root>/z1' */
  control_Y.z1 = rtb_DiscreteStateSpace[0];

  /* Outport: '<Root>/z2' */
  control_Y.z2 = rtb_DiscreteStateSpace[1];
}

/* Model initialize function */
void control_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/Subsystem' */
  /* InitializeConditions for DiscreteStateSpace: '<S3>/Discrete State-Space' incorporates:
   *  Inport: '<Root>/Gap'
   */
  control_DW.DiscreteStateSpace_DSTATE[0] = (0.0216F);
  control_DW.DiscreteStateSpace_DSTATE[1] = (0.0F);
  control_DW.DiscreteStateSpace_DSTATE[2] = (0.0F);

  /* End of SystemInitialize for SubSystem: '<S1>/Subsystem' */
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
