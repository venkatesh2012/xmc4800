/*
 * Copyright (C) 2015 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with
 * Infineon's microcontrollers.
 * This file can be freely distributed within development tools that are
 * supporting such microcontrollers.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

/**
 * @file
 * @date 12 Oct, 2015
 * @version 1.0.0
 *
 * @brief XMC4700/4800 Relax Kit Blinky GPIO demo example based on XMC Lib
 *
 * This blinky example flashes the led LED1 (P5.9) of the board with a initial periodic rate of 1.0s.
 * Using buttons flash rate can be adjusted in steps of 100ms. Use Button1 (P15.13) to increase flash rate.
 * Use Button2 (P15.12) to decrease flash rate.
 *
 * History <br>
 *
 * Version 1.0.0 Initial <br>
 *
 */
#include "xmc_ccu4.h"
#include "xmc_gpio.h"

#define CALCULATE_PERIOD(interval_in_ms) ((35155 * interval_in_ms) / 1000) /* fCPU=144MHz; Prescaler set to 4096 */

void CCU43_1_IRQHandler(void)
{
  XMC_GPIO_ToggleOutput(P5_9);
  return;
}

int main(void)
{
  uint32_t timer_interval = 1000;
  bool button_edge = true;

  /* INITIALIZE CCU43 FOR TOGGLING OF LED */
  /* Initialize CCU43 */
  XMC_CCU4_Init(CCU43, XMC_CCU4_SLICE_MCMS_ACTION_TRANSFER_PR_CR);
  /* Enable the clock for selected timer */
  XMC_CCU4_EnableClock(CCU43, 3);

  /* Prepare configuration */
  XMC_CCU4_SLICE_COMPARE_CONFIG_t slice_config =  {
                                                    .tc = 0,
                                                    .prescaler_initval = 12, /* set pre-scaler to 4096 */
                                                    .float_limit = 0,
                                                    .dither_limit = 0,
                                                    .passive_level = 0,
                                                    .timer_concatenation = 0
                                                  };
  /* Configure the timer */
  XMC_CCU4_SLICE_CompareInit(CCU43_CC43, &slice_config);
  /* programs the timer period register according to time interval value */
  XMC_CCU4_SLICE_SetTimerPeriodMatch(CCU43_CC43, 35155); /*initial period is 1s. fCPU / pre-scaler = 144E6 / 4096 = 35155*/
  /* Transfers value from shadow timer registers to actual timer registers */
  XMC_CCU4_EnableShadowTransfer(CCU43, XMC_CCU4_SHADOW_TRANSFER_SLICE_3 | XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_3);
  /* Bind period match event to an NVIC node CCU43_1_IRQn */
  XMC_CCU4_SLICE_SetInterruptNode(CCU43_CC43, XMC_CCU4_SLICE_IRQ_ID_PERIOD_MATCH, XMC_CCU4_SLICE_SR_ID_1);
  /* Enables timer(period match) event  */
  XMC_CCU4_SLICE_EnableEvent(CCU43_CC43, XMC_CCU4_SLICE_IRQ_ID_PERIOD_MATCH);

  XMC_CCU4_SLICE_ClearTimer(CCU43_CC43);
  XMC_CCU4_SLICE_StartTimer(CCU43_CC43);
  NVIC_SetPriority(CCU43_1_IRQn,NVIC_EncodePriority(NVIC_GetPriorityGrouping(),63,0));

  NVIC_EnableIRQ(CCU43_1_IRQn); //CCU43_3_IRQn

  /* INITIALIZE LED1 ON PORT 5.9 FOR OUTPUT (PUSH-PULL) */
  XMC_GPIO_SetMode(P5_9, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);

  /* INITIALIZE BUTTON1 ON PORT 5.13 FOR INPUT */
  /* Set mode to input tristate */
  XMC_GPIO_SetMode(P15_13, XMC_GPIO_MODE_INPUT_TRISTATE);
  /* Enable digital input. Only needed because P15.13 is an analog port */
  XMC_GPIO_EnableDigitalInput(P15_13);

  /* INITIALIZE BUTTON2 ON PORT 5.12 FOR INPUT */
  /* Set mode to input tristate */
  XMC_GPIO_SetMode(P15_12, XMC_GPIO_MODE_INPUT_TRISTATE);
  /* Enable digital input. Only needed because P15.12 is an analog port */
  XMC_GPIO_EnableDigitalInput(P15_12);

  while(1U)
    {
      /* any button pushed?*/
      if (!XMC_GPIO_GetInput(P15_13)||!XMC_GPIO_GetInput(P15_12))
        {
          /* new edge on any button? */
          if (button_edge == true)
            {
            /* which button ? */
              if (!XMC_GPIO_GetInput(P15_13))
                {
                  /* Button1 pushed. Decrease cycle time of flashing LED. */
                 timer_interval = (timer_interval > 100 ) ? (timer_interval - 100 ) : timer_interval;
                }
                else
                {
                  /* Button2 pushed. Increase cycle time of flashing LED. */
                  timer_interval = (timer_interval < 1500 ) ? (timer_interval + 100 ) : timer_interval;
                }
                XMC_CCU4_SLICE_StopTimer(CCU43_CC43);
                XMC_CCU4_SLICE_SetTimerPeriodMatch(CCU43_CC43, CALCULATE_PERIOD(timer_interval));
                XMC_CCU4_EnableShadowTransfer(CCU43, XMC_CCU4_SHADOW_TRANSFER_SLICE_3 | XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_3);
                XMC_CCU4_SLICE_StartTimer(CCU43_CC43);
            }
            button_edge = false;
        }
      else
        {
          /* currently no button pushed */
          /* next trigger on button is new edge */
          button_edge = true;
        }
    }
}

void UserIRQHandler(void)
{

  XMC_GPIO_ToggleOutput(P5_9);
}

