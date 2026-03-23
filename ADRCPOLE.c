/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADRCPOLE.c
 *
 * Code generated for Simulink model 'ADRCPOLE'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Mar  8 00:33:23 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADRCPOLE.h"
#include "rtwtypes.h"
#include "ADRCPOLE_private.h"
#include <math.h>
#include <string.h>

/* Block states (default storage) */
DW_ADRCPOLE_T ADRCPOLE_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ADRCPOLE_T ADRCPOLE_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ADRCPOLE_T ADRCPOLE_Y;

/* Real-time model */
static RT_MODEL_ADRCPOLE_T ADRCPOLE_M_;
RT_MODEL_ADRCPOLE_T *const ADRCPOLE_M = &ADRCPOLE_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ADRCPOLE_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ADRCPOLE_M, 1));
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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ADRCPOLE_M->Timing.TaskCounters.TID[1])++;
  if ((ADRCPOLE_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    ADRCPOLE_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/Simulink1'
 *    '<S3>/Simulink2'
 *    '<S3>/Simulink3'
 *    '<S3>/Simulink4'
 */
void ADRCPOLE_Simulink1_Init(DW_Simulink1_ADRCPOLE_T *localDW)
{
  /* InitializeConditions for DiscreteStateSpace: '<S6>/Discrete State-Space' */
  localDW->DiscreteStateSpace_DSTATE[0] = (0.0225);
  localDW->DiscreteStateSpace_DSTATE[1] = (0.0);
  localDW->DiscreteStateSpace_DSTATE[2] = (0.0);
}

/*
 * Output and update for atomic system:
 *    '<S3>/Simulink1'
 *    '<S3>/Simulink2'
 *    '<S3>/Simulink3'
 *    '<S3>/Simulink4'
 */
void ADRCPOLE_Simulink1(real_T rtu_ref_out, real_T rtu_y_out, real_T *rty_u_out,
  real_T rty_Out1[3], DW_Simulink1_ADRCPOLE_T *localDW)
{
  /* local block i/o variables */
  real_T rtb_UnitDelay;
  real_T u0;

  /* UnitDelay: '<S6>/Unit Delay' */
  rtb_UnitDelay = localDW->UnitDelay_DSTATE;

  /* DiscreteStateSpace: '<S6>/Discrete State-Space' */
  {
    rty_Out1[0] = (0.87629657983779907)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.00043814830132760108)*localDW->DiscreteStateSpace_DSTATE[1]
      + (2.1907415259647678E-7)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[0] += (-3.2861123600014253E-8)*rtb_UnitDelay + (0.12370339781045914)*
      rtu_y_out;
    rty_Out1[1] = (-10.806708335876465)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.99459666013717651)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.00049729831516742706)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[1] += (-7.4594754551071674E-5)*rtb_UnitDelay + (10.806708335876465)*
      rtu_y_out;
    rty_Out1[2] = (-319.41012573242188)*localDW->DiscreteStateSpace_DSTATE[0]
      + (-0.15970505774021149)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.999920129776001)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[2] += (1.1977879694313742E-5)*rtb_UnitDelay + (319.41012573242188)*
      rtu_y_out;
  }

  /* Gain: '<S6>/b0' incorporates:
   *  Gain: '<S6>/Kd'
   *  Gain: '<S6>/Kp'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum13'
   *  Sum: '<S6>/Sum5'
   */
  u0 = (((rtu_ref_out - rty_Out1[0]) * 625.0 - 50.0 * rty_Out1[1]) - rty_Out1[2])
    * -6.666666666666667;

  /* Saturate: '<S6>/Saturation' */
  if (u0 > 50.0) {
    *rty_u_out = 50.0;
  } else if (u0 < -50.0) {
    *rty_u_out = -50.0;
  } else {
    *rty_u_out = u0;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_u_out;

  /* Update for DiscreteStateSpace: '<S6>/Discrete State-Space' */
  {
    real_T xnew[3];
    xnew[0] = (0.75259321928024292)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.00087629660265520215)*localDW->DiscreteStateSpace_DSTATE[1]
      + (4.3814830519295356E-7)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[0] += (-6.57222472000285E-8)*rtb_UnitDelay + (0.24740679562091827)*
      rtu_y_out;
    xnew[1] = (-21.61341667175293)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.989193320274353)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.00099459663033485413)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[1] += (-0.00014918950910214335)*rtb_UnitDelay + (21.61341667175293)*
      rtu_y_out;
    xnew[2] = (-638.82025146484375)*localDW->DiscreteStateSpace_DSTATE[0]
      + (-0.319410115480423)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.99984031915664673)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[2] += (2.3955759388627484E-5)*rtb_UnitDelay + (638.82025146484375)*
      rtu_y_out;
    (void) memcpy(&localDW->DiscreteStateSpace_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }
}

