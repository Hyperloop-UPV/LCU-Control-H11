#include "CONTROLH10_1.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "rt_hypotd.h"
#include "look2_binlcpw.h"
#include "CONTROLH10_1_private.h"
#include "ControlDeCorrienteH10REF.h"

real_T CONTROLH10_1::CONTROLH10_1_xnrm2_l2M7eLKH(int32_T n, const real_T x[12],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      int32_T kend;
      CONTROLH10_1_B.scale_c = 3.312168642111238E-170;
      kend = ix0 + n;
      for (int32_T k{ix0}; k < kend; k++) {
        CONTROLH10_1_B.absxk_b = std::abs(x[k - 1]);
        if (CONTROLH10_1_B.absxk_b > CONTROLH10_1_B.scale_c) {
          real_T t;
          t = CONTROLH10_1_B.scale_c / CONTROLH10_1_B.absxk_b;
          y = y * t * t + 1.0;
          CONTROLH10_1_B.scale_c = CONTROLH10_1_B.absxk_b;
        } else {
          real_T t;
          t = CONTROLH10_1_B.absxk_b / CONTROLH10_1_B.scale_c;
          y += t * t;
        }
      }

      y = CONTROLH10_1_B.scale_c * std::sqrt(y);
    }
  }

  return y;
}

