/**
 * @file xmc4_scu.h
 * @date 2015-10-27
 *
 * @cond
  *********************************************************************************************************************
 * XMClib v2.1.2 - XMC Peripheral Driver Library 
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.                        
 *                                             
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the 
 * following conditions are met:   
 *                                                                              
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
 * disclaimer.                        
 * 
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
 * disclaimer in the documentation and/or other materials provided with the distribution.                       
 * 
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote 
 * products derived from this software without specific prior written permission.                                           
 *                                                                              
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                                  
 *                                                                              
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes with 
 * Infineon Technologies AG dave@infineon.com).                                                          
 *********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-06-20:
 *     - Initial version
 *     - Documentation improved
 *      
 * @endcond 
 *
 */

#ifndef XMC4_SCU_H
#define XMC4_SCU_H

/*********************************************************************************************************************
 * HEADER FILES
 ********************************************************************************************************************/

#include "xmc_common.h"

#if UC_FAMILY == XMC4

/**
 * @addtogroup XMClib XMC Peripheral Library
 * @{
 */
 
/**
 * @addtogroup SCU
 * @{
 */

/*********************************************************************************************************************
 * MACROS
 ********************************************************************************************************************/
#define PLL_PDIV_XTAL_8MHZ (1U)
#define PLL_NDIV_XTAL_8MHZ (89U)
#define PLL_K2DIV_XTAL_8MHZ (2U)

#define PLL_PDIV_XTAL_12MHZ (1U)
#define PLL_NDIV_XTAL_12MHZ (79U)
#define PLL_K2DIV_XTAL_12MHZ (3U)

#define PLL_PDIV_XTAL_16MHZ (1U)
#define PLL_NDIV_XTAL_16MHZ (59U)
#define PLL_K2DIV_XTAL_16MHZ (3U)

#define XMC_SCU_INTERRUPT_EVENT_WDT_WARN           SCU_INTERRUPT_SRSTAT_PRWARN_Msk /**< Watchdog prewarning event. */
#define XMC_SCU_INTERRUPT_EVENT_RTC_PERIODIC       SCU_INTERRUPT_SRSTAT_PI_Msk     /**< RTC periodic interrupt. */
#define XMC_SCU_INTERRUPT_EVENT_RTC_ALARM          SCU_INTERRUPT_SRSTAT_AI_Msk     /**< RTC alarm event. */
#define XMC_SCU_INTERRUPT_EVENT_DLR_OVERRUN        SCU_INTERRUPT_SRSTAT_DLROVR_Msk /**< DLR overrun event. */
#if defined(SCU_INTERRUPT_SRSTAT_LPACCR_Msk)
#define XMC_SCU_INTERRUPT_EVENT_LPACCR_UPDATED     SCU_INTERRUPT_SRSTAT_LPACCR_Msk /**< LPAC Control register update event. */
#endif
#if defined(SCU_INTERRUPT_SRSTAT_LPACTH0_Msk)
#define XMC_SCU_INTERRUPT_EVENT_LPACTH0_UPDATED    SCU_INTERRUPT_SRSTAT_LPACTH0_Msk /**< LPAC Threshold-0 register update event. */
#endif
#if defined(SCU_INTERRUPT_SRSTAT_LPACTH1_Msk)
#define XMC_SCU_INTERRUPT_EVENT_LPACTH1_UPDATED    SCU_INTERRUPT_SRSTAT_LPACTH1_Msk  /**< LPAC Threshold-1 register update event. */
#endif
#if defined(SCU_INTERRUPT_SRSTAT_LPACST_Msk)
#define XMC_SCU_INTERRUPT_EVENT_LPACST_UPDATED     SCU_INTERRUPT_SRSTAT_LPACST_Msk  /**< LPAC Status register update event. */
#endif
#if defined(SCU_INTERRUPT_SRSTAT_LPACCLR_Msk)
#define XMC_SCU_INTERRUPT_EVENT_LPACCLR_UPDATED    SCU_INTERRUPT_SRSTAT_LPACCLR_Msk /**< LPAC event clear register update event. */
#endif
#if defined(SCU_INTERRUPT_SRSTAT_LPACSET_Msk)
#define XMC_SCU_INTERRUPT_EVENT_LPACSET_UPDATED    SCU_INTERRUPT_SRSTAT_LPACSET_Msk /**< LPAC event set register update event. */
#endif
#if defined(SCU_INTERRUPT_SRSTAT_HINTST_Msk)
#define XMC_SCU_INTERRUPT_EVENT_HINTST_UPDATED     SCU_INTERRUPT_SRSTAT_HINTST_Msk /**< HIB HINTST register update event. */
#endif
#if defined(SCU_INTERRUPT_SRSTAT_HINTCLR_Msk)
#define XMC_SCU_INTERRUPT_EVENT_HINTCLR_UPDATED    SCU_INTERRUPT_SRSTAT_HINTCLR_Msk /**< HIB HINTCLR register update event. */
#endif
#if defined(SCU_INTERRUPT_SRSTAT_HINTSET_Msk)
#define XMC_SCU_INTERRUPT_EVENT_HINTSET_UPDATED    SCU_INTERRUPT_SRSTAT_HINTSET_Msk /**< HIB HINTSET register update event. */
#endif
#define XMC_SCU_INTERRUPT_EVENT_HDSTAT_UPDATED     SCU_INTERRUPT_SRSTAT_HDSTAT_Msk /**< HIB HDSTAT register update event. */
#define XMC_SCU_INTERRUPT_EVENT_HDCLR_UPDATED      SCU_INTERRUPT_SRSTAT_HDCLR_Msk /**< HIB HDCLR register update event. */
#define XMC_SCU_INTERRUPT_EVENT_HDSET_UPDATED      SCU_INTERRUPT_SRSTAT_HDSET_Msk /**< HIB HDSET register update event. */
#define XMC_SCU_INTERRUPT_EVENT_HDCR_UPDATED       SCU_INTERRUPT_SRSTAT_HDCR_Msk /**< HIB HDCR register update event. */
#define XMC_SCU_INTERRUPT_EVENT_OSCSICTRL_UPDATED  SCU_INTERRUPT_SRSTAT_OSCSICTRL_Msk /**< HIB OSCSICTRL register update event. */
#define XMC_SCU_INTERRUPT_EVENT_OSCULSTAT_UPDATED  SCU_INTERRUPT_SRSTAT_OSCULSTAT_Msk /**< HIB OSCULSTAT register update event. */
#define XMC_SCU_INTERRUPT_EVENT_OSCULCTRL_UPDATED  SCU_INTERRUPT_SRSTAT_OSCULCTRL_Msk /**< HIB OSCULCTRL register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCCTR_UPDATED     SCU_INTERRUPT_SRSTAT_RTC_CTR_Msk /**< HIB RTCCTR register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCATIM0_UPDATED   SCU_INTERRUPT_SRSTAT_RTC_ATIM0_Msk /**< HIB RTCATIM0 register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCATIM1_UPDATED   SCU_INTERRUPT_SRSTAT_RTC_ATIM1_Msk /**< HIB RTCATIM1 register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCTIM0_UPDATED    SCU_INTERRUPT_SRSTAT_RTC_TIM0_Msk /**< HIB TIM0 register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCTIM1_UPDATED    SCU_INTERRUPT_SRSTAT_RTC_TIM1_Msk /**< HIB TIM1 register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RMX_UPDATED        SCU_INTERRUPT_SRSTAT_RMX_Msk /**< HIB RMX register update event. */

/*********************************************************************************************************************
 * ENUMS
 ********************************************************************************************************************/
/**
 *  Defines Capture/Compare unit timer slice trigger, that enables synchronous start function available on the \a SCU,
 *  CCUCON register. Use type \a XMC_SCU_CCU_TRIGGER_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_CCU_TRIGGER
{
#if defined(CCU40)
  XMC_SCU_CCU_TRIGGER_CCU40 = SCU_GENERAL_CCUCON_GSC40_Msk, /**< Trigger mask used for Global Start Control of
                                                                 CCU40 peripheral. */
#endif
#if defined(CCU41)
  XMC_SCU_CCU_TRIGGER_CCU41 = SCU_GENERAL_CCUCON_GSC41_Msk, /**< Trigger mask used for Global Start Control of
                                                                 CCU41 peripheral. */
#endif
#if defined(CCU42)
  XMC_SCU_CCU_TRIGGER_CCU42 = SCU_GENERAL_CCUCON_GSC42_Msk, /**< Trigger mask used for Global Start Control of
                                                                 CCU42 peripheral. */
#endif
#if defined(CCU43)
  XMC_SCU_CCU_TRIGGER_CCU43 = SCU_GENERAL_CCUCON_GSC43_Msk, /**< Trigger mask used for Global Start Control of
                                                                 CCU43 peripheral. */
#endif
#if defined(CCU80)
  XMC_SCU_CCU_TRIGGER_CCU80 = SCU_GENERAL_CCUCON_GSC80_Msk, /**< Trigger mask used for Global Start Control of
                                                                 CCU80 peripheral. */
#endif
#if defined(CCU81)
  XMC_SCU_CCU_TRIGGER_CCU81 = SCU_GENERAL_CCUCON_GSC81_Msk /**< Trigger mask used for Global Start Control of
                                                                 CCU41 peripheral. */
#endif
} XMC_SCU_CCU_TRIGGER_t;

/**
 *  Defines enumerations representing the status of trap cause. The cause of the trap gets automatically stored in 
 *  the \a TRAPSTAT register and can be checked by user software to determine the state of the system and for debug
 *  purpose. 
 *  Use type \a XMC_SCU_TRAP_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_TRAP 
{
  XMC_SCU_TRAP_OSC_WDG      = SCU_TRAP_TRAPSTAT_SOSCWDGT_Msk, /**< OSC_HP Oscillator Watchdog trap. */
  XMC_SCU_TRAP_VCO_LOCK     = SCU_TRAP_TRAPSTAT_SVCOLCKT_Msk, /**< PLL loss of lock trap. */
  XMC_SCU_TRAP_USB_VCO_LOCK = SCU_TRAP_TRAPSTAT_UVCOLCKT_Msk, /**< USB PLL loss of lock trap. */ 
  XMC_SCU_TRAP_PARITY_ERROR = SCU_TRAP_TRAPSTAT_PET_Msk,      /**< Memory Parity error trap. */  
  XMC_SCU_TRAP_BROWNOUT     = SCU_TRAP_TRAPSTAT_BRWNT_Msk,    /**< Brownout trap. */ 
  XMC_SCU_TRAP_ULP_WDG      = SCU_TRAP_TRAPSTAT_ULPWDGT_Msk,  /**< Unstable 32KHz clock trap. */ 
  XMC_SCU_TRAP_PER_BRIDGE0  = SCU_TRAP_TRAPSTAT_BWERR0T_Msk,  /**< Bad memory access of peripherals on Bridge-0. */  
  XMC_SCU_TRAP_PER_BRIDGE1  = SCU_TRAP_TRAPSTAT_BWERR1T_Msk,  /**< Bad memory access of peripherals on Bridge-1. */  
#if defined(SCU_TRAP_TRAPSTAT_TEMPHIT_Msk)
  XMC_SCU_TRAP_DIETEMP_HIGH = SCU_TRAP_TRAPSTAT_TEMPHIT_Msk,  /**< Die temperature higher than expected. */ 
#endif
#if defined(SCU_TRAP_TRAPSTAT_TEMPLOT_Msk)
  XMC_SCU_TRAP_DIETEMP_LOW  = SCU_TRAP_TRAPSTAT_TEMPLOT_Msk,  /**< Die temperature lower than expected. */ 
#endif
#if defined(ECAT0)
  XMC_SCU_TRAP_ECAT_PARITY_ERROR = SCU_TRAP_TRAPSTAT_ECAT0RST_Msk, /**< EtherCat Reset */ 
#endif
} XMC_SCU_TRAP_t;

/**
 *  Defines enumerations for different parity event generating modules that in turn generate a trap.
 *  Parity can be enabled with \a PETE register in order to get the trap flag reflected in \a TRAPRAW register. These enums are used to
 *  configure parity error trap generation mechanism bits of \a PETE register.
 *  All the enum items are tabulated as per bits present in \a PETE register.
 *  Use type \a XMC_SCU_PARITY_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_PARITY
{
  XMC_SCU_PARITY_PSRAM_MEM  = SCU_PARITY_PEEN_PEENPS_Msk,   /**< Program SRAM parity error trap. */ 
  XMC_SCU_PARITY_DSRAM1_MEM = SCU_PARITY_PEEN_PEENDS1_Msk,  /**< Data SRAM-1 parity error trap. */ 
#if defined(XMC_SCU_PARITY_DSRAM2_MEM)
  XMC_SCU_PARITY_DSRAM2_MEM = SCU_PARITY_PEEN_PEENDS2_Msk,  /**< Data SRAM-2 parity error trap. */ 
#endif
  XMC_SCU_PARITY_USIC0_MEM  = SCU_PARITY_PEEN_PEENU0_Msk,   /**< USIC0 memory parity error trap. */ 
#if defined(XMC_SCU_PARITY_USIC1_MEM)
  XMC_SCU_PARITY_USIC1_MEM  = SCU_PARITY_PEEN_PEENU1_Msk,   /**< USIC1 memory parity error trap. */ 
#endif
#if defined(XMC_SCU_PARITY_USIC2_MEM)
  XMC_SCU_PARITY_USIC2_MEM  = SCU_PARITY_PEEN_PEENU2_Msk,   /**< USIC2 memory parity error trap. */ 
#endif
  XMC_SCU_PARITY_MCAN_MEM   = SCU_PARITY_PEEN_PEENMC_Msk,   /**< CAN memory parity error trap. */
  XMC_SCU_PARITY_PMU_MEM    = SCU_PARITY_PEEN_PEENPPRF_Msk, /**< PMU Prefetch memory parity error trap. */ 
  XMC_SCU_PARITY_USB_MEM    = SCU_PARITY_PEEN_PEENUSB_Msk,  /**< USB memory parity error trap. */ 
#if defined(SCU_PARITY_PEEN_PEENETH0TX_Msk)
  XMC_SCU_PARITY_ETH_TXMEM  = SCU_PARITY_PEEN_PEENETH0TX_Msk, /**< Ethernet transmit memory parity error trap. */ 
#endif
#if defined(SCU_PARITY_PEEN_PEENETH0RX_Msk)
  XMC_SCU_PARITY_ETH_RXMEM  = SCU_PARITY_PEEN_PEENETH0RX_Msk, /**< Ethernet receive memory parity error trap. */ 
#endif
#if defined(SCU_PARITY_PEEN_PEENSD0_Msk)
  XMC_SCU_PARITY_SDMMC_MEM0 = SCU_PARITY_PEEN_PEENSD0_Msk, /**< SDMMC Memory-0 parity error trap. */ 
#endif
#if defined(SCU_PARITY_PEEN_PEENSD1_Msk)
  XMC_SCU_PARITY_SDMMC_MEM1 = SCU_PARITY_PEEN_PEENSD1_Msk, /**< SDMMC Memory-1 parity error trap. */ 
#endif
} XMC_SCU_PARITY_t;

