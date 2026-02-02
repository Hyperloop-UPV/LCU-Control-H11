/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control.c
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Jan 31 19:32:33 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "control.h"
#include "rtwtypes.h"
#include "control_private.h"
#include <string.h>

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
  real32_T rtb_IntegralGain;
  int8_T tmp;
  int8_T tmp_0;

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
  rtb_IntegralGain = control_B.RateTransition - control_U.corriente_real;

  /* Gain: '<S38>/Proportional Gain' incorporates:
   *  DiscreteIntegrator: '<S40>/Integrator'
   *  Sum: '<S49>/Sum'
   */
  control_B.Saturation = (rtb_IntegralGain + control_DW.Integrator_DSTATE) *
    22.9546F;

  /* DeadZone: '<S32>/DeadZone' incorporates:
   *  Saturate: '<S47>/Saturation'
   */
  if (control_B.Saturation > 400.0F) {
    rtb_DeadZone = control_B.Saturation - 400.0F;

    /* Gain: '<S38>/Proportional Gain' incorporates:
     *  Saturate: '<S47>/Saturation'
     */
    control_B.Saturation = 400.0F;
  } else {
    if (control_B.Saturation >= -400.0F) {
      rtb_DeadZone = 0.0F;
    } else {
      rtb_DeadZone = control_B.Saturation - -400.0F;
    }

    if (control_B.Saturation < -400.0F) {
      /* Gain: '<S38>/Proportional Gain' incorporates:
       *  Saturate: '<S47>/Saturation'
       */
      control_B.Saturation = -400.0F;
    }
  }

  /* End of DeadZone: '<S32>/DeadZone' */

  /* Gain: '<S37>/Integral Gain' */
  rtb_IntegralGain *= 208.333298F;

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
  if (rtb_IntegralGain > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
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
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IntegralGain = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S40>/Integrator' incorporates:
   *  Switch: '<S30>/Switch'
   */
  control_DW.Integrator_DSTATE += 0.0005F * rtb_IntegralGain;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Voltage' */
  control_Y.Voltage = control_B.Saturation;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  control_M->Timing.taskTime0 =
    ((time_T)(++control_M->Timing.clockTick0)) * control_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void control_step1(void)               /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_UnitDelay;
  real32_T u0;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* UnitDelay: '<S1>/Unit Delay' */
  rtb_UnitDelay = control_DW.UnitDelay_DSTATE;

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem' */
  /* DiscreteStateSpace: '<S3>/Discrete State-Space' incorporates:
   *  Inport: '<Root>/Gap'
   */
  {
    control_B.DiscreteStateSpace[0] = (0.915141642F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.00045757083F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (2.2878541E-7F)*control_DW.DiscreteStateSpace_DSTATE[2];
    control_B.DiscreteStateSpace[0] += (-2.28785417E-8F)*rtb_UnitDelay +
      (0.084858343F)*control_U.Gap;
    control_B.DiscreteStateSpace[1] = (-4.9911828F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.997504413F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.000498752226F)*control_DW.DiscreteStateSpace_DSTATE[2];
    control_B.DiscreteStateSpace[1] += (-4.98752197E-5F)*rtb_UnitDelay +
      (4.9911828F)*control_U.Gap;
    control_B.DiscreteStateSpace[2] = (-98.8353F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (-0.0494176485F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.999975264F)*control_DW.DiscreteStateSpace_DSTATE[2];
    control_B.DiscreteStateSpace[2] += (2.47088246E-6F)*rtb_UnitDelay +
      (98.8353F)*control_U.Gap;
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
  /* Gain: '<S1>/b0' incorporates:
   *  Gain: '<S1>/Kd'
   *  Gain: '<S1>/Kp'
   *  Inport: '<Root>/Referencia'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum13'
   *  Sum: '<S1>/Sum5'
   */
  u0 = (((control_U.Referencia - control_B.DiscreteStateSpace[0]) * 1600.0F -
         80.0F * control_B.DiscreteStateSpace[1]) -
        control_B.DiscreteStateSpace[2]) * -10.0F;

  /* Saturate: '<S1>/Saturation' */
  if (u0 > 50.0F) {
    /* Saturate: '<S1>/Saturation' */
    control_B.Corrientedereferencia = 50.0F;
  } else if (u0 < -50.0F) {
    /* Saturate: '<S1>/Saturation' */
    control_B.Corrientedereferencia = -50.0F;
  } else {
    /* Saturate: '<S1>/Saturation' */
    control_B.Corrientedereferencia = u0;
  }

  /* End of Saturate: '<S1>/Saturation' */
  /* RateTransition: '<S1>/Rate Transition' */
  control_DW.RateTransition_Buffer0 = control_B.Corrientedereferencia;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  control_DW.UnitDelay_DSTATE = control_B.Corrientedereferencia;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  control_M->Timing.clockTick1++;
}

/* Model initialize function */
void control_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)control_M, 0,
                sizeof(RT_MODEL_control_T));
  rtmSetTFinal(control_M, -1);
  control_M->Timing.stepSize0 = 0.0005;

  /* External mode info */
  control_M->Sizes.checksums[0] = (2865505258U);
  control_M->Sizes.checksums[1] = (3979209131U);
  control_M->Sizes.checksums[2] = (1347307208U);
  control_M->Sizes.checksums[3] = (1713624325U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(control_M->extModeInfo,
      &control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(control_M->extModeInfo, control_M->Sizes.checksums);
    rteiSetTPtr(control_M->extModeInfo, rtmGetTPtr(control_M));
  }

  /* block I/O */
  (void) memset(((void *) &control_B), 0,
                sizeof(B_control_T));

  /* states (dwork) */
  (void) memset((void *)&control_DW, 0,
                sizeof(DW_control_T));

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
