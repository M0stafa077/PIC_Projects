/* 
 * File:   MCAL_INTI.h
 * Author: Mostafa Asaad
 *
 * Created on January 14, 2024, 9:19 PM
 */

#ifndef MCAL_INTI_H
#define	MCAL_INTI_H

/* Section : Includes */
#include "../MCAL_interrupt_cfg.h"

/* Section: Macro Declarations */
#define ADC_INTERRUPT_FEATURE               INTERRUPT_ENABLE

/* Section: Macro Functions Declarations */
#if ADC_INTERRUPT_FEATURE==INTERRUPT_ENABLE
/* Disable the Interrupts for the (A/D) */
#define INTI_ADC_INTERRRUPT_DISABLE()       (PIE1bits.ADIE = STD_LOW)     
/* Enable the Interrupts for the (A/D) */
#define INTI_ADC_INTERRRUPT_ENABLE()        (PIE1bits.ADIE = STD_HIGH)
/* Clear the Interrupt flag for the (A/D) */
#define INTI_ADC_CLR_FLAG()                 (PIR1bits.ADIF = STD_LOW)

/* Handle The Interrupt priority feature for the (A/D) module */
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_ENABLE
#define INTI_ADC_INTERRUPT_PRIORITY_HIGH()  (IPR1bits.ADIP = STD_HIGH)
#define INTI_ADC_INTERRUPT_PRIORITY_LOW()   (IPR1bits.ADIP = STD_LOW)
#endif

#endif

/* Section: Data Type Declarations */

/* Section: Function Declarations */

#endif	/* MCAL_INTI_H */

