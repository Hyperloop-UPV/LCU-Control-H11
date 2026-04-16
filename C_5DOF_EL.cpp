//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: C_5DOF_EL.cpp
//
// Code generated for Simulink model 'C_5DOF_EL'.
//
// Model version                  : 1.82
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Thu Apr 16 19:58:10 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "C_5DOF_EL.h"
#include <cmath>
#include "rtwtypes.h"
#include "C_5DOF_EL_private.h"

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

  // Column-major Lookup 2-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Clip'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    // Binary Search
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

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    // Binary Search
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

  // Column-major Interpolation 2-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

// Model step function for TID0
void C_5DOF_EL::step0()                // Sample time: [0.0005s, 0.0s]
{
  int32_T i;
  int8_T ipiv;
  boolean_T tmp;
  static const real_T h[5]{ 0.0, -1.0, 0.21748, 1.0093, 0.0 };

  static const real_T g[5]{ 0.0, -1.0, -0.21748, 1.0093, 0.0 };

  static const real_T f[5]{ 0.0, -1.0, 0.21748, -1.0093, 0.0 };

  static const real_T e[5]{ 0.0, -1.0, -0.21748, -1.0093, 0.0 };

  static const real_T b_H_tmp[5]{ 1.0, 0.0, -0.18782, 0.0, 1.0095 };

  static const real_T H_tmp[5]{ 1.0, 0.0, -0.18782, 0.0, -1.0095 };

  // Update the flag to indicate when data transfers from
  //   Sample time: [0.0005s, 0.0s] to Sample time: [0.001s, 0.0s]
  ((&C_5DOF_EL_M)->Timing.RateInteraction.TID0_1)++;
  if (((&C_5DOF_EL_M)->Timing.RateInteraction.TID0_1) > 1) {
    (&C_5DOF_EL_M)->Timing.RateInteraction.TID0_1 = 0;
  }

  // MATLAB Function: '<Root>/GapToStates' incorporates:
  //   Inport: '<Root>/SensoresPos'

  if (!C_5DOF_EL_DW.H_pseudo_not_empty) {
    i = 0;
    for (C_5DOF_EL_B.b_j = 0; C_5DOF_EL_B.b_j < 5; C_5DOF_EL_B.b_j++) {
      C_5DOF_EL_B.H[i] = h[C_5DOF_EL_B.b_j];
      C_5DOF_EL_B.H[i + 1] = g[C_5DOF_EL_B.b_j];
      C_5DOF_EL_B.H[i + 2] = f[C_5DOF_EL_B.b_j];
      C_5DOF_EL_B.H[i + 3] = e[C_5DOF_EL_B.b_j];
      C_5DOF_EL_B.H[i + 4] = b_H_tmp[C_5DOF_EL_B.b_j];
      C_5DOF_EL_B.H[i + 5] = b_H_tmp[C_5DOF_EL_B.b_j];
      C_5DOF_EL_B.H[i + 6] = H_tmp[C_5DOF_EL_B.b_j];
      C_5DOF_EL_B.H[i + 7] = H_tmp[C_5DOF_EL_B.b_j];
      i += 8;
    }

    i = 0;
    C_5DOF_EL_B.b_j = 0;
    for (C_5DOF_EL_B.jj = 0; C_5DOF_EL_B.jj < 5; C_5DOF_EL_B.jj++) {
      C_5DOF_EL_B.iy = 0;
      for (C_5DOF_EL_B.b_ix = 0; C_5DOF_EL_B.b_ix < 5; C_5DOF_EL_B.b_ix++) {
        C_5DOF_EL_B.smax = 0.0;
        for (C_5DOF_EL_B.ix = 0; C_5DOF_EL_B.ix < 8; C_5DOF_EL_B.ix++) {
          C_5DOF_EL_B.smax += C_5DOF_EL_B.H[C_5DOF_EL_B.ix + C_5DOF_EL_B.iy] *
            C_5DOF_EL_B.H[C_5DOF_EL_B.ix + C_5DOF_EL_B.b_j];
        }

        C_5DOF_EL_B.A[C_5DOF_EL_B.b_ix + i] = C_5DOF_EL_B.smax;
        C_5DOF_EL_B.iy += 8;
      }

      i += 5;
      C_5DOF_EL_B.b_j += 8;
    }

    i = 0;
    for (C_5DOF_EL_B.b_j = 0; C_5DOF_EL_B.b_j < 8; C_5DOF_EL_B.b_j++) {
      C_5DOF_EL_B.jj = 0;
      for (C_5DOF_EL_B.iy = 0; C_5DOF_EL_B.iy < 5; C_5DOF_EL_B.iy++) {
        C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.iy + i] = C_5DOF_EL_B.H[C_5DOF_EL_B.jj
          + C_5DOF_EL_B.b_j];
        C_5DOF_EL_B.jj += 8;
      }

      i += 5;
    }

    for (i = 0; i < 5; i++) {
      C_5DOF_EL_B.ipiv[i] = static_cast<int8_T>(i + 1);
    }

    for (C_5DOF_EL_B.b_j = 0; C_5DOF_EL_B.b_j < 4; C_5DOF_EL_B.b_j++) {
      C_5DOF_EL_B.jj = C_5DOF_EL_B.b_j * 6;
      C_5DOF_EL_B.iy = 6 - C_5DOF_EL_B.b_j;
      C_5DOF_EL_B.b_ix = 0;
      C_5DOF_EL_B.smax = std::abs(C_5DOF_EL_B.A[C_5DOF_EL_B.jj]);
      for (i = 2; i < C_5DOF_EL_B.iy; i++) {
        C_5DOF_EL_B.s = std::abs(C_5DOF_EL_B.A[(C_5DOF_EL_B.jj + i) - 1]);
        if (C_5DOF_EL_B.s > C_5DOF_EL_B.smax) {
          C_5DOF_EL_B.b_ix = i - 1;
          C_5DOF_EL_B.smax = C_5DOF_EL_B.s;
        }
      }

      if (C_5DOF_EL_B.A[C_5DOF_EL_B.jj + C_5DOF_EL_B.b_ix] != 0.0) {
        if (C_5DOF_EL_B.b_ix != 0) {
          C_5DOF_EL_B.iy = C_5DOF_EL_B.b_j + C_5DOF_EL_B.b_ix;
          C_5DOF_EL_B.ipiv[C_5DOF_EL_B.b_j] = static_cast<int8_T>(C_5DOF_EL_B.iy
            + 1);
          for (C_5DOF_EL_B.ix = 0; C_5DOF_EL_B.ix < 5; C_5DOF_EL_B.ix++) {
            i = C_5DOF_EL_B.ix * 5 + C_5DOF_EL_B.b_j;
            C_5DOF_EL_B.smax = C_5DOF_EL_B.A[i];
            C_5DOF_EL_B.A[i] = C_5DOF_EL_B.A[C_5DOF_EL_B.iy];
            C_5DOF_EL_B.A[C_5DOF_EL_B.iy] = C_5DOF_EL_B.smax;
            C_5DOF_EL_B.iy += 5;
          }
        }

        C_5DOF_EL_B.iy = (C_5DOF_EL_B.jj - C_5DOF_EL_B.b_j) + 5;
        for (C_5DOF_EL_B.b_ix = C_5DOF_EL_B.jj + 2; C_5DOF_EL_B.b_ix <=
             C_5DOF_EL_B.iy; C_5DOF_EL_B.b_ix++) {
          C_5DOF_EL_B.A[C_5DOF_EL_B.b_ix - 1] /= C_5DOF_EL_B.A[C_5DOF_EL_B.jj];
        }
      }

      C_5DOF_EL_B.iy = 3 - C_5DOF_EL_B.b_j;
      C_5DOF_EL_B.b_ix = C_5DOF_EL_B.jj + 7;
      for (i = 0; i <= C_5DOF_EL_B.iy; i++) {
        C_5DOF_EL_B.smax = C_5DOF_EL_B.A[(i * 5 + C_5DOF_EL_B.jj) + 5];
        if (C_5DOF_EL_B.smax != 0.0) {
          C_5DOF_EL_B.ix = (C_5DOF_EL_B.b_ix - C_5DOF_EL_B.b_j) + 3;
          for (C_5DOF_EL_B.ijA = C_5DOF_EL_B.b_ix; C_5DOF_EL_B.ijA <=
               C_5DOF_EL_B.ix; C_5DOF_EL_B.ijA++) {
            C_5DOF_EL_B.A[C_5DOF_EL_B.ijA - 1] += C_5DOF_EL_B.A[((C_5DOF_EL_B.jj
              + C_5DOF_EL_B.ijA) - C_5DOF_EL_B.b_ix) + 1] * -C_5DOF_EL_B.smax;
          }
        }

        C_5DOF_EL_B.b_ix += 5;
      }
    }

    for (C_5DOF_EL_B.b_j = 0; C_5DOF_EL_B.b_j < 4; C_5DOF_EL_B.b_j++) {
      ipiv = C_5DOF_EL_B.ipiv[C_5DOF_EL_B.b_j];
      if (C_5DOF_EL_B.b_j + 1 != ipiv) {
        for (C_5DOF_EL_B.iy = 0; C_5DOF_EL_B.iy < 8; C_5DOF_EL_B.iy++) {
          i = 5 * C_5DOF_EL_B.iy + C_5DOF_EL_B.b_j;
          C_5DOF_EL_B.smax = C_5DOF_EL_DW.H_pseudo[i];
          C_5DOF_EL_B.ijA = (5 * C_5DOF_EL_B.iy + ipiv) - 1;
          C_5DOF_EL_DW.H_pseudo[i] = C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.ijA];
          C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.ijA] = C_5DOF_EL_B.smax;
        }
      }
    }

    for (C_5DOF_EL_B.b_j = 0; C_5DOF_EL_B.b_j < 8; C_5DOF_EL_B.b_j++) {
      C_5DOF_EL_B.jj = 5 * C_5DOF_EL_B.b_j;
      for (C_5DOF_EL_B.iy = 0; C_5DOF_EL_B.iy < 5; C_5DOF_EL_B.iy++) {
        C_5DOF_EL_B.b_ix = 5 * C_5DOF_EL_B.iy;
        i = C_5DOF_EL_B.iy + C_5DOF_EL_B.jj;
        if (C_5DOF_EL_DW.H_pseudo[i] != 0.0) {
          for (C_5DOF_EL_B.ix = C_5DOF_EL_B.iy + 2; C_5DOF_EL_B.ix < 6;
               C_5DOF_EL_B.ix++) {
            C_5DOF_EL_B.ijA = (C_5DOF_EL_B.ix + C_5DOF_EL_B.jj) - 1;
            C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.ijA] -= C_5DOF_EL_B.A
              [(C_5DOF_EL_B.ix + C_5DOF_EL_B.b_ix) - 1] *
              C_5DOF_EL_DW.H_pseudo[i];
          }
        }
      }
    }

    for (C_5DOF_EL_B.b_j = 0; C_5DOF_EL_B.b_j < 8; C_5DOF_EL_B.b_j++) {
      C_5DOF_EL_B.jj = 5 * C_5DOF_EL_B.b_j;
      for (C_5DOF_EL_B.iy = 4; C_5DOF_EL_B.iy >= 0; C_5DOF_EL_B.iy--) {
        C_5DOF_EL_B.b_ix = 5 * C_5DOF_EL_B.iy;
        i = C_5DOF_EL_B.iy + C_5DOF_EL_B.jj;
        if (C_5DOF_EL_DW.H_pseudo[i] != 0.0) {
          C_5DOF_EL_DW.H_pseudo[i] /= C_5DOF_EL_B.A[C_5DOF_EL_B.iy +
            C_5DOF_EL_B.b_ix];
          for (C_5DOF_EL_B.ix = 0; C_5DOF_EL_B.ix < C_5DOF_EL_B.iy;
               C_5DOF_EL_B.ix++) {
            C_5DOF_EL_B.ijA = C_5DOF_EL_B.ix + C_5DOF_EL_B.jj;
            C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.ijA] -=
              C_5DOF_EL_B.A[C_5DOF_EL_B.ix + C_5DOF_EL_B.b_ix] *
              C_5DOF_EL_DW.H_pseudo[i];
          }
        }
      }
    }

    C_5DOF_EL_DW.H_pseudo_not_empty = true;
  }

  C_5DOF_EL_B.b[0] = C_5DOF_EL_U.SensoresPos.AG_Z1 - 0.099740000000000009;
  C_5DOF_EL_B.b[1] = C_5DOF_EL_U.SensoresPos.AG_Z2 - 0.099740000000000009;
  C_5DOF_EL_B.b[2] = C_5DOF_EL_U.SensoresPos.AG_Z3 - 0.099740000000000009;
  C_5DOF_EL_B.b[3] = C_5DOF_EL_U.SensoresPos.AG_Z4 - 0.099740000000000009;
  C_5DOF_EL_B.b[4] = (C_5DOF_EL_U.SensoresPos.AG_Y5 - 0.277) + 0.1347;
  C_5DOF_EL_B.b[5] = (-C_5DOF_EL_U.SensoresPos.AG_Y6 + 0.277) - 0.1347;
  C_5DOF_EL_B.b[6] = (C_5DOF_EL_U.SensoresPos.AG_Y7 - 0.277) + 0.1347;
  C_5DOF_EL_B.b[7] = (-C_5DOF_EL_U.SensoresPos.AG_Y8 + 0.277) - 0.1347;
  for (i = 0; i < 5; i++) {
    C_5DOF_EL_B.u[i] = 0.0;
  }

  i = 0;
  for (C_5DOF_EL_B.b_j = 0; C_5DOF_EL_B.b_j < 8; C_5DOF_EL_B.b_j++) {
    C_5DOF_EL_B.smax = C_5DOF_EL_B.b[C_5DOF_EL_B.b_j];
    for (C_5DOF_EL_B.jj = 0; C_5DOF_EL_B.jj < 5; C_5DOF_EL_B.jj++) {
      C_5DOF_EL_B.u[C_5DOF_EL_B.jj] += C_5DOF_EL_DW.H_pseudo[C_5DOF_EL_B.jj + i]
        * C_5DOF_EL_B.smax;
    }

    i += 5;
  }

  // End of MATLAB Function: '<Root>/GapToStates'

  // MATLAB Function: '<S1>/MATLAB Function1'
  C_5DOF_EL_B.smax = std::sin(C_5DOF_EL_B.u[2]);
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm = 0.191 * C_5DOF_EL_B.smax;
  C_5DOF_EL_B.s = 0.6475 * std::sin(C_5DOF_EL_B.u[3]);
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0__c = C_5DOF_EL_B.u[1] -
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm;
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm += C_5DOF_EL_B.u[1];
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4_tm = 0.268 - 0.261 * std::cos
    (C_5DOF_EL_B.u[4]);
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__c = 0.788 * std::sin(C_5DOF_EL_B.u[4]);
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b = 0.20255 * C_5DOF_EL_B.smax;
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__p =
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4_tm + C_5DOF_EL_B.u[0];
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm =
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4_tm - C_5DOF_EL_B.u[0];

  // RateTransition generated from: '<S4>/Mezclador' incorporates:
  //   RateTransition generated from: '<S4>/Y'
  //   RateTransition generated from: '<S6>/Sum3_Z'

  tmp = ((&C_5DOF_EL_M)->Timing.RateInteraction.TID0_1 == 1);
  if (tmp) {
    // RateTransition generated from: '<S4>/Mezclador'
    for (i = 0; i < 6; i++) {
      C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[i] =
        C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[i];
    }

    // End of RateTransition generated from: '<S4>/Mezclador'
  }

  // End of RateTransition generated from: '<S4>/Mezclador'

  // Gain: '<S4>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_EMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.smax = std::abs((C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__p +
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__c) -
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b) * 1000.0;

  // Saturate: '<S4>/Sat_I' incorporates:
  //   Gain: '<S4>/AG_mm'
  //   Lookup_n-D: '<S4>/InvLUT_1'

  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[0] = look2_binlcpw(C_5DOF_EL_B.smax,
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[0], C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
    C_5DOF_EL_ConstP.pooled31, 13U);

  // Gain: '<S4>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_EMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4_tm = std::abs
    ((C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm -
      C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__c) +
     C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b) * 1000.0;

  // Saturate: '<S4>/Sat_I' incorporates:
  //   Gain: '<S4>/AG_mm'
  //   Lookup_n-D: '<S4>/InvLUT_2'

  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[1] = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4_tm,
     C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[1], C_5DOF_EL_ConstP.pooled11,
     C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
     C_5DOF_EL_ConstP.pooled31, 13U);

  // Gain: '<S4>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_EMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.d = std::abs(C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__p -
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b) * 1000.0;

  // Saturate: '<S4>/Sat_I' incorporates:
  //   Gain: '<S4>/AG_mm'
  //   Lookup_n-D: '<S4>/InvLUT_3'

  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[2] = look2_binlcpw(C_5DOF_EL_B.d,
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[2], C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
    C_5DOF_EL_ConstP.pooled31, 13U);

  // Gain: '<S4>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_EMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.d1 = std::abs(C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm +
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b) * 1000.0;

  // Saturate: '<S4>/Sat_I' incorporates:
  //   Gain: '<S4>/AG_mm'
  //   Lookup_n-D: '<S4>/InvLUT_4'

  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[3] = look2_binlcpw(C_5DOF_EL_B.d1,
    C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[3], C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
    C_5DOF_EL_ConstP.pooled31, 13U);

  // Gain: '<S4>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_EMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__p = std::abs
    ((C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__p -
      C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__c) -
     C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b) * 1000.0;

  // Saturate: '<S4>/Sat_I' incorporates:
  //   Gain: '<S4>/AG_mm'
  //   Lookup_n-D: '<S4>/InvLUT_5'

  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[4] = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__p,
     C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[4], C_5DOF_EL_ConstP.pooled11,
     C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
     C_5DOF_EL_ConstP.pooled31, 13U);

  // Gain: '<S4>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_EMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__c = std::abs
    ((C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm +
      C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__c) +
     C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b) * 1000.0;

  // Saturate: '<S4>/Sat_I' incorporates:
  //   Gain: '<S4>/AG_mm'
  //   Lookup_n-D: '<S4>/InvLUT_6'

  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[5] = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__c,
     C_5DOF_EL_B.TmpRTBAtMezcladorOutport1[5], C_5DOF_EL_ConstP.pooled11,
     C_5DOF_EL_ConstP.pooled12, C_5DOF_EL_ConstP.pooled10,
     C_5DOF_EL_ConstP.pooled31, 13U);
  for (i = 0; i < 6; i++) {
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b =
      C_5DOF_EL_B.TmpSignalConversionAtKin_EM[i];
    if (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b > 50.0) {
      C_5DOF_EL_B.AG_mm[i] = 50.0;
    } else if (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b < 0.0) {
      C_5DOF_EL_B.AG_mm[i] = 0.0;
    } else {
      C_5DOF_EL_B.AG_mm[i] = C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b;
    }
  }

  // RateTransition generated from: '<S6>/Sum3_Z' incorporates:
  //   RateTransition generated from: '<S6>/b0_Roll'

  if (tmp) {
    // RateTransition generated from: '<S6>/Sum3_Z'
    C_5DOF_EL_B.TmpRTBAtSum3_ZInport2 =
      C_5DOF_EL_DW.TmpRTBAtSum3_ZInport2_Buffer0;

    // RateTransition generated from: '<S6>/Sum2_Z'
    C_5DOF_EL_B.TmpRTBAtSum2_ZInport2 =
      C_5DOF_EL_DW.TmpRTBAtSum2_ZInport2_Buffer0;

    // RateTransition generated from: '<S6>/SumErr_Z'
    C_5DOF_EL_B.TmpRTBAtSumErr_ZInport2 =
      C_5DOF_EL_DW.TmpRTBAtSumErr_ZInport2_Buffer0;

    // RateTransition generated from: '<S6>/b0_Roll'
    C_5DOF_EL_B.TmpRTBAtb0_RollOutport1 =
      C_5DOF_EL_DW.TmpRTBAtb0_RollOutport1_Buffer0;

    // RateTransition generated from: '<S6>/b0_Pitch'
    C_5DOF_EL_B.TmpRTBAtb0_PitchOutport1 =
      C_5DOF_EL_DW.TmpRTBAtb0_PitchOutport1_Buffer;
  }

  // MATLAB Function: '<S6>/Mezclador' incorporates:
  //   Gain: '<S6>/Kp_Z'
  //   Gain: '<S6>/b0_Z'
  //   Inport: '<Root>/RefZ'
  //   Sum: '<S6>/Sum2_Z'
  //   Sum: '<S6>/Sum3_Z'
  //   Sum: '<S6>/SumErr_Z'

  C_5DOF_EL_B.unnamed_idx_0_tmp = (((C_5DOF_EL_U.RefZ -
    C_5DOF_EL_B.TmpRTBAtSumErr_ZInport2) * 900.0 -
    C_5DOF_EL_B.TmpRTBAtSum2_ZInport2) - C_5DOF_EL_B.TmpRTBAtSum3_ZInport2) *
    250.0 * -0.25;

  // Gain: '<S6>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_HEMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b = std::abs
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0__c - C_5DOF_EL_B.s) * 1000.0;

  // Lookup_n-D: '<S6>/InvLUT_1' incorporates:
  //   Gain: '<S6>/AG_mm'
  //   MATLAB Function: '<S6>/Mezclador'
  //   SignalConversion generated from: '<S559>/ SFunction '

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b, (1.3089005235602094 *
      C_5DOF_EL_B.TmpRTBAtb0_RollOutport1 + C_5DOF_EL_B.unnamed_idx_0_tmp) +
     0.36764705882352938 * C_5DOF_EL_B.TmpRTBAtb0_PitchOutport1,
     C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled17,
     C_5DOF_EL_ConstP.pooled15, C_5DOF_EL_ConstP.pooled32, 14U);

  // Gain: '<S6>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_HEMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.unnamed_idx_1_tmp = std::abs
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm - C_5DOF_EL_B.s) * 1000.0;

  // Lookup_n-D: '<S6>/InvLUT_2' incorporates:
  //   Gain: '<S6>/AG_mm'
  //   MATLAB Function: '<S6>/Mezclador'
  //   SignalConversion generated from: '<S559>/ SFunction '

  C_5DOF_EL_B.unnamed_idx_1 = look2_binlcpw(C_5DOF_EL_B.unnamed_idx_1_tmp,
    (C_5DOF_EL_B.unnamed_idx_0_tmp - 1.3089005235602094 *
     C_5DOF_EL_B.TmpRTBAtb0_RollOutport1) + 0.36764705882352938 *
    C_5DOF_EL_B.TmpRTBAtb0_PitchOutport1, C_5DOF_EL_ConstP.pooled16,
    C_5DOF_EL_ConstP.pooled17, C_5DOF_EL_ConstP.pooled15,
    C_5DOF_EL_ConstP.pooled32, 14U);

  // Gain: '<S6>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_HEMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0__c = std::abs
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0__c + C_5DOF_EL_B.s) * 1000.0;

  // Lookup_n-D: '<S6>/InvLUT_3' incorporates:
  //   Gain: '<S6>/AG_mm'
  //   MATLAB Function: '<S6>/Mezclador'
  //   SignalConversion generated from: '<S559>/ SFunction '

  C_5DOF_EL_B.unnamed_idx_2 = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0__c, (1.3089005235602094 *
      C_5DOF_EL_B.TmpRTBAtb0_RollOutport1 + C_5DOF_EL_B.unnamed_idx_0_tmp) -
     0.36764705882352938 * C_5DOF_EL_B.TmpRTBAtb0_PitchOutport1,
     C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled17,
     C_5DOF_EL_ConstP.pooled15, C_5DOF_EL_ConstP.pooled32, 14U);

  // Gain: '<S6>/AG_mm' incorporates:
  //   Gain: '<S5>/AG_HEMS_mm'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  C_5DOF_EL_B.s = std::abs(C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm +
    C_5DOF_EL_B.s) * 1000.0;

  // Lookup_n-D: '<S6>/InvLUT_4' incorporates:
  //   Gain: '<S6>/AG_mm'
  //   MATLAB Function: '<S6>/Mezclador'
  //   SignalConversion generated from: '<S559>/ SFunction '

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm = look2_binlcpw(C_5DOF_EL_B.s,
    (C_5DOF_EL_B.unnamed_idx_0_tmp - 1.3089005235602094 *
     C_5DOF_EL_B.TmpRTBAtb0_RollOutport1) - 0.36764705882352938 *
    C_5DOF_EL_B.TmpRTBAtb0_PitchOutport1, C_5DOF_EL_ConstP.pooled16,
    C_5DOF_EL_ConstP.pooled17, C_5DOF_EL_ConstP.pooled15,
    C_5DOF_EL_ConstP.pooled32, 14U);

  // Saturate: '<S6>/Sat_I' incorporates:
  //   Lookup_n-D: '<S6>/InvLUT_1'
  //   Lookup_n-D: '<S6>/InvLUT_2'
  //   Lookup_n-D: '<S6>/InvLUT_3'
  //   Lookup_n-D: '<S6>/InvLUT_4'

  if (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm > 50.0) {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[0] = 50.0;
  } else if (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm < -50.0) {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[0] = -50.0;
  } else {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[0] =
      C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm;
  }

  if (C_5DOF_EL_B.unnamed_idx_1 > 50.0) {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[1] = 50.0;
  } else if (C_5DOF_EL_B.unnamed_idx_1 < -50.0) {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[1] = -50.0;
  } else {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[1] = C_5DOF_EL_B.unnamed_idx_1;
  }

  if (C_5DOF_EL_B.unnamed_idx_2 > 50.0) {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[2] = 50.0;
  } else if (C_5DOF_EL_B.unnamed_idx_2 < -50.0) {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[2] = -50.0;
  } else {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[2] = C_5DOF_EL_B.unnamed_idx_2;
  }

  if (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm > 50.0) {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[3] = 50.0;
  } else if (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm < -50.0) {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[3] = -50.0;
  } else {
    C_5DOF_EL_B.TmpSignalConversionAtKin_HE[3] =
      C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm;
  }

  // End of Saturate: '<S6>/Sat_I'

  // Outputs for Atomic SubSystem: '<S1>/ControlDeCorriente'
  // Inport: '<Root>/I_HEMS' incorporates:
  //   Inport: '<Root>/I_EMS'

  C_5DOF_E_ControlDeCorriente(C_5DOF_EL_B.TmpSignalConversionAtKin_HE,
    &C_5DOF_EL_U.I_HEMS, &C_5DOF_EL_U.I_EMS, C_5DOF_EL_B.AG_mm,
    &C_5DOF_EL_B.ControlDeCorriente, &C_5DOF_EL_DW.ControlDeCorriente);

  // End of Outputs for SubSystem: '<S1>/ControlDeCorriente'

  // SignalConversion generated from: '<S5>/Kin_EMS' incorporates:
  //   Inport: '<Root>/I_EMS'
  //   Lookup_n-D: '<S5>/LUT_EMS_1'
  //   Lookup_n-D: '<S5>/LUT_EMS_2'
  //   Lookup_n-D: '<S5>/LUT_EMS_3'
  //   Lookup_n-D: '<S5>/LUT_EMS_4'
  //   Lookup_n-D: '<S5>/LUT_EMS_5'
  //   Lookup_n-D: '<S5>/LUT_EMS_6'

  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[0] = look2_binlcpw(C_5DOF_EL_B.smax,
    C_5DOF_EL_U.I_EMS.I_EMS5, C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled19, C_5DOF_EL_ConstP.pooled18,
    C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[1] = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4_tm, C_5DOF_EL_U.I_EMS.I_EMS6,
     C_5DOF_EL_ConstP.pooled11, C_5DOF_EL_ConstP.pooled19,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[2] = look2_binlcpw(C_5DOF_EL_B.d,
    C_5DOF_EL_U.I_EMS.I_EMS7, C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled19, C_5DOF_EL_ConstP.pooled18,
    C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[3] = look2_binlcpw(C_5DOF_EL_B.d1,
    C_5DOF_EL_U.I_EMS.I_EMS8, C_5DOF_EL_ConstP.pooled11,
    C_5DOF_EL_ConstP.pooled19, C_5DOF_EL_ConstP.pooled18,
    C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[4] = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__p, C_5DOF_EL_U.I_EMS.I_EMS9,
     C_5DOF_EL_ConstP.pooled11, C_5DOF_EL_ConstP.pooled19,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled33, 13U);
  C_5DOF_EL_B.TmpSignalConversionAtKin_EM[5] = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__c, C_5DOF_EL_U.I_EMS.I_EMS10,
     C_5DOF_EL_ConstP.pooled11, C_5DOF_EL_ConstP.pooled19,
     C_5DOF_EL_ConstP.pooled18, C_5DOF_EL_ConstP.pooled33, 13U);

  // RateTransition generated from: '<S4>/Y' incorporates:
  //   UnitDelay: '<S1>/UnitDelay'

  if (tmp) {
    C_5DOF_EL_DW.TmpRTBAtYInport1_Buffer[0] = C_5DOF_EL_B.u[0];
    C_5DOF_EL_DW.TmpRTBAtYInport1_Buffer[1] = C_5DOF_EL_DW.UnitDelay_DSTATE[3];

    // RateTransition generated from: '<S4>/Yaw' incorporates:
    //   UnitDelay: '<S1>/UnitDelay'

    C_5DOF_EL_DW.TmpRTBAtYawInport1_Buffer[0] = C_5DOF_EL_B.u[4];
    C_5DOF_EL_DW.TmpRTBAtYawInport1_Buffer[1] = C_5DOF_EL_DW.UnitDelay_DSTATE[4];

    // RateTransition generated from: '<S6>/Pitch' incorporates:
    //   UnitDelay: '<S1>/UnitDelay'

    C_5DOF_EL_DW.TmpRTBAtPitchInport1_Buffer[0] = C_5DOF_EL_B.u[3];
    C_5DOF_EL_DW.TmpRTBAtPitchInport1_Buffer[1] = C_5DOF_EL_DW.UnitDelay_DSTATE
      [2];

    // RateTransition generated from: '<S6>/Roll' incorporates:
    //   UnitDelay: '<S1>/UnitDelay'

    C_5DOF_EL_DW.TmpRTBAtRollInport1_Buffer[0] = C_5DOF_EL_B.u[2];
    C_5DOF_EL_DW.TmpRTBAtRollInport1_Buffer[1] = C_5DOF_EL_DW.UnitDelay_DSTATE[1];

    // RateTransition generated from: '<S6>/Z' incorporates:
    //   UnitDelay: '<S1>/UnitDelay'

    C_5DOF_EL_DW.TmpRTBAtZInport1_Buffer[0] = C_5DOF_EL_B.u[1];
    C_5DOF_EL_DW.TmpRTBAtZInport1_Buffer[1] = C_5DOF_EL_DW.UnitDelay_DSTATE[0];
  }

  // BusCreator: '<S1>/Bus Creator4' incorporates:
  //   Outport: '<Root>/V'

  C_5DOF_EL_Y.V_h.V_HEMS1 = C_5DOF_EL_B.ControlDeCorriente.Saturation;
  C_5DOF_EL_Y.V_h.V_HEMS2 = C_5DOF_EL_B.ControlDeCorriente.Saturation_h;
  C_5DOF_EL_Y.V_h.V_HEMS3 = C_5DOF_EL_B.ControlDeCorriente.Saturation_f;
  C_5DOF_EL_Y.V_h.V_HEMS4 = C_5DOF_EL_B.ControlDeCorriente.Saturation_d;
  C_5DOF_EL_Y.V_h.V_EMS5 = C_5DOF_EL_B.ControlDeCorriente.Saturation_k;
  C_5DOF_EL_Y.V_h.V_EMS6 = C_5DOF_EL_B.ControlDeCorriente.Saturation_dd;
  C_5DOF_EL_Y.V_h.V_EMS7 = C_5DOF_EL_B.ControlDeCorriente.Saturation_o;
  C_5DOF_EL_Y.V_h.V_EMS8 = C_5DOF_EL_B.ControlDeCorriente.Saturation_p;
  C_5DOF_EL_Y.V_h.V_EMS9 = C_5DOF_EL_B.ControlDeCorriente.Saturation_oe;
  C_5DOF_EL_Y.V_h.V_EMS10 = C_5DOF_EL_B.ControlDeCorriente.Saturation_j;

  // Lookup_n-D: '<S5>/LUT_HEMS_1' incorporates:
  //   Inport: '<Root>/I_HEMS'

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_4__b, C_5DOF_EL_U.I_HEMS.I_HEMS1,
     C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled21,
     C_5DOF_EL_ConstP.pooled20, C_5DOF_EL_ConstP.pooled34, 14U);

  // Lookup_n-D: '<S5>/LUT_HEMS_2' incorporates:
  //   Inport: '<Root>/I_HEMS'

  C_5DOF_EL_B.unnamed_idx_1 = look2_binlcpw(C_5DOF_EL_B.unnamed_idx_1_tmp,
    C_5DOF_EL_U.I_HEMS.I_HEMS2, C_5DOF_EL_ConstP.pooled16,
    C_5DOF_EL_ConstP.pooled21, C_5DOF_EL_ConstP.pooled20,
    C_5DOF_EL_ConstP.pooled34, 14U);

  // Lookup_n-D: '<S5>/LUT_HEMS_3' incorporates:
  //   Inport: '<Root>/I_HEMS'

  C_5DOF_EL_B.unnamed_idx_2 = look2_binlcpw
    (C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0__c, C_5DOF_EL_U.I_HEMS.I_HEMS3,
     C_5DOF_EL_ConstP.pooled16, C_5DOF_EL_ConstP.pooled21,
     C_5DOF_EL_ConstP.pooled20, C_5DOF_EL_ConstP.pooled34, 14U);

  // Lookup_n-D: '<S5>/LUT_HEMS_4' incorporates:
  //   Inport: '<Root>/I_HEMS'

  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm = look2_binlcpw(C_5DOF_EL_B.s,
    C_5DOF_EL_U.I_HEMS.I_HEMS4, C_5DOF_EL_ConstP.pooled16,
    C_5DOF_EL_ConstP.pooled21, C_5DOF_EL_ConstP.pooled20,
    C_5DOF_EL_ConstP.pooled34, 14U);

  // Sum: '<S5>/Sum_HEMS' incorporates:
  //   Gain: '<S5>/Kin_HEMS'
  //   Lookup_n-D: '<S5>/LUT_HEMS_1'
  //   Lookup_n-D: '<S5>/LUT_HEMS_2'
  //   Lookup_n-D: '<S5>/LUT_HEMS_3'
  //   Lookup_n-D: '<S5>/LUT_HEMS_4'

  for (i = 0; i < 3; i++) {
    C_5DOF_EL_B.dv[i] = ((C_5DOF_EL_ConstP.Kin_HEMS_Gain[i + 3] *
                          C_5DOF_EL_B.unnamed_idx_1 +
                          C_5DOF_EL_ConstP.Kin_HEMS_Gain[i] *
                          C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm) +
                         C_5DOF_EL_ConstP.Kin_HEMS_Gain[i + 6] *
                         C_5DOF_EL_B.unnamed_idx_2) +
      C_5DOF_EL_ConstP.Kin_HEMS_Gain[i + 9] *
      C_5DOF_EL_B.rtb_airgaps_actuadores_idx_0_tm;
  }

  // End of Sum: '<S5>/Sum_HEMS'

  // Gain: '<S5>/Kin_EMS'
  C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm = 0.0;
  C_5DOF_EL_B.unnamed_idx_1 = 0.0;
  i = 0;
  for (C_5DOF_EL_B.b_j = 0; C_5DOF_EL_B.b_j < 6; C_5DOF_EL_B.b_j++) {
    C_5DOF_EL_B.smax = C_5DOF_EL_B.TmpSignalConversionAtKin_EM[C_5DOF_EL_B.b_j];
    C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm +=
      C_5DOF_EL_ConstP.Kin_EMS_Gain[i] * C_5DOF_EL_B.smax;
    C_5DOF_EL_B.unnamed_idx_1 += C_5DOF_EL_ConstP.Kin_EMS_Gain[i + 1] *
      C_5DOF_EL_B.smax;
    i += 2;
  }

  // End of Gain: '<S5>/Kin_EMS'

  // Update for UnitDelay: '<S1>/UnitDelay'
  C_5DOF_EL_DW.UnitDelay_DSTATE[0] = C_5DOF_EL_B.dv[0];
  C_5DOF_EL_DW.UnitDelay_DSTATE[1] = C_5DOF_EL_B.dv[1];
  C_5DOF_EL_DW.UnitDelay_DSTATE[2] = C_5DOF_EL_B.dv[2];
  C_5DOF_EL_DW.UnitDelay_DSTATE[3] = C_5DOF_EL_B.rtb_airgaps_actuadores_idx_5_tm;
  C_5DOF_EL_DW.UnitDelay_DSTATE[4] = C_5DOF_EL_B.unnamed_idx_1;
}

// Model step function for TID1
void C_5DOF_EL::step1()                // Sample time: [0.001s, 0.0s]
{
  // local block i/o variables
  real_T rtb_TmpRTBAtZInport1[2];
  real_T rtb_F_des_n_tmp;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_TmpSignalConversionAtSFun_1;
  real_T rtb_b0_Y;
  int32_T i;

  // DiscreteStateSpace: '<S4>/Y'
  {
    C_5DOF_EL_B.Roll[0] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[0];
    C_5DOF_EL_B.Roll[1] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[1];
    C_5DOF_EL_B.Roll[2] = (1.0)*C_5DOF_EL_DW.Y_DSTATE[2];
  }

  // Gain: '<S4>/b0_Y' incorporates:
  //   Constant: '<S4>/Ref_Y'
  //   Gain: '<S4>/Kd_Y'
  //   Gain: '<S4>/Kp_Y'
  //   Sum: '<S4>/Sum2_Y'
  //   Sum: '<S4>/Sum3_Y'
  //   Sum: '<S4>/SumErr_Y'

  rtb_b0_Y = (((0.0 - C_5DOF_EL_B.Roll[0]) * 400.0 - 80.0 * C_5DOF_EL_B.Roll[1])
              - C_5DOF_EL_B.Roll[2]) * 250.0;

  // DiscreteStateSpace: '<S4>/Yaw'
  {
    C_5DOF_EL_B.Roll[0] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[0];
    C_5DOF_EL_B.Roll[1] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[1];
    C_5DOF_EL_B.Roll[2] = (1.0)*C_5DOF_EL_DW.Yaw_DSTATE[2];
  }

  // SignalConversion generated from: '<S558>/ SFunction ' incorporates:
  //   Constant: '<S4>/Ref_Yaw'
  //   Gain: '<S4>/Fy_x2'
  //   Gain: '<S4>/Kd_Yaw'
  //   Gain: '<S4>/Kp_Yaw'
  //   Gain: '<S4>/Mz_x2'
  //   Gain: '<S4>/b0_Yaw'
  //   MATLAB Function: '<S4>/Mezclador'
  //   Sum: '<S4>/Sum2_Yaw'
  //   Sum: '<S4>/Sum3_Yaw'
  //   Sum: '<S4>/SumErr_Yaw'

  rtb_TmpSignalConversionAtSFun_0 = 2.0 * rtb_b0_Y;
  rtb_TmpSignalConversionAtSFun_1 = (((0.0 - C_5DOF_EL_B.Roll[0]) * 400.0 - 80.0
    * C_5DOF_EL_B.Roll[1]) - C_5DOF_EL_B.Roll[2]) * 29.297 * 2.0;

  // MATLAB Function: '<S4>/Mezclador'
  rtb_b0_Y = -0.16666666666666666 * rtb_TmpSignalConversionAtSFun_0;
  rtb_F_des_n_tmp = -0.30266343825665859 * rtb_TmpSignalConversionAtSFun_1;
  C_5DOF_EL_B.F_des_n[0] = rtb_b0_Y + rtb_F_des_n_tmp;
  rtb_TmpSignalConversionAtSFun_0 *= 0.16666666666666666;
  rtb_TmpSignalConversionAtSFun_1 *= 0.30266343825665859;
  C_5DOF_EL_B.F_des_n[1] = rtb_TmpSignalConversionAtSFun_0 +
    rtb_TmpSignalConversionAtSFun_1;
  C_5DOF_EL_B.F_des_n[2] = rtb_b0_Y;
  C_5DOF_EL_B.F_des_n[3] = rtb_TmpSignalConversionAtSFun_0;
  C_5DOF_EL_B.F_des_n[4] = rtb_b0_Y + rtb_TmpSignalConversionAtSFun_1;
  C_5DOF_EL_B.F_des_n[5] = rtb_TmpSignalConversionAtSFun_0 + rtb_F_des_n_tmp;

  // RateTransition generated from: '<S4>/Mezclador'
  for (i = 0; i < 6; i++) {
    C_5DOF_EL_DW.TmpRTBAtMezcladorOutport1_Buffe[i] = C_5DOF_EL_B.F_des_n[i];
  }

  // End of RateTransition generated from: '<S4>/Mezclador'

  // DiscreteStateSpace: '<S6>/Pitch'
  {
    C_5DOF_EL_B.Roll[0] = (1.0)*C_5DOF_EL_DW.Pitch_DSTATE[0];
    C_5DOF_EL_B.Roll[1] = (1.0)*C_5DOF_EL_DW.Pitch_DSTATE[1];
    C_5DOF_EL_B.Roll[2] = (1.0)*C_5DOF_EL_DW.Pitch_DSTATE[2];
  }

  // RateTransition generated from: '<S6>/b0_Pitch' incorporates:
  //   Constant: '<S6>/Ref_Pitch'
  //   Gain: '<S6>/Kd_Pitch'
  //   Gain: '<S6>/Kp_Pitch'
  //   Gain: '<S6>/b0_Pitch'
  //   Sum: '<S6>/Sum2_Pitch'
  //   Sum: '<S6>/Sum3_Pitch'
  //   Sum: '<S6>/SumErr_Pitch'

  C_5DOF_EL_DW.TmpRTBAtb0_PitchOutport1_Buffer = (((0.0 - C_5DOF_EL_B.Roll[0]) *
    1225.0 - 70.0 * C_5DOF_EL_B.Roll[1]) - C_5DOF_EL_B.Roll[2]) * 26.887;

  // DiscreteStateSpace: '<S6>/Roll'
  {
    C_5DOF_EL_B.Roll[0] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE[0];
    C_5DOF_EL_B.Roll[1] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE[1];
    C_5DOF_EL_B.Roll[2] = (1.0)*C_5DOF_EL_DW.Roll_DSTATE[2];
  }

  // RateTransition generated from: '<S6>/b0_Roll' incorporates:
  //   Constant: '<S6>/Ref_Roll'
  //   Gain: '<S6>/Kd_Roll'
  //   Gain: '<S6>/Kp_Roll'
  //   Gain: '<S6>/b0_Roll'
  //   Sum: '<S6>/Sum2_Roll'
  //   Sum: '<S6>/Sum3_Roll'
  //   Sum: '<S6>/SumErr_Roll'

  C_5DOF_EL_DW.TmpRTBAtb0_RollOutport1_Buffer0 = (((0.0 - C_5DOF_EL_B.Roll[0]) *
    1225.0 - 70.0 * C_5DOF_EL_B.Roll[1]) - C_5DOF_EL_B.Roll[2]) * 43.082;

  // DiscreteStateSpace: '<S6>/Z'
  {
    C_5DOF_EL_B.Z[0] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[0];
    C_5DOF_EL_B.Z[1] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[1];
    C_5DOF_EL_B.Z[2] = (1.0)*C_5DOF_EL_DW.Z_DSTATE[2];
  }

  // RateTransition generated from: '<S6>/Sum3_Z'
  C_5DOF_EL_DW.TmpRTBAtSum3_ZInport2_Buffer0 = C_5DOF_EL_B.Z[2];

  // RateTransition generated from: '<S6>/SumErr_Z'
  C_5DOF_EL_DW.TmpRTBAtSumErr_ZInport2_Buffer0 = C_5DOF_EL_B.Z[0];

  // RateTransition generated from: '<S6>/Sum2_Z' incorporates:
  //   Gain: '<S6>/Kd_Z'

  C_5DOF_EL_DW.TmpRTBAtSum2_ZInport2_Buffer0 = 60.0 * C_5DOF_EL_B.Z[1];

  // RateTransition generated from: '<S4>/Y'
  C_5DOF_EL_B.TmpRTBAtYInport1[0] = C_5DOF_EL_DW.TmpRTBAtYInport1_Buffer[0];

  // RateTransition generated from: '<S4>/Yaw'
  C_5DOF_EL_B.TmpRTBAtYawInport1[0] = C_5DOF_EL_DW.TmpRTBAtYawInport1_Buffer[0];

  // RateTransition generated from: '<S6>/Pitch'
  C_5DOF_EL_B.TmpRTBAtPitchInport1[0] =
    C_5DOF_EL_DW.TmpRTBAtPitchInport1_Buffer[0];

  // RateTransition generated from: '<S6>/Roll'
  C_5DOF_EL_B.TmpRTBAtRollInport1[0] = C_5DOF_EL_DW.TmpRTBAtRollInport1_Buffer[0];

  // RateTransition generated from: '<S6>/Z'
  rtb_TmpRTBAtZInport1[0] = C_5DOF_EL_DW.TmpRTBAtZInport1_Buffer[0];

  // RateTransition generated from: '<S4>/Y'
  C_5DOF_EL_B.TmpRTBAtYInport1[1] = C_5DOF_EL_DW.TmpRTBAtYInport1_Buffer[1];

  // RateTransition generated from: '<S4>/Yaw'
  C_5DOF_EL_B.TmpRTBAtYawInport1[1] = C_5DOF_EL_DW.TmpRTBAtYawInport1_Buffer[1];

  // RateTransition generated from: '<S6>/Pitch'
  C_5DOF_EL_B.TmpRTBAtPitchInport1[1] =
    C_5DOF_EL_DW.TmpRTBAtPitchInport1_Buffer[1];

  // RateTransition generated from: '<S6>/Roll'
  C_5DOF_EL_B.TmpRTBAtRollInport1[1] = C_5DOF_EL_DW.TmpRTBAtRollInport1_Buffer[1];

  // RateTransition generated from: '<S6>/Z'
  rtb_TmpRTBAtZInport1[1] = C_5DOF_EL_DW.TmpRTBAtZInport1_Buffer[1];

  // Update for DiscreteStateSpace: '<S4>/Y'
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
    (void) std::memcpy(&C_5DOF_EL_DW.Y_DSTATE[0], xnew,
                       sizeof(real_T)*3);
  }

  // Update for DiscreteStateSpace: '<S4>/Yaw'
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
    (void) std::memcpy(&C_5DOF_EL_DW.Yaw_DSTATE[0], xnew,
                       sizeof(real_T)*3);
  }

  // Update for DiscreteStateSpace: '<S6>/Pitch'
  {
    real_T xnew[3];
    xnew[0] = (0.75259320810981811)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (0.000876296604054912)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (4.3814830202746851E-7)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[0] += (0.24740679189018189)*C_5DOF_EL_B.TmpRTBAtPitchInport1[0]
      + (1.629591631745635E-8)*C_5DOF_EL_B.TmpRTBAtPitchInport1[1];
    xnew[1] = (-21.613417590712306)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (0.98919329120464383)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (0.000994596645602322)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[1] += (21.613417590712306)*C_5DOF_EL_B.TmpRTBAtPitchInport1[0]
      + (3.69917300406264E-5)*C_5DOF_EL_B.TmpRTBAtPitchInport1[1];
    xnew[2] = (-638.82022435602892)*C_5DOF_EL_DW.Pitch_DSTATE[0]
      + (-0.31941011217801363)*C_5DOF_EL_DW.Pitch_DSTATE[1]
      + (0.99984029494391125)*C_5DOF_EL_DW.Pitch_DSTATE[2];
    xnew[2] += (638.82022435602892)*C_5DOF_EL_B.TmpRTBAtPitchInport1[0]
      + (-5.9398614977128325E-6)*C_5DOF_EL_B.TmpRTBAtPitchInport1[1];
    (void) std::memcpy(&C_5DOF_EL_DW.Pitch_DSTATE[0], xnew,
                       sizeof(real_T)*3);
  }

  // Update for DiscreteStateSpace: '<S6>/Roll'
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
    (void) std::memcpy(&C_5DOF_EL_DW.Roll_DSTATE[0], xnew,
                       sizeof(real_T)*3);
  }

  // Update for DiscreteStateSpace: '<S6>/Z'
  {
    real_T xnew[3];
    xnew[0] = (0.75259320810981811)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (0.000876296604054912)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (4.3814830202746851E-7)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[0] += (0.24740679189018189)*rtb_TmpRTBAtZInport1[0] +
      (1.7525932081098171E-9)*rtb_TmpRTBAtZInport1[1];
    xnew[1] = (-21.613417590712306)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (0.98919329120464383)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (0.000994596645602322)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[1] += (21.613417590712306)*rtb_TmpRTBAtZInport1[0] +
      (3.9783865824092869E-6)*rtb_TmpRTBAtZInport1[1];
    xnew[2] = (-638.82022435602892)*C_5DOF_EL_DW.Z_DSTATE[0]
      + (-0.31941011217801363)*C_5DOF_EL_DW.Z_DSTATE[1]
      + (0.99984029494391125)*C_5DOF_EL_DW.Z_DSTATE[2];
    xnew[2] += (638.82022435602892)*rtb_TmpRTBAtZInport1[0] +
      (-6.388202243560248E-7)*rtb_TmpRTBAtZInport1[1];
    (void) std::memcpy(&C_5DOF_EL_DW.Z_DSTATE[0], xnew,
                       sizeof(real_T)*3);
  }
}

