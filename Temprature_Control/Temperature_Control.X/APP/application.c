/* 
 * File:   application.c
 * Author: Mostafa_Assad
 *
 * Created on Jan 30, 2024, 3:34 PM
 */
/* --------------- Section : Includes --------------- */
#include "application.h"

/*---------------  Section: Global Variables --------------- */
volatile uint16_t adc_res;
volatile uint8_t adc_res_txt[7];
uint16_t temp = 0;

/*---------------  Section: Function Declarations --------------- */
int main(void) {
    Std_ReturnType ret = E_OK;
    /* Initialize The Application */
    ret = application_initialize(); 
    
    ret = intro_msg();
    
    ret = lcd_4bit_send_string_pos(&lcd_4bits, 1, 2, "Temp value: ");
    while(1)
    {
        ret = ADC_start_conversion_interrupt(&adc, ADC_CHANNEL_AN0); 
        temp = adc_res * 4.88f;
        temp /= 10;
        ret = convert_uint16_to_string(temp, adc_res_txt);
        __delay_ms(150);
        ret = lcd_4bit_send_string_pos(&lcd_4bits, 1, 13, adc_res_txt);
        
        if (temp < 30)
        {
            ret = led_turn_ON(&green_led);
            ret = lcd_4bit_send_string_pos(&lcd_4bits, 2, 3, "   Normal  ");
            ret = dc_motor_stop(&motor_1);
            ret = dc_motor_stop(&motor_2);
        }
        else if ((temp > 30) && (temp < 35))
        {
            ret = led_turn_ON(&green_led);
            ret = lcd_4bit_send_string_pos(&lcd_4bits, 2, 3, "Overheating");
            ret = dc_motor_move_CW(&motor_1);
            ret = dc_motor_stop(&motor_2);
        }
        else if (temp > 35)
        {
            ret = led_turn_OFF(&green_led);
            ret = danger_msg();
            ret = dc_motor_move_CW(&motor_1);
            ret = dc_motor_move_CW(&motor_2);
            
        }
        else
        { /* Nothing */}
        
    }
}

Std_ReturnType application_initialize(void){
    Std_ReturnType ret = E_OK;
    ret = ecu_layer_intialize();
    ret = mcal_layer_intialize();
    return ret;
}

Std_ReturnType intro_msg()
{
    Std_ReturnType ret = E_OK;
    
    uint8_t temp_txt[] = "Temperature";   
    ret = lcd_4bit_set_cursor(&lcd_4bits, 1, 4);
    for (uint8_t l_counter = 0; l_counter < strlen(temp_txt); ++l_counter)
    {
        ret = lcd_4bit_send_char_data(&lcd_4bits, temp_txt[l_counter]);
        __delay_ms(50);
    }
    
    uint8_t control_txt[] = "Control";
    ret = lcd_4bit_set_cursor(&lcd_4bits, 2, 6);
    for (uint8_t l_counter = 0; l_counter < strlen(control_txt); ++l_counter)
    {
        ret = lcd_4bit_send_char_data(&lcd_4bits, control_txt[l_counter]);
        __delay_ms(50);
    }
    
    __delay_ms(1500);
    ret = lcd_4bit_send_command(&lcd_4bits, _LCD_CLEAR);
    
    return ret;
}

Std_ReturnType danger_msg()
{
    Std_ReturnType ret = E_OK;
    ret = lcd_4bit_send_string_pos(&lcd_4bits, 2, 3, "  Danger!! ");
    ret = led_TOGGLE(&red_led);
    ret = buzzer_turn_on(&buzzer);
    __delay_ms(200);
    ret = lcd_4bit_send_string_pos(&lcd_4bits, 2, 3, "           ");
    ret = led_TOGGLE(&red_led);
    ret = buzzer_turn_off(&buzzer);
    __delay_ms(200);
    return ret;
}

void adc_interrupt_handler(void)
{
    ADC_get_conversion_result(&adc, &adc_res);
}