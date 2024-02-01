/* 
 * File:   application.c
 * Author: Mostafa_Assad
 *
 * Created on Feb 1, 2024, 09:23 PM
 */
/* --------------- Section : Includes --------------- */
#include "application.h"
/* --------------- Section : Global Variables --------------- */
real_time_clock_t clock; volatile uint8_t delay_flag = 0;

Timer0_t timer = 
{
    .TMR0_INTERRUPT_HANDLER = ISR,
    .priority = PRIORITY_HIGH,
    .prescaler_enable = TMR0_PRESCALER_ENABLE,
    .prescaler_value = TMR0_PRESCALAR_RATIO_16,
    .timer0_mode = TMR0_TIMER_MODE,
    .timer0_preloaded_value = 3036,
    .tmr0_register_size = TMR0_16_BIT_MODE
};

Timer1_t dely_timer = 
{
    .TMR1_INTERRUPT_HANDLER = dely_timer_isr,
    .priority = PRIORITY_HIGH,
    .prescaler_value = TMR1_PRESCALAR_RATIO_1,
    .timer1_mode = TMR1_TIMER_MODE,
    .timer1_preloaded_value = 60536,
    .timer1_rw_mode = TMR1_RW_REG_MODE_16BIT
};

int main(void) {
    Std_ReturnType ret = E_OK;
    
    /* Initialize The Application */
    ret = application_initialize();     
     
    while(1)
    {           
        /* Display the hours */
        ret = seven_segment_write_num(&segment_hours, clock.hours % 10);
        ret = gpio_pin_write_logic(&SEG_HRS_EN2, STD_HIGH);
        delay_5ms();       
        ret = gpio_pin_write_logic(&SEG_HRS_EN2, STD_LOW);
        
        ret = seven_segment_write_num(&segment_hours, clock.hours / 10);
        ret = gpio_pin_write_logic(&SEG_HRS_EN1, STD_HIGH);
        delay_5ms();        
        ret = gpio_pin_write_logic(&SEG_HRS_EN1, STD_LOW);

        /* Display the minutes */
        ret = seven_segment_write_num(&segment_minutes, clock.min % 10);
        ret = gpio_pin_write_logic(&SEG_MIN_EN2, STD_HIGH);
        delay_5ms();
        ret = gpio_pin_write_logic(&SEG_MIN_EN2, STD_LOW);
        
        ret = seven_segment_write_num(&segment_minutes, clock.min / 10);
        ret = gpio_pin_write_logic(&SEG_MIN_EN1, STD_HIGH);
        delay_5ms();
        ret = gpio_pin_write_logic(&SEG_MIN_EN1, STD_LOW);

        /* Display the seconds */
        ret = seven_segment_write_num(&segment_seconds, clock.sec % 10);
        ret = gpio_pin_write_logic(&SEG_SEC_EN2, STD_HIGH);
        delay_5ms();
        ret = gpio_pin_write_logic(&SEG_SEC_EN2, STD_LOW);
        
        ret = seven_segment_write_num(&segment_seconds, clock.sec / 10);
        ret = gpio_pin_write_logic(&SEG_SEC_EN1, STD_HIGH);
        delay_5ms();
        ret = gpio_pin_write_logic(&SEG_SEC_EN1, STD_LOW); 
    }
}

Std_ReturnType application_initialize(void){
    Std_ReturnType ret = E_OK;
    ret = ecu_layer_intialize();
    ret = timer0_init(&timer);
    ret = timer1_init(&dely_timer);
    ret = real_time_clock_init(&clock);
    return ret;
}

Std_ReturnType real_time_clock_init(real_time_clock_t *clock)
{
    Std_ReturnType ret = E_OK;
    clock -> sec = 0;
    clock -> min = 30;
    clock -> hours = 9;
    return ret; 
}

void delay_5ms(void)
{
    timer1_write_value(&dely_timer, 60536);
    delay_flag = 0;
    while (!delay_flag);
    delay_flag = 0;
}

void ISR (void)
{
    ++(clock.sec);
    if (60 <= clock.sec)
    {
        clock.sec = 0;
        ++(clock.min);
        if (60 <= clock.min)
        {
            clock.min = 0;
            ++(clock.hours);
            if (24 <= clock.hours)
            {
                clock.hours = 0;
            }
            else
            { /* Nothing */ }
        }
        { /* Nothing */ }
    }
    { /* Nothing */ }
}

void dely_timer_isr (void)
{
    delay_flag = 1;
}
