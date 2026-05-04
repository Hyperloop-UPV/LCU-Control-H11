#ifndef LOOK2_BINLCPW_H_
#define LOOK2_BINLCPW_H_
#include "rtwtypes.h"

extern real_T look2_binlcpw(real_T u0, real_T u1, const real_T *__restrict bp0,
  const real_T *__restrict bp1, const real_T *__restrict table, const uint32_T
  *__restrict maxIndex, uint32_T stride);

#endif