/**
 *  Defines the different causes for last reset. The cause of the last reset gets automatically stored in 
 *  the \a SCU_RSTSTAT register and can be checked by user software to determine the state of the system and for debuggging
 *  purpose. All the enum items are tabulated as per bits present in \a SCU_RSTSTAT register.
 *  Use type \a XMC_SCU_RESET_REASON_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_RESET_REASON
{
  XMC_SCU_RESET_REASON_PORST        = (1UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to Power on reset. */
  XMC_SCU_RESET_REASON_SWD          = (2UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to Serial wire debugger reset. */
  XMC_SCU_RESET_REASON_PV           = (4UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to Power Validation reset. */
  XMC_SCU_RESET_REASON_SW           = (8UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to Software reset. */
  XMC_SCU_RESET_REASON_LOCKUP       = (16UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to reset due to CPU lockup. */
  XMC_SCU_RESET_REASON_WATCHDOG     = (32UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to Watchdog timer initiated  reset. */
  XMC_SCU_RESET_REASON_PARITY_ERROR = (128UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to reset due to  memory parity  error. */
} XMC_SCU_RESET_REASON_t;

/**
 *  Defines enumerations for events which can lead to interrupt. These enumeration values represent the 
 * status of one of the bits in \a SRSTAT register. 
 *  Use type \a XMC_SCU_INTERRUPT_EVENT_t for accessing these enum parameters.
 */
typedef uint32_t XMC_SCU_INTERRUPT_EVENT_t;

 
/**
 *  Defines enumeration for the events that can generate non maskable interrupt(NMI).
 *  The NMI generation can be enabled with \a NMIREQEN register. The event will be reflected in \a SRSTAT or will be
 *  mirrored in the TRAPSTAT register. These enums can be used to configure NMI request generation bits of \a
 *  NMIREQEN register.  Once configured, these events can generate non maskable interrupt.
 *  All the enum items are tabulated as per bits present in \a NMIREQEN register.
 *  Use type \a XMC_SCU_NMIREQ_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_NMIREQ
{
  XMC_SCU_NMIREQ_WDT_WARN = SCU_INTERRUPT_NMIREQEN_PRWARN_Msk, /**< Watchdog timer Pre-Warning event */ 
  XMC_SCU_NMIREQ_RTC_PI   = SCU_INTERRUPT_NMIREQEN_PI_Msk,     /**< RTC Periodic event */ 
  XMC_SCU_NMIREQ_RTC_AI   = SCU_INTERRUPT_NMIREQEN_AI_Msk,     /**< RTC Alarm event */ 
  XMC_SCU_NMIREQ_ERU0_0   = SCU_INTERRUPT_NMIREQEN_ERU00_Msk,  /**< Channel 0 event of ERU0 */  
  XMC_SCU_NMIREQ_ERU0_1   = SCU_INTERRUPT_NMIREQEN_ERU01_Msk,  /**< Channel 1 event of ERU0 */ 
  XMC_SCU_NMIREQ_ERU0_2   = SCU_INTERRUPT_NMIREQEN_ERU02_Msk,  /**< Channel 2 event of ERU0 */ 
  XMC_SCU_NMIREQ_ERU0_3   = SCU_INTERRUPT_NMIREQEN_ERU03_Msk   /**< Channel 3 event of ERU0 */ 
} XMC_SCU_NMIREQ_t;
  

/**
 *  Defines enumeration representing different peripheral reset bits in the \a PRSTAT registers.
 *  All the enum items are tabulated as per bits present in \a PRSTAT0,  \a PRSTAT1,  \a PRSTAT2,
 *  \a PRSTAT3 registers. Use type \a XMC_SCU_PERIPHERAL_RESET_t for accessing these enum parameters.
 *  Note: Release of reset should be prevented when the peripheral clock is gated in cases where kernel
 *  clock and bus interface clocks are shared, in order to avoid system hang-up.
 */
typedef enum XMC_SCU_PERIPHERAL_RESET
{
  XMC_SCU_PERIPHERAL_RESET_VADC   = SCU_RESET_PRSTAT0_VADCRS_Msk,   /**< VADC reset. */ 
#if defined(DSD)
  XMC_SCU_PERIPHERAL_RESET_DSD    = SCU_RESET_PRSTAT0_DSDRS_Msk,    /**< DSD reset. */
#endif
  XMC_SCU_PERIPHERAL_RESET_CCU40  = SCU_RESET_PRSTAT0_CCU40RS_Msk,  /**< CCU40 reset. */
#if defined(CCU41)
  XMC_SCU_PERIPHERAL_RESET_CCU41  = SCU_RESET_PRSTAT0_CCU41RS_Msk,  /**< CCU41 reset. */
#endif  
#if defined(CCU42)
  XMC_SCU_PERIPHERAL_RESET_CCU42  = SCU_RESET_PRSTAT0_CCU42RS_Msk,  /**< CCU42 reset. */
#endif
#if defined(CCU80)
  XMC_SCU_PERIPHERAL_RESET_CCU80  = SCU_RESET_PRSTAT0_CCU80RS_Msk,  /**< CCU80 reset. */
#endif  
#if defined(CCU81)
  XMC_SCU_PERIPHERAL_RESET_CCU81  = SCU_RESET_PRSTAT0_CCU81RS_Msk,  /**< CCU81 reset. */
#endif
#if defined(POSIF0)
  XMC_SCU_PERIPHERAL_RESET_POSIF0 = SCU_RESET_PRSTAT0_POSIF0RS_Msk, /**< POSIF0 reset. */
#endif  
#if defined(POSIF1)
  XMC_SCU_PERIPHERAL_RESET_POSIF1 = SCU_RESET_PRSTAT0_POSIF1RS_Msk, /**< POSIF1 reset.*/
#endif
  XMC_SCU_PERIPHERAL_RESET_USIC0  = SCU_RESET_PRSTAT0_USIC0RS_Msk,  /**< USIC0 reset. */
  XMC_SCU_PERIPHERAL_RESET_ERU1   = SCU_RESET_PRSTAT0_ERU1RS_Msk,   /**< ERU1 reset. */
#if defined(HRPWM0)
  XMC_SCU_PERIPHERAL_RESET_HRPWM0 = SCU_RESET_PRSTAT0_HRPWM0RS_Msk,  /**< HRPWM0 reset. */
#endif
#if defined(CCU43)
  XMC_SCU_PERIPHERAL_RESET_CCU43  = (SCU_RESET_PRSTAT1_CCU43RS_Msk | 0x10000000UL),   /**< CCU43 reset. */
#endif
#if defined(LEDTS0)
  XMC_SCU_PERIPHERAL_RESET_LEDTS0 = (SCU_RESET_PRSTAT1_LEDTSCU0RS_Msk | 0x10000000UL), /**< LEDTS0 reset. */
#endif  
#if defined(CAN)
  XMC_SCU_PERIPHERAL_RESET_MCAN   = (SCU_RESET_PRSTAT1_MCAN0RS_Msk | 0x10000000UL), /**< MCAN reset. */
#endif  
#if defined(DAC)  
  XMC_SCU_PERIPHERAL_RESET_DAC    = (SCU_RESET_PRSTAT1_DACRS_Msk | 0x10000000UL),    /**< DAC reset. */
#endif  
#if defined(SDMMC)
  XMC_SCU_PERIPHERAL_RESET_SDMMC  = (SCU_RESET_PRSTAT1_MMCIRS_Msk | 0x10000000UL),     /**< SDMMC reset. */
#endif
#if defined(USIC1)
  XMC_SCU_PERIPHERAL_RESET_USIC1  = (SCU_RESET_PRSTAT1_USIC1RS_Msk | 0x10000000UL),    /**< USIC1 reset. */
#endif  
#if defined(USIC2)
  XMC_SCU_PERIPHERAL_RESET_USIC2  = (SCU_RESET_PRSTAT1_USIC2RS_Msk | 0x10000000UL),    /**< USIC2 reset. */
#endif
  XMC_SCU_PERIPHERAL_RESET_PORTS  = (SCU_RESET_PRSTAT1_PPORTSRS_Msk | 0x10000000UL),   /**< PORTS reset. */
  XMC_SCU_PERIPHERAL_RESET_WDT    = (SCU_RESET_PRSTAT2_WDTRS_Msk | 0x20000000UL),      /**< WDT reset. */
#if defined(ETH0)
  XMC_SCU_PERIPHERAL_RESET_ETH0   = (SCU_RESET_PRSTAT2_ETH0RS_Msk | 0x20000000UL),     /**< ETH0 reset. */
#endif
  XMC_SCU_PERIPHERAL_RESET_GPDMA0 = (SCU_RESET_PRSTAT2_DMA0RS_Msk | 0x20000000UL),     /**< DMA0 reset. */
#if defined(GPDMA1)
  XMC_SCU_PERIPHERAL_RESET_GPDMA1 = (SCU_RESET_PRSTAT2_DMA1RS_Msk | 0x20000000UL),     /**< DMA1 reset. */
#endif
#if defined(FCE)
  XMC_SCU_PERIPHERAL_RESET_FCE    = (SCU_RESET_PRSTAT2_FCERS_Msk | 0x20000000UL),      /**< FCE reset. */
#endif
#if defined(USB0)  
  XMC_SCU_PERIPHERAL_RESET_USB0   = (SCU_RESET_PRSTAT2_USBRS_Msk | 0x20000000UL),      /**< USB0 reset. */
#endif  
#if defined(ECAT0)  
  XMC_SCU_PERIPHERAL_RESET_ECAT0  = (SCU_RESET_PRSTAT2_ECAT0RS_Msk | 0x20000000UL),      /**< ECAT0 reset. */
#endif  
#if defined(EBU)
  XMC_SCU_PERIPHERAL_RESET_EBU    = (SCU_RESET_PRSTAT3_EBURS_Msk | 0x30000000UL)       /**< EBU reset. */
#endif
} XMC_SCU_PERIPHERAL_RESET_t;

/**
 *  Defines enumerations for disabling the clocks sources of peripherals. Disabling of the peripheral
 *  clock is configured via the \a CLKCLR registers.
 *  Use type \a XMC_SCU_PERIPHERAL_CLOCK_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_CLOCK
{
  XMC_SCU_CLOCK_USB = SCU_CLK_CLKCLR_USBCDI_Msk, /**< USB module clock. */
#if defined(SDMMC)
  XMC_SCU_CLOCK_MMC = SCU_CLK_CLKCLR_MMCCDI_Msk, /**< MMC module clock. */
#endif
#if defined(ETH0)
  XMC_SCU_CLOCK_ETH = SCU_CLK_CLKCLR_ETH0CDI_Msk, /**< Ethernet module clock. */
#endif
#if defined(EBU)
  XMC_SCU_CLOCK_EBU = SCU_CLK_CLKCLR_EBUCDI_Msk, /**< EBU module clock. */
#endif
  XMC_SCU_CLOCK_CCU = SCU_CLK_CLKCLR_CCUCDI_Msk, /**< CCU module clock. */
  XMC_SCU_CLOCK_WDT = SCU_CLK_CLKCLR_WDTCDI_Msk  /**< WDT module clock. */
} XMC_SCU_CLOCK_t;

#if(UC_SERIES != XMC45)
/**
 * Defines enumeration for peripherals that support clock gating. 
 * The enumerations can be used for gating or ungating the peripheral clocks.
 * All the enum items are tabulated as per bits present in \a CGATSTAT0 register.
 * Use type \a XMC_SCU_PERIPHERAL_CLOCK_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_PERIPHERAL_CLOCK
{
  XMC_SCU_PERIPHERAL_CLOCK_VADC   = SCU_CLK_CGATSTAT0_VADC_Msk,  /**< VADC peripheral gating. */
#if defined(DSD)
  XMC_SCU_PERIPHERAL_CLOCK_DSD    = SCU_CLK_CGATSTAT0_DSD_Msk,   /**< DSD peripheral gating. */
#endif
  XMC_SCU_PERIPHERAL_CLOCK_CCU40  = SCU_CLK_CGATSTAT0_CCU40_Msk,  /**< CCU40 peripheral gating. */
#if defined(CCU41)
  XMC_SCU_PERIPHERAL_CLOCK_CCU41  = SCU_CLK_CGATSTAT0_CCU41_Msk,  /**< CCU41 peripheral gating. */
#endif  
#if defined(CCU42)
  XMC_SCU_PERIPHERAL_CLOCK_CCU42  = SCU_CLK_CGATSTAT0_CCU42_Msk,  /**< CCU42 peripheral gating. */
#endif
#if defined(CCU80)
  XMC_SCU_PERIPHERAL_CLOCK_CCU80  = SCU_CLK_CGATSTAT0_CCU80_Msk,  /**< CCU80 peripheral gating. */
#endif  
#if defined(CCU81)
  XMC_SCU_PERIPHERAL_CLOCK_CCU81  = SCU_CLK_CGATSTAT0_CCU81_Msk,  /**< CCU81 peripheral gating. */
#endif
#if defined(POSIF0)
  XMC_SCU_PERIPHERAL_CLOCK_POSIF0 = SCU_CLK_CGATSTAT0_POSIF0_Msk,  /**< POSIF0 peripheral gating. */
#endif  
#if defined(POSIF1)
  XMC_SCU_PERIPHERAL_CLOCK_POSIF1 = SCU_CLK_CGATSTAT0_POSIF1_Msk,   /**< POSIF1 peripheral gating. */
#endif
  XMC_SCU_PERIPHERAL_CLOCK_USIC0  = SCU_CLK_CGATSTAT0_USIC0_Msk,   /**< USIC0 peripheral gating. */
  XMC_SCU_PERIPHERAL_CLOCK_ERU1   = SCU_CLK_CGATSTAT0_ERU1_Msk,    /**< ERU1 peripheral gating. */
#if defined(HRPWM0)
  XMC_SCU_PERIPHERAL_CLOCK_HRPWM0 = SCU_CLK_CGATSTAT0_HRPWM0_Msk,  /**< HRPWM0 peripheral gating. */
#endif
#if defined(CCU43)
  XMC_SCU_PERIPHERAL_CLOCK_CCU43  = (SCU_CLK_CGATSTAT1_CCU43_Msk | 0x10000000UL),   /**< CCU43 peripheral gating. */
#endif
#if defined(LEDTS0)
  XMC_SCU_PERIPHERAL_CLOCK_LEDTS0 = (SCU_CLK_CGATSTAT1_LEDTSCU0_Msk | 0x10000000UL), /**< LEDTS0 peripheral gating. */
#endif  
#if defined(CAN)
  XMC_SCU_PERIPHERAL_CLOCK_MCAN   = (SCU_CLK_CGATSTAT1_MCAN0_Msk | 0x10000000UL),   /**< MCAN peripheral gating. */
#endif
#if defined(DAC)  
  XMC_SCU_PERIPHERAL_CLOCK_DAC    = (SCU_CLK_CGATSTAT1_DAC_Msk | 0x10000000UL),     /**< DAC peripheral gating. */
#endif  
#if defined(SDMMC)
  XMC_SCU_PERIPHERAL_CLOCK_SDMMC  = (SCU_CLK_CGATSTAT1_MMCI_Msk | 0x10000000UL),    /**< SDMMC peripheral gating. */
#endif
#if defined(USIC1)
  XMC_SCU_PERIPHERAL_CLOCK_USIC1  = (SCU_CLK_CGATSTAT1_USIC1_Msk | 0x10000000UL),   /**< USIC1 peripheral gating. */
#endif  
#if defined(USIC2)
  XMC_SCU_PERIPHERAL_CLOCK_USIC2  = (SCU_CLK_CGATSTAT1_USIC2_Msk | 0x10000000UL),    /**< USIC2 peripheral gating. */
#endif
  XMC_SCU_PERIPHERAL_CLOCK_PORTS  = (SCU_CLK_CGATSTAT1_PPORTS_Msk | 0x10000000UL),   /**< PORTS peripheral gating. */
  XMC_SCU_PERIPHERAL_CLOCK_WDT    = (SCU_CLK_CGATSTAT2_WDT_Msk | 0x20000000UL),      /**< WDT peripheral gating. */
#if defined(ETH0)
  XMC_SCU_PERIPHERAL_CLOCK_ETH0   = (SCU_CLK_CGATSTAT2_ETH0_Msk | 0x20000000UL),     /**< ETH0 peripheral gating. */
#endif
  XMC_SCU_PERIPHERAL_CLOCK_GPDMA0 = (SCU_CLK_CGATSTAT2_DMA0_Msk | 0x20000000UL),     /**< DMA0 peripheral gating. */
#if defined(GPDMA1)
  XMC_SCU_PERIPHERAL_CLOCK_GPDMA1 = (SCU_CLK_CGATSTAT2_DMA1_Msk | 0x20000000UL),     /**< DMA1 peripheral gating. */
#endif
#if defined(FCE)
  XMC_SCU_PERIPHERAL_CLOCK_FCE    = (SCU_CLK_CGATSTAT2_FCE_Msk | 0x20000000UL),      /**< FCE peripheral gating. */
#endif  
#if defined(USB0)
  XMC_SCU_PERIPHERAL_CLOCK_USB0   = (SCU_CLK_CGATSTAT2_USB_Msk | 0x20000000UL),      /**< USB0 peripheral gating. */
#endif  
#if defined(ECAT0)
  XMC_SCU_PERIPHERAL_CLOCK_ECAT0   = (SCU_CLK_CGATSTAT2_ECAT0_Msk | 0x20000000UL),      /**< ECAT0 peripheral gating. */
#endif  
#if defined(EBU)
  XMC_SCU_PERIPHERAL_CLOCK_EBU    = (SCU_CLK_CGATSTAT3_EBU_Msk | 0x30000000UL)       /**< EBU peripheral gating. */
#endif
} XMC_SCU_PERIPHERAL_CLOCK_t;
#endif

/**
 *  Defines options for system clock (fSYS) source. These enums are used to configure \a SYSSEL bits of \a SYSCLKCR
 *  Clock Control Register. 
 *  Use type \a XMC_SCU_CLOCK_SYSCLKSRC_t for accessing these enum parameters.
 */ 
typedef enum XMC_SCU_CLOCK_SYSCLKSRC
{
  XMC_SCU_CLOCK_SYSCLKSRC_OFI = (0UL << SCU_CLK_SYSCLKCR_SYSSEL_Pos), /**< Internal Fast Clock (fOFI) as a 
                                                                           source for system clock (fSYS). */
  XMC_SCU_CLOCK_SYSCLKSRC_PLL = (1UL << SCU_CLK_SYSCLKCR_SYSSEL_Pos)  /**< PLL output (fPLL) as a
                                                                           source for system clock (fSYS). */
} XMC_SCU_CLOCK_SYSCLKSRC_t;

/**
 *  Defines options for selecting the P-Divider input frequency. These enums are used to configure \a PINSEL bits of \a PLLCON2
 *  register. 
 *  Use type \a XMC_SCU_CLOCK_OSCCLKSRC_t for accessing these enum parameters.
 */ 
typedef enum XMC_SCU_CLOCK_SYSPLLCLKSRC
{
  XMC_SCU_CLOCK_SYSPLLCLKSRC_OSCHP = 0UL,  /**< External crystal oscillator
                                                (fOHP) as the source for P-Divider. */
  XMC_SCU_CLOCK_SYSPLLCLKSRC_OFI = SCU_PLL_PLLCON2_PINSEL_Msk | SCU_PLL_PLLCON2_K1INSEL_Msk /**< Backup clock(fOFI)
                                                                             as the source for P-Divider. */
} XMC_SCU_CLOCK_SYSPLLCLKSRC_t;

/**
 * Defines options for selecting the USB clock source(fUSB/fSDMMC).
 * These enums are used to configure \a USBSEL bits of \a USBCLKCR
 * register. User can choose either fPLL or fUSBPLL clock as a source for USB clock. 
 * Use type \a XMC_SCU_CLOCK_USBCLKSRC_t for accessing these enum parameters.
 */ 
typedef enum XMC_SCU_CLOCK_USBCLKSRC
{
  XMC_SCU_CLOCK_USBCLKSRC_USBPLL = (0UL << SCU_CLK_USBCLKCR_USBSEL_Pos), /**< USB PLL(fUSB PLL) as a 
                                                                           source for USB clock (fUSB/fSDMMC). */
  XMC_SCU_CLOCK_USBCLKSRC_SYSPLL = (1UL << SCU_CLK_USBCLKCR_USBSEL_Pos)  /**< Main PLL output (fPLL) as a
                                                                           source for USB clock (fUSB/fSDMMC). */
} XMC_SCU_CLOCK_USBCLKSRC_t;

#if defined(ECAT0) 
/**
 * Defines options for selecting the PERIPH2 clock source.
 */ 
typedef enum XMC_SCU_CLOCK_ECATCLKSRC
{
  XMC_SCU_CLOCK_ECATCLKSRC_USBPLL = (0UL << SCU_CLK_ECATCLKCR_ECATSEL_Pos), /**< USB PLL (fUSBPLL) as a source for PERIPH2 clock. */
  XMC_SCU_CLOCK_ECATCLKSRC_SYSPLL = (1UL << SCU_CLK_ECATCLKCR_ECATSEL_Pos)  /**< Main PLL output (fPLL) as a source for PERIPH2 clock. */
} XMC_SCU_CLOCK_ECATCLKSRC_t;
#endif

/**
 *  Defines options for selecting the source of WDT clock(fWDT). These enums are used to configure \a WDTSEL bits of \a WDTCLKCR
 *  register. User can choose either fOFI or fPLL or fSTDBY clock as a source for WDT clock. 
 *  Use type \a XMC_SCU_CLOCK_USBCLKSRC_t for accessing these enum parameters.
 */ 
typedef enum XMC_SCU_CLOCK_WDTCLKSRC
{
  XMC_SCU_CLOCK_WDTCLKSRC_OFI = (0UL << SCU_CLK_WDTCLKCR_WDTSEL_Pos),  /**< Internal Fast Clock 
                                                                           (fOFI) as the source for WDT clock (fWDT). */
  XMC_SCU_CLOCK_WDTCLKSRC_STDBY = (1UL << SCU_CLK_WDTCLKCR_WDTSEL_Pos), /**< Standby clock 
                                                                           (fSTDBY) as the source for WDT clock (fWDT). */
  XMC_SCU_CLOCK_WDTCLKSRC_PLL = (2UL << SCU_CLK_WDTCLKCR_WDTSEL_Pos)   /**< PLL output (fPLL) as the
                                                                           source for WDT clock (fWDT). */
} XMC_SCU_CLOCK_WDTCLKSRC_t;

/**
 *  Defines options for selecting the source of external clock out (fEXT). These enums are used to configure \a ECKSEL bits of \a EXTCLKCR
 *  register. User can choose either fSYS or fPLL or fUSBPLL clock as a source for external clock out (fEXT).
 *  Use type \a XMC_SCU_CLOCK_EXTOUTCLKSRC_t for accessing these enum parameters.
 */ 
typedef enum XMC_SCU_CLOCK_EXTOUTCLKSRC
{
  XMC_SCU_CLOCK_EXTOUTCLKSRC_SYS = (0UL << SCU_CLK_EXTCLKCR_ECKSEL_Pos),  /**< System clock (fSYS) as
                                                                            the source for external clock out (fEXT). */
  XMC_SCU_CLOCK_EXTOUTCLKSRC_USB = (2UL << SCU_CLK_EXTCLKCR_ECKSEL_Pos), /**< USB PLL output(fUSB PLL) as the
                                                                           source for external clock out (fEXT). */
  XMC_SCU_CLOCK_EXTOUTCLKSRC_PLL = (3UL << SCU_CLK_EXTCLKCR_ECKSEL_Pos), /**< Main PLL output(fPLL) as the
                                                                           source for external clock out (fEXT). */
#if ((UC_SERIES == XMC42) || (UC_SERIES == XMC41))
  XMC_SCU_CLOCK_EXTOUTCLKSRC_STDBY = (4UL << SCU_CLK_EXTCLKCR_ECKSEL_Pos), /**< Standby clock(fSTDBY) as the
                                                                           source for external clock out (fEXT). */
#endif
} XMC_SCU_CLOCK_EXTOUTCLKSRC_t;

/**
 *  Defines options for selecting the source of RTC Clock (fRTC). These enums are used to configure \a RCS bit of \a HDCR register.
 *  User can choose either fOSI or fULP clock as a source for RTC Clock (fRTC).
 *  Use type \a XMC_SCU_HIB_RTCCLKSRC_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_HIB_RTCCLKSRC
{
  XMC_SCU_HIB_RTCCLKSRC_OSI = (0UL << SCU_HIBERNATE_HDCR_RCS_Pos), /**< Internal Slow Clock
                                                                         (fOSI) as the source for RTC Clock (fRTC). */
  XMC_SCU_HIB_RTCCLKSRC_ULP = (1UL << SCU_HIBERNATE_HDCR_RCS_Pos) /**< Ultra Low Power Clock (fULP)
                                                                        as the source for RTC Clock (fRTC). */
} XMC_SCU_HIB_RTCCLKSRC_t;

/**
 *  Defines options for selecting the source of Standby Clock (fSTDBY). These enums are used to configure \a STDBYSEL bit of \a HDCR
 *  register. User can choose either fOSI or fULP clock as a source for Standby Clock (fSTDBY).
 *  Use type \a XMC_SCU_HIB_STDBYCLKSRC_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_HIB_STDBYCLKSRC
{
  XMC_SCU_HIB_STDBYCLKSRC_OSI = (0UL << SCU_HIBERNATE_HDCR_STDBYSEL_Pos), /**< Internal Slow Clock 
                                                                          (fOSI) as the source for Standby Clock
                                                                          (fSTDBY). */
  XMC_SCU_HIB_STDBYCLKSRC_OSCULP = (1UL << SCU_HIBERNATE_HDCR_STDBYSEL_Pos) /**< Ultra Low Power Clock
                                                                          (fULP) as the source for Standby Clock
                                                                          (fSTDBY). */
} XMC_SCU_HIB_STDBYCLKSRC_t;

