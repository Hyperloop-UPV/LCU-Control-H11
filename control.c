/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control.c
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Apr 30 22:43:24 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "control.h"
#include "rtwtypes.h"
#include "control_private.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"

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

/* Forward declaration for local functions */
static real_T control_xnrm2(int32_T n, const real_T x[12], int32_T ix0);
static void control_mldivide(const real_T A[12], const real32_T B[4], real32_T
  Y[3]);

/*
 * Output and update for atomic system:
 *    '<S1>/Simulink2'
 *    '<S1>/Simulink3'
 *    '<S1>/Simulink4'
 */
void control_Simulink2(real32_T rtu_ref_out, real32_T rtu_y_out, real32_T
  *rty_u_out, real32_T rty_Out1[3], DW_Simulink2_control_T *localDW)
{
  /* local block i/o variables */
  real32_T rtb_UnitDelay_e;
  real32_T u0;

  /* UnitDelay: '<S6>/Unit Delay' */
  rtb_UnitDelay_e = localDW->UnitDelay_DSTATE;

  /* DiscreteStateSpace: '<S6>/Discrete State-Space' */
  {
    rty_Out1[0] = (0.87629658F)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.000438148301F)*localDW->DiscreteStateSpace_DSTATE[1]
      + (2.19074153E-7F)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[0] += (0.123703398F)*rtb_UnitDelay_e + (7.63096808E-10F)*rtu_y_out;
    rty_Out1[1] = (-10.8067083F)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.99459666F)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.000497298315F)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[1] += (10.8067083F)*rtb_UnitDelay_e + (1.73222986E-6F)*rtu_y_out;
    rty_Out1[2] = (-319.410126F)*localDW->DiscreteStateSpace_DSTATE[0]
      + (-0.159705058F)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.99992013F)*localDW->DiscreteStateSpace_DSTATE[2];
    rty_Out1[2] += (319.410126F)*rtb_UnitDelay_e + (-2.78148804E-7F)*rtu_y_out;
  }

  /* Gain: '<S6>/b0' incorporates:
   *  Gain: '<S6>/Kd'
   *  Gain: '<S6>/Kp'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum13'
   *  Sum: '<S6>/Sum5'
   */
  u0 = (((rtu_ref_out - rty_Out1[0]) * 900.0F - 60.0F * rty_Out1[1]) - rty_Out1
        [2]) * 287.085F;

  /* Saturate: '<S6>/Saturation' */
  if (u0 > 50.0F) {
    *rty_u_out = 50.0F;
  } else if (u0 < -50.0F) {
    *rty_u_out = -50.0F;
  } else {
    *rty_u_out = u0;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_u_out;

  /* Update for DiscreteStateSpace: '<S6>/Discrete State-Space' */
  {
    real32_T xnew[3];
    xnew[0] = (0.752593219F)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.000876296603F)*localDW->DiscreteStateSpace_DSTATE[1]
      + (4.38148305E-7F)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[0] += (0.247406796F)*rtb_UnitDelay_e + (1.52619362E-9F)*rtu_y_out;
    xnew[1] = (-21.6134167F)*localDW->DiscreteStateSpace_DSTATE[0]
      + (0.98919332F)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.00099459663F)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[1] += (21.6134167F)*rtb_UnitDelay_e + (3.46445972E-6F)*rtu_y_out;
    xnew[2] = (-638.820251F)*localDW->DiscreteStateSpace_DSTATE[0]
      + (-0.319410115F)*localDW->DiscreteStateSpace_DSTATE[1]
      + (0.999840319F)*localDW->DiscreteStateSpace_DSTATE[2];
    xnew[2] += (638.820251F)*rtb_UnitDelay_e + (-5.56297607E-7F)*rtu_y_out;
    (void) memcpy(&localDW->DiscreteStateSpace_DSTATE[0], xnew,
                  sizeof(real32_T)*3);
  }
}

