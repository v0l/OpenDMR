/***************************************************************************
 *   Copyright (C) 2020 by Silvano Seva                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   As a special exception, if other files instantiate templates or use   *
 *   macros or inline functions from this file, or you compile this file   *
 *   and link it with other works to produce a work based on this file,    *
 *   this file does not by itself cause the resulting work to be covered   *
 *   by the GNU General Public License. However the source code for this   *
 *   file must still be made available in accordance with the GNU General  *
 *   Public License. This exception does not invalidate any other reasons  *
 *   why a work based on this file might be covered by the GNU General     *
 *   Public License.                                                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/
 

#include <string.h>
#include <stdio.h>
#include "stm32f4xx.h"

///< Entry point for application code
int main(int argc, char *argv[]);

void Reset_Handler() __attribute__((__interrupt__, noreturn));
void Reset_Handler()
{
    __disable_irq();

    //Call CMSIS init function, it's safe to do it here.
    SystemInit();

    //These are defined in the linker script
    extern unsigned char _etext asm("_etext");
    extern unsigned char _data asm("_data");
    extern unsigned char _edata asm("_edata");
    extern unsigned char _bss_start asm("_bss_start");
    extern unsigned char _bss_end asm("_bss_end");

    //Initialize .data section, clear .bss section
    unsigned char *etext=&_etext;
    unsigned char *data=&_data;
    unsigned char *edata=&_edata;
    unsigned char *bss_start=&_bss_start;
    unsigned char *bss_end=&_bss_end;

    memcpy(data, etext, edata-data);
    memset(bss_start, 0, bss_end-bss_start);

    __enable_irq();

    //Jump to application code 
    main(0, NULL);

    //If main returns loop indefinitely
    for(;;) ;
}

void Default_Handler()
{
    // default handler does nothing
}

// Used by FreeRTOS
void SVC_Handler();
void PendSV_Handler();
void SysTick_Handler();

void __attribute__((weak)) NMI_Handler();
void __attribute__((weak)) HardFault_Handler();
void __attribute__((weak)) MemManage_Handler();
void __attribute__((weak)) BusFault_Handler();
void __attribute__((weak)) UsageFault_Handler();
void __attribute__((weak)) DebugMon_Handler();

void __attribute__((weak)) WWDG_IRQHandler();
void __attribute__((weak)) PVD_IRQHandler();
void __attribute__((weak)) TAMP_STAMP_IRQHandler();
void __attribute__((weak)) RTC_WKUP_IRQHandler();
void __attribute__((weak)) FLASH_IRQHandler();
void __attribute__((weak)) RCC_IRQHandler();
void __attribute__((weak)) EXTI0_IRQHandler();
void __attribute__((weak)) EXTI1_IRQHandler();
void __attribute__((weak)) EXTI2_IRQHandler();
void __attribute__((weak)) EXTI3_IRQHandler();
void __attribute__((weak)) EXTI4_IRQHandler();
void __attribute__((weak)) DMA1_Stream0_IRQHandler();
void __attribute__((weak)) DMA1_Stream1_IRQHandler();
void __attribute__((weak)) DMA1_Stream2_IRQHandler();
void __attribute__((weak)) DMA1_Stream3_IRQHandler();
void __attribute__((weak)) DMA1_Stream4_IRQHandler();
void __attribute__((weak)) DMA1_Stream5_IRQHandler();
void __attribute__((weak)) DMA1_Stream6_IRQHandler();
void __attribute__((weak)) ADC_IRQHandler();
void __attribute__((weak)) CAN1_TX_IRQHandler();
void __attribute__((weak)) CAN1_RX0_IRQHandler();
void __attribute__((weak)) CAN1_RX1_IRQHandler();
void __attribute__((weak)) CAN1_SCE_IRQHandler();
void __attribute__((weak)) EXTI9_5_IRQHandler();
void __attribute__((weak)) TIM1_BRK_TIM9_IRQHandler();
void __attribute__((weak)) TIM1_UP_TIM10_IRQHandler();
void __attribute__((weak)) TIM1_TRG_COM_TIM11_IRQHandler();
void __attribute__((weak)) TIM1_CC_IRQHandler();
void __attribute__((weak)) TIM2_IRQHandler();
void __attribute__((weak)) TIM3_IRQHandler();
void __attribute__((weak)) TIM4_IRQHandler();
void __attribute__((weak)) I2C1_EV_IRQHandler();
void __attribute__((weak)) I2C1_ER_IRQHandler();
void __attribute__((weak)) I2C2_EV_IRQHandler();
void __attribute__((weak)) I2C2_ER_IRQHandler();
void __attribute__((weak)) SPI1_IRQHandler();
void __attribute__((weak)) SPI2_IRQHandler();
void __attribute__((weak)) USART1_IRQHandler();
void __attribute__((weak)) USART2_IRQHandler();
void __attribute__((weak)) USART3_IRQHandler();
void __attribute__((weak)) EXTI15_10_IRQHandler();
void __attribute__((weak)) RTC_Alarm_IRQHandler();
void __attribute__((weak)) OTG_FS_WKUP_IRQHandler();
void __attribute__((weak)) TIM8_BRK_TIM12_IRQHandler();
void __attribute__((weak)) TIM8_UP_TIM13_IRQHandler();
void __attribute__((weak)) TIM8_TRG_COM_TIM14_IRQHandler();
void __attribute__((weak)) TIM8_CC_IRQHandler();
void __attribute__((weak)) DMA1_Stream7_IRQHandler();
void __attribute__((weak)) FSMC_IRQHandler();
void __attribute__((weak)) SDIO_IRQHandler();
void __attribute__((weak)) TIM5_IRQHandler();
void __attribute__((weak)) SPI3_IRQHandler();
void __attribute__((weak)) UART4_IRQHandler();
void __attribute__((weak)) UART5_IRQHandler();
void __attribute__((weak)) TIM6_DAC_IRQHandler();
void __attribute__((weak)) TIM7_IRQHandler();
void __attribute__((weak)) DMA2_Stream0_IRQHandler();
void __attribute__((weak)) DMA2_Stream1_IRQHandler();
void __attribute__((weak)) DMA2_Stream2_IRQHandler();
void __attribute__((weak)) DMA2_Stream3_IRQHandler();
void __attribute__((weak)) DMA2_Stream4_IRQHandler();
void __attribute__((weak)) ETH_IRQHandler();
void __attribute__((weak)) ETH_WKUP_IRQHandler();
void __attribute__((weak)) CAN2_TX_IRQHandler();
void __attribute__((weak)) CAN2_RX0_IRQHandler();
void __attribute__((weak)) CAN2_RX1_IRQHandler();
void __attribute__((weak)) CAN2_SCE_IRQHandler();
void __attribute__((weak)) OTG_FS_IRQHandler();
void __attribute__((weak)) DMA2_Stream5_IRQHandler();
void __attribute__((weak)) DMA2_Stream6_IRQHandler();
void __attribute__((weak)) DMA2_Stream7_IRQHandler();
void __attribute__((weak)) USART6_IRQHandler();
void __attribute__((weak)) I2C3_EV_IRQHandler();
void __attribute__((weak)) I2C3_ER_IRQHandler();
void __attribute__((weak)) OTG_HS_EP1_OUT_IRQHandler();
void __attribute__((weak)) OTG_HS_EP1_IN_IRQHandler();
void __attribute__((weak)) OTG_HS_WKUP_IRQHandler();
void __attribute__((weak)) OTG_HS_IRQHandler();
void __attribute__((weak)) DCMI_IRQHandler();
void __attribute__((weak)) CRYP_IRQHandler();
void __attribute__((weak)) HASH_RNG_IRQHandler();
void __attribute__((weak)) FPU_IRQHandler();

//Stack top, defined in the linker script
extern char _stack_top asm("_stack_top");

//Interrupt vectors, must be placed @ address 0x00000000
//The extern declaration is required otherwise g++ optimizes it out
extern void (* const __Vectors[])();
void (* const __Vectors[])() __attribute__ ((section(".isr_vector"))) =
{
    (void (*)())(&_stack_top),
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    WWDG_IRQHandler,
    PVD_IRQHandler,
    TAMP_STAMP_IRQHandler,
    RTC_WKUP_IRQHandler,
    FLASH_IRQHandler,
    RCC_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA1_Stream0_IRQHandler,
    DMA1_Stream1_IRQHandler,
    DMA1_Stream2_IRQHandler,
    DMA1_Stream3_IRQHandler,
    DMA1_Stream4_IRQHandler,
    DMA1_Stream5_IRQHandler,
    DMA1_Stream6_IRQHandler,
    ADC_IRQHandler,
    CAN1_TX_IRQHandler,
    CAN1_RX0_IRQHandler,
    CAN1_RX1_IRQHandler,
    CAN1_SCE_IRQHandler,
    EXTI9_5_IRQHandler,
    TIM1_BRK_TIM9_IRQHandler,
    TIM1_UP_TIM10_IRQHandler,
    TIM1_TRG_COM_TIM11_IRQHandler,
    TIM1_CC_IRQHandler,
    TIM2_IRQHandler,
    TIM3_IRQHandler,
    TIM4_IRQHandler,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    I2C2_EV_IRQHandler,
    I2C2_ER_IRQHandler,
    SPI1_IRQHandler,
    SPI2_IRQHandler,
    USART1_IRQHandler,
    USART2_IRQHandler,
    USART3_IRQHandler,
    EXTI15_10_IRQHandler,
    RTC_Alarm_IRQHandler,
    OTG_FS_WKUP_IRQHandler,
    TIM8_BRK_TIM12_IRQHandler,
    TIM8_UP_TIM13_IRQHandler,
    TIM8_TRG_COM_TIM14_IRQHandler,
    TIM8_CC_IRQHandler,
    DMA1_Stream7_IRQHandler,
    FSMC_IRQHandler,
    SDIO_IRQHandler,
    TIM5_IRQHandler,
    SPI3_IRQHandler,
    UART4_IRQHandler,
    UART5_IRQHandler,
    TIM6_DAC_IRQHandler,
    TIM7_IRQHandler,
    DMA2_Stream0_IRQHandler,
    DMA2_Stream1_IRQHandler,
    DMA2_Stream2_IRQHandler,
    DMA2_Stream3_IRQHandler,
    DMA2_Stream4_IRQHandler,
    ETH_IRQHandler,
    ETH_WKUP_IRQHandler,
    CAN2_TX_IRQHandler,
    CAN2_RX0_IRQHandler,
    CAN2_RX1_IRQHandler,
    CAN2_SCE_IRQHandler,
    OTG_FS_IRQHandler,
    DMA2_Stream5_IRQHandler,
    DMA2_Stream6_IRQHandler,
    DMA2_Stream7_IRQHandler,
    USART6_IRQHandler,
    I2C3_EV_IRQHandler,
    I2C3_ER_IRQHandler,
    OTG_HS_EP1_OUT_IRQHandler,
    OTG_HS_EP1_IN_IRQHandler,
    OTG_HS_WKUP_IRQHandler,
    OTG_HS_IRQHandler,
    DCMI_IRQHandler,
    CRYP_IRQHandler,
    HASH_RNG_IRQHandler,
    FPU_IRQHandler
};

#pragma weak NMI_Handler= Default_Handler
#pragma weak HardFault_Handler= Default_Handler
#pragma weak MemManage_Handler= Default_Handler
#pragma weak BusFault_Handler= Default_Handler
#pragma weak UsageFault_Handler= Default_Handler
#pragma weak SVC_Handler= Default_Handler
#pragma weak DebugMon_Handler= Default_Handler
#pragma weak PendSV_Handler= Default_Handler
#pragma weak SysTick_Handler= Default_Handler
#pragma weak WWDG_IRQHandler= Default_Handler

#pragma weak PVD_IRQHandler= Default_Handler
#pragma weak TAMP_STAMP_IRQHandler= Default_Handler
#pragma weak RTC_WKUP_IRQHandler= Default_Handler
#pragma weak FLASH_IRQHandler= Default_Handler
#pragma weak RCC_IRQHandler= Default_Handler
#pragma weak EXTI0_IRQHandler= Default_Handler
#pragma weak EXTI1_IRQHandler= Default_Handler
#pragma weak EXTI2_IRQHandler= Default_Handler
#pragma weak EXTI3_IRQHandler= Default_Handler
#pragma weak EXTI4_IRQHandler= Default_Handler
#pragma weak DMA1_Stream0_IRQHandler= Default_Handler
#pragma weak DMA1_Stream1_IRQHandler= Default_Handler
#pragma weak DMA1_Stream2_IRQHandler= Default_Handler
#pragma weak DMA1_Stream3_IRQHandler= Default_Handler
#pragma weak DMA1_Stream4_IRQHandler= Default_Handler
#pragma weak DMA1_Stream5_IRQHandler= Default_Handler
#pragma weak DMA1_Stream6_IRQHandler= Default_Handler
#pragma weak ADC_IRQHandler= Default_Handler
#pragma weak CAN1_TX_IRQHandler= Default_Handler
#pragma weak CAN1_RX0_IRQHandler= Default_Handler
#pragma weak CAN1_RX1_IRQHandler= Default_Handler
#pragma weak CAN1_SCE_IRQHandler= Default_Handler
#pragma weak EXTI9_5_IRQHandler= Default_Handler
#pragma weak TIM1_BRK_TIM9_IRQHandler= Default_Handler
#pragma weak TIM1_UP_TIM10_IRQHandler= Default_Handler
#pragma weak TIM1_TRG_COM_TIM11_IRQHandler= Default_Handler
#pragma weak TIM1_CC_IRQHandler= Default_Handler
#pragma weak TIM2_IRQHandler= Default_Handler
#pragma weak TIM3_IRQHandler= Default_Handler
#pragma weak TIM4_IRQHandler= Default_Handler
#pragma weak I2C1_EV_IRQHandler= Default_Handler
#pragma weak I2C1_ER_IRQHandler= Default_Handler
#pragma weak I2C2_EV_IRQHandler= Default_Handler
#pragma weak I2C2_ER_IRQHandler= Default_Handler
#pragma weak SPI1_IRQHandler= Default_Handler
#pragma weak SPI2_IRQHandler= Default_Handler
#pragma weak USART1_IRQHandler= Default_Handler
#pragma weak USART2_IRQHandler= Default_Handler
#pragma weak USART3_IRQHandler= Default_Handler
#pragma weak EXTI15_10_IRQHandler= Default_Handler
#pragma weak RTC_Alarm_IRQHandler= Default_Handler
#pragma weak OTG_FS_WKUP_IRQHandler= Default_Handler
#pragma weak TIM8_BRK_TIM12_IRQHandler= Default_Handler
#pragma weak TIM8_UP_TIM13_IRQHandler= Default_Handler
#pragma weak TIM8_TRG_COM_TIM14_IRQHandler= Default_Handler
#pragma weak TIM8_CC_IRQHandler= Default_Handler
#pragma weak DMA1_Stream7_IRQHandler= Default_Handler
#pragma weak FSMC_IRQHandler= Default_Handler
#pragma weak SDIO_IRQHandler= Default_Handler
#pragma weak TIM5_IRQHandler= Default_Handler
#pragma weak SPI3_IRQHandler= Default_Handler
#pragma weak UART4_IRQHandler= Default_Handler
#pragma weak UART5_IRQHandler= Default_Handler
#pragma weak TIM6_DAC_IRQHandler= Default_Handler
#pragma weak TIM7_IRQHandler= Default_Handler
#pragma weak DMA2_Stream0_IRQHandler= Default_Handler
#pragma weak DMA2_Stream1_IRQHandler= Default_Handler
#pragma weak DMA2_Stream2_IRQHandler= Default_Handler
#pragma weak DMA2_Stream3_IRQHandler= Default_Handler
#pragma weak DMA2_Stream4_IRQHandler= Default_Handler
#pragma weak ETH_IRQHandler= Default_Handler
#pragma weak ETH_WKUP_IRQHandler= Default_Handler
#pragma weak CAN2_TX_IRQHandler= Default_Handler
#pragma weak CAN2_RX0_IRQHandler= Default_Handler
#pragma weak CAN2_RX1_IRQHandler= Default_Handler
#pragma weak CAN2_SCE_IRQHandler= Default_Handler
#pragma weak OTG_FS_IRQHandler= Default_Handler
#pragma weak DMA2_Stream5_IRQHandler= Default_Handler
#pragma weak DMA2_Stream6_IRQHandler= Default_Handler
#pragma weak DMA2_Stream7_IRQHandler= Default_Handler
#pragma weak USART6_IRQHandler= Default_Handler
#pragma weak I2C3_EV_IRQHandler= Default_Handler
#pragma weak I2C3_ER_IRQHandler= Default_Handler
#pragma weak OTG_HS_EP1_OUT_IRQHandler= Default_Handler
#pragma weak OTG_HS_EP1_IN_IRQHandler= Default_Handler
#pragma weak OTG_HS_WKUP_IRQHandler= Default_Handler
#pragma weak OTG_HS_IRQHandler= Default_Handler
#pragma weak DCMI_IRQHandler= Default_Handler
#pragma weak CRYP_IRQHandler= Default_Handler
#pragma weak HASH_RNG_IRQHandler= Default_Handler
#pragma weak FPU_IRQHandler= Default_Handler