void CONTROLH10_1::CONTROLH10_1_mldivide_l89k28gF(const real_T A[12], const
  real_T B[4], real_T Y[3])
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
  std::memcpy(&CONTROLH10_1_B.b_A[0], &A[0], 12U * sizeof(real_T));
  CONTROLH10_1_B.b_B[0] = B[0];
  CONTROLH10_1_B.b_B[1] = B[1];
  CONTROLH10_1_B.b_B[2] = B[2];
  CONTROLH10_1_B.b_B[3] = B[3];
  for (rankA = 0; rankA < 3; rankA++) {
    jpvt[rankA] = static_cast<int8_T>(rankA + 1);
    CONTROLH10_1_B.work[rankA] = 0.0;
    ii = (rankA << 2) + 1;
    CONTROLH10_1_B.smax = 0.0;
    CONTROLH10_1_B.scale = 3.312168642111238E-170;
    for (pvt = ii; pvt <= ii + 3; pvt++) {
      CONTROLH10_1_B.absxk = std::abs(A[pvt - 1]);
      if (CONTROLH10_1_B.absxk > CONTROLH10_1_B.scale) {
        CONTROLH10_1_B.t = CONTROLH10_1_B.scale / CONTROLH10_1_B.absxk;
        CONTROLH10_1_B.smax = CONTROLH10_1_B.smax * CONTROLH10_1_B.t *
          CONTROLH10_1_B.t + 1.0;
        CONTROLH10_1_B.scale = CONTROLH10_1_B.absxk;
      } else {
        CONTROLH10_1_B.t = CONTROLH10_1_B.absxk / CONTROLH10_1_B.scale;
        CONTROLH10_1_B.smax += CONTROLH10_1_B.t * CONTROLH10_1_B.t;
      }
    }

    CONTROLH10_1_B.absxk = CONTROLH10_1_B.scale * std::sqrt(CONTROLH10_1_B.smax);
    CONTROLH10_1_B.vn1[rankA] = CONTROLH10_1_B.absxk;
    CONTROLH10_1_B.vn2[rankA] = CONTROLH10_1_B.absxk;
  }

  for (rankA = 0; rankA < 3; rankA++) {
    ii_tmp = rankA << 2;
    ii = ii_tmp + rankA;
    pvt = 4 - rankA;
    b_ix = 0;
    if (3 - rankA > 1) {
      ix = rankA;
      CONTROLH10_1_B.smax = std::abs(CONTROLH10_1_B.vn1[rankA]);
      for (jy = 2; jy < pvt; jy++) {
        ix++;
        CONTROLH10_1_B.scale = std::abs(CONTROLH10_1_B.vn1[ix]);
        if (CONTROLH10_1_B.scale > CONTROLH10_1_B.smax) {
          b_ix = jy - 1;
          CONTROLH10_1_B.smax = CONTROLH10_1_B.scale;
        }
      }
    }

    pvt = rankA + b_ix;
    if (pvt != rankA) {
      b_ix = pvt << 2;
      CONTROLH10_1_B.smax = CONTROLH10_1_B.b_A[b_ix];
      CONTROLH10_1_B.b_A[b_ix] = CONTROLH10_1_B.b_A[ii_tmp];
      CONTROLH10_1_B.b_A[ii_tmp] = CONTROLH10_1_B.smax;
      CONTROLH10_1_B.smax = CONTROLH10_1_B.b_A[b_ix + 1];
      CONTROLH10_1_B.b_A[b_ix + 1] = CONTROLH10_1_B.b_A[ii_tmp + 1];
      CONTROLH10_1_B.b_A[ii_tmp + 1] = CONTROLH10_1_B.smax;
      CONTROLH10_1_B.smax = CONTROLH10_1_B.b_A[b_ix + 2];
      CONTROLH10_1_B.b_A[b_ix + 2] = CONTROLH10_1_B.b_A[ii_tmp + 2];
      CONTROLH10_1_B.b_A[ii_tmp + 2] = CONTROLH10_1_B.smax;
      CONTROLH10_1_B.smax = CONTROLH10_1_B.b_A[b_ix + 3];
      CONTROLH10_1_B.b_A[b_ix + 3] = CONTROLH10_1_B.b_A[ii_tmp + 3];
      CONTROLH10_1_B.b_A[ii_tmp + 3] = CONTROLH10_1_B.smax;
      b_ix = jpvt[pvt];
      jpvt[pvt] = jpvt[rankA];
      jpvt[rankA] = static_cast<int8_T>(b_ix);
      CONTROLH10_1_B.vn1[pvt] = CONTROLH10_1_B.vn1[rankA];
      CONTROLH10_1_B.vn2[pvt] = CONTROLH10_1_B.vn2[rankA];
    }

    CONTROLH10_1_B.scale = CONTROLH10_1_B.b_A[ii];
    pvt = ii + 2;
    CONTROLH10_1_B.tau[rankA] = 0.0;
    CONTROLH10_1_B.smax = CONTROLH10_1_xnrm2_l2M7eLKH(3 - rankA,
      CONTROLH10_1_B.b_A, ii + 2);
    if (CONTROLH10_1_B.smax != 0.0) {
      CONTROLH10_1_B.smax = rt_hypotd(CONTROLH10_1_B.b_A[ii],
        CONTROLH10_1_B.smax);
      if (CONTROLH10_1_B.b_A[ii] >= 0.0) {
        CONTROLH10_1_B.smax = -CONTROLH10_1_B.smax;
      }

      if (std::abs(CONTROLH10_1_B.smax) < 1.0020841800044864E-292) {
        b_ix = 0;
        ix = (ii - rankA) + 4;
        do {
          b_ix++;
          for (jy = pvt; jy <= ix; jy++) {
            CONTROLH10_1_B.b_A[jy - 1] *= 9.9792015476736E+291;
          }

          CONTROLH10_1_B.smax *= 9.9792015476736E+291;
          CONTROLH10_1_B.scale *= 9.9792015476736E+291;
        } while ((std::abs(CONTROLH10_1_B.smax) < 1.0020841800044864E-292) &&
                 (b_ix < 20));

        CONTROLH10_1_B.smax = rt_hypotd(CONTROLH10_1_B.scale,
          CONTROLH10_1_xnrm2_l2M7eLKH(3 - rankA, CONTROLH10_1_B.b_A, ii + 2));
        if (CONTROLH10_1_B.scale >= 0.0) {
          CONTROLH10_1_B.smax = -CONTROLH10_1_B.smax;
        }

        CONTROLH10_1_B.tau[rankA] = (CONTROLH10_1_B.smax - CONTROLH10_1_B.scale)
          / CONTROLH10_1_B.smax;
        CONTROLH10_1_B.scale = 1.0 / (CONTROLH10_1_B.scale - CONTROLH10_1_B.smax);
        for (jy = pvt; jy <= ix; jy++) {
          CONTROLH10_1_B.b_A[jy - 1] *= CONTROLH10_1_B.scale;
        }

        for (pvt = 0; pvt < b_ix; pvt++) {
          CONTROLH10_1_B.smax *= 1.0020841800044864E-292;
        }

        CONTROLH10_1_B.scale = CONTROLH10_1_B.smax;
      } else {
        CONTROLH10_1_B.tau[rankA] = (CONTROLH10_1_B.smax - CONTROLH10_1_B.b_A[ii])
          / CONTROLH10_1_B.smax;
        CONTROLH10_1_B.scale = 1.0 / (CONTROLH10_1_B.b_A[ii] -
          CONTROLH10_1_B.smax);
        b_ix = (ii - rankA) + 4;
        for (ix = pvt; ix <= b_ix; ix++) {
          CONTROLH10_1_B.b_A[ix - 1] *= CONTROLH10_1_B.scale;
        }

        CONTROLH10_1_B.scale = CONTROLH10_1_B.smax;
      }
    }

    CONTROLH10_1_B.b_A[ii] = CONTROLH10_1_B.scale;
    if (rankA + 1 < 3) {
      CONTROLH10_1_B.smax = CONTROLH10_1_B.b_A[ii];
      CONTROLH10_1_B.b_A[ii] = 1.0;
      if (CONTROLH10_1_B.tau[rankA] != 0.0) {
        pvt = 4 - rankA;
        b_ix = (ii - rankA) + 3;
        while ((pvt > 0) && (CONTROLH10_1_B.b_A[b_ix] == 0.0)) {
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
              if (CONTROLH10_1_B.b_A[jy] != 0.0) {
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
          std::memset(&CONTROLH10_1_B.work[0], 0, static_cast<uint32_T>(b_ix + 1)
                      * sizeof(real_T));
          ix = 0;
          jy = ((b_ix << 2) + ii) + 5;
          for (ii_tmp = ii + 5; ii_tmp <= jy; ii_tmp += 4) {
            CONTROLH10_1_B.scale = 0.0;
            e = ii_tmp + pvt;
            for (ia = ii_tmp; ia < e; ia++) {
              CONTROLH10_1_B.scale += CONTROLH10_1_B.b_A[(ii + ia) - ii_tmp] *
                CONTROLH10_1_B.b_A[ia - 1];
            }

            CONTROLH10_1_B.work[ix] += CONTROLH10_1_B.scale;
            ix++;
          }
        }

        if (-CONTROLH10_1_B.tau[rankA] != 0.0) {
          ix = ii + 5;
          for (ii_tmp = 0; ii_tmp <= b_ix; ii_tmp++) {
            CONTROLH10_1_B.scale = CONTROLH10_1_B.work[ii_tmp];
            if (CONTROLH10_1_B.scale != 0.0) {
              CONTROLH10_1_B.scale *= -CONTROLH10_1_B.tau[rankA];
              e = pvt + ix;
              for (ia = ix; ia < e; ia++) {
                CONTROLH10_1_B.b_A[ia - 1] += CONTROLH10_1_B.b_A[(ii + ia) - ix]
                  * CONTROLH10_1_B.scale;
              }
            }

            ix += 4;
          }
        }
      }

      CONTROLH10_1_B.b_A[ii] = CONTROLH10_1_B.smax;
    }

    for (ii = rankA + 2; ii < 4; ii++) {
      pvt = ((ii - 1) << 2) + rankA;
      CONTROLH10_1_B.absxk = CONTROLH10_1_B.vn1[ii - 1];
      if (CONTROLH10_1_B.absxk != 0.0) {
        CONTROLH10_1_B.smax = std::abs(CONTROLH10_1_B.b_A[pvt]) /
          CONTROLH10_1_B.absxk;
        CONTROLH10_1_B.smax = 1.0 - CONTROLH10_1_B.smax * CONTROLH10_1_B.smax;
        if (CONTROLH10_1_B.smax < 0.0) {
          CONTROLH10_1_B.smax = 0.0;
        }

        CONTROLH10_1_B.scale = CONTROLH10_1_B.absxk / CONTROLH10_1_B.vn2[ii - 1];
        if (CONTROLH10_1_B.scale * CONTROLH10_1_B.scale * CONTROLH10_1_B.smax <=
            1.4901161193847656E-8) {
          CONTROLH10_1_B.absxk = CONTROLH10_1_xnrm2_l2M7eLKH(3 - rankA,
            CONTROLH10_1_B.b_A, pvt + 2);
          CONTROLH10_1_B.vn1[ii - 1] = CONTROLH10_1_B.absxk;
          CONTROLH10_1_B.vn2[ii - 1] = CONTROLH10_1_B.absxk;
        } else {
          CONTROLH10_1_B.vn1[ii - 1] = CONTROLH10_1_B.absxk * std::sqrt
            (CONTROLH10_1_B.smax);
        }
      }
    }
  }

  rankA = 0;
  CONTROLH10_1_B.smax = 8.881784197001252E-15 * std::abs(CONTROLH10_1_B.b_A[0]);
  while ((rankA < 3) && (std::abs(CONTROLH10_1_B.b_A[(rankA << 2) + rankA]) >
                         CONTROLH10_1_B.smax)) {
    rankA++;
  }

  for (ii = 0; ii < 3; ii++) {
    Y[ii] = 0.0;
    if (CONTROLH10_1_B.tau[ii] != 0.0) {
      CONTROLH10_1_B.smax = CONTROLH10_1_B.b_B[ii];
      for (pvt = ii + 2; pvt < 5; pvt++) {
        CONTROLH10_1_B.smax += CONTROLH10_1_B.b_A[((ii << 2) + pvt) - 1] *
          CONTROLH10_1_B.b_B[pvt - 1];
      }

      CONTROLH10_1_B.smax *= CONTROLH10_1_B.tau[ii];
      if (CONTROLH10_1_B.smax != 0.0) {
        CONTROLH10_1_B.b_B[ii] -= CONTROLH10_1_B.smax;
        for (pvt = ii + 2; pvt < 5; pvt++) {
          CONTROLH10_1_B.b_B[pvt - 1] -= CONTROLH10_1_B.b_A[((ii << 2) + pvt) -
            1] * CONTROLH10_1_B.smax;
        }
      }
    }
  }

  for (ii = 0; ii < rankA; ii++) {
    Y[jpvt[ii] - 1] = CONTROLH10_1_B.b_B[ii];
  }

  for (ii = rankA; ii >= 1; ii--) {
    jpvt_0 = jpvt[ii - 1];
    pvt = (ii - 1) << 2;
    Y[jpvt_0 - 1] /= CONTROLH10_1_B.b_A[(pvt + ii) - 1];
    for (b_ix = 0; b_ix <= ii - 2; b_ix++) {
      ix = jpvt[b_ix] - 1;
      Y[ix] -= CONTROLH10_1_B.b_A[pvt + b_ix] * Y[jpvt_0 - 1];
    }
  }
}

