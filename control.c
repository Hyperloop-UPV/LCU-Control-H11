/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control.c
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.78
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Feb 16 13:00:40 2026
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
  real32_T rtb_PProdOut;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_Equal1;
  boolean_T rtb_RelationalOperator1;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* RateTransition: '<S1>/Rate Transition' */
  if (control_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<S1>/Rate Transition' */
    control_B.RateTransition = control_DW.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition' */

  /* Sum: '<S1>/Add2' incorporates:
   *  Inport: '<Root>/corriente_real'
   */
  rtb_ErrorCorriente = control_B.RateTransition - control_U.corriente_real;

  /* Product: '<S39>/PProd Out' incorporates:
   *  Inport: '<Root>/P'
   *  Sum: '<S50>/Sum Fdbk'
   */
  rtb_DeadZone = (rtb_ErrorCorriente + control_DW.Integrator_DSTATE) *
    control_U.P;

  /* DeadZone: '<S32>/DeadZone' */
  if (rtb_DeadZone > 400.0F) {
    rtb_DeadZone -= 400.0F;
  } else if (rtb_DeadZone >= -400.0F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -400.0F;
  }

  /* End of DeadZone: '<S32>/DeadZone' */

  /* Product: '<S37>/IProd Out' incorporates:
   *  Inport: '<Root>/I'
   */
  rtb_PProdOut = rtb_ErrorCorriente * control_U.I;

  /* Switch: '<S30>/Switch3' incorporates:
   *  Constant: '<S30>/Clamping_zero'
   *  Constant: '<S30>/Constant6'
   *  Constant: '<S30>/Constant7'
   *  RelationalOperator: '<S30>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S30>/Switch2' incorporates:
   *  Constant: '<S30>/Clamping_zero'
   *  Constant: '<S30>/Constant4'
   *  Constant: '<S30>/Constant5'
   *  RelationalOperator: '<S30>/fix for DT propagation issue1'
   */
  if (rtb_PProdOut > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* RelationalOperator: '<S30>/Equal1' incorporates:
   *  Switch: '<S30>/Switch2'
   *  Switch: '<S30>/Switch3'
   */
  rtb_Equal1 = (tmp == tmp_0);

  /* RelationalOperator: '<S30>/Relational Operator1' incorporates:
   *  Constant: '<S30>/Clamping_zero'
   *  Inport: '<Root>/P'
   */
  rtb_RelationalOperator1 = (control_U.P > 0.0F);

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Clamping_zero'
   *  Constant: '<S30>/Constant1'
   *  Logic: '<S30>/AND1'
   *  Logic: '<S30>/AND2'
   *  Logic: '<S30>/AND3'
   *  Logic: '<S30>/NOT1'
   *  Logic: '<S30>/NOT2'
   *  Logic: '<S30>/OR1'
   *  RelationalOperator: '<S30>/Relational Operator'
   */
  if ((rtb_DeadZone != 0.0F) && ((rtb_Equal1 && rtb_RelationalOperator1) ||
       ((!rtb_Equal1) && (!rtb_RelationalOperator1)))) {
    rtb_PProdOut = 0.0F;
  }

  /* End of Switch: '<S30>/Switch' */

  /* DiscreteIntegrator: '<S40>/Integrator' */
  rtb_DeadZone = 0.00025F * rtb_PProdOut;

  /* DiscreteIntegrator: '<S40>/Integrator' */
  rtb_PProdOut = rtb_DeadZone + control_DW.Integrator_DSTATE;

  /* DiscreteIntegrator: '<S40>/Integrator' */
  if (rtb_PProdOut > 400.0F) {
    /* DiscreteIntegrator: '<S40>/Integrator' */
    rtb_PProdOut = 400.0F;
  } else if (rtb_PProdOut < -400.0F) {
    /* DiscreteIntegrator: '<S40>/Integrator' */
    rtb_PProdOut = -400.0F;
  }

  /* Update for DiscreteIntegrator: '<S40>/Integrator' */
  control_DW.Integrator_DSTATE = rtb_DeadZone + rtb_PProdOut;
  if (control_DW.Integrator_DSTATE > 400.0F) {
    control_DW.Integrator_DSTATE = 400.0F;
  } else if (control_DW.Integrator_DSTATE < -400.0F) {
    control_DW.Integrator_DSTATE = -400.0F;
  }

  /* Product: '<S38>/PProd Out' incorporates:
   *  Inport: '<Root>/P'
   *  Sum: '<S49>/Sum'
   */
  control_Y.Voltage = (rtb_ErrorCorriente + rtb_PProdOut) * control_U.P;

  /* Saturate: '<S47>/Saturation' */
  if (control_Y.Voltage > 400.0F) {
    /* Product: '<S38>/PProd Out' incorporates:
     *  Outport: '<Root>/Voltage'
     */
    control_Y.Voltage = 400.0F;
  } else if (control_Y.Voltage < -400.0F) {
    /* Product: '<S38>/PProd Out' incorporates:
     *  Outport: '<Root>/Voltage'
     */
    control_Y.Voltage = -400.0F;
  }

  /* End of Saturate: '<S47>/Saturation' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model step function for TID1 */
void control_step1(void)               /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_UnitDelay;
  real32_T rtb_DiscreteStateSpace[3];

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* UnitDelay: '<S1>/Unit Delay' */
  rtb_UnitDelay = control_DW.UnitDelay_DSTATE;

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem' */
  /* DiscreteStateSpace: '<S3>/Discrete State-Space' incorporates:
   *  Inport: '<Root>/Gap'
   */
  {
    rtb_DiscreteStateSpace[0] = (0.915141642F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.00045757083F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (2.2878541E-7F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[0] += (-2.28785417E-8F)*rtb_UnitDelay + (0.084858343F)*
      control_U.Gap;
    rtb_DiscreteStateSpace[1] = (-4.9911828F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.997504413F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.000498752226F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[1] += (-4.98752197E-5F)*rtb_UnitDelay + (4.9911828F)*
      control_U.Gap;
    rtb_DiscreteStateSpace[2] = (-98.8353F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (-0.0494176485F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.999975264F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[2] += (2.47088246E-6F)*rtb_UnitDelay + (98.8353F)*
      control_U.Gap;
  }

  /* Update for DiscreteStateSpace: '<S3>/Discrete State-Space' incorporates:
   *  Inport: '<Root>/Gap'
   */
  {
    real32_T xnew[3];
    xnew[0] = (0.830283344F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.00091514166F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (4.5757082E-7F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[0] += (-4.57570835E-8F)*rtb_UnitDelay + (0.169716686F)*control_U.Gap;
    xnew[1] = (-9.98236561F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.995008826F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.000997504452F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[1] += (-9.97504394E-5F)*rtb_UnitDelay + (9.98236561F)*control_U.Gap;
    xnew[2] = (-197.670593F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (-0.0988353F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.999950588F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[2] += (4.94176493E-6F)*rtb_UnitDelay + (197.670593F)*control_U.Gap;
    (void) memcpy(&control_DW.DiscreteStateSpace_DSTATE[0], xnew,
                  sizeof(real32_T)*3);
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* Product: '<S1>/Divide' incorporates:
   *  Inport: '<Root>/K_D'
   *  Inport: '<Root>/K_P'
   *  Inport: '<Root>/Referencia'
   *  Inport: '<Root>/b_0'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum13'
   *  Sum: '<S1>/Sum5'
   */
  control_DW.UnitDelay_DSTATE = (((control_U.Referencia -
    rtb_DiscreteStateSpace[0]) * control_U.K_P - rtb_DiscreteStateSpace[1] *
    control_U.K_D) - rtb_DiscreteStateSpace[2]) / control_U.b_0;

  /* Saturate: '<S1>/Saturation' */
  if (control_DW.UnitDelay_DSTATE > 50.0F) {
    /* Product: '<S1>/Divide' */
    control_DW.UnitDelay_DSTATE = 50.0F;
  } else if (control_DW.UnitDelay_DSTATE < -50.0F) {
    /* Product: '<S1>/Divide' */
    control_DW.UnitDelay_DSTATE = -50.0F;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* RateTransition: '<S1>/Rate Transition' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  control_DW.RateTransition_Buffer0 = control_DW.UnitDelay_DSTATE;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model initialize function */
void control_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/Subsystem' */
  /* InitializeConditions for DiscreteStateSpace: '<S3>/Discrete State-Space' incorporates:
   *  Inport: '<Root>/Gap'
   */
  control_DW.DiscreteStateSpace_DSTATE[0] = (0.0225F);
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
