/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control.h
 *
 * Code generated for Simulink model 'control'.
 *
 * Model version                  : 1.108
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr  7 22:41:27 2026
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
#include "math.h"
#endif                                 /* control_COMMON_INCLUDES_ */

#include "control_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
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
  real32_T TmpRTBAtSumRefInport2;
  real32_T TmpRTBAtSumVInport2;        /* '<S1>/Kd' */
  real32_T TmpRTBAtSumCtrlInport2;
} B_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S39>/Integrator' */
  real32_T ESO_DSTATE[3];              /* '<S1>/ESO' */
  real32_T TmpRTBAtSumRefInport2_Buffer0;/* synthesized block */
  real32_T TmpRTBAtSumVInport2_Buffer0;/* synthesized block */
  real32_T TmpRTBAtSumCtrlInport2_Buffer0;/* synthesized block */
  real32_T TmpRTBAtESOInport1_Buffer[2];/* synthesized block */
} DW_control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: LUT_Inv_F2I_tableData
   * Referenced by: '<S1>/LUT_Inv_F2I'
   */
  real32_T LUT_Inv_F2I_tableData[2800];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/LUT_Dir_I2F'
   *   '<S1>/LUT_Inv_F2I'
   */
  real32_T pooled2[14];

  /* Computed Parameter: LUT_Inv_F2I_bp02Data
   * Referenced by: '<S1>/LUT_Inv_F2I'
   */
  real32_T LUT_Inv_F2I_bp02Data[200];

  /* Computed Parameter: LUT_Dir_I2F_tableData
   * Referenced by: '<S1>/LUT_Dir_I2F'
   */
  real32_T LUT_Dir_I2F_tableData[1554];

  /* Computed Parameter: LUT_Dir_I2F_bp02Data
   * Referenced by: '<S1>/LUT_Dir_I2F'
   */
  real32_T LUT_Dir_I2F_bp02Data[111];

  /* Computed Parameter: LUT_Inv_F2I_maxIndex
   * Referenced by: '<S1>/LUT_Inv_F2I'
   */
  uint32_T LUT_Inv_F2I_maxIndex[2];

  /* Computed Parameter: LUT_Dir_I2F_maxIndex
   * Referenced by: '<S1>/LUT_Dir_I2F'
   */
  uint32_T LUT_Dir_I2F_maxIndex[2];
} ConstP_control_T;

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
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
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

/* Constant parameters (default storage) */
extern const ConstP_control_T control_ConstP;

/* External function called from main */
extern void control_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void control_initialize(void);
extern void control_step0(void);       /* Sample time: [0.0005s, 0.0s] */
extern void control_step1(void);       /* Sample time: [0.001s, 0.0s] */
extern void control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_control_T *const control_M;

/* [PATCH] Direct current control bypass */
extern int control_bypass_active;
extern real32_T control_bypass_i_ref;

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
 * '<S3>'   : 'control/Subsystem/PID Controller/Anti-windup'
 * '<S4>'   : 'control/Subsystem/PID Controller/D Gain'
 * '<S5>'   : 'control/Subsystem/PID Controller/External Derivative'
 * '<S6>'   : 'control/Subsystem/PID Controller/Filter'
 * '<S7>'   : 'control/Subsystem/PID Controller/Filter ICs'
 * '<S8>'   : 'control/Subsystem/PID Controller/I Gain'
 * '<S9>'   : 'control/Subsystem/PID Controller/Ideal P Gain'
 * '<S10>'  : 'control/Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'control/Subsystem/PID Controller/Integrator'
 * '<S12>'  : 'control/Subsystem/PID Controller/Integrator ICs'
 * '<S13>'  : 'control/Subsystem/PID Controller/N Copy'
 * '<S14>'  : 'control/Subsystem/PID Controller/N Gain'
 * '<S15>'  : 'control/Subsystem/PID Controller/P Copy'
 * '<S16>'  : 'control/Subsystem/PID Controller/Parallel P Gain'
 * '<S17>'  : 'control/Subsystem/PID Controller/Reset Signal'
 * '<S18>'  : 'control/Subsystem/PID Controller/Saturation'
 * '<S19>'  : 'control/Subsystem/PID Controller/Saturation Fdbk'
 * '<S20>'  : 'control/Subsystem/PID Controller/Sum'
 * '<S21>'  : 'control/Subsystem/PID Controller/Sum Fdbk'
 * '<S22>'  : 'control/Subsystem/PID Controller/Tracking Mode'
 * '<S23>'  : 'control/Subsystem/PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'control/Subsystem/PID Controller/Tsamp - Integral'
 * '<S25>'  : 'control/Subsystem/PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'control/Subsystem/PID Controller/postSat Signal'
 * '<S27>'  : 'control/Subsystem/PID Controller/preInt Signal'
 * '<S28>'  : 'control/Subsystem/PID Controller/preSat Signal'
 * '<S29>'  : 'control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S30>'  : 'control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Ideal/Dead Zone'
 * '<S31>'  : 'control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Ideal/Dead Zone/Enabled'
 * '<S32>'  : 'control/Subsystem/PID Controller/D Gain/Disabled'
 * '<S33>'  : 'control/Subsystem/PID Controller/External Derivative/Disabled'
 * '<S34>'  : 'control/Subsystem/PID Controller/Filter/Disabled'
 * '<S35>'  : 'control/Subsystem/PID Controller/Filter ICs/Disabled'
 * '<S36>'  : 'control/Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S37>'  : 'control/Subsystem/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S38>'  : 'control/Subsystem/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S39>'  : 'control/Subsystem/PID Controller/Integrator/Discrete'
 * '<S40>'  : 'control/Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S41>'  : 'control/Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S42>'  : 'control/Subsystem/PID Controller/N Gain/Disabled'
 * '<S43>'  : 'control/Subsystem/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S44>'  : 'control/Subsystem/PID Controller/Parallel P Gain/Passthrough'
 * '<S45>'  : 'control/Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S46>'  : 'control/Subsystem/PID Controller/Saturation/Enabled'
 * '<S47>'  : 'control/Subsystem/PID Controller/Saturation Fdbk/Passthrough'
 * '<S48>'  : 'control/Subsystem/PID Controller/Sum/Sum_PI'
 * '<S49>'  : 'control/Subsystem/PID Controller/Sum Fdbk/Enabled'
 * '<S50>'  : 'control/Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S51>'  : 'control/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'control/Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S53>'  : 'control/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'control/Subsystem/PID Controller/postSat Signal/Feedback_Path'
 * '<S55>'  : 'control/Subsystem/PID Controller/preInt Signal/Internal PreInt'
 * '<S56>'  : 'control/Subsystem/PID Controller/preSat Signal/Feedback_Path'
 */
#endif                                 /* control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