void CONTROLH10_1::step0()
{
  int32_T i;
  (&CONTROLH10_1_M)->Timing.RateInteraction.b_TID0_1 = ((&CONTROLH10_1_M)
    ->Timing.RateInteraction.TID0_1 == 0);
  ((&CONTROLH10_1_M)->Timing.RateInteraction.TID0_1)++;
  if (((&CONTROLH10_1_M)->Timing.RateInteraction.TID0_1) > 1) {
    (&CONTROLH10_1_M)->Timing.RateInteraction.TID0_1 = 0;
  }

  if ((&CONTROLH10_1_M)->Timing.RateInteraction.TID0_1 == 1) {
    CONTROLH10_1_B.RT1[0] = CONTROLH10_1_DW.RT1_Buffer0[0];
    CONTROLH10_1_B.RT1[1] = CONTROLH10_1_DW.RT1_Buffer0[1];
    CONTROLH10_1_B.RT1[2] = CONTROLH10_1_DW.RT1_Buffer0[2];
    CONTROLH10_1_B.RT1[3] = CONTROLH10_1_DW.RT1_Buffer0[3];
  }

  if (CONTROLH10_1_U.ManualLevitacin >= 0.5) {
    CONTROLH10_1_B.Switch[0] = CONTROLH10_1_B.RT1[0];
    CONTROLH10_1_B.Switch[1] = CONTROLH10_1_B.RT1[1];
    CONTROLH10_1_B.Switch[2] = CONTROLH10_1_B.RT1[2];
    CONTROLH10_1_B.Switch[3] = CONTROLH10_1_B.RT1[3];
  } else {
    CONTROLH10_1_B.Switch[0] = CONTROLH10_1_U.CorrienteManual;
    CONTROLH10_1_B.Switch[1] = CONTROLH10_1_U.CorrienteManual;
    CONTROLH10_1_B.Switch[2] = CONTROLH10_1_U.CorrienteManual;
    CONTROLH10_1_B.Switch[3] = CONTROLH10_1_U.CorrienteManual;
  }

  ControlDeCorrienteMDLOBJ1.step(&CONTROLH10_1_B.Switch[0],
    &CONTROLH10_1_U.I_HEMS[0], &CONTROLH10_1_B.ControlDeCorriente[0]);
  CONTROLH10_1_Y.V[0] = CONTROLH10_1_B.ControlDeCorriente[0];
  CONTROLH10_1_Y.V[1] = CONTROLH10_1_B.ControlDeCorriente[1];
  CONTROLH10_1_Y.V[2] = CONTROLH10_1_B.ControlDeCorriente[2];
  CONTROLH10_1_Y.V[3] = CONTROLH10_1_B.ControlDeCorriente[3];
  for (i = 0; i < 6; i++) {
    CONTROLH10_1_Y.V[i + 4] = 0.0;
  }

  if ((&CONTROLH10_1_M)->Timing.RateInteraction.TID0_1 == 1) {
    CONTROLH10_1_DW.RT_Buffer[0] = CONTROLH10_1_U.I_HEMS[0];
    CONTROLH10_1_DW.RT_Buffer[1] = CONTROLH10_1_U.I_HEMS[1];
    CONTROLH10_1_DW.RT_Buffer[2] = CONTROLH10_1_U.I_HEMS[2];
    CONTROLH10_1_DW.RT_Buffer[3] = CONTROLH10_1_U.I_HEMS[3];
  }
}