/*
 * System initialize for atomic system:
 *    '<S10>/Simulink1'
 *    '<S10>/Simulink2'
 *    '<S10>/Simulink3'
 *    '<S10>/Simulink4'
 *    '<S10>/Simulink5'
 *    '<S10>/Simulink6'
 */
void ADRCPOLE_Simulink1_k_Init(DW_Simulink1_ADRCPOLE_i_T *localDW)
{
  /* InitializeConditions for DiscreteStateSpace: '<S11>/Discrete State-Space' */
  localDW->DiscreteStateSpace_DSTATE[0] = (0.001);
  localDW->DiscreteStateSpace_DSTATE[1] = (0.0);
  localDW->DiscreteStateSpace_DSTATE[2] = (0.0);
}

/*
 * Output and update for atomic system:
 *    '<S10>/Simulink1'
 *    '<S10>/Simulink2'
 *    '<S10>/Simulink3'
 *    '<S10>/Simulink4'
 *    '<S10>/Simulink5'
 *    '<S10>/Simulink6'
 */
void ADRCPOLE_Simulink1_m(real_T rtu_ref_out, real_T rtu_y_out, real_T
  *rty_u_out, real_T rty_Out1[3], DW_Simulink1_ADRCPOLE_i_T *localDW)
{
  /* local block i/o variables */
  real_T rtb_UnitDelay_k;
  real_T u0;

  /* UnitDelay: '<S11>/Unit Delay' */
  rtb_UnitDelay_k = localDW->UnitDelay_DSTATE;

  /* DiscreteStateSpace: '<S11>/Discrete State-Space' */
  {
    rty_Out1[0] = (0.942322313785553)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.00047116115456447005)*localDW->DiscreteStateSpace_DSTATE[1]
      + (2.3558058614980837E-7)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[0] += (-4.7116117229961674E-8)*rtb_UnitDelay_k +
      (0.057677663862705231)*rtu_y_out;
    rty_Out1[1] = (-2.2766506671905518)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.99886167049407959)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.00049943081103265285)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[1] += (-9.9886172392871231E-5)*rtb_UnitDelay_k +
      (2.2766506671905518)*rtu_y_out;
    rty_Out1[2] = (-30.154314041137695)*localDW->DiscreteStateSpace_DSTATE[0]
      + (-0.015077156946063042)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.9999924898147583)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[2] += (1.5077157513587736E-6)*rtb_UnitDelay_k + (30.154314041137695)*
      rtu_y_out;
  }

  /* Gain: '<S11>/b0' incorporates:
   *  Gain: '<S11>/Kd'
   *  Gain: '<S11>/Kp'
   *  Sum: '<S11>/Sum1'
   *  Sum: '<S11>/Sum13'
   *  Sum: '<S11>/Sum5'
   */
  u0 = (((rtu_ref_out - rty_Out1[0]) * 36.0 - 12.0 * rty_Out1[1]) - rty_Out1[2])
    * -5.0;

  /* Saturate: '<S11>/Saturation' */
  if (u0 > 50.0) {
    *rty_u_out = 50.0;
  } else if (u0 < 0.0) {
    *rty_u_out = 0.0;
  } else {
    *rty_u_out = u0;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_u_out;

  /* Update for DiscreteStateSpace: '<S11>/Discrete State-Space' */
  {
    real_T xnew[3];
    xnew[0] = (0.88464468717575073)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.00094232230912894011)*localDW->DiscreteStateSpace_DSTATE[1]
      + (4.7116117229961674E-7)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[0] += (-9.4232234459923347E-8)*rtb_UnitDelay_k + (0.11535532772541046)*
      rtu_y_out;
    xnew[1] = (-4.5533013343811035)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.99772334098815918)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.00099886162206530571)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[1] += (-0.00019977234478574246)*rtb_UnitDelay_k + (4.5533013343811035)*
      rtu_y_out;
    xnew[2] = (-60.308628082275391)*localDW->DiscreteStateSpace_DSTATE[0]
      + (-0.030154313892126083)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.99998492002487183)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[2] += (3.0154315027175471E-6)*rtb_UnitDelay_k + (60.308628082275391)*
      rtu_y_out;
    (void) memcpy(&localDW->DiscreteStateSpace_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }
}

