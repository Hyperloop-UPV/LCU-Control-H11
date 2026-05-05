#include "rtwtypes.h"
#include "xnrm2_l2M7eLKH.h"
#include <cmath>

real_T xnrm2_l2M7eLKH(int32_T n, const real_T x[12], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.312168642111238E-170;
      kend = ix0 + n;
      for (int32_T k{ix0}; k < kend; k++) {
        real_T absxk;
        absxk = std::abs(x[k - 1]);
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

      y = scale * std::sqrt(y);
    }
  }

  return y;
}
