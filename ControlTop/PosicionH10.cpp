#include "PosicionH10.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "xnrm2_l2M7eLKH.h"
#include "rt_hypotd.h"
#include "look2_binlcpw.h"
#include "PosicionH10_private.h"

void PosicionH10::PosicionH10_mldivide_l89k28gF(const real_T A[12], const real_T
  B[4], real_T Y[3])
{
  real_T b_B[4];
  real_T tau[3];
  real_T vn1[3];
  real_T vn2[3];
  real_T work[3];
  real_T absxk;
  real_T scale;
  real_T smax;
  real_T t;
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
  std::memcpy(&PosicionH10_B.b_A[0], &A[0], 12U * sizeof(real_T));
  b_B[0] = B[0];
  b_B[1] = B[1];
  b_B[2] = B[2];
  b_B[3] = B[3];
  for (rankA = 0; rankA < 3; rankA++) {
    jpvt[rankA] = static_cast<int8_T>(rankA + 1);
    work[rankA] = 0.0;
    ii = (rankA << 2) + 1;
    smax = 0.0;
    scale = 3.312168642111238E-170;
    for (pvt = ii; pvt <= ii + 3; pvt++) {
      absxk = std::abs(A[pvt - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        smax = smax * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        smax += t * t;
      }
    }

    absxk = scale * std::sqrt(smax);
    vn1[rankA] = absxk;
    vn2[rankA] = absxk;
  }

  for (rankA = 0; rankA < 3; rankA++) {
    ii_tmp = rankA << 2;
    ii = ii_tmp + rankA;
    pvt = 4 - rankA;
    b_ix = 0;
    if (3 - rankA > 1) {
      ix = rankA;
      smax = std::abs(vn1[rankA]);
      for (jy = 2; jy < pvt; jy++) {
        ix++;
        scale = std::abs(vn1[ix]);
        if (scale > smax) {
          b_ix = jy - 1;
          smax = scale;
        }
      }
    }

    pvt = rankA + b_ix;
    if (pvt != rankA) {
      b_ix = pvt << 2;
      smax = PosicionH10_B.b_A[b_ix];
      PosicionH10_B.b_A[b_ix] = PosicionH10_B.b_A[ii_tmp];
      PosicionH10_B.b_A[ii_tmp] = smax;
      smax = PosicionH10_B.b_A[b_ix + 1];
      PosicionH10_B.b_A[b_ix + 1] = PosicionH10_B.b_A[ii_tmp + 1];
      PosicionH10_B.b_A[ii_tmp + 1] = smax;
      smax = PosicionH10_B.b_A[b_ix + 2];
      PosicionH10_B.b_A[b_ix + 2] = PosicionH10_B.b_A[ii_tmp + 2];
      PosicionH10_B.b_A[ii_tmp + 2] = smax;
      smax = PosicionH10_B.b_A[b_ix + 3];
      PosicionH10_B.b_A[b_ix + 3] = PosicionH10_B.b_A[ii_tmp + 3];
      PosicionH10_B.b_A[ii_tmp + 3] = smax;
      b_ix = jpvt[pvt];
      jpvt[pvt] = jpvt[rankA];
      jpvt[rankA] = static_cast<int8_T>(b_ix);
      vn1[pvt] = vn1[rankA];
      vn2[pvt] = vn2[rankA];
    }

    scale = PosicionH10_B.b_A[ii];
    pvt = ii + 2;
    tau[rankA] = 0.0;
    smax = xnrm2_l2M7eLKH(3 - rankA, PosicionH10_B.b_A, ii + 2);
    if (smax != 0.0) {
      smax = rt_hypotd(PosicionH10_B.b_A[ii], smax);
      if (PosicionH10_B.b_A[ii] >= 0.0) {
        smax = -smax;
      }

      if (std::abs(smax) < 1.0020841800044864E-292) {
        b_ix = 0;
        ix = (ii - rankA) + 4;
        do {
          b_ix++;
          for (jy = pvt; jy <= ix; jy++) {
            PosicionH10_B.b_A[jy - 1] *= 9.9792015476736E+291;
          }

          smax *= 9.9792015476736E+291;
          scale *= 9.9792015476736E+291;
        } while ((std::abs(smax) < 1.0020841800044864E-292) && (b_ix < 20));

        smax = rt_hypotd(scale, xnrm2_l2M7eLKH(3 - rankA, PosicionH10_B.b_A, ii
          + 2));
        if (scale >= 0.0) {
          smax = -smax;
        }

        tau[rankA] = (smax - scale) / smax;
        scale = 1.0 / (scale - smax);
        for (jy = pvt; jy <= ix; jy++) {
          PosicionH10_B.b_A[jy - 1] *= scale;
        }

        for (pvt = 0; pvt < b_ix; pvt++) {
          smax *= 1.0020841800044864E-292;
        }

        scale = smax;
      } else {
        tau[rankA] = (smax - PosicionH10_B.b_A[ii]) / smax;
        scale = 1.0 / (PosicionH10_B.b_A[ii] - smax);
        b_ix = (ii - rankA) + 4;
        for (ix = pvt; ix <= b_ix; ix++) {
          PosicionH10_B.b_A[ix - 1] *= scale;
        }

        scale = smax;
      }
    }

    PosicionH10_B.b_A[ii] = scale;
    if (rankA + 1 < 3) {
      smax = PosicionH10_B.b_A[ii];
      PosicionH10_B.b_A[ii] = 1.0;
      if (tau[rankA] != 0.0) {
        pvt = 4 - rankA;
        b_ix = (ii - rankA) + 3;
        while ((pvt > 0) && (PosicionH10_B.b_A[b_ix] == 0.0)) {
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
              if (PosicionH10_B.b_A[jy] != 0.0) {
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
          std::memset(&work[0], 0, static_cast<uint32_T>(b_ix + 1) * sizeof
                      (real_T));
          ix = 0;
          jy = ((b_ix << 2) + ii) + 5;
          for (ii_tmp = ii + 5; ii_tmp <= jy; ii_tmp += 4) {
            scale = 0.0;
            e = ii_tmp + pvt;
            for (ia = ii_tmp; ia < e; ia++) {
              scale += PosicionH10_B.b_A[(ii + ia) - ii_tmp] *
                PosicionH10_B.b_A[ia - 1];
            }

            work[ix] += scale;
            ix++;
          }
        }

        if (-tau[rankA] != 0.0) {
          ix = ii + 5;
          for (ii_tmp = 0; ii_tmp <= b_ix; ii_tmp++) {
            scale = work[ii_tmp];
            if (scale != 0.0) {
              scale *= -tau[rankA];
              e = pvt + ix;
              for (ia = ix; ia < e; ia++) {
                PosicionH10_B.b_A[ia - 1] += PosicionH10_B.b_A[(ii + ia) - ix] *
                  scale;
              }
            }

            ix += 4;
          }
        }
      }

      PosicionH10_B.b_A[ii] = smax;
    }

    for (ii = rankA + 2; ii < 4; ii++) {
      pvt = ((ii - 1) << 2) + rankA;
      absxk = vn1[ii - 1];
      if (absxk != 0.0) {
        smax = std::abs(PosicionH10_B.b_A[pvt]) / absxk;
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        scale = absxk / vn2[ii - 1];
        if (scale * scale * smax <= 1.4901161193847656E-8) {
          absxk = xnrm2_l2M7eLKH(3 - rankA, PosicionH10_B.b_A, pvt + 2);
          vn1[ii - 1] = absxk;
          vn2[ii - 1] = absxk;
        } else {
          vn1[ii - 1] = absxk * std::sqrt(smax);
        }
      }
    }
  }

  rankA = 0;
  smax = 8.881784197001252E-15 * std::abs(PosicionH10_B.b_A[0]);
  while ((rankA < 3) && (std::abs(PosicionH10_B.b_A[(rankA << 2) + rankA]) >
                         smax)) {
    rankA++;
  }

  for (ii = 0; ii < 3; ii++) {
    Y[ii] = 0.0;
    if (tau[ii] != 0.0) {
      smax = b_B[ii];
      for (pvt = ii + 2; pvt < 5; pvt++) {
        smax += PosicionH10_B.b_A[((ii << 2) + pvt) - 1] * b_B[pvt - 1];
      }

      smax *= tau[ii];
      if (smax != 0.0) {
        b_B[ii] -= smax;
        for (pvt = ii + 2; pvt < 5; pvt++) {
          b_B[pvt - 1] -= PosicionH10_B.b_A[((ii << 2) + pvt) - 1] * smax;
        }
      }
    }
  }

  for (ii = 0; ii < rankA; ii++) {
    Y[jpvt[ii] - 1] = b_B[ii];
  }

  for (ii = rankA; ii >= 1; ii--) {
    jpvt_0 = jpvt[ii - 1];
    pvt = (ii - 1) << 2;
    Y[jpvt_0 - 1] /= PosicionH10_B.b_A[(pvt + ii) - 1];
    for (b_ix = 0; b_ix <= ii - 2; b_ix++) {
      ix = jpvt[b_ix] - 1;
      Y[ix] -= PosicionH10_B.b_A[pvt + b_ix] * Y[jpvt_0 - 1];
    }
  }
}

void PosicionH10::PosicionH10_local_add_limited(const real_T Fa[4], const real_T
  step[4], const real_T lower[4], const real_T upper[4], real_T Fa_new[4],
  real_T *alpha)
{
  real_T y;
  if (step[0] > 0.0) {
    y = (upper[0] - Fa[0]) / step[0];
  } else if (step[0] < 0.0) {
    y = (lower[0] - Fa[0]) / step[0];
  } else {
    y = 1.0;
  }

  *alpha = std::fmin(1.0, y);
  if (step[1] > 0.0) {
    y = (upper[1] - Fa[1]) / step[1];
  } else if (step[1] < 0.0) {
    y = (lower[1] - Fa[1]) / step[1];
  } else {
    y = 1.0;
  }

  *alpha = std::fmin(*alpha, y);
  if (step[2] > 0.0) {
    y = (upper[2] - Fa[2]) / step[2];
  } else if (step[2] < 0.0) {
    y = (lower[2] - Fa[2]) / step[2];
  } else {
    y = 1.0;
  }

  *alpha = std::fmin(*alpha, y);
  if (step[3] > 0.0) {
    y = (upper[3] - Fa[3]) / step[3];
  } else if (step[3] < 0.0) {
    y = (lower[3] - Fa[3]) / step[3];
  } else {
    y = 1.0;
  }

  *alpha = std::fmax(0.0, std::fmin(*alpha, y));
  Fa_new[0] = std::fmin(std::fmax(*alpha * step[0] + Fa[0], lower[0]), upper[0]);
  Fa_new[1] = std::fmin(std::fmax(*alpha * step[1] + Fa[1], lower[1]), upper[1]);
  Fa_new[2] = std::fmin(std::fmax(*alpha * step[2] + Fa[2], lower[2]), upper[2]);
  Fa_new[3] = std::fmin(std::fmax(*alpha * step[3] + Fa[3], lower[3]), upper[3]);
}

void PosicionH10::init(void)
{
  PosicionH10_DW.Z_DSTATE[0] = 0.025;
  PosicionH10_DW.Z_DSTATE[1] = 0.0;
  PosicionH10_DW.Z_DSTATE[2] = 9.8;
}

void PosicionH10::step0(void)
{
}

void PosicionH10::step1(const real_T rtu_airgaps_sensores[8], const real_T
  *rtu_RefZ, const real_T rtu_I_HEMS[4], real_T rty_GapsLoclaes[4], real_T
  rty_I_referencia[4], real_T rty_Pos[5], real_T rty_Fe[3], real_T rty_Ef[3],
  real_T rty_P[3], real_T rty_R[3], real_T rty_Zz[3], real_T rty_Ak[4], real_T
  rty_Bk[3])
{
  real_T a[4];
  real_T rtb_TmpSignalConversionAtSFun_f[4];
  real_T rtb_TmpSignalConversionAtSFun_l[4];
  real_T upper[4];
  real_T theta_l[3];
  real_T theta_v[3];
  real_T accumulatedData;
  real_T b_accumulatedData;
  real_T f_x;
  real_T g_v_idx_0;
  real_T g_v_idx_1;
  real_T g_v_idx_1_tmp;
  real_T g_v_idx_2;
  real_T g_v_idx_3;
  real_T rotz;
  real_T rtb_InvLUT_1;
  int32_T i;
  int32_T tmp;
  static const real_T b[12]{ 1.0, 1.0, 1.0, 1.0, -0.305, 0.239, -0.305, 0.239,
    -1.2536, -1.256, 1.2814, 1.279 };

  static const real_T e[12]{ 1.0, 1.0, 1.0, 1.0, -0.134, 0.134, -0.134, 0.134,
    1.005, 1.005, -1.005, -1.005 };

  PosicionH10_B.lower[0] = ((-rtu_airgaps_sensores[0] - 0.015) - 0.032) - -0.157;
  PosicionH10_B.lower[1] = ((-rtu_airgaps_sensores[1] - 0.015) - 0.032) - -0.157;
  PosicionH10_B.lower[2] = ((-rtu_airgaps_sensores[2] - 0.015) - 0.032) - -0.157;
  PosicionH10_B.lower[3] = ((-rtu_airgaps_sensores[3] - 0.015) - 0.032) - -0.157;
  PosicionH10_mldivide_l89k28gF(b, PosicionH10_B.lower, theta_v);
  rotz = std::sin(theta_v[2]);
  b_accumulatedData = std::sin(theta_v[1]);
  g_v_idx_3 = -0.157 * std::cos(theta_v[1]);
  g_v_idx_2 = -0.305 * b_accumulatedData;
  g_v_idx_0 = ((((-rtu_airgaps_sensores[0] - 0.015) - 0.032) - g_v_idx_3) +
               1.2536 * rotz) - g_v_idx_2;
  g_v_idx_1_tmp = 0.239 * b_accumulatedData;
  g_v_idx_1 = ((((-rtu_airgaps_sensores[1] - 0.015) - 0.032) - g_v_idx_3) +
               1.256 * rotz) - g_v_idx_1_tmp;
  g_v_idx_2 = ((((-rtu_airgaps_sensores[2] - 0.015) - 0.032) - g_v_idx_3) +
               -1.2814 * rotz) - g_v_idx_2;
  g_v_idx_3 = ((((-rtu_airgaps_sensores[3] - 0.015) - 0.032) - g_v_idx_3) +
               -1.279 * rotz) - g_v_idx_1_tmp;
  accumulatedData = 0.184 * b_accumulatedData;
  PosicionH10_B.lower[0] = (-0.277 - (-rtu_airgaps_sensores[4])) +
    accumulatedData;
  PosicionH10_B.lower[1] = (0.277 - rtu_airgaps_sensores[5]) + accumulatedData;
  PosicionH10_B.lower[2] = (-0.277 - (-rtu_airgaps_sensores[6])) +
    accumulatedData;
  PosicionH10_B.lower[3] = (0.277 - rtu_airgaps_sensores[7]) + accumulatedData;
  PosicionH10_mldivide_l89k28gF(e, PosicionH10_B.lower, theta_l);
  rotz = std::atan2(theta_l[2], theta_l[1]);
  rtb_InvLUT_1 = std::cos(rotz);
  f_x = std::sin(rotz);
  b_accumulatedData = 1.005 * f_x;
  g_v_idx_1_tmp = -0.134 * rtb_InvLUT_1;
  rtb_InvLUT_1 *= 0.134;
  f_x *= -1.005;
  rty_Pos[0] = (((((-0.277 - (-rtu_airgaps_sensores[4])) - ((g_v_idx_1_tmp +
    b_accumulatedData) - accumulatedData)) + ((0.277 - rtu_airgaps_sensores[5])
    - ((rtb_InvLUT_1 + b_accumulatedData) - accumulatedData))) + ((-0.277 -
    (-rtu_airgaps_sensores[6])) - ((g_v_idx_1_tmp + f_x) - accumulatedData))) +
                ((0.277 - rtu_airgaps_sensores[7]) - ((rtb_InvLUT_1 + f_x) -
    accumulatedData))) / 4.0;
  rty_Pos[1] = (((g_v_idx_0 + g_v_idx_1) + g_v_idx_2) + g_v_idx_3) / 4.0;
  rty_Pos[2] = theta_v[1];
  rty_Pos[3] = theta_v[2];
  rty_Pos[4] = rotz;
  accumulatedData = std::sin(rty_Pos[2]);
  rotz = std::sin(rty_Pos[3]);
  b_accumulatedData = 0.8498 * rotz;
  g_v_idx_1_tmp = -0.3055 * accumulatedData + rty_Pos[1];
  rty_GapsLoclaes[0] = std::abs(g_v_idx_1_tmp - b_accumulatedData);
  rtb_InvLUT_1 = 0.2395 * accumulatedData + rty_Pos[1];
  rty_GapsLoclaes[1] = std::abs(rtb_InvLUT_1 - b_accumulatedData);
  b_accumulatedData = -0.8752 * rotz;
  rty_GapsLoclaes[2] = std::abs(g_v_idx_1_tmp - b_accumulatedData);
  rty_GapsLoclaes[3] = std::abs(rtb_InvLUT_1 - b_accumulatedData);
  g_v_idx_0 = 1000.0 * rty_GapsLoclaes[0];
  g_v_idx_1 = 1000.0 * rty_GapsLoclaes[1];
  g_v_idx_2 = 1000.0 * rty_GapsLoclaes[2];
  g_v_idx_3 = 1000.0 * rty_GapsLoclaes[3];
  b_accumulatedData = look2_binlcpw(g_v_idx_0, rtu_I_HEMS[0],
    rtCP_LUT_HEMS_1_bp01Data, rtCP_LUT_HEMS_1_bp02Data,
    rtCP_LUT_HEMS_1_tableData, rtCP_LUT_HEMS_1_maxIndex, 54U);
  accumulatedData = look2_binlcpw(g_v_idx_1, rtu_I_HEMS[1],
    rtCP_LUT_HEMS_2_bp01Data, rtCP_LUT_HEMS_2_bp02Data,
    rtCP_LUT_HEMS_2_tableData, rtCP_LUT_HEMS_2_maxIndex, 54U);
  rotz = look2_binlcpw(g_v_idx_2, rtu_I_HEMS[2], rtCP_LUT_HEMS_3_bp01Data,
                       rtCP_LUT_HEMS_3_bp02Data, rtCP_LUT_HEMS_3_tableData,
                       rtCP_LUT_HEMS_3_maxIndex, 54U);
  rtb_InvLUT_1 = look2_binlcpw(g_v_idx_3, rtu_I_HEMS[3],
    rtCP_LUT_HEMS_4_bp01Data, rtCP_LUT_HEMS_4_bp02Data,
    rtCP_LUT_HEMS_4_tableData, rtCP_LUT_HEMS_4_maxIndex, 54U);
  rty_Ak[0] = b_accumulatedData;
  rty_Ak[1] = accumulatedData;
  rty_Ak[2] = rotz;
  rty_Ak[3] = rtb_InvLUT_1;
  PosicionH10_B.lower[0] = b_accumulatedData;
  PosicionH10_B.lower[1] = accumulatedData;
  PosicionH10_B.lower[2] = rotz;
  PosicionH10_B.lower[3] = rtb_InvLUT_1;
  rty_Bk[0] = 0.0;
  rty_Bk[1] = 0.0;
  rty_Bk[2] = 0.0;
  rotz = rty_Bk[0];
  g_v_idx_1_tmp = rty_Bk[1];
  accumulatedData = rty_Bk[2];
  tmp = 0;
  for (i = 0; i < 4; i++) {
    b_accumulatedData = PosicionH10_B.lower[i];
    rotz += rtCP_Kin_HEMS_Gain[tmp] * b_accumulatedData;
    g_v_idx_1_tmp += rtCP_Kin_HEMS_Gain[tmp + 1] * b_accumulatedData;
    accumulatedData += rtCP_Kin_HEMS_Gain[tmp + 2] * b_accumulatedData;
    tmp += 3;
  }

  rty_Bk[2] = accumulatedData;
  rty_Bk[1] = g_v_idx_1_tmp;
  rty_Bk[0] = rotz;

  {
    rty_Zz[0] = 0.92859941091974874*PosicionH10_DW.Z_DSTATE[0] +
      0.00046429970545987443*PosicionH10_DW.Z_DSTATE[1]
      + 2.3214985272993714E-7*PosicionH10_DW.Z_DSTATE[2];
    rty_Zz[0] += 0.0714005890802513*rty_Pos[1] + (-8.086431792391477E-10)*
      rty_Bk[0];
    rty_Zz[1] = (-3.5112665225403)*PosicionH10_DW.Z_DSTATE[0] +
      0.99824436673872985*PosicionH10_DW.Z_DSTATE[1]
      + 0.0004991221833693649*PosicionH10_DW.Z_DSTATE[2];
    rty_Zz[1] += 3.5112665225402995*rty_Pos[1] + (-1.7385828353641673E-6)*
      rty_Bk[0];
    rty_Zz[2] = (-58.037463182484288)*PosicionH10_DW.Z_DSTATE[0] +
      (-0.029018731591242145)*PosicionH10_DW.Z_DSTATE[1]
      + 0.99998549063420428*PosicionH10_DW.Z_DSTATE[2];
    rty_Zz[2] += 58.037463182484288*rty_Pos[1] + 5.0540198702446724E-8*rty_Bk[0];
  }

  {
    rty_R[0] = 0.92859941091974874*PosicionH10_DW.Roll_DSTATE[0] +
      0.00046429970545987443*PosicionH10_DW.Roll_DSTATE[1]
      + 2.3214985272993714E-7*PosicionH10_DW.Roll_DSTATE[2];
    rty_R[0] += 0.0714005890802513*rty_Pos[2] + 1.0485032517166441E-8*rty_Bk[1];
    rty_R[1] = (-3.5112665225403)*PosicionH10_DW.Roll_DSTATE[0] +
      0.99824436673872985*PosicionH10_DW.Roll_DSTATE[1]
      + 0.0004991221833693649*PosicionH10_DW.Roll_DSTATE[2];
    rty_R[1] += 3.5112665225402995*rty_Pos[2] + 2.2542819911907847E-5*rty_Bk[1];
    rty_R[2] = (-58.037463182484288)*PosicionH10_DW.Roll_DSTATE[0] +
      (-0.029018731591242145)*PosicionH10_DW.Roll_DSTATE[1]
      + 0.99998549063420428*PosicionH10_DW.Roll_DSTATE[2];
    rty_R[2] += 58.037463182484288*rty_Pos[2] + (-6.553145323229025E-7)*rty_Bk[1];
  }

  {
    rty_P[0] = 0.92859941091974874*PosicionH10_DW.Pitch_DSTATE[0] +
      0.00046429970545987443*PosicionH10_DW.Pitch_DSTATE[1]
      + 2.3214985272993714E-7*PosicionH10_DW.Pitch_DSTATE[2];
    rty_P[0] += 0.0714005890802513*rty_Pos[3] + 1.606127726472755E-9*rty_Bk[2];
    rty_P[1] = (-3.5112665225403)*PosicionH10_DW.Pitch_DSTATE[0] +
      0.99824436673872985*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.0004991221833693649*PosicionH10_DW.Pitch_DSTATE[2];
    rty_P[1] += 3.5112665225402995*rty_Pos[3] + 3.4531746119164229E-6*rty_Bk[2];
    rty_P[2] = (-58.037463182484288)*PosicionH10_DW.Pitch_DSTATE[0] +
      (-0.029018731591242145)*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.99998549063420428*PosicionH10_DW.Pitch_DSTATE[2];
    rty_P[2] += 58.037463182484288*rty_Pos[3] + (-1.0038298290454718E-7)*rty_Bk
      [2];
  }

  rty_Fe[0] = (((*rtu_RefZ - rty_Zz[0]) * 225.0 - 30.0 * rty_Zz[1]) - rty_Zz[2])
    * -287.08565;
  rty_Fe[1] = (((0.0 - rty_R[0]) * 225.0 - 30.0 * rty_R[1]) - rty_R[2]) *
    22.1410713176;
  rty_Fe[2] = (((0.0 - rty_P[0]) * 225.0 - 30.0 * rty_P[1]) - rty_P[2]) *
    144.54009410557;
  accumulatedData = std::abs(look2_binlcpw(g_v_idx_0, -55.0,
    rtCP_LUT_HEMS_2_bp01Data_h, rtCP_LUT_HEMS_2_bp02Data_k,
    rtCP_LUT_HEMS_2_tableData_f, rtCP_LUT_HEMS_2_maxIndex_j, 54U));
  rotz = std::abs(look2_binlcpw(g_v_idx_0, 55.0, rtCP_LUT_HEMS_1_bp01Data_f,
    rtCP_LUT_HEMS_1_bp02Data_a, rtCP_LUT_HEMS_1_tableData_o,
    rtCP_LUT_HEMS_1_maxIndex_p, 54U));
  PosicionH10_B.lower[0] = std::fmin(accumulatedData, rotz);
  upper[0] = std::fmax(accumulatedData, rotz);
  accumulatedData = std::abs(look2_binlcpw(g_v_idx_1, -55.0,
    rtCP_LUT_HEMS_2_bp01Data_m, rtCP_LUT_HEMS_2_bp02Data_b,
    rtCP_LUT_HEMS_2_tableData_b, rtCP_LUT_HEMS_2_maxIndex_p, 54U));
  rotz = std::abs(look2_binlcpw(g_v_idx_1, 55.0, rtCP_LUT_HEMS_1_bp01Data_a,
    rtCP_LUT_HEMS_1_bp02Data_g, rtCP_LUT_HEMS_1_tableData_n,
    rtCP_LUT_HEMS_1_maxIndex_g, 54U));
  PosicionH10_B.lower[1] = std::fmin(accumulatedData, rotz);
  upper[1] = std::fmax(accumulatedData, rotz);
  accumulatedData = std::abs(look2_binlcpw(g_v_idx_2, -55.0,
    rtCP_LUT_HEMS_2_bp01Data_a, rtCP_LUT_HEMS_2_bp02Data_p,
    rtCP_LUT_HEMS_2_tableData_c, rtCP_LUT_HEMS_2_maxIndex_b, 54U));
  rotz = std::abs(look2_binlcpw(g_v_idx_2, 55.0, rtCP_LUT_HEMS_1_bp01Data_av,
    rtCP_LUT_HEMS_1_bp02Data_h, rtCP_LUT_HEMS_1_tableData_c,
    rtCP_LUT_HEMS_1_maxIndex_j, 54U));
  PosicionH10_B.lower[2] = std::fmin(accumulatedData, rotz);
  upper[2] = std::fmax(accumulatedData, rotz);
  accumulatedData = std::abs(look2_binlcpw(g_v_idx_3, -55.0,
    rtCP_LUT_HEMS_2_bp01Data_c, rtCP_LUT_HEMS_2_bp02Data_i,
    rtCP_LUT_HEMS_2_tableData_e, rtCP_LUT_HEMS_2_maxIndex_jh, 54U));
  rotz = std::abs(look2_binlcpw(g_v_idx_3, 55.0, rtCP_LUT_HEMS_1_bp01Data_p,
    rtCP_LUT_HEMS_1_bp02Data_ha, rtCP_LUT_HEMS_1_tableData_p,
    rtCP_LUT_HEMS_1_maxIndex_d, 54U));
  PosicionH10_B.lower[3] = std::fmin(accumulatedData, rotz);
  upper[3] = std::fmax(accumulatedData, rotz);
  rtb_TmpSignalConversionAtSFun_l[0] = 0.0;
  a[0] = 0.22340593006249168 * rty_Fe[0];
  rtb_TmpSignalConversionAtSFun_l[1] = 0.0;
  a[1] = 0.28395638877808804 * rty_Fe[0];
  rtb_TmpSignalConversionAtSFun_l[2] = 0.0;
  a[2] = 0.21604361122191199 * rty_Fe[0];
  rtb_TmpSignalConversionAtSFun_l[3] = 0.0;
  a[3] = 0.27659406993750835 * rty_Fe[0];
  PosicionH10_local_add_limited(rtb_TmpSignalConversionAtSFun_l, a,
    PosicionH10_B.lower, upper, rtb_TmpSignalConversionAtSFun_f,
    &accumulatedData);
  rotz = 0.2898550724637681 * rty_Fe[2];
  a[0] = rotz;
  a[1] = rotz;
  rotz = -0.2898550724637681 * rty_Fe[2];
  a[2] = rotz;
  a[3] = rotz;
  PosicionH10_local_add_limited(rtb_TmpSignalConversionAtSFun_f, a,
    PosicionH10_B.lower, upper, rtb_TmpSignalConversionAtSFun_l,
    &accumulatedData);
  rotz = 0.9174311926605505 * rty_Fe[1];
  rtb_TmpSignalConversionAtSFun_f[0] = rotz;
  b_accumulatedData = -0.9174311926605505 * rty_Fe[1];
  rtb_TmpSignalConversionAtSFun_f[1] = b_accumulatedData;
  rtb_TmpSignalConversionAtSFun_f[2] = rotz;
  rtb_TmpSignalConversionAtSFun_f[3] = b_accumulatedData;
  PosicionH10_local_add_limited(rtb_TmpSignalConversionAtSFun_l,
    rtb_TmpSignalConversionAtSFun_f, PosicionH10_B.lower, upper, a,
    &accumulatedData);
  g_v_idx_0 = look2_binlcpw(g_v_idx_0, std::fmin(std::fmax(a[0],
    PosicionH10_B.lower[0]), upper[0]), rtCP_InvLUT_1_bp01Data,
    rtCP_InvLUT_1_bp02Data, rtCP_InvLUT_1_tableData, rtCP_InvLUT_1_maxIndex, 54U);
  g_v_idx_1 = look2_binlcpw(g_v_idx_1, std::fmin(std::fmax(a[1],
    PosicionH10_B.lower[1]), upper[1]), rtCP_InvLUT_2_bp01Data,
    rtCP_InvLUT_2_bp02Data, rtCP_InvLUT_2_tableData, rtCP_InvLUT_2_maxIndex, 54U);
  g_v_idx_2 = look2_binlcpw(g_v_idx_2, std::fmin(std::fmax(a[2],
    PosicionH10_B.lower[2]), upper[2]), rtCP_InvLUT_3_bp01Data,
    rtCP_InvLUT_3_bp02Data, rtCP_InvLUT_3_tableData, rtCP_InvLUT_3_maxIndex, 54U);
  g_v_idx_3 = look2_binlcpw(g_v_idx_3, std::fmin(std::fmax(a[3],
    PosicionH10_B.lower[3]), upper[3]), rtCP_InvLUT_4_bp01Data,
    rtCP_InvLUT_4_bp02Data, rtCP_InvLUT_4_tableData, rtCP_InvLUT_4_maxIndex, 54U);
  if (g_v_idx_0 > 55.0) {
    rty_I_referencia[0] = 55.0;
  } else if (g_v_idx_0 < -55.0) {
    rty_I_referencia[0] = -55.0;
  } else {
    rty_I_referencia[0] = g_v_idx_0;
  }

  if (g_v_idx_1 > 55.0) {
    rty_I_referencia[1] = 55.0;
  } else if (g_v_idx_1 < -55.0) {
    rty_I_referencia[1] = -55.0;
  } else {
    rty_I_referencia[1] = g_v_idx_1;
  }

  if (g_v_idx_2 > 55.0) {
    rty_I_referencia[2] = 55.0;
  } else if (g_v_idx_2 < -55.0) {
    rty_I_referencia[2] = -55.0;
  } else {
    rty_I_referencia[2] = g_v_idx_2;
  }

  if (g_v_idx_3 > 55.0) {
    rty_I_referencia[3] = 55.0;
  } else if (g_v_idx_3 < -55.0) {
    rty_I_referencia[3] = -55.0;
  } else {
    rty_I_referencia[3] = g_v_idx_3;
  }

  rty_Ef[0] = rty_Bk[0];
  rty_Ef[1] = rty_Bk[1];
  rty_Ef[2] = rty_Bk[2];

  {
    real_T xnew[3];
    xnew[0] = 0.85719882183949758*PosicionH10_DW.Z_DSTATE[0] +
      0.00092859941091974875*PosicionH10_DW.Z_DSTATE[1]
      + 4.6429970545987424E-7*PosicionH10_DW.Z_DSTATE[2];
    xnew[0] += 0.14280117816050261*rty_Pos[1] + (-1.6172863584782954E-9)*rty_Bk
      [0];
    xnew[1] = (-7.0225330450806)*PosicionH10_DW.Z_DSTATE[0] +
      0.99648873347745981*PosicionH10_DW.Z_DSTATE[1]
      + 0.00099824436673872957*PosicionH10_DW.Z_DSTATE[2];
    xnew[1] += 7.0225330450805989*rty_Pos[1] + (-3.4771656707283345E-6)*rty_Bk[0];
    xnew[2] = (-116.07492636496859)*PosicionH10_DW.Z_DSTATE[0] +
      (-0.058037463182484296)*PosicionH10_DW.Z_DSTATE[1]
      + 0.99997098126840867*PosicionH10_DW.Z_DSTATE[2];
    xnew[2] += 116.07492636496858*rty_Pos[1] + 1.0108039740489345E-7*rty_Bk[0];
    (void) std::memcpy(PosicionH10_DW.Z_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  {
    real_T xnew[3];
    xnew[0] = 0.85719882183949758*PosicionH10_DW.Roll_DSTATE[0] +
      0.00092859941091974875*PosicionH10_DW.Roll_DSTATE[1]
      + 4.6429970545987424E-7*PosicionH10_DW.Roll_DSTATE[2];
    xnew[0] += 0.14280117816050261*rty_Pos[2] + 2.0970065034332882E-8*rty_Bk[1];
    xnew[1] = (-7.0225330450806)*PosicionH10_DW.Roll_DSTATE[0] +
      0.99648873347745981*PosicionH10_DW.Roll_DSTATE[1]
      + 0.00099824436673872957*PosicionH10_DW.Roll_DSTATE[2];
    xnew[1] += 7.0225330450805989*rty_Pos[2] + 4.5085639823815694E-5*rty_Bk[1];
    xnew[2] = (-116.07492636496859)*PosicionH10_DW.Roll_DSTATE[0] +
      (-0.058037463182484296)*PosicionH10_DW.Roll_DSTATE[1]
      + 0.99997098126840867*PosicionH10_DW.Roll_DSTATE[2];
    xnew[2] += 116.07492636496858*rty_Pos[2] + (-1.310629064645805E-6)*rty_Bk[1];
    (void) std::memcpy(PosicionH10_DW.Roll_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  {
    real_T xnew[3];
    xnew[0] = 0.85719882183949758*PosicionH10_DW.Pitch_DSTATE[0] +
      0.00092859941091974875*PosicionH10_DW.Pitch_DSTATE[1]
      + 4.6429970545987424E-7*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[0] += 0.14280117816050261*rty_Pos[3] + 3.21225545294551E-9*rty_Bk[2];
    xnew[1] = (-7.0225330450806)*PosicionH10_DW.Pitch_DSTATE[0] +
      0.99648873347745981*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.00099824436673872957*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[1] += 7.0225330450805989*rty_Pos[3] + 6.9063492238328458E-6*rty_Bk[2];
    xnew[2] = (-116.07492636496859)*PosicionH10_DW.Pitch_DSTATE[0] +
      (-0.058037463182484296)*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.99997098126840867*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[2] += 116.07492636496858*rty_Pos[3] + (-2.0076596580909436E-7)*rty_Bk[2];
    (void) std::memcpy(PosicionH10_DW.Pitch_DSTATE, xnew,
                       sizeof(real_T)*3);
  }
}

const char_T* PosicionH10::RT_MODEL_PosicionH10_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void PosicionH10::RT_MODEL_PosicionH10_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** PosicionH10::RT_MODEL_PosicionH10_T::getErrorStatusPointer()
  const
{
  return errorStatus;
}

void PosicionH10::RT_MODEL_PosicionH10_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

PosicionH10::PosicionH10() :
  PosicionH10_B(),
  PosicionH10_DW(),
  PosicionH10_M()
{
}

PosicionH10::~PosicionH10() = default;
PosicionH10::RT_MODEL_PosicionH10_T * PosicionH10::getRTM()
{
  return (&PosicionH10_M);
}
