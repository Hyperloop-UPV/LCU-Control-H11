#include "rtmodel.h"

void CONTROLH10_1_step(CONTROLH10_1 & CONTROLH10_1_Obj_In, int_T tid)
{
  switch (tid) {
   case 0 :
    CONTROLH10_1_Obj_In.step0();
    break;

   case 1 :
    CONTROLH10_1_Obj_In.step1();
    break;

   default :
    break;
  }
}
