#include "rtwtypes.h"
#include "mldivide_l89k28gF.h"
#include <cstring>
#include <cmath>
#include "xnrm2_l2M7eLKH.h"
#include "rt_hypotd.h"

void mldivide_l89k28gF(const real_T A[12], const real_T B[4], real_T Y[3])
{
  real_T b_A[12];
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
  std::memcpy(&b_A[0], &A[0], 12U * sizeof(real_T));
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
      smax = b_A[b_ix];
      b_A[b_ix] = b_A[ii_tmp];
      b_A[ii_tmp] = smax;
      smax = b_A[b_ix + 1];
      b_A[b_ix + 1] = b_A[ii_tmp + 1];
      b_A[ii_tmp + 1] = smax;
      smax = b_A[b_ix + 2];
      b_A[b_ix + 2] = b_A[ii_tmp + 2];
      b_A[ii_tmp + 2] = smax;
      smax = b_A[b_ix + 3];
      b_A[b_ix + 3] = b_A[ii_tmp + 3];
      b_A[ii_tmp + 3] = smax;
      b_ix = jpvt[pvt];
      jpvt[pvt] = jpvt[rankA];
      jpvt[rankA] = static_cast<int8_T>(b_ix);
      vn1[pvt] = vn1[rankA];
      vn2[pvt] = vn2[rankA];
    }

    scale = b_A[ii];
    pvt = ii + 2;
    tau[rankA] = 0.0;
    smax = xnrm2_l2M7eLKH(3 - rankA, b_A, ii + 2);
    if (smax != 0.0) {
      smax = rt_hypotd(b_A[ii], smax);
      if (b_A[ii] >= 0.0) {
        smax = -smax;
      }

      if (std::abs(smax) < 1.0020841800044864E-292) {
        b_ix = 0;
        ix = (ii - rankA) + 4;
        do {
          b_ix++;
          for (jy = pvt; jy <= ix; jy++) {
            b_A[jy - 1] *= 9.9792015476736E+291;
          }

          smax *= 9.9792015476736E+291;
          scale *= 9.9792015476736E+291;
        } while ((std::abs(smax) < 1.0020841800044864E-292) && (b_ix < 20));

        smax = rt_hypotd(scale, xnrm2_l2M7eLKH(3 - rankA, b_A, ii + 2));
        if (scale >= 0.0) {
          smax = -smax;
        }

        tau[rankA] = (smax - scale) / smax;
        scale = 1.0 / (scale - smax);
        for (jy = pvt; jy <= ix; jy++) {
          b_A[jy - 1] *= scale;
        }

        for (pvt = 0; pvt < b_ix; pvt++) {
          smax *= 1.0020841800044864E-292;
        }

        scale = smax;
      } else {
        tau[rankA] = (smax - b_A[ii]) / smax;
        scale = 1.0 / (b_A[ii] - smax);
        b_ix = (ii - rankA) + 4;
        for (ix = pvt; ix <= b_ix; ix++) {
          b_A[ix - 1] *= scale;
        }

        scale = smax;
      }
    }

    b_A[ii] = scale;
    if (rankA + 1 < 3) {
      smax = b_A[ii];
      b_A[ii] = 1.0;
      if (tau[rankA] != 0.0) {
        pvt = 4 - rankA;
        b_ix = (ii - rankA) + 3;
        while ((pvt > 0) && (b_A[b_ix] == 0.0)) {
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
              if (b_A[jy] != 0.0) {
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
              scale += b_A[(ii + ia) - ii_tmp] * b_A[ia - 1];
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
                b_A[ia - 1] += b_A[(ii + ia) - ix] * scale;
              }
            }

            ix += 4;
          }
        }
      }

      b_A[ii] = smax;
    }

    for (ii = rankA + 2; ii < 4; ii++) {
      pvt = ((ii - 1) << 2) + rankA;
      absxk = vn1[ii - 1];
      if (absxk != 0.0) {
        smax = std::abs(b_A[pvt]) / absxk;
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        scale = absxk / vn2[ii - 1];
        if (scale * scale * smax <= 1.4901161193847656E-8) {
          absxk = xnrm2_l2M7eLKH(3 - rankA, b_A, pvt + 2);
          vn1[ii - 1] = absxk;
          vn2[ii - 1] = absxk;
        } else {
          vn1[ii - 1] = absxk * std::sqrt(smax);
        }
      }
    }
  }

  rankA = 0;
  smax = 8.881784197001252E-15 * std::abs(b_A[0]);
  while ((rankA < 3) && (std::abs(b_A[(rankA << 2) + rankA]) > smax)) {
    rankA++;
  }

  for (ii = 0; ii < 3; ii++) {
    Y[ii] = 0.0;
    if (tau[ii] != 0.0) {
      smax = b_B[ii];
      for (pvt = ii + 2; pvt < 5; pvt++) {
        smax += b_A[((ii << 2) + pvt) - 1] * b_B[pvt - 1];
      }

      smax *= tau[ii];
      if (smax != 0.0) {
        b_B[ii] -= smax;
        for (pvt = ii + 2; pvt < 5; pvt++) {
          b_B[pvt - 1] -= b_A[((ii << 2) + pvt) - 1] * smax;
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
    Y[jpvt_0 - 1] /= b_A[(pvt + ii) - 1];
    for (b_ix = 0; b_ix <= ii - 2; b_ix++) {
      ix = jpvt[b_ix] - 1;
      Y[ix] -= b_A[pvt + b_ix] * Y[jpvt_0 - 1];
    }
  }
}
