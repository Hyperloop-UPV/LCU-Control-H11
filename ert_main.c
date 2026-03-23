/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include "ADRCPOLE.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  ADRCPOLE_SetEventsForThisBaseStep(eventFlags);
  __enable_irq();
  ADRCPOLE_step0();

  /* Get model outputs here */
  __disable_irq();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    __enable_irq();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      ADRCPOLE_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

    __disable_irq();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(int argc, char **argv)
{
  float modelBaseRate = 0.0005;
  float systemClock = 192.0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#if !defined(MW_FREERTOS) && defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;

  // Start Peripheral initialization imported from STM32CubeMX project;
  HAL_Init();
  SystemClock_Config();
  PeriphCommonClock_Config();
  MX_DMA_Init();
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_DAC1_Init();

  // End Peripheral initialization imported from STM32CubeMX project;
  rtmSetErrorStatus(ADRCPOLE_M, 0);
  ADRCPOLE_initialize();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    rtmGetErrorStatus(ADRCPOLE_M) == (NULL);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(ADRCPOLE_M) == (NULL));
    if (stopRequested) {
      SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    ;
  }

  /* Terminate model */
  ADRCPOLE_terminate();

#if !defined(MW_FREERTOS) && !defined(USE_RTX)

  (void) systemClock;

#endif

  ;
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
