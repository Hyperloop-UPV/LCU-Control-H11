#include "rtwtypes.h"
#include "rt_hypotd.h"
#include <cmath>

real_T rt_hypotd(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0) * a;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}
