//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: C_5DOF_EL_types.h
//
// Code generated for Simulink model 'C_5DOF_EL'.
//
// Model version                  : 1.81
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Thu Apr 16 19:43:07 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef C_5DOF_EL_types_h_
#define C_5DOF_EL_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_AIRGAP_Bus_
#define DEFINED_TYPEDEF_FOR_AIRGAP_Bus_

// Sensores físicos de distancia del vehículo
struct AIRGAP_Bus
{
  real_T AG_Z1;
  real_T AG_Z2;
  real_T AG_Z3;
  real_T AG_Z4;
  real_T AG_Y5;
  real_T AG_Y6;
  real_T AG_Y7;
  real_T AG_Y8;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_HEMS_
#define DEFINED_TYPEDEF_FOR_HEMS_

struct HEMS
{
  real_T I_HEMS1;
  real_T I_HEMS2;
  real_T I_HEMS3;
  real_T I_HEMS4;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_EMS_
#define DEFINED_TYPEDEF_FOR_EMS_

struct EMS
{
  real_T I_EMS5;
  real_T I_EMS6;
  real_T I_EMS7;
  real_T I_EMS8;
  real_T I_EMS9;
  real_T I_EMS10;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_V_
#define DEFINED_TYPEDEF_FOR_V_

struct V
{
  real_T V_HEMS1;
  real_T V_HEMS2;
  real_T V_HEMS3;
  real_T V_HEMS4;
  real_T V_EMS5;
  real_T V_EMS6;
  real_T V_EMS7;
  real_T V_EMS8;
  real_T V_EMS9;
  real_T V_EMS10;
};

#endif
#endif                                 // C_5DOF_EL_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
