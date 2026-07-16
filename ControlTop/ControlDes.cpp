#include "ControlDes.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "rt_hypotd.h"
#include "look2_binlcpw.h"
#include "ControlDes_private.h"

real_T ControlDes::ControlDes_xnrm2_l2M7eLKH(int32_T n, const real_T x[12],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      int32_T kend;
      ControlDes_B.scale_g = 3.312168642111238E-170;
      kend = ix0 + n;
      for (int32_T k{ix0}; k < kend; k++) {
        ControlDes_B.absxk_l = std::abs(x[k - 1]);
        if (ControlDes_B.absxk_l > ControlDes_B.scale_g) {
          real_T t;
          t = ControlDes_B.scale_g / ControlDes_B.absxk_l;
          y = y * t * t + 1.0;
          ControlDes_B.scale_g = ControlDes_B.absxk_l;
        } else {
          real_T t;
          t = ControlDes_B.absxk_l / ControlDes_B.scale_g;
          y += t * t;
        }
      }

      y = ControlDes_B.scale_g * std::sqrt(y);
    }
  }

  return y;
}

void ControlDes::ControlDes_mldivide_l89k28gF(const real_T A[12], const real_T
  B[4], real_T Y[3])
{
  int32_T b_ix;
  int32_T e;
  int32_T exitg1;
  int32_T ia;
  int32_T ii;
  int32_T ii_tmp;
  int32_T ix;
  int32_T jy;
  int32_T pvt;
  int32_T rankA;
  int8_T jpvt[3];
  int8_T jpvt_0;
  boolean_T exitg2;
  std::memcpy(&ControlDes_B.b_A[0], &A[0], 12U * sizeof(real_T));
  ControlDes_B.b_B[0] = B[0];
  ControlDes_B.b_B[1] = B[1];
  ControlDes_B.b_B[2] = B[2];
  ControlDes_B.b_B[3] = B[3];
  for (rankA = 0; rankA < 3; rankA++) {
    jpvt[rankA] = static_cast<int8_T>(rankA + 1);
    ControlDes_B.work[rankA] = 0.0;
    ii = (rankA << 2) + 1;
    ControlDes_B.smax = 0.0;
    ControlDes_B.scale = 3.312168642111238E-170;
    for (pvt = ii; pvt <= ii + 3; pvt++) {
      ControlDes_B.absxk = std::abs(A[pvt - 1]);
      if (ControlDes_B.absxk > ControlDes_B.scale) {
        ControlDes_B.t = ControlDes_B.scale / ControlDes_B.absxk;
        ControlDes_B.smax = ControlDes_B.smax * ControlDes_B.t * ControlDes_B.t
          + 1.0;
        ControlDes_B.scale = ControlDes_B.absxk;
      } else {
        ControlDes_B.t = ControlDes_B.absxk / ControlDes_B.scale;
        ControlDes_B.smax += ControlDes_B.t * ControlDes_B.t;
      }
    }

    ControlDes_B.absxk = ControlDes_B.scale * std::sqrt(ControlDes_B.smax);
    ControlDes_B.vn1[rankA] = ControlDes_B.absxk;
    ControlDes_B.vn2[rankA] = ControlDes_B.absxk;
  }

  for (rankA = 0; rankA < 3; rankA++) {
    ii_tmp = rankA << 2;
    ii = ii_tmp + rankA;
    pvt = 4 - rankA;
    b_ix = 0;
    if (3 - rankA > 1) {
      ix = rankA;
      ControlDes_B.smax = std::abs(ControlDes_B.vn1[rankA]);
      for (jy = 2; jy < pvt; jy++) {
        ix++;
        ControlDes_B.scale = std::abs(ControlDes_B.vn1[ix]);
        if (ControlDes_B.scale > ControlDes_B.smax) {
          b_ix = jy - 1;
          ControlDes_B.smax = ControlDes_B.scale;
        }
      }
    }

    pvt = rankA + b_ix;
    if (pvt != rankA) {
      b_ix = pvt << 2;
      ControlDes_B.smax = ControlDes_B.b_A[b_ix];
      ControlDes_B.b_A[b_ix] = ControlDes_B.b_A[ii_tmp];
      ControlDes_B.b_A[ii_tmp] = ControlDes_B.smax;
      ControlDes_B.smax = ControlDes_B.b_A[b_ix + 1];
      ControlDes_B.b_A[b_ix + 1] = ControlDes_B.b_A[ii_tmp + 1];
      ControlDes_B.b_A[ii_tmp + 1] = ControlDes_B.smax;
      ControlDes_B.smax = ControlDes_B.b_A[b_ix + 2];
      ControlDes_B.b_A[b_ix + 2] = ControlDes_B.b_A[ii_tmp + 2];
      ControlDes_B.b_A[ii_tmp + 2] = ControlDes_B.smax;
      ControlDes_B.smax = ControlDes_B.b_A[b_ix + 3];
      ControlDes_B.b_A[b_ix + 3] = ControlDes_B.b_A[ii_tmp + 3];
      ControlDes_B.b_A[ii_tmp + 3] = ControlDes_B.smax;
      b_ix = jpvt[pvt];
      jpvt[pvt] = jpvt[rankA];
      jpvt[rankA] = static_cast<int8_T>(b_ix);
      ControlDes_B.vn1[pvt] = ControlDes_B.vn1[rankA];
      ControlDes_B.vn2[pvt] = ControlDes_B.vn2[rankA];
    }

    ControlDes_B.scale = ControlDes_B.b_A[ii];
    pvt = ii + 2;
    ControlDes_B.tau[rankA] = 0.0;
    ControlDes_B.smax = ControlDes_xnrm2_l2M7eLKH(3 - rankA, ControlDes_B.b_A,
      ii + 2);
    if (ControlDes_B.smax != 0.0) {
      ControlDes_B.smax = rt_hypotd(ControlDes_B.b_A[ii], ControlDes_B.smax);
      if (ControlDes_B.b_A[ii] >= 0.0) {
        ControlDes_B.smax = -ControlDes_B.smax;
      }

      if (std::abs(ControlDes_B.smax) < 1.0020841800044864E-292) {
        b_ix = 0;
        ix = (ii - rankA) + 4;
        do {
          b_ix++;
          for (jy = pvt; jy <= ix; jy++) {
            ControlDes_B.b_A[jy - 1] *= 9.9792015476736E+291;
          }

          ControlDes_B.smax *= 9.9792015476736E+291;
          ControlDes_B.scale *= 9.9792015476736E+291;
        } while ((std::abs(ControlDes_B.smax) < 1.0020841800044864E-292) &&
                 (b_ix < 20));

        ControlDes_B.smax = rt_hypotd(ControlDes_B.scale,
          ControlDes_xnrm2_l2M7eLKH(3 - rankA, ControlDes_B.b_A, ii + 2));
        if (ControlDes_B.scale >= 0.0) {
          ControlDes_B.smax = -ControlDes_B.smax;
        }

        ControlDes_B.tau[rankA] = (ControlDes_B.smax - ControlDes_B.scale) /
          ControlDes_B.smax;
        ControlDes_B.scale = 1.0 / (ControlDes_B.scale - ControlDes_B.smax);
        for (jy = pvt; jy <= ix; jy++) {
          ControlDes_B.b_A[jy - 1] *= ControlDes_B.scale;
        }

        for (pvt = 0; pvt < b_ix; pvt++) {
          ControlDes_B.smax *= 1.0020841800044864E-292;
        }

        ControlDes_B.scale = ControlDes_B.smax;
      } else {
        ControlDes_B.tau[rankA] = (ControlDes_B.smax - ControlDes_B.b_A[ii]) /
          ControlDes_B.smax;
        ControlDes_B.scale = 1.0 / (ControlDes_B.b_A[ii] - ControlDes_B.smax);
        b_ix = (ii - rankA) + 4;
        for (ix = pvt; ix <= b_ix; ix++) {
          ControlDes_B.b_A[ix - 1] *= ControlDes_B.scale;
        }

        ControlDes_B.scale = ControlDes_B.smax;
      }
    }

    ControlDes_B.b_A[ii] = ControlDes_B.scale;
    if (rankA + 1 < 3) {
      ControlDes_B.smax = ControlDes_B.b_A[ii];
      ControlDes_B.b_A[ii] = 1.0;
      if (ControlDes_B.tau[rankA] != 0.0) {
        pvt = 4 - rankA;
        b_ix = (ii - rankA) + 3;
        while ((pvt > 0) && (ControlDes_B.b_A[b_ix] == 0.0)) {
          pvt--;
          b_ix--;
        }

        b_ix = 1 - rankA;
        exitg2 = false;
        while (!exitg2 && (b_ix + 1 > 0)) {
          ix = ((b_ix << 2) + ii) + 4;
          jy = ix;
          do {
            exitg1 = 0;
            if (jy + 1 <= ix + pvt) {
              if (ControlDes_B.b_A[jy] != 0.0) {
                exitg1 = 1;
              } else {
                jy++;
              }
            } else {
              b_ix--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = 0;
        b_ix = -1;
      }

      if (pvt > 0) {
        if (b_ix + 1 != 0) {
          std::memset(&ControlDes_B.work[0], 0, static_cast<uint32_T>(b_ix + 1) *
                      sizeof(real_T));
          ix = 0;
          jy = ((b_ix << 2) + ii) + 5;
          for (ii_tmp = ii + 5; ii_tmp <= jy; ii_tmp += 4) {
            ControlDes_B.scale = 0.0;
            e = ii_tmp + pvt;
            for (ia = ii_tmp; ia < e; ia++) {
              ControlDes_B.scale += ControlDes_B.b_A[(ii + ia) - ii_tmp] *
                ControlDes_B.b_A[ia - 1];
            }

            ControlDes_B.work[ix] += ControlDes_B.scale;
            ix++;
          }
        }

        if (-ControlDes_B.tau[rankA] != 0.0) {
          ix = ii + 5;
          for (ii_tmp = 0; ii_tmp <= b_ix; ii_tmp++) {
            ControlDes_B.scale = ControlDes_B.work[ii_tmp];
            if (ControlDes_B.scale != 0.0) {
              ControlDes_B.scale *= -ControlDes_B.tau[rankA];
              e = pvt + ix;
              for (ia = ix; ia < e; ia++) {
                ControlDes_B.b_A[ia - 1] += ControlDes_B.b_A[(ii + ia) - ix] *
                  ControlDes_B.scale;
              }
            }

            ix += 4;
          }
        }
      }

      ControlDes_B.b_A[ii] = ControlDes_B.smax;
    }

    for (ii = rankA + 2; ii < 4; ii++) {
      pvt = ((ii - 1) << 2) + rankA;
      ControlDes_B.absxk = ControlDes_B.vn1[ii - 1];
      if (ControlDes_B.absxk != 0.0) {
        ControlDes_B.smax = std::abs(ControlDes_B.b_A[pvt]) / ControlDes_B.absxk;
        ControlDes_B.smax = 1.0 - ControlDes_B.smax * ControlDes_B.smax;
        if (ControlDes_B.smax < 0.0) {
          ControlDes_B.smax = 0.0;
        }

        ControlDes_B.scale = ControlDes_B.absxk / ControlDes_B.vn2[ii - 1];
        if (ControlDes_B.scale * ControlDes_B.scale * ControlDes_B.smax <=
            1.4901161193847656E-8) {
          ControlDes_B.absxk = ControlDes_xnrm2_l2M7eLKH(3 - rankA,
            ControlDes_B.b_A, pvt + 2);
          ControlDes_B.vn1[ii - 1] = ControlDes_B.absxk;
          ControlDes_B.vn2[ii - 1] = ControlDes_B.absxk;
        } else {
          ControlDes_B.vn1[ii - 1] = ControlDes_B.absxk * std::sqrt
            (ControlDes_B.smax);
        }
      }
    }
  }

  rankA = 0;
  ControlDes_B.smax = 8.881784197001252E-15 * std::abs(ControlDes_B.b_A[0]);
  while ((rankA < 3) && (std::abs(ControlDes_B.b_A[(rankA << 2) + rankA]) >
                         ControlDes_B.smax)) {
    rankA++;
  }

  for (ii = 0; ii < 3; ii++) {
    Y[ii] = 0.0;
    if (ControlDes_B.tau[ii] != 0.0) {
      ControlDes_B.smax = ControlDes_B.b_B[ii];
      for (pvt = ii + 2; pvt < 5; pvt++) {
        ControlDes_B.smax += ControlDes_B.b_A[((ii << 2) + pvt) - 1] *
          ControlDes_B.b_B[pvt - 1];
      }

      ControlDes_B.smax *= ControlDes_B.tau[ii];
      if (ControlDes_B.smax != 0.0) {
        ControlDes_B.b_B[ii] -= ControlDes_B.smax;
        for (pvt = ii + 2; pvt < 5; pvt++) {
          ControlDes_B.b_B[pvt - 1] -= ControlDes_B.b_A[((ii << 2) + pvt) - 1] *
            ControlDes_B.smax;
        }
      }
    }
  }

  for (ii = 0; ii < rankA; ii++) {
    Y[jpvt[ii] - 1] = ControlDes_B.b_B[ii];
  }

  for (ii = rankA; ii >= 1; ii--) {
    jpvt_0 = jpvt[ii - 1];
    pvt = (ii - 1) << 2;
    Y[jpvt_0 - 1] /= ControlDes_B.b_A[(pvt + ii) - 1];
    for (b_ix = 0; b_ix <= ii - 2; b_ix++) {
      ix = jpvt[b_ix] - 1;
      Y[ix] -= ControlDes_B.b_A[pvt + b_ix] * Y[jpvt_0 - 1];
    }
  }
}

void ControlDes::init(real_T rty_R4[3])
{
  ControlDes_DW.State_DSTATE[0] = 0.009;
  ControlDes_DW.State_DSTATE_e[0] = 0.018;
  ControlDes_DW.State_DSTATE_j[0] = 0.018;
  ControlDes_DW.State_DSTATE_k[0] = 0.018;
  ControlDes_DW.State_DSTATE_f[0] = 0.01023;
  ControlDes_DW.State_DSTATE_g[0] = 0.018;
  ControlDes_DW.State_DSTATE_fj[0] = 0.009;
  ControlDes_DW.State_DSTATE_n[0] = 0.01023;
  ControlDes_DW.State_DSTATE_b[0] = 0.009;
  ControlDes_DW.State_DSTATE_m[0] = 0.01023;
  rty_R4[0] = 0.0;
  ControlDes_DW.State_DSTATE[1] = 0.0;
  ControlDes_DW.State_DSTATE_e[1] = 0.0;
  ControlDes_DW.State_DSTATE_j[1] = 0.0;
  ControlDes_DW.State_DSTATE_k[1] = 0.0;
  ControlDes_DW.State_DSTATE_f[1] = 0.0;
  ControlDes_DW.State_DSTATE_g[1] = 0.0;
  ControlDes_DW.State_DSTATE_fj[1] = 0.0;
  ControlDes_DW.State_DSTATE_n[1] = 0.0;
  ControlDes_DW.State_DSTATE_b[1] = 0.0;
  ControlDes_DW.State_DSTATE_m[1] = 0.0;
  rty_R4[1] = 0.0;
  ControlDes_DW.State_DSTATE[2] = 0.0;
  ControlDes_DW.State_DSTATE_e[2] = 9.8;
  ControlDes_DW.State_DSTATE_j[2] = 9.8;
  ControlDes_DW.State_DSTATE_k[2] = 9.8;
  ControlDes_DW.State_DSTATE_f[2] = 0.0;
  ControlDes_DW.State_DSTATE_g[2] = 9.8;
  ControlDes_DW.State_DSTATE_fj[2] = 0.0;
  ControlDes_DW.State_DSTATE_n[2] = 0.0;
  ControlDes_DW.State_DSTATE_b[2] = 0.0;
  ControlDes_DW.State_DSTATE_m[2] = 0.0;
  rty_R4[2] = 0.0;
}

void ControlDes::step(const real_T rtu_Sensores[8], const real_T *rtu_RefZ,
                      const real_T rtu_I_Hems[4], const real_T rtu_I_EMS[6],
                      real_T rty_Estados[5], real_T rty_R1[3], real_T rty_R2[3],
                      real_T rty_R3[3], real_T rty_R4[3], real_T rty_Fa[4],
                      real_T rty_CorrienteDeReferencia[10], real_T
                      rty_airgaps_actuadores[10])
{
  int32_T k;
  int32_T tmp;
  static const real_T b[12]{ 1.0, 1.0, 1.0, 1.0, -0.3128, 0.31027, -0.3128,
    0.31027, -1.21436, -1.21636, 1.24866, 1.24666 };

  static const real_T e[12]{ 1.0, 1.0, 1.0, 1.0, -0.28497, 0.28244, -0.28497,
    0.28244, 1.24634, 1.24834, -1.28064, -1.27864 };

  static const real_T e_0[6]{ -0.35903, 0.35697, -0.35903, 0.35697, -0.35903,
    0.35697 };

  static const real_T f[6]{ -0.35003, 0.34674, -0.35003, 0.34674, -0.35003,
    0.34674 };

  static const real_T g[6]{ 0.75185, 0.75185, -0.01615, -0.01615, -0.78415,
    -0.78415 };

  static const real_T h[6]{ 0.22816, 0.22816, 0.22816, 0.22816, 0.22818, 0.22816
  };

  static const int8_T d[6]{ -1, 1, -1, 1, -1, 1 };

  ControlDes_B.g_v[0] = ((-rtu_Sensores[0] - 0.015) + 0.0932) - -0.00782;
  ControlDes_B.g_v[1] = ((-rtu_Sensores[1] - 0.015) + 0.0932) - -0.00782;
  ControlDes_B.g_v[2] = ((-rtu_Sensores[2] - 0.015) + 0.0932) - -0.00782;
  ControlDes_B.g_v[3] = ((-rtu_Sensores[3] - 0.015) + 0.0932) - -0.00782;
  ControlDes_mldivide_l89k28gF(b, ControlDes_B.g_v, ControlDes_B.theta_v);
  ControlDes_B.rotz = std::sin(ControlDes_B.theta_v[2]);
  ControlDes_B.b_accumulatedData = std::sin(ControlDes_B.theta_v[1]);
  ControlDes_B.Div = -0.00782 * std::cos(ControlDes_B.theta_v[1]);
  ControlDes_B.g_v_idx_0_tmp = -0.3128 * ControlDes_B.b_accumulatedData;
  ControlDes_B.g_v_idx_0 = ((((-rtu_Sensores[0] - 0.015) + 0.0932) -
    ControlDes_B.Div) + 1.21436 * ControlDes_B.rotz) -
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.g_v_idx_1_tmp = 0.31027 * ControlDes_B.b_accumulatedData;
  ControlDes_B.g_v_idx_1 = ((((-rtu_Sensores[1] - 0.015) + 0.0932) -
    ControlDes_B.Div) + 1.21636 * ControlDes_B.rotz) -
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.g_v_idx_2 = ((((-rtu_Sensores[2] - 0.015) + 0.0932) -
    ControlDes_B.Div) + -1.24866 * ControlDes_B.rotz) -
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.g_v_idx_3 = ((((-rtu_Sensores[3] - 0.015) + 0.0932) -
    ControlDes_B.Div) + -1.24666 * ControlDes_B.rotz) -
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.b_accumulatedData *= 0.26891;
  ControlDes_B.g_v[0] = (-0.35903 - (-rtu_Sensores[4])) +
    ControlDes_B.b_accumulatedData;
  ControlDes_B.g_v[1] = (0.35697 - rtu_Sensores[5]) +
    ControlDes_B.b_accumulatedData;
  ControlDes_B.g_v[2] = (-0.35903 - (-rtu_Sensores[6])) +
    ControlDes_B.b_accumulatedData;
  ControlDes_B.g_v[3] = (0.35697 - rtu_Sensores[7]) +
    ControlDes_B.b_accumulatedData;
  ControlDes_mldivide_l89k28gF(e, ControlDes_B.g_v, ControlDes_B.theta_l);
  ControlDes_B.rotz = std::atan2(ControlDes_B.theta_l[2], ControlDes_B.theta_l[1]);
  ControlDes_B.Div = std::cos(ControlDes_B.rotz);
  ControlDes_B.Sat_I_m = std::sin(ControlDes_B.rotz);
  ControlDes_B.g_v_idx_1_tmp = -0.28497 * ControlDes_B.Div;
  ControlDes_B.g_v_idx_0_tmp = 0.28244 * ControlDes_B.Div;
  rty_Estados[0] = (((((-0.35903 - (-rtu_Sensores[4])) - ((1.24634 *
    ControlDes_B.Sat_I_m + ControlDes_B.g_v_idx_1_tmp) -
    ControlDes_B.b_accumulatedData)) + ((0.35697 - rtu_Sensores[5]) - ((1.24834 *
    ControlDes_B.Sat_I_m + ControlDes_B.g_v_idx_0_tmp) -
    ControlDes_B.b_accumulatedData))) + ((-0.35903 - (-rtu_Sensores[6])) -
    ((-1.28064 * ControlDes_B.Sat_I_m + ControlDes_B.g_v_idx_1_tmp) -
     ControlDes_B.b_accumulatedData))) + ((0.35697 - rtu_Sensores[7]) -
    ((-1.27864 * ControlDes_B.Sat_I_m + ControlDes_B.g_v_idx_0_tmp) -
     ControlDes_B.b_accumulatedData))) / 4.0;
  rty_Estados[1] = (((ControlDes_B.g_v_idx_0 + ControlDes_B.g_v_idx_1) +
                     ControlDes_B.g_v_idx_2) + ControlDes_B.g_v_idx_3) / 4.0;
  rty_Estados[2] = ControlDes_B.theta_v[1];
  rty_Estados[3] = ControlDes_B.theta_v[2];
  rty_Estados[4] = ControlDes_B.rotz;
  ControlDes_B.g_v_idx_0 = std::sin(rty_Estados[2]);
  ControlDes_B.rotz = std::sin(rty_Estados[3]);
  ControlDes_B.b_accumulatedData = std::cos(rty_Estados[4]);
  ControlDes_B.Div = std::sin(rty_Estados[4]);
  ControlDes_B.Sat_I_m = std::sin(rty_Estados[2]);
  ControlDes_B.g_v_idx_1_tmp = rty_Estados[0];
  for (k = 0; k < 6; k++) {
    ControlDes_B.g_e[k] = std::abs(((e_0[k] - ((f[k] *
      ControlDes_B.b_accumulatedData + g[k] * ControlDes_B.Div) - h[k] *
      ControlDes_B.Sat_I_m)) - ControlDes_B.g_v_idx_1_tmp) * static_cast<real_T>
      (d[k]));
  }

  ControlDes_B.g_v_idx_1_tmp = 0.93085 * ControlDes_B.rotz;
  ControlDes_B.g_v_idx_0_tmp = -0.27376 * ControlDes_B.g_v_idx_0 + rty_Estados[1];
  rty_airgaps_actuadores[0] = std::abs(ControlDes_B.g_v_idx_0_tmp -
    ControlDes_B.g_v_idx_1_tmp);
  ControlDes_B.d13 = 0.27124 * ControlDes_B.g_v_idx_0 + rty_Estados[1];
  rty_airgaps_actuadores[1] = std::abs(ControlDes_B.d13 -
    ControlDes_B.g_v_idx_1_tmp);
  ControlDes_B.g_v_idx_1_tmp = -0.96315 * ControlDes_B.rotz;
  rty_airgaps_actuadores[2] = std::abs(ControlDes_B.g_v_idx_0_tmp -
    ControlDes_B.g_v_idx_1_tmp);
  rty_airgaps_actuadores[3] = std::abs(ControlDes_B.d13 -
    ControlDes_B.g_v_idx_1_tmp);
  rty_airgaps_actuadores[4] = ControlDes_B.g_e[0];
  rty_airgaps_actuadores[5] = ControlDes_B.g_e[1];
  rty_airgaps_actuadores[6] = ControlDes_B.g_e[2];
  rty_airgaps_actuadores[7] = ControlDes_B.g_e[3];
  rty_airgaps_actuadores[8] = ControlDes_B.g_e[4];
  rty_airgaps_actuadores[9] = ControlDes_B.g_e[5];
  ControlDes_B.b_accumulatedData = 1000.0 * rty_airgaps_actuadores[4];
  ControlDes_B.TmpSignalConversionAtBInpor[0] = look2_binlcpw
    (ControlDes_B.b_accumulatedData, ControlDes_DW.UnitDelay_DSTATE,
     rtCP_LUT_HEMS_3_bp01Data, rtCP_LUT_HEMS_3_bp02Data,
     rtCP_LUT_HEMS_3_tableData, rtCP_LUT_HEMS_3_maxIndex, 33U);
  ControlDes_B.TmpSignalConversionAtBInpor[1] = rty_airgaps_actuadores[4];
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_C_Gain[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_C_Gain[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_C_Gain[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversionAtBInpor[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_D_Gain[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_D_Gain[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_D_Gain[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_B.rotz = 1000.0 * rty_airgaps_actuadores[1];
  ControlDes_B.TmpSignalConversionAtBInp_i[0] = look2_binlcpw(ControlDes_B.rotz,
    ControlDes_DW.UnitDelay_DSTATE_i, rtCP_LUT_HEMS_3_bp01Data_p,
    rtCP_LUT_HEMS_3_bp02Data_b, rtCP_LUT_HEMS_3_tableData_o,
    rtCP_LUT_HEMS_3_maxIndex_g, 37U);
  ControlDes_B.TmpSignalConversionAtBInp_i[1] = rty_airgaps_actuadores[1];
  ControlDes_B.unnamed_idx_0_m = 0.0;
  ControlDes_B.unnamed_idx_1_n = 0.0;
  ControlDes_B.unnamed_idx_2_p = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.d = ControlDes_DW.State_DSTATE_e[k];
    ControlDes_B.unnamed_idx_0_m += rtCP_C_Gain_o[tmp] * ControlDes_B.d;
    ControlDes_B.unnamed_idx_1_n += rtCP_C_Gain_o[tmp + 1] * ControlDes_B.d;
    ControlDes_B.unnamed_idx_2_p += rtCP_C_Gain_o[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_B.d = 0.0;
  ControlDes_B.d11 = 0.0;
  ControlDes_B.d12 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d1 = ControlDes_B.TmpSignalConversionAtBInp_i[k];
    ControlDes_B.d += rtCP_D_Gain_i[tmp] * ControlDes_B.d1;
    ControlDes_B.d11 += rtCP_D_Gain_i[tmp + 1] * ControlDes_B.d1;
    ControlDes_B.d12 += rtCP_D_Gain_i[tmp + 2] * ControlDes_B.d1;
    tmp += 3;
  }

  rty_R2[0] = ControlDes_B.unnamed_idx_0_m + ControlDes_B.d;
  rty_R2[1] = ControlDes_B.unnamed_idx_1_n + ControlDes_B.d11;
  rty_R2[2] = ControlDes_B.unnamed_idx_2_p + ControlDes_B.d12;
  ControlDes_B.Div = (((*rtu_RefZ - rty_R2[0]) * 100.0 - 20.0 * rty_R2[1]) -
                      rty_R2[2]) / -0.0103359173126615;
  ControlDes_B.Sat_I_m = 1000.0 * rty_airgaps_actuadores[2];
  ControlDes_B.TmpSignalConversionAtBIn_iz[0] = look2_binlcpw
    (ControlDes_B.Sat_I_m, ControlDes_DW.UnitDelay_DSTATE_m,
     rtCP_LUT_HEMS_3_bp01Data_f, rtCP_LUT_HEMS_3_bp02Data_e,
     rtCP_LUT_HEMS_3_tableData_g, rtCP_LUT_HEMS_3_maxIndex_g3, 37U);
  ControlDes_B.TmpSignalConversionAtBIn_iz[1] = rty_airgaps_actuadores[2];
  ControlDes_B.unnamed_idx_0_m = 0.0;
  ControlDes_B.unnamed_idx_1_n = 0.0;
  ControlDes_B.unnamed_idx_2_p = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.d = ControlDes_DW.State_DSTATE_j[k];
    ControlDes_B.unnamed_idx_0_m += rtCP_C_Gain_j[tmp] * ControlDes_B.d;
    ControlDes_B.unnamed_idx_1_n += rtCP_C_Gain_j[tmp + 1] * ControlDes_B.d;
    ControlDes_B.unnamed_idx_2_p += rtCP_C_Gain_j[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_B.d = 0.0;
  ControlDes_B.d11 = 0.0;
  ControlDes_B.d12 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d1 = ControlDes_B.TmpSignalConversionAtBIn_iz[k];
    ControlDes_B.d += rtCP_D_Gain_j[tmp] * ControlDes_B.d1;
    ControlDes_B.d11 += rtCP_D_Gain_j[tmp + 1] * ControlDes_B.d1;
    ControlDes_B.d12 += rtCP_D_Gain_j[tmp + 2] * ControlDes_B.d1;
    tmp += 3;
  }

  rty_R3[0] = ControlDes_B.unnamed_idx_0_m + ControlDes_B.d;
  rty_R3[1] = ControlDes_B.unnamed_idx_1_n + ControlDes_B.d11;
  rty_R3[2] = ControlDes_B.unnamed_idx_2_p + ControlDes_B.d12;
  ControlDes_B.g_v_idx_0 = (((*rtu_RefZ - rty_R3[0]) * 100.0 - 20.0 * rty_R3[1])
    - rty_R3[2]) / -0.0103359173126615;
  ControlDes_B.Sat_I_h = 1000.0 * rty_airgaps_actuadores[3];
  ControlDes_B.TmpSignalConversionAtBI_izx[0] = look2_binlcpw
    (ControlDes_B.Sat_I_h, ControlDes_DW.UnitDelay_DSTATE_g,
     rtCP_LUT_HEMS_3_bp01Data_c, rtCP_LUT_HEMS_3_bp02Data_bg,
     rtCP_LUT_HEMS_3_tableData_gc, rtCP_LUT_HEMS_3_maxIndex_gw, 37U);
  ControlDes_B.TmpSignalConversionAtBI_izx[1] = rty_airgaps_actuadores[3];
  ControlDes_B.unnamed_idx_0_m = 0.0;
  ControlDes_B.unnamed_idx_1_n = 0.0;
  ControlDes_B.unnamed_idx_2_p = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.d = ControlDes_DW.State_DSTATE_k[k];
    ControlDes_B.unnamed_idx_0_m += rtCP_C_Gain_g[tmp] * ControlDes_B.d;
    ControlDes_B.unnamed_idx_1_n += rtCP_C_Gain_g[tmp + 1] * ControlDes_B.d;
    ControlDes_B.unnamed_idx_2_p += rtCP_C_Gain_g[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_B.d = 0.0;
  ControlDes_B.d11 = 0.0;
  ControlDes_B.d12 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d1 = ControlDes_B.TmpSignalConversionAtBI_izx[k];
    ControlDes_B.d += rtCP_D_Gain_c[tmp] * ControlDes_B.d1;
    ControlDes_B.d11 += rtCP_D_Gain_c[tmp + 1] * ControlDes_B.d1;
    ControlDes_B.d12 += rtCP_D_Gain_c[tmp + 2] * ControlDes_B.d1;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1 = (((*rtu_RefZ - (ControlDes_B.unnamed_idx_0_m +
    ControlDes_B.d)) * 100.0 - (ControlDes_B.unnamed_idx_1_n + ControlDes_B.d11)
    * 20.0) - (ControlDes_B.unnamed_idx_2_p + ControlDes_B.d12)) /
    -0.0103359173126615;
  ControlDes_B.Sat_I_o = 1000.0 * rty_airgaps_actuadores[5];
  ControlDes_B.TmpSignalConversionAtB_izxo[0] = look2_binlcpw
    (ControlDes_B.Sat_I_o, ControlDes_DW.UnitDelay_DSTATE_mu,
     rtCP_LUT_HEMS_3_bp01Data_l, rtCP_LUT_HEMS_3_bp02Data_e2,
     rtCP_LUT_HEMS_3_tableData_e, rtCP_LUT_HEMS_3_maxIndex_gr, 33U);
  ControlDes_B.TmpSignalConversionAtB_izxo[1] = rty_airgaps_actuadores[5];
  ControlDes_B.unnamed_idx_0_m = 0.0;
  ControlDes_B.unnamed_idx_1_n = 0.0;
  ControlDes_B.unnamed_idx_2_p = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.d = ControlDes_DW.State_DSTATE_f[k];
    ControlDes_B.unnamed_idx_0_m += rtCP_C_Gain_f[tmp] * ControlDes_B.d;
    ControlDes_B.unnamed_idx_1_n += rtCP_C_Gain_f[tmp + 1] * ControlDes_B.d;
    ControlDes_B.unnamed_idx_2_p += rtCP_C_Gain_f[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_B.d = 0.0;
  ControlDes_B.d11 = 0.0;
  ControlDes_B.d12 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d1 = ControlDes_B.TmpSignalConversionAtB_izxo[k];
    ControlDes_B.d += rtCP_D_Gain_jj[tmp] * ControlDes_B.d1;
    ControlDes_B.d11 += rtCP_D_Gain_jj[tmp + 1] * ControlDes_B.d1;
    ControlDes_B.d12 += rtCP_D_Gain_jj[tmp + 2] * ControlDes_B.d1;
    tmp += 3;
  }

  ControlDes_B.Sat_I_b = 1000.0 * rty_airgaps_actuadores[0];
  ControlDes_B.TmpSignalConversionAt_izxof[0] = look2_binlcpw
    (ControlDes_B.Sat_I_b, ControlDes_DW.UnitDelay_DSTATE_n,
     rtCP_LUT_HEMS_3_bp01Data_m, rtCP_LUT_HEMS_3_bp02Data_h,
     rtCP_LUT_HEMS_3_tableData_ek, rtCP_LUT_HEMS_3_maxIndex_p, 37U);
  ControlDes_B.TmpSignalConversionAt_izxof[1] = rty_airgaps_actuadores[0];
  ControlDes_B.unnamed_idx_0_f = 0.0;
  ControlDes_B.unnamed_idx_1_g = 0.0;
  ControlDes_B.unnamed_idx_2_g = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.d1 = ControlDes_DW.State_DSTATE_g[k];
    ControlDes_B.unnamed_idx_0_f += rtCP_C_Gain_fm[tmp] * ControlDes_B.d1;
    ControlDes_B.unnamed_idx_1_g += rtCP_C_Gain_fm[tmp + 1] * ControlDes_B.d1;
    ControlDes_B.unnamed_idx_2_g += rtCP_C_Gain_fm[tmp + 2] * ControlDes_B.d1;
    tmp += 3;
  }

  ControlDes_B.d1 = 0.0;
  ControlDes_B.d9 = 0.0;
  ControlDes_B.d10 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.u0 = ControlDes_B.TmpSignalConversionAt_izxof[k];
    ControlDes_B.d1 += rtCP_D_Gain_k[tmp] * ControlDes_B.u0;
    ControlDes_B.d9 += rtCP_D_Gain_k[tmp + 1] * ControlDes_B.u0;
    ControlDes_B.d10 += rtCP_D_Gain_k[tmp + 2] * ControlDes_B.u0;
    tmp += 3;
  }

  rty_R1[0] = ControlDes_B.unnamed_idx_0_f + ControlDes_B.d1;
  rty_R1[1] = ControlDes_B.unnamed_idx_1_g + ControlDes_B.d9;
  rty_R1[2] = ControlDes_B.unnamed_idx_2_g + ControlDes_B.d10;
  ControlDes_B.g_v_idx_2 = (((*rtu_RefZ - rty_R1[0]) * 100.0 - 20.0 * rty_R1[1])
    - rty_R1[2]) / -0.0103359173126615;
  ControlDes_B.Sat_I_g = 1000.0 * rty_airgaps_actuadores[6];
  ControlDes_B.TmpSignalConversionA_izxofb[0] = look2_binlcpw
    (ControlDes_B.Sat_I_g, ControlDes_DW.UnitDelay_DSTATE_gq,
     rtCP_LUT_HEMS_3_bp01Data_a, rtCP_LUT_HEMS_3_bp02Data_n,
     rtCP_LUT_HEMS_3_tableData_gy, rtCP_LUT_HEMS_3_maxIndex_c, 33U);
  ControlDes_B.TmpSignalConversionA_izxofb[1] = rty_airgaps_actuadores[6];
  ControlDes_B.unnamed_idx_0_f = 0.0;
  ControlDes_B.unnamed_idx_1_g = 0.0;
  ControlDes_B.unnamed_idx_2_g = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.d1 = ControlDes_DW.State_DSTATE_fj[k];
    ControlDes_B.unnamed_idx_0_f += rtCP_C_Gain_n[tmp] * ControlDes_B.d1;
    ControlDes_B.unnamed_idx_1_g += rtCP_C_Gain_n[tmp + 1] * ControlDes_B.d1;
    ControlDes_B.unnamed_idx_2_g += rtCP_C_Gain_n[tmp + 2] * ControlDes_B.d1;
    tmp += 3;
  }

  ControlDes_B.d1 = 0.0;
  ControlDes_B.d9 = 0.0;
  ControlDes_B.d10 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.u0 = ControlDes_B.TmpSignalConversionA_izxofb[k];
    ControlDes_B.d1 += rtCP_D_Gain_h[tmp] * ControlDes_B.u0;
    ControlDes_B.d9 += rtCP_D_Gain_h[tmp + 1] * ControlDes_B.u0;
    ControlDes_B.d10 += rtCP_D_Gain_h[tmp + 2] * ControlDes_B.u0;
    tmp += 3;
  }

  ControlDes_B.Sat_I_j = 1000.0 * rty_airgaps_actuadores[7];
  ControlDes_B.TmpSignalConversion_izxofbo[0] = look2_binlcpw
    (ControlDes_B.Sat_I_j, ControlDes_DW.UnitDelay_DSTATE_p,
     rtCP_LUT_HEMS_3_bp01Data_i, rtCP_LUT_HEMS_3_bp02Data_bg0,
     rtCP_LUT_HEMS_3_tableData_d, rtCP_LUT_HEMS_3_maxIndex_m, 33U);
  ControlDes_B.TmpSignalConversion_izxofbo[1] = rty_airgaps_actuadores[7];
  ControlDes_B.unnamed_idx_0_b = 0.0;
  ControlDes_B.unnamed_idx_1_p = 0.0;
  ControlDes_B.unnamed_idx_2_cv = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.u0 = ControlDes_DW.State_DSTATE_n[k];
    ControlDes_B.unnamed_idx_0_b += rtCP_C_Gain_fs[tmp] * ControlDes_B.u0;
    ControlDes_B.unnamed_idx_1_p += rtCP_C_Gain_fs[tmp + 1] * ControlDes_B.u0;
    ControlDes_B.unnamed_idx_2_cv += rtCP_C_Gain_fs[tmp + 2] * ControlDes_B.u0;
    tmp += 3;
  }

  ControlDes_B.u0 = 0.0;
  ControlDes_B.d7 = 0.0;
  ControlDes_B.d8 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.u0_m = ControlDes_B.TmpSignalConversion_izxofbo[k];
    ControlDes_B.u0 += rtCP_D_Gain_g[tmp] * ControlDes_B.u0_m;
    ControlDes_B.d7 += rtCP_D_Gain_g[tmp + 1] * ControlDes_B.u0_m;
    ControlDes_B.d8 += rtCP_D_Gain_g[tmp + 2] * ControlDes_B.u0_m;
    tmp += 3;
  }

  ControlDes_B.Sat_I_mk = 1000.0 * rty_airgaps_actuadores[8];
  ControlDes_B.TmpSignalConversio_izxofbou[0] = look2_binlcpw
    (ControlDes_B.Sat_I_mk, ControlDes_DW.UnitDelay_DSTATE_ne,
     rtCP_LUT_HEMS_3_bp01Data_ca, rtCP_LUT_HEMS_3_bp02Data_g,
     rtCP_LUT_HEMS_3_tableData_h, rtCP_LUT_HEMS_3_maxIndex_j, 33U);
  ControlDes_B.TmpSignalConversio_izxofbou[1] = rty_airgaps_actuadores[8];
  ControlDes_B.unnamed_idx_0_c = 0.0;
  ControlDes_B.unnamed_idx_1_k = 0.0;
  ControlDes_B.unnamed_idx_2_c = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.u0_m = ControlDes_DW.State_DSTATE_b[k];
    ControlDes_B.unnamed_idx_0_c += rtCP_C_Gain_gq[tmp] * ControlDes_B.u0_m;
    ControlDes_B.unnamed_idx_1_k += rtCP_C_Gain_gq[tmp + 1] * ControlDes_B.u0_m;
    ControlDes_B.unnamed_idx_2_c += rtCP_C_Gain_gq[tmp + 2] * ControlDes_B.u0_m;
    tmp += 3;
  }

  ControlDes_B.u0_m = 0.0;
  ControlDes_B.d5 = 0.0;
  ControlDes_B.d6 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.g_v_idx_3 = ControlDes_B.TmpSignalConversio_izxofbou[k];
    ControlDes_B.u0_m += rtCP_D_Gain_kj[tmp] * ControlDes_B.g_v_idx_3;
    ControlDes_B.d5 += rtCP_D_Gain_kj[tmp + 1] * ControlDes_B.g_v_idx_3;
    ControlDes_B.d6 += rtCP_D_Gain_kj[tmp + 2] * ControlDes_B.g_v_idx_3;
    tmp += 3;
  }

  ControlDes_B.Sat_I_mx = 1000.0 * rty_airgaps_actuadores[9];
  ControlDes_B.TmpSignalConversi_izxofbouj[0] = look2_binlcpw
    (ControlDes_B.Sat_I_mx, ControlDes_DW.UnitDelay_DSTATE_b,
     rtCP_LUT_HEMS_3_bp01Data_lq, rtCP_LUT_HEMS_3_bp02Data_a,
     rtCP_LUT_HEMS_3_tableData_b, rtCP_LUT_HEMS_3_maxIndex_i, 33U);
  ControlDes_B.TmpSignalConversi_izxofbouj[1] = rty_airgaps_actuadores[9];
  ControlDes_B.unnamed_idx_0 = 0.0;
  ControlDes_B.unnamed_idx_1 = 0.0;
  ControlDes_B.unnamed_idx_2 = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_3 = ControlDes_DW.State_DSTATE_m[k];
    ControlDes_B.unnamed_idx_0 += rtCP_C_Gain_i[tmp] * ControlDes_B.g_v_idx_3;
    ControlDes_B.unnamed_idx_1 += rtCP_C_Gain_i[tmp + 1] *
      ControlDes_B.g_v_idx_3;
    ControlDes_B.unnamed_idx_2 += rtCP_C_Gain_i[tmp + 2] *
      ControlDes_B.g_v_idx_3;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_3 = 0.0;
  ControlDes_B.d3 = 0.0;
  ControlDes_B.d4 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d2 = ControlDes_B.TmpSignalConversi_izxofbouj[k];
    ControlDes_B.g_v_idx_3 += rtCP_D_Gain_n[tmp] * ControlDes_B.d2;
    ControlDes_B.d3 += rtCP_D_Gain_n[tmp + 1] * ControlDes_B.d2;
    ControlDes_B.d4 += rtCP_D_Gain_n[tmp + 2] * ControlDes_B.d2;
    tmp += 3;
  }

  ControlDes_B.Sat_I_b = look2_binlcpw(ControlDes_B.Sat_I_b,
    ControlDes_B.g_v_idx_2, rtCP_InvLUT_1_bp01Data_oc, rtCP_InvLUT_1_bp02Data_a,
    rtCP_InvLUT_1_tableData_ok, rtCP_InvLUT_1_maxIndex_i, 37U);
  ControlDes_B.rotz = look2_binlcpw(ControlDes_B.rotz, ControlDes_B.Div,
    rtCP_InvLUT_1_bp01Data_h, rtCP_InvLUT_1_bp02Data_j,
    rtCP_InvLUT_1_tableData_m, rtCP_InvLUT_1_maxIndex_d, 37U);
  ControlDes_B.Sat_I_m = look2_binlcpw(ControlDes_B.Sat_I_m,
    ControlDes_B.g_v_idx_0, rtCP_InvLUT_1_bp01Data_e, rtCP_InvLUT_1_bp02Data_p,
    rtCP_InvLUT_1_tableData_f, rtCP_InvLUT_1_maxIndex_p, 37U);
  ControlDes_B.Sat_I_h = look2_binlcpw(ControlDes_B.Sat_I_h,
    ControlDes_B.g_v_idx_1, rtCP_InvLUT_1_bp01Data_c, rtCP_InvLUT_1_bp02Data_jh,
    rtCP_InvLUT_1_tableData_h, rtCP_InvLUT_1_maxIndex_b, 37U);
  ControlDes_B.b_accumulatedData = look2_binlcpw(ControlDes_B.b_accumulatedData,
    (((0.009 - (ControlDes_B.unnamed_idx_0_l + ControlDes_B.g_v_idx_1_tmp)) *
      64.0 - (ControlDes_B.unnamed_idx_1_j + ControlDes_B.g_v_idx_0_tmp) * 16.0)
     - (ControlDes_B.unnamed_idx_2_d + ControlDes_B.d13)) / -0.00775193798449612,
    rtCP_InvLUT_1_bp01Data, rtCP_InvLUT_1_bp02Data, rtCP_InvLUT_1_tableData,
    rtCP_InvLUT_1_maxIndex, 33U);
  ControlDes_B.g_v_idx_1_tmp = look2_binlcpw(ControlDes_B.Sat_I_o, (((0.01023 -
    (ControlDes_B.unnamed_idx_0_m + ControlDes_B.d)) * 64.0 -
    (ControlDes_B.unnamed_idx_1_n + ControlDes_B.d11) * 16.0) -
    (ControlDes_B.unnamed_idx_2_p + ControlDes_B.d12)) / -0.00775193798449612,
    rtCP_InvLUT_1_bp01Data_o, rtCP_InvLUT_1_bp02Data_k,
    rtCP_InvLUT_1_tableData_o, rtCP_InvLUT_1_maxIndex_o, 33U);
  ControlDes_B.g_v_idx_0_tmp = look2_binlcpw(ControlDes_B.Sat_I_g, (((0.009 -
    (ControlDes_B.unnamed_idx_0_f + ControlDes_B.d1)) * 64.0 -
    (ControlDes_B.unnamed_idx_1_g + ControlDes_B.d9) * 16.0) -
    (ControlDes_B.unnamed_idx_2_g + ControlDes_B.d10)) / -0.00775193798449612,
    rtCP_InvLUT_1_bp01Data_d, rtCP_InvLUT_1_bp02Data_i,
    rtCP_InvLUT_1_tableData_j, rtCP_InvLUT_1_maxIndex_l, 33U);
  ControlDes_B.u0 = look2_binlcpw(ControlDes_B.Sat_I_j, (((0.01023 -
    (ControlDes_B.unnamed_idx_0_b + ControlDes_B.u0)) * 64.0 -
    (ControlDes_B.unnamed_idx_1_p + ControlDes_B.d7) * 16.0) -
    (ControlDes_B.unnamed_idx_2_cv + ControlDes_B.d8)) / -0.00775193798449612,
    rtCP_InvLUT_1_bp01Data_ce, rtCP_InvLUT_1_bp02Data_o,
    rtCP_InvLUT_1_tableData_d, rtCP_InvLUT_1_maxIndex_dq, 33U);
  ControlDes_B.u0_m = look2_binlcpw(ControlDes_B.Sat_I_mk, (((0.009 -
    (ControlDes_B.unnamed_idx_0_c + ControlDes_B.u0_m)) * 64.0 -
    (ControlDes_B.unnamed_idx_1_k + ControlDes_B.d5) * 16.0) -
    (ControlDes_B.unnamed_idx_2_c + ControlDes_B.d6)) / -0.00775193798449612,
    rtCP_InvLUT_1_bp01Data_k, rtCP_InvLUT_1_bp02Data_pg,
    rtCP_InvLUT_1_tableData_e, rtCP_InvLUT_1_maxIndex_k, 33U);
  if (ControlDes_B.Sat_I_b > 50.0) {
    rty_CorrienteDeReferencia[0] = 50.0;
  } else if (ControlDes_B.Sat_I_b < -50.0) {
    rty_CorrienteDeReferencia[0] = -50.0;
  } else {
    rty_CorrienteDeReferencia[0] = ControlDes_B.Sat_I_b;
  }

  if (ControlDes_B.rotz > 50.0) {
    rty_CorrienteDeReferencia[1] = 50.0;
  } else if (ControlDes_B.rotz < -50.0) {
    rty_CorrienteDeReferencia[1] = -50.0;
  } else {
    rty_CorrienteDeReferencia[1] = ControlDes_B.rotz;
  }

  if (ControlDes_B.Sat_I_m > 50.0) {
    rty_CorrienteDeReferencia[2] = 50.0;
  } else if (ControlDes_B.Sat_I_m < -50.0) {
    rty_CorrienteDeReferencia[2] = -50.0;
  } else {
    rty_CorrienteDeReferencia[2] = ControlDes_B.Sat_I_m;
  }

  if (ControlDes_B.Sat_I_h > 50.0) {
    rty_CorrienteDeReferencia[3] = 50.0;
  } else if (ControlDes_B.Sat_I_h < -50.0) {
    rty_CorrienteDeReferencia[3] = -50.0;
  } else {
    rty_CorrienteDeReferencia[3] = ControlDes_B.Sat_I_h;
  }

  if (ControlDes_B.b_accumulatedData > 50.0) {
    rty_CorrienteDeReferencia[4] = 50.0;
  } else if (ControlDes_B.b_accumulatedData < -50.0) {
    rty_CorrienteDeReferencia[4] = -50.0;
  } else {
    rty_CorrienteDeReferencia[4] = ControlDes_B.b_accumulatedData;
  }

  if (ControlDes_B.g_v_idx_1_tmp > 50.0) {
    rty_CorrienteDeReferencia[5] = 50.0;
  } else if (ControlDes_B.g_v_idx_1_tmp < -50.0) {
    rty_CorrienteDeReferencia[5] = -50.0;
  } else {
    rty_CorrienteDeReferencia[5] = ControlDes_B.g_v_idx_1_tmp;
  }

  if (ControlDes_B.g_v_idx_0_tmp > 50.0) {
    rty_CorrienteDeReferencia[6] = 50.0;
  } else if (ControlDes_B.g_v_idx_0_tmp < -50.0) {
    rty_CorrienteDeReferencia[6] = -50.0;
  } else {
    rty_CorrienteDeReferencia[6] = ControlDes_B.g_v_idx_0_tmp;
  }

  if (ControlDes_B.u0 > 50.0) {
    rty_CorrienteDeReferencia[7] = 50.0;
  } else if (ControlDes_B.u0 < -50.0) {
    rty_CorrienteDeReferencia[7] = -50.0;
  } else {
    rty_CorrienteDeReferencia[7] = ControlDes_B.u0;
  }

  if (ControlDes_B.u0_m > 50.0) {
    rty_CorrienteDeReferencia[8] = 50.0;
  } else if (ControlDes_B.u0_m < -50.0) {
    rty_CorrienteDeReferencia[8] = -50.0;
  } else {
    rty_CorrienteDeReferencia[8] = ControlDes_B.u0_m;
  }

  rty_Fa[0] = ControlDes_B.g_v_idx_2;
  rty_Fa[1] = ControlDes_B.Div;
  rty_Fa[2] = ControlDes_B.g_v_idx_0;
  rty_Fa[3] = ControlDes_B.g_v_idx_1;
  rty_R4[0] = 0.0;
  rty_R4[1] = 0.0;
  rty_R4[2] = 0.0;
  ControlDes_B.Sat_I_b = look2_binlcpw(ControlDes_B.Sat_I_mx, (((0.01023 -
    (ControlDes_B.unnamed_idx_0 + ControlDes_B.g_v_idx_3)) * 64.0 -
    (ControlDes_B.unnamed_idx_1 + ControlDes_B.d3) * 16.0) -
    (ControlDes_B.unnamed_idx_2 + ControlDes_B.d4)) / -0.00775193798449612,
    rtCP_InvLUT_1_bp01Data_hv, rtCP_InvLUT_1_bp02Data_d,
    rtCP_InvLUT_1_tableData_b, rtCP_InvLUT_1_maxIndex_j, 33U);
  if (ControlDes_B.Sat_I_b > 50.0) {
    rty_CorrienteDeReferencia[9] = 50.0;
  } else if (ControlDes_B.Sat_I_b < -50.0) {
    rty_CorrienteDeReferencia[9] = -50.0;
  } else {
    rty_CorrienteDeReferencia[9] = ControlDes_B.Sat_I_b;
  }

  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_hd[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_hd[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_hd[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversionAtBInpor[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_jk[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_jk[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_jk[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE = rtu_I_EMS[0];
  ControlDes_DW.State_DSTATE[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_e[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_l[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_l[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_l[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversionAtBInp_i[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_j[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_j[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_j[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE_i = rtu_I_Hems[1];
  ControlDes_DW.State_DSTATE_e[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE_e[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE_e[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_j[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_c[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_c[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_c[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversionAtBIn_iz[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_c2[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_c2[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_c2[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE_m = rtu_I_Hems[2];
  ControlDes_DW.State_DSTATE_j[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE_j[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE_j[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_k[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_dv[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_dv[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_dv[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversionAtBI_izx[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_f[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_f[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_f[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE_g = rtu_I_Hems[3];
  ControlDes_DW.State_DSTATE_k[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE_k[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE_k[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_f[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_e[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_e[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_e[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversionAtB_izxo[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_l[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_l[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_l[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE_mu = rtu_I_EMS[1];
  ControlDes_DW.State_DSTATE_f[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE_f[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE_f[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_g[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_d[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_d[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_d[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversionAt_izxof[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_d[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_d[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_d[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE_n = rtu_I_Hems[0];
  ControlDes_DW.State_DSTATE_g[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE_g[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE_g[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_fj[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_i[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_i[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_i[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversionA_izxofb[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_o[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_o[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_o[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE_gq = rtu_I_EMS[2];
  ControlDes_DW.State_DSTATE_fj[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE_fj[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE_fj[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_n[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_n[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_n[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_n[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversion_izxofbo[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_c[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_c[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_c[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE_p = rtu_I_EMS[3];
  ControlDes_DW.State_DSTATE_n[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE_n[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE_n[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_b[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain_h[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain_h[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain_h[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversio_izxofbou[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain_k[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain_k[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain_k[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.UnitDelay_DSTATE_ne = rtu_I_EMS[4];
  ControlDes_DW.State_DSTATE_b[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_B.unnamed_idx_0_l = 0.0;
  ControlDes_DW.State_DSTATE_b[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_B.unnamed_idx_1_j = 0.0;
  ControlDes_DW.State_DSTATE_b[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_B.unnamed_idx_2_d = 0.0;
  tmp = 0;
  for (k = 0; k < 3; k++) {
    ControlDes_B.g_v_idx_1_tmp = ControlDes_DW.State_DSTATE_m[k];
    ControlDes_B.unnamed_idx_0_l += rtCP_A_Gain[tmp] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_1_j += rtCP_A_Gain[tmp + 1] *
      ControlDes_B.g_v_idx_1_tmp;
    ControlDes_B.unnamed_idx_2_d += rtCP_A_Gain[tmp + 2] *
      ControlDes_B.g_v_idx_1_tmp;
    tmp += 3;
  }

  ControlDes_B.g_v_idx_1_tmp = 0.0;
  ControlDes_B.g_v_idx_0_tmp = 0.0;
  ControlDes_B.d13 = 0.0;
  tmp = 0;
  for (k = 0; k < 2; k++) {
    ControlDes_B.d = ControlDes_B.TmpSignalConversi_izxofbouj[k];
    ControlDes_B.g_v_idx_1_tmp += rtCP_B_Gain[tmp] * ControlDes_B.d;
    ControlDes_B.g_v_idx_0_tmp += rtCP_B_Gain[tmp + 1] * ControlDes_B.d;
    ControlDes_B.d13 += rtCP_B_Gain[tmp + 2] * ControlDes_B.d;
    tmp += 3;
  }

  ControlDes_DW.State_DSTATE_m[0] = ControlDes_B.unnamed_idx_0_l +
    ControlDes_B.g_v_idx_1_tmp;
  ControlDes_DW.State_DSTATE_m[1] = ControlDes_B.unnamed_idx_1_j +
    ControlDes_B.g_v_idx_0_tmp;
  ControlDes_DW.State_DSTATE_m[2] = ControlDes_B.unnamed_idx_2_d +
    ControlDes_B.d13;
  ControlDes_DW.UnitDelay_DSTATE_b = rtu_I_EMS[5];
}

const char_T* ControlDes::RT_MODEL_ControlDes_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void ControlDes::RT_MODEL_ControlDes_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** ControlDes::RT_MODEL_ControlDes_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void ControlDes::RT_MODEL_ControlDes_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

ControlDes::ControlDes() :
  ControlDes_B(),
  ControlDes_DW(),
  ControlDes_M()
{
}

ControlDes::~ControlDes() = default;
ControlDes::RT_MODEL_ControlDes_T * ControlDes::getRTM()
{
  return (&ControlDes_M);
}