/* Function for MATLAB Function: '<Root>/GapToStates' */
static real_T control_xnrm2(int32_T n, const real_T x[12], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (k = ix0; k < kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/GapToStates' */
static void control_mldivide(const real_T A[12], const real32_T B[4], real32_T
  Y[3])
{
  real_T b_A[12];
  real_T tau[3];
  real_T vn1[3];
  real_T vn2[3];
  real_T work[3];
  real_T s;
  real_T smax;
  real_T temp2;
  int32_T b_ix;
  int32_T b_k;
  int32_T e;
  int32_T exitg1;
  int32_T ia;
  int32_T ii;
  int32_T itemp;
  int32_T pvt;
  int32_T rankA;
  real32_T b_B[4];
  real32_T wj;
  int8_T jpvt[3];
  int8_T jpvt_0;
  boolean_T exitg2;
  b_B[0] = B[0];
  b_B[1] = B[1];
  b_B[2] = B[2];
  b_B[3] = B[3];
  jpvt[0] = 1;
  jpvt[1] = 2;
  jpvt[2] = 3;
  memcpy(&b_A[0], &A[0], 12U * sizeof(real_T));
  tau[0] = 0.0;
  work[0] = 0.0;
  smax = control_xnrm2(4, A, 1);
  vn1[0] = smax;
  vn2[0] = smax;
  tau[1] = 0.0;
  work[1] = 0.0;
  smax = control_xnrm2(4, A, 5);
  vn1[1] = smax;
  vn2[1] = smax;
  tau[2] = 0.0;
  work[2] = 0.0;
  smax = control_xnrm2(4, A, 9);
  vn1[2] = smax;
  vn2[2] = smax;
  for (rankA = 0; rankA < 3; rankA++) {
    itemp = rankA << 2;
    ii = itemp + rankA;
    pvt = 4 - rankA;
    b_ix = 0;
    if (3 - rankA > 1) {
      smax = fabs(vn1[rankA]);
      for (b_k = 2; b_k < pvt; b_k++) {
        s = fabs(vn1[(rankA + b_k) - 1]);
        if (s > smax) {
          b_ix = b_k - 1;
          smax = s;
        }
      }
    }

    pvt = rankA + b_ix;
    if (pvt != rankA) {
      b_ix = pvt << 2;
      smax = b_A[b_ix];
      b_A[b_ix] = b_A[itemp];
      b_A[itemp] = smax;
      smax = b_A[b_ix + 1];
      b_A[b_ix + 1] = b_A[itemp + 1];
      b_A[itemp + 1] = smax;
      smax = b_A[b_ix + 2];
      b_A[b_ix + 2] = b_A[itemp + 2];
      b_A[itemp + 2] = smax;
      smax = b_A[b_ix + 3];
      b_A[b_ix + 3] = b_A[itemp + 3];
      b_A[itemp + 3] = smax;
      itemp = jpvt[pvt];
      jpvt[pvt] = jpvt[rankA];
      jpvt[rankA] = (int8_T)itemp;
      vn1[pvt] = vn1[rankA];
      vn2[pvt] = vn2[rankA];
    }

    smax = b_A[ii];
    itemp = ii + 2;
    tau[rankA] = 0.0;
    s = control_xnrm2(3 - rankA, b_A, ii + 2);
    if (s != 0.0) {
      temp2 = b_A[ii];
      s = rt_hypotd_snf(temp2, s);
      if (temp2 >= 0.0) {
        s = -s;
      }

      if (fabs(s) < 1.0020841800044864E-292) {
        pvt = 0;
        b_ix = (ii - rankA) + 4;
        do {
          pvt++;
          for (b_k = itemp; b_k <= b_ix; b_k++) {
            b_A[b_k - 1] *= 9.9792015476736E+291;
          }

          s *= 9.9792015476736E+291;
          smax *= 9.9792015476736E+291;
        } while ((fabs(s) < 1.0020841800044864E-292) && (pvt < 20));

        s = rt_hypotd_snf(smax, control_xnrm2(3 - rankA, b_A, ii + 2));
        if (smax >= 0.0) {
          s = -s;
        }

        tau[rankA] = (s - smax) / s;
        smax = 1.0 / (smax - s);
        for (b_k = itemp; b_k <= b_ix; b_k++) {
          b_A[b_k - 1] *= smax;
        }

        for (itemp = 0; itemp < pvt; itemp++) {
          s *= 1.0020841800044864E-292;
        }

        smax = s;
      } else {
        tau[rankA] = (s - temp2) / s;
        smax = 1.0 / (temp2 - s);
        pvt = (ii - rankA) + 4;
        for (b_ix = itemp; b_ix <= pvt; b_ix++) {
          b_A[b_ix - 1] *= smax;
        }

        smax = s;
      }
    }

    b_A[ii] = smax;
    if (rankA + 1 < 3) {
      b_A[ii] = 1.0;
      if (tau[rankA] != 0.0) {
        itemp = 4 - rankA;
        pvt = (ii - rankA) + 3;
        while ((itemp > 0) && (b_A[pvt] == 0.0)) {
          itemp--;
          pvt--;
        }

        pvt = 2 - rankA;
        exitg2 = false;
        while ((!exitg2) && (pvt > 0)) {
          b_ix = (((pvt - 1) << 2) + ii) + 4;
          b_k = b_ix;
          do {
            exitg1 = 0;
            if (b_k + 1 <= b_ix + itemp) {
              if (b_A[b_k] != 0.0) {
                exitg1 = 1;
              } else {
                b_k++;
              }
            } else {
              pvt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }

        pvt--;
      } else {
        itemp = 0;
        pvt = -1;
      }

      if (itemp > 0) {
        if (pvt + 1 != 0) {
          memset(&work[0], 0, (uint32_T)(pvt + 1) * sizeof(real_T));
          b_ix = ((pvt << 2) + ii) + 5;
          for (b_k = ii + 5; b_k <= b_ix; b_k += 4) {
            s = 0.0;
            e = b_k + itemp;
            for (ia = b_k; ia < e; ia++) {
              s += b_A[(ii + ia) - b_k] * b_A[ia - 1];
            }

            e = ((b_k - ii) - 5) >> 2;
            work[e] += s;
          }
        }

        if (!(-tau[rankA] == 0.0)) {
          b_ix = ii + 5;
          for (b_k = 0; b_k <= pvt; b_k++) {
            s = work[b_k];
            if (s != 0.0) {
              s *= -tau[rankA];
              e = itemp + b_ix;
              for (ia = b_ix; ia < e; ia++) {
                b_A[ia - 1] += b_A[(ii + ia) - b_ix] * s;
              }
            }

            b_ix += 4;
          }
        }
      }

      b_A[ii] = smax;
    }

    for (ii = rankA + 2; ii < 4; ii++) {
      itemp = ((ii - 1) << 2) + rankA;
      smax = vn1[ii - 1];
      if (smax != 0.0) {
        s = fabs(b_A[itemp]) / smax;
        s = 1.0 - s * s;
        if (s < 0.0) {
          s = 0.0;
        }

        temp2 = smax / vn2[ii - 1];
        temp2 = temp2 * temp2 * s;
        if (temp2 <= 1.4901161193847656E-8) {
          smax = control_xnrm2(3 - rankA, b_A, itemp + 2);
          vn1[ii - 1] = smax;
          vn2[ii - 1] = smax;
        } else {
          vn1[ii - 1] = smax * sqrt(s);
        }
      }
    }
  }

  rankA = 0;
  smax = 8.8817841970012523E-15 * fabs(b_A[0]);
  while ((rankA < 3) && (!(fabs(b_A[(rankA << 2) + rankA]) <= smax))) {
    rankA++;
  }

  for (ii = 0; ii < 3; ii++) {
    Y[ii] = 0.0F;
    if (tau[ii] != 0.0) {
      wj = b_B[ii];
      for (itemp = ii + 2; itemp < 5; itemp++) {
        wj += (real32_T)b_A[((ii << 2) + itemp) - 1] * b_B[itemp - 1];
      }

      wj *= (real32_T)tau[ii];
      if (wj != 0.0F) {
        b_B[ii] -= wj;
        for (itemp = ii + 2; itemp < 5; itemp++) {
          b_B[itemp - 1] -= (real32_T)b_A[((ii << 2) + itemp) - 1] * wj;
        }
      }
    }
  }

  for (ii = 0; ii < rankA; ii++) {
    Y[jpvt[ii] - 1] = b_B[ii];
  }

  for (ii = rankA; ii >= 1; ii--) {
    jpvt_0 = jpvt[ii - 1];
    itemp = (ii - 1) << 2;
    Y[jpvt_0 - 1] /= (real32_T)b_A[(itemp + ii) - 1];
    for (pvt = 0; pvt <= ii - 2; pvt++) {
      b_ix = jpvt[pvt] - 1;
      Y[b_ix] -= (real32_T)b_A[itemp + pvt] * Y[jpvt_0 - 1];
    }
  }
}

/* Model step function for TID0 */
void control_step0(void)               /* Sample time: [0.0005s, 0.0s] */
{
  real32_T Integrator;
  real32_T Integrator_g;
  real32_T Integrator_g_tmp;
  real32_T Integrator_l;
  real32_T Integrator_l_tmp;
  real32_T Integrator_m;
  real32_T Integrator_m_tmp;
  real32_T Integrator_tmp;
  real32_T rtb_ProportionalGain;
  real32_T rtb_ProportionalGain_c;
  real32_T rtb_ProportionalGain_h;
  real32_T rtb_Sum;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0005s, 0.0s] to Sample time: [0.001s, 0.0s]  */
  (control_M->Timing.RateInteraction.TID0_1)++;
  if ((control_M->Timing.RateInteraction.TID0_1) > 1) {
    control_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition generated from: '<S1>/ControlDeCorriente' */
  if (control_M->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition generated from: '<S1>/ControlDeCorriente' */
    control_B.Corriente[0] = control_DW.Corriente_Buffer0[0];
    control_B.Corriente[1] = control_DW.Corriente_Buffer0[1];
    control_B.Corriente[2] = control_DW.Corriente_Buffer0[2];
    control_B.Corriente[3] = control_DW.Corriente_Buffer0[3];
  }

  /* End of RateTransition generated from: '<S1>/ControlDeCorriente' */

  /* Outputs for Atomic SubSystem: '<S1>/ControlDeCorriente' */
  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/I_real_hems'
   */
  rtb_Sum = control_B.Corriente[0] - control_U.I_real_hems[0];

  /* DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Gain: '<S44>/Integral Gain'
   */
  Integrator_tmp = 208.333298F * rtb_Sum * 0.00025F;

  /* DiscreteIntegrator: '<S47>/Integrator' */
  Integrator = Integrator_tmp + control_DW.Integrator_DSTATE;

  /* DiscreteIntegrator: '<S47>/Integrator' */
  if (Integrator > 400.0F) {
    /* DiscreteIntegrator: '<S47>/Integrator' */
    Integrator = 400.0F;
  } else if (Integrator < -400.0F) {
    /* DiscreteIntegrator: '<S47>/Integrator' */
    Integrator = -400.0F;
  }

  /* Gain: '<S52>/Proportional Gain' */
  rtb_ProportionalGain = 22.9546F * rtb_Sum;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Inport: '<Root>/I_real_hems'
   */
  rtb_Sum = control_B.Corriente[1] - control_U.I_real_hems[1];

  /* DiscreteIntegrator: '<S99>/Integrator' incorporates:
   *  Gain: '<S96>/Integral Gain'
   */
  Integrator_g_tmp = 208.333298F * rtb_Sum * 0.00025F;

  /* DiscreteIntegrator: '<S99>/Integrator' */
  Integrator_g = Integrator_g_tmp + control_DW.Integrator_DSTATE_k;

  /* DiscreteIntegrator: '<S99>/Integrator' */
  if (Integrator_g > 400.0F) {
    /* DiscreteIntegrator: '<S99>/Integrator' */
    Integrator_g = 400.0F;
  } else if (Integrator_g < -400.0F) {
    /* DiscreteIntegrator: '<S99>/Integrator' */
    Integrator_g = -400.0F;
  }

  /* Gain: '<S104>/Proportional Gain' */
  rtb_ProportionalGain_h = 22.9546F * rtb_Sum;

  /* Sum: '<S3>/Sum2' incorporates:
   *  Inport: '<Root>/I_real_hems'
   */
  rtb_Sum = control_B.Corriente[2] - control_U.I_real_hems[2];

  /* DiscreteIntegrator: '<S151>/Integrator' incorporates:
   *  Gain: '<S148>/Integral Gain'
   */
  Integrator_l_tmp = 208.333298F * rtb_Sum * 0.00025F;

  /* DiscreteIntegrator: '<S151>/Integrator' */
  Integrator_l = Integrator_l_tmp + control_DW.Integrator_DSTATE_f;

  /* DiscreteIntegrator: '<S151>/Integrator' */
  if (Integrator_l > 400.0F) {
    /* DiscreteIntegrator: '<S151>/Integrator' */
    Integrator_l = 400.0F;
  } else if (Integrator_l < -400.0F) {
    /* DiscreteIntegrator: '<S151>/Integrator' */
    Integrator_l = -400.0F;
  }

  /* Gain: '<S156>/Proportional Gain' */
  rtb_ProportionalGain_c = 22.9546F * rtb_Sum;

  /* Sum: '<S3>/Sum3' incorporates:
   *  Inport: '<Root>/I_real_hems'
   */
  rtb_Sum = control_B.Corriente[3] - control_U.I_real_hems[3];

  /* DiscreteIntegrator: '<S203>/Integrator' incorporates:
   *  Gain: '<S200>/Integral Gain'
   */
  Integrator_m_tmp = 208.333298F * rtb_Sum * 0.00025F;

  /* DiscreteIntegrator: '<S203>/Integrator' */
  Integrator_m = Integrator_m_tmp + control_DW.Integrator_DSTATE_h;

  /* DiscreteIntegrator: '<S203>/Integrator' */
  if (Integrator_m > 400.0F) {
    /* DiscreteIntegrator: '<S203>/Integrator' */
    Integrator_m = 400.0F;
  } else if (Integrator_m < -400.0F) {
    /* DiscreteIntegrator: '<S203>/Integrator' */
    Integrator_m = -400.0F;
  }

  /* Sum: '<S212>/Sum' incorporates:
   *  Gain: '<S208>/Proportional Gain'
   */
  rtb_Sum = 22.9546F * rtb_Sum + Integrator_m;

  /* Update for DiscreteIntegrator: '<S47>/Integrator' */
  control_DW.Integrator_DSTATE = Integrator_tmp + Integrator;
  if (control_DW.Integrator_DSTATE > 400.0F) {
    control_DW.Integrator_DSTATE = 400.0F;
  } else if (control_DW.Integrator_DSTATE < -400.0F) {
    control_DW.Integrator_DSTATE = -400.0F;
  }

  /* Update for DiscreteIntegrator: '<S99>/Integrator' */
  control_DW.Integrator_DSTATE_k = Integrator_g_tmp + Integrator_g;
  if (control_DW.Integrator_DSTATE_k > 400.0F) {
    control_DW.Integrator_DSTATE_k = 400.0F;
  } else if (control_DW.Integrator_DSTATE_k < -400.0F) {
    control_DW.Integrator_DSTATE_k = -400.0F;
  }

  /* Update for DiscreteIntegrator: '<S151>/Integrator' */
  control_DW.Integrator_DSTATE_f = Integrator_l_tmp + Integrator_l;
  if (control_DW.Integrator_DSTATE_f > 400.0F) {
    control_DW.Integrator_DSTATE_f = 400.0F;
  } else if (control_DW.Integrator_DSTATE_f < -400.0F) {
    control_DW.Integrator_DSTATE_f = -400.0F;
  }

  /* Update for DiscreteIntegrator: '<S203>/Integrator' */
  control_DW.Integrator_DSTATE_h = Integrator_m_tmp + Integrator_m;
  if (control_DW.Integrator_DSTATE_h > 400.0F) {
    control_DW.Integrator_DSTATE_h = 400.0F;
  } else if (control_DW.Integrator_DSTATE_h < -400.0F) {
    control_DW.Integrator_DSTATE_h = -400.0F;
  }

  /* Sum: '<S56>/Sum' */
  Integrator_tmp = rtb_ProportionalGain + Integrator;

  /* Saturate: '<S54>/Saturation' */
  if (Integrator_tmp > 400.0F) {
    /* Outport: '<Root>/I' */
    control_Y.I[0] = 400.0F;
  } else if (Integrator_tmp < -400.0F) {
    /* Outport: '<Root>/I' */
    control_Y.I[0] = -400.0F;
  } else {
    /* Outport: '<Root>/I' */
    control_Y.I[0] = Integrator_tmp;
  }

  /* End of Saturate: '<S54>/Saturation' */

  /* Sum: '<S108>/Sum' */
  Integrator_tmp = rtb_ProportionalGain_h + Integrator_g;

  /* Saturate: '<S106>/Saturation' */
  if (Integrator_tmp > 400.0F) {
    /* Outport: '<Root>/I' */
    control_Y.I[1] = 400.0F;
  } else if (Integrator_tmp < -400.0F) {
    /* Outport: '<Root>/I' */
    control_Y.I[1] = -400.0F;
  } else {
    /* Outport: '<Root>/I' */
    control_Y.I[1] = Integrator_tmp;
  }

  /* End of Saturate: '<S106>/Saturation' */

  /* Sum: '<S160>/Sum' */
  Integrator_tmp = rtb_ProportionalGain_c + Integrator_l;

  /* Saturate: '<S158>/Saturation' */
  if (Integrator_tmp > 400.0F) {
    /* Outport: '<Root>/I' */
    control_Y.I[2] = 400.0F;
  } else if (Integrator_tmp < -400.0F) {
    /* Outport: '<Root>/I' */
    control_Y.I[2] = -400.0F;
  } else {
    /* Outport: '<Root>/I' */
    control_Y.I[2] = Integrator_tmp;
  }

  /* End of Saturate: '<S158>/Saturation' */

  /* Saturate: '<S210>/Saturation' */
  if (rtb_Sum > 400.0F) {
    /* Outport: '<Root>/I' */
    control_Y.I[3] = 400.0F;
  } else if (rtb_Sum < -400.0F) {
    /* Outport: '<Root>/I' */
    control_Y.I[3] = -400.0F;
  } else {
    /* Outport: '<Root>/I' */
    control_Y.I[3] = rtb_Sum;
  }

  /* End of Saturate: '<S210>/Saturation' */
  /* End of Outputs for SubSystem: '<S1>/ControlDeCorriente' */

  /* Outport: '<Root>/I' */
  control_Y.I[4] = 0.0F;
  control_Y.I[5] = 0.0F;
  control_Y.I[6] = 0.0F;
  control_Y.I[7] = 0.0F;
  control_Y.I[8] = 0.0F;
  control_Y.I[9] = 0.0F;
}

/* Model step function for TID1 */
void control_step1(void)               /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_UnitDelay;
  real32_T rtb_airgaps_actuadores[10];
  real32_T rtb_DiscreteStateSpace[3];
  int32_T i;
  real32_T tmp[4];
  real32_T q[3];
  real32_T rtb_airgaps_actuadores_tmp;
  real32_T rtb_airgaps_actuadores_tmp_0;
  real32_T rtb_airgaps_actuadores_tmp_1;
  real32_T rtb_airgaps_actuadores_tmp_2;
  static const real_T b[12] = { 1.0, 1.0, 1.0, 1.0, -0.31417, 0.24811, -0.31417,
    0.24811, -1.24708, -1.24946, 1.27493, 1.27253 };

  /* MATLAB Function: '<Root>/GapToStates' incorporates:
   *  Inport: '<Root>/Airgaps_Model'
   */
  tmp[0] = 0.11965F - control_U.Airgaps_Model[0];
  tmp[1] = 0.11965F - control_U.Airgaps_Model[1];
  tmp[2] = 0.11965F - control_U.Airgaps_Model[2];
  tmp[3] = 0.11965F - control_U.Airgaps_Model[3];
  control_mldivide(b, tmp, q);

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<Root>/GapToStates'
   */
  rtb_airgaps_actuadores_tmp = sinf(asinf(fminf(1.0F, fmaxf(-1.0F, q[1]))));
  rtb_airgaps_actuadores_tmp_0 = sinf(asinf(fminf(1.0F, fmaxf(-1.0F, q[2]))));
  rtb_airgaps_actuadores_tmp_1 = 0.76978F * rtb_airgaps_actuadores_tmp_0;
  rtb_airgaps_actuadores_tmp_2 = q[0] - 0.28958F * rtb_airgaps_actuadores_tmp;
  rtb_airgaps_actuadores[0] = fabsf(rtb_airgaps_actuadores_tmp_2 -
    rtb_airgaps_actuadores_tmp_1);
  rtb_airgaps_actuadores_tmp = 0.22351F * rtb_airgaps_actuadores_tmp + q[0];
  rtb_airgaps_actuadores[1] = fabsf(rtb_airgaps_actuadores_tmp -
    rtb_airgaps_actuadores_tmp_1);
  rtb_airgaps_actuadores_tmp_0 *= 0.79522F;
  rtb_airgaps_actuadores[2] = fabsf(rtb_airgaps_actuadores_tmp_2 +
    rtb_airgaps_actuadores_tmp_0);
  rtb_airgaps_actuadores[3] = fabsf(rtb_airgaps_actuadores_tmp +
    rtb_airgaps_actuadores_tmp_0);
  for (i = 0; i < 6; i++) {
    rtb_airgaps_actuadores[i + 4] = 0.0F;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function2' */

  /* Outputs for Atomic SubSystem: '<S1>/Simulink1' */
  /* UnitDelay: '<S5>/Unit Delay' */
  rtb_UnitDelay = control_DW.UnitDelay_DSTATE;

  /* DiscreteStateSpace: '<S5>/Discrete State-Space' */
  {
    rtb_DiscreteStateSpace[0] = (0.87629658F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.000438148301F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (2.19074153E-7F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[0] += (0.123703398F)*rtb_UnitDelay + (7.63096808E-10F)*
      rtb_airgaps_actuadores[0];
    rtb_DiscreteStateSpace[1] = (-10.8067083F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.99459666F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.000497298315F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[1] += (10.8067083F)*rtb_UnitDelay + (1.73222986E-6F)*
      rtb_airgaps_actuadores[0];
    rtb_DiscreteStateSpace[2] = (-319.410126F)*
      control_DW.DiscreteStateSpace_DSTATE[0]
      + (-0.159705058F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.99992013F)*control_DW.DiscreteStateSpace_DSTATE[2];
    rtb_DiscreteStateSpace[2] += (319.410126F)*rtb_UnitDelay + (-2.78148804E-7F)*
      rtb_airgaps_actuadores[0];
  }

  /* Gain: '<S5>/b0' incorporates:
   *  Gain: '<S5>/Kd'
   *  Gain: '<S5>/Kp'
   *  Inport: '<Root>/Refz'
   *  Sum: '<S5>/Sum1'
   *  Sum: '<S5>/Sum13'
   *  Sum: '<S5>/Sum5'
   */
  control_DW.UnitDelay_DSTATE = (((control_U.Refz - rtb_DiscreteStateSpace[0]) *
    900.0F - 60.0F * rtb_DiscreteStateSpace[1]) - rtb_DiscreteStateSpace[2]) *
    287.085F;

  /* Saturate: '<S5>/Saturation' */
  if (control_DW.UnitDelay_DSTATE > 50.0F) {
    /* Gain: '<S5>/b0' */
    control_DW.UnitDelay_DSTATE = 50.0F;
  } else if (control_DW.UnitDelay_DSTATE < -50.0F) {
    /* Gain: '<S5>/b0' */
    control_DW.UnitDelay_DSTATE = -50.0F;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Update for DiscreteStateSpace: '<S5>/Discrete State-Space' */
  {
    real32_T xnew[3];
    xnew[0] = (0.752593219F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.000876296603F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (4.38148305E-7F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[0] += (0.247406796F)*rtb_UnitDelay + (1.52619362E-9F)*
      rtb_airgaps_actuadores[0];
    xnew[1] = (-21.6134167F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (0.98919332F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.00099459663F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[1] += (21.6134167F)*rtb_UnitDelay + (3.46445972E-6F)*
      rtb_airgaps_actuadores[0];
    xnew[2] = (-638.820251F)*control_DW.DiscreteStateSpace_DSTATE[0]
      + (-0.319410115F)*control_DW.DiscreteStateSpace_DSTATE[1]
      + (0.999840319F)*control_DW.DiscreteStateSpace_DSTATE[2];
    xnew[2] += (638.820251F)*rtb_UnitDelay + (-5.56297607E-7F)*
      rtb_airgaps_actuadores[0];
    (void) memcpy(&control_DW.DiscreteStateSpace_DSTATE[0], xnew,
                  sizeof(real32_T)*3);
  }

  /* End of Outputs for SubSystem: '<S1>/Simulink1' */

  /* Outputs for Atomic SubSystem: '<S1>/Simulink4' */
  /* RateTransition generated from: '<S1>/ControlDeCorriente' incorporates:
   *  Inport: '<Root>/Refz'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  control_Simulink2(control_U.Refz, rtb_airgaps_actuadores[1],
                    &control_DW.Corriente_Buffer0[1], rtb_DiscreteStateSpace,
                    &control_DW.Simulink4);

  /* End of Outputs for SubSystem: '<S1>/Simulink4' */

  /* Outputs for Atomic SubSystem: '<S1>/Simulink2' */
  control_Simulink2(control_U.Refz, rtb_airgaps_actuadores[2],
                    &control_DW.Corriente_Buffer0[2], rtb_DiscreteStateSpace,
                    &control_DW.Simulink2);

  /* End of Outputs for SubSystem: '<S1>/Simulink2' */

  /* Outputs for Atomic SubSystem: '<S1>/Simulink3' */
  control_Simulink2(control_U.Refz, rtb_airgaps_actuadores[3],
                    &control_DW.Corriente_Buffer0[3], rtb_DiscreteStateSpace,
                    &control_DW.Simulink3);

  /* End of Outputs for SubSystem: '<S1>/Simulink3' */
  control_DW.Corriente_Buffer0[0] = control_DW.UnitDelay_DSTATE;
}

/* Model initialize function */
void control_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (control_M)->Timing.TaskCounters.cLimit[0] = 1;
  (control_M)->Timing.TaskCounters.cLimit[1] = 2;

  /* SystemInitialize for Atomic SubSystem: '<S1>/Simulink1' */
  /* InitializeConditions for Gain: '<S5>/b0' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  control_DW.UnitDelay_DSTATE = -2.0F;
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