/**
 *  Defines options for backup clock trimming. These enums are used to configure \a AOTREN  \a FOTR bits of \a
 *  PLLCON0 register. Use type \a XMC_SCU_CLOCK_BACKUP_TRIM_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE
{
  XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_FACTORY   = 0UL,  /**< Factory Oscillator Calibration: 
                                                        Force adjustment of the internal oscillator with the firmware defined values.*/
  XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_AUTOMATIC = 1UL   /**<  Automatic Oscillator Calibration adjustment of the fOFI clock with fSTDBY clock.  */
} XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_t;


/**
 *  Defines options for selecting device boot mode. These enums are used to configure \a SWCON bits of \a STCON register.
 *  User can choose among various boot modes by configuring SWCON bits.
 *  Use type \a XMC_SCU_BOOTMODE_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_BOOTMODE 
{
  XMC_SCU_BOOTMODE_NORMAL     = (0UL << SCU_GENERAL_STCON_SWCON_Pos), /**< Boot from start of flash. */
  XMC_SCU_BOOTMODE_ASC_BSL    = (1UL << SCU_GENERAL_STCON_SWCON_Pos), /**< UART bootstrap. */
  XMC_SCU_BOOTMODE_BMI        = (2UL << SCU_GENERAL_STCON_SWCON_Pos), /**< Boot Mode Index - Customized boot 
                                                                           sequence. */
  XMC_SCU_BOOTMODE_CAN_BSL    = (3UL << SCU_GENERAL_STCON_SWCON_Pos), /**< CAN bootstrap. */
  XMC_SCU_BOOTMODE_PSRAM_BOOT = (4UL << SCU_GENERAL_STCON_SWCON_Pos), /**< Boot from PSRAM. */
  XMC_SCU_BOOTMODE_ABM0       = (8UL << SCU_GENERAL_STCON_SWCON_Pos), /**< Boot from flash - fixed alternative
                                                                           address 0. */
  XMC_SCU_BOOTMODE_ABM1       = (12UL << SCU_GENERAL_STCON_SWCON_Pos), /**< Boot from flash - fixed alternative 
                                                                            address 1. */
  XMC_SCU_BOOTMODE_FABM       = (14UL << SCU_GENERAL_STCON_SWCON_Pos), /**< fallback Alternate Boot Mode (ABM) - 
                                                                            Try ABM-0 then try ABM-1. */
} XMC_SCU_BOOTMODE_t;


/**
 *  Defines various PLL modes of operation. These enums are used to configure \a VCOBYP bit of \a PLLCON0 register.
 *  User can choose either normal or prescalar mode by configuring VCOBYP bit.
 *  Use type \a XMC_SCU_PLL_MODE_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_CLOCK_SYSPLL_MODE
{
  XMC_SCU_CLOCK_SYSPLL_MODE_DISABLED, /**< fPLL derived from fOSC and PLL operating in prescalar mode(i.e.VCO bypassed). */
  XMC_SCU_CLOCK_SYSPLL_MODE_NORMAL,  /**< fPLL derived from fVCO and PLL operating in normal mode. */
  XMC_SCU_CLOCK_SYSPLL_MODE_PRESCALAR /**< fPLL derived from fOSC and PLL operating in prescalar mode(i.e.VCO bypassed). */
} XMC_SCU_CLOCK_SYSPLL_MODE_t;

/**
 *
 */
typedef enum XMC_SCU_CLOCK_SLEEP_MODE_CONFIG
{
  XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_SYSCLK_FOFI = 0,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_SYSCLK_FOFI
  XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_SYSCLK_FPLL = SCU_CLK_SLEEPCR_SYSSEL_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_SYSCLK_FPLL
#if defined(USB0)
  XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_USB = SCU_CLK_SLEEPCR_USBCR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_USB
#endif  
#if defined(SDMMC)
  XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_SDMMC = SCU_CLK_SLEEPCR_MMCCR_Msk,//!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_SDMMC
#endif  
#if defined(ETH0)
  XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_ETH = SCU_CLK_SLEEPCR_ETH0CR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_ETH
#endif  
#if defined(EBU)
  XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_EBU = SCU_CLK_SLEEPCR_EBUCR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_EBU
#endif  
  XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_CCU = SCU_CLK_SLEEPCR_CCUCR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_CCU
  XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_WDT = SCU_CLK_SLEEPCR_WDTCR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_WDT
} XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_t;

/**
 *
 */
typedef enum XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG
{
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_SYSCLK_FOFI = 0,  //!< XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_SYSCLK_FOFI
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_SYSCLK_FPLL = SCU_CLK_SLEEPCR_SYSSEL_Msk,  //!< XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_SYSCLK_FPLL
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_FLASH_POWERDOWN = SCU_CLK_DSLEEPCR_FPDN_Msk,//!< XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_FLASH_POWERDOWN
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_PLL_POWERDOWN = SCU_CLK_DSLEEPCR_PLLPDN_Msk,  //!< XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_PLL_POWERDOWN
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_VCO_POWERDOWN = SCU_CLK_DSLEEPCR_VCOPDN_Msk,  //!< XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_VCO_POWERDOWN
#if defined(USB0)
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_DISABLE_USB = SCU_CLK_SLEEPCR_USBCR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_USB
#endif  
#if defined(SDMMC)
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_DISABLE_SDMMC = SCU_CLK_SLEEPCR_MMCCR_Msk,//!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_SDMMC
#endif  
#if defined(ETH0)
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_DISABLE_ETH = SCU_CLK_SLEEPCR_ETH0CR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_ETH
#endif  
#if defined(EBU)
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_DISABLE_EBU = SCU_CLK_SLEEPCR_EBUCR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_EBU
#endif  
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_DISABLE_CCU = SCU_CLK_SLEEPCR_CCUCR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_CCU
  XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_DISABLE_WDT = SCU_CLK_SLEEPCR_WDTCR_Msk,  //!< XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_DISABLE_WDT
} XMC_SCU_CLOCK_DEEPSLEEP_MODE_CONFIG_t;


/*********************************************************************************************************************
 * DATA STRUCTURES
 ********************************************************************************************************************/

/**
 *  Defines a data structure for initializing the PLL functional block.
 *  Structure holds divider values for N-DIV, P-DIV, K1-DIV, K2-DIV in order to generate desired 
 *  frequency using VCO. It holds the PLL mode of operation either normal or prescaler (VCO bypassed).
 *  Use type \a XMC_SCU_CLOCK_PLL_CONFIG_t for accessing these structure parameters.
 */
typedef struct XMC_SCU_CLOCK_SYSPLL_CONFIG
{
  uint8_t n_div;                       /**<  PLL N-Divider value. */
  uint8_t p_div;                       /**<  PLL P-Divider value. */
  uint8_t k_div;                       /**<  K1-Divider(Prescalar mode) or K2-Divider (Normal mode). */
  XMC_SCU_CLOCK_SYSPLL_MODE_t mode;    /**<  PLL mode of operation. */
  XMC_SCU_CLOCK_SYSPLLCLKSRC_t clksrc; /**<  PLL divider input frequency. */
} XMC_SCU_CLOCK_SYSPLL_CONFIG_t;

/**
 *  Defines a data structure used for initializing the clock functional block.
 *  Clock functional block configures clock source needed for various peripheral and its divider values.
 *  Use type \a XMC_SCU_CLOCK_CONFIG_t for accessing these structure parameters.
 */
