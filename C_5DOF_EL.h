//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: C_5DOF_EL.h
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
#ifndef C_5DOF_EL_h_
#define C_5DOF_EL_h_
#include <cmath>
#include "rtwtypes.h"
#include "C_5DOF_EL_types.h"
#include <cstring>

// Code_Instrumentation_Declarations_Placeholder

// Class declaration for model C_5DOF_EL
class C_5DOF_EL final
{
  // public data and function members
 public:
  // Block signals for system '<S1>/ControlDeCorriente'
  struct B_ControlDeCorriente_C_5DOF_E_T {
    real_T Saturation;                 // '<S385>/Saturation'
    real_T Saturation_h;               // '<S439>/Saturation'
    real_T Saturation_f;               // '<S493>/Saturation'
    real_T Saturation_d;               // '<S547>/Saturation'
    real_T Saturation_k;               // '<S61>/Saturation'
    real_T Saturation_dd;              // '<S115>/Saturation'
    real_T Saturation_o;               // '<S169>/Saturation'
    real_T Saturation_p;               // '<S223>/Saturation'
    real_T Saturation_oe;              // '<S277>/Saturation'
    real_T Saturation_j;               // '<S331>/Saturation'
    real_T DeadZone;                   // '<S316>/DeadZone'
    real_T Sum;                        // '<S333>/Sum'
    real_T IntegralGain;               // '<S321>/Integral Gain'
    real_T Integrator;
    real_T Integrator_d;
    real_T Integrator_k;
    real_T Integrator_p;
    real_T Integrator_pa;
    real_T Integrator_m;
    real_T Integrator_a;
    real_T Integrator_f;
    real_T Integrator_e;
    real_T Integrator_tmp;
    real_T Integrator_d_tmp;
  };

  // Block states (default storage) for system '<S1>/ControlDeCorriente'
  struct DW_ControlDeCorriente_C_5DOF__T {
    real_T Integrator_DSTATE;          // '<S378>/Integrator'
    real_T Integrator_DSTATE_o;        // '<S432>/Integrator'
    real_T Integrator_DSTATE_c;        // '<S486>/Integrator'
    real_T Integrator_DSTATE_om;       // '<S540>/Integrator'
    real_T Integrator_DSTATE_b;        // '<S54>/Integrator'
    real_T Integrator_DSTATE_bd;       // '<S108>/Integrator'
    real_T Integrator_DSTATE_p;        // '<S162>/Integrator'
    real_T Integrator_DSTATE_g;        // '<S216>/Integrator'
    real_T Integrator_DSTATE_gi;       // '<S270>/Integrator'
    real_T Integrator_DSTATE_px;       // '<S324>/Integrator'
  };

  // Block signals (default storage)
  struct B_C_5DOF_EL_T {
    real_T H[40];
    real_T A[25];
    real_T b[8];
    real_T TmpRTBAtMezcladorOutport1[6];// '<S4>/Mezclador'
    real_T AG_mm[6];                   // '<S4>/AG_mm'
    real_T TmpSignalConversionAtKin_EM[6];
    real_T F_des_n[6];                 // '<S4>/Mezclador'
    real_T u[5];                       // '<Root>/GapToStates'
    real_T TmpSignalConversionAtKin_HE[4];
    real_T dv[3];
    real_T Roll[3];                    // '<S6>/Roll'
    real_T Z[3];                       // '<S6>/Z'
    real_T TmpRTBAtYInport1[2];
    real_T TmpRTBAtYawInport1[2];
    real_T TmpRTBAtPitchInport1[2];
    real_T TmpRTBAtRollInport1[2];
    real_T TmpRTBAtSum3_ZInport2;
    real_T TmpRTBAtSum2_ZInport2;      // '<S6>/Kd_Z'
    real_T TmpRTBAtSumErr_ZInport2;
    real_T TmpRTBAtb0_RollOutport1;    // '<S6>/b0_Roll'
    real_T TmpRTBAtb0_PitchOutport1;   // '<S6>/b0_Pitch'
    real_T smax;
    real_T s;
    real_T unnamed_idx_1;
    real_T unnamed_idx_2;
    real_T rtb_airgaps_actuadores_idx_0_tm;
    real_T rtb_airgaps_actuadores_idx_0__c;
    real_T rtb_airgaps_actuadores_idx_4_tm;
    real_T rtb_airgaps_actuadores_idx_4__c;
    real_T rtb_airgaps_actuadores_idx_4__b;
    real_T rtb_airgaps_actuadores_idx_4__p;
    real_T rtb_airgaps_actuadores_idx_5_tm;
    real_T unnamed_idx_0_tmp;
    real_T d;
    real_T d1;
    real_T unnamed_idx_1_tmp;
    int8_T ipiv[5];
    int32_T jj;
    int32_T b_j;
    int32_T ix;
    int32_T b_ix;
    int32_T iy;
    int32_T ijA;
    B_ControlDeCorriente_C_5DOF_E_T ControlDeCorriente;// '<S1>/ControlDeCorriente' 
  };

