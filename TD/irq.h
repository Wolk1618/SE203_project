#ifndef IRQ_H
#define IRQ_H

#include "./CMSIS/stm32l475xx.h"

extern uint8_t _stack;
extern int main();
void irq_init();

#define MAKE_DEFAULT_HANDLER(x_IRQHandler) void __attribute__((weak)) x_IRQHandler(void) { \
	__disable_irq(); \
	while(1) { \
	} \
}

MAKE_DEFAULT_HANDLER(NMI_Handler)
MAKE_DEFAULT_HANDLER(HardFault_Handler)
MAKE_DEFAULT_HANDLER(MemManage_Handler)
MAKE_DEFAULT_HANDLER(BusFault_Handler)
MAKE_DEFAULT_HANDLER(UsageFault_Handler)
MAKE_DEFAULT_HANDLER(SVC_Handler)
MAKE_DEFAULT_HANDLER(PendSV_Handler)
MAKE_DEFAULT_HANDLER(SysTick_Handler)


MAKE_DEFAULT_HANDLER(WWDG_IRQHandler)
MAKE_DEFAULT_HANDLER(PVD_PVM_IRQHandler)
MAKE_DEFAULT_HANDLER(TAMP_STAMP_IRQHandler)
MAKE_DEFAULT_HANDLER(RTC_WKUP_IRQHandler)
MAKE_DEFAULT_HANDLER(FLASH_IRQHandler)
MAKE_DEFAULT_HANDLER(RCC_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI0_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI1_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI2_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI3_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI4_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH1_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH2_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH3_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH4_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH5_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH6_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH7_IRQHandler)
MAKE_DEFAULT_HANDLER(ADC1_2_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN1_TX_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN1_RX0_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN1_RX1_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN1_SCE_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI9_5_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM1_BRK_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM1_UP_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM1_TRG_COM_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM1_CC_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM2_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM3_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM4_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C1_EV_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C1_ER_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C2_EV_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C2_ER_IRQHandler)
MAKE_DEFAULT_HANDLER(SPI1_IRQHandler)
MAKE_DEFAULT_HANDLER(SPI2_IRQHandler)
MAKE_DEFAULT_HANDLER(USART1_IRQHandler)
MAKE_DEFAULT_HANDLER(USART2_IRQHandler)
MAKE_DEFAULT_HANDLER(USART3_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI15_10_IRQHandler)
MAKE_DEFAULT_HANDLER(RTC_ALARM_IRQHandler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT3_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM8_BRK_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM8_UP_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM8_TRG_COM_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM8_CC_IRQHandler)
MAKE_DEFAULT_HANDLER(ADC3_IRQHandler)
MAKE_DEFAULT_HANDLER(FMC_IRQHandler)
MAKE_DEFAULT_HANDLER(SDMMC1_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM5_IRQHandler)
MAKE_DEFAULT_HANDLER(SPI3_IRQHandler)
MAKE_DEFAULT_HANDLER(UART4_IRQHandler)
MAKE_DEFAULT_HANDLER(UART5_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM6_DACUNDER_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM7_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH1_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH2_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH3_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH4_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH5_IRQHandler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT0_IRQHandler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT1_IRQHandler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT2_IRQHandler)
MAKE_DEFAULT_HANDLER(COMP_IRQHandler)
MAKE_DEFAULT_HANDLER(LPTIM1_IRQHandler)
MAKE_DEFAULT_HANDLER(LPTIM2_IRQHandler)
MAKE_DEFAULT_HANDLER(OTG_FS_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH6_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH7_IRQHandler)
MAKE_DEFAULT_HANDLER(LPUART1_IRQHandler)
MAKE_DEFAULT_HANDLER(QUADSPI_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C3_EV_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C3_ER_IRQHandler)
MAKE_DEFAULT_HANDLER(SAI1_IRQHandler)
MAKE_DEFAULT_HANDLER(SAI2_IRQHandler)
MAKE_DEFAULT_HANDLER(SWPMI1_IRQHandler)
MAKE_DEFAULT_HANDLER(TSC_IRQHandler)
MAKE_DEFAULT_HANDLER(LCD_IRQHandler)
MAKE_DEFAULT_HANDLER(AES_IRQHandler)
MAKE_DEFAULT_HANDLER(RNG_IRQHandler)
MAKE_DEFAULT_HANDLER (FPU_IRQHandler)

MAKE_DEFAULT_HANDLER(HASH_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C4_EV_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C4_ER_IRQHandler)
MAKE_DEFAULT_HANDLER(DCMI_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN2_TX_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN2_RX0_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN2_RX1_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN2_SCE_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2D_IRQHandler)

#endif