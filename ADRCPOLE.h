/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADRCPOLE.h
 *
 * Code generated for Simulink model 'ADRCPOLE'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Mar  8 00:33:23 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ADRCPOLE_h_
#define ADRCPOLE_h_
#ifndef ADRCPOLE_COMMON_INCLUDES_
#define ADRCPOLE_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* ADRCPOLE_COMMON_INCLUDES_ */

#include "ADRCPOLE_types.h"
#include <string.h>
#include <stddef.h>
#include "MW_target_hardware_resources.h"

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

/* Block states (default storage) for system '<S3>/Simulink1' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S6>/Unit Delay' */
  real_T DiscreteStateSpace_DSTATE[3]; /* '<S6>/Discrete State-Space' */
} DW_Simulink1_ADRCPOLE_T;

/* Block states (default storage) for system '<S10>/Simulink1' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S11>/Unit Delay' */
  real_T DiscreteStateSpace_DSTATE[3]; /* '<S11>/Discrete State-Space' */
} DW_Simulink1_ADRCPOLE_i_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_Simulink1_ADRCPOLE_i_T Simulink6; /* '<S10>/Simulink6' */
  DW_Simulink1_ADRCPOLE_i_T Simulink5; /* '<S10>/Simulink5' */
  DW_Simulink1_ADRCPOLE_i_T Simulink4_o;/* '<S10>/Simulink4' */
  DW_Simulink1_ADRCPOLE_i_T Simulink3_j;/* '<S10>/Simulink3' */
  DW_Simulink1_ADRCPOLE_i_T Simulink2_b;/* '<S10>/Simulink2' */
  DW_Simulink1_ADRCPOLE_i_T Simulink1_m;/* '<S10>/Simulink1' */
  DW_Simulink1_ADRCPOLE_T Simulink4;   /* '<S3>/Simulink4' */
  DW_Simulink1_ADRCPOLE_T Simulink3;   /* '<S3>/Simulink3' */
  DW_Simulink1_ADRCPOLE_T Simulink2;   /* '<S3>/Simulink2' */
  DW_Simulink1_ADRCPOLE_T Simulink1;   /* '<S3>/Simulink1' */
} DW_ADRCPOLE_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Airgaps[8];                 /* '<Root>/Airgaps' */
} ExtU_ADRCPOLE_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T I[10];                        /* '<Root>/I' */
} ExtY_ADRCPOLE_T;

/* Real-time Model Data Structure */
struct tag_RTM_ADRCPOLE_T {
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
  } Timing;
};

/* Block states (default storage) */
extern DW_ADRCPOLE_T ADRCPOLE_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ADRCPOLE_T ADRCPOLE_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ADRCPOLE_T ADRCPOLE_Y;

/* External function called from main */
extern void ADRCPOLE_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ADRCPOLE_initialize(void);
extern void ADRCPOLE_step0(void);      /* Sample time: [0.0005s, 0.0s] */
extern void ADRCPOLE_step1(void);      /* Sample time: [0.001s, 0.0s] */
extern void ADRCPOLE_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ADRCPOLE_T *const ADRCPOLE_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S16>/Scope' : Unused code path elimination
 */

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
 * '<Root>' : 'ADRCPOLE'
 * '<S1>'   : 'ADRCPOLE/Subsystem'
 * '<S2>'   : 'ADRCPOLE/Subsystem/Aigaps2Pos'
 * '<S3>'   : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2'
 * '<S4>'   : 'ADRCPOLE/Subsystem/Aigaps2Pos/MATLAB Function'
 * '<S5>'   : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/MATLAB Function1'
 * '<S6>'   : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Simulink1'
 * '<S7>'   : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Simulink2'
 * '<S8>'   : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Simulink3'
 * '<S9>'   : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Simulink4'
 * '<S10>'  : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Subsystem'
 * '<S11>'  : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Subsystem/Simulink1'
 * '<S12>'  : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Subsystem/Simulink2'
 * '<S13>'  : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Subsystem/Simulink3'
 * '<S14>'  : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Subsystem/Simulink4'
 * '<S15>'  : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Subsystem/Simulink5'
 * '<S16>'  : 'ADRCPOLE/Subsystem/Controlador Espacio de estados2/Subsystem/Simulink6'
 */
#endif                                 /* ADRCPOLE_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