  // Block states (default storage) for system '<Root>'
  struct DW_C_5DOF_EL_T {
    real_T UnitDelay_DSTATE[5];        // '<S1>/UnitDelay'
    real_T Y_DSTATE[3];                // '<S4>/Y'
    real_T Yaw_DSTATE[3];              // '<S4>/Yaw'
    real_T Pitch_DSTATE[3];            // '<S6>/Pitch'
    real_T Roll_DSTATE[3];             // '<S6>/Roll'
    real_T Z_DSTATE[3];                // '<S6>/Z'
    real_T TmpRTBAtMezcladorOutport1_Buffe[6];// synthesized block
    real_T TmpRTBAtSum3_ZInport2_Buffer0;// synthesized block
    real_T TmpRTBAtSum2_ZInport2_Buffer0;// synthesized block
    real_T TmpRTBAtSumErr_ZInport2_Buffer0;// synthesized block
    real_T TmpRTBAtb0_RollOutport1_Buffer0;// synthesized block
    real_T TmpRTBAtb0_PitchOutport1_Buffer;// synthesized block
    real_T TmpRTBAtYInport1_Buffer[2]; // synthesized block
    real_T TmpRTBAtYawInport1_Buffer[2];// synthesized block
    real_T TmpRTBAtPitchInport1_Buffer[2];// synthesized block
    real_T TmpRTBAtRollInport1_Buffer[2];// synthesized block
    real_T TmpRTBAtZInport1_Buffer[2]; // synthesized block
    real_T H_pseudo[40];               // '<Root>/GapToStates'
    boolean_T H_pseudo_not_empty;      // '<Root>/GapToStates'
    DW_ControlDeCorriente_C_5DOF__T ControlDeCorriente;// '<S1>/ControlDeCorriente' 
  };

  // Constant parameters (default storage)
  struct ConstP_C_5DOF_EL_T {
    // Pooled Parameter (Expression: ems_inv_I_table)
    //  Referenced by:
    //    '<S4>/InvLUT_1'
    //    '<S4>/InvLUT_2'
    //    '<S4>/InvLUT_3'
    //    '<S4>/InvLUT_4'
    //    '<S4>/InvLUT_5'
    //    '<S4>/InvLUT_6'

    real_T pooled10[2600];

    // Pooled Parameter (Mixed Expressions)
    //  Referenced by:
    //    '<S4>/InvLUT_1'
    //    '<S4>/InvLUT_2'
    //    '<S4>/InvLUT_3'
    //    '<S4>/InvLUT_4'
    //    '<S4>/InvLUT_5'
    //    '<S4>/InvLUT_6'
    //    '<S5>/LUT_EMS_1'
    //    '<S5>/LUT_EMS_2'
    //    '<S5>/LUT_EMS_3'
    //    '<S5>/LUT_EMS_4'
    //    '<S5>/LUT_EMS_5'
    //    '<S5>/LUT_EMS_6'

    real_T pooled11[13];

    // Pooled Parameter (Expression: ems_inv_F_bp)
    //  Referenced by:
    //    '<S4>/InvLUT_1'
    //    '<S4>/InvLUT_2'
    //    '<S4>/InvLUT_3'
    //    '<S4>/InvLUT_4'
    //    '<S4>/InvLUT_5'
    //    '<S4>/InvLUT_6'

    real_T pooled12[200];

    // Pooled Parameter (Expression: hems_inv_I_table)
    //  Referenced by:
    //    '<S6>/InvLUT_1'
    //    '<S6>/InvLUT_2'
    //    '<S6>/InvLUT_3'
    //    '<S6>/InvLUT_4'

    real_T pooled15[2800];

    // Pooled Parameter (Mixed Expressions)
    //  Referenced by:
    //    '<S5>/LUT_HEMS_1'
    //    '<S5>/LUT_HEMS_2'
    //    '<S5>/LUT_HEMS_3'
    //    '<S5>/LUT_HEMS_4'
    //    '<S6>/InvLUT_1'
    //    '<S6>/InvLUT_2'
    //    '<S6>/InvLUT_3'
    //    '<S6>/InvLUT_4'

    real_T pooled16[14];

    // Pooled Parameter (Expression: hems_inv_F_bp)
    //  Referenced by:
    //    '<S6>/InvLUT_1'
    //    '<S6>/InvLUT_2'
    //    '<S6>/InvLUT_3'
    //    '<S6>/InvLUT_4'

    real_T pooled17[200];

    // Pooled Parameter (Expression: ems_direct_F_table)
    //  Referenced by:
    //    '<S5>/LUT_EMS_1'
    //    '<S5>/LUT_EMS_2'
    //    '<S5>/LUT_EMS_3'
    //    '<S5>/LUT_EMS_4'
    //    '<S5>/LUT_EMS_5'
    //    '<S5>/LUT_EMS_6'

    real_T pooled18[728];

    // Pooled Parameter (Expression: ems_direct_I_bp)
    //  Referenced by:
    //    '<S5>/LUT_EMS_1'
    //    '<S5>/LUT_EMS_2'
    //    '<S5>/LUT_EMS_3'
    //    '<S5>/LUT_EMS_4'
    //    '<S5>/LUT_EMS_5'
    //    '<S5>/LUT_EMS_6'

    real_T pooled19[56];