void CONTROLH10_1::step1()
{
  int32_T i;
  static const real_T b[12]{ 1.0, 1.0, 1.0, 1.0, -0.31417, 0.24811, -0.31417,
    0.24811, -1.24708, -1.24946, 1.27493, 1.27253 };

  CONTROLH10_1_B.dv[0] = 0.11965 - CONTROLH10_1_U.Sensores[0];
  CONTROLH10_1_B.dv[1] = 0.11965 - CONTROLH10_1_U.Sensores[1];
  CONTROLH10_1_B.dv[2] = 0.11965 - CONTROLH10_1_U.Sensores[2];
  CONTROLH10_1_B.dv[3] = 0.11965 - CONTROLH10_1_U.Sensores[3];
  CONTROLH10_1_mldivide_l89k28gF(b, CONTROLH10_1_B.dv, CONTROLH10_1_B.q);
  CONTROLH10_1_B.rotx = std::asin(std::fmin(1.0, std::fmax(-1.0,
    CONTROLH10_1_B.q[1])));
  CONTROLH10_1_B.rotz = (std::asin(std::fmin(1.0, std::fmax(-1.0,
    (CONTROLH10_1_U.Sensores[4] - CONTROLH10_1_U.Sensores[6]) / 2.55205))) + std::
    asin(std::fmin(1.0, std::fmax(-1.0, (CONTROLH10_1_U.Sensores[7] -
    CONTROLH10_1_U.Sensores[5]) / 2.55205)))) / 2.0;
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_1 = std::sin(CONTROLH10_1_B.rotx);
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_0 = 0.2877 * std::cos
    (CONTROLH10_1_B.rotz);
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2 = 1.276025 * std::sin
    (CONTROLH10_1_B.rotz);
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3 = 0.186484 *
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_1;
  CONTROLH10_1_B.estados[0] = (((((((CONTROLH10_1_U.Sensores[4] - 0.3592) +
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_0) -
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2) +
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3) + ((((-CONTROLH10_1_U.Sensores
    [5] + 0.3592) - CONTROLH10_1_B.rtb_airgaps_actuadores_idx_0) -
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2) +
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3)) + ((((CONTROLH10_1_U.Sensores
    [6] - 0.3592) + CONTROLH10_1_B.rtb_airgaps_actuadores_idx_0) +
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2) +
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3)) +
    ((((-CONTROLH10_1_U.Sensores[7] + 0.3592) -
       CONTROLH10_1_B.rtb_airgaps_actuadores_idx_0) +
      CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2) +
     CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3)) / 4.0;
  CONTROLH10_1_B.estados[1] = CONTROLH10_1_B.q[0];
  CONTROLH10_1_B.estados[2] = CONTROLH10_1_B.rotx;
  CONTROLH10_1_B.estados[3] = std::asin(std::fmin(1.0, std::fmax(-1.0,
    CONTROLH10_1_B.q[2])));
  CONTROLH10_1_B.estados[4] = CONTROLH10_1_B.rotz;
  CONTROLH10_1_B.rotz = std::sin(CONTROLH10_1_B.estados[3]);
  CONTROLH10_1_B.rotx = 0.76978 * CONTROLH10_1_B.rotz;
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2 = CONTROLH10_1_B.q[0] - 0.28958 *
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_1;
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_0 = std::abs
    (CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2 - CONTROLH10_1_B.rotx);
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3 = 0.22351 *
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_1 + CONTROLH10_1_B.q[0];
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_1 = std::abs
    (CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3 - CONTROLH10_1_B.rotx);
  CONTROLH10_1_B.rotz *= 0.79522;
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2 = std::abs
    (CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2 + CONTROLH10_1_B.rotz);
  CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3 = std::abs
    (CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3 + CONTROLH10_1_B.rotz);
  CONTROLH10_1_B.q[0] = CONTROLH10_1_DW.uz_DSTATE[0];
  CONTROLH10_1_B.q[1] = CONTROLH10_1_DW.uz_DSTATE[1];
  CONTROLH10_1_B.q[2] = CONTROLH10_1_DW.uz_DSTATE[2];

  {
    CONTROLH10_1_B.Kin_HEMS[0] = 0.93542732052003519*CONTROLH10_1_DW.Z_DSTATE[0]
      + 0.00046771366026001764*CONTROLH10_1_DW.Z_DSTATE[1]
      + 2.338568301300088E-7*CONTROLH10_1_DW.Z_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[0] += 0.064572679479964978*CONTROLH10_1_B.estados[1]
      + (-8.1458906124360063E-10)*CONTROLH10_1_DW.uz_DSTATE[0];
    CONTROLH10_1_B.Kin_HEMS[1] = (-2.8626706897252041)*CONTROLH10_1_DW.Z_DSTATE
      [0] + 0.99856866465513749*CONTROLH10_1_DW.Z_DSTATE[1]
      + 0.00049928433232756869*CONTROLH10_1_DW.Z_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[1] += 2.8626706897252037*CONTROLH10_1_B.estados[1] +
      (-1.7391476457550868E-6)*CONTROLH10_1_DW.uz_DSTATE[0];
    CONTROLH10_1_B.Kin_HEMS[2] = (-42.620407291194113)*CONTROLH10_1_DW.Z_DSTATE
      [0] + (-0.021310203645597058)*CONTROLH10_1_DW.Z_DSTATE[1]
      + 0.99998934489817737*CONTROLH10_1_DW.Z_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[2] += 42.620407291194105*CONTROLH10_1_B.estados[1] +
      3.7114714102911558E-8*CONTROLH10_1_DW.uz_DSTATE[0];
  }

  CONTROLH10_1_B.rotx = (((CONTROLH10_1_U.RefZ - CONTROLH10_1_B.Kin_HEMS[0]) *
    400.0 - 40.0 * CONTROLH10_1_B.Kin_HEMS[1]) - CONTROLH10_1_B.Kin_HEMS[2]) *
    -287.08565;

  {
    CONTROLH10_1_B.Kin_HEMS[0] = 0.93542732052003519*
      CONTROLH10_1_DW.Roll_DSTATE[0] + 0.00046771366026001764*
      CONTROLH10_1_DW.Roll_DSTATE[1]
      + 2.338568301300088E-7*CONTROLH10_1_DW.Roll_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[0] += 0.064572679479964978*CONTROLH10_1_B.estados[2]
      + (-1.6179374420443038E-9)*CONTROLH10_1_DW.uz_DSTATE[1];
    CONTROLH10_1_B.Kin_HEMS[1] = (-2.8626706897252041)*
      CONTROLH10_1_DW.Roll_DSTATE[0] + 0.99856866465513749*
      CONTROLH10_1_DW.Roll_DSTATE[1]
      + 0.00049928433232756869*CONTROLH10_1_DW.Roll_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[1] += 2.8626706897252037*CONTROLH10_1_B.estados[2] +
      (-3.4542964387645875E-6)*CONTROLH10_1_DW.uz_DSTATE[1];
    CONTROLH10_1_B.Kin_HEMS[2] = (-42.620407291194113)*
      CONTROLH10_1_DW.Roll_DSTATE[0] + (-0.021310203645597058)*
      CONTROLH10_1_DW.Roll_DSTATE[1]
      + 0.99998934489817737*CONTROLH10_1_DW.Roll_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[2] += 42.620407291194105*CONTROLH10_1_B.estados[2] +
      7.37172747031436E-8*CONTROLH10_1_DW.uz_DSTATE[1];
  }

  CONTROLH10_1_B.rotz = (((0.0 - CONTROLH10_1_B.Kin_HEMS[0]) * 400.0 - 40.0 *
    CONTROLH10_1_B.Kin_HEMS[1]) - CONTROLH10_1_B.Kin_HEMS[2]) * -144.54009410557;

  {
    CONTROLH10_1_B.Kin_HEMS[0] = 0.93542732052003519*
      CONTROLH10_1_DW.Pitch_DSTATE[0] + 0.00046771366026001764*
      CONTROLH10_1_DW.Pitch_DSTATE[1]
      + 2.338568301300088E-7*CONTROLH10_1_DW.Pitch_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[0] += 0.064572679479964978*CONTROLH10_1_B.estados[3]
      + (-1.4881389511319672E-9)*CONTROLH10_1_DW.uz_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[1] = (-2.8626706897252041)*
      CONTROLH10_1_DW.Pitch_DSTATE[0] + 0.99856866465513749*
      CONTROLH10_1_DW.Pitch_DSTATE[1]
      + 0.00049928433232756869*CONTROLH10_1_DW.Pitch_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[1] += 2.8626706897252037*CONTROLH10_1_B.estados[3] +
      (-3.1771766606667491E-6)*CONTROLH10_1_DW.uz_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[2] = (-42.620407291194113)*
      CONTROLH10_1_DW.Pitch_DSTATE[0] + (-0.021310203645597058)*
      CONTROLH10_1_DW.Pitch_DSTATE[1]
      + 0.99998934489817737*CONTROLH10_1_DW.Pitch_DSTATE[2];
    CONTROLH10_1_B.Kin_HEMS[2] += 42.620407291194105*CONTROLH10_1_B.estados[3] +
      6.7803330960950284E-8*CONTROLH10_1_DW.uz_DSTATE[2];
  }

  CONTROLH10_1_B.rtb_Kin_HEMS_m = CONTROLH10_1_B.Kin_HEMS[0];
  CONTROLH10_1_B.rtb_Kin_HEMS_c = CONTROLH10_1_B.Kin_HEMS[1];
  CONTROLH10_1_B.rtb_Kin_HEMS_k = CONTROLH10_1_B.Kin_HEMS[2];
  CONTROLH10_1_B.Kin_HEMS[2] = (((0.0 - CONTROLH10_1_B.rtb_Kin_HEMS_m) * 400.0 -
    40.0 * CONTROLH10_1_B.rtb_Kin_HEMS_c) - CONTROLH10_1_B.rtb_Kin_HEMS_k) *
    -157.14717362389;
  CONTROLH10_1_B.unnamed_idx_0_tmp = 1000.0 *
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_0;
  CONTROLH10_1_B.rtb_Kin_HEMS_tmp = 0.3194888178913738 *
    CONTROLH10_1_B.Kin_HEMS[2];
  CONTROLH10_1_B.rtb_Kin_HEMS_k = 0.9744879066050791 * CONTROLH10_1_B.rotz;
  CONTROLH10_1_B.rtb_Kin_HEMS_m = look2_binlcpw(CONTROLH10_1_B.unnamed_idx_0_tmp,
    (-0.2218716897688795 * CONTROLH10_1_B.rotx + CONTROLH10_1_B.rtb_Kin_HEMS_k)
    + CONTROLH10_1_B.rtb_Kin_HEMS_tmp, rtCP_InvLUT_1_bp01Data,
    rtCP_InvLUT_1_bp02Data, rtCP_InvLUT_1_tableData, rtCP_InvLUT_1_maxIndex, 54U);
  CONTROLH10_1_B.unnamed_idx_1_tmp = 1000.0 *
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_1;
  CONTROLH10_1_B.rotz *= -0.9744879066050791;
  CONTROLH10_1_B.rtb_Kin_HEMS_c = look2_binlcpw(CONTROLH10_1_B.unnamed_idx_1_tmp,
    (-0.2862561057582771 * CONTROLH10_1_B.rotx + CONTROLH10_1_B.rotz) +
    CONTROLH10_1_B.rtb_Kin_HEMS_tmp, rtCP_InvLUT_2_bp01Data,
    rtCP_InvLUT_2_bp02Data, rtCP_InvLUT_2_tableData, rtCP_InvLUT_2_maxIndex, 54U);
  CONTROLH10_1_B.unnamed_idx_2_tmp = 1000.0 *
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2;
  CONTROLH10_1_B.rtb_Kin_HEMS_tmp = -0.3194888178913738 *
    CONTROLH10_1_B.Kin_HEMS[2];
  CONTROLH10_1_B.rtb_Kin_HEMS_k = look2_binlcpw(CONTROLH10_1_B.unnamed_idx_2_tmp,
    (-0.21374389424172294 * CONTROLH10_1_B.rotx + CONTROLH10_1_B.rtb_Kin_HEMS_k)
    + CONTROLH10_1_B.rtb_Kin_HEMS_tmp, rtCP_InvLUT_3_bp01Data,
    rtCP_InvLUT_3_bp02Data, rtCP_InvLUT_3_tableData, rtCP_InvLUT_3_maxIndex, 54U);
  CONTROLH10_1_B.unnamed_idx_3_tmp = 1000.0 *
    CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3;
  CONTROLH10_1_B.rotz = look2_binlcpw(CONTROLH10_1_B.unnamed_idx_3_tmp,
    (-0.2781283102311205 * CONTROLH10_1_B.rotx + CONTROLH10_1_B.rotz) +
    CONTROLH10_1_B.rtb_Kin_HEMS_tmp, rtCP_InvLUT_4_bp01Data,
    rtCP_InvLUT_4_bp02Data, rtCP_InvLUT_4_tableData, rtCP_InvLUT_4_maxIndex, 54U);
  CONTROLH10_1_B.rotx = look2_binlcpw(CONTROLH10_1_B.unnamed_idx_0_tmp,
    CONTROLH10_1_DW.RT_Buffer[0], rtCP_LUT_HEMS_1_bp01Data,
    rtCP_LUT_HEMS_1_bp02Data, rtCP_LUT_HEMS_1_tableData,
    rtCP_LUT_HEMS_1_maxIndex, 54U);
  CONTROLH10_1_B.unnamed_idx_1_tmp = look2_binlcpw
    (CONTROLH10_1_B.unnamed_idx_1_tmp, CONTROLH10_1_DW.RT_Buffer[1],
     rtCP_LUT_HEMS_2_bp01Data, rtCP_LUT_HEMS_2_bp02Data,
     rtCP_LUT_HEMS_2_tableData, rtCP_LUT_HEMS_2_maxIndex, 54U);
  CONTROLH10_1_B.unnamed_idx_2_tmp = look2_binlcpw
    (CONTROLH10_1_B.unnamed_idx_2_tmp, CONTROLH10_1_DW.RT_Buffer[2],
     rtCP_LUT_HEMS_3_bp01Data, rtCP_LUT_HEMS_3_bp02Data,
     rtCP_LUT_HEMS_3_tableData, rtCP_LUT_HEMS_3_maxIndex, 54U);
  CONTROLH10_1_B.unnamed_idx_3_tmp = look2_binlcpw
    (CONTROLH10_1_B.unnamed_idx_3_tmp, CONTROLH10_1_DW.RT_Buffer[3],
     rtCP_LUT_HEMS_4_bp01Data, rtCP_LUT_HEMS_4_bp02Data,
     rtCP_LUT_HEMS_4_tableData, rtCP_LUT_HEMS_4_maxIndex, 54U);
  for (i = 0; i < 3; i++) {
    CONTROLH10_1_DW.uz_DSTATE[i] = ((rtCP_Kin_HEMS_Gain[i + 3] *
      CONTROLH10_1_B.unnamed_idx_1_tmp + rtCP_Kin_HEMS_Gain[i] *
      CONTROLH10_1_B.rotx) + rtCP_Kin_HEMS_Gain[i + 6] *
      CONTROLH10_1_B.unnamed_idx_2_tmp) + rtCP_Kin_HEMS_Gain[i + 9] *
      CONTROLH10_1_B.unnamed_idx_3_tmp;
  }

  {
    real_T xnew[3];
    xnew[0] = 0.87085464104007027*CONTROLH10_1_DW.Z_DSTATE[0] +
      0.00093542732052003539*CONTROLH10_1_DW.Z_DSTATE[1]
      + 4.6771366026001761E-7*CONTROLH10_1_DW.Z_DSTATE[2];
    xnew[0] += 0.12914535895992996*CONTROLH10_1_B.estados[1] +
      (-1.6291781224872013E-9)*CONTROLH10_1_B.q[0];
    xnew[1] = (-5.7253413794504073)*CONTROLH10_1_DW.Z_DSTATE[0] +
      0.99713732931027488*CONTROLH10_1_DW.Z_DSTATE[1]
      + 0.00099856866465513738*CONTROLH10_1_DW.Z_DSTATE[2];
    xnew[1] += 5.7253413794504073*CONTROLH10_1_B.estados[1] +
      (-3.4782952915101736E-6)*CONTROLH10_1_B.q[0];
    xnew[2] = (-85.240814582388225)*CONTROLH10_1_DW.Z_DSTATE[0] +
      (-0.042620407291194116)*CONTROLH10_1_DW.Z_DSTATE[1]
      + 0.99997868979635451*CONTROLH10_1_DW.Z_DSTATE[2];
    xnew[2] += 85.240814582388211*CONTROLH10_1_B.estados[1] +
      7.4229428205823117E-8*CONTROLH10_1_B.q[0];
    (void) std::memcpy(CONTROLH10_1_DW.Z_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  {
    real_T xnew[3];
    xnew[0] = 0.87085464104007027*CONTROLH10_1_DW.Roll_DSTATE[0] +
      0.00093542732052003539*CONTROLH10_1_DW.Roll_DSTATE[1]
      + 4.6771366026001761E-7*CONTROLH10_1_DW.Roll_DSTATE[2];
    xnew[0] += 0.12914535895992996*CONTROLH10_1_B.estados[2] +
      (-3.2358748840886075E-9)*CONTROLH10_1_B.q[1];
    xnew[1] = (-5.7253413794504073)*CONTROLH10_1_DW.Roll_DSTATE[0] +
      0.99713732931027488*CONTROLH10_1_DW.Roll_DSTATE[1]
      + 0.00099856866465513738*CONTROLH10_1_DW.Roll_DSTATE[2];
    xnew[1] += 5.7253413794504073*CONTROLH10_1_B.estados[2] +
      (-6.9085928775291751E-6)*CONTROLH10_1_B.q[1];
    xnew[2] = (-85.240814582388225)*CONTROLH10_1_DW.Roll_DSTATE[0] +
      (-0.042620407291194116)*CONTROLH10_1_DW.Roll_DSTATE[1]
      + 0.99997868979635451*CONTROLH10_1_DW.Roll_DSTATE[2];
    xnew[2] += 85.240814582388211*CONTROLH10_1_B.estados[2] +
      1.4743454940628719E-7*CONTROLH10_1_B.q[1];
    (void) std::memcpy(CONTROLH10_1_DW.Roll_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  {
    real_T xnew[3];
    xnew[0] = 0.87085464104007027*CONTROLH10_1_DW.Pitch_DSTATE[0] +
      0.00093542732052003539*CONTROLH10_1_DW.Pitch_DSTATE[1]
      + 4.6771366026001761E-7*CONTROLH10_1_DW.Pitch_DSTATE[2];
    xnew[0] += 0.12914535895992996*CONTROLH10_1_B.estados[3] +
      (-2.9762779022639343E-9)*CONTROLH10_1_B.q[2];
    xnew[1] = (-5.7253413794504073)*CONTROLH10_1_DW.Pitch_DSTATE[0] +
      0.99713732931027488*CONTROLH10_1_DW.Pitch_DSTATE[1]
      + 0.00099856866465513738*CONTROLH10_1_DW.Pitch_DSTATE[2];
    xnew[1] += 5.7253413794504073*CONTROLH10_1_B.estados[3] +
      (-6.3543533213334981E-6)*CONTROLH10_1_B.q[2];
    xnew[2] = (-85.240814582388225)*CONTROLH10_1_DW.Pitch_DSTATE[0] +
      (-0.042620407291194116)*CONTROLH10_1_DW.Pitch_DSTATE[1]
      + 0.99997868979635451*CONTROLH10_1_DW.Pitch_DSTATE[2];
    xnew[2] += 85.240814582388211*CONTROLH10_1_B.estados[3] +
      1.3560666192190057E-7*CONTROLH10_1_B.q[2];
    (void) std::memcpy(CONTROLH10_1_DW.Pitch_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  for (i = 0; i < 5; i++) {
    CONTROLH10_1_Y.Estados[i] = CONTROLH10_1_B.estados[i];
  }

  CONTROLH10_1_Y.GapsLoclaes[0] = CONTROLH10_1_B.rtb_airgaps_actuadores_idx_0;
  if (CONTROLH10_1_B.rtb_Kin_HEMS_m > 55.0) {
    CONTROLH10_1_DW.RT1_Buffer0[0] = 55.0;
  } else if (CONTROLH10_1_B.rtb_Kin_HEMS_m < -55.0) {
    CONTROLH10_1_DW.RT1_Buffer0[0] = -55.0;
  } else {
    CONTROLH10_1_DW.RT1_Buffer0[0] = CONTROLH10_1_B.rtb_Kin_HEMS_m;
  }

  CONTROLH10_1_Y.GapsLoclaes[1] = CONTROLH10_1_B.rtb_airgaps_actuadores_idx_1;
  if (CONTROLH10_1_B.rtb_Kin_HEMS_c > 55.0) {
    CONTROLH10_1_DW.RT1_Buffer0[1] = 55.0;
  } else if (CONTROLH10_1_B.rtb_Kin_HEMS_c < -55.0) {
    CONTROLH10_1_DW.RT1_Buffer0[1] = -55.0;
  } else {
    CONTROLH10_1_DW.RT1_Buffer0[1] = CONTROLH10_1_B.rtb_Kin_HEMS_c;
  }

  CONTROLH10_1_Y.GapsLoclaes[2] = CONTROLH10_1_B.rtb_airgaps_actuadores_idx_2;
  if (CONTROLH10_1_B.rtb_Kin_HEMS_k > 55.0) {
    CONTROLH10_1_DW.RT1_Buffer0[2] = 55.0;
  } else if (CONTROLH10_1_B.rtb_Kin_HEMS_k < -55.0) {
    CONTROLH10_1_DW.RT1_Buffer0[2] = -55.0;
  } else {
    CONTROLH10_1_DW.RT1_Buffer0[2] = CONTROLH10_1_B.rtb_Kin_HEMS_k;
  }

  CONTROLH10_1_Y.GapsLoclaes[3] = CONTROLH10_1_B.rtb_airgaps_actuadores_idx_3;
  if (CONTROLH10_1_B.rotz > 55.0) {
    CONTROLH10_1_DW.RT1_Buffer0[3] = 55.0;
  } else if (CONTROLH10_1_B.rotz < -55.0) {
    CONTROLH10_1_DW.RT1_Buffer0[3] = -55.0;
  } else {
    CONTROLH10_1_DW.RT1_Buffer0[3] = CONTROLH10_1_B.rotz;
  }
}

void CONTROLH10_1::initialize()
{
  ((&CONTROLH10_1_M))->Timing.TaskCounters.cLimit[0] = 1;
  ((&CONTROLH10_1_M))->Timing.TaskCounters.cLimit[1] = 2;
  ControlDeCorrienteMDLOBJ1.getRTM()->setErrorStatusPointer((&CONTROLH10_1_M)
    ->getErrorStatusPointer());
  CONTROLH10_1_DW.Z_DSTATE[0] = 0.025;
  CONTROLH10_1_DW.Z_DSTATE[1] = 0.0;
  CONTROLH10_1_DW.Z_DSTATE[2] = 9.8;
}

void CONTROLH10_1::terminate()
{
}

boolean_T CONTROLH10_1::RT_MODEL_CONTROLH10_1_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

uint32_T &CONTROLH10_1::RT_MODEL_CONTROLH10_1_T::CounterLimit(int32_T idx)
{
  return (Timing.TaskCounters.cLimit[(idx)]);
}

const char_T* CONTROLH10_1::RT_MODEL_CONTROLH10_1_T::getErrorStatus() const
{
  return (errorStatus);
}

void CONTROLH10_1::RT_MODEL_CONTROLH10_1_T::setErrorStatus(const char_T* const
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

uint32_T &CONTROLH10_1::RT_MODEL_CONTROLH10_1_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

const char_T** CONTROLH10_1::RT_MODEL_CONTROLH10_1_T::getErrorStatusPointer()
{
  return &errorStatus;
}

CONTROLH10_1::CONTROLH10_1() :
  CONTROLH10_1_U(),
  CONTROLH10_1_Y(),
  CONTROLH10_1_B(),
  CONTROLH10_1_DW(),
  CONTROLH10_1_M()
{
}

CONTROLH10_1::~CONTROLH10_1() = default;
CONTROLH10_1::RT_MODEL_CONTROLH10_1_T * CONTROLH10_1::getRTM()
{
  return (&CONTROLH10_1_M);
}
