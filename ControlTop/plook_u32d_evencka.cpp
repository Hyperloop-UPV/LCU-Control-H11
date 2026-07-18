#include "plook_u32d_evencka.h"
#include "rtwtypes.h"

uint32_T plook_u32d_evencka(real_T u, real_T bp0, real_T bpSpace, uint32_T
  maxIndex)
{
  uint32_T bpIndex;
  if (u <= bp0) {
    bpIndex = 0U;
  } else {
    real_T fbpIndex;
    fbpIndex = (u - bp0) * (1.0 / bpSpace);
    if (fbpIndex < maxIndex) {
      bpIndex = static_cast<uint32_T>(fbpIndex);
    } else {
      bpIndex = maxIndex;
    }
  }

  return bpIndex;
}
