/* 
 * File:   mcal_layer_init.c
 * Author: Mostafa Asaad
 *
 * Created on January 30, 2024, 2:56 PM
 */
/* --------------- Section : Includes --------------- */
#include "mcal_layer_init.h"
#include "Interrupt/EXT_interrupts/MCAL_EXTI.h"
/*---------------  Section: Global Variables --------------- */
adc_cfg_t adc =
{
    .ADC_InterruptHandler = adc_interrupt_handler,
    .priority = PRIORITY_HIGH,
    .adc_channel = ADC_CHANNEL_AN0,
    .result_format = ADC_RESULT_RIGHT,
    .acquisition_time = ADC_12_ATD,
    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};

/*---------------  Section: Function Definitions --------------- */
Std_ReturnType mcal_layer_intialize(void)
{
    Std_ReturnType ret = E_OK;
    ret = ADC_init(&adc);
    return ret;
}