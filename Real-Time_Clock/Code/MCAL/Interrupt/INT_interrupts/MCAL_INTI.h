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
#define TMR0_INTERRUPT_FEATURE              INTERRUPT_ENABLE
#define TMR1_INTERRUPT_FEATURE              INTERRUPT_ENABLE

/* -------- Section: Macro Functions Declarations -------- */

/* -------- Section: ADC INTERRUPT CONFIGURATIOs -------- */
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
/* -------- Section: End of ADC INTERRUPT CONFIGURATIOs -------- */

/* ===========================================================================*/

/* -------- Section: Timer0 INTERRUPT CONFIGURATIOs -------- */
#if TMR0_INTERRUPT_FEATURE==INTERRUPT_ENABLE

/* Enable the Interrupts for the Timer0 */
#define INTI_TMR0_INTERRRUPT_ENABLE()        (INTCONbits.T0IE = STD_HIGH)
/* Disable the Interrupts for the Timer0 */
#define INTI_TMR0_INTERRRUPT_DISABLE()      (INTCONbits.T0IE = STD_LOW)     
/* Clear the Interrupt flag for the Timer0 */
#define INTI_TMR0_CLR_FLAG()                 (INTCONbits.T0IF = STD_LOW)

/* Handle The Interrupt priority feature for the Timer0 module */
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_ENABLE
#define INTI_TMR0_INTERRUPT_PRIORITY_HIGH()  (INTCON2bits.TMR0IP = PRIORITY_HIGH)
#define INTI_TMR0_INTERRUPT_PRIORITY_LOW()   (INTCON2bits.TMR0IP = PRIORITY_LOW)
#endif

#endif
/* -------- Section: End of Timer0 INTERRUPT CONFIGURATIOs -------- */

/* ===========================================================================*/

/* -------- Section: Timer1 INTERRUPT CONFIGURATIOs -------- */

#if TMR1_INTERRUPT_FEATURE==INTERRUPT_ENABLE

/* Enable the Interrupts for the Timer1 */
#define INTI_TMR1_INTERRRUPT_ENABLE()       (PIE1bits.TMR1IE = STD_HIGH)
/* Disable the Interrupts for the Timer1 */
#define INTI_TMR1_INTERRRUPT_DISABLE()      (PIE1bits.TMR1IE = STD_LOW)     
/* Clear the Interrupt flag for the Timer1 */
#define INTI_TMR1_CLR_FLAG()                (PIR1bits.TMR1IF = STD_LOW)

/* Handle The Interrupt priority feature for the Timer0 module */
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_ENABLE
#define INTI_TMR1_INTERRUPT_PRIORITY_HIGH()  (IPR1bits.TMR1IP = PRIORITY_HIGH)
#define INTI_TMR1_INTERRUPT_PRIORITY_LOW()   (IPR1bits.TMR1IP = PRIORITY_LOW)
#endif

#endif

/* -------- Section: End of Timer1 INTERRUPT CONFIGURATIOs -------- */

/* Section: Data Type Declarations */

/* Section: Function Declarations */

#endif	/* MCAL_INTI_H */

