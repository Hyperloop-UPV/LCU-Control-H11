#ifndef RTMODEL_H_
#define RTMODEL_H_
#include "CONTROLH10_1.h"
#define MODEL_CLASSNAME                CONTROLH10_1
#define MODEL_STEPNAME                 CONTROLH10_1_step
#define ROOT_IO_FORMAT                 1
#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((void*) 0)
#endif

#ifdef __cplusplus

extern "C"
{

#endif

  extern void CONTROLH10_1_step(CONTROLH10_1 & CONTROLH10_1_Obj_In, int_T tid);

#ifdef __cplusplus

}

#endif
#endif

