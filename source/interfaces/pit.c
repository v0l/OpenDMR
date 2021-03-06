/*
 * Copyright (C)2019 Kai Ludwig, DG4KLU
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <pit.h>

volatile uint32_t timer_maintask;
volatile uint32_t timer_beeptask;
volatile uint32_t timer_hrc6000task;
volatile uint32_t timer_watchdogtask;
volatile uint32_t timer_keypad;
volatile uint32_t timer_keypad_timeout;
volatile uint32_t PITCounter;

void init_pit(void)
{
#if defined(BSP_FSL)
	taskENTER_CRITICAL();
	timer_maintask=0;
	timer_beeptask=0;
	timer_hrc6000task=0;
	timer_watchdogtask=0;
	timer_keypad=0;
	timer_keypad_timeout=0;
	taskEXIT_CRITICAL();

	pit_config_t pitConfig;
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT, &pitConfig);

	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, CLOCK_GetFreq(kCLOCK_BusClk)));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);

	EnableIRQ(PIT0_IRQn);

    PIT_StartTimer(PIT, kPIT_Chnl_0);
#elif defined(BSP_STM32F4XX)
    // STM32F4XX has no PIT, we use a basic timer intead
    RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
    TIM7->ARR = 1;
    TIM7->PSC = 4200;
    TIM7->DIER |= TIM_DIER_UIE;
    TIM7->CR1 |= 1;
    NVIC_ClearPendingIRQ(TIM7_IRQn);
    NVIC_SetPriority(TIM7_IRQn, 14);
    NVIC_EnableIRQ(TIM7_IRQn);
#endif
}

#if defined(BSP_FSL)
void PIT0_IRQHandler(void)
#elif defined(BSP_STM32F4XX)
void TIM7_IRQHandler(void)
#endif
{
	PITCounter++;// is unsigned so will wrap around

	if (timer_maintask>0)
	{
		timer_maintask--;
	}
	if (timer_beeptask>0)
	{
		timer_beeptask--;
	}
	if (timer_hrc6000task>0)
	{
		timer_hrc6000task--;
	}
	if (timer_watchdogtask>0)
	{
		timer_watchdogtask--;
	}
	if (timer_keypad>0)
	{
		timer_keypad--;
	}
	if (timer_keypad_timeout>0)
	{
		timer_keypad_timeout--;
	}
#if defined(BSP_FSL)
    /* Clear interrupt flag.*/
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    __DSB();
#elif defined(BSP_STM32F4XX)
    TIM7->SR &= ~TIM_SR_UIF;
#endif
}