// Model initialize function
void C_5DOF_EL::initialize()
{
  // Registration code

  // Set task counter limit used by the static main program
  ((&C_5DOF_EL_M))->Timing.TaskCounters.cLimit[0] = 1;
  ((&C_5DOF_EL_M))->Timing.TaskCounters.cLimit[1] = 2;

  // InitializeConditions for DiscreteStateSpace: '<S4>/Y'
  C_5DOF_EL_DW.Y_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Y_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Y_DSTATE[2] = (0.0);

  // InitializeConditions for DiscreteStateSpace: '<S4>/Yaw'
  C_5DOF_EL_DW.Yaw_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Yaw_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Yaw_DSTATE[2] = (0.0);

  // InitializeConditions for DiscreteStateSpace: '<S6>/Pitch'
  C_5DOF_EL_DW.Pitch_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Pitch_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Pitch_DSTATE[2] = (0.0);

  // InitializeConditions for DiscreteStateSpace: '<S6>/Roll'
  C_5DOF_EL_DW.Roll_DSTATE[0] = (0.001);
  C_5DOF_EL_DW.Roll_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Roll_DSTATE[2] = (0.0);

  // InitializeConditions for DiscreteStateSpace: '<S6>/Z'
  C_5DOF_EL_DW.Z_DSTATE[0] = (0.0225);
  C_5DOF_EL_DW.Z_DSTATE[1] = (0.0);
  C_5DOF_EL_DW.Z_DSTATE[2] = (0.0);
}

// Model terminate function
void C_5DOF_EL::terminate()
{
  // (no terminate code required)
}

boolean_T C_5DOF_EL::RT_MODEL_C_5DOF_EL_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

uint8_T &C_5DOF_EL::RT_MODEL_C_5DOF_EL_T::CounterLimit(int32_T idx)
{
  return (Timing.TaskCounters.cLimit[(idx)]);
}

const char_T* C_5DOF_EL::RT_MODEL_C_5DOF_EL_T::getErrorStatus() const
{
  return (errorStatus);
}

void C_5DOF_EL::RT_MODEL_C_5DOF_EL_T::setErrorStatus(const char_T* const
  volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

uint8_T &C_5DOF_EL::RT_MODEL_C_5DOF_EL_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

// Constructor
C_5DOF_EL::C_5DOF_EL() :
  C_5DOF_EL_U(),
  C_5DOF_EL_Y(),
  C_5DOF_EL_B(),
  C_5DOF_EL_DW(),
  C_5DOF_EL_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
C_5DOF_EL::~C_5DOF_EL() = default;

// Real-Time Model get method
C_5DOF_EL::RT_MODEL_C_5DOF_EL_T * C_5DOF_EL::getRTM()
{
  return (&C_5DOF_EL_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
