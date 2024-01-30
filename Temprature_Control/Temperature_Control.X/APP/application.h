/* 
 * File:   application.h
 * Author: Mostafa _Asaad
 *
 * Created on Jan 30, 2024, 3:34 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
/* --------------- Section : Includes --------------- */
#include "../ECUAL/ecu_layer_init.h"
#include "../MCAL/mcal_layer_init.h"
/* --------------- Section : Extern Devices from ECU Layer --------------- */
extern char_lcd_4bit_t lcd_4bits;
extern led_t red_led;
extern led_t green_led;
extern dc_motor_t motor_1;
extern dc_motor_t motor_2;
extern Buzzer_t buzzer;
/* --------------- Section : Extern Modules from MCAL Layer --------------- */
extern adc_cfg_t adc;
/*---------------  Section: Function Declarations --------------- */
Std_ReturnType application_initialize(void);
Std_ReturnType intro_msg();
void adc_interrupt_handler(void);
Std_ReturnType danger_msg();

#endif	/* APPLICATION_H */

