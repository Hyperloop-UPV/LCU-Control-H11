#ifndef RTMODEL_H_
#define RTMODEL_H_
#include "ControlTop.h"
#define MODEL_CLASSNAME                ControlTop
#define MODEL_STEPNAME                 ControlTop_step
#define ROOT_IO_FORMAT                 1
#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((void*) 0)
#endif

#ifdef __cplusplus

extern "C"
{

#endif

  extern void ControlTop_step(ControlTop & ControlTop_Obj_In, int_T tid);

#ifdef __cplusplus

}

#endif
#endif

