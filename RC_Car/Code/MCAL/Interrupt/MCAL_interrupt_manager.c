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
    if ((INTERRUPT_ENABLE == PIE1bits.TXIE) && (INTERRUPT_OCCURED == PIR1bits.TXIF))
    {
        USART_TX_ISR();
    }
    else
        { /* Nothing */ }
    
    if ((INTERRUPT_ENABLE == PIE1bits.RCIE) && (INTERRUPT_OCCURED == PIR1bits.RCIF))
    {
        USART_RX_ISR();
    }
    else
        { /* Nothing */ }
}

void __interrupt(low_priority) InterruptManagerLow(void)
{
    
}
#else
void __interrupt() InterruptManager(void)      /* IVT */  /* Address = 0x08 */    
{
    if ((INTERRUPT_ENABLE == PIE1bits.TXIE) && (INTERRUPT_OCCURED == PIR1bits.TXIF))
    {
        USART_TX_ISR();
    }
    else
        { /* Nothing */ }
    
    if ((INTERRUPT_ENABLE == PIE1bits.RCIE) && (INTERRUPT_OCCURED == PIR1bits.RCIF))
    {
        USART_RX_ISR();
    }
    else
        { /* Nothing */ }
}
#endif
