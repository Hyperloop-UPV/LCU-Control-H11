#include "rtmodel.h"

void ControlTop_step(ControlTop & ControlTop_Obj_In, int_T tid)
{
  switch (tid) {
   case 0 :
    ControlTop_Obj_In.step0();
    break;

   case 1 :
    ControlTop_Obj_In.step1();
    break;

   default :
    break;
  }
}
