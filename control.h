/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control.h
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Apr 30 22:43:24 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef control_h_
#define control_h_
#ifndef control_COMMON_INCLUDES_
#define control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* control_COMMON_INCLUDES_ */

#include "control_types.h"
#include <string.h>
#include "rtGetNaN.h"

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

/* Block states (default storage) for system '<S1>/Simulink2' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S6>/Unit Delay' */
  real32_T DiscreteStateSpace_DSTATE[3];/* '<S6>/Discrete State-Space' */
} DW_Simulink2_control_T;

/* Block signals (default storage) */
typedef struct {
  real32_T Corriente[4];
} B_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S5>/Unit Delay' */
  real32_T DiscreteStateSpace_DSTATE[3];/* '<S5>/Discrete State-Space' */
  real32_T Integrator_DSTATE;          /* '<S47>/Integrator' */
  real32_T Integrator_DSTATE_k;        /* '<S99>/Integrator' */
  real32_T Integrator_DSTATE_f;        /* '<S151>/Integrator' */
  real32_T Integrator_DSTATE_h;        /* '<S203>/Integrator' */
  real32_T Corriente_Buffer0[4];       /* synthesized block */
  DW_Simulink2_control_T Simulink4;    /* '<S1>/Simulink4' */
  DW_Simulink2_control_T Simulink3;    /* '<S1>/Simulink3' */
  DW_Simulink2_control_T Simulink2;    /* '<S1>/Simulink2' */
} DW_control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Airgaps_Model[8];           /* '<Root>/Airgaps_Model' */
  real32_T Refz;                       /* '<Root>/Refz' */
  real32_T I_real_hems[4];             /* '<Root>/I_real_hems' */
} ExtU_control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T I[10];                      /* '<Root>/I' */
} ExtY_control_T;

/* Real-time Model Data Structure */
struct tag_RTM_control_T {
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
extern B_control_T control_B;

/* Block states (default storage) */
extern DW_control_T control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_control_T control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_control_T control_Y;

/* Model entry point functions */
extern void control_initialize(void);
extern void control_step0(void);       /* Sample time: [0.0005s, 0.0s] */
extern void control_step1(void);       /* Sample time: [0.001s, 0.0s] */
extern void control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_control_T *const control_M;

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
 * '<Root>' : 'control'
 * '<S1>'   : 'control/Controlador Espacio de estados2'
 * '<S2>'   : 'control/GapToStates'
 * '<S3>'   : 'control/Controlador Espacio de estados2/ControlDeCorriente'
 * '<S4>'   : 'control/Controlador Espacio de estados2/MATLAB Function2'
 * '<S5>'   : 'control/Controlador Espacio de estados2/Simulink1'
 * '<S6>'   : 'control/Controlador Espacio de estados2/Simulink2'
 * '<S7>'   : 'control/Controlador Espacio de estados2/Simulink3'
 * '<S8>'   : 'control/Controlador Espacio de estados2/Simulink4'
 * '<S9>'   : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller'
 * '<S10>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1'
 * '<S11>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2'
 * '<S12>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3'
 * '<S13>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Anti-windup'
 * '<S14>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/D Gain'
 * '<S15>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/External Derivative'
 * '<S16>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Filter'
 * '<S17>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Filter ICs'
 * '<S18>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/I Gain'
 * '<S19>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Ideal P Gain'
 * '<S20>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Ideal P Gain Fdbk'
 * '<S21>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Integrator'
 * '<S22>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Integrator ICs'
 * '<S23>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/N Copy'
 * '<S24>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/N Gain'
 * '<S25>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/P Copy'
 * '<S26>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Parallel P Gain'
 * '<S27>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Reset Signal'
 * '<S28>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Saturation'
 * '<S29>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Saturation Fdbk'
 * '<S30>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Sum'
 * '<S31>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Sum Fdbk'
 * '<S32>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Tracking Mode'
 * '<S33>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Tracking Mode Sum'
 * '<S34>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Tsamp - Integral'
 * '<S35>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Tsamp - Ngain'
 * '<S36>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/postSat Signal'
 * '<S37>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/preInt Signal'
 * '<S38>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/preSat Signal'
 * '<S39>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Anti-windup/Passthrough'
 * '<S40>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/D Gain/Disabled'
 * '<S41>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/External Derivative/Disabled'
 * '<S42>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Filter/Disabled'
 * '<S43>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Filter ICs/Disabled'
 * '<S44>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/I Gain/Internal Parameters'
 * '<S45>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Ideal P Gain/Passthrough'
 * '<S46>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Integrator/Discrete'
 * '<S48>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Integrator ICs/Internal IC'
 * '<S49>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/N Gain/Disabled'
 * '<S51>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/P Copy/Disabled'
 * '<S52>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Reset Signal/Disabled'
 * '<S54>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Saturation/Enabled'
 * '<S55>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Saturation Fdbk/Disabled'
 * '<S56>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Sum/Sum_PI'
 * '<S57>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Sum Fdbk/Disabled'
 * '<S58>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Tracking Mode/Disabled'
 * '<S59>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S61>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/postSat Signal/Forward_Path'
 * '<S63>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/preInt Signal/Internal PreInt'
 * '<S64>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller/preSat Signal/Forward_Path'
 * '<S65>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Anti-windup'
 * '<S66>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/D Gain'
 * '<S67>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/External Derivative'
 * '<S68>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Filter'
 * '<S69>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Filter ICs'
 * '<S70>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/I Gain'
 * '<S71>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Ideal P Gain'
 * '<S72>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Ideal P Gain Fdbk'
 * '<S73>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Integrator'
 * '<S74>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Integrator ICs'
 * '<S75>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/N Copy'
 * '<S76>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/N Gain'
 * '<S77>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/P Copy'
 * '<S78>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Parallel P Gain'
 * '<S79>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Reset Signal'
 * '<S80>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Saturation'
 * '<S81>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Saturation Fdbk'
 * '<S82>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Sum'
 * '<S83>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Sum Fdbk'
 * '<S84>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Tracking Mode'
 * '<S85>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Tracking Mode Sum'
 * '<S86>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Tsamp - Integral'
 * '<S87>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Tsamp - Ngain'
 * '<S88>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/postSat Signal'
 * '<S89>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/preInt Signal'
 * '<S90>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/preSat Signal'
 * '<S91>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Anti-windup/Passthrough'
 * '<S92>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/D Gain/Disabled'
 * '<S93>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/External Derivative/Disabled'
 * '<S94>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Filter/Disabled'
 * '<S95>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Filter ICs/Disabled'
 * '<S96>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/I Gain/Internal Parameters'
 * '<S97>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Ideal P Gain/Passthrough'
 * '<S98>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S99>'  : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Integrator/Discrete'
 * '<S100>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Integrator ICs/Internal IC'
 * '<S101>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S102>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/N Gain/Disabled'
 * '<S103>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/P Copy/Disabled'
 * '<S104>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S105>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Reset Signal/Disabled'
 * '<S106>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Saturation/Enabled'
 * '<S107>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Saturation Fdbk/Disabled'
 * '<S108>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Sum/Sum_PI'
 * '<S109>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Sum Fdbk/Disabled'
 * '<S110>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Tracking Mode/Disabled'
 * '<S111>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S112>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S113>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S114>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/postSat Signal/Forward_Path'
 * '<S115>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/preInt Signal/Internal PreInt'
 * '<S116>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller1/preSat Signal/Forward_Path'
 * '<S117>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Anti-windup'
 * '<S118>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/D Gain'
 * '<S119>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/External Derivative'
 * '<S120>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Filter'
 * '<S121>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Filter ICs'
 * '<S122>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/I Gain'
 * '<S123>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Ideal P Gain'
 * '<S124>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Ideal P Gain Fdbk'
 * '<S125>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Integrator'
 * '<S126>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Integrator ICs'
 * '<S127>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/N Copy'
 * '<S128>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/N Gain'
 * '<S129>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/P Copy'
 * '<S130>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Parallel P Gain'
 * '<S131>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Reset Signal'
 * '<S132>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Saturation'
 * '<S133>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Saturation Fdbk'
 * '<S134>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Sum'
 * '<S135>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Sum Fdbk'
 * '<S136>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Tracking Mode'
 * '<S137>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Tracking Mode Sum'
 * '<S138>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Tsamp - Integral'
 * '<S139>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Tsamp - Ngain'
 * '<S140>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/postSat Signal'
 * '<S141>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/preInt Signal'
 * '<S142>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/preSat Signal'
 * '<S143>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Anti-windup/Passthrough'
 * '<S144>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/D Gain/Disabled'
 * '<S145>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/External Derivative/Disabled'
 * '<S146>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Filter/Disabled'
 * '<S147>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Filter ICs/Disabled'
 * '<S148>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/I Gain/Internal Parameters'
 * '<S149>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Ideal P Gain/Passthrough'
 * '<S150>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S151>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Integrator/Discrete'
 * '<S152>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Integrator ICs/Internal IC'
 * '<S153>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S154>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/N Gain/Disabled'
 * '<S155>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/P Copy/Disabled'
 * '<S156>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S157>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Reset Signal/Disabled'
 * '<S158>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Saturation/Enabled'
 * '<S159>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Saturation Fdbk/Disabled'
 * '<S160>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Sum/Sum_PI'
 * '<S161>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Sum Fdbk/Disabled'
 * '<S162>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Tracking Mode/Disabled'
 * '<S163>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S164>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S165>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S166>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/postSat Signal/Forward_Path'
 * '<S167>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/preInt Signal/Internal PreInt'
 * '<S168>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller2/preSat Signal/Forward_Path'
 * '<S169>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Anti-windup'
 * '<S170>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/D Gain'
 * '<S171>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/External Derivative'
 * '<S172>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Filter'
 * '<S173>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Filter ICs'
 * '<S174>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/I Gain'
 * '<S175>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Ideal P Gain'
 * '<S176>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Ideal P Gain Fdbk'
 * '<S177>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Integrator'
 * '<S178>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Integrator ICs'
 * '<S179>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/N Copy'
 * '<S180>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/N Gain'
 * '<S181>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/P Copy'
 * '<S182>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Parallel P Gain'
 * '<S183>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Reset Signal'
 * '<S184>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Saturation'
 * '<S185>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Saturation Fdbk'
 * '<S186>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Sum'
 * '<S187>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Sum Fdbk'
 * '<S188>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Tracking Mode'
 * '<S189>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Tracking Mode Sum'
 * '<S190>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Tsamp - Integral'
 * '<S191>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Tsamp - Ngain'
 * '<S192>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/postSat Signal'
 * '<S193>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/preInt Signal'
 * '<S194>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/preSat Signal'
 * '<S195>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Anti-windup/Passthrough'
 * '<S196>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/D Gain/Disabled'
 * '<S197>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/External Derivative/Disabled'
 * '<S198>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Filter/Disabled'
 * '<S199>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Filter ICs/Disabled'
 * '<S200>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/I Gain/Internal Parameters'
 * '<S201>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Ideal P Gain/Passthrough'
 * '<S202>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S203>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Integrator/Discrete'
 * '<S204>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Integrator ICs/Internal IC'
 * '<S205>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S206>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/N Gain/Disabled'
 * '<S207>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/P Copy/Disabled'
 * '<S208>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S209>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Reset Signal/Disabled'
 * '<S210>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Saturation/Enabled'
 * '<S211>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Saturation Fdbk/Disabled'
 * '<S212>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Sum/Sum_PI'
 * '<S213>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Sum Fdbk/Disabled'
 * '<S214>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Tracking Mode/Disabled'
 * '<S215>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S216>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S217>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S218>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/postSat Signal/Forward_Path'
 * '<S219>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/preInt Signal/Internal PreInt'
 * '<S220>' : 'control/Controlador Espacio de estados2/ControlDeCorriente/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