/* Model step function for TID0 */
void ADRCPOLE_step0(void)              /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void ADRCPOLE_step1(void)              /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_airgaps_locales[10];
  real_T rtb_DiscreteStateSpace[3];
  real_T rotx;
  real_T rotz;
  real_T rtb_u_idx_0;
  real_T rtb_u_idx_1;
  real_T y_aux_tmp;
  real_T z_aux_data_idx_0;
  real_T z_aux_data_idx_1;
  real_T z_aux_data_idx_2;
  real_T z_aux_data_idx_3;
  real_T z_aux_tmp;
  real_T z_aux_tmp_0;
  real_T z_aux_tmp_1;

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Airgaps'
   */
  rotx = ((real_T)asinf((ADRCPOLE_U.Airgaps[0] - ADRCPOLE_U.Airgaps[1]) /
                        0.43496F) + asinf((ADRCPOLE_U.Airgaps[2] -
            ADRCPOLE_U.Airgaps[3]) / 0.43496F)) / 2.0;
  rotz = ((real_T)asinf((ADRCPOLE_U.Airgaps[4] - ADRCPOLE_U.Airgaps[6]) / 2.019F)
          + asinf((ADRCPOLE_U.Airgaps[7] - ADRCPOLE_U.Airgaps[5]) / 2.019F)) /
    2.0;
  z_aux_tmp = sin(rotx);
  z_aux_tmp_0 = sin(((real_T)asinf((ADRCPOLE_U.Airgaps[0] - ADRCPOLE_U.Airgaps[2])
    / 2.0186F) + asinf((ADRCPOLE_U.Airgaps[1] - ADRCPOLE_U.Airgaps[3]) / 2.0186F))
                    / 2.0);
  rotx = cos(rotx);
  z_aux_tmp_1 = 1.0093 * z_aux_tmp;
  rtb_u_idx_0 = 0.21748 * z_aux_tmp_0;
  rtb_u_idx_1 = 0.05459 * rotx;
  z_aux_data_idx_0 = -ADRCPOLE_U.Airgaps[0] - (real32_T)(((-0.03905 -
    z_aux_tmp_1) - rtb_u_idx_0) - rtb_u_idx_1);
  z_aux_data_idx_1 = -ADRCPOLE_U.Airgaps[1] - (real32_T)(((z_aux_tmp_1 - 0.03905)
    - rtb_u_idx_0) - rtb_u_idx_1);
  z_aux_data_idx_2 = -ADRCPOLE_U.Airgaps[2] - (real32_T)(((-0.03905 -
    z_aux_tmp_1) + rtb_u_idx_0) - rtb_u_idx_1);
  z_aux_data_idx_3 = -ADRCPOLE_U.Airgaps[3] - (real32_T)(((z_aux_tmp_1 - 0.03905)
    + rtb_u_idx_0) - rtb_u_idx_1);
  z_aux_tmp_1 = sin(rotz);
  rotz = cos(rotz);
  rtb_u_idx_0 = 0.1347 * rotz;
  rtb_u_idx_1 = 0.18782 * z_aux_tmp;
  y_aux_tmp = -1.0095 * z_aux_tmp_1 + rtb_u_idx_0;
  rtb_u_idx_0 += 1.0095 * z_aux_tmp_1;
  rtb_u_idx_0 = ((((real_T)((real32_T)(y_aux_tmp - rtb_u_idx_1) +
    (ADRCPOLE_U.Airgaps[4] - 0.271F)) + ((-ADRCPOLE_U.Airgaps[5] + 0.271F) -
    (real32_T)(rtb_u_idx_0 + rtb_u_idx_1))) + ((real32_T)(rtb_u_idx_0 -
    rtb_u_idx_1) + (ADRCPOLE_U.Airgaps[6] - 0.271F))) + ((-ADRCPOLE_U.Airgaps[7]
    + 0.271F) - (real32_T)(y_aux_tmp + rtb_u_idx_1))) / 4.0;
  rtb_u_idx_1 = (((z_aux_data_idx_0 + z_aux_data_idx_1) + z_aux_data_idx_2) +
                 z_aux_data_idx_3) / 4.0;

  /* MATLAB Function: '<S3>/MATLAB Function1' */
  z_aux_tmp_0 *= 0.191;
  rotx *= 0.05405;
  y_aux_tmp = 0.6475 * z_aux_tmp;
  rtb_airgaps_locales[0] = fabs((y_aux_tmp + z_aux_tmp_0) - rotx) + (rtb_u_idx_1
    - 0.05405);
  z_aux_data_idx_0 = -0.6475 * z_aux_tmp;
  rtb_airgaps_locales[1] = fabs((z_aux_data_idx_0 + z_aux_tmp_0) - rotx) +
    (rtb_u_idx_1 - 0.05405);
  rtb_airgaps_locales[2] = fabs((y_aux_tmp - z_aux_tmp_0) - rotx) + (rtb_u_idx_1
    - 0.05405);
  rtb_airgaps_locales[3] = fabs((z_aux_data_idx_0 - z_aux_tmp_0) - rotx) +
    (rtb_u_idx_1 - 0.05405);
  z_aux_tmp_0 = 0.788 * z_aux_tmp_1;
  rotx = 0.268 * rotz;
  y_aux_tmp = 0.20255 * z_aux_tmp;
  rtb_airgaps_locales[4] = 0.268 - (((-rtb_u_idx_0 - z_aux_tmp_0) + rotx) -
    y_aux_tmp);
  rtb_airgaps_locales[5] = 0.268 - (((z_aux_tmp_0 + rtb_u_idx_0) + rotx) +
    y_aux_tmp);
  z_aux_data_idx_0 = 0.0 * z_aux_tmp_1;
  rtb_airgaps_locales[6] = 0.268 - (((z_aux_data_idx_0 - rtb_u_idx_0) + rotx) -
    y_aux_tmp);
  rtb_airgaps_locales[7] = 0.268 - (((z_aux_data_idx_0 + rtb_u_idx_0) + rotx) +
    y_aux_tmp);
  rtb_airgaps_locales[8] = 0.268 - (((z_aux_tmp_0 - rtb_u_idx_0) + rotx) -
    y_aux_tmp);
  rtb_airgaps_locales[9] = 0.268 - (((rtb_u_idx_0 - z_aux_tmp_0) + rotx) +
    y_aux_tmp);

  /* Outputs for Atomic SubSystem: '<S3>/Simulink1' */

  /* Outport: '<Root>/I' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   */
  ADRCPOLE_Simulink1(0.01636, rtb_airgaps_locales[0], &ADRCPOLE_Y.I[0],
                     rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink1);

  /* End of Outputs for SubSystem: '<S3>/Simulink1' */

  /* Outputs for Atomic SubSystem: '<S3>/Simulink4' */
  ADRCPOLE_Simulink1(0.01636, rtb_airgaps_locales[1], &ADRCPOLE_Y.I[1],
                     rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink4);

  /* End of Outputs for SubSystem: '<S3>/Simulink4' */

  /* Outputs for Atomic SubSystem: '<S3>/Simulink2' */
  ADRCPOLE_Simulink1(0.01636, rtb_airgaps_locales[2], &ADRCPOLE_Y.I[2],
                     rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink2);

  /* End of Outputs for SubSystem: '<S3>/Simulink2' */

  /* Outputs for Atomic SubSystem: '<S3>/Simulink3' */
  ADRCPOLE_Simulink1(0.01636, rtb_airgaps_locales[3], &ADRCPOLE_Y.I[3],
                     rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink3);

  /* End of Outputs for SubSystem: '<S3>/Simulink3' */

  /* Outputs for Atomic SubSystem: '<S10>/Simulink4' */
  ADRCPOLE_Simulink1_m(0.0, rtb_airgaps_locales[4], &ADRCPOLE_Y.I[4],
                       rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink4_o);

  /* End of Outputs for SubSystem: '<S10>/Simulink4' */

  /* Outputs for Atomic SubSystem: '<S10>/Simulink1' */
  ADRCPOLE_Simulink1_m(0.0, rtb_airgaps_locales[5], &ADRCPOLE_Y.I[5],
                       rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink1_m);

  /* End of Outputs for SubSystem: '<S10>/Simulink1' */

  /* Outputs for Atomic SubSystem: '<S10>/Simulink2' */
  ADRCPOLE_Simulink1_m(0.0, rtb_airgaps_locales[6], &ADRCPOLE_Y.I[6],
                       rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink2_b);

  /* End of Outputs for SubSystem: '<S10>/Simulink2' */

  /* Outputs for Atomic SubSystem: '<S10>/Simulink3' */
  ADRCPOLE_Simulink1_m(0.0, rtb_airgaps_locales[7], &ADRCPOLE_Y.I[7],
                       rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink3_j);

  /* End of Outputs for SubSystem: '<S10>/Simulink3' */

  /* Outputs for Atomic SubSystem: '<S10>/Simulink5' */
  ADRCPOLE_Simulink1_m(0.0, rtb_airgaps_locales[8], &ADRCPOLE_Y.I[8],
                       rtb_DiscreteStateSpace, &ADRCPOLE_DW.Simulink5);

  /* End of Outputs for SubSystem: '<S10>/Simulink5' */

  /* Outputs for Atomic SubSystem: '<S10>/Simulink6' */
  ADRCPOLE_Simulink1_m(0.0, 0.0, &ADRCPOLE_Y.I[9], rtb_DiscreteStateSpace,
                       &ADRCPOLE_DW.Simulink6);

  /* End of Outputs for SubSystem: '<S10>/Simulink6' */
}