typedef struct XMC_SCU_CLOCK_CONFIG
{
  XMC_SCU_CLOCK_SYSPLL_CONFIG_t         syspll_config;      /**< PLL configuration */
  bool                                  enable_oschp;       /**< Enable external high precision oscillator.
                                                                 Should be enabled when fOHP has to be source of system clock. */
  bool                                  enable_osculp;      /**< Enable external ultra low power oscillator.
                                                                 Should be enabled when fULP has to be source of standby clock(fSTDBY). */
  XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_t calibration_mode;   /**< Backup clock trimming mode. */
  XMC_SCU_HIB_STDBYCLKSRC_t             fstdby_clksrc;      /**< Standby clock source. */
  XMC_SCU_CLOCK_SYSCLKSRC_t             fsys_clksrc;        /**< Choice of system clock. */
  uint8_t                               fsys_clkdiv;        /**< Ratio of fPLL to fSYS. */
  uint8_t                               fcpu_clkdiv;        /**< Ratio of fSys to fCPU. */
  uint8_t                               fccu_clkdiv;        /**< Ratio of fSys to fCCU. */
  uint8_t                               fperipheral_clkdiv; /**< Ratio of fSYS to fPERI. */
} const XMC_SCU_CLOCK_CONFIG_t;


/*********************************************************************************************************************
 * API PROTOTYPES
 ********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 
 * @param group   ADC Group to which the channel being monitored belongs to.\n
 *                 \b Range: 0 or 1.
 * @param channel  The channel whose voltage range has to be monitored.\n
 *                 \b Range: 6 or 7. Value identifies the channel in the selected ADC group.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables out of range comparator for the selected ADC group and channel. \n\n
 * The ADC channel input is compared by Out of Range Comparator (ORC) for overvoltage monitoring
 * or for detection of out of range analog inputs. ORC must be turned on explicitly
 * to leverage the auditing feature. ORC is enabled by setting the enable bit in the GORCEN register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_DisableOutOfRangeComparator()\n\n\n
 */
void XMC_SCU_EnableOutOfRangeComparator(const uint32_t group, const uint32_t channel);

/**
 * 
 * @param group   ADC Group to which the channel being monitored belongs to.\n
 *                 \b Range: 0 or 1.
 * @param channel  The channel whose voltage range has to be monitored.\n
 *                 \b Range: 6 or 7. Value identifies the channel in the selected ADC group.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables the out of range comparator for the selected ADC group and the channel. \n\n
 * Out of range comparator is disabled by clearing the enable bit in the GORCEN register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_EnableOutOfRangeComparator()\n\n\n
 */
void XMC_SCU_DisableOutOfRangeComparator(const uint32_t group, const uint32_t channel);

/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables die temperature measurement by powering the DTS module.\n\n
 * Die temperature sensor is enabled by setting the PWD bit of DTSCON register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_DisableTemperatureSensor(), XMC_SCU_IsTemperatureSensorEnabled(), XMC_SCU_CalibrateTemperatureSensor(),
 * XMC_SCU_StartTemperatureMeasurement(), XMC_SCU_GetTemperatureMeasurement() \n\n\n
 */
void XMC_SCU_EnableTemperatureSensor(void);

/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables die temperature measurement by powering the DTS module off.\n\n
 * Die temperature sensor is disabled by clearing the PWD bit of DTSCON register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_EnableTemperatureSensor(), XMC_SCU_IsTemperatureSensorEnabled(), XMC_SCU_CalibrateTemperatureSensor(),
 * XMC_SCU_StartTemperatureMeasurement(), XMC_SCU_GetTemperatureMeasurement() \n\n\n
 */
void XMC_SCU_DisableTemperatureSensor(void);

/**
 * @return Status of die temperature sensor. \n
 *          \b Range: true - if temperature sensor is enabled.\n
 *                    false - if temperature sensor is disabled.
 *
 * \par<b>Description</b><br>
 * Provides the die temperature sensor power status.\n\n
 * The status is obtained by reading the PWD bit of DTSCON register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_EnableTemperatureSensor(), XMC_SCU_CalibrateTemperatureSensor(),
 * XMC_SCU_StartTemperatureMeasurement(), XMC_SCU_GetTemperatureMeasurement() \n\n\n
 */
bool XMC_SCU_IsTemperatureSensorEnabled(void);

/**
 *
 * @param offset  Offset value for calibrating the DTS result.\n
 *                \b Range: 0 to 127.
 * @param gain    Gain value for calibrating the DTS conversion result.\n
 *                \b Range: 0 to 63.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Calibrates the measurement of temperature by configuring the values of offset and gain of \a DTSCON register. \n\n
 * Allows to improve the accuracy of the temperature measurement with the adjustment of \a OFFSET and \a GAIN bit fields
 * in the \a DTSCON register.
 * Offset adjustment is defined as a shift of the conversion result. The range of the offset adjustment is 7 bits with a 
 * resolution that corresponds to +/- 12.5?C. The offset value gets added to the measure result. 
 * Offset is considered as a signed value.
 * Gain adjustment helps in minimizing gain error. When the \a gain value is 0, result is generated with maximum gain.
 * When the \a gain value is 63, result is generated with least gain, i.e, \a RESULT - 63 at the highest measured temperature.\n
 * It is recommended to use following steps:\n
 * - Call \a XMC_SCU_StopTempMeasurement to stop temperature measurement if it was started previously.\n
 * - Call \a XMC_SCU_CalibrateTempMonitor with desired offset and gain calibration values to the DTS.\n
 * - Call \a XMC_SCU_SetRawTempLimits with desired lower and upper temperature threshold limit values if it is needed.\n
 * - Call \a XMC_SCU_StartTempMeasurement to start temperature measurement.\n
 * - Check whether Die Temperature Sensor (DTS) is busy in conversion by calling \a XMC_SCU_IsTemperatureSensorBusy() and wait till
 * conversion complete.\n
 * - Read the die temperature value using \a XMC_SCU_GetTemperatureMeasurement API.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_EnableTemperatureSensor(),
 * XMC_SCU_StartTemperatureMeasurement(), XMC_SCU_GetTemperatureMeasurement() \n\n\n
 */
void XMC_SCU_CalibrateTemperatureSensor(uint32_t offset, uint32_t gain);

/**
 * @return XMC_SCU_STATUS_t  Result of starting the temperature measurement.\n
 *                           \b Range: \n 
 *                              XMC_SCU_STATUS_OK if the measurement is started successfully.\n
 *                              XMC_SCU_STATUS_ERROR if temperature sensor is not enabled.\n
 *                              XMC_SCU_STATUS_BUSY if temperature sensor is busy measuring the temperature.\n
 *
 *
 * \par<b>Description</b><br>
 * Starts die temperature measurement using internal temperature sensor.\n\n
 * The API checks if the temperature sensor is enabled and is not busy in measurement.\n
 * It is recommended to use following steps:\n
 * - Call \a XMC_SCU_StopTempMeasurement to stop temperature measurement if it was started previously.\n
 * - Call \a XMC_SCU_SetRawTempLimits with desired lower and upper temperature threshold limit values if it is needed.\n
 * - Call \a XMC_SCU_StartTempMeasurement to start temperature measurement.\n
 * - Check whether Die Temperature Sensor (DTS) is busy in conversion by calling \a XMC_SCU_IsTemperatureSensorBusy() and wait till
 * conversion complete.\n
 * - Read the die temperature value using \a XMC_SCU_GetTemperatureMeasurement API.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_EnableTemperatureSensor(), XMC_SCU_CalibrateTemperatureSensor(),
 * XMC_SCU_GetTemperatureMeasurement() \n\n\n
 */
XMC_SCU_STATUS_t XMC_SCU_StartTemperatureMeasurement(void);


/**
 *
 * @return uint32_t  Measured temperature value.\n
 *              \b Range: Valid temperature range is 0 to 1023. \n
 *              If sensor is not enabled, 0x7FFFFFFFH is returned.
 *
 * \par<b>Description</b><br>
 * Reads the measured value of die temperature.\n\n
 * Temperature measurement result is read from \a RESULT bit field of \a DTSSTAT register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_IsTemperatureSensorBusy() \n\n\n
 */
uint32_t XMC_SCU_GetTemperatureMeasurement(void);

/**
 * @return bool  Indicates if the die temperature sensor is busy.\n
 *                    \b Range: \a true if sensor is busy in temperature measurement.
 *                    \a false if sensor is free and can accept a new request for measurement.
 *
 * \par<b>Description</b><br>
 * Checks whether Die Temperature Sensor (DTS) is busy in temperature measurement.\n\n
 * The status is read from the \a BUSY bit field of the \a DTSSTAT register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_GetTemperatureMeasurement() \n\n\n
 */
bool XMC_SCU_IsTemperatureSensorBusy(void);

/**
 * @return bool Status of die temperature sensor whether it is ready to start measurement. \n
 *          \b Range: \n \a true if temperature sensor is ready to start measurement. \n
 *          \a false if temperature sensor is not ready to start measurement.
 *
 * \par<b>Description</b><br>
 * Checks if the die temperature sensor is ready to start a measurement\n\n
 * The status is obtained by reading \a RDY bit of \a DTSSTAT register. It is recommended
 * to check the ready status of die temperature sensor before starting it.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_StartTemperatureMeasurement(), XMC_SCU_IsTemperatureSensorBusy() \n\n\n
 */
bool XMC_SCU_IsTemperatureSensorReady(void);

#if (UC_SERIES != XMC45)
/**
 * @return bool  Indicates if the measured die temperature value has exceeded the configured upper limit.\n
 *              \b Range: \a true if the temperature value has exceeded the configured upper limit. \a false
 *              if the temperature value is less than the configured upper limit.
 *
 * \par<b>Description</b><br>
 * Checks if the measured temperature has exceeded the configured upper limit of temperature.\n\n
 * The API checks \a OVERFL bit (Upper Limit Overflow Status bit) of \a DTEMPALARM register.
 * The \a OVERFL bit will be set if the measured temperature has exceeded the limit configured in 
 * the bitfield \a UPPER in the \a DTEMPLIM register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_SetRawTempLimits(),XMC_SCU_LowTemperature() \n\n\n
 */
bool XMC_SCU_HighTemperature(void);

/**
 *
 * @param lower_temp  Lower threshold of die temperature. If measured temperature falls below this value, 
 *                    alarm bit will be set in \a UNDERFL bit field of \a DTEMPALARM register.
 * @param upper_temp  Upper threshold of die temperature. If measured temperature exceeds this value, 
 *                    alarm bit will be set in \a OVERFL bit field of \a DTEMPALARM register.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the lower and upper threshold of die temperature.\n\n
 * API configures \a DTEMPLIM register for upper and lower die temperature threshold limits.
 * When the measured temperature is outside the range defined by the limits, alarm bits \a UNDERFL or \a OVERFL
 * will be set in the register \a DTEMPALARM.\n
 * It is recommended to use following steps:\n
 * - Call \a XMC_SCU_StopTempMeasurement to stop temperature measurement if it was started previously.\n
 * - Call \a XMC_SCU_SetRawTempLimits with desired lower and upper temperature threshold limit values.\n
 * - Call \a XMC_SCU_StartTempMeasurement to start temperature measurement.\n
 * - Use \a XMC_SCU_HighTemperature() and XMC_SCU_LowTemperature() to monitor the temperature.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HighTemperature(), XMC_SCU_LowTemperature() \n\n\n
 */
void XMC_SCU_SetRawTempLimits(const uint32_t lower_temp, const uint32_t upper_temp);

/**
 * @return bool  Indicates if the measured die temperature value has dropped below the configured lower limit.\n
 *              \b Range: \a true if the temperature value has dropped below the configured lower limit. \a false
 *              if the temperature value is higher than the configured lower limit.
 *
 * \par<b>Description</b><br>
 * Checks if the measured temperature has dropped below the configured lower limit of temperature.\n\n
 * The API checks \a UNDERFL bit (Lower LimitUnderflow Status bit) of \a DTEMPALARM register.
 * The \a UNDERFL bit will be set if the measured temperature has dropped below the limit configured in 
 * the bitfield \a LOWER in the \a DTEMPLIM register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_SetRawTempLimits(),XMC_SCU_HighTemperature() \n\n\n
 */
bool XMC_SCU_LowTemperature(void);
#endif

/**
 * @return uint32_t Configured boot mode for the device.\n
 *        \b Range: Use type @ref XMC_SCU_BOOTMODE_t for enumeration of different boot modes.
 *
 * \par<b>Description</b><br>
 * Provides the boot mode configured for the device.\n\n
 * The boot mode is read from the \a STCON register bit field \a SWCON.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_SetBootMode() \n\n\n
 */
uint32_t XMC_SCU_GetBootMode(void);

/**
 *
 * @param mode Boot mode to be configured for the device.\n
 *        \b Range: Use type @ref XMC_SCU_BOOTMODE_t for selecting the boot mode.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the desired boot mode for the device.\n\n
 * The XMC4 series devices support multiple boot modes. A running application can set a desired bootmode and 
 * launch it by means of software reset. Switching of boot modes should be handled carefully. User should ensure that
 * the initial boot sequence is executed. A stable execution environment should be maintained when program control is 
 * eventually handed over to the application program.\n
 * It is recommended to use following steps to launch requested bootmode:\n
 * - Call \a XMC_SCU_SetBootMode() with desired boot mode value.\n
 * - Trigger a software reset using system reset request by enabling a bit \a SYSRESETREQ of AIRCR register
 *   (PPB->AIRCR |= PPB_AIRCR_SYSRESETREQ_Msk).\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_GetBootMode() \n\n\n
 */
void XMC_SCU_SetBootMode(const XMC_SCU_BOOTMODE_t mode);

/**
 *
 * @param index  The SCU general purpose register to be read.\n
 *        \b Range: 0 and 1 corresponding to GPR0 and GPR1.
 *
 * @return uint32_t  Data read from the selected general purpose register.
 *
 * \par<b>Description</b><br>
 * Provides stored data from general purpose SCU register.\n\n
 * SCU consists of 2 general purpose registers. These registers can be used for storing
 * data. The API reads from either GPR0 or GPR1 based on the \a index value.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_WriteGPR()\n\n\n
 */
uint32_t XMC_SCU_ReadGPR(const uint32_t index);
 
/**
 *
 * @param index  The SCU general purpose register to be written.\n
 *        \b Range: 0 and 1 corresponding to GPR0 and GPR1.
 * @param data  Data to be written to the selected general purpose register.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Stores data in the selected general purpose SCU register.\n\n
 * SCU consists of 2 general purpose registers. These registers can be used for storing
 * data. The API writes data to either GPR0 or GPR1 based on the \a index value.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_ReadGPR()\n\n\n
 */
void XMC_SCU_WriteGPR(const uint32_t index, const uint32_t data);

/**
 *
 * @param address  Location in the retention memory to be written.\n
 *        \b Range: 4 bit address space is provided for selecting 16 words of 32 bits.
 *                  equivalent to 64 bytes of data. \a address value should be from
 *                  0 to 15.
 * @param data    32 bit data to be written into retention memory. The API writes
 *                one word(4 bytes) of data to the address specified.\n
 *                \b Range: 32 bit data.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Writes input data to the selected address of Retention memory in hibernate domain.\n\n
 * The retention memory is located in hibernate domain. 
 * It is used for the purpose of store/restore of context information.
 * Access to the retention memory space is served over shared serial interface. 
 * Retention memory content is retained even in hibernate mode.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_ReadFromRetentionMemory() \n\n\n
 */
void XMC_SCU_WriteToRetentionMemory(uint32_t address, uint32_t data);

/**
 *
 * @param address  Location in the retention memory to be read.\n
 *        \b Range: 4 bit address space is provided for selecting 16 words of 32 bits.
 *                  equivalent to 64 bytes of data. \a address value should be from
 *                  0 to 15.
 *
 * @return uint32_t  32 bit data read from retention memory. The API reads
 *                one word(4 bytes) of data from the address specified.\n
 *                \b Range: 32 bit data.
 *
 * \par<b>Description</b><br>
 * Reads data from selected address of retention memory in hibernate domain.\n\n
 * The retention memory is located in hibernate domain. 
 * It is used for the purpose of store/restore of context information.
 * Access to the retention memory space is served over shared serial interface. 
 * Retention memory content is retained even in hibernate mode.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_WriteToRetentionMemory() \n\n\n
 */
