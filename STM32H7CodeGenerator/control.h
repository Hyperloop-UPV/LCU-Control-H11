/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control.h
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Jan 31 19:32:33 2026
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
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#endif                                 /* control_COMMON_INCLUDES_ */

#include "control_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T RateTransition;             /* '<S1>/Rate Transition' */
  real32_T Saturation;                 /* '<S47>/Saturation' */
  real32_T Corrientedereferencia;      /* '<S1>/Saturation' */
  real32_T DiscreteStateSpace[3];      /* '<S3>/Discrete State-Space' */
} B_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S40>/Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
  real32_T DiscreteStateSpace_DSTATE[3];/* '<S3>/Discrete State-Space' */
  real32_T RateTransition_Buffer0;     /* '<S1>/Rate Transition' */
} DW_control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Gap;                        /* '<Root>/Gap' */
  real32_T Referencia;                 /* '<Root>/Referencia' */
  real32_T corriente_real;             /* '<Root>/corriente_real' */
} ExtU_control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Voltage;                    /* '<Root>/Voltage' */
} ExtY_control_T;

/* Real-time Model Data Structure */
struct tag_RTM_control_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
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

/* External function called from main */
extern void control_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void control_initialize(void);
extern void control_step0(void);       /* Sample time: [0.0005s, 0.0s] */
extern void control_step1(void);       /* Sample time: [0.001s, 0.0s] */
extern void control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_control_T *const control_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<S1>'   : 'control/Subsystem'
 * '<S2>'   : 'control/Subsystem/PID Controller'
 * '<S3>'   : 'control/Subsystem/Subsystem'
 * '<S4>'   : 'control/Subsystem/PID Controller/Anti-windup'
 * '<S5>'   : 'control/Subsystem/PID Controller/D Gain'
 * '<S6>'   : 'control/Subsystem/PID Controller/External Derivative'
 * '<S7>'   : 'control/Subsystem/PID Controller/Filter'
 * '<S8>'   : 'control/Subsystem/PID Controller/Filter ICs'
 * '<S9>'   : 'control/Subsystem/PID Controller/I Gain'
 * '<S10>'  : 'control/Subsystem/PID Controller/Ideal P Gain'
 * '<S11>'  : 'control/Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'control/Subsystem/PID Controller/Integrator'
 * '<S13>'  : 'control/Subsystem/PID Controller/Integrator ICs'
 * '<S14>'  : 'control/Subsystem/PID Controller/N Copy'
 * '<S15>'  : 'control/Subsystem/PID Controller/N Gain'
 * '<S16>'  : 'control/Subsystem/PID Controller/P Copy'
 * '<S17>'  : 'control/Subsystem/PID Controller/Parallel P Gain'
 * '<S18>'  : 'control/Subsystem/PID Controller/Reset Signal'
 * '<S19>'  : 'control/Subsystem/PID Controller/Saturation'
 * '<S20>'  : 'control/Subsystem/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'control/Subsystem/PID Controller/Sum'
 * '<S22>'  : 'control/Subsystem/PID Controller/Sum Fdbk'
 * '<S23>'  : 'control/Subsystem/PID Controller/Tracking Mode'
 * '<S24>'  : 'control/Subsystem/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'control/Subsystem/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'control/Subsystem/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'control/Subsystem/PID Controller/postSat Signal'
 * '<S28>'  : 'control/Subsystem/PID Controller/preInt Signal'
 * '<S29>'  : 'control/Subsystem/PID Controller/preSat Signal'
 * '<S30>'  : 'control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S31>'  : 'control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Ideal/Dead Zone'
 * '<S32>'  : 'control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Ideal/Dead Zone/Enabled'
 * '<S33>'  : 'control/Subsystem/PID Controller/D Gain/Disabled'
 * '<S34>'  : 'control/Subsystem/PID Controller/External Derivative/Disabled'
 * '<S35>'  : 'control/Subsystem/PID Controller/Filter/Disabled'
 * '<S36>'  : 'control/Subsystem/PID Controller/Filter ICs/Disabled'
 * '<S37>'  : 'control/Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S38>'  : 'control/Subsystem/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S39>'  : 'control/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'control/Subsystem/PID Controller/Integrator/Discrete'
 * '<S41>'  : 'control/Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S42>'  : 'control/Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S43>'  : 'control/Subsystem/PID Controller/N Gain/Disabled'
 * '<S44>'  : 'control/Subsystem/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S45>'  : 'control/Subsystem/PID Controller/Parallel P Gain/Passthrough'
 * '<S46>'  : 'control/Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S47>'  : 'control/Subsystem/PID Controller/Saturation/Enabled'
 * '<S48>'  : 'control/Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S49>'  : 'control/Subsystem/PID Controller/Sum/Sum_PI'
 * '<S50>'  : 'control/Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S51>'  : 'control/Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S52>'  : 'control/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'control/Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S54>'  : 'control/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'control/Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S56>'  : 'control/Subsystem/PID Controller/preInt Signal/Internal PreInt'
 * '<S57>'  : 'control/Subsystem/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
