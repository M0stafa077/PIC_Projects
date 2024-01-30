/* 
 * File:   mcal_layer_init.h
 * Author: Mostafa Asaad
 *
 * Created on January 30, 2024, 2:56 PM
 */

#ifndef MCAL_LAYER_INIT_H
#define	MCAL_LAYER_INIT_H

/* --------------- Section : Includes --------------- */
#include "../MCAL/ADC/hal_adc.h"

/* --------------- Section: Macro Declarations --------------- */

/*---------------  Section: Function Declarations --------------- */
Std_ReturnType mcal_layer_intialize(void);
void adc_interrupt_handler(void);
void app_sleep(void);
#endif	/* MCAL_LAYER_INIT_H */