uint32_t XMC_SCU_ReadFromRetentionMemory(uint32_t address);

/**
 *
 * @param request  Non-maskable interrupt (NMI) request source to be enabled.\n
 *              \b Range: Use type @ref XMC_SCU_NMIREQ_t for selecting the source of NMI. Multiple 
 *              sources can be combined using \a OR operation.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Selectively enables interrupt sources to generate non maskable interrupt(NMI).\n\n
 * NMI assertion can be individually enabled by setting corresponding bit of an interrupt in the 
 * \a NMIREQEN register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_INTERRUPT_DisableNmiRequest() \n\n\n
 */
void XMC_SCU_INTERRUPT_EnableNmiRequest(const uint32_t request);

/**
 *
 * @param request  Non-maskable interrupt (NMI) request source to be disabled.\n
 *              \b Range: Use type @ref XMC_SCU_NMIREQ_t for selecting the source of NMI. Multiple 
 *              sources can be combined using \a OR operation.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Selectively disables interrupt sources from generating non maskable interrupt(NMI).\n\n
 * NMI assertion can be individually disabled by clearing corresponding bits in the \a NMIREQEN register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_INTERRUPT_EnableNmiRequest() \n\n\n
 */
void XMC_SCU_INTERRUPT_DisableNmiRequest(const uint32_t request);

/**
 *
 * @param trap  The event for which, trap generation has to be enabled.\n
 *        \b Range: Use type @ref XMC_SCU_TRAP_t to identify the event.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Enables assertion of trap for the selected trap event.\n\n
 * Trap assertion can be individually enabled by clearing respective bit of the 
 * event in \a TRAPDIS register in order to get an exception.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_TRAP_Disable(), XMC_SCU_TRAP_ClearStatus(), XMC_SCU_TRAP_GetStatus() \n\n\n
 */
void XMC_SCU_TRAP_Enable(const uint32_t trap);

/**
 *
 * @param trap  The event for which, trap generation has to be disabled.\n
 *        \b Range: Use type @ref XMC_SCU_TRAP_t to identify the event.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Disables assertion of trap for the selected trap event.\n\n
 * Trap assertion can be individually disabled by setting the respective event bit 
 * in the \a TRAPDIS register in order to suppress trap generation.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_TRAP_Enable(), XMC_SCU_TRAP_ClearStatus(), XMC_SCU_TRAP_GetStatus() \n\n\n
 */
void XMC_SCU_TRAP_Disable(const uint32_t trap);

/**
 *
 * @param trap  The event for which, trap status bit has to be cleared.\n
 *        \b Range: Use type @ref XMC_SCU_TRAP_t to identify the event.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Clears the trap status of input event.\n\n
 * Once a trap event is detected, it will have to be acknowledged and later serviced. 
 * The trap status bit should be cleared to detect the occurence of trap next time. 
 * This is useful while polling for TRAPSTAT without enabling the NMI for trap.
 * Trap status can be cleared by setting the event bit in the \a TRAPCLR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_INTERRUPT_EnableNmiRequest(), XMC_SCU_TRAP_GetStatus() \n\n\n
 */
void XMC_SCU_TRAP_ClearStatus(const uint32_t trap);

/**
 * @return uint32_t  Status of trap generating events.\n
 *        \b Range: Use type @ref XMC_SCU_TRAP_t to identify the event. The returned
 * value indicates the status of multiple events at their respective bit positions.
 * User should mask the bits of the events of interest using the type specified.
 *
 * \par<b>Description</b><br>
 * Provides the status of trap generating events. \n\n
 * The status is read from \a TRAPRAW register. Status of the specific events can be checked
 * using their respective bits in the \a TRAPRAW register. The bit masks can be obtained from
 * the enumeration type @ref XMC_SCU_TRAP_t. Multiple events can be combined using \a OR operation.
 * A trap event is considered to be asserted if the respective bit of the event is set to 1.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_INTERRUPT_EnableNmiRequest(), XMC_SCU_TRAP_ClearStatus() \n\n\n
 */
uint32_t XMC_SCU_TRAP_GetStatus(void);  

/**
 *
 * @param trap  The event for which, trap has to be triggered.\n
 *        \b Range: Use type @ref XMC_SCU_TRAP_t to identify the event.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Triggers trap generation for the event specified. \n\n
 * The trap source has to be enabled before invocation of this API. 
 * Trap event can be triggered by setting its respective bit in the \a TRAPSET register.
 * Trap event can be configured to generate a non maskable interrupt by using the API XMC_SCU_INTERRUPT_EnableNmiRequest().\n
 * It is recommended to use following steps to manually assert a trap event:\n
 * - Call \a XMC_SCU_TRAP_EnableEvent with desired trap request source ID.\n
 * - Call \a XMC_SCU_TRAP_SetEvent with same trap request source ID to manually assert a trap event.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_INTERRUPT_EnableNmiRequest(), XMC_SCU_TRAP_GetStatus() \n\n\n
 */
void XMC_SCU_TRAP_Trigger(const uint32_t trap);

/**
 *
 * @param peripheral  The peripheral to be reset.\n
 *        \b Range: Type @ref XMC_SCU_PERIPHERAL_RESET_t enumerates all the peripherals that can be reset.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Puts the specified peripheral in to reset state. \n\n
 * The API achieves reset of peripherals by setting the respective bit in the \a PRSET0,  \a PRSET1 or  \a PRSET2
 * register. Status of reset assertion automatically stored in the \a PRSTATn register and can be checked by
 * user software to determine the state of the system and for debug purpose.\n
 * It is recommended to use following steps to assert a peripheral reset:\n
 * - Call \a XMC_SCU_RESET_AssertPeripheralReset() with desired peripheral identifier.\n
 * - Call \a XMC_SCU_RESET_IsPeripheralResetAsserted with same peripheral identifier to verify whether peripheral
 * is in reset state.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_RESET_IsPeripheralResetAsserted() \n\n\n
 */
void XMC_SCU_RESET_AssertPeripheralReset(const XMC_SCU_PERIPHERAL_RESET_t peripheral);

/**
 *
 * @param peripheral  The peripheral to be moved out of reset state.\n
 *        \b Range: Type @ref XMC_SCU_PERIPHERAL_RESET_t enumerates all the peripherals that can be reset.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables the specified peripheral by moving it out of reset state.  \n\n
 * Any peripheral should be moved out of reset state for executing its functionality.
 * The API enables the peripheral by setting its respective bit in the \a PRCLR0,  \a PRCLR1 or  \a PRCLR2
 * register. Status of reset deassertion is automatically stored in the \a PRSTATn register and can be checked by
 * the user software to determine the state of the system and for debug purpose.\n
 * It is recommended to use following steps to deassert a peripheral reset:\n
 * - Call \a XMC_SCU_RESET_DeassertPeripheralReset() with desired peripheral identifier.\n
 * - Call \a XMC_SCU_RESET_IsPeripheralResetAsserted() with desired peripheral identifier to verify whether peripheral
 * has been enabled.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_RESET_AssertPeripheralReset() \n\n\n
 */
void XMC_SCU_RESET_DeassertPeripheralReset(const XMC_SCU_PERIPHERAL_RESET_t peripheral);

/**
 *
 * @param peripheral  The peripheral, whose reset status has to be checked.\n
 *        \b Range: Type @ref XMC_SCU_PERIPHERAL_RESET_t enumerates all the peripherals.
 *
 * @return bool  Status of peripheral reset. \n
 *               \b Range: \a true if peripheral is in reset state. \a false if peripheral is enabled and out of reset state.
 *
 * \par<b>Description</b><br>
 * Checks the reset status of the selected peripheral.\n\n
 * The API reads the reset status from \a PRSTATn register. Returns true if the peripheral is in
 * reset state. On power up of the device, all the peripherals will be in reset state. 
 * If the peripheral is enabled, \a false will be returned as the status.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_RESET_AssertPeripheralReset(), XMC_SCU_RESET_DeassertPeripheralReset() \n\n\n 
 */
bool XMC_SCU_RESET_IsPeripheralResetAsserted(const XMC_SCU_PERIPHERAL_RESET_t peripheral);
 
/**
 *
 * @param memory  The on-chip RAM type, for which the parity error status has to be cleared.\n
 *          \b Range: Use type @ref XMC_SCU_PARITY_t to identify the on-chip RAM type. Multiple 
 *          memory status bits can be cleared by using the \a OR operation.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Clears the parity error status bit. \n\n
 * When a memory parity error is detected using the status bits in \a PEFLAG register. It has to 
 * be cleared by software to detect the parity error from the same memory next time.
 * The API clears the parity error status bit of the selected peripheral by setting the 
 * respective bit in the \a PEFLAG register. Status of multiple memory parity errors 
 * can be cleared by combining the enum values using \a OR operation.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_PARITY_GetStatus(), XMC_SCU_PARITY_Enable(), XMC_SCU_PARITY_EnableTrapGeneration() \n\n\n
 */
void XMC_SCU_PARITY_ClearStatus(const uint32_t memory);

/**
 *
 * @param memory  The on-chip RAM type, for which the parity error checking has to be enabled.\n
 *          \b Range: Use type @ref XMC_SCU_PARITY_t to identify the on-chip RAM type. Multiple 
 *          memory types can be combined using the \a OR operation.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Enables parity error checking for the selected on-chip RAM type.\n\n
 * Parity error checking can be enabled by setting respective bits in the \a PEEN register.
 * Additionally parity error can be configured to generate trap when the error is detected,
 * using the API XMC_SCU_PARITY_EnableTrapGeneration(). Such a trap can be further configured
 * to generate non maskable interrupt(NMI) using the API XMC_SCU_INTERRUPT_EnableNmiRequest().
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_PARITY_EnableTrapGeneration(), XMC_SCU_INTERRUPT_EnableNmiRequest() \n\n\n
 */
void XMC_SCU_PARITY_Enable(const uint32_t memory);

/**
 *
 * @param memory   The on-chip RAM type, for which the parity error checking has to be disabled.\n
 *          \b Range: Use type @ref XMC_SCU_PARITY_t to identify the on-chip RAM type. Multiple 
 *          memory types can be combined using the \a OR operation.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Disables parity error checking for the selected on-chip RAM type.\n\n
 * Parity error detection can be disabled by clearing the respective bit in the \a PEEN register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_PARITY_Enable(), XMC_SCU_PARITY_DisableTrapGeneration() \n\n\n
 */
void XMC_SCU_PARITY_Disable(const uint32_t memory);

/**
 *
 * @param memory  The on-chip RAM type, for which the parity error trap generation has to be enabled.\n
 *          \b Range: Use type @ref XMC_SCU_PARITY_t to identify the on-chip RAM type. Multiple 
 *          memory types can be combined using the \a OR operation.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Enables trap assertion for the parity error source.\n\n
 * Parity error detection for different types of on-chip RAM can generate trap.
 * Trap assertion for parity error can be individually enabled by setting the respective bits
 * in the \a PETE register. The generated trap can be additionally configured to generate
 * non maskable interrupt(NMI) using the API XMC_SCU_INTERRUPT_EnableNmiRequest().
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_INTERRUPT_EnableNmiRequest(), XMC_SCU_PARITY_DisableTrapGeneration() \n\n\n
 */
void XMC_SCU_PARITY_EnableTrapGeneration(const uint32_t memory);

/**
 *
 * @param memory  The on-chip RAM type, for which the parity error trap generation has to be disabled.\n
 *          \b Range: Use type @ref XMC_SCU_PARITY_t to identify the on-chip RAM type. Multiple 
 *          memory types can be combined using the \a OR operation.
 *
 * @return None  
 *
 * \par<b>Description</b><br>
 * Disables the assertion of trap for the parity error source.\n\n
 * Trap assertion can be disabled by clearing the respective bit of the RAM type in the \a PETE register.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_PARITY_EnableTrapGeneration() \n\n\n
 */
void XMC_SCU_PARITY_DisableTrapGeneration(const uint32_t memory);

/**
 *
 * @return uint32_t  Status of parity error detection for the on-chip RAM modules.\n
 *          \b Range: Use type @ref XMC_SCU_PARITY_t to get the bit mask of each RAM module type.
 *
 * \par<b>Description</b><br>
 * Provides the status of parity error detection for the on-chip RAM modules.\n\n
 * Parity error status information is obtained from the \a PEFLAG register.
 * If a particular RAM module has parity error, its respective bit field will be set to 1 in the 
 * returned value. A check for the status of a particular RAM module can be done by
 * masking the returned value with the RAM module identifier from the type @ref XMC_SCU_PARITY_t.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_PARITY_ClearStatus() \n\n\n
 */
uint32_t XMC_SCU_PARITY_GetStatus(void);  

/**
 *
 * @param clock  Peripheral for which the clock has to be enabled. \n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_t to select the peripheral.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables the source clock for selected peripheral.\n\n
 * The various outputs of Clock Generation Unit (CGU) can be individually enabled by setting the peripheral
 * specific bit in the \a CLKSET register.\n
 * It is recommended to use following steps to verify whether a source clock of peripheral is enabled/disabled:\n
 * - Call \a XMC_SCU_CLOCK_EnableClock() with desired peripheral identifier.\n
 * - Call \a XMC_SCU_CLOCK_IsClockEnabled() with same peripheral identifier to verify whether the clock is enabled.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_DisableClock(), XMC_SCU_RESET_DeassertPeripheralReset() \n\n\n
 */
void XMC_SCU_CLOCK_EnableClock(const XMC_SCU_CLOCK_t clock);

/**
 *
 * @param clock  Peripheral for which the clock has to be disabled. \n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_t to select the peripheral.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables source clock for the peripheral selected.\n\n
 * The various outputs of Clock Generation Unit (CGU) can be individually disabled  by setting the peripheral
 * specific bits in the \a CLKCLR register.\n
 * It is recommended to use following steps to verify whether clock source of the peripheral is enabled/disabled:\n
 * - Call \a XMC_SCU_CLOCK_DisableClock with desired peripheral identifier.\n
 * - Call \a XMC_SCU_CLOCK_IsClockEnabled with same peripheral identifier to verify whether peripheral is enabled/disabled.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_EnableClock(), XMC_SCU_RESET_AssertPeripheralReset() \n\n\n
 */
void XMC_SCU_CLOCK_DisableClock(const XMC_SCU_CLOCK_t clock);

/**
 *
 * @param clock   Peripheral for which the clock status has to be checked. \n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_t to select the peripheral.
 *
 * @return bool  Status of peripheral clock.\n
 *        \b Range: \a true if peripheral clock is enabled. \a false if peripheral clock is disabled.
 *
 * \par<b>Description</b><br>
 * Checks the status of peripheral source clock.\n\n
 * The status of peripheral source clock is read from the \a CLKSTATn register. 
 * Returns \a true if clock is enabled and returns \a false otherwise.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_EnableClock(), XMC_SCU_CLOCK_DisableClock() \n\n\n
 */
bool XMC_SCU_CLOCK_IsClockEnabled(const XMC_SCU_CLOCK_t clock);

/**
 *
 * @param source  Source of clock for fSYS.\n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_SYSCLKSRC_t to select the source of clock.\n
 *                  XMC_SCU_CLOCK_SYSCLKSRC_OFI for selecting internal fast clock as fSYS.\n
 *                  XMC_SCU_CLOCK_SYSCLKSRC_PLL for selecting the output of PLL fPLL as fSYS.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Selects the source for system clock (fSYS).\n\n
 * System clock is selected by setting \a SYSSEL bits in the \a SYSCLKCR register.
 * If \a XMC_SCU_CLOCK_SYSCLKSRC_PLL is selected, then the dividers of the PLL have to be
 * additionally configured to achieve the required system clock frequency. 
  * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_StartSystemPll(), XMC_SCU_CLOCK_EnableHighPerformanceOscillator() \n\n\n
 */
void XMC_SCU_CLOCK_SetSystemClockSource(const XMC_SCU_CLOCK_SYSCLKSRC_t source);

/**
 * @return XMC_SCU_CLOCK_SYSCLKSRC_t   Source of clock for fSYS.\n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_SYSCLKSRC_t to select the source of clock.\n
 *                  XMC_SCU_CLOCK_SYSCLKSRC_OFI - internal fast clock selected as fSYS.\n
 *                  XMC_SCU_CLOCK_SYSCLKSRC_PLL - output of PLL fPLL selected as fSYS.
 *
 * \par<b>Description</b><br>
 * Provides the selected source of system clock (fSYS). \n\n
 * Selected source of fSYS is obtained by reading \a SYSSEL bits of \a SYSCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetSystemClockSource(), XMC_SCU_CLOCK_GetSystemPllClockSourceFrequency() \n\n\n
 */
__STATIC_INLINE XMC_SCU_CLOCK_SYSCLKSRC_t XMC_SCU_CLOCK_GetSystemClockSource(void)
{
  return (XMC_SCU_CLOCK_SYSCLKSRC_t)(SCU_CLK->SYSCLKCR & SCU_CLK_SYSCLKCR_SYSSEL_Msk);
}

/**
 *
 * @param source   Source of clock for USB and SDMMC(fUSB/SDMMC).\n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_USBCLKSRC_t to select the source of clock.\n
 *                  XMC_SCU_CLOCK_USBCLKSRC_USBPLL - output of USB PLL as source of USB clock(fUSB/SDMMC).\n
 *                  XMC_SCU_CLOCK_USBCLKSRC_SYSPLL - output of PLL fPLL as source of USB clock(fUSB/SDMMC).
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Selects the source of USB/SDMMC clock (fUSB/SDMMC).\n\n
 * USB and SDMMC use a common clock source. They can either use fUSB PLL or fPLL as the source of clock.
 * The selection is done by configuring the \a USBSEL bits of \a USBCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetUsbClockDivider(), XMC_SCU_CLOCK_GetUsbPllClockFrequency() \n\n\n
 */
void XMC_SCU_CLOCK_SetUsbClockSource(const XMC_SCU_CLOCK_USBCLKSRC_t source);

/**
 * @return XMC_SCU_CLOCK_USBCLKSRC_t   Source of clock for USB and SDMMC(fUSB/SDMMC).\n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_USBCLKSRC_t to identify the source of clock.\n
 *                  XMC_SCU_CLOCK_USBCLKSRC_USBPLL - output of USB PLL is selected as source of USB clock(fUSB/SDMMC).\n
 *                  XMC_SCU_CLOCK_USBCLKSRC_SYSPLL - output of PLL fPLL is selected as source of USB clock(fUSB/SDMMC).
 *
 * \par<b>Description</b><br>
 * Provides the selected source of USB and SDMMC clock frequency.\n\n
 * The clock source is read from from the \a USBSEL bits of \a USBCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetUsbClockDivider(), XMC_SCU_CLOCK_GetUsbPllClockFrequency() \n\n\n
 */
__STATIC_INLINE XMC_SCU_CLOCK_USBCLKSRC_t XMC_SCU_CLOCK_GetUsbClockSource(void)
{
  return (XMC_SCU_CLOCK_USBCLKSRC_t)(SCU_CLK->USBCLKCR & SCU_CLK_USBCLKCR_USBSEL_Msk);
}

/**
 *
 * @param source  Clock source for watchdog timer.\n
 *        \b Range: Use type XMC_SCU_CLOCK_WDTCLKSRC_t to identify the clock source.\n
 *                  XMC_SCU_CLOCK_WDTCLKSRC_OFI - internal fast oscillator (fOFI)\n
 *                  XMC_SCU_CLOCK_WDTCLKSRC_STDBY - backup standby clock (fSTDBY)\n
 *                  XMC_SCU_CLOCK_WDTCLKSRC_PLL - PLL output clock (fPLL)
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Selects the source of WDT clock (fWDT).\n\n
 * The selected value is configured to the \a WDTSEL bits of \a WDTCLKCR register.
 * The watchdog timer counts at the frequency selected using this API. So the time for
 * timeout or pre-warning of watchdog has to be calculated based on this selection.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetWdtClockDivider(), XMC_SCU_CLOCK_GetWdtClockFrequency() \n\n\n
 */
void XMC_SCU_CLOCK_SetWdtClockSource(const XMC_SCU_CLOCK_WDTCLKSRC_t source);

/**
 * @return XMC_SCU_CLOCK_WDTCLKSRC_t   Clock source configured for watchdog timer.\n
 *        \b Range: Use type XMC_SCU_CLOCK_WDTCLKSRC_t to identify the clock source.\n
 *                  XMC_SCU_CLOCK_WDTCLKSRC_OFI - internal fast oscillator (fOFI)\n
 *                  XMC_SCU_CLOCK_WDTCLKSRC_STDBY - backup standby clock (fSTDBY)\n
 *                  XMC_SCU_CLOCK_WDTCLKSRC_PLL - PLL output clock (fPLL)
 *
 * \par<b>Description</b><br>
 * Provides the source of clock used for watchdog timer.\n\n
 * The value is obtained by reading \a WDTSEL bits of \a WDTCLKCR register.
 * The time for timeout or pre-warning of watchdog has to be calculated based on 
 * the clock source selected.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetWdtClockDivider(), XMC_SCU_CLOCK_SetWdtClockSource() \n\n\n
 */
__STATIC_INLINE XMC_SCU_CLOCK_WDTCLKSRC_t XMC_SCU_CLOCK_GetWdtClockSource(void)
{
  return (XMC_SCU_CLOCK_WDTCLKSRC_t)(SCU_CLK->WDTCLKCR & SCU_CLK_WDTCLKCR_WDTSEL_Msk);
}

/**
 *
 * @param source   Source for standby clock.\n
 *          \b Range: Use type @ref XMC_SCU_HIB_STDBYCLKSRC_t to identify the clock source.\n
 *                    XMC_SCU_HIB_STDBYCLKSRC_OSI - internal slow oscillator (fOSI) \n
 *                    XMC_SCU_HIB_STDBYCLKSRC_OSCULP - ultra low power osciallator (fULP) \n
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Selects the source of Standby clock (fSTDBY).\n\n
 * Clock source is configured by setting the \a STDBYSEL bits of \a HDCR register.
 * Hibernate domain should be enabled explicitly before using the API.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_GetStdbyClockSource(), XMC_SCU_HIB_EnableHibernateDomain() \n\n\n
 */
void XMC_SCU_HIB_SetStandbyClockSource(const XMC_SCU_HIB_STDBYCLKSRC_t source);

/**
 * @return XMC_SCU_HIB_RTCCLKSRC_t   Source clock of standby clock(fSTDBY).\n
 *          \b Range: Use type @ref XMC_SCU_HIB_STDBYCLKSRC_t to identify the clock source.\n
 *                    XMC_SCU_HIB_STDBYCLKSRC_OSI - internal slow oscillator (fOSI) \n
 *                    XMC_SCU_HIB_STDBYCLKSRC_OSCULP - ultra low power osciallator (fULP) \n
 *
 * \par<b>Description</b><br>
 * Provides the source of standby clock (fSTDBY).\n\n
 * The value is obtained by reading \a STDBYSEL bits of \a HDCR register.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_SetStandbyClockSource(), XMC_SCU_HIB_EnableHibernateDomain() \n\n\n
 */
__STATIC_INLINE XMC_SCU_HIB_RTCCLKSRC_t XMC_SCU_HIB_GetStdbyClockSource(void)
{
  return (XMC_SCU_HIB_RTCCLKSRC_t)(SCU_HIBERNATE->HDCR & SCU_HIBERNATE_HDCR_STDBYSEL_Msk);
}

/**
 *
 * @param source  Source of RTC clock.\n
 *            \b Range: Use type @ref XMC_SCU_HIB_RTCCLKSRC_t to identify the clock source.\n
 *                       XMC_SCU_HIB_RTCCLKSRC_OSI - internal slow oscillator(fOSI). \n
 *                       XMC_SCU_HIB_RTCCLKSRC_ULP - ultra low power oscillator(fULP). \n
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Selects the source of RTC clock (fRTC).\n\n
 * The value is configured to \a RCS bit of \a HDCR register.
 * fULP needs external input powered by VBAT or VDDP. fOSI is internal clock.
 * The frequency of the clock will be 32.768 kHz.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_GetRtcClockSource() \n\n\n
 */
void XMC_SCU_HIB_SetRtcClockSource(const XMC_SCU_HIB_RTCCLKSRC_t source);

/**
 * @return XMC_SCU_HIB_RTCCLKSRC_t   Source of RTC clock.\n
 *            \b Range: Use type @ref XMC_SCU_HIB_RTCCLKSRC_t to identify the clock source.\n
 *                       XMC_SCU_HIB_RTCCLKSRC_OSI - internal slow oscillator(fOSI). \n
 *                       XMC_SCU_HIB_RTCCLKSRC_ULP - ultra low power oscillator(fULP). \n
 *
 * \par<b>Description</b><br>
 * Provides the source of RTC clock (fRTC).
 * The value is obtained by reading \a RCS bit of \a HDCR register.
 * The frequency of the clock will be 32.768 kHz.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_SetRtcClockSource() \n\n\n
 */
__STATIC_INLINE XMC_SCU_HIB_RTCCLKSRC_t XMC_SCU_HIB_GetRtcClockSource(void)
{
  return (XMC_SCU_HIB_RTCCLKSRC_t)(SCU_HIBERNATE->HDCR & SCU_HIBERNATE_HDCR_RCS_Msk);
}

/**
 *
 * @param clock  Source of external clock output(fEXT).\n
 *           \b Range: Use type @ref XMC_SCU_CLOCK_EXTOUTCLKSRC_t to identify the clock.\n
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_SYS - system clock fSYS. \n
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_USB - USB clock fUSB. \n
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_PLL - PLL output fPLL. \n
 * \if XMC42
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_STDBY - Standby clock fSTDBY. \n
 *
 * \endif
 * \if XMC41
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_STDBY - Standby clock fSTDBY. \n
 * \endif
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Selects the source of external clock out (fEXT).\n\n
 * The value will be configured to \a ECKSEL bits of \a EXTCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetExternalOutputClockSource(), XMC_SCU_CLOCK_SetExternalOutputClockDivider() \n\n\n
 */
void XMC_SCU_CLOCK_SetExternalOutputClockSource(const XMC_SCU_CLOCK_EXTOUTCLKSRC_t clock);

/**
 * @return XMC_SCU_CLOCK_EXTOUTCLKSRC_t   Source of external clock output(fEXT).\n
 *           \b Range: Use type @ref XMC_SCU_CLOCK_EXTOUTCLKSRC_t to identify the clock.\n
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_SYS - system clock fSYS. \n
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_USB - USB clock fUSB. \n
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_PLL - PLL output fPLL. \n
 * \if XMC42
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_STDBY - Standby clock fSTDBY. \n
 * \endif
 * \if XMC41
 *                      XMC_SCU_CLOCK_EXTOUTCLKSRC_STDBY - Standby clock fSTDBY. \n
 * \endif
 *
 * \par<b>Description</b><br>
 * Provides the source of external clock output(fEXT).\n\n
 * The value is obtained by reading \a ECKSEL bits of \a EXTCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetExternalOutputClockSource(), XMC_SCU_CLOCK_SetExternalOutputClockDivider() \n\n\n
 */
__STATIC_INLINE XMC_SCU_CLOCK_EXTOUTCLKSRC_t XMC_SCU_CLOCK_GetExternalOutputClockSource(void)
{
  return (XMC_SCU_CLOCK_EXTOUTCLKSRC_t)(SCU_CLK->EXTCLKCR & SCU_CLK_EXTCLKCR_ECKSEL_Msk);
}

/**
 *
 * @param source  Source of clock for system PLL.\n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_SYSPLLCLKSRC_t for identifying the clock source.\n
 *                            XMC_SCU_CLOCK_SYSPLLCLKSRC_OSCHP - External High performance oscillator(fOHP).\n
 *                            XMC_SCU_CLOCK_SYSPLLCLKSRC_OFI - Internal fast clock (fOFI).
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Selects the source of system PLL.\n\n
 * The value is configured to \a VCOBYP bit of \a PLLCON0 register.
 * If \a XMC_SCU_CLOCK_SYSPLLCLKSRC_OSCHP is selected, ensure that the high performance oscillator is 
 * enabled by using the API XMC_SCU_CLOCK_EnableHighPerformanceOscillator().
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_EnableHighPerformanceOscillator()\n\n\n
 */
void XMC_SCU_CLOCK_SetSystemPllClockSource(const XMC_SCU_CLOCK_SYSPLLCLKSRC_t source);

/**
 * @return XMC_SCU_CLOCK_OSCCLKSRC_t   Source of clock for system PLL.\n
 *        \b Range: Use type @ref XMC_SCU_CLOCK_SYSPLLCLKSRC_t for identifying the clock source.\n
 *                            XMC_SCU_CLOCK_SYSPLLCLKSRC_OSCHP - External High performance oscillator(fOHP).\n
 *                            XMC_SCU_CLOCK_SYSPLLCLKSRC_OFI - Internal fast clock (fOFI).
 *
 * \par<b>Description</b><br>
 * Provides the source of system PLL clock (fPLL). \n\n
 * The value is obtained by reading \a VCOBYP bit of \a PLLCON0 register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_EnableHighPerformanceOscillator(), XMC_SCU_CLOCK_SetSystemPllClockSource()\n\n\n
 */
__STATIC_INLINE XMC_SCU_CLOCK_SYSPLLCLKSRC_t XMC_SCU_CLOCK_GetSystemPllClockSource(void)
{
  return (XMC_SCU_CLOCK_SYSPLLCLKSRC_t)(SCU_PLL->PLLCON0 & SCU_PLL_PLLCON0_VCOBYP_Msk);
}

#if defined(ECAT0) 
__STATIC_INLINE void XMC_SCU_CLOCK_SetECATClockSource(const XMC_SCU_CLOCK_ECATCLKSRC_t source)
{
  SCU_CLK->ECATCLKCR = (SCU_CLK->ECATCLKCR & ((uint32_t)~SCU_CLK_ECATCLKCR_ECATSEL_Msk)) |
                      ((uint32_t)source);
}

__STATIC_INLINE XMC_SCU_CLOCK_ECATCLKSRC_t XMC_SCU_CLOCK_GetECATClockSource(void)
{
  return (XMC_SCU_CLOCK_ECATCLKSRC_t)((SCU_CLK->ECATCLKCR & SCU_CLK_ECATCLKCR_ECATSEL_Msk) >> SCU_CLK_ECATCLKCR_ECATSEL_Pos);
}
#endif

/**
 *
 * @param divider   Ratio of fSYS clock source to the value of fSYS.
 *              \b Range: 1 to 256.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the ratio of system clock source to the value of system clock frequency.\n\n
 * The value is configured as \a SYSDIV bits of \a SYSCLKCR register. The divider value is 
 * decremented by 1 before configuring.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetSystemClockDivider(),  XMC_SCU_CLOCK_SetSystemClockSource() \n\n\n
 */
void XMC_SCU_CLOCK_SetSystemClockDivider(const uint32_t divider);

/**
 * @return uint32_t   Ratio of fSYS clock source to the value of fSYS.
 *              \b Range: 1 to 256.
 *
 * \par<b>Description</b><br>
 * Provides the value of ratio between the source of system clock to the the value of system clock frequency. \n\n
 * The value is obtained by reading \a SYSDIV bits of \a SYSCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetSystemClockDivider(),  XMC_SCU_CLOCK_SetSystemClockSource() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetSystemClockDivider(void)
{
  return (uint32_t)((SCU_CLK->SYSCLKCR & SCU_CLK_SYSCLKCR_SYSDIV_Msk) >> SCU_CLK_SYSCLKCR_SYSDIV_Pos);
}

/**
 *
 * @param ratio  Ratio of fCCU clock source to the value of fCCU.
 *              \b Range: 0 or 1.\n
 *                  0-> fCCU= fSYS \n
 *                  1-> fCCU= fSYS/2.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the divider for CCU clock source. \n\n
 * Capture compare unit(CCU) can take either fSYS or fSYS/2 as the source of clock.
 * The configuration is set to \a CCUDIV bit of \a CCUCLKCR register. The CCUDIV bit is 1 bit wide.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetCcuClockDivider() \n\n\n
 */
void XMC_SCU_CLOCK_SetCcuClockDivider(const uint32_t ratio);

/**
 * @return uint32_t  Ratio of fCCU clock source to the value of fCCU.
 *              \b Range: 0 or 1.\n
 *                  0-> fCCU= fSYS \n
 *                  1-> fCCU= fSYS/2.
 *
 * \par<b>Description</b><br>
 * Provides the ratio of CCU clock(fCCU) to system clock(fSYS).\n\n
 * The value is obtained by reading \a CCUDIV bit of \a CCUCLKCR register.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetCcuClockDivider() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetCcuClockDivider(void)
{
  return (uint32_t)((SCU_CLK->CCUCLKCR & SCU_CLK_CCUCLKCR_CCUDIV_Msk) >> SCU_CLK_CCUCLKCR_CCUDIV_Pos);
}

/**
 *
 * @param ratio  Ratio between system clock(fSYS) and CPU clock(fCPU).
 *          \b Range: 0 or 1.\n
 *            0-> fCPU= fSYS. \n
 *            1-> fCPU= fSYS/2.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the CPU clock by setting the divider value for the system clock. \n\n
 * The value is set to the \a CPUDIV bit of \a CPUCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetCpuClockDivider() \n\n\n
 */
void XMC_SCU_CLOCK_SetCpuClockDivider(const uint32_t ratio);

/**
 * @return uint32_t   Ratio between system clock(fSYS) and CPU clock(fCPU).
 *          \b Range: 0 or 1.\n
 *            0-> fCPU= fSYS. \n
 *            1-> fCPU= fSYS/2.
 *
 * \par<b>Description</b><br>
 * Provides the ratio between system clock(fSYS) and CPU clock(fCPU). \n\n
 * The value is obtained by reading \a CPUDIV bit of \a CPUCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetCpuClockDivider() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetCpuClockDivider(void)
{
  return (uint32_t)((SCU_CLK->CPUCLKCR & SCU_CLK_CPUCLKCR_CPUDIV_Msk) >> SCU_CLK_CPUCLKCR_CPUDIV_Pos);
}

/**
 *
 * @param ratio  Ratio of peripheral clock source to the value of peripheral clock.\n
 *          \b Range: 0 or 1.\n
 *                0-> fPERIPH= fCPU.\n
 *                1-> fPERIPH= fCPU/2.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the peripheral clock by setting the divider for CPU clock(fCPU).\n\n
 * The peripheral clock can be equal to either fCPU or fCPU/2. The value is configured to \a PBDIV bit of \a PBCLKCR register.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetPeripheralClockDivider() \n\n\n
 */
void XMC_SCU_CLOCK_SetPeripheralClockDivider(const uint32_t ratio);

/**
 * @return uint32_t  Ratio of peripheral clock source to the value of peripheral clock.\n
 *          \b Range: 0 or 1.\n
 *                0-> fPERIPH= fCPU.\n
 *                1-> fPERIPH= fCPU/2.
 *
 * \par<b>Description</b><br>
 * Provides the ratio of CPU clock(fCPU) to peripheral clock(fPERIPH).\n\n
 * The value is obtained by reading \a PBDIV bit of \a PBCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetPeripheralClockDivider() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetPeripheralClockDivider(void)
{
  return (uint32_t)((SCU_CLK->PBCLKCR & SCU_CLK_PBCLKCR_PBDIV_Msk) >> SCU_CLK_PBCLKCR_PBDIV_Pos);
}

/**
 *
 * @param ratio   Ratio of PLL output clock(fPLL) to USB clock(fUSB).
 *          \b Range: 1 to 8.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the USB clock(fUSB) by setting the USB clock divider. \n\n
 * The value is decremented by 1 before setting it to \a USBDIV bits of \a USBCLKCR register.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetUsbClockDivider(), XMC_SCU_CLOCK_SetUsbClockSource() \n\n\n
 */
void XMC_SCU_CLOCK_SetUsbClockDivider(const uint32_t ratio);

/**
 *
 * @return uint32_t  Ratio of PLL output clock(fPLL) to USB clock(fUSB).
 *          \b Range: 1 to 8.
 *
 * \par<b>Description</b><br>
 * Provides the ratio between PLL output frequency(fPLL) and USB clock(fUSB).\n\n
 * The value is obtained by reading \a USBDIV bit of \a USBCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetUsbClockDivider(), XMC_SCU_CLOCK_GetUsbClockSource() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetUsbClockDivider(void)
{
  return (uint32_t)((SCU_CLK->USBCLKCR & SCU_CLK_USBCLKCR_USBDIV_Msk) >> SCU_CLK_USBCLKCR_USBDIV_Pos);
}



#if defined(EBU)
/**
 *
 * @param ratio Ratio of PLL clock(fPLL) to EBU clock(fEBU).\n
 *          \b Range: 1 to 64.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the EBU clock(fEBU) by setting the divider value.\n\n
 * The clock divider is configured to the \a EBUDIV bits of \a EBUCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetEbuClockDivider() \n\n\n
 */
void XMC_SCU_CLOCK_SetEbuClockDivider(const uint32_t ratio);

/**
 *
 * @return uint32_t  Ratio of PLL clock(fPLL) to EBU clock(fEBU).\n
 *          \b Range: 1 to 64.
 *
 * \par<b>Description</b><br>
 * Provides the ratio between PLL clock(fPLL) and EBU clock(fEBU).\n\n
 * The value is obtained by reading \a EBUDIV bits of \a EBUCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetEbuClockDivider() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetEbuClockDivider(void)
{
  return (uint32_t)((SCU_CLK->EBUCLKCR & SCU_CLK_EBUCLKCR_EBUDIV_Msk) >> SCU_CLK_EBUCLKCR_EBUDIV_Pos);
}
#endif

/**
 *
 * @param ratio  Ratio between the source of WDT clock and the WDT clock.\n
 *          \b Range: 1 to 256.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the WDT clock by setting the clock divider for the WDT clock source.\n\n
 * The value is configured to \a WDTDIV bits of \a WDTCLKCR register. The value of divider
 * is decremented by 1 before configuring. Check the selected clock source for the WDT clock
 * before configuring the divider using the API XMC_SCU_CLOCK_SetWdtClockSource().
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetWdtClockSource(), XMC_SCU_CLOCK_GetWdtClockDivider() \n\n\n
 */
void XMC_SCU_CLOCK_SetWdtClockDivider(const uint32_t ratio);

/**
 *
 * @return uint32_t  Ratio between the source of WDT clock and the WDT clock.\n
 *          \b Range: 1 to 256.
 *
 * \par<b>Description</b><br>
 * Provides the ratio between the WDT parent clock and the WDT clock. \n\n
 * The value is obtained by reading \a WDTDIV bits of \a WDTCLKCR register.
 * Ensure that the WDT parent clock is considered before using the value of
 * the divider value.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetWdtClockSource(), XMC_SCU_CLOCK_SetWdtClockDivider() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetWdtClockDivider(void)
{
  return (uint32_t)((SCU_CLK->WDTCLKCR & SCU_CLK_WDTCLKCR_WDTDIV_Msk) >> SCU_CLK_WDTCLKCR_WDTDIV_Pos);
}

/**
 *
 * @param ratio   Ratio between the external output parent clock selected and the output clock.\n
 *          \b Range: 1 to 512.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the external output clock by setting the divider value for the parent clock. \n\n
 * The value will be configured to \a ECKDIV bits of \a EXTCLKCR register.
 * The divider value is decremented by 1 before storing it to the bit fields.
 * Ensure that the source of external output clock is configured appropriately using the API
 * XMC_SCU_CLOCK_SetExternalOutputClockSource().
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetExternalOutputClockSource(), XMC_SCU_CLOCK_GetExternalOutputClockDivider() \n\n\n
 */
void XMC_SCU_CLOCK_SetExternalOutputClockDivider(const uint32_t ratio);

/**
 *
 * @return uint32_t  Ratio between the external output parent clock selected and the output clock.\n
 *          \b Range: 1 to 512.
 *
 * \par<b>Description</b><br>
 * Provides the divider value applied on parent clock before the generation of external output clock. \n\n
 * The value is obtained by reading \a EXTDIV bit of \a EXTCLKCR register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetExternalOutputClockSource(), XMC_SCU_CLOCK_SetExternalOutputClockDivider() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetExternalOutputClockDivider(void)
{
  return (uint32_t)((SCU_CLK->EXTCLKCR & SCU_CLK_EXTCLKCR_ECKDIV_Msk) >> SCU_CLK_EXTCLKCR_ECKDIV_Pos);
}

#if defined(ECAT0)
void XMC_SCU_CLOCK_SetECATClockDivider(const uint32_t divider);

__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetECATClockDivider(void)
{
  return (uint32_t)((SCU_CLK->ECATCLKCR & SCU_CLK_ECATCLKCR_ECADIV_Msk) >> SCU_CLK_ECATCLKCR_ECADIV_Pos);
}
#endif

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables the high precision oscillator by configuring external crystal mode.\n\n
 * The API configures \a MODE bits of \a OSCHPCTRL register to 0, there by configuring the 
 * external clock input. 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_DisableHighPerformanceOscillator() \n\n\n
 */
void XMC_SCU_CLOCK_EnableHighPerformanceOscillator(void);

/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables the high precision oscillator by disabling the external oscillator.\n\n
 * The API configures \a MODE bits of \a OSCHPCTRL register to 1, there by disabling the 
 * external oscillator. 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_EnableHighPerformanceOscillator() \n\n\n
 */
void XMC_SCU_CLOCK_DisableHighPerformanceOscillator(void);

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables ultra low power oscillator(ULP). \n\n
 * It enables the hibernate domain, configures the ultra low power oscillator
 * uisng the \a MODE bits of the \a OSCULCTRL register. The \a Mode bits will be
 * reset to 0 to enable the low power oscillator. Mirror register update delays 
 * are handled internally.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_DisableLowPowerOscillator() \n\n\n
 */
void XMC_SCU_CLOCK_EnableLowPowerOscillator(void);

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables ultra low power oscillator.\n\n
 * It is disabled by setting the \a MODE bits of \a OSCULCTRL register to value 2.
 * By default on power up, the ultra low power osciallator is disabled.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_EnableLowPowerOscillator() \n\n\n
 */
void XMC_SCU_CLOCK_DisableLowPowerOscillator(void);

/**
 *
 * @return uint32_t   System frequency in Hertz.\n
 *            \b Range: clock frequency in Hertz. Range of the value depends on the source clock frequency
 *            and the configured values of dividers.
 *
 * \par<b>Description</b><br>
 * Provides the value of system PLL output clock frequency(fPLL).\n\n
 * The API uses \a N-DIV,  \a P-DIV,  \a K1-DIV,  \a K2-DIV bits information from \a PLLCON1 register and
 * VCOBYP bit information from \a PLLCON0 register. It calculates frequency of system pll clock using following formula:
 * If normal Mode : fPLL = (fOSC * N)/(P * K2).
 * If prescaler mode: fPLL = fOSC/ K1.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetSystemClockSource() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetSystemPllClockFrequency(void);

/**
 *
 * @return uint32_t  Source clock used for deriving system clock.\n
 *          \b Range: fOHP frequency if external high precision frequency is used. \n
 *                    fOFI fast internal clock frequency.
 *
 * \par<b>Description</b><br>
 * Provides the value of the input clock frequency for deriving the system clock.
 * The API retrieves frequency of system PLL input clock (fPLLin).
 * Based on \a PINSEL bits information from \a PLLCON2 register, the parent clock source is obtained.
 * This bit field specifies if fOHP or fOFI is used for deriving system clock.
 * System clock frequency is obtained by dividing the source clock frequency with different divider values.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetSystemPllClockFrequency() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetSystemPllClockSourceFrequency(void);

/**
 *
 * @return uint32_t   USB PLL output clock frequency.
 *
 * \par<b>Description</b><br>
 * Provides the frequency of USB PLL output clock (fUSBPLL).\n\n
 * It obtains the \a VCOBYP bits information from \a USBPLLCON register and decides if USB PLL mode is used.
 * If USB PLL mode is used, the USB clock frequency is obtained by dividing the source clock by USB PLL dividers.\n
 * The frequency is obtained using following formula:\n
 * If Normal Mode : fUSBPLL = (fOSC * N)/(P * 2).\n
 * If Prescaler mode: fPLL = fOSC.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetSystemPllClockSourceFrequency() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetUsbPllClockFrequency(void);

/**
 *
 * @return uint32_t   System clock frequency in Hertz.
 *
 * \par<b>Description</b><br>
 * Provides the frequency of system clock (fSYS).\n\n
 * The value obtained by dividing \a CPUDIV bits information of \a CPUCLKCR register with SystemCoreClock (fCPU) value.\n
 * Based on these values, fSYS clock frequency is derived using the following formula:\n
 * fSYS = fCPU << CPUDIV.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetUsbPllClockFrequency() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetSystemClockFrequency(void)
{
  return SystemCoreClock << ((SCU_CLK->CPUCLKCR & SCU_CLK_CPUCLKCR_CPUDIV_Msk) >> SCU_CLK_CPUCLKCR_CPUDIV_Pos);
}
 

/**
 *
 * @return uint32_t  CCU clock frequency in Hertz.
 *
 * \par<b>Description</b><br>
 * Provides the frequency of clock(fCPU) used for CCU4, CCU8, POSIF and HRPWM.\n\n
 * The value is obtained from \a CCUDIV bits of \a CCUCLKCR register and system clock (fSYS) frequency.
 * Based on these values, fCCU clock frequency is calculated using following formula:\n
 * fCCU = fSYS >> CCUDIV.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetCcuClockDivider(), XMC_SCU_CLOCK_GetSystemClockFrequency() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetCcuClockFrequency(void);

/**
 * @return uint32_t   USB clock frequency in Hertz.
 *
 * \par<b>Description</b><br>
 * Provides the frequency of USB and SDMMC clock(fUSB/fSDMMC).\n\n
 * The value is obtained from \a USBDIV bits of \a USBCLKCR register and USB clock source.
 * Based on these values fUSB/fSDMMC clock frequency is calculated using following formula:\n
 * if USB clock source = USBPLL: fUSB/fSDMMC = fUSBPLL/(USBDIV + 1).\n
 * if USB clock source = PLL:  fUSB/fSDMMC = fPLL/(USBDIV + 1).\n
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetUsbClockSource(), XMC_SCU_CLOCK_GetUsbClockDivider() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetUsbClockFrequency(void); 

/**
 * @return uint32_t   Ethernet clock frequency in Hertz.
 *
 * \par<b>Description</b><br>
 * Provides the frequency of Ethernet clock(fETH).\n\n
 * The value is derived from system clock frequency(fSYS). It is calculated using
 * the following formula:\n
 * fETH = fSYS >> 1;
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetSystemClockFrequency() \n\n\n
 */
__STATIC_INLINE uint32_t XMC_SCU_CLOCK_GetEthernetClockFrequency(void)
{
  return XMC_SCU_CLOCK_GetSystemClockFrequency() >> 1U;
}

#if defined(EBU)
/**
 * @return uint32_t   EBU clock frequency in Hertz.
 *
 * \par<b>Description</b><br>
 * Provides the frequency of EBU clock(fEBU).\n\n
 * The value is derived from system PLL clock frequency(fPLL) by applying the EBU divider. 
 * It is calculated using the following formula:\n
 * fETH = fPLL /(EBUDIV+1)
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetEbuClockDivider(), XMC_SCU_CLOCK_GetSystemPllClockFrequency() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetEbuClockFrequency(void); 
#endif
 
/**
 * @return uint32_t   WDT clock frequency in Hertz.
 *
 * \par<b>Description</b><br>
 * Provides the frequency of WDT clock(fWDT).\n\n
 * The value is derived using \a WDTDIV bits of \a WDTCLKCR register and WDT clock source.
 * Based on these values it is calculated using the following formula:\n
 * if WDT clock source = PLL: fWDT = fUSBPLL/(WDTDIV + 1).\n
 * if WDT clock source = OFI:  fWDT = fOFI/(WDTDIV + 1).\n
 * if WDT clock source = Standby:  fWDT = fSTDBY/(WDTDIV + 1).\n
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetWdtClockSource(), XMC_SCU_CLOCK_GetWdtClockDivider() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetWdtClockFrequency(void); 

/**
 *
 * @return uint32_t   External clock out frequency in Hertz.
 *
 * \par<b>Description</b><br>
 * Provides the frequency of external output clock(fEXT).\n\n
 * The value is derived using \a ECKDIV bits of \a EXCLKCR register and external clock out source.
 * Based on these values, it is calculated using the following formula:\n
 * if external clock out source = System clock: fEXT = fSYS.\n
 * if external clock out source = PLL:  fEXT = fPLL/(ECKDIV + 1).\n
 * if external clock out source = USBPLL:  fEXT = fUSBPLL/(ECKDIV + 1).\n
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetExternalOutputClockDivider(), XMC_SCU_CLOCK_GetExternalOutputClockSource() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetExternalOutputClockFrequency(void); 

#if defined(ECAT)
/**
 *
 */