    // Pooled Parameter (Expression: hems_direct_F_table)
    //  Referenced by:
    //    '<S5>/LUT_HEMS_1'
    //    '<S5>/LUT_HEMS_2'
    //    '<S5>/LUT_HEMS_3'
    //    '<S5>/LUT_HEMS_4'

    real_T pooled20[1554];

    // Pooled Parameter (Expression: hems_direct_I_bp)
    //  Referenced by:
    //    '<S5>/LUT_HEMS_1'
    //    '<S5>/LUT_HEMS_2'
    //    '<S5>/LUT_HEMS_3'
    //    '<S5>/LUT_HEMS_4'

    real_T pooled21[111];

    // Expression: K_kin_hems
    //  Referenced by: '<S5>/Kin_HEMS'

    real_T Kin_HEMS_Gain[12];

    // Expression: K_kin_ems
    //  Referenced by: '<S5>/Kin_EMS'

    real_T Kin_EMS_Gain[12];

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S4>/InvLUT_1'
    //    '<S4>/InvLUT_2'
    //    '<S4>/InvLUT_3'
    //    '<S4>/InvLUT_4'
    //    '<S4>/InvLUT_5'
    //    '<S4>/InvLUT_6'

    uint32_T pooled31[2];

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S6>/InvLUT_1'
    //    '<S6>/InvLUT_2'
    //    '<S6>/InvLUT_3'
    //    '<S6>/InvLUT_4'

    uint32_T pooled32[2];

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S5>/LUT_EMS_1'
    //    '<S5>/LUT_EMS_2'
    //    '<S5>/LUT_EMS_3'
    //    '<S5>/LUT_EMS_4'
    //    '<S5>/LUT_EMS_5'
    //    '<S5>/LUT_EMS_6'

    uint32_T pooled33[2];

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S5>/LUT_HEMS_1'
    //    '<S5>/LUT_HEMS_2'
    //    '<S5>/LUT_HEMS_3'
    //    '<S5>/LUT_HEMS_4'

    uint32_T pooled34[2];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_C_5DOF_EL_T {
    AIRGAP_Bus SensoresPos;            // '<Root>/SensoresPos'
    HEMS I_HEMS;                       // '<Root>/I_HEMS'
    EMS I_EMS;                         // '<Root>/I_EMS'
    real_T RefZ;                       // '<Root>/RefZ'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_C_5DOF_EL_T {
    V V_h;                             // '<Root>/V'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_C_5DOF_EL_T {
    const char_T * volatile errorStatus;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      struct {
        uint8_T TID[2];
        uint8_T cLimit[2];
      } TaskCounters;

      struct {
        uint8_T TID0_1;
      } RateInteraction;
    } Timing;

    boolean_T StepTask(int32_T idx) const;
    uint8_T &CounterLimit(int32_T idx);
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
    uint8_T &TaskCounter(int32_T idx);
  };

  // Copy Constructor
  C_5DOF_EL(C_5DOF_EL const&) = delete;

  // Assignment Operator
  C_5DOF_EL& operator= (C_5DOF_EL const&) & = delete;

  // Move Constructor
  C_5DOF_EL(C_5DOF_EL &&) = delete;

  // Move Assignment Operator
  C_5DOF_EL& operator= (C_5DOF_EL &&) = delete;

  // Real-Time Model get method
  C_5DOF_EL::RT_MODEL_C_5DOF_EL_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_C_5DOF_EL_T *pExtU_C_5DOF_EL_T)
  {
    C_5DOF_EL_U = *pExtU_C_5DOF_EL_T;
  }

  // Root outports get method
  const ExtY_C_5DOF_EL_T &getExternalOutputs() const
  {
    return C_5DOF_EL_Y;
  }

  // model initialize function
  void initialize();

  // model step function
  void step0();

  // model step function
  void step1();

  // model terminate function
  static void terminate();

  // Constructor
  C_5DOF_EL();

  // Destructor
  ~C_5DOF_EL();

  // private data and function members
 private:
  // External inputs
  ExtU_C_5DOF_EL_T C_5DOF_EL_U;

  // External outputs
  ExtY_C_5DOF_EL_T C_5DOF_EL_Y;

  // Block signals
  B_C_5DOF_EL_T C_5DOF_EL_B;

  // Block states
  DW_C_5DOF_EL_T C_5DOF_EL_DW;

  // private member function(s) for subsystem '<S1>/ControlDeCorriente'
  static void C_5DOF_E_ControlDeCorriente(const real_T rtu_CorrienteRefHEMS[4],
    const HEMS *rtu_I_real_hems, const EMS *rtu_I_real_ems, const real_T
    rtu_CorrienteRefEMS[6], B_ControlDeCorriente_C_5DOF_E_T *localB,
    DW_ControlDeCorriente_C_5DOF__T *localDW);

  // Real-Time Model
  RT_MODEL_C_5DOF_EL_T C_5DOF_EL_M;
};

