/* 
 * File:   ecu_layer_init.c
 * Author: Mostafa_Asaad
 *
 * Created on December 8, 2023, 11:47 PM
 */

/* --------------- Section : Includes --------------- */
#include "ecu_layer_init.h"

/* --------------- Section : Some Objects --------------- */
seven_segment_t segment_seconds = 
{
    .segment_type = SEGMENT_COMMON_ANODE,
    
    .segment_pins[0].port = PORTA_INDEX,
    .segment_pins[0].pin = PIN0_INDEX,
    .segment_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[0].logic = GPIO_LOW,
    
    .segment_pins[1].port = PORTA_INDEX,
    .segment_pins[1].pin = PIN1_INDEX,
    .segment_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[1].logic = GPIO_LOW,
    
    .segment_pins[2].port = PORTA_INDEX,
    .segment_pins[2].pin = PIN2_INDEX,
    .segment_pins[2].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[2].logic = GPIO_LOW,
    
    .segment_pins[3].port = PORTA_INDEX,
    .segment_pins[3].pin = PIN3_INDEX,
    .segment_pins[3].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[3].logic = GPIO_LOW
};
seven_segment_t segment_minutes = 
{
    .segment_type = SEGMENT_COMMON_ANODE,
    
    .segment_pins[0].port = PORTD_INDEX,
    .segment_pins[0].pin = PIN0_INDEX,
    .segment_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[0].logic = GPIO_LOW,
    
    .segment_pins[1].port = PORTD_INDEX,
    .segment_pins[1].pin = PIN1_INDEX,
    .segment_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[1].logic = GPIO_LOW,
    
    .segment_pins[2].port = PORTD_INDEX,
    .segment_pins[2].pin = PIN2_INDEX,
    .segment_pins[2].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[2].logic = GPIO_LOW,
    
    .segment_pins[3].port = PORTD_INDEX,
    .segment_pins[3].pin = PIN3_INDEX,
    .segment_pins[3].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[3].logic = GPIO_LOW
};

seven_segment_t segment_hours = 
{
    .segment_type = SEGMENT_COMMON_ANODE,
    
    .segment_pins[0].port = PORTB_INDEX,
    .segment_pins[0].pin = PIN0_INDEX,
    .segment_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[0].logic = GPIO_LOW,
    
    .segment_pins[1].port = PORTB_INDEX,
    .segment_pins[1].pin = PIN1_INDEX,
    .segment_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[1].logic = GPIO_LOW,
    
    .segment_pins[2].port = PORTB_INDEX,
    .segment_pins[2].pin = PIN2_INDEX,
    .segment_pins[2].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[2].logic = GPIO_LOW,
    
    .segment_pins[3].port = PORTB_INDEX,
    .segment_pins[3].pin = PIN3_INDEX,
    .segment_pins[3].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[3].logic = GPIO_LOW
};

pin_config_t SEG_SEC_EN1 = 
{
    .port = PORTC_INDEX,
    .pin = PIN0_INDEX,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = STD_LOW
};
pin_config_t SEG_SEC_EN2 = 
{
    .port = PORTC_INDEX,
    .pin = PIN1_INDEX,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = STD_LOW
};

pin_config_t SEG_MIN_EN1 = 
{
    .port = PORTC_INDEX,
    .pin = PIN2_INDEX,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = STD_LOW
};
pin_config_t SEG_MIN_EN2 = 
{
    .port = PORTC_INDEX,
    .pin = PIN3_INDEX,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = STD_LOW
};

pin_config_t SEG_HRS_EN1 = 
{
    .port = PORTC_INDEX,
    .pin = PIN4_INDEX,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = STD_LOW
};
pin_config_t SEG_HRS_EN2 = 
{
    .port = PORTC_INDEX,
    .pin = PIN5_INDEX,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = STD_LOW
};
/* ---------- Section : Functions Definitions ---------- */
Std_ReturnType ecu_layer_intialize(void){
    Std_ReturnType ret = E_OK;
    ret = seven_segment_initialize(&segment_seconds);
    ret = seven_segment_initialize(&segment_minutes);
    ret = seven_segment_initialize(&segment_hours);
    ret = gpio_pin_initialize(&SEG_SEC_EN1);
    ret = gpio_pin_initialize(&SEG_SEC_EN2);
    ret = gpio_pin_initialize(&SEG_MIN_EN1);
    ret = gpio_pin_initialize(&SEG_MIN_EN2);
    ret = gpio_pin_initialize(&SEG_HRS_EN1);
    ret = gpio_pin_initialize(&SEG_HRS_EN2);
    return ret;
}