uint32_t XMC_SCU_CLOCK_GetECATClockFrequency(void);
#endif

/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables main PLL for system clock. \n\n
 * System PLL is enabled by clearing the \a PLLPWD and \a VCOPWD bits of \a PLLCON0 register.
 * By default the system PLL is in power saving mode. The API enables the PLL and the voltage 
 * controlled oscillator associated with it.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_DisableSystemPll(), XMC_SCU_CLOCK_StartSystemPll() \n\n\n
 */
void XMC_SCU_CLOCK_EnableSystemPll(void);
 
 /**
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables main PLL for system clock. \n\n
 * System PLL is disabled by setting the \a PLLPWD and \a VCOPWD bits of \a PLLCON0 register.
 * By default the system PLL is in power saving mode. If the system PLL is explicitly enabled, 
 * the API disables the PLL and the voltage controlled oscillator(VCO) associated with it.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_EnableSystemPll(), XMC_SCU_CLOCK_StopSystemPll() \n\n\n
 */
 void XMC_SCU_CLOCK_DisableSystemPll(void);

/**
 * @param source PLL clock source. \n
 *          \b Range: Use type @ref XMC_SCU_CLOCK_SYSPLLCLKSRC_t to identify the clock source.\n
 *                    XMC_SCU_CLOCK_SYSPLLCLKSRC_OSCHP- External high precision oscillator input.
 *                    XMC_SCU_CLOCK_SYSPLLCLKSRC_OFI- Internal fast clock input.
 * @param mode Mode of PLL operation.\n
 *          \b Range: Use type @ref XMC_SCU_CLOCK_SYSPLL_MODE_t to identify the PLL mode. \n
 *                    XMC_SCU_CLOCK_SYSPLL_MODE_NORMAL- PLL frequency obtained from output of VCO(fVCO).\n
 *                    XMC_SCU_CLOCK_SYSPLL_MODE_PRESCALAR- VCO is bypassed. Frequency obtained from fOSC.\n
 * @param pdiv Input divider. Represents (PDIV+1) applied to external reference frequency. \n
 *          \b Range: 1 to 16.\n
 * @param ndiv Feedback divider. Represents(NDIV+1) \n
 *          \b Range: 1 to 128. \n
 * @param kdiv Output divider. Represents (K2DIV+1) in normal PLL mode or (K1DIV+1) in prescaler mode.\n
 *          \b Range: 1 to 128. \n
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables system PLL.\n\n
 * Based on the selected source of clock, either external frequency fOHP or internal clock fOFI will be used.
 * Based on the selected PLL mode, either voltage controlled oscillator(VCO) output(fVCO) or direct input frequency 
 * is used for the output dividers.\n
 * The API implements the following sequence:\n
 * - Store the value of TRAPDIS register into a temporary variable before disabling all traps.\n
 * - Clear all PLL related traps.\n
 * - If external fOHP is selected as source, wait for the external oscillator to stabilize.\n
 * - If PLL normal mode is selected, calculate the value of K2DIV and configure the PDIV, NDIV and K2DIV values.\n
 * - Ramp up the PLL frequency in steps. \n
 * - If prescaler mode is selected, configure the value of K1DIV.\n
 * - Wait for LOCK.\n
 * - Restore the trap configuration from stored temporary variable.\n
 * 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetSystemPllClockFrequency(), XMC_SCU_CLOCK_StopSystemPll() \n\n\n
 */
void XMC_SCU_CLOCK_StartSystemPll(XMC_SCU_CLOCK_SYSPLLCLKSRC_t source,
                                  XMC_SCU_CLOCK_SYSPLL_MODE_t mode,
                                  uint32_t pdiv,
                                  uint32_t ndiv,
                                  uint32_t kdiv);

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables the system PLL.
 * PLL is placed in power saving mode. It disables the PLL by setting the \a PLLPWD bit of \a PLLCON0 register.
 * If the PLL is put to power saving mode, it can no longer be used.
 * It is recommended to ensure following steps before using \a XMC_SCU_CLOCK_StopSystemPll API:\n
 * - Store the value of TRAPDIS register into a temporary variable before disabling all traps.\n
 * - Clear all PLL related traps.\n
 * - Ramp down frequency until fPLL reaches backup clock frequency (fOFI).\n
 * - Disable PLL.\n
 * - Restore the trap configuration from stored temporary variable.\n
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetSystemPllClockFrequency(), XMC_SCU_CLOCK_StartSystemPll() \n\n\n
 */
void XMC_SCU_CLOCK_StopSystemPll(void);

/**
 * @param kdiv PLL output divider K2DIV. \n
 *          \b Range: 1 to 128. Represents (K2DIV+1).
 * @return None
 *
 * \par<b>Description</b><br>
 * Ramps up or ramps down the PLL output frequency in provided step. \n\n
 * The PLL output frequency is divided by the \a kdiv value. This generates a step of ramp
 * for the PLL output frequency. The API waits for the clock to stabilize before the completing its
 * execution. 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_StartSystemPll() \n\n\n
 */
void XMC_SCU_CLOCK_StepSystemPllFrequency(uint32_t kdiv);

/**
 * @param None
 * @return Boolean value indicating if System PLL is locked
 *
 * \par<b>Description</b><br>
 * Return status of System PLL VCO. 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_StartSystemPll() \n\n\n
 */
bool XMC_SCU_CLOCK_IsSystemPllLocked(void);

/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables USB PLL for USB clock. \n\n
 * USB PLL is enabled by clearing the \a PLLPWD and \a VCOPWD bits of \a USBPLLCON register.
 * By default the USB PLL is in power saving mode. The API enables the PLL and the voltage 
 * controlled oscillator associated with it.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_DisableUsbPll(), XMC_SCU_CLOCK_StartUsbPll() \n\n\n
 */
 void XMC_SCU_CLOCK_EnableUsbPll(void);
 
 /**
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables USB PLL for USB clock. \n\n
 * USB PLL is disabled by setting the \a PLLPWD and \a VCOPWD bits of \a USBPLLCON register.
 * By default the USB PLL is in power saving mode. If the USB PLL is explicitly enabled, 
 * the API disables the PLL and the voltage controlled oscillator(VCO) associated with it.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_EnableUsbPll(), XMC_SCU_CLOCK_StopUsbPll() \n\n\n
 */
void XMC_SCU_CLOCK_DisableUsbPll(void);
 
/**
 *
 * @param pdiv Input divider value. Represents (PDIV+1) divider for the USB PLL.\n
 *        \b Range: 1 to 16.
 * @param ndiv VCO feedback divider for USB PLL. Represents (NDIV+1) feedback divider.\n
 *        \b Range: 1 to 128.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures USB PLL dividers and enables the PLL.\n\n
 * The API follows the required sequence for safely configuring the divider values of USB PLL.
 * Checks for PLL stabilization before enabling the same. After the configuring the dividers,
 * it waits till the VCO lock is achieved.
 * The sequence followed is as follows:\n
 * - Enable the USB PLL and configure VCO to be bypassed.\n
 * - Set up the HP oscillator clock input.\n
 * - Store the value of TRAPDIS register into a temporary variable before disabling all traps.\n
 * - Clear all USBPLL related traps.\n
 * - Disconnect the oscillator from USB PLL and configure the dividers PDIV and NDIV. \n
 * - Connect the oscillator to USB PLL and enable VCO.\n
 * - Wait for LOCK.\n
 * - Restore the trap configuration from stored temporary variable.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_StopUsbPll() \n\n\n
 */
void XMC_SCU_CLOCK_StartUsbPll(uint32_t pdiv, uint32_t ndiv);

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables USB PLL operation.\n\n
 * USB PLL is disabled by placing the USB PLL in power saving mode. The VCO and USB PLL are put in power saving mode
 * by setting the \a PLLPWD bit and \a VCOPWD bit of \a USBLLCON register to 1. VCO bypass mode is enabled by setting the
 * \a VCOBYP bit of \a USBLLCON register to 1.
 * It is recommended to ensure following steps before using \a XMC_SCU_CLOCK_StopUsbPll API:\n
 * - Store the value of TRAPDIS register into a temporary variable before disabling all traps.\n
 * - Clear all USBPLL related traps.\n
 * - Ramp down frequency.\n
 * - Disable PLL.\n
 * - Restore the trap configuration from stored temporary variable.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_StartUsbPll() \n\n\n
 */
void XMC_SCU_CLOCK_StopUsbPll(void);

/**
 * @param None
 * @return Boolean value indicating if USB PLL is locked
 *
 * \par<b>Description</b><br>
 * Return status of USB PLL VCO. 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_StartUsbPll() \n\n\n
 */
bool XMC_SCU_CLOCK_IsUsbPllLocked(void);

/**
 * @param mode Backup clock calibration mode.\n
 *          \b Range: Use type @ref XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_t to identify the calibration mode.\n
 *                  XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_FACTORY- Force trimming of internal oscillator with firmware configured values.\n
 *                  XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_AUTOMATIC- Calibrate internal oscillator automatically using standby clock(fSTDBY).\n
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the calibration of internal oscillator.\n\n
 * Based on the calibration mode selected, the internal oscillator calibration will be configured.
 * The calibration is useful while using fast internal clock(fOFI). When factory mode calibration is used,
 * the internal oscillator is trimmed using the firmware configured values. If automatic calibration is 
 * selected, the internal oscillator will be monitored using the backup clock. 
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetSystemClockSource() \n\n\n
 */
void XMC_SCU_CLOCK_SetBackupClockCalibrationMode(XMC_SCU_CLOCK_FOFI_CALIBRATION_MODE_t mode);


/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables the USB PHY and also OTG comparator if available.\n\n
 * Configures the \a USBPHYPDQ bit of \a PWRSET register to move the USB PHY from power down state.
 * If USB OTG is available in the device, the \a USBOTGEN bit of \a PWRSET register is set to 1. This
 * enables the USB on the go comparators.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_POWER_DisableUsb(), XMC_SCU_CLOCK_SetUsbClockSource() \n\n\n
 */
void XMC_SCU_POWER_EnableUsb(void);

/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables the USB PHY and also OTG comparator if available.\n\n
 * Configures the \a USBPHYPDQ bit of \a PWRSET register to move the USB PHY to power down state.
 * If USB OTG is available in the device, the \a USBOTGEN bit of \a PWRSET register is set to 0. This
 * disables the USB on the go comparators.
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_POWER_EnableUsb(), XMC_SCU_CLOCK_SetUsbClockSource() \n\n\n
 */
void XMC_SCU_POWER_DisableUsb(void);

/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Powers up the hibernation domain.\n\n
 * Hibernate domain should be enabled before using any peripheral from the hibernate domain.
 * It enables the power to the hibernate domain and moves it out of reset state.
 * Power to hibernate domain is enabled by setting the \a HIB bit of \a PWRSET register only if it is currently powered down.
 * The API will wait until HIB domain is enabled. If hibernate domain is in a state of reset, 
 * \a HIBRS bit of \a RSTCLR register is set to move it out of reset state.\n
 * It is recommended to use following steps to verify whether a hibernation domain is enabled/disabled:\n
 * - Call \a XMC_SCU_HIB_EnableHibernateDomain .
 * - Call \a XMC_SCU_HIB_IsHibernateDomainEnabled and check the return value. If return value is true, it indicates
 * that the hibernation domain is enabled otherwise disabled.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_DisableHibernateDomain(), XMC_SCU_HIB_IsHibernateDomainEnabled() \n\n\n
 */
void XMC_SCU_HIB_EnableHibernateDomain(void);

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Powers down the hibernation domain.\n\n
 * After disabling the hibernate domain, none of the peripherals from the hibernte domain can be used.
 * Hibernate domain is disabled by setting the \a HIB bit of \a PWRCLR register and \ HIBRS bit of \a RSTSET register.\n
 * It is recommended to use following steps to verify whether a hibernation domain is enabled/disabled:\n
 * - Call \a XMC_SCU_HIB_DisableHibernateDomain .
 * - Call \a XMC_SCU_HIB_IsHibernateDomainEnabled and check return value. If return value is true, it indicates
 * that the hibernation domain is enabled otherwise disabled.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_EnableHibernateDomain(), XMC_SCU_HIB_IsHibernateDomainEnabled() \n\n\n
 */
void XMC_SCU_HIB_DisableHibernateDomain(void);

/**
 *
 * @return bool  Power status of hibernate domain.\n
 *            \b Range: Boolean state value.\n
 *                \a true if hibernate domain is enabled.\n
 *                \a false if hibernate domain is disabled.\n
 *                      
 *
 * \par<b>Description</b><br>
 * Checks whether hibernation domain is enabled/disabled.\n\n
 * The API can be used before using the peripherals from hibernation domain to ensure that the 
 * power is supplied to the peripherals and also that the hibernation domain is not in reset state.
 * The status is obtained using the \a HIBEN bit of \a PWRSTAT register and \a HIBRS bit of \a RSTSET register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_EnableHibernateDomain(), XMC_SCU_HIB_DisableHibernateDomain() \n\n\n
 */
bool XMC_SCU_HIB_IsHibernateDomainEnabled(void);

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Enables slow internal oscillator(fOSI).\n\n
 * By default on device power up, the slow internall oscillator is enabled.
 * It can be disabled only if the external oscillator(fULP) is enabled and toggling.
 * It is recommended to enable fOSI to prevent deadlock if fULP fails.
 * fOSI is enabled by clearing the \a PWD bit of \a OSCSICTRL register. 
 * The API waits for the mirror register update of the configured register. 
 * The slow internal oscillator registers are in hibernate domain.
 * Ensure that the hibernate domain is enabled before changing the configuration.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_DisableInternalSlowClock(), XMC_SCU_CLOCK_SetBackupClockCalibrationMode(), 
 * XMC_SCU_HIB_EnableHibernateDomain() \n\n\n
 */
void XMC_SCU_HIB_EnableInternalSlowClock(void);

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Disables slow internal oscillator(fOSI).\n\n
 * By default on device power up, the slow internall oscillator is enabled.
 * It can be disabled only if the external oscillator(fULP) is enabled and toggling.
 * It is recommended to enable fOSI to prevent deadlock if fULP fails.
 * fOSI is disabled by setting the \a PWD bit of \a OSCSICTRL register. 
 * The API waits for the mirror register update of the configured register. 
 * The slow internal oscillator registers are in hibernate domain.
 * Ensure that the hibernate domain is enabled before changing the configuration.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_HIB_EnableInternalSlowClock(), XMC_SCU_CLOCK_SetBackupClockCalibrationMode(), 
 * XMC_SCU_HIB_EnableHibernateDomain() \n\n\n
 */
void XMC_SCU_HIB_DisableInternalSlowClock(void);

/**
 *
 */
__STATIC_INLINE void XMC_SCU_CLOCK_SetDeepSleepConfig(uint32_t config)
{
  SCU_CLK->DSLEEPCR = config;
}

/**
 *
 */
__STATIC_INLINE void XMC_SCU_CLOCK_SetSleepConfig(uint32_t config)
{
  SCU_CLK->SLEEPCR = config;
}


/**
 * @}
 */
 
/**
 * @}
 */
 
#ifdef __cplusplus
}
#endif
 
#endif /* UC_FAMILY == XMC4 */

#endif /* XMC4_SCU_H */

