/* 
 * File:   MCAL_interrupt_manager.c
 * Author: Mostafa Asaad
 *
 * Created on January 14, 2024, 9:16 PM
 */

/* Section : Includes */
#include "MCAL_interrupt_manager.h"

#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_ENABLE
void __interrupt() InterruptManagerHigh(void)
{
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCURED == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    else 
        { /* Nothing */ }
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCURED == INTCON3bits.INT1IF))
    {
        INT1_ISR();
    }
    else
        { /* Nothing */ }
    
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) 
                                             && (PORTBbits.RB4 == STD_HIGH))
    {
        RB4_ISR(STD_HIGH);
    }
    else
        { /* Nothing */ }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) 
                                             && (PORTBbits.RB4 == STD_LOW) )
    {
        RB4_ISR(STD_LOW);
    }
    else
        { /* Nothing */ }
    if ( (INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCURED == PIR1bits.ADIF) )
    {
        INTI_ADC_ISR();
    }
    else
        { /* Nothing */ }
    if ( (INTERRUPT_ENABLE == INTCONbits.T0IE) && (INTERRUPT_OCCURED == INTCONbits.T0IF) )
    {
        INTI_TMR0_ISR();
    }
    else
        { /* Nothing */ }
    if ( (INTERRUPT_ENABLE == PIE1bits.TMR1IE) && (INTERRUPT_OCCURED == PIR1bits.TMR1IF) )
    {
        INTI_TMR1_ISR();
    }
    else
        { /* Nothing */ }
}

void __interrupt(low_priority) InterruptManagerLow(void)
{
    
}
#else
void __interrupt() InterruptManager(void)
{
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCURED == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    else 
        { /* Nothing */ }
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCURED == INTCON3bits.INT1IF))
    {
        INT1_ISR();
    }
    else
        { /* Nothing */ }
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCURED == INTCON3bits.INT2IF))
    {
        INT2_ISR();
    }
    else
        { /* Nothing */ }
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF))
    {
        
    }
    else
        { /* Nothing */ }
    
    if ( (INTERRUPT_ENABLE == INTCONbits.T0IE) && (INTERRUPT_OCCURED == INTCONbits.T0IF) )
    {
        INTI_TMR0_ISR();
    }
    else
        { /* Nothing */ }
}
#endif
