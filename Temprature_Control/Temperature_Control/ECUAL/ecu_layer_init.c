/* 
 * File:   ecu_layer_init.c
 * Author: Mostafa_Asaad
 *
 * Created on December 8, 2023, 11:47 PM
 */

/* --------------- Section : Includes --------------- */
#include "ecu_layer_init.h"

/* --------------- Section : Some Objects --------------- */
char_lcd_4bit_t lcd_4bits = {  
    .lcd_rs_pin.port = PORTC_INDEX,
    .lcd_rs_pin.pin = PIN0_INDEX,
    .lcd_rs_pin.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_rs_pin.logic = GPIO_LOW,
    
    .lcd_en_pin.port = PORTC_INDEX,
    .lcd_en_pin.pin = PIN1_INDEX,
    .lcd_en_pin.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_en_pin.logic = GPIO_LOW,
    
    .lcd_data_pins[0].port = PORTC_INDEX,
    .lcd_data_pins[0].pin = PIN2_INDEX,
    .lcd_data_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[0].logic = GPIO_LOW,
    
    .lcd_data_pins[1].port = PORTC_INDEX,
    .lcd_data_pins[1].pin = PIN3_INDEX,
    .lcd_data_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[1].logic = GPIO_LOW,
    
    .lcd_data_pins[2].port = PORTC_INDEX,
    .lcd_data_pins[2].pin = PIN4_INDEX,
    .lcd_data_pins[2].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[2].logic = GPIO_LOW,
    
    .lcd_data_pins[3].port = PORTC_INDEX,
    .lcd_data_pins[3].pin = PIN5_INDEX,
    .lcd_data_pins[3].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[3].logic = GPIO_LOW 
};

dc_motor_t motor_1 = 
{
    .motor_pin[0].port = PORTD_INDEX,
    .motor_pin[0].pin = PIN0_INDEX,
    .motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .motor_pin[0].logic = GPIO_LOW,
    
    .motor_pin[1].port = PORTD_INDEX,
    .motor_pin[1].pin = PIN1_INDEX,
    .motor_pin[1].direction = GPIO_DIRECTION_OUTPUT,
    .motor_pin[1].logic = GPIO_LOW,
};

dc_motor_t motor_2 = 
{
    .motor_pin[0].port = PORTD_INDEX,
    .motor_pin[0].pin = PIN2_INDEX,
    .motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .motor_pin[0].logic = GPIO_LOW,
    
    .motor_pin[1].port = PORTD_INDEX,
    .motor_pin[1].pin = PIN3_INDEX,
    .motor_pin[1].direction = GPIO_DIRECTION_OUTPUT,
    .motor_pin[1].logic = GPIO_LOW,
};

Buzzer_t buzzer =
{
    .buzzer_pin.port = PORTA_INDEX,
    .buzzer_pin.pin = PIN3_INDEX,
    .buzzer_pin.direction = GPIO_DIRECTION_OUTPUT,
    .buzzer_pin.logic = STD_LOW
};

led_t red_led = { .port = PORTA_INDEX, .pin = PIN1_INDEX, .led_status = LED_OFF };

led_t green_led = { .port = PORTA_INDEX, .pin = PIN2_INDEX, .led_status = LED_OFF };
/*---------------  Section: Function Definitions --------------- */
Std_ReturnType ecu_layer_intialize(void){
    Std_ReturnType ret = E_OK;
    ret = lcd_4bit_initialize(&lcd_4bits);
    ret = dc_motor_init(&motor_1);
    ret = dc_motor_init(&motor_2);
    ret = led_init(&red_led);
    ret = led_init(&green_led);
    ret = buzzer_init(&buzzer);
    return ret;
}
