/* 
 * File:   MCAL_Interrupt_manager.h
 * Author: Mostafa Asaad
 *
 * Created on January 15, 2024, 11:34 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* Section : Includes */
#include "MCAL_interrupt_cfg.h"
#include "INT_interrupts/MCAL_INTI.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8_t mode);
void RB5_ISR(uint8_t mode);
void RB6_ISR(uint8_t mode);
void RB7_ISR(uint8_t mode);

#if ADC_INTERRUPT_FEATURE==INTERRUPT_ENABLE
void INTI_ADC_ISR(void);
#endif

#endif	/* MCAL_INTERRUPT_MANAGER_H */

