#include "PosicionH10.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "xnrm2_l2M7eLKH.h"
#include "rt_hypotd.h"
#include "plook_binc.h"
#include "intrp2d_l_pw.h"
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
  PosicionH10_DW.Z_DSTATE[2] = 0.0;
}

void PosicionH10::step0(void)
{
}

void PosicionH10::step1(const real_T rtu_airgaps_sensores[8], const real_T
  *rtu_RefZ, const real_T rtu_I_HEMS[4], real_T rty_GapsLoclaes[4], real_T
  rty_I_referencia[4], real_T rty_Pos[5], real_T rty_Fe[3], real_T rty_Fa[4],
  real_T rty_Ef[3], real_T rty_P[3], real_T rty_R[3], real_T rty_Zz[3], real_T
  rty_Fe_L[3], real_T rty_Ak[4], real_T rty_Bk[3])
{
  real_T a[4];
  real_T rtb_LUT_HEMS_1[4];
  real_T rtb_LUT_HEMS_2[4];
  real_T theta_l[3];
  real_T theta_v[3];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T accumulatedData;
  real_T b_accumulatedData;
  real_T b_accumulatedData_tmp;
  real_T f_x;
  real_T g_v_idx_0;
  real_T g_v_idx_1;
  real_T g_v_idx_2;
  real_T g_v_idx_3;
  real_T rotz;
  real_T rtb_InvLUT_1;
  int32_T i;
  int32_T tmp;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  static const real_T b[12]{ 1.0, 1.0, 1.0, 1.0, -0.305, 0.239, -0.305, 0.239,
    -1.2536, -1.256, 1.2814, 1.279 };

  static const real_T e[12]{ 1.0, 1.0, 1.0, 1.0, -0.134, 0.134, -0.134, 0.134,
    1.005, 1.005, -1.005, -1.005 };

  static const real_T d_a[12]{ -1.0, 0.3055, 0.8498, -1.0, -0.2395, 0.8498, -1.0,
    0.3055, -0.8752, -1.0, -0.2395, -0.8752 };

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
  rtb_InvLUT_1 = 0.239 * b_accumulatedData;
  g_v_idx_1 = ((((-rtu_airgaps_sensores[1] - 0.015) - 0.032) - g_v_idx_3) +
               1.256 * rotz) - rtb_InvLUT_1;
  g_v_idx_2 = ((((-rtu_airgaps_sensores[2] - 0.015) - 0.032) - g_v_idx_3) +
               -1.2814 * rotz) - g_v_idx_2;
  g_v_idx_3 = ((((-rtu_airgaps_sensores[3] - 0.015) - 0.032) - g_v_idx_3) +
               -1.279 * rotz) - rtb_InvLUT_1;
  b_accumulatedData *= 0.184;
  PosicionH10_B.lower[0] = (-0.277 - (-rtu_airgaps_sensores[4])) +
    b_accumulatedData;
  PosicionH10_B.lower[1] = (0.277 - rtu_airgaps_sensores[5]) + b_accumulatedData;
  PosicionH10_B.lower[2] = (-0.277 - (-rtu_airgaps_sensores[6])) +
    b_accumulatedData;
  PosicionH10_B.lower[3] = (0.277 - rtu_airgaps_sensores[7]) + b_accumulatedData;
  PosicionH10_mldivide_l89k28gF(e, PosicionH10_B.lower, theta_l);
  rotz = std::atan2(theta_l[2], theta_l[1]);
  rtb_InvLUT_1 = std::cos(rotz);
  f_x = std::sin(rotz);
  accumulatedData = 1.005 * f_x;
  b_accumulatedData_tmp = -0.134 * rtb_InvLUT_1;
  rtb_InvLUT_1 *= 0.134;
  f_x *= -1.005;
  rty_Pos[0] = (((((-0.277 - (-rtu_airgaps_sensores[4])) -
                   ((b_accumulatedData_tmp + accumulatedData) -
                    b_accumulatedData)) + ((0.277 - rtu_airgaps_sensores[5]) -
    ((rtb_InvLUT_1 + accumulatedData) - b_accumulatedData))) + ((-0.277 -
    (-rtu_airgaps_sensores[6])) - ((b_accumulatedData_tmp + f_x) -
    b_accumulatedData))) + ((0.277 - rtu_airgaps_sensores[7]) - ((rtb_InvLUT_1 +
    f_x) - b_accumulatedData))) / 4.0;
  rty_Pos[1] = (((g_v_idx_0 + g_v_idx_1) + g_v_idx_2) + g_v_idx_3) / 4.0;
  rty_Pos[2] = theta_v[1];
  rty_Pos[3] = theta_v[2];
  rty_Pos[4] = rotz;
  accumulatedData = std::sin(rty_Pos[2]);
  rotz = std::sin(rty_Pos[3]);
  b_accumulatedData = 0.8498 * rotz;
  g_v_idx_1 = rty_Pos[1] - -0.3055 * accumulatedData;
  rty_GapsLoclaes[0] = std::abs(g_v_idx_1 + b_accumulatedData);
  g_v_idx_2 = rty_Pos[1] - 0.2395 * accumulatedData;
  rty_GapsLoclaes[1] = std::abs(g_v_idx_2 + b_accumulatedData);
  b_accumulatedData = -0.8752 * rotz;
  rty_GapsLoclaes[2] = std::abs(g_v_idx_1 + b_accumulatedData);
  rty_GapsLoclaes[3] = std::abs(g_v_idx_2 + b_accumulatedData);
  g_v_idx_0 = 1000.0 * rty_GapsLoclaes[0];
  g_v_idx_1 = 1000.0 * rty_GapsLoclaes[1];
  g_v_idx_2 = 1000.0 * rty_GapsLoclaes[2];
  g_v_idx_3 = 1000.0 * rty_GapsLoclaes[3];
  bpIndices[1U] = plook_binc(55.0, rtCP_LUT_HEMS_1_bp02Data, 110U,
    &b_accumulatedData);
  fractions[1U] = b_accumulatedData;
  bpIndices[0U] = plook_binc(g_v_idx_0, rtCP_LUT_HEMS_1_bp01Data, 53U,
    &b_accumulatedData);
  fractions[0U] = b_accumulatedData;
  rtb_LUT_HEMS_1[0] = intrp2d_l_pw(bpIndices, fractions,
    rtCP_LUT_HEMS_1_tableData, 54U);
  bpIndices[0U] = plook_binc(g_v_idx_1, rtCP_LUT_HEMS_1_bp01Data, 53U,
    &b_accumulatedData);
  fractions[0U] = b_accumulatedData;
  rtb_LUT_HEMS_1[1] = intrp2d_l_pw(bpIndices, fractions,
    rtCP_LUT_HEMS_1_tableData, 54U);
  bpIndices[0U] = plook_binc(g_v_idx_2, rtCP_LUT_HEMS_1_bp01Data, 53U,
    &b_accumulatedData);
  fractions[0U] = b_accumulatedData;
  rtb_LUT_HEMS_1[2] = intrp2d_l_pw(bpIndices, fractions,
    rtCP_LUT_HEMS_1_tableData, 54U);
  bpIndices[0U] = plook_binc(g_v_idx_3, rtCP_LUT_HEMS_1_bp01Data, 53U,
    &b_accumulatedData);
  fractions[0U] = b_accumulatedData;
  rtb_LUT_HEMS_1[3] = intrp2d_l_pw(bpIndices, fractions,
    rtCP_LUT_HEMS_1_tableData, 54U);
  rty_Ef[0] = PosicionH10_DW.uz_DSTATE[0];
  rty_Ef[1] = PosicionH10_DW.uz_DSTATE[1];
  rty_Ef[2] = PosicionH10_DW.uz_DSTATE[2];

  {
    rty_Zz[0] = 0.87629660405490917*PosicionH10_DW.Z_DSTATE[0] +
      0.000438148302027456*PosicionH10_DW.Z_DSTATE[1]
      + 2.1907415101372875E-7*PosicionH10_DW.Z_DSTATE[2];
    rty_Zz[0] += 0.12370339594509094*rty_Pos[1] + (-7.6309683543475108E-10)*
      rty_Ef[0];
    rty_Zz[1] = (-10.806708795356153)*PosicionH10_DW.Z_DSTATE[0] +
      0.99459664560232186*PosicionH10_DW.Z_DSTATE[1]
      + 0.00049729832280116109*PosicionH10_DW.Z_DSTATE[2];
    rty_Zz[1] += 10.806708795356153*rty_Pos[1] + (-1.7322298164368753E-6)*
      rty_Ef[0];
    rty_Zz[2] = (-319.41011217801451)*PosicionH10_DW.Z_DSTATE[0] +
      (-0.15970505608900332)*PosicionH10_DW.Z_DSTATE[1]
      + 0.99992014747195579*PosicionH10_DW.Z_DSTATE[2];
    rty_Zz[2] += 319.41011217801446*rty_Pos[1] + 2.7814879651595886E-7*rty_Ef[0];
  }

  {
    rty_R[0] = 0.87629660405490917*PosicionH10_DW.Roll_DSTATE[0] +
      0.000438148302027456*PosicionH10_DW.Roll_DSTATE[1]
      + 2.1907415101372875E-7*PosicionH10_DW.Roll_DSTATE[2];
    rty_R[0] += 0.12370339594509094*rty_Pos[2] + (-1.5156635421429937E-9)*
      rty_Ef[1];
    rty_R[1] = (-10.806708795356153)*PosicionH10_DW.Roll_DSTATE[0] +
      0.99459664560232186*PosicionH10_DW.Roll_DSTATE[1]
      + 0.00049729832280116109*PosicionH10_DW.Roll_DSTATE[2];
    rty_R[1] += 10.806708795356153*rty_Pos[2] + (-3.4405562406645552E-6)*rty_Ef
      [1];
    rty_R[2] = (-319.41011217801451)*PosicionH10_DW.Roll_DSTATE[0] +
      (-0.15970505608900332)*PosicionH10_DW.Roll_DSTATE[1]
      + 0.99992014747195579*PosicionH10_DW.Roll_DSTATE[2];
    rty_R[2] += 319.41011217801446*rty_Pos[2] + 5.52459361111114E-7*rty_Ef[1];
  }

  {
    rty_P[0] = 0.90194270566802215*PosicionH10_DW.Pitch_DSTATE[0] +
      0.00045097135283401124*PosicionH10_DW.Pitch_DSTATE[1]
      + 2.2548567641700562E-7*PosicionH10_DW.Pitch_DSTATE[2];
    rty_P[0] += 0.098057294331977823*rty_Pos[3] + (-1.018404544127756E-8)*
      rty_Ef[2];
    rty_P[1] = (-6.7066204736709976)*PosicionH10_DW.Pitch_DSTATE[0] +
      0.99664668976316451*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.00049832334488158223*PosicionH10_DW.Pitch_DSTATE[2];
    rty_P[1] += 6.7066204736709958*rty_Pos[3] + (-2.2506740425223403E-5)*rty_Ef
      [2];
    rty_P[2] = (-154.68317402206583)*PosicionH10_DW.Pitch_DSTATE[0] +
      (-0.077341587011032914)*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.9999613292064945*PosicionH10_DW.Pitch_DSTATE[2];
    rty_P[2] += 154.68317402206583*rty_Pos[3] + 1.7465637931791013E-6*rty_Ef[2];
  }

  bpIndices_0[1U] = plook_binc(-55.0, rtCP_LUT_HEMS_2_bp02Data, 110U,
    &b_accumulatedData);
  fractions_0[1U] = b_accumulatedData;
  bpIndices_0[0U] = plook_binc(g_v_idx_0, rtCP_LUT_HEMS_2_bp01Data, 53U,
    &b_accumulatedData);
  fractions_0[0U] = b_accumulatedData;
  rtb_LUT_HEMS_2[0] = intrp2d_l_pw(bpIndices_0, fractions_0,
    rtCP_LUT_HEMS_2_tableData, 54U);
  bpIndices_0[0U] = plook_binc(g_v_idx_1, rtCP_LUT_HEMS_2_bp01Data, 53U,
    &b_accumulatedData);
  fractions_0[0U] = b_accumulatedData;
  rtb_LUT_HEMS_2[1] = intrp2d_l_pw(bpIndices_0, fractions_0,
    rtCP_LUT_HEMS_2_tableData, 54U);
  bpIndices_0[0U] = plook_binc(g_v_idx_2, rtCP_LUT_HEMS_2_bp01Data, 53U,
    &b_accumulatedData);
  fractions_0[0U] = b_accumulatedData;
  rtb_LUT_HEMS_2[2] = intrp2d_l_pw(bpIndices_0, fractions_0,
    rtCP_LUT_HEMS_2_tableData, 54U);
  bpIndices_0[0U] = plook_binc(g_v_idx_3, rtCP_LUT_HEMS_2_bp01Data, 53U,
    &b_accumulatedData);
  fractions_0[0U] = b_accumulatedData;
  rtb_LUT_HEMS_2[3] = intrp2d_l_pw(bpIndices_0, fractions_0,
    rtCP_LUT_HEMS_2_tableData, 54U);
  rty_Fe[0] = (((*rtu_RefZ - rty_Zz[0]) * 900.0 - 60.0 * rty_Zz[1]) - rty_Zz[2])
    * -287.08565;
  rty_Fe[1] = (((0.0 - rty_R[0]) * 900.0 - 60.0 * rty_R[1]) - rty_R[2]) *
    -144.54009410557;
  rty_Fe[2] = (((0.0 - rty_P[0]) * 900.0 - 60.0 * rty_P[1]) - rty_P[2]) *
    -22.1410713176;
  rotz = std::fmin(rtb_LUT_HEMS_1[0], rtb_LUT_HEMS_2[0]);
  PosicionH10_B.lower[0] = rotz;
  rtb_InvLUT_1 = std::fmax(rtb_LUT_HEMS_1[0], rtb_LUT_HEMS_2[0]);
  PosicionH10_B.upper[0] = rtb_InvLUT_1;
  rtb_LUT_HEMS_1[0] = std::fmin(std::fmax(-629.1804054957391, rotz),
    rtb_InvLUT_1);
  a[0] = -0.22340593006249168 * rty_Fe[0];
  rotz = std::fmin(rtb_LUT_HEMS_1[1], rtb_LUT_HEMS_2[1]);
  PosicionH10_B.lower[1] = rotz;
  rtb_InvLUT_1 = std::fmax(rtb_LUT_HEMS_1[1], rtb_LUT_HEMS_2[1]);
  PosicionH10_B.upper[1] = rtb_InvLUT_1;
  rtb_LUT_HEMS_1[1] = std::fmin(std::fmax(-799.7092815957393, rotz),
    rtb_InvLUT_1);
  a[1] = -0.28395638877808804 * rty_Fe[0];
  rotz = std::fmin(rtb_LUT_HEMS_1[2], rtb_LUT_HEMS_2[2]);
  PosicionH10_B.lower[2] = rotz;
  rtb_InvLUT_1 = std::fmax(rtb_LUT_HEMS_1[2], rtb_LUT_HEMS_2[2]);
  PosicionH10_B.upper[2] = rtb_InvLUT_1;
  rtb_LUT_HEMS_1[2] = std::fmin(std::fmax(-608.4458316542609, rotz),
    rtb_InvLUT_1);
  a[2] = -0.21604361122191199 * rty_Fe[0];
  rotz = std::fmin(rtb_LUT_HEMS_1[3], rtb_LUT_HEMS_2[3]);
  PosicionH10_B.lower[3] = rotz;
  rtb_InvLUT_1 = std::fmax(rtb_LUT_HEMS_1[3], rtb_LUT_HEMS_2[3]);
  PosicionH10_B.upper[3] = rtb_InvLUT_1;
  rtb_LUT_HEMS_1[3] = std::fmin(std::fmax(-778.9747077542611, rotz),
    rtb_InvLUT_1);
  a[3] = -0.27659406993750835 * rty_Fe[0];
  PosicionH10_local_add_limited(rtb_LUT_HEMS_1, a, PosicionH10_B.lower,
    PosicionH10_B.upper, rty_Fa, &b_accumulatedData);
  b_accumulatedData = 0.2898550724637681 * rty_Fe[2];
  rtb_LUT_HEMS_2[0] = b_accumulatedData;
  rtb_LUT_HEMS_2[1] = b_accumulatedData;
  b_accumulatedData = -0.2898550724637681 * rty_Fe[2];
  rtb_LUT_HEMS_2[2] = b_accumulatedData;
  rtb_LUT_HEMS_2[3] = b_accumulatedData;
  PosicionH10_local_add_limited(rty_Fa, rtb_LUT_HEMS_2, PosicionH10_B.lower,
    PosicionH10_B.upper, rtb_LUT_HEMS_1, &b_accumulatedData);
  b_accumulatedData = 0.9174311926605505 * rty_Fe[1];
  a[0] = b_accumulatedData;
  accumulatedData = -0.9174311926605505 * rty_Fe[1];
  a[1] = accumulatedData;
  a[2] = b_accumulatedData;
  a[3] = accumulatedData;
  PosicionH10_local_add_limited(rtb_LUT_HEMS_1, a, PosicionH10_B.lower,
    PosicionH10_B.upper, rtb_LUT_HEMS_2, &b_accumulatedData);
  rty_Fa[0] = std::fmin(std::fmax(rtb_LUT_HEMS_2[0], PosicionH10_B.lower[0]),
                        PosicionH10_B.upper[0]);
  rty_Fa[1] = std::fmin(std::fmax(rtb_LUT_HEMS_2[1], PosicionH10_B.lower[1]),
                        PosicionH10_B.upper[1]);
  rty_Fa[2] = std::fmin(std::fmax(rtb_LUT_HEMS_2[2], PosicionH10_B.lower[2]),
                        PosicionH10_B.upper[2]);
  rty_Fa[3] = std::fmin(std::fmax(rtb_LUT_HEMS_2[3], rotz), rtb_InvLUT_1);
  rtb_LUT_HEMS_1[0] = rty_Fa[0] - -629.1804054957391;
  rtb_LUT_HEMS_1[1] = rty_Fa[1] - -799.7092815957393;
  rtb_LUT_HEMS_1[2] = rty_Fa[2] - -608.4458316542609;
  rtb_LUT_HEMS_1[3] = rty_Fa[3] - -778.9747077542611;
  rotz = 0.0;
  rtb_InvLUT_1 = 0.0;
  accumulatedData = 0.0;
  tmp = 0;
  for (i = 0; i < 4; i++) {
    b_accumulatedData = rtb_LUT_HEMS_1[i];
    rotz += d_a[tmp] * b_accumulatedData;
    rtb_InvLUT_1 += d_a[tmp + 1] * b_accumulatedData;
    accumulatedData += d_a[tmp + 2] * b_accumulatedData;
    tmp += 3;
  }

  rty_Fe_L[0] = rotz;
  rty_Fe_L[1] = rtb_InvLUT_1;
  rty_Fe_L[2] = accumulatedData;
  b_accumulatedData = look2_binlcpw(g_v_idx_0, rtu_I_HEMS[0],
    rtCP_LUT_HEMS_1_bp01Data_k, rtCP_LUT_HEMS_1_bp02Data_g,
    rtCP_LUT_HEMS_1_tableData_m, rtCP_LUT_HEMS_1_maxIndex_i, 54U);
  accumulatedData = look2_binlcpw(g_v_idx_1, rtu_I_HEMS[1],
    rtCP_LUT_HEMS_2_bp01Data_p, rtCP_LUT_HEMS_2_bp02Data_p,
    rtCP_LUT_HEMS_2_tableData_o, rtCP_LUT_HEMS_2_maxIndex_m, 54U);
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
  g_v_idx_0 = look2_binlcpw(g_v_idx_0, rty_Fa[0], rtCP_InvLUT_1_bp01Data,
    rtCP_InvLUT_1_bp02Data, rtCP_InvLUT_1_tableData, rtCP_InvLUT_1_maxIndex, 54U);
  g_v_idx_1 = look2_binlcpw(g_v_idx_1, rty_Fa[1], rtCP_InvLUT_2_bp01Data,
    rtCP_InvLUT_2_bp02Data, rtCP_InvLUT_2_tableData, rtCP_InvLUT_2_maxIndex, 54U);
  g_v_idx_2 = look2_binlcpw(g_v_idx_2, rty_Fa[2], rtCP_InvLUT_3_bp01Data,
    rtCP_InvLUT_3_bp02Data, rtCP_InvLUT_3_tableData, rtCP_InvLUT_3_maxIndex, 54U);
  g_v_idx_3 = look2_binlcpw(g_v_idx_3, rty_Fa[3], rtCP_InvLUT_4_bp01Data,
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

  rtb_LUT_HEMS_1[0] = b_accumulatedData;
  rtb_LUT_HEMS_1[1] = accumulatedData;
  rtb_LUT_HEMS_1[2] = rotz;
  rtb_LUT_HEMS_1[3] = rtb_InvLUT_1;
  rty_Bk[0] = 0.0;
  rty_Bk[1] = 0.0;
  rty_Bk[2] = 0.0;
  g_v_idx_1 = rty_Bk[0];
  g_v_idx_2 = rty_Bk[1];
  g_v_idx_0 = rty_Bk[2];
  tmp = 0;
  for (i = 0; i < 4; i++) {
    b_accumulatedData = rtb_LUT_HEMS_1[i];
    g_v_idx_1 += rtCP_Kin_HEMS_Gain[tmp] * b_accumulatedData;
    g_v_idx_2 += rtCP_Kin_HEMS_Gain[tmp + 1] * b_accumulatedData;
    g_v_idx_0 += rtCP_Kin_HEMS_Gain[tmp + 2] * b_accumulatedData;
    tmp += 3;
  }

  rty_Bk[2] = g_v_idx_0;
  rty_Bk[1] = g_v_idx_2;
  rty_Bk[0] = g_v_idx_1;
  PosicionH10_DW.uz_DSTATE[0] = rty_Bk[0] - 2816.3102265;
  PosicionH10_DW.uz_DSTATE[1] = rty_Bk[1];
  PosicionH10_DW.uz_DSTATE[2] = rty_Bk[2];

  {
    real_T xnew[3];
    xnew[0] = 0.75259320810981811*PosicionH10_DW.Z_DSTATE[0] +
      0.000876296604054912*PosicionH10_DW.Z_DSTATE[1]
      + 4.3814830202746851E-7*PosicionH10_DW.Z_DSTATE[2];
    xnew[0] += 0.24740679189018189*rty_Pos[1] + (-1.5261936708695022E-9)*rty_Ef
      [0];
    xnew[1] = (-21.613417590712306)*PosicionH10_DW.Z_DSTATE[0] +
      0.98919329120464383*PosicionH10_DW.Z_DSTATE[1]
      + 0.000994596645602322*PosicionH10_DW.Z_DSTATE[2];
    xnew[1] += 21.613417590712306*rty_Pos[1] + (-3.4644596328737506E-6)*rty_Ef[0];
    xnew[2] = (-638.82022435602892)*PosicionH10_DW.Z_DSTATE[0] +
      (-0.31941011217801363)*PosicionH10_DW.Z_DSTATE[1]
      + 0.99984029494391125*PosicionH10_DW.Z_DSTATE[2];
    xnew[2] += 638.82022435602892*rty_Pos[1] + 5.5629759303191771E-7*rty_Ef[0];
    (void) std::memcpy(PosicionH10_DW.Z_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  {
    real_T xnew[3];
    xnew[0] = 0.75259320810981811*PosicionH10_DW.Roll_DSTATE[0] +
      0.000876296604054912*PosicionH10_DW.Roll_DSTATE[1]
      + 4.3814830202746851E-7*PosicionH10_DW.Roll_DSTATE[2];
    xnew[0] += 0.24740679189018189*rty_Pos[2] + (-3.0313270842859875E-9)*rty_Ef
      [1];
    xnew[1] = (-21.613417590712306)*PosicionH10_DW.Roll_DSTATE[0] +
      0.98919329120464383*PosicionH10_DW.Roll_DSTATE[1]
      + 0.000994596645602322*PosicionH10_DW.Roll_DSTATE[2];
    xnew[1] += 21.613417590712306*rty_Pos[2] + (-6.88111248132911E-6)*rty_Ef[1];
    xnew[2] = (-638.82022435602892)*PosicionH10_DW.Roll_DSTATE[0] +
      (-0.31941011217801363)*PosicionH10_DW.Roll_DSTATE[1]
      + 0.99984029494391125*PosicionH10_DW.Roll_DSTATE[2];
    xnew[2] += 638.82022435602892*rty_Pos[2] + 1.1049187222222279E-6*rty_Ef[1];
    (void) std::memcpy(PosicionH10_DW.Roll_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  {
    real_T xnew[3];
    xnew[0] = 0.8038854113360443*PosicionH10_DW.Pitch_DSTATE[0] +
      0.00090194270566802237*PosicionH10_DW.Pitch_DSTATE[1]
      + 4.5097135283401114E-7*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[0] += 0.19611458866395565*rty_Pos[3] + (-2.036809088255512E-8)*rty_Ef[2];
    xnew[1] = (-13.413240947341995)*PosicionH10_DW.Pitch_DSTATE[0] +
      0.99329337952632912*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.00099664668976316446*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[1] += 13.413240947341992*rty_Pos[3] + (-4.5013480850446806E-5)*rty_Ef[2];
    xnew[2] = (-309.36634804413166)*PosicionH10_DW.Pitch_DSTATE[0] +
      (-0.15468317402206583)*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.99992265841298889*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[2] += 309.36634804413166*rty_Pos[3] + 3.4931275863582026E-6*rty_Ef[2];
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
