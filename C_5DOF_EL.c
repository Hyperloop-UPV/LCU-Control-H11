/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: C_5DOF_EL.c
 *
 * Code generated for Simulink model 'C_5DOF_EL'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Apr 16 16:40:05 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "C_5DOF_EL.h"
#include <math.h>
#include "ControlDeCorriente.h"
#include "rtwtypes.h"
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

/* Model step function for TID0 */
void C_5DOF_EL_step0(void)             /* Sample time: [0.0005s, 0.0s] */
{
  int32_T i;
  int8_T ipiv;
  boolean_T tmp;
  static const real_T h[5] = { 0.0, -1.0, 0.21748, 1.0093, 0.0 };

  static const real_T g[5] = { 0.0, -1.0, -0.21748, 1.0093, 0.0 };

  static const real_T f[5] = { 0.0, -1.0, 0.21748, -1.0093, 0.0 };

  static const real_T e[5] = { 0.0, -1.0, -0.21748, -1.0093, 0.0 };

  static const real_T b_H_tmp[5] = { 1.0, 0.0, -0.18782, 0.0, 1.0095 };

  static const real_T H_tmp[5] = { 1.0, 0.0, -0.18782, 0.0, -1.0095 };

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0005s, 0.0s] to Sample time: [0.001s, 0.0s]  */
  (C_5DOF_EL_M->Timing.RateInteraction.TID0_1)++;
  if ((C_5DOF_EL_M->Timing.RateInteraction.TID0_1) > 1) {
    C_5DOF_EL_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/AIRGAP'
   */
  if (!C_5DOF_EL_DW.H_pseudo_not_empty) {
    for (i = 0; i < 5; i++) {
      C_5DOF_EL_B.jj = i << 3;
      C_5DOF_EL_B.H[C_5DOF_EL_B.jj] = h[i];
      C_5DOF_EL_B.H[C_5DOF_EL_B.jj + 1] = g[i];
      C_5DOF_EL_B.H[C_5DOF_EL_B.jj + 2] = f[i];
      C_5DOF_EL_B.H[C_5DOF_EL_B.jj + 3] = e[i];
      C_5DOF_EL_B.H[C_5DOF_EL_B.jj + 4] = b_H_tmp[i];
      C_5DOF_EL_B.H[C_5DOF_EL_B.jj + 5] = b_H_tmp[i];
      C_5DOF_EL_B.H[C_5DOF_EL_B.jj + 6] = H_tmp[i];
      C_5DOF_EL_B.H[C_5DOF_EL_B.jj + 7] = H_tmp[i];
    }

    for (i = 0; i < 5; i++) {
      for (C_5DOF_EL_B.jj = 0; C_5DOF_EL_B.jj < 5; C_5DOF_EL_B.jj++) {
        C_5DOF_EL_B.smax = 0.0;
        for (C_5DOF_EL_B.c_k = 0; C_5DOF_EL_B.c_k < 8; C_5DOF_EL_B.c_k++) {
          C_5DOF_EL_B.smax += C_5DOF_EL_B.H[(C_5DOF_EL_B.jj << 3) +
            C_5DOF_EL_B.c_k] * C_5DOF_EL_B.H[(i << 3) + C_5DOF_EL_B.c_k];
        }

        C_5DOF_EL_B.A[C_5DOF_EL_B.jj + 5 * i] = C_5DOF_EL_B.smax;
      }
    }

    for (i = 0; i < 8; i++) {
      for (C_5DOF_EL_B.jj = 0; C_5DOF_EL_B.jj < 5; C_5DOF_EL_B.jj++) {
        C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.jj + 5 * i] = C_5DOF_EL_B.H
          [(C_5DOF_EL_B.jj << 3) + i];
      }
    }

    for (i = 0; i < 5; i++) {
      C_5DOF_EL_B.ipiv[i] = (int8_T)(i + 1);
    }

    for (i = 0; i < 4; i++) {
      C_5DOF_EL_B.jj = i * 6;
      C_5DOF_EL_B.n = 6 - i;
      C_5DOF_EL_B.a = 0;
      C_5DOF_EL_B.smax = fabs(C_5DOF_EL_B.A[C_5DOF_EL_B.jj]);
      for (C_5DOF_EL_B.c_k = 2; C_5DOF_EL_B.c_k < C_5DOF_EL_B.n; C_5DOF_EL_B.c_k
           ++) {
        C_5DOF_EL_B.s = fabs(C_5DOF_EL_B.A[(C_5DOF_EL_B.jj + C_5DOF_EL_B.c_k) -
                             1]);
        if (C_5DOF_EL_B.s > C_5DOF_EL_B.smax) {
          C_5DOF_EL_B.a = C_5DOF_EL_B.c_k - 1;
          C_5DOF_EL_B.smax = C_5DOF_EL_B.s;
        }
      }

      if (C_5DOF_EL_B.A[C_5DOF_EL_B.jj + C_5DOF_EL_B.a] != 0.0) {
        if (C_5DOF_EL_B.a != 0) {
          C_5DOF_EL_B.n = i + C_5DOF_EL_B.a;
          C_5DOF_EL_B.ipiv[i] = (int8_T)(C_5DOF_EL_B.n + 1);
          for (C_5DOF_EL_B.c_k = 0; C_5DOF_EL_B.c_k < 5; C_5DOF_EL_B.c_k++) {
            C_5DOF_EL_B.a = C_5DOF_EL_B.c_k * 5 + i;
            C_5DOF_EL_B.smax = C_5DOF_EL_B.A[C_5DOF_EL_B.a];
            C_5DOF_EL_B.jA = C_5DOF_EL_B.c_k * 5 + C_5DOF_EL_B.n;
            C_5DOF_EL_B.A[C_5DOF_EL_B.a] = C_5DOF_EL_B.A[C_5DOF_EL_B.jA];
            C_5DOF_EL_B.A[C_5DOF_EL_B.jA] = C_5DOF_EL_B.smax;
          }
        }

        C_5DOF_EL_B.n = (C_5DOF_EL_B.jj - i) + 5;
        for (C_5DOF_EL_B.c_k = C_5DOF_EL_B.jj + 2; C_5DOF_EL_B.c_k <=
             C_5DOF_EL_B.n; C_5DOF_EL_B.c_k++) {
          C_5DOF_EL_B.A[C_5DOF_EL_B.c_k - 1] /= C_5DOF_EL_B.A[C_5DOF_EL_B.jj];
        }
      }

      C_5DOF_EL_B.a = 3 - i;
      C_5DOF_EL_B.jA = C_5DOF_EL_B.jj + 7;
      for (C_5DOF_EL_B.c_k = 0; C_5DOF_EL_B.c_k <= C_5DOF_EL_B.a;
           C_5DOF_EL_B.c_k++) {
        C_5DOF_EL_B.smax = C_5DOF_EL_B.A[(C_5DOF_EL_B.c_k * 5 + C_5DOF_EL_B.jj)
          + 5];
        if (C_5DOF_EL_B.smax != 0.0) {
          C_5DOF_EL_B.kAcol = (C_5DOF_EL_B.jA - i) + 3;
          for (C_5DOF_EL_B.n = C_5DOF_EL_B.jA; C_5DOF_EL_B.n <=
               C_5DOF_EL_B.kAcol; C_5DOF_EL_B.n++) {
            C_5DOF_EL_B.A[C_5DOF_EL_B.n - 1] += C_5DOF_EL_B.A[((C_5DOF_EL_B.jj +
              C_5DOF_EL_B.n) - C_5DOF_EL_B.jA) + 1] * -C_5DOF_EL_B.smax;
          }
        }

        C_5DOF_EL_B.jA += 5;
      }

      ipiv = C_5DOF_EL_B.ipiv[i];
      if (i + 1 != ipiv) {
        for (C_5DOF_EL_B.c_k = 0; C_5DOF_EL_B.c_k < 8; C_5DOF_EL_B.c_k++) {
          C_5DOF_EL_B.n = 5 * C_5DOF_EL_B.c_k + i;
          C_5DOF_EL_B.smax = C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.n];
          C_5DOF_EL_B.jj = (5 * C_5DOF_EL_B.c_k + ipiv) - 1;
          C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.n] =
            C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.jj];
          C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.jj] = C_5DOF_EL_B.smax;
        }
      }
    }

    for (C_5DOF_EL_B.c_k = 0; C_5DOF_EL_B.c_k < 8; C_5DOF_EL_B.c_k++) {
      C_5DOF_EL_B.jA = 5 * C_5DOF_EL_B.c_k;
      for (C_5DOF_EL_B.n = 0; C_5DOF_EL_B.n < 5; C_5DOF_EL_B.n++) {
        C_5DOF_EL_B.kAcol = 5 * C_5DOF_EL_B.n;
        i = C_5DOF_EL_B.n + C_5DOF_EL_B.jA;
        if (C_5DOF_EL_DW.H_pseudo[i] != 0.0) {
          for (C_5DOF_EL_B.a = C_5DOF_EL_B.n + 2; C_5DOF_EL_B.a < 6;
               C_5DOF_EL_B.a++) {
            C_5DOF_EL_B.jj = (C_5DOF_EL_B.a + C_5DOF_EL_B.jA) - 1;
            C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.jj] -= C_5DOF_EL_B.A
              [(C_5DOF_EL_B.a + C_5DOF_EL_B.kAcol) - 1] *
              C_5DOF_EL_DW.H_pseudo[i];
          }
        }
      }
    }

    for (C_5DOF_EL_B.c_k = 0; C_5DOF_EL_B.c_k < 8; C_5DOF_EL_B.c_k++) {
      C_5DOF_EL_B.jA = 5 * C_5DOF_EL_B.c_k;
      for (C_5DOF_EL_B.n = 4; C_5DOF_EL_B.n >= 0; C_5DOF_EL_B.n--) {
        C_5DOF_EL_B.kAcol = 5 * C_5DOF_EL_B.n;
        i = C_5DOF_EL_B.n + C_5DOF_EL_B.jA;
        if (C_5DOF_EL_DW.H_pseudo[i] != 0.0) {
          C_5DOF_EL_DW.H_pseudo[i] /= C_5DOF_EL_B.A[C_5DOF_EL_B.n +
            C_5DOF_EL_B.kAcol];
          for (C_5DOF_EL_B.a = 0; C_5DOF_EL_B.a < C_5DOF_EL_B.n; C_5DOF_EL_B.a++)
          {
            C_5DOF_EL_B.jj = C_5DOF_EL_B.a + C_5DOF_EL_B.jA;
            C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.jj] -= C_5DOF_EL_B.A[C_5DOF_EL_B.a
              + C_5DOF_EL_B.kAcol] * C_5DOF_EL_DW.H_pseudo[i];
          }
        }
      }
    }

    C_5DOF_EL_DW.H_pseudo_not_empty = true;
  }

  C_5DOF_EL_B.b[0] = C_5DOF_EL_U.AIRGAP[0] - 0.09974F;
  C_5DOF_EL_B.b[1] = C_5DOF_EL_U.AIRGAP[1] - 0.09974F;
  C_5DOF_EL_B.b[2] = C_5DOF_EL_U.AIRGAP[2] - 0.09974F;
  C_5DOF_EL_B.b[3] = C_5DOF_EL_U.AIRGAP[3] - 0.09974F;
  C_5DOF_EL_B.b[4] = (C_5DOF_EL_U.AIRGAP[4] - 0.277F) + 0.1347F;
  C_5DOF_EL_B.b[5] = (-C_5DOF_EL_U.AIRGAP[5] + 0.277F) - 0.1347F;
  C_5DOF_EL_B.b[6] = (C_5DOF_EL_U.AIRGAP[6] - 0.277F) + 0.1347F;
  C_5DOF_EL_B.b[7] = (-C_5DOF_EL_U.AIRGAP[7] + 0.277F) - 0.1347F;
  for (i = 0; i < 5; i++) {
    C_5DOF_EL_B.u[i] = 0.0;
  }

  for (i = 0; i < 8; i++) {
    C_5DOF_EL_B.smax = C_5DOF_EL_B.b[i];
    for (C_5DOF_EL_B.jj = 0; C_5DOF_EL_B.jj < 5; C_5DOF_EL_B.jj++) {
      C_5DOF_EL_B.u[C_5DOF_EL_B.jj] += C_5DOF_EL_DW.H_pseudo[5 * i +
        C_5DOF_EL_B.jj] * C_5DOF_EL_B.smax;
    }
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  C_5DOF_EL_B.smax = sin(C_5DOF_EL_B.u[2]);
  C_5DOF_EL_B.s = 0.191 * C_5DOF_EL_B.smax;
  C_5DOF_EL_B.rtb_airgaps_actuadores_tmp = 0.6475 * sin(C_5DOF_EL_B.u[3]);
  C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m = C_5DOF_EL_B.u[1] - C_5DOF_EL_B.s;
  C_5DOF_EL_B.airgaps_actuadores[0] = fabs
    (C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m -
     C_5DOF_EL_B.rtb_airgaps_actuadores_tmp);
  C_5DOF_EL_B.s += C_5DOF_EL_B.u[1];
  C_5DOF_EL_B.airgaps_actuadores[1] = fabs(C_5DOF_EL_B.s -
    C_5DOF_EL_B.rtb_airgaps_actuadores_tmp);
  C_5DOF_EL_B.airgaps_actuadores[2] = fabs
    (C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m +
     C_5DOF_EL_B.rtb_airgaps_actuadores_tmp);
  C_5DOF_EL_B.airgaps_actuadores[3] = fabs(C_5DOF_EL_B.s +
    C_5DOF_EL_B.rtb_airgaps_actuadores_tmp);
  C_5DOF_EL_B.s = 0.268 - 0.261 * cos(C_5DOF_EL_B.u[4]);
  C_5DOF_EL_B.rtb_airgaps_actuadores_tmp = 0.788 * sin(C_5DOF_EL_B.u[4]);
  C_5DOF_EL_B.smax *= 0.20255;
  C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m = C_5DOF_EL_B.s + C_5DOF_EL_B.u[0];
  C_5DOF_EL_B.airgaps_actuadores[4] = fabs
    ((C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m +
      C_5DOF_EL_B.rtb_airgaps_actuadores_tmp) - C_5DOF_EL_B.smax);
  C_5DOF_EL_B.s -= C_5DOF_EL_B.u[0];
  C_5DOF_EL_B.airgaps_actuadores[5] = fabs((C_5DOF_EL_B.s -
    C_5DOF_EL_B.rtb_airgaps_actuadores_tmp) + C_5DOF_EL_B.smax);
  C_5DOF_EL_B.airgaps_actuadores[6] = fabs
    (C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m - C_5DOF_EL_B.smax);
  C_5DOF_EL_B.airgaps_actuadores[7] = fabs(C_5DOF_EL_B.s + C_5DOF_EL_B.smax);
  C_5DOF_EL_B.airgaps_actuadores[8] = fabs
    ((C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m -
      C_5DOF_EL_B.rtb_airgaps_actuadores_tmp) - C_5DOF_EL_B.smax);
  C_5DOF_EL_B.airgaps_actuadores[9] = fabs((C_5DOF_EL_B.s +
    C_5DOF_EL_B.rtb_airgaps_actuadores_tmp) + C_5DOF_EL_B.smax);
  for (i = 0; i < 6; i++) {
    /* Gain: '<S5>/AG_mm' incorporates:
     *  Gain: '<S6>/AG_EMS_mm'
     */
    C_5DOF_EL_B.smax = C_5DOF_EL_B.airgaps_actuadores[i + 4] * 1000.0;
    C_5DOF_EL_B.AG_mm[i] = C_5DOF_EL_B.smax;

    /* Gain: '<S6>/AG_EMS_mm' */
    C_5DOF_EL_B.TmpSignalConversionAtKin_EM[i] = C_5DOF_EL_B.smax;
  }

  /* SignalConversion generated from: '<S2>/ControlDeCorriente' */
  C_5DOF_EL_B.TmpSignalConversionAtContro[0] = 0.0;
  C_5DOF_EL_B.TmpSignalConversionAtContro[1] = 0.0;
  C_5DOF_EL_B.TmpSignalConversionAtContro[2] = 0.0;
  C_5DOF_EL_B.TmpSignalConversionAtContro[3] = 0.0;
  C_5DOF_EL_B.TmpSignalConversionAtContro[4] = 0.0;
  C_5DOF_EL_B.TmpSignalConversionAtContro[5] = 0.0;

  /* RateTransition generated from: '<S7>/Mezclador' incorporates:
   *  RateTransition generated from: '<S5>/Mezclador'
   *  RateTransition generated from: '<S5>/Y'
   */
  tmp = (C_5DOF_EL_M->Timing.RateInteraction.TID0_1 == 1);
  if (tmp) {
    /* RateTransition generated from: '<S7>/Mezclador' */
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[0] =
      C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[0];
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[1] =
      C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[1];
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[2] =
      C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[2];
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[3] =
      C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[3];
  }

  /* End of RateTransition generated from: '<S7>/Mezclador' */

  /* Gain: '<S7>/AG_mm' incorporates:
   *  Gain: '<S6>/AG_HEMS_mm'
   */
  C_5DOF_EL_B.smax = 1000.0 * C_5DOF_EL_B.airgaps_actuadores[0];

  /* Lookup_n-D: '<S7>/InvLUT_1' incorporates:
   *  Gain: '<S7>/AG_mm'
   */
  C_5DOF_EL_B.LUT_HEMS_3 = look2_binlcpw(C_5DOF_EL_B.smax,
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[0], C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
    C_5DOF_EL_ConstP.pooled31, 14U);

  /* Gain: '<S7>/AG_mm' incorporates:
   *  Gain: '<S6>/AG_HEMS_mm'
   */
  C_5DOF_EL_B.s = 1000.0 * C_5DOF_EL_B.airgaps_actuadores[1];

  /* Lookup_n-D: '<S7>/InvLUT_2' incorporates:
   *  Gain: '<S7>/AG_mm'
   */
  C_5DOF_EL_B.LUT_HEMS_4 = look2_binlcpw(C_5DOF_EL_B.s,
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[1], C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
    C_5DOF_EL_ConstP.pooled31, 14U);

  /* Gain: '<S7>/AG_mm' incorporates:
   *  Gain: '<S6>/AG_HEMS_mm'
   */
  C_5DOF_EL_B.rtb_airgaps_actuadores_tmp = 1000.0 *
    C_5DOF_EL_B.airgaps_actuadores[2];

  /* Lookup_n-D: '<S7>/InvLUT_3' incorporates:
   *  Gain: '<S7>/AG_mm'
   */
  C_5DOF_EL_B.LUT_EMS_5 = look2_binlcpw(C_5DOF_EL_B.rtb_airgaps_actuadores_tmp,
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[2], C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
    C_5DOF_EL_ConstP.pooled31, 14U);

  /* Gain: '<S7>/AG_mm' incorporates:
   *  Gain: '<S6>/AG_HEMS_mm'
   */
  C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m = 1000.0 *
    C_5DOF_EL_B.airgaps_actuadores[3];

  /* Lookup_n-D: '<S7>/InvLUT_4' incorporates:
   *  Gain: '<S7>/AG_mm'
   */
  C_5DOF_EL_B.LUT_EMS_6 = look2_binlcpw(C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m,
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[3], C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
    C_5DOF_EL_ConstP.pooled31, 14U);

  /* Saturate: '<S7>/Sat_I' incorporates:
   *  Lookup_n-D: '<S7>/InvLUT_1'
   *  Lookup_n-D: '<S7>/InvLUT_2'
   *  Lookup_n-D: '<S7>/InvLUT_3'
   *  Lookup_n-D: '<S7>/InvLUT_4'
   */
  if (C_5DOF_EL_B.LUT_HEMS_3 > 50.0) {
    C_5DOF_EL_B.AG_mm_h[0] = 50.0;
  } else if (C_5DOF_EL_B.LUT_HEMS_3 < -50.0) {
    C_5DOF_EL_B.AG_mm_h[0] = -50.0;
  } else {
    C_5DOF_EL_B.AG_mm_h[0] = C_5DOF_EL_B.LUT_HEMS_3;
  }

  if (C_5DOF_EL_B.LUT_HEMS_4 > 50.0) {
    C_5DOF_EL_B.AG_mm_h[1] = 50.0;
  } else if (C_5DOF_EL_B.LUT_HEMS_4 < -50.0) {
    C_5DOF_EL_B.AG_mm_h[1] = -50.0;
  } else {
    C_5DOF_EL_B.AG_mm_h[1] = C_5DOF_EL_B.LUT_HEMS_4;
  }

  if (C_5DOF_EL_B.LUT_EMS_5 > 50.0) {
    C_5DOF_EL_B.AG_mm_h[2] = 50.0;
  } else if (C_5DOF_EL_B.LUT_EMS_5 < -50.0) {
    C_5DOF_EL_B.AG_mm_h[2] = -50.0;
  } else {
    C_5DOF_EL_B.AG_mm_h[2] = C_5DOF_EL_B.LUT_EMS_5;
  }

  if (C_5DOF_EL_B.LUT_EMS_6 > 50.0) {
    C_5DOF_EL_B.AG_mm_h[3] = 50.0;
  } else if (C_5DOF_EL_B.LUT_EMS_6 < -50.0) {
    C_5DOF_EL_B.AG_mm_h[3] = -50.0;
  } else {
    C_5DOF_EL_B.AG_mm_h[3] = C_5DOF_EL_B.LUT_EMS_6;
  }

  /* End of Saturate: '<S7>/Sat_I' */

  /* SignalConversion generated from: '<S2>/ControlDeCorriente' */
  C_5DOF_EL_B.TmpSignalConversionAtCont_k[0] = 0.0;
  C_5DOF_EL_B.TmpSignalConversionAtCont_k[1] = 0.0;
  C_5DOF_EL_B.TmpSignalConversionAtCont_k[2] = 0.0;
  C_5DOF_EL_B.TmpSignalConversionAtCont_k[3] = 0.0;

  /* RateTransition generated from: '<S5>/Mezclador' */
  if (tmp) {
    /* RateTransition generated from: '<S5>/Mezclador' */
    for (i = 0; i < 6; i++) {
      C_5DOF_EL_B.TmpRTBAtMezcladorOutport1_j[i] =
        C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buf_g[i];
    }

    /* End of RateTransition generated from: '<S5>/Mezclador' */
  }

  /* Lookup_n-D: '<S5>/InvLUT_1' */
  C_5DOF_EL_B.LUT_HEMS_3 = look2_binlcpw(C_5DOF_EL_B.AG_mm[0],
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1_j[0], C_5DOF_EL_ConstP.pooled15,
    C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled14,
    C_5DOF_EL_ConstP.pooled32, 13U);

  /* Lookup_n-D: '<S5>/InvLUT_2' */
  C_5DOF_EL_B.LUT_HEMS_4 = look2_binlcpw(C_5DOF_EL_B.AG_mm[1],
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1_j[1], C_5DOF_EL_ConstP.pooled15,
    C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled14,
    C_5DOF_EL_ConstP.pooled32, 13U);

  /* Lookup_n-D: '<S5>/InvLUT_3' */
  C_5DOF_EL_B.LUT_EMS_5 = look2_binlcpw(C_5DOF_EL_B.AG_mm[2],
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1_j[2], C_5DOF_EL_ConstP.pooled15,
    C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled14,
    C_5DOF_EL_ConstP.pooled32, 13U);

  /* Lookup_n-D: '<S5>/InvLUT_4' */
  C_5DOF_EL_B.LUT_EMS_6 = look2_binlcpw(C_5DOF_EL_B.AG_mm[3],
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1_j[3], C_5DOF_EL_ConstP.pooled15,
    C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled14,
    C_5DOF_EL_ConstP.pooled32, 13U);

  /* Lookup_n-D: '<S5>/InvLUT_5' */
  C_5DOF_EL_B.LUT_HEMS_2 = look2_binlcpw(C_5DOF_EL_B.AG_mm[4],
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1_j[4], C_5DOF_EL_ConstP.pooled15,
    C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled14,
    C_5DOF_EL_ConstP.pooled32, 13U);

  /* Lookup_n-D: '<S5>/InvLUT_6' */
  C_5DOF_EL_B.LUT_HEMS_1 = look2_binlcpw(C_5DOF_EL_B.AG_mm[5],
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1_j[5], C_5DOF_EL_ConstP.pooled15,
    C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled14,
    C_5DOF_EL_ConstP.pooled32, 13U);

  /* Saturate: '<S5>/Sat_I' */
  if (C_5DOF_EL_B.LUT_HEMS_3 > 50.0) {
    C_5DOF_EL_B.AG_mm[0] = 50.0;
  } else if (C_5DOF_EL_B.LUT_HEMS_3 < 0.0) {
    C_5DOF_EL_B.AG_mm[0] = 0.0;
  } else {
    C_5DOF_EL_B.AG_mm[0] = C_5DOF_EL_B.LUT_HEMS_3;
  }

  if (C_5DOF_EL_B.LUT_HEMS_4 > 50.0) {
    C_5DOF_EL_B.AG_mm[1] = 50.0;
  } else if (C_5DOF_EL_B.LUT_HEMS_4 < 0.0) {
    C_5DOF_EL_B.AG_mm[1] = 0.0;
  } else {
    C_5DOF_EL_B.AG_mm[1] = C_5DOF_EL_B.LUT_HEMS_4;
  }

  if (C_5DOF_EL_B.LUT_EMS_5 > 50.0) {
    C_5DOF_EL_B.AG_mm[2] = 50.0;
  } else if (C_5DOF_EL_B.LUT_EMS_5 < 0.0) {
    C_5DOF_EL_B.AG_mm[2] = 0.0;
  } else {
    C_5DOF_EL_B.AG_mm[2] = C_5DOF_EL_B.LUT_EMS_5;
  }

  if (C_5DOF_EL_B.LUT_EMS_6 > 50.0) {
    C_5DOF_EL_B.AG_mm[3] = 50.0;
  } else if (C_5DOF_EL_B.LUT_EMS_6 < 0.0) {
    C_5DOF_EL_B.AG_mm[3] = 0.0;
  } else {
    C_5DOF_EL_B.AG_mm[3] = C_5DOF_EL_B.LUT_EMS_6;
  }

  if (C_5DOF_EL_B.LUT_HEMS_2 > 50.0) {
    C_5DOF_EL_B.AG_mm[4] = 50.0;
  } else if (C_5DOF_EL_B.LUT_HEMS_2 < 0.0) {
    C_5DOF_EL_B.AG_mm[4] = 0.0;
  } else {
    C_5DOF_EL_B.AG_mm[4] = C_5DOF_EL_B.LUT_HEMS_2;
  }

  if (C_5DOF_EL_B.LUT_HEMS_1 > 50.0) {
    C_5DOF_EL_B.AG_mm[5] = 50.0;
  } else if (C_5DOF_EL_B.LUT_HEMS_1 < 0.0) {
    C_5DOF_EL_B.AG_mm[5] = 0.0;
  } else {
    C_5DOF_EL_B.AG_mm[5] = C_5DOF_EL_B.LUT_HEMS_1;
  }

  /* End of Saturate: '<S5>/Sat_I' */

  /* Outputs for Atomic SubSystem: '<S2>/ControlDeCorriente' */
  /* Outport: '<Root>/V' */
  C_5DOF_E_ControlDeCorriente(C_5DOF_EL_B.AG_mm_h,
    C_5DOF_EL_B.TmpSignalConversionAtCont_k,
    C_5DOF_EL_B.TmpSignalConversionAtContro, C_5DOF_EL_B.AG_mm,
    &C_5DOF_EL_B.LUT_HEMS_1, &C_5DOF_EL_B.LUT_HEMS_2, &C_5DOF_EL_B.LUT_HEMS_3,
    &C_5DOF_EL_B.LUT_HEMS_4, &C_5DOF_EL_B.LUT_EMS_5, &C_5DOF_EL_B.LUT_EMS_6,
    &C_5DOF_EL_Y.V[6], &C_5DOF_EL_Y.V[7], &C_5DOF_EL_Y.V[8], &C_5DOF_EL_Y.V[9],
    &C_5DOF_EL_B.ControlDeCorriente, &C_5DOF_EL_DW.ControlDeCorriente);

  /* End of Outputs for SubSystem: '<S2>/ControlDeCorriente' */
  C_5DOF_EL_Y.V[0] = C_5DOF_EL_B.LUT_HEMS_1;
  C_5DOF_EL_Y.V[1] = C_5DOF_EL_B.LUT_HEMS_2;
  C_5DOF_EL_Y.V[2] = C_5DOF_EL_B.LUT_HEMS_3;
  C_5DOF_EL_Y.V[3] = C_5DOF_EL_B.LUT_HEMS_4;
  C_5DOF_EL_Y.V[4] = C_5DOF_EL_B.LUT_EMS_5;
  C_5DOF_EL_Y.V[5] = C_5DOF_EL_B.LUT_EMS_6;

  /* Lookup_n-D: '<S6>/LUT_EMS_1' */
  C_5DOF_EL_B.LUT_HEMS_3 = C_5DOF_EL_B.TmpSignalConversionAtKin_EM[0];

  /* Lookup_n-D: '<S6>/LUT_EMS_2' */
  C_5DOF_EL_B.LUT_HEMS_4 = C_5DOF_EL_B.TmpSignalConversionAtKin_EM[1];

  /* Lookup_n-D: '<S6>/LUT_EMS_3' */
  C_5DOF_EL_B.LUT_EMS_5 = C_5DOF_EL_B.TmpSignalConversionAtKin_EM[2];

  /* Lookup_n-D: '<S6>/LUT_EMS_4' */
  C_5DOF_EL_B.LUT_EMS_6 = C_5DOF_EL_B.TmpSignalConversionAtKin_EM[3];

  /* Lookup_n-D: '<S6>/LUT_EMS_5' */
  C_5DOF_EL_B.LUT_HEMS_2 = C_5DOF_EL_B.TmpSignalConversionAtKin_EM[4];

  /* Lookup_n-D: '<S6>/LUT_EMS_6' */
  C_5DOF_EL_B.LUT_HEMS_1 = C_5DOF_EL_B.TmpSignalConversionAtKin_EM[5];

  /* SignalConversion generated from: '<S6>/Kin_EMS' incorporates:
   *  Lookup_n-D: '<S6>/LUT_EMS_1'
   *  Lookup_n-D: '<S6>/LUT_EMS_2'
   *  Lookup_n-D: '<S6>/LUT_EMS_3'
   *  Lookup_n-D: '<S6>/LUT_EMS_4'
   *  Lookup_n-D: '<S6>/LUT_EMS_5'
   *  Lookup_n-D: '<S6>/LUT_EMS_6'
   */
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[0] = look2_binlcpw
    (C_5DOF_EL_B.LUT_HEMS_3, 0.0, C_5DOF_EL_ConstP.pooled15,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled17,
     C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[1] = look2_binlcpw
    (C_5DOF_EL_B.LUT_HEMS_4, 0.0, C_5DOF_EL_ConstP.pooled15,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled17,
     C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[2] = look2_binlcpw
    (C_5DOF_EL_B.LUT_EMS_5, 0.0, C_5DOF_EL_ConstP.pooled15,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled17,
     C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[3] = look2_binlcpw
    (C_5DOF_EL_B.LUT_EMS_6, 0.0, C_5DOF_EL_ConstP.pooled15,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled17,
     C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[4] = look2_binlcpw
    (C_5DOF_EL_B.LUT_HEMS_2, 0.0, C_5DOF_EL_ConstP.pooled15,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled17,
     C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[5] = look2_binlcpw
    (C_5DOF_EL_B.LUT_HEMS_1, 0.0, C_5DOF_EL_ConstP.pooled15,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled17,
     C_5DOF_EL_ConstP.pooled33, 13U);

  /* RateTransition generated from: '<S5>/Y' incorporates:
   *  UnitDelay: '<S2>/uz'
   */
  if (tmp) {
    C_5DOF_EL_DW.TmpRTBAtYInport1_Buffer[0] = C_5DOF_EL_B.u[0];
    C_5DOF_EL_DW.TmpRTBAtYInport1_Buffer[1] = C_5DOF_EL_DW.uz_DSTATE[3];

    /* RateTransition generated from: '<S5>/Yaw' incorporates:
     *  UnitDelay: '<S2>/uz'
     */
    C_5DOF_EL_DW.TmpRTBAtYawInport1_Buffer[0] = C_5DOF_EL_B.u[4];
    C_5DOF_EL_DW.TmpRTBAtYawInport1_Buffer[1] = C_5DOF_EL_DW.uz_DSTATE[4];

    /* RateTransition generated from: '<S7>/Pitch' incorporates:
     *  UnitDelay: '<S2>/uz'
     */
    C_5DOF_EL_DW.TmpRTBAtPitchInport1_Buffer[0] = C_5DOF_EL_B.u[3];
    C_5DOF_EL_DW.TmpRTBAtPitchInport1_Buffer[1] = C_5DOF_EL_DW.uz_DSTATE[2];

    /* RateTransition generated from: '<S7>/Roll' incorporates:
     *  UnitDelay: '<S2>/uz'
     */
    C_5DOF_EL_DW.TmpRTBAtRollInport1_Buffer[0] = C_5DOF_EL_B.u[2];
    C_5DOF_EL_DW.TmpRTBAtRollInport1_Buffer[1] = C_5DOF_EL_DW.uz_DSTATE[1];

    /* RateTransition generated from: '<S7>/Z' incorporates:
     *  UnitDelay: '<S2>/uz'
     */
    C_5DOF_EL_DW.TmpRTBAtZInport1_Buffer[0] = C_5DOF_EL_B.u[1];
    C_5DOF_EL_DW.TmpRTBAtZInport1_Buffer[1] = C_5DOF_EL_DW.uz_DSTATE[0];
  }

  /* Lookup_n-D: '<S6>/LUT_HEMS_1' */
  C_5DOF_EL_B.LUT_HEMS_3 = look2_binlcpw(C_5DOF_EL_B.smax, 0.0,
    C_5DOF_EL_ConstP.pooled11, C_5DOF_EL_ConstP.pooled20,
    C_5DOF_EL_ConstP.pooled19, C_5DOF_EL_ConstP.pooled34, 14U);

  /* Lookup_n-D: '<S6>/LUT_HEMS_2' */
  C_5DOF_EL_B.LUT_HEMS_4 = look2_binlcpw(C_5DOF_EL_B.s, 0.0,
    C_5DOF_EL_ConstP.pooled11, C_5DOF_EL_ConstP.pooled20,
    C_5DOF_EL_ConstP.pooled19, C_5DOF_EL_ConstP.pooled34, 14U);

  /* Lookup_n-D: '<S6>/LUT_HEMS_3' */
  C_5DOF_EL_B.LUT_EMS_5 = look2_binlcpw(C_5DOF_EL_B.rtb_airgaps_actuadores_tmp,
    0.0, C_5DOF_EL_ConstP.pooled11, C_5DOF_EL_ConstP.pooled20,
    C_5DOF_EL_ConstP.pooled19, C_5DOF_EL_ConstP.pooled34, 14U);

  /* Lookup_n-D: '<S6>/LUT_HEMS_4' */
  C_5DOF_EL_B.LUT_EMS_6 = look2_binlcpw(C_5DOF_EL_B.rtb_airgaps_actuadores_tmp_m,
    0.0, C_5DOF_EL_ConstP.pooled11, C_5DOF_EL_ConstP.pooled20,
    C_5DOF_EL_ConstP.pooled19, C_5DOF_EL_ConstP.pooled34, 14U);

  /* Sum: '<S6>/Sum_HEMS' incorporates:
   *  Gain: '<S6>/Kin_HEMS'
   *  Lookup_n-D: '<S6>/LUT_HEMS_1'
   *  Lookup_n-D: '<S6>/LUT_HEMS_2'
   *  Lookup_n-D: '<S6>/LUT_HEMS_3'
   *  Lookup_n-D: '<S6>/LUT_HEMS_4'
   */
  for (i = 0; i < 3; i++) {
    C_5DOF_EL_B.dv[i] = ((C_5DOF_EL_ConstP.Kin_HEMS_Gain[i + 3] *
                          C_5DOF_EL_B.LUT_HEMS_4 +
                          C_5DOF_EL_ConstP.Kin_HEMS_Gain[i] *
                          C_5DOF_EL_B.LUT_HEMS_3) +
                         C_5DOF_EL_ConstP.Kin_HEMS_Gain[i + 6] *
                         C_5DOF_EL_B.LUT_EMS_5) +
      C_5DOF_EL_ConstP.Kin_HEMS_Gain[i + 9] * C_5DOF_EL_B.LUT_EMS_6;
  }

  /* End of Sum: '<S6>/Sum_HEMS' */

  /* Gain: '<S6>/Kin_EMS' */
  C_5DOF_EL_B.LUT_HEMS_3 = 0.0;
  C_5DOF_EL_B.LUT_HEMS_4 = 0.0;
  for (i = 0; i < 6; i++) {
    C_5DOF_EL_B.smax = C_5DOF_EL_B.TmpSignalConversionAtKin_EM[i];
    C_5DOF_EL_B.jj = i << 1;
    C_5DOF_EL_B.LUT_HEMS_3 += C_5DOF_EL_ConstP.Kin_EMS_Gain[C_5DOF_EL_B.jj] *
      C_5DOF_EL_B.smax;
    C_5DOF_EL_B.LUT_HEMS_4 += C_5DOF_EL_ConstP.Kin_EMS_Gain[C_5DOF_EL_B.jj + 1] *
      C_5DOF_EL_B.smax;
  }

  /* End of Gain: '<S6>/Kin_EMS' */

  /* Update for UnitDelay: '<S2>/uz' */
  C_5DOF_EL_DW.uz_DSTATE[0] = C_5DOF_EL_B.dv[0];
  C_5DOF_EL_DW.uz_DSTATE[1] = C_5DOF_EL_B.dv[1];
  C_5DOF_EL_DW.uz_DSTATE[2] = C_5DOF_EL_B.dv[2];
  C_5DOF_EL_DW.uz_DSTATE[3] = C_5DOF_EL_B.LUT_HEMS_3;
  C_5DOF_EL_DW.uz_DSTATE[4] = C_5DOF_EL_B.LUT_HEMS_4;
}

/* Model step function for TID1 */
void C_5DOF_EL_step1(void)             /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_TmpRTBAtPitchInport1[2];
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_TmpSignalConversionAtSFun_1;
  real_T rtb_b0_Roll;
  real_T rtb_b0_Y;
  real_T tmp;
  int32_T i;

  /* DiscreteStateSpace: '<S5>/Y' */
  {
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[0];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[1];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[2];
  }

  /* Gain: '<S5>/b0_Y' incorporates:
   *  Constant: '<S5>/Ref_Y'
   *  Gain: '<S5>/Kd_Y'
   *  Gain: '<S5>/Kp_Y'
   *  Sum: '<S5>/Sum2_Y'
   *  Sum: '<S5>/Sum3_Y'
   *  Sum: '<S5>/SumErr_Y'
   */
  rtb_b0_Y = (((0.0 - C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0]) * 400.0 - 80.0
               * C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1]) -
              C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2]) * 250.0;

  /* DiscreteStateSpace: '<S5>/Yaw' */
  {
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[0];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[1];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[2];
  }

  /* SignalConversion generated from: '<S559>/ SFunction ' incorporates:
   *  Constant: '<S5>/Ref_Yaw'
   *  Gain: '<S5>/Fy_x2'
   *  Gain: '<S5>/Kd_Yaw'
   *  Gain: '<S5>/Kp_Yaw'
   *  Gain: '<S5>/Mz_x2'
   *  Gain: '<S5>/b0_Yaw'
   *  MATLAB Function: '<S5>/Mezclador'
   *  Sum: '<S5>/Sum2_Yaw'
   *  Sum: '<S5>/Sum3_Yaw'
   *  Sum: '<S5>/SumErr_Yaw'
   */
  rtb_TmpSignalConversionAtSFun_0 = 2.0 * rtb_b0_Y;
  rtb_TmpSignalConversionAtSFun_1 = (((0.0 -
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0]) * 400.0 - 80.0 *
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1]) -
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2]) * 29.297 * 2.0;

  /* MATLAB Function: '<S5>/Mezclador' */
  rtb_b0_Y = -0.16666666666666666 * rtb_TmpSignalConversionAtSFun_0;
  rtb_b0_Roll = -0.30266343825665859 * rtb_TmpSignalConversionAtSFun_1;
  C_5DOF_EL_B.F_des_n[0] = rtb_b0_Y + rtb_b0_Roll;
  rtb_TmpSignalConversionAtSFun_0 *= 0.16666666666666666;
  rtb_TmpSignalConversionAtSFun_1 *= 0.30266343825665859;
  C_5DOF_EL_B.F_des_n[1] = rtb_TmpSignalConversionAtSFun_0 +
    rtb_TmpSignalConversionAtSFun_1;
  C_5DOF_EL_B.F_des_n[2] = rtb_b0_Y;
  C_5DOF_EL_B.F_des_n[3] = rtb_TmpSignalConversionAtSFun_0;
  C_5DOF_EL_B.F_des_n[4] = rtb_b0_Y + rtb_TmpSignalConversionAtSFun_1;
  C_5DOF_EL_B.F_des_n[5] = rtb_TmpSignalConversionAtSFun_0 + rtb_b0_Roll;

  /* RateTransition generated from: '<S5>/Mezclador' */
  for (i = 0; i < 6; i++) {
    C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buf_g[i] = C_5DOF_EL_B.F_des_n[i];
  }

  /* End of RateTransition generated from: '<S5>/Mezclador' */

  /* DiscreteStateSpace: '<S7>/Z' */
  {
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[0];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[1];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[2];
  }

  /* Gain: '<S7>/b0_Z' incorporates:
   *  Constant: '<S7>/Ref_Z'
   *  Gain: '<S7>/Kd_Z'
   *  Gain: '<S7>/Kp_Z'
   *  Sum: '<S7>/Sum2_Z'
   *  Sum: '<S7>/Sum3_Z'
   *  Sum: '<S7>/SumErr_Z'
   */
  rtb_b0_Y = (((0.01643 - C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0]) * 900.0 -
               60.0 * C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1]) -
              C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2]) * 250.0;

  /* DiscreteStateSpace: '<S7>/Roll' */
  {
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE
      [0];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE
      [1];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE
      [2];
  }

  /* Gain: '<S7>/b0_Roll' incorporates:
   *  Constant: '<S7>/Ref_Roll'
   *  Gain: '<S7>/Kd_Roll'
   *  Gain: '<S7>/Kp_Roll'
   *  Sum: '<S7>/Sum2_Roll'
   *  Sum: '<S7>/Sum3_Roll'
   *  Sum: '<S7>/SumErr_Roll'
   */
  rtb_b0_Roll = (((0.0 - C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0]) * 1225.0 -
                  70.0 * C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1]) -
                 C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2]) * 43.082;

  /* DiscreteStateSpace: '<S7>/Pitch' */
  {
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0] = (1.0)*
      C_5DOF_EL_DW.Pitch_DSTATE[0];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1] = (1.0)*
      C_5DOF_EL_DW.Pitch_DSTATE[1];
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2] = (1.0)*
      C_5DOF_EL_DW.Pitch_DSTATE[2];
  }

  /* Sum: '<S7>/SumErr_Pitch' */
  rtb_TmpSignalConversionAtSFun_1 = C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0];

  /* Gain: '<S7>/Kd_Pitch' */
  rtb_TmpSignalConversionAtSFun_0 = C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1];

  /* Sum: '<S7>/Sum3_Pitch' */
  tmp = C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2];

  /* SignalConversion generated from: '<S560>/ SFunction ' incorporates:
   *  Constant: '<S7>/Ref_Pitch'
   *  Gain: '<S7>/Kd_Pitch'
   *  Gain: '<S7>/Kp_Pitch'
   *  Gain: '<S7>/b0_Pitch'
   *  MATLAB Function: '<S7>/Mezclador'
   *  Sum: '<S7>/Sum2_Pitch'
   *  Sum: '<S7>/Sum3_Pitch'
   *  Sum: '<S7>/SumErr_Pitch'
   */
  C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0] = rtb_b0_Y;
  C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1] = rtb_b0_Roll;
  C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2] = (((0.0 -
    rtb_TmpSignalConversionAtSFun_1) * 1225.0 - 70.0 *
    rtb_TmpSignalConversionAtSFun_0) - tmp) * 26.887;

  /* MATLAB Function: '<S7>/Mezclador' */
  rtb_b0_Y = -0.25 * C_5DOF_EL_B.TmpSignalConversionAtSFun_c[0];
  rtb_b0_Roll = 1.3089005235602094 * C_5DOF_EL_B.TmpSignalConversionAtSFun_c[1];
  rtb_TmpSignalConversionAtSFun_1 = 0.36764705882352938 *
    C_5DOF_EL_B.TmpSignalConversionAtSFun_c[2];
  rtb_TmpSignalConversionAtSFun_0 = rtb_b0_Y + rtb_b0_Roll;
  C_5DOF_EL_B.F_des[0] = rtb_TmpSignalConversionAtSFun_0 +
    rtb_TmpSignalConversionAtSFun_1;
  rtb_b0_Y -= rtb_b0_Roll;
  C_5DOF_EL_B.F_des[1] = rtb_b0_Y + rtb_TmpSignalConversionAtSFun_1;
  C_5DOF_EL_B.F_des[2] = rtb_TmpSignalConversionAtSFun_0 -
    rtb_TmpSignalConversionAtSFun_1;
  C_5DOF_EL_B.F_des[3] = rtb_b0_Y - rtb_TmpSignalConversionAtSFun_1;

  /* RateTransition generated from: '<S7>/Mezclador' */
  C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[0] = C_5DOF_EL_B.F_des[0];
  C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[1] = C_5DOF_EL_B.F_des[1];
  C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[2] = C_5DOF_EL_B.F_des[2];
  C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[3] = C_5DOF_EL_B.F_des[3];

  /* RateTransition generated from: '<S5>/Y' */
  C_5DOF_EL_B.TmpRTBAtYInport1[0] = C_5DOF_EL_DW.TmpRTBAtYInport1_Buffer[0];

  /* RateTransition generated from: '<S5>/Yaw' */
  C_5DOF_EL_B.TmpRTBAtYawInport1[0] = C_5DOF_EL_DW.TmpRTBAtYawInport1_Buffer[0];

  /* RateTransition generated from: '<S7>/Pitch' */
  rtb_TmpRTBAtPitchInport1[0] = C_5DOF_EL_DW.TmpRTBAtPitchInport1_Buffer[0];

  /* RateTransition generated from: '<S7>/Roll' */
  C_5DOF_EL_B.TmpRTBAtRollInport1[0] = C_5DOF_EL_DW.TmpRTBAtRollInport1_Buffer[0];

  /* RateTransition generated from: '<S7>/Z' */
  C_5DOF_EL_B.TmpRTBAtZInport1[0] = C_5DOF_EL_DW.TmpRTBAtZInport1_Buffer[0];

  /* RateTransition generated from: '<S5>/Y' */
  C_5DOF_EL_B.TmpRTBAtYInport1[1] = C_5DOF_EL_DW.TmpRTBAtYInport1_Buffer[1];

  /* RateTransition generated from: '<S5>/Yaw' */
  C_5DOF_EL_B.TmpRTBAtYawInport1[1] = C_5DOF_EL_DW.TmpRTBAtYawInport1_Buffer[1];

  /* RateTransition generated from: '<S7>/Pitch' */
  rtb_TmpRTBAtPitchInport1[1] = C_5DOF_EL_DW.TmpRTBAtPitchInport1_Buffer[1];

  /* RateTransition generated from: '<S7>/Roll' */
  C_5DOF_EL_B.TmpRTBAtRollInport1[1] = C_5DOF_EL_DW.TmpRTBAtRollInport1_Buffer[1];

  /* RateTransition generated from: '<S7>/Z' */
  C_5DOF_EL_B.TmpRTBAtZInport1[1] = C_5DOF_EL_DW.TmpRTBAtZInport1_Buffer[1];

  /* Update for DiscreteStateSpace: '<S5>/Y' */
  {
    real_T xnew[3];
    xnew[0] = (0.85719882183949758)*C_5DOF_EL_DW.Y_DSTATE[0]
      + (0.00092859941091974875)*C_5DOF_EL_DW.Y_DSTATE[1]
      + (4.6429970545987424E-7)*C_5DOF_EL_DW.Y_DSTATE[2];
    xnew[0] += (0.14280117816050261)*C_5DOF_EL_B.TmpRTBAtYInport1[0]
      + (1.8571988218394976E-9)*C_5DOF_EL_B.TmpRTBAtYInport1[1];
    xnew[1] = (-7.0225330450806)*C_5DOF_EL_DW.Y_DSTATE[0]
      + (0.99648873347745981)*C_5DOF_EL_DW.Y_DSTATE[1]
      + (0.00099824436673872957)*C_5DOF_EL_DW.Y_DSTATE[2];
    xnew[1] += (7.0225330450805989)*C_5DOF_EL_B.TmpRTBAtYInport1[0]
      + (3.9929774669549195E-6)*C_5DOF_EL_B.TmpRTBAtYInport1[1];
    xnew[2] = (-116.07492636496859)*C_5DOF_EL_DW.Y_DSTATE[0]
      + (-0.058037463182484296)*C_5DOF_EL_DW.Y_DSTATE[1]
      + (0.99997098126840867)*C_5DOF_EL_DW.Y_DSTATE[2];
    xnew[2] += (116.07492636496858)*C_5DOF_EL_B.TmpRTBAtYInport1[0]
      + (-1.1607492636496859E-7)*C_5DOF_EL_B.TmpRTBAtYInport1[1];
    (void) memcpy(&C_5DOF_EL_DW.Y_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S5>/Yaw' */
  {
    real_T xnew[3];
    xnew[0] = (0.85719882183949758)*C_5DOF_EL_DW.Yaw_DSTATE[0]
      + (0.00092859941091974875)*C_5DOF_EL_DW.Yaw_DSTATE[1]
      + (4.6429970545987424E-7)*C_5DOF_EL_DW.Yaw_DSTATE[2];
    xnew[0] += (0.14280117816050261)*C_5DOF_EL_B.TmpRTBAtYawInport1[0]
      + (1.5848028994773337E-8)*C_5DOF_EL_B.TmpRTBAtYawInport1[1];
    xnew[1] = (-7.0225330450806)*C_5DOF_EL_DW.Yaw_DSTATE[0]
      + (0.99648873347745981)*C_5DOF_EL_DW.Yaw_DSTATE[1]
      + (0.00099824436673872957)*C_5DOF_EL_DW.Yaw_DSTATE[2];
    xnew[1] += (7.0225330450805989)*C_5DOF_EL_B.TmpRTBAtYawInport1[0]
      + (3.4073262338762669E-5)*C_5DOF_EL_B.TmpRTBAtYawInport1[1];
    xnew[2] = (-116.07492636496859)*C_5DOF_EL_DW.Yaw_DSTATE[0]
      + (-0.058037463182484296)*C_5DOF_EL_DW.Yaw_DSTATE[1]
      + (0.99997098126840867)*C_5DOF_EL_DW.Yaw_DSTATE[2];
    xnew[2] += (116.07492636496858)*C_5DOF_EL_B.TmpRTBAtYawInport1[0]
      + (-9.9050181217333332E-7)*C_5DOF_EL_B.TmpRTBAtYawInport1[1];
    (void) memcpy(&C_5DOF_EL_DW.Yaw_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S7>/Z' */
  {
    real_T xnew[3];
    xnew[0] = (0.75259320810981811)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (0.000876296604054912)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (4.3814830202746851E-7)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[0] += (0.24740679189018189)*C_5DOF_EL_B.TmpRTBAtZInport1[0]
      + (1.7525932081098171E-9)*C_5DOF_EL_B.TmpRTBAtZInport1[1];
    xnew[1] = (-21.613417590712306)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (0.98919329120464383)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (0.000994596645602322)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[1] += (21.613417590712306)*C_5DOF_EL_B.TmpRTBAtZInport1[0]
      + (3.9783865824092869E-6)*C_5DOF_EL_B.TmpRTBAtZInport1[1];
    xnew[2] = (-638.82022435602892)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (-0.31941011217801363)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (0.99984029494391125)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[2] += (638.82022435602892)*C_5DOF_EL_B.TmpRTBAtZInport1[0]
      + (-6.388202243560248E-7)*C_5DOF_EL_B.TmpRTBAtZInport1[1];
    (void) memcpy(&C_5DOF_EL_DW.Z_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S7>/Roll' */
  {
    real_T xnew[3];
    xnew[0] = (0.75259320810981811)*C_5DOF_EL_DW.Roll_DSTATE[0]
      + (0.000876296604054912)*C_5DOF_EL_DW.Roll_DSTATE[1]
      + (4.3814830202746851E-7)*C_5DOF_EL_DW.Roll_DSTATE[2];
    xnew[0] += (0.24740679189018189)*C_5DOF_EL_B.TmpRTBAtRollInport1[0]
      + (1.0170101249418672E-8)*C_5DOF_EL_B.TmpRTBAtRollInport1[1];
    xnew[1] = (-21.613417590712306)*C_5DOF_EL_DW.Roll_DSTATE[0]
      + (0.98919329120464383)*C_5DOF_EL_DW.Roll_DSTATE[1]
      + (0.000994596645602322)*C_5DOF_EL_DW.Roll_DSTATE[2];
    xnew[1] += (21.613417590712306)*C_5DOF_EL_B.TmpRTBAtRollInport1[0]
      + (2.3086129836180353E-5)*C_5DOF_EL_B.TmpRTBAtRollInport1[1];
    xnew[2] = (-638.82022435602892)*C_5DOF_EL_DW.Roll_DSTATE[0]
      + (-0.31941011217801363)*C_5DOF_EL_DW.Roll_DSTATE[1]
      + (0.99984029494391125)*C_5DOF_EL_DW.Roll_DSTATE[2];
    xnew[2] += (638.82022435602892)*C_5DOF_EL_B.TmpRTBAtRollInport1[0]
      + (-3.7070019054130953E-6)*C_5DOF_EL_B.TmpRTBAtRollInport1[1];
    (void) memcpy(&C_5DOF_EL_DW.Roll_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S7>/Pitch' */
  {
    real_T xnew[3];
    xnew[0] = (0.75259320810981811)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (0.000876296604054912)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (4.3814830202746851E-7)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[0] += (0.24740679189018189)*rtb_TmpRTBAtPitchInport1[0] +
      (1.629591631745635E-8)*rtb_TmpRTBAtPitchInport1[1];
    xnew[1] = (-21.613417590712306)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (0.98919329120464383)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (0.000994596645602322)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[1] += (21.613417590712306)*rtb_TmpRTBAtPitchInport1[0] +
      (3.69917300406264E-5)*rtb_TmpRTBAtPitchInport1[1];
    xnew[2] = (-638.82022435602892)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (-0.31941011217801363)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (0.99984029494391125)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[2] += (638.82022435602892)*rtb_TmpRTBAtPitchInport1[0] +
      (-5.9398614977128325E-6)*rtb_TmpRTBAtPitchInport1[1];
    (void) memcpy(&C_5DOF_EL_DW.Pitch_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }
}

/* Model initialize function */
void C_5DOF_EL_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)C_5DOF_EL_M, 0,
                sizeof(RT_MODEL_C_5DOF_EL_T));

  /* Set task counter limit used by the static main program */
  (C_5DOF_EL_M)->Timing.TaskCounters.cLimit[0] = 1;
  (C_5DOF_EL_M)->Timing.TaskCounters.cLimit[1] = 2;

  /* block I/O */
  (void) memset(((void *) &C_5DOF_EL_B), 0,
                sizeof(B_C_5DOF_EL_T));

  /* states (dwork) */
  (void) memset((void *)&C_5DOF_EL_DW, 0,
                sizeof(DW_C_5DOF_EL_T));

  /* InitializeConditions for DiscreteStateSpace: '<S5>/Y' */
  C_5DOF_EL_DW.Y_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Y_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Y_DSTATE[2] = (0.0);

  /* InitializeConditions for DiscreteStateSpace: '<S5>/Yaw' */
  C_5DOF_EL_DW.Yaw_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Yaw_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Yaw_DSTATE[2] = (0.0);

  /* InitializeConditions for DiscreteStateSpace: '<S7>/Z' */
  C_5DOF_EL_DW.Z_DSTATE[0] = (0.0225);
  C_5DOF_EL_DW.Z_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Z_DSTATE[2] = (0.0);

  /* InitializeConditions for DiscreteStateSpace: '<S7>/Roll' */
  C_5DOF_EL_DW.Roll_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Roll_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Roll_DSTATE[2] = (0.0);

  /* InitializeConditions for DiscreteStateSpace: '<S7>/Pitch' */
  C_5DOF_EL_DW.Pitch_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Pitch_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Pitch_DSTATE[2] = (0.0);

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
  C_5DOF_EL_DW.H_pseudo_not_empty = false;

  /* SystemInitialize for Atomic SubSystem: '<S2>/ControlDeCorriente' */
  C_5_ControlDeCorriente_Init(&C_5DOF_EL_DW.ControlDeCorriente);

  /* End of SystemInitialize for SubSystem: '<S2>/ControlDeCorriente' */
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