// Constant parameters (default storage)
extern const C_5DOF_EL::ConstP_C_5DOF_EL_T C_5DOF_EL_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/RT_Iref_EMS' : Eliminated since input and output rates are identical
//  Block '<S3>/RT_Iref_HEMS' : Eliminated since input and output rates are identical


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'C_5DOF_EL'
//  '<S1>'   : 'C_5DOF_EL/Controlador '
//  '<S2>'   : 'C_5DOF_EL/GapToStates'
//  '<S3>'   : 'C_5DOF_EL/Controlador /ControlDeCorriente'
//  '<S4>'   : 'C_5DOF_EL/Controlador /E'
//  '<S5>'   : 'C_5DOF_EL/Controlador /Eff'
//  '<S6>'   : 'C_5DOF_EL/Controlador /H'
//  '<S7>'   : 'C_5DOF_EL/Controlador /MATLAB Function1'
//  '<S8>'   : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller'
//  '<S9>'   : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1'
//  '<S10>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2'
//  '<S11>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3'
//  '<S12>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4'
//  '<S13>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5'
//  '<S14>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6'
//  '<S15>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7'
//  '<S16>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8'
//  '<S17>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9'
//  '<S18>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Anti-windup'
//  '<S19>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/D Gain'
//  '<S20>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/External Derivative'
//  '<S21>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Filter'
//  '<S22>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Filter ICs'
//  '<S23>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/I Gain'
//  '<S24>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Ideal P Gain'
//  '<S25>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Ideal P Gain Fdbk'
//  '<S26>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Integrator'
//  '<S27>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Integrator ICs'
//  '<S28>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/N Copy'
//  '<S29>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/N Gain'
//  '<S30>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/P Copy'
//  '<S31>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Parallel P Gain'
//  '<S32>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Reset Signal'
//  '<S33>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Saturation'
//  '<S34>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Saturation Fdbk'
//  '<S35>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Sum'
//  '<S36>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Sum Fdbk'
//  '<S37>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Tracking Mode'
//  '<S38>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Tracking Mode Sum'
//  '<S39>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Tsamp - Integral'
//  '<S40>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Tsamp - Ngain'
//  '<S41>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/postSat Signal'
//  '<S42>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/preInt Signal'
//  '<S43>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/preSat Signal'
//  '<S44>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S45>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S46>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S47>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/D Gain/Disabled'
//  '<S48>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/External Derivative/Disabled'
//  '<S49>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Filter/Disabled'
//  '<S50>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Filter ICs/Disabled'
//  '<S51>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/I Gain/Internal Parameters'
//  '<S52>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Ideal P Gain/Passthrough'
//  '<S53>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Ideal P Gain Fdbk/Passthrough'
//  '<S54>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Integrator/Discrete'
//  '<S55>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Integrator ICs/Internal IC'
//  '<S56>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S57>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/N Gain/Disabled'
//  '<S58>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/P Copy/Disabled'
//  '<S59>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S60>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Reset Signal/Disabled'
//  '<S61>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Saturation/Enabled'
//  '<S62>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Saturation Fdbk/Passthrough'
//  '<S63>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Sum/Sum_PI'
//  '<S64>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Sum Fdbk/Enabled'
//  '<S65>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Tracking Mode/Disabled'
//  '<S66>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S67>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S68>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S69>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/postSat Signal/Feedback_Path'
//  '<S70>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/preInt Signal/Internal PreInt'
//  '<S71>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller/preSat Signal/Feedback_Path'
//  '<S72>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Anti-windup'
//  '<S73>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/D Gain'
//  '<S74>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/External Derivative'
//  '<S75>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Filter'
//  '<S76>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Filter ICs'
//  '<S77>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/I Gain'
//  '<S78>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Ideal P Gain'
//  '<S79>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Ideal P Gain Fdbk'
//  '<S80>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Integrator'
//  '<S81>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Integrator ICs'
//  '<S82>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/N Copy'
//  '<S83>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/N Gain'
//  '<S84>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/P Copy'
//  '<S85>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Parallel P Gain'
//  '<S86>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Reset Signal'
//  '<S87>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Saturation'
//  '<S88>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Saturation Fdbk'
//  '<S89>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Sum'
//  '<S90>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Sum Fdbk'
//  '<S91>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Tracking Mode'
//  '<S92>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Tracking Mode Sum'
//  '<S93>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Tsamp - Integral'
//  '<S94>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Tsamp - Ngain'
//  '<S95>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/postSat Signal'
//  '<S96>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/preInt Signal'
//  '<S97>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/preSat Signal'
//  '<S98>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S99>'  : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S100>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S101>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/D Gain/Disabled'
//  '<S102>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/External Derivative/Disabled'
//  '<S103>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Filter/Disabled'
//  '<S104>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Filter ICs/Disabled'
//  '<S105>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/I Gain/Internal Parameters'
//  '<S106>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Ideal P Gain/Passthrough'
//  '<S107>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Ideal P Gain Fdbk/Passthrough'
//  '<S108>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Integrator/Discrete'
//  '<S109>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Integrator ICs/Internal IC'
//  '<S110>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S111>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/N Gain/Disabled'
//  '<S112>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/P Copy/Disabled'
//  '<S113>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S114>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Reset Signal/Disabled'
//  '<S115>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Saturation/Enabled'
//  '<S116>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Saturation Fdbk/Passthrough'
//  '<S117>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Sum/Sum_PI'
//  '<S118>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Sum Fdbk/Enabled'
//  '<S119>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Tracking Mode/Disabled'
//  '<S120>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S121>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S122>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S123>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/postSat Signal/Feedback_Path'
//  '<S124>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/preInt Signal/Internal PreInt'
//  '<S125>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller1/preSat Signal/Feedback_Path'
//  '<S126>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Anti-windup'
//  '<S127>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/D Gain'
//  '<S128>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/External Derivative'
//  '<S129>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Filter'
//  '<S130>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Filter ICs'
//  '<S131>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/I Gain'
//  '<S132>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Ideal P Gain'
//  '<S133>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Ideal P Gain Fdbk'
//  '<S134>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Integrator'
//  '<S135>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Integrator ICs'
//  '<S136>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/N Copy'
//  '<S137>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/N Gain'
//  '<S138>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/P Copy'
//  '<S139>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Parallel P Gain'
//  '<S140>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Reset Signal'
//  '<S141>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Saturation'
//  '<S142>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Saturation Fdbk'
//  '<S143>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Sum'
//  '<S144>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Sum Fdbk'
//  '<S145>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Tracking Mode'
//  '<S146>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Tracking Mode Sum'
//  '<S147>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Tsamp - Integral'
//  '<S148>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Tsamp - Ngain'
//  '<S149>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/postSat Signal'
//  '<S150>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/preInt Signal'
//  '<S151>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/preSat Signal'
//  '<S152>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S153>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S154>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S155>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/D Gain/Disabled'
//  '<S156>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/External Derivative/Disabled'
//  '<S157>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Filter/Disabled'
//  '<S158>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Filter ICs/Disabled'
//  '<S159>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/I Gain/Internal Parameters'
//  '<S160>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Ideal P Gain/Passthrough'
//  '<S161>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Ideal P Gain Fdbk/Passthrough'
//  '<S162>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Integrator/Discrete'
//  '<S163>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Integrator ICs/Internal IC'
//  '<S164>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S165>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/N Gain/Disabled'
//  '<S166>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/P Copy/Disabled'
//  '<S167>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S168>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Reset Signal/Disabled'
//  '<S169>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Saturation/Enabled'
//  '<S170>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Saturation Fdbk/Passthrough'
//  '<S171>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Sum/Sum_PI'
//  '<S172>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Sum Fdbk/Enabled'
//  '<S173>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Tracking Mode/Disabled'
//  '<S174>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S175>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S176>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S177>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/postSat Signal/Feedback_Path'
//  '<S178>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/preInt Signal/Internal PreInt'
//  '<S179>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller2/preSat Signal/Feedback_Path'
//  '<S180>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Anti-windup'
//  '<S181>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/D Gain'
//  '<S182>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/External Derivative'
//  '<S183>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Filter'
//  '<S184>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Filter ICs'
//  '<S185>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/I Gain'
//  '<S186>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Ideal P Gain'
//  '<S187>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Ideal P Gain Fdbk'
//  '<S188>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Integrator'
//  '<S189>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Integrator ICs'
//  '<S190>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/N Copy'
//  '<S191>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/N Gain'
//  '<S192>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/P Copy'
//  '<S193>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Parallel P Gain'
//  '<S194>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Reset Signal'
//  '<S195>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Saturation'
//  '<S196>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Saturation Fdbk'
//  '<S197>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Sum'
//  '<S198>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Sum Fdbk'
//  '<S199>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Tracking Mode'
//  '<S200>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Tracking Mode Sum'
//  '<S201>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Tsamp - Integral'
//  '<S202>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Tsamp - Ngain'
//  '<S203>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/postSat Signal'
//  '<S204>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/preInt Signal'
//  '<S205>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/preSat Signal'
//  '<S206>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Anti-windup/Disc. Clamping Parallel'
//  '<S207>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S208>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S209>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/D Gain/Disabled'
//  '<S210>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/External Derivative/Disabled'
//  '<S211>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Filter/Disabled'
//  '<S212>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Filter ICs/Disabled'
//  '<S213>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/I Gain/Internal Parameters'
//  '<S214>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Ideal P Gain/Passthrough'
//  '<S215>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Ideal P Gain Fdbk/Passthrough'
//  '<S216>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Integrator/Discrete'
//  '<S217>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Integrator ICs/Internal IC'
//  '<S218>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S219>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/N Gain/Disabled'
//  '<S220>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/P Copy/Disabled'
//  '<S221>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S222>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Reset Signal/Disabled'
//  '<S223>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Saturation/Enabled'
//  '<S224>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Saturation Fdbk/Passthrough'
//  '<S225>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Sum/Sum_PI'
//  '<S226>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Sum Fdbk/Enabled'
//  '<S227>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Tracking Mode/Disabled'
//  '<S228>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S229>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S230>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S231>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/postSat Signal/Feedback_Path'
//  '<S232>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/preInt Signal/Internal PreInt'
//  '<S233>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller3/preSat Signal/Feedback_Path'
//  '<S234>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Anti-windup'
//  '<S235>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/D Gain'
//  '<S236>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/External Derivative'
//  '<S237>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Filter'
//  '<S238>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Filter ICs'
//  '<S239>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/I Gain'
//  '<S240>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Ideal P Gain'
//  '<S241>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Ideal P Gain Fdbk'
//  '<S242>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Integrator'
//  '<S243>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Integrator ICs'
//  '<S244>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/N Copy'
//  '<S245>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/N Gain'
//  '<S246>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/P Copy'
//  '<S247>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Parallel P Gain'
//  '<S248>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Reset Signal'
//  '<S249>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Saturation'
//  '<S250>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Saturation Fdbk'
//  '<S251>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Sum'
//  '<S252>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Sum Fdbk'
//  '<S253>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Tracking Mode'
//  '<S254>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Tracking Mode Sum'
//  '<S255>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Tsamp - Integral'
//  '<S256>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Tsamp - Ngain'
//  '<S257>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/postSat Signal'
//  '<S258>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/preInt Signal'
//  '<S259>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/preSat Signal'
//  '<S260>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S261>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S262>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S263>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/D Gain/Disabled'
//  '<S264>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/External Derivative/Disabled'
//  '<S265>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Filter/Disabled'
//  '<S266>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Filter ICs/Disabled'
//  '<S267>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/I Gain/Internal Parameters'
//  '<S268>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Ideal P Gain/Passthrough'
//  '<S269>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Ideal P Gain Fdbk/Passthrough'
//  '<S270>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Integrator/Discrete'
//  '<S271>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Integrator ICs/Internal IC'
//  '<S272>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S273>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/N Gain/Disabled'
//  '<S274>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/P Copy/Disabled'
//  '<S275>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S276>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Reset Signal/Disabled'
//  '<S277>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Saturation/Enabled'
//  '<S278>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Saturation Fdbk/Passthrough'
//  '<S279>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Sum/Sum_PI'
//  '<S280>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Sum Fdbk/Enabled'
//  '<S281>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Tracking Mode/Disabled'
//  '<S282>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S283>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S284>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S285>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/postSat Signal/Feedback_Path'
//  '<S286>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/preInt Signal/Internal PreInt'
//  '<S287>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller4/preSat Signal/Feedback_Path'
//  '<S288>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Anti-windup'
//  '<S289>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/D Gain'
//  '<S290>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/External Derivative'
//  '<S291>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Filter'
//  '<S292>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Filter ICs'
//  '<S293>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/I Gain'
//  '<S294>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Ideal P Gain'
//  '<S295>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Ideal P Gain Fdbk'
//  '<S296>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Integrator'
//  '<S297>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Integrator ICs'
//  '<S298>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/N Copy'
//  '<S299>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/N Gain'
//  '<S300>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/P Copy'
//  '<S301>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Parallel P Gain'
//  '<S302>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Reset Signal'
//  '<S303>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Saturation'
//  '<S304>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Saturation Fdbk'
//  '<S305>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Sum'
//  '<S306>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Sum Fdbk'
//  '<S307>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Tracking Mode'
//  '<S308>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Tracking Mode Sum'
//  '<S309>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Tsamp - Integral'
//  '<S310>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Tsamp - Ngain'
//  '<S311>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/postSat Signal'
//  '<S312>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/preInt Signal'
//  '<S313>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/preSat Signal'
//  '<S314>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Anti-windup/Disc. Clamping Parallel'
//  '<S315>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S316>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S317>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/D Gain/Disabled'
//  '<S318>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/External Derivative/Disabled'
//  '<S319>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Filter/Disabled'
//  '<S320>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Filter ICs/Disabled'
//  '<S321>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/I Gain/Internal Parameters'
//  '<S322>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Ideal P Gain/Passthrough'
//  '<S323>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Ideal P Gain Fdbk/Passthrough'
//  '<S324>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Integrator/Discrete'
//  '<S325>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Integrator ICs/Internal IC'
//  '<S326>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S327>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/N Gain/Disabled'
//  '<S328>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/P Copy/Disabled'
//  '<S329>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S330>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Reset Signal/Disabled'
//  '<S331>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Saturation/Enabled'
//  '<S332>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Saturation Fdbk/Passthrough'
//  '<S333>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Sum/Sum_PI'
//  '<S334>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Sum Fdbk/Enabled'
//  '<S335>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Tracking Mode/Disabled'
//  '<S336>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S337>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S338>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S339>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/postSat Signal/Feedback_Path'
//  '<S340>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/preInt Signal/Internal PreInt'
//  '<S341>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller5/preSat Signal/Feedback_Path'
//  '<S342>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Anti-windup'
//  '<S343>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/D Gain'
//  '<S344>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/External Derivative'
//  '<S345>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Filter'
//  '<S346>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Filter ICs'
//  '<S347>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/I Gain'
//  '<S348>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Ideal P Gain'
//  '<S349>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Ideal P Gain Fdbk'
//  '<S350>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Integrator'
//  '<S351>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Integrator ICs'
//  '<S352>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/N Copy'
//  '<S353>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/N Gain'
//  '<S354>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/P Copy'
//  '<S355>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Parallel P Gain'
//  '<S356>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Reset Signal'
//  '<S357>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Saturation'
//  '<S358>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Saturation Fdbk'
//  '<S359>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Sum'
//  '<S360>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Sum Fdbk'
//  '<S361>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Tracking Mode'
//  '<S362>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Tracking Mode Sum'
//  '<S363>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Tsamp - Integral'
//  '<S364>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Tsamp - Ngain'
//  '<S365>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/postSat Signal'
//  '<S366>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/preInt Signal'
//  '<S367>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/preSat Signal'
//  '<S368>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Anti-windup/Disc. Clamping Parallel'
//  '<S369>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S370>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S371>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/D Gain/Disabled'
//  '<S372>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/External Derivative/Disabled'
//  '<S373>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Filter/Disabled'
//  '<S374>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Filter ICs/Disabled'
//  '<S375>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/I Gain/Internal Parameters'
//  '<S376>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Ideal P Gain/Passthrough'
//  '<S377>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Ideal P Gain Fdbk/Passthrough'
//  '<S378>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Integrator/Discrete'
//  '<S379>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Integrator ICs/Internal IC'
//  '<S380>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/N Copy/Disabled wSignal Specification'
//  '<S381>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/N Gain/Disabled'
//  '<S382>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/P Copy/Disabled'
//  '<S383>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Parallel P Gain/Internal Parameters'
//  '<S384>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Reset Signal/Disabled'
//  '<S385>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Saturation/Enabled'
//  '<S386>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Saturation Fdbk/Passthrough'
//  '<S387>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Sum/Sum_PI'
//  '<S388>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Sum Fdbk/Enabled'
//  '<S389>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Tracking Mode/Disabled'
//  '<S390>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Tracking Mode Sum/Passthrough'
//  '<S391>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Tsamp - Integral/TsSignalSpecification'
//  '<S392>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/Tsamp - Ngain/Passthrough'
//  '<S393>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/postSat Signal/Feedback_Path'
//  '<S394>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/preInt Signal/Internal PreInt'
//  '<S395>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller6/preSat Signal/Feedback_Path'
//  '<S396>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Anti-windup'
//  '<S397>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/D Gain'
//  '<S398>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/External Derivative'
//  '<S399>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Filter'
//  '<S400>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Filter ICs'
//  '<S401>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/I Gain'
//  '<S402>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Ideal P Gain'
//  '<S403>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Ideal P Gain Fdbk'
//  '<S404>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Integrator'
//  '<S405>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Integrator ICs'
//  '<S406>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/N Copy'
//  '<S407>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/N Gain'
//  '<S408>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/P Copy'
//  '<S409>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Parallel P Gain'
//  '<S410>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Reset Signal'
//  '<S411>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Saturation'
//  '<S412>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Saturation Fdbk'
//  '<S413>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Sum'
//  '<S414>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Sum Fdbk'
//  '<S415>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Tracking Mode'
//  '<S416>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Tracking Mode Sum'
//  '<S417>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Tsamp - Integral'
//  '<S418>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Tsamp - Ngain'
//  '<S419>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/postSat Signal'
//  '<S420>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/preInt Signal'
//  '<S421>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/preSat Signal'
//  '<S422>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Anti-windup/Disc. Clamping Parallel'
//  '<S423>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S424>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S425>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/D Gain/Disabled'
//  '<S426>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/External Derivative/Disabled'
//  '<S427>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Filter/Disabled'
//  '<S428>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Filter ICs/Disabled'
//  '<S429>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/I Gain/Internal Parameters'
//  '<S430>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Ideal P Gain/Passthrough'
//  '<S431>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Ideal P Gain Fdbk/Passthrough'
//  '<S432>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Integrator/Discrete'
//  '<S433>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Integrator ICs/Internal IC'
//  '<S434>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/N Copy/Disabled wSignal Specification'
//  '<S435>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/N Gain/Disabled'
//  '<S436>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/P Copy/Disabled'
//  '<S437>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Parallel P Gain/Internal Parameters'
//  '<S438>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Reset Signal/Disabled'
//  '<S439>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Saturation/Enabled'
//  '<S440>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Saturation Fdbk/Passthrough'
//  '<S441>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Sum/Sum_PI'
//  '<S442>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Sum Fdbk/Enabled'
//  '<S443>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Tracking Mode/Disabled'
//  '<S444>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Tracking Mode Sum/Passthrough'
//  '<S445>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Tsamp - Integral/TsSignalSpecification'
//  '<S446>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/Tsamp - Ngain/Passthrough'
//  '<S447>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/postSat Signal/Feedback_Path'
//  '<S448>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/preInt Signal/Internal PreInt'
//  '<S449>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller7/preSat Signal/Feedback_Path'
//  '<S450>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Anti-windup'
//  '<S451>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/D Gain'
//  '<S452>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/External Derivative'
//  '<S453>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Filter'
//  '<S454>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Filter ICs'
//  '<S455>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/I Gain'
//  '<S456>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Ideal P Gain'
//  '<S457>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Ideal P Gain Fdbk'
//  '<S458>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Integrator'
//  '<S459>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Integrator ICs'
//  '<S460>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/N Copy'
//  '<S461>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/N Gain'
//  '<S462>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/P Copy'
//  '<S463>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Parallel P Gain'
//  '<S464>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Reset Signal'
//  '<S465>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Saturation'
//  '<S466>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Saturation Fdbk'
//  '<S467>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Sum'
//  '<S468>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Sum Fdbk'
//  '<S469>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Tracking Mode'
//  '<S470>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Tracking Mode Sum'
//  '<S471>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Tsamp - Integral'
//  '<S472>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Tsamp - Ngain'
//  '<S473>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/postSat Signal'
//  '<S474>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/preInt Signal'
//  '<S475>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/preSat Signal'
//  '<S476>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Anti-windup/Disc. Clamping Parallel'
//  '<S477>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S478>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S479>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/D Gain/Disabled'
//  '<S480>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/External Derivative/Disabled'
//  '<S481>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Filter/Disabled'
//  '<S482>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Filter ICs/Disabled'
//  '<S483>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/I Gain/Internal Parameters'
//  '<S484>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Ideal P Gain/Passthrough'
//  '<S485>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Ideal P Gain Fdbk/Passthrough'
//  '<S486>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Integrator/Discrete'
//  '<S487>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Integrator ICs/Internal IC'
//  '<S488>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/N Copy/Disabled wSignal Specification'
//  '<S489>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/N Gain/Disabled'
//  '<S490>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/P Copy/Disabled'
//  '<S491>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Parallel P Gain/Internal Parameters'
//  '<S492>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Reset Signal/Disabled'
//  '<S493>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Saturation/Enabled'
//  '<S494>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Saturation Fdbk/Passthrough'
//  '<S495>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Sum/Sum_PI'
//  '<S496>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Sum Fdbk/Enabled'
//  '<S497>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Tracking Mode/Disabled'
//  '<S498>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Tracking Mode Sum/Passthrough'
//  '<S499>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Tsamp - Integral/TsSignalSpecification'
//  '<S500>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/Tsamp - Ngain/Passthrough'
//  '<S501>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/postSat Signal/Feedback_Path'
//  '<S502>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/preInt Signal/Internal PreInt'
//  '<S503>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller8/preSat Signal/Feedback_Path'
//  '<S504>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Anti-windup'
//  '<S505>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/D Gain'
//  '<S506>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/External Derivative'
//  '<S507>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Filter'
//  '<S508>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Filter ICs'
//  '<S509>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/I Gain'
//  '<S510>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Ideal P Gain'
//  '<S511>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Ideal P Gain Fdbk'
//  '<S512>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Integrator'
//  '<S513>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Integrator ICs'
//  '<S514>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/N Copy'
//  '<S515>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/N Gain'
//  '<S516>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/P Copy'
//  '<S517>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Parallel P Gain'
//  '<S518>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Reset Signal'
//  '<S519>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Saturation'
//  '<S520>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Saturation Fdbk'
//  '<S521>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Sum'
//  '<S522>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Sum Fdbk'
//  '<S523>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Tracking Mode'
//  '<S524>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Tracking Mode Sum'
//  '<S525>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Tsamp - Integral'
//  '<S526>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Tsamp - Ngain'
//  '<S527>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/postSat Signal'
//  '<S528>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/preInt Signal'
//  '<S529>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/preSat Signal'
//  '<S530>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Anti-windup/Disc. Clamping Parallel'
//  '<S531>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S532>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S533>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/D Gain/Disabled'
//  '<S534>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/External Derivative/Disabled'
//  '<S535>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Filter/Disabled'
//  '<S536>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Filter ICs/Disabled'
//  '<S537>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/I Gain/Internal Parameters'
//  '<S538>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Ideal P Gain/Passthrough'
//  '<S539>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Ideal P Gain Fdbk/Passthrough'
//  '<S540>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Integrator/Discrete'
//  '<S541>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Integrator ICs/Internal IC'
//  '<S542>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/N Copy/Disabled wSignal Specification'
//  '<S543>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/N Gain/Disabled'
//  '<S544>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/P Copy/Disabled'
//  '<S545>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Parallel P Gain/Internal Parameters'
//  '<S546>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Reset Signal/Disabled'
//  '<S547>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Saturation/Enabled'
//  '<S548>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Saturation Fdbk/Passthrough'
//  '<S549>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Sum/Sum_PI'
//  '<S550>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Sum Fdbk/Enabled'
//  '<S551>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Tracking Mode/Disabled'
//  '<S552>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Tracking Mode Sum/Passthrough'
//  '<S553>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Tsamp - Integral/TsSignalSpecification'
//  '<S554>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/Tsamp - Ngain/Passthrough'
//  '<S555>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/postSat Signal/Feedback_Path'
//  '<S556>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/preInt Signal/Internal PreInt'
//  '<S557>' : 'C_5DOF_EL/Controlador /ControlDeCorriente/PID Controller9/preSat Signal/Feedback_Path'
//  '<S558>' : 'C_5DOF_EL/Controlador /E/Mezclador'
//  '<S559>' : 'C_5DOF_EL/Controlador /H/Mezclador'

#endif                                 // C_5DOF_EL_h_

//
// File trailer for generated code.
//
// [EOF]
//
