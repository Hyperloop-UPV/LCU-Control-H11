//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rtmodel.cpp
//
// Code generated for Simulink model 'C_5DOF_EL'.
//
// Model version                  : 1.82
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Thu Apr 16 19:58:10 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtmodel.h"

// Use this function only if you need to maintain compatibility with an existing static main program.
void C_5DOF_EL_step(C_5DOF_EL & C_5DOF_EL_Obj_In, int_T tid)
{
  switch (tid) {
   case 0 :
    C_5DOF_EL_Obj_In.step0();
    break;

   case 1 :
    C_5DOF_EL_Obj_In.step1();
    break;

   default :
    // do nothing
    break;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