/* Model initialize function */
void ADRCPOLE_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ADRCPOLE_M, 0,
                sizeof(RT_MODEL_ADRCPOLE_T));

  /* states (dwork) */
  (void) memset((void *)&ADRCPOLE_DW, 0,
                sizeof(DW_ADRCPOLE_T));

  /* SystemInitialize for Atomic SubSystem: '<S3>/Simulink1' */
  ADRCPOLE_Simulink1_Init(&ADRCPOLE_DW.Simulink1);

  /* End of SystemInitialize for SubSystem: '<S3>/Simulink1' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/Simulink2' */
  ADRCPOLE_Simulink1_Init(&ADRCPOLE_DW.Simulink2);

  /* End of SystemInitialize for SubSystem: '<S3>/Simulink2' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/Simulink3' */
  ADRCPOLE_Simulink1_Init(&ADRCPOLE_DW.Simulink3);

  /* End of SystemInitialize for SubSystem: '<S3>/Simulink3' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/Simulink4' */
  ADRCPOLE_Simulink1_Init(&ADRCPOLE_DW.Simulink4);

  /* End of SystemInitialize for SubSystem: '<S3>/Simulink4' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/Simulink1' */
  ADRCPOLE_Simulink1_k_Init(&ADRCPOLE_DW.Simulink1_m);

  /* End of SystemInitialize for SubSystem: '<S10>/Simulink1' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/Simulink2' */
  ADRCPOLE_Simulink1_k_Init(&ADRCPOLE_DW.Simulink2_b);

  /* End of SystemInitialize for SubSystem: '<S10>/Simulink2' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/Simulink3' */
  ADRCPOLE_Simulink1_k_Init(&ADRCPOLE_DW.Simulink3_j);

  /* End of SystemInitialize for SubSystem: '<S10>/Simulink3' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/Simulink4' */
  ADRCPOLE_Simulink1_k_Init(&ADRCPOLE_DW.Simulink4_o);

  /* End of SystemInitialize for SubSystem: '<S10>/Simulink4' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/Simulink5' */
  ADRCPOLE_Simulink1_k_Init(&ADRCPOLE_DW.Simulink5);

  /* End of SystemInitialize for SubSystem: '<S10>/Simulink5' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/Simulink6' */
  ADRCPOLE_Simulink1_k_Init(&ADRCPOLE_DW.Simulink6);

  /* End of SystemInitialize for SubSystem: '<S10>/Simulink6' */
}

/* Model terminate function */
void ADRCPOLE_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
