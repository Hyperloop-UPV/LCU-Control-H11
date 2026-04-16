/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: C_5DOF_EL.h
 *
 * Code generated for Simulink model 'C_5DOF_EL'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Apr 16 15:20:29 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef C_5DOF_EL_h_
#define C_5DOF_EL_h_
#ifndef C_5DOF_EL_COMMON_INCLUDES_
#define C_5DOF_EL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* C_5DOF_EL_COMMON_INCLUDES_ */

#include "C_5DOF_EL_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T H[40];
  real_T A[25];
  real_T airgaps_actuadores[10];       /* '<S2>/MATLAB Function1' */
  real_T b[8];
  real_T TmpSignalConversionAtKin_EM[6];
  real_T dv[6];
  real_T u[5];                         /* '<S1>/MATLAB Function1' */
  real_T uz[5];                        /* '<S2>/uz' */
  real_T RT_Iref_HEMS[4];              /* '<S6>/RT_Iref_HEMS' */
  real_T RT_Iref_EMS[6];               /* '<S4>/RT_Iref_EMS' */
  real_T dv1[4];
  real_T Yaw[3];                       /* '<S4>/Yaw' */
  real_T TmpSignalConversionAtSFun_f[3];/* '<S6>/Mezclador' */
  real_T smax;
  real_T s;
  real_T b0_Z;                         /* '<S6>/b0_Z' */
  real_T b0_Roll;                      /* '<S6>/b0_Roll' */
  real_T rtb_AG_mm_idx_0;
  real_T rtb_AG_mm_idx_1;
  real_T rtb_Sum_HEMS_idx_0;
  real_T rtb_Sum_HEMS_idx_1;
  real_T rtb_Sum_HEMS_idx_2;
  real_T Saturation_g;                 /* '<S441>/Saturation' */
  real_T Saturation;                   /* '<S387>/Saturation' */
  real_T Saturation_n;                 /* '<S495>/Saturation' */
  real_T Saturation_a;                 /* '<S549>/Saturation' */
  real_T Saturation_c;                 /* '<S58>/Saturation' */
  real_T Saturation_av;                /* '<S112>/Saturation' */
  real_T Saturation_b;                 /* '<S166>/Saturation' */
  real_T Saturation_at;                /* '<S220>/Saturation' */
  real_T Saturation_h;                 /* '<S274>/Saturation' */
  real_T Saturation_cw;                /* '<S328>/Saturation' */
  real_T IntegralGain;                 /* '<S318>/Integral Gain' */
  real_T DeadZone;                     /* '<S313>/DeadZone' */
  real_T Integrator;
  real_T Integrator_k;
  real_T Integrator_c;
  real_T Integrator_a;
  real_T Integrator_f;
  real_T Integrator_j;
  real_T Integrator_am;
  real_T Integrator_l;
  real_T Integrator_j3;
  real_T Integrator_tmp;
  real_T Integrator_k_tmp;
} B_C_5DOF_EL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S380>/Integrator' */
  real_T Integrator_DSTATE_b;          /* '<S434>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S488>/Integrator' */
  real_T Integrator_DSTATE_e;          /* '<S542>/Integrator' */
  real_T Integrator_DSTATE_i;          /* '<S51>/Integrator' */
  real_T Integrator_DSTATE_e2;         /* '<S105>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S159>/Integrator' */
  real_T Integrator_DSTATE_l;          /* '<S213>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S267>/Integrator' */
  real_T Integrator_DSTATE_be;         /* '<S321>/Integrator' */
  real_T Y_DSTATE[3];                  /* '<S4>/Y' */
  real_T Yaw_DSTATE[3];                /* '<S4>/Yaw' */
  real_T Z_DSTATE[3];                  /* '<S6>/Z' */
  real_T Roll_DSTATE[3];               /* '<S6>/Roll' */
  real_T Pitch_DSTATE[3];              /* '<S6>/Pitch' */
  real_T uz_DSTATE[5];                 /* '<S2>/uz' */
  real_T RT_Iref_HEMS_Buffer0[4];      /* '<S6>/RT_Iref_HEMS' */
  real_T RT_Iref_EMS_Buffer0[6];       /* '<S4>/RT_Iref_EMS' */
  real_T H_pseudo[40];                 /* '<S1>/MATLAB Function1' */
  boolean_T H_pseudo_not_empty;        /* '<S1>/MATLAB Function1' */
} DW_C_5DOF_EL_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: ems_inv_I_table)
   * Referenced by:
   *   '<S4>/InvLUT_1'
   *   '<S4>/InvLUT_2'
   *   '<S4>/InvLUT_3'
   *   '<S4>/InvLUT_4'
   *   '<S4>/InvLUT_5'
   *   '<S4>/InvLUT_6'
   */
  real_T pooled17[2600];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S4>/InvLUT_1'
   *   '<S4>/InvLUT_2'
   *   '<S4>/InvLUT_3'
   *   '<S4>/InvLUT_4'
   *   '<S4>/InvLUT_5'
   *   '<S4>/InvLUT_6'
   *   '<S5>/LUT_EMS_1'
   *   '<S5>/LUT_EMS_2'
   *   '<S5>/LUT_EMS_3'
   *   '<S5>/LUT_EMS_4'
   *   '<S5>/LUT_EMS_5'
   *   '<S5>/LUT_EMS_6'
   */
  real_T pooled18[13];

  /* Pooled Parameter (Expression: ems_inv_F_bp)
   * Referenced by:
   *   '<S4>/InvLUT_1'
   *   '<S4>/InvLUT_2'
   *   '<S4>/InvLUT_3'
   *   '<S4>/InvLUT_4'
   *   '<S4>/InvLUT_5'
   *   '<S4>/InvLUT_6'
   */
  real_T pooled19[200];

  /* Pooled Parameter (Expression: ems_direct_F_table)
   * Referenced by:
   *   '<S5>/LUT_EMS_1'
   *   '<S5>/LUT_EMS_2'
   *   '<S5>/LUT_EMS_3'
   *   '<S5>/LUT_EMS_4'
   *   '<S5>/LUT_EMS_5'
   *   '<S5>/LUT_EMS_6'
   */
  real_T pooled21[728];

  /* Pooled Parameter (Expression: ems_direct_I_bp)
   * Referenced by:
   *   '<S5>/LUT_EMS_1'
   *   '<S5>/LUT_EMS_2'
   *   '<S5>/LUT_EMS_3'
   *   '<S5>/LUT_EMS_4'
   *   '<S5>/LUT_EMS_5'
   *   '<S5>/LUT_EMS_6'
   */
  real_T pooled22[56];

  /* Expression: K_kin_ems
   * Referenced by: '<S5>/Kin_EMS'
   */
  real_T Kin_EMS_Gain[12];

  /* Pooled Parameter (Expression: hems_direct_F_table)
   * Referenced by:
   *   '<S5>/LUT_HEMS_1'
   *   '<S5>/LUT_HEMS_2'
   *   '<S5>/LUT_HEMS_3'
   *   '<S5>/LUT_HEMS_4'
   */
  real_T pooled23[1554];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S5>/LUT_HEMS_1'
   *   '<S5>/LUT_HEMS_2'
   *   '<S5>/LUT_HEMS_3'
   *   '<S5>/LUT_HEMS_4'
   *   '<S6>/InvLUT_1'
   *   '<S6>/InvLUT_2'
   *   '<S6>/InvLUT_3'
   *   '<S6>/InvLUT_4'
   */
  real_T pooled24[14];

  /* Pooled Parameter (Expression: hems_direct_I_bp)
   * Referenced by:
   *   '<S5>/LUT_HEMS_1'
   *   '<S5>/LUT_HEMS_2'
   *   '<S5>/LUT_HEMS_3'
   *   '<S5>/LUT_HEMS_4'
   */
  real_T pooled25[111];

  /* Expression: K_kin_hems
   * Referenced by: '<S5>/Kin_HEMS'
   */
  real_T Kin_HEMS_Gain[12];

  /* Pooled Parameter (Expression: hems_inv_I_table)
   * Referenced by:
   *   '<S6>/InvLUT_1'
   *   '<S6>/InvLUT_2'
   *   '<S6>/InvLUT_3'
   *   '<S6>/InvLUT_4'
   */
  real_T pooled29[2800];

  /* Pooled Parameter (Expression: hems_inv_F_bp)
   * Referenced by:
   *   '<S6>/InvLUT_1'
   *   '<S6>/InvLUT_2'
   *   '<S6>/InvLUT_3'
   *   '<S6>/InvLUT_4'
   */
  real_T pooled30[200];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S4>/InvLUT_1'
   *   '<S4>/InvLUT_2'
   *   '<S4>/InvLUT_3'
   *   '<S4>/InvLUT_4'
   *   '<S4>/InvLUT_5'
   *   '<S4>/InvLUT_6'
   */
  uint32_T pooled31[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/LUT_EMS_1'
   *   '<S5>/LUT_EMS_2'
   *   '<S5>/LUT_EMS_3'
   *   '<S5>/LUT_EMS_4'
   *   '<S5>/LUT_EMS_5'
   *   '<S5>/LUT_EMS_6'
   */
  uint32_T pooled32[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/LUT_HEMS_1'
   *   '<S5>/LUT_HEMS_2'
   *   '<S5>/LUT_HEMS_3'
   *   '<S5>/LUT_HEMS_4'
   */
  uint32_T pooled33[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/InvLUT_1'
   *   '<S6>/InvLUT_2'
   *   '<S6>/InvLUT_3'
   *   '<S6>/InvLUT_4'
   */
  uint32_T pooled34[2];
} ConstP_C_5DOF_EL_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Ag[8];                      /* '<Root>/Ag' */
} ExtU_C_5DOF_EL_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Corrientes[10];               /* '<Root>/Corrientes' */
} ExtY_C_5DOF_EL_T;

/* Real-time Model Data Structure */
struct tag_RTM_C_5DOF_EL_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
      uint8_T cLimit[2];
    } TaskCounters;

    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals (default storage) */
extern B_C_5DOF_EL_T C_5DOF_EL_B;

/* Block states (default storage) */
extern DW_C_5DOF_EL_T C_5DOF_EL_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_C_5DOF_EL_T C_5DOF_EL_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_C_5DOF_EL_T C_5DOF_EL_Y;

/* Constant parameters (default storage) */
extern const ConstP_C_5DOF_EL_T C_5DOF_EL_ConstP;

/* Model entry point functions */
extern void C_5DOF_EL_initialize(void);
extern void C_5DOF_EL_step0(void);     /* Sample time: [0.0005s, 0.0s] */
extern void C_5DOF_EL_step1(void);     /* Sample time: [0.001s, 0.0s] */
extern void C_5DOF_EL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_C_5DOF_EL_T *const C_5DOF_EL_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'C_5DOF_EL'
 * '<S1>'   : 'C_5DOF_EL/Aigaps2Pos'
 * '<S2>'   : 'C_5DOF_EL/Controlador Espacio de estados2'
 * '<S3>'   : 'C_5DOF_EL/Aigaps2Pos/MATLAB Function1'
 * '<S4>'   : 'C_5DOF_EL/Controlador Espacio de estados2/E'
 * '<S5>'   : 'C_5DOF_EL/Controlador Espacio de estados2/Eff'
 * '<S6>'   : 'C_5DOF_EL/Controlador Espacio de estados2/H'
 * '<S7>'   : 'C_5DOF_EL/Controlador Espacio de estados2/MATLAB Function1'
 * '<S8>'   : 'C_5DOF_EL/Controlador Espacio de estados2/E/Mezclador'
 * '<S9>'   : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller'
 * '<S10>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1'
 * '<S11>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2'
 * '<S12>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3'
 * '<S13>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4'
 * '<S14>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5'
 * '<S15>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Anti-windup'
 * '<S16>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/D Gain'
 * '<S17>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/External Derivative'
 * '<S18>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Filter'
 * '<S19>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Filter ICs'
 * '<S20>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/I Gain'
 * '<S21>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Ideal P Gain'
 * '<S22>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Ideal P Gain Fdbk'
 * '<S23>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Integrator'
 * '<S24>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Integrator ICs'
 * '<S25>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/N Copy'
 * '<S26>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/N Gain'
 * '<S27>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/P Copy'
 * '<S28>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Parallel P Gain'
 * '<S29>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Reset Signal'
 * '<S30>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Saturation'
 * '<S31>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Saturation Fdbk'
 * '<S32>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Sum'
 * '<S33>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Sum Fdbk'
 * '<S34>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Tracking Mode'
 * '<S35>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Tracking Mode Sum'
 * '<S36>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Tsamp - Integral'
 * '<S37>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Tsamp - Ngain'
 * '<S38>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/postSat Signal'
 * '<S39>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/preInt Signal'
 * '<S40>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/preSat Signal'
 * '<S41>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S42>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S43>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S44>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/D Gain/Disabled'
 * '<S45>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/External Derivative/Disabled'
 * '<S46>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Filter/Disabled'
 * '<S47>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Filter ICs/Disabled'
 * '<S48>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/I Gain/Internal Parameters'
 * '<S49>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Ideal P Gain/Passthrough'
 * '<S50>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S51>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Integrator/Discrete'
 * '<S52>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Integrator ICs/Internal IC'
 * '<S53>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S54>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/N Gain/Disabled'
 * '<S55>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/P Copy/Disabled'
 * '<S56>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S57>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Reset Signal/Disabled'
 * '<S58>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Saturation/Enabled'
 * '<S59>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Saturation Fdbk/Passthrough'
 * '<S60>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Sum/Sum_PI'
 * '<S61>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Sum Fdbk/Enabled'
 * '<S62>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Tracking Mode/Disabled'
 * '<S63>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S64>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S65>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S66>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/postSat Signal/Feedback_Path'
 * '<S67>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/preInt Signal/Internal PreInt'
 * '<S68>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller/preSat Signal/Feedback_Path'
 * '<S69>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Anti-windup'
 * '<S70>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/D Gain'
 * '<S71>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/External Derivative'
 * '<S72>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Filter'
 * '<S73>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Filter ICs'
 * '<S74>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/I Gain'
 * '<S75>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Ideal P Gain'
 * '<S76>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Ideal P Gain Fdbk'
 * '<S77>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Integrator'
 * '<S78>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Integrator ICs'
 * '<S79>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/N Copy'
 * '<S80>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/N Gain'
 * '<S81>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/P Copy'
 * '<S82>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Parallel P Gain'
 * '<S83>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Reset Signal'
 * '<S84>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Saturation'
 * '<S85>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Saturation Fdbk'
 * '<S86>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Sum'
 * '<S87>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Sum Fdbk'
 * '<S88>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Tracking Mode'
 * '<S89>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Tracking Mode Sum'
 * '<S90>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Tsamp - Integral'
 * '<S91>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Tsamp - Ngain'
 * '<S92>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/postSat Signal'
 * '<S93>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/preInt Signal'
 * '<S94>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/preSat Signal'
 * '<S95>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S96>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S97>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S98>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/D Gain/Disabled'
 * '<S99>'  : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/External Derivative/Disabled'
 * '<S100>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Filter/Disabled'
 * '<S101>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Filter ICs/Disabled'
 * '<S102>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/I Gain/Internal Parameters'
 * '<S103>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Ideal P Gain/Passthrough'
 * '<S104>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Ideal P Gain Fdbk/Passthrough'
 * '<S105>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Integrator/Discrete'
 * '<S106>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Integrator ICs/Internal IC'
 * '<S107>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S108>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/N Gain/Disabled'
 * '<S109>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/P Copy/Disabled'
 * '<S110>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S111>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Reset Signal/Disabled'
 * '<S112>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Saturation/Enabled'
 * '<S113>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Saturation Fdbk/Passthrough'
 * '<S114>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Sum/Sum_PI'
 * '<S115>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Sum Fdbk/Enabled'
 * '<S116>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Tracking Mode/Disabled'
 * '<S117>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S118>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S119>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S120>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/postSat Signal/Feedback_Path'
 * '<S121>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/preInt Signal/Internal PreInt'
 * '<S122>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller1/preSat Signal/Feedback_Path'
 * '<S123>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Anti-windup'
 * '<S124>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/D Gain'
 * '<S125>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/External Derivative'
 * '<S126>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Filter'
 * '<S127>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Filter ICs'
 * '<S128>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/I Gain'
 * '<S129>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Ideal P Gain'
 * '<S130>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Ideal P Gain Fdbk'
 * '<S131>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Integrator'
 * '<S132>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Integrator ICs'
 * '<S133>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/N Copy'
 * '<S134>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/N Gain'
 * '<S135>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/P Copy'
 * '<S136>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Parallel P Gain'
 * '<S137>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Reset Signal'
 * '<S138>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Saturation'
 * '<S139>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Saturation Fdbk'
 * '<S140>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Sum'
 * '<S141>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Sum Fdbk'
 * '<S142>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Tracking Mode'
 * '<S143>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Tracking Mode Sum'
 * '<S144>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Tsamp - Integral'
 * '<S145>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Tsamp - Ngain'
 * '<S146>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/postSat Signal'
 * '<S147>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/preInt Signal'
 * '<S148>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/preSat Signal'
 * '<S149>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S150>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S151>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S152>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/D Gain/Disabled'
 * '<S153>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/External Derivative/Disabled'
 * '<S154>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Filter/Disabled'
 * '<S155>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Filter ICs/Disabled'
 * '<S156>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/I Gain/Internal Parameters'
 * '<S157>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Ideal P Gain/Passthrough'
 * '<S158>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Ideal P Gain Fdbk/Passthrough'
 * '<S159>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Integrator/Discrete'
 * '<S160>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Integrator ICs/Internal IC'
 * '<S161>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S162>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/N Gain/Disabled'
 * '<S163>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/P Copy/Disabled'
 * '<S164>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S165>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Reset Signal/Disabled'
 * '<S166>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Saturation/Enabled'
 * '<S167>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Saturation Fdbk/Passthrough'
 * '<S168>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Sum/Sum_PI'
 * '<S169>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Sum Fdbk/Enabled'
 * '<S170>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Tracking Mode/Disabled'
 * '<S171>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S172>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S173>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S174>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/postSat Signal/Feedback_Path'
 * '<S175>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/preInt Signal/Internal PreInt'
 * '<S176>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller2/preSat Signal/Feedback_Path'
 * '<S177>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Anti-windup'
 * '<S178>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/D Gain'
 * '<S179>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/External Derivative'
 * '<S180>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Filter'
 * '<S181>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Filter ICs'
 * '<S182>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/I Gain'
 * '<S183>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Ideal P Gain'
 * '<S184>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Ideal P Gain Fdbk'
 * '<S185>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Integrator'
 * '<S186>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Integrator ICs'
 * '<S187>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/N Copy'
 * '<S188>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/N Gain'
 * '<S189>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/P Copy'
 * '<S190>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Parallel P Gain'
 * '<S191>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Reset Signal'
 * '<S192>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Saturation'
 * '<S193>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Saturation Fdbk'
 * '<S194>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Sum'
 * '<S195>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Sum Fdbk'
 * '<S196>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Tracking Mode'
 * '<S197>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Tracking Mode Sum'
 * '<S198>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Tsamp - Integral'
 * '<S199>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Tsamp - Ngain'
 * '<S200>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/postSat Signal'
 * '<S201>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/preInt Signal'
 * '<S202>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/preSat Signal'
 * '<S203>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S204>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S205>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S206>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/D Gain/Disabled'
 * '<S207>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/External Derivative/Disabled'
 * '<S208>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Filter/Disabled'
 * '<S209>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Filter ICs/Disabled'
 * '<S210>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/I Gain/Internal Parameters'
 * '<S211>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Ideal P Gain/Passthrough'
 * '<S212>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Ideal P Gain Fdbk/Passthrough'
 * '<S213>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Integrator/Discrete'
 * '<S214>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Integrator ICs/Internal IC'
 * '<S215>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S216>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/N Gain/Disabled'
 * '<S217>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/P Copy/Disabled'
 * '<S218>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S219>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Reset Signal/Disabled'
 * '<S220>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Saturation/Enabled'
 * '<S221>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Saturation Fdbk/Passthrough'
 * '<S222>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Sum/Sum_PI'
 * '<S223>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Sum Fdbk/Enabled'
 * '<S224>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Tracking Mode/Disabled'
 * '<S225>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S226>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S227>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S228>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/postSat Signal/Feedback_Path'
 * '<S229>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/preInt Signal/Internal PreInt'
 * '<S230>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller3/preSat Signal/Feedback_Path'
 * '<S231>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Anti-windup'
 * '<S232>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/D Gain'
 * '<S233>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/External Derivative'
 * '<S234>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Filter'
 * '<S235>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Filter ICs'
 * '<S236>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/I Gain'
 * '<S237>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Ideal P Gain'
 * '<S238>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Ideal P Gain Fdbk'
 * '<S239>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Integrator'
 * '<S240>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Integrator ICs'
 * '<S241>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/N Copy'
 * '<S242>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/N Gain'
 * '<S243>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/P Copy'
 * '<S244>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Parallel P Gain'
 * '<S245>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Reset Signal'
 * '<S246>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Saturation'
 * '<S247>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Saturation Fdbk'
 * '<S248>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Sum'
 * '<S249>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Sum Fdbk'
 * '<S250>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Tracking Mode'
 * '<S251>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Tracking Mode Sum'
 * '<S252>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Tsamp - Integral'
 * '<S253>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Tsamp - Ngain'
 * '<S254>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/postSat Signal'
 * '<S255>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/preInt Signal'
 * '<S256>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/preSat Signal'
 * '<S257>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Anti-windup/Disc. Clamping Parallel'
 * '<S258>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S259>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S260>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/D Gain/Disabled'
 * '<S261>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/External Derivative/Disabled'
 * '<S262>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Filter/Disabled'
 * '<S263>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Filter ICs/Disabled'
 * '<S264>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/I Gain/Internal Parameters'
 * '<S265>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Ideal P Gain/Passthrough'
 * '<S266>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Ideal P Gain Fdbk/Passthrough'
 * '<S267>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Integrator/Discrete'
 * '<S268>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Integrator ICs/Internal IC'
 * '<S269>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S270>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/N Gain/Disabled'
 * '<S271>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/P Copy/Disabled'
 * '<S272>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S273>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Reset Signal/Disabled'
 * '<S274>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Saturation/Enabled'
 * '<S275>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Saturation Fdbk/Passthrough'
 * '<S276>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Sum/Sum_PI'
 * '<S277>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Sum Fdbk/Enabled'
 * '<S278>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Tracking Mode/Disabled'
 * '<S279>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S280>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Tsamp - Integral/TsSignalSpecification'
 * '<S281>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S282>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/postSat Signal/Feedback_Path'
 * '<S283>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/preInt Signal/Internal PreInt'
 * '<S284>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller4/preSat Signal/Feedback_Path'
 * '<S285>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Anti-windup'
 * '<S286>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/D Gain'
 * '<S287>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/External Derivative'
 * '<S288>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Filter'
 * '<S289>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Filter ICs'
 * '<S290>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/I Gain'
 * '<S291>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Ideal P Gain'
 * '<S292>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Ideal P Gain Fdbk'
 * '<S293>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Integrator'
 * '<S294>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Integrator ICs'
 * '<S295>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/N Copy'
 * '<S296>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/N Gain'
 * '<S297>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/P Copy'
 * '<S298>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Parallel P Gain'
 * '<S299>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Reset Signal'
 * '<S300>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Saturation'
 * '<S301>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Saturation Fdbk'
 * '<S302>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Sum'
 * '<S303>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Sum Fdbk'
 * '<S304>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Tracking Mode'
 * '<S305>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Tracking Mode Sum'
 * '<S306>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Tsamp - Integral'
 * '<S307>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Tsamp - Ngain'
 * '<S308>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/postSat Signal'
 * '<S309>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/preInt Signal'
 * '<S310>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/preSat Signal'
 * '<S311>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Anti-windup/Disc. Clamping Parallel'
 * '<S312>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S313>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S314>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/D Gain/Disabled'
 * '<S315>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/External Derivative/Disabled'
 * '<S316>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Filter/Disabled'
 * '<S317>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Filter ICs/Disabled'
 * '<S318>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/I Gain/Internal Parameters'
 * '<S319>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Ideal P Gain/Passthrough'
 * '<S320>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Ideal P Gain Fdbk/Passthrough'
 * '<S321>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Integrator/Discrete'
 * '<S322>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Integrator ICs/Internal IC'
 * '<S323>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/N Copy/Disabled wSignal Specification'
 * '<S324>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/N Gain/Disabled'
 * '<S325>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/P Copy/Disabled'
 * '<S326>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Parallel P Gain/Internal Parameters'
 * '<S327>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Reset Signal/Disabled'
 * '<S328>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Saturation/Enabled'
 * '<S329>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Saturation Fdbk/Passthrough'
 * '<S330>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Sum/Sum_PI'
 * '<S331>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Sum Fdbk/Enabled'
 * '<S332>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Tracking Mode/Disabled'
 * '<S333>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Tracking Mode Sum/Passthrough'
 * '<S334>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Tsamp - Integral/TsSignalSpecification'
 * '<S335>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/Tsamp - Ngain/Passthrough'
 * '<S336>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/postSat Signal/Feedback_Path'
 * '<S337>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/preInt Signal/Internal PreInt'
 * '<S338>' : 'C_5DOF_EL/Controlador Espacio de estados2/E/PID Controller5/preSat Signal/Feedback_Path'
 * '<S339>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/Mezclador'
 * '<S340>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller'
 * '<S341>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1'
 * '<S342>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2'
 * '<S343>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3'
 * '<S344>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Anti-windup'
 * '<S345>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/D Gain'
 * '<S346>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/External Derivative'
 * '<S347>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Filter'
 * '<S348>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Filter ICs'
 * '<S349>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/I Gain'
 * '<S350>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Ideal P Gain'
 * '<S351>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Ideal P Gain Fdbk'
 * '<S352>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Integrator'
 * '<S353>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Integrator ICs'
 * '<S354>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/N Copy'
 * '<S355>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/N Gain'
 * '<S356>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/P Copy'
 * '<S357>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Parallel P Gain'
 * '<S358>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Reset Signal'
 * '<S359>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Saturation'
 * '<S360>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Saturation Fdbk'
 * '<S361>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Sum'
 * '<S362>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Sum Fdbk'
 * '<S363>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Tracking Mode'
 * '<S364>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Tracking Mode Sum'
 * '<S365>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Tsamp - Integral'
 * '<S366>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Tsamp - Ngain'
 * '<S367>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/postSat Signal'
 * '<S368>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/preInt Signal'
 * '<S369>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/preSat Signal'
 * '<S370>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S371>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S372>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S373>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/D Gain/Disabled'
 * '<S374>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/External Derivative/Disabled'
 * '<S375>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Filter/Disabled'
 * '<S376>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Filter ICs/Disabled'
 * '<S377>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/I Gain/Internal Parameters'
 * '<S378>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Ideal P Gain/Passthrough'
 * '<S379>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S380>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Integrator/Discrete'
 * '<S381>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Integrator ICs/Internal IC'
 * '<S382>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S383>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/N Gain/Disabled'
 * '<S384>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/P Copy/Disabled'
 * '<S385>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S386>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Reset Signal/Disabled'
 * '<S387>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Saturation/Enabled'
 * '<S388>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Saturation Fdbk/Passthrough'
 * '<S389>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Sum/Sum_PI'
 * '<S390>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Sum Fdbk/Enabled'
 * '<S391>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Tracking Mode/Disabled'
 * '<S392>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S393>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S394>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S395>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/postSat Signal/Feedback_Path'
 * '<S396>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/preInt Signal/Internal PreInt'
 * '<S397>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller/preSat Signal/Feedback_Path'
 * '<S398>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Anti-windup'
 * '<S399>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/D Gain'
 * '<S400>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/External Derivative'
 * '<S401>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Filter'
 * '<S402>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Filter ICs'
 * '<S403>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/I Gain'
 * '<S404>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Ideal P Gain'
 * '<S405>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Ideal P Gain Fdbk'
 * '<S406>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Integrator'
 * '<S407>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Integrator ICs'
 * '<S408>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/N Copy'
 * '<S409>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/N Gain'
 * '<S410>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/P Copy'
 * '<S411>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Parallel P Gain'
 * '<S412>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Reset Signal'
 * '<S413>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Saturation'
 * '<S414>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Saturation Fdbk'
 * '<S415>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Sum'
 * '<S416>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Sum Fdbk'
 * '<S417>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Tracking Mode'
 * '<S418>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Tracking Mode Sum'
 * '<S419>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Tsamp - Integral'
 * '<S420>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Tsamp - Ngain'
 * '<S421>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/postSat Signal'
 * '<S422>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/preInt Signal'
 * '<S423>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/preSat Signal'
 * '<S424>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S425>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S426>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S427>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/D Gain/Disabled'
 * '<S428>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/External Derivative/Disabled'
 * '<S429>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Filter/Disabled'
 * '<S430>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Filter ICs/Disabled'
 * '<S431>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/I Gain/Internal Parameters'
 * '<S432>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Ideal P Gain/Passthrough'
 * '<S433>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Ideal P Gain Fdbk/Passthrough'
 * '<S434>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Integrator/Discrete'
 * '<S435>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Integrator ICs/Internal IC'
 * '<S436>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S437>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/N Gain/Disabled'
 * '<S438>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/P Copy/Disabled'
 * '<S439>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S440>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Reset Signal/Disabled'
 * '<S441>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Saturation/Enabled'
 * '<S442>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Saturation Fdbk/Passthrough'
 * '<S443>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Sum/Sum_PI'
 * '<S444>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Sum Fdbk/Enabled'
 * '<S445>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Tracking Mode/Disabled'
 * '<S446>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S447>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S448>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S449>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/postSat Signal/Feedback_Path'
 * '<S450>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/preInt Signal/Internal PreInt'
 * '<S451>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller1/preSat Signal/Feedback_Path'
 * '<S452>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Anti-windup'
 * '<S453>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/D Gain'
 * '<S454>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/External Derivative'
 * '<S455>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Filter'
 * '<S456>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Filter ICs'
 * '<S457>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/I Gain'
 * '<S458>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Ideal P Gain'
 * '<S459>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Ideal P Gain Fdbk'
 * '<S460>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Integrator'
 * '<S461>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Integrator ICs'
 * '<S462>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/N Copy'
 * '<S463>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/N Gain'
 * '<S464>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/P Copy'
 * '<S465>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Parallel P Gain'
 * '<S466>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Reset Signal'
 * '<S467>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Saturation'
 * '<S468>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Saturation Fdbk'
 * '<S469>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Sum'
 * '<S470>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Sum Fdbk'
 * '<S471>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Tracking Mode'
 * '<S472>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Tracking Mode Sum'
 * '<S473>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Tsamp - Integral'
 * '<S474>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Tsamp - Ngain'
 * '<S475>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/postSat Signal'
 * '<S476>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/preInt Signal'
 * '<S477>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/preSat Signal'
 * '<S478>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S479>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S480>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S481>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/D Gain/Disabled'
 * '<S482>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/External Derivative/Disabled'
 * '<S483>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Filter/Disabled'
 * '<S484>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Filter ICs/Disabled'
 * '<S485>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/I Gain/Internal Parameters'
 * '<S486>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Ideal P Gain/Passthrough'
 * '<S487>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Ideal P Gain Fdbk/Passthrough'
 * '<S488>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Integrator/Discrete'
 * '<S489>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Integrator ICs/Internal IC'
 * '<S490>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S491>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/N Gain/Disabled'
 * '<S492>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/P Copy/Disabled'
 * '<S493>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S494>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Reset Signal/Disabled'
 * '<S495>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Saturation/Enabled'
 * '<S496>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Saturation Fdbk/Passthrough'
 * '<S497>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Sum/Sum_PI'
 * '<S498>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Sum Fdbk/Enabled'
 * '<S499>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Tracking Mode/Disabled'
 * '<S500>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S501>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S502>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S503>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/postSat Signal/Feedback_Path'
 * '<S504>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/preInt Signal/Internal PreInt'
 * '<S505>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller2/preSat Signal/Feedback_Path'
 * '<S506>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Anti-windup'
 * '<S507>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/D Gain'
 * '<S508>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/External Derivative'
 * '<S509>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Filter'
 * '<S510>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Filter ICs'
 * '<S511>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/I Gain'
 * '<S512>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Ideal P Gain'
 * '<S513>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Ideal P Gain Fdbk'
 * '<S514>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Integrator'
 * '<S515>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Integrator ICs'
 * '<S516>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/N Copy'
 * '<S517>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/N Gain'
 * '<S518>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/P Copy'
 * '<S519>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Parallel P Gain'
 * '<S520>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Reset Signal'
 * '<S521>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Saturation'
 * '<S522>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Saturation Fdbk'
 * '<S523>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Sum'
 * '<S524>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Sum Fdbk'
 * '<S525>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Tracking Mode'
 * '<S526>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Tracking Mode Sum'
 * '<S527>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Tsamp - Integral'
 * '<S528>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Tsamp - Ngain'
 * '<S529>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/postSat Signal'
 * '<S530>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/preInt Signal'
 * '<S531>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/preSat Signal'
 * '<S532>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S533>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S534>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S535>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/D Gain/Disabled'
 * '<S536>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/External Derivative/Disabled'
 * '<S537>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Filter/Disabled'
 * '<S538>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Filter ICs/Disabled'
 * '<S539>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/I Gain/Internal Parameters'
 * '<S540>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Ideal P Gain/Passthrough'
 * '<S541>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Ideal P Gain Fdbk/Passthrough'
 * '<S542>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Integrator/Discrete'
 * '<S543>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Integrator ICs/Internal IC'
 * '<S544>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S545>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/N Gain/Disabled'
 * '<S546>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/P Copy/Disabled'
 * '<S547>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S548>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Reset Signal/Disabled'
 * '<S549>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Saturation/Enabled'
 * '<S550>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Saturation Fdbk/Passthrough'
 * '<S551>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Sum/Sum_PI'
 * '<S552>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Sum Fdbk/Enabled'
 * '<S553>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Tracking Mode/Disabled'
 * '<S554>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S555>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S556>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S557>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/postSat Signal/Feedback_Path'
 * '<S558>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/preInt Signal/Internal PreInt'
 * '<S559>' : 'C_5DOF_EL/Controlador Espacio de estados2/H/PID Controller3/preSat Signal/Feedback_Path'
 */
#endif                                 /* C_5DOF_EL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
