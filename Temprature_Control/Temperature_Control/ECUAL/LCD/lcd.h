/* 
 * File:   lcd.h
 * Author: Mostafa_Asaad
 *
 * Created on December 14, 2023, 7:51 PM
 */

#ifndef LCD_H
#define	LCD_H

/* Section : Includes */
#include "../../MCAL/GPIO/gpio.h"
#include "lcd_cfg.h"

/* Section: Macro Declarations */
#define _LCD_CLEAR                      0x01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE                 0x06
#define _LCD_CURSOR_OFF_DISPLAY_ON      0x0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF     0x08
#define _LCD_CURSOR_ON_BLINK_ON         0x0F
#define _LCD_CURSOR_ON_BLINK_OFF        0x0E
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28
#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80
#define LCD_4BITS                       4
#define LCD_8BITS                       8
#define ROW1                            1
#define ROW2                            2
#define ROW3                            3
#define ROW4                            4

#define XTAL_FREQ   4000000

/* Section: Data Type Declarations */
typedef struct {
    pin_config_t lcd_rs_pin;                // RS pin
    pin_config_t lcd_en_pin;                // E pin
    pin_config_t lcd_data_pins[LCD_4BITS];  // Data pins     
    
} char_lcd_4bit_t;

typedef struct {
    pin_config_t lcd_rs_pin;                // RS pin
    pin_config_t lcd_en_pin;                // E pin
    pin_config_t lcd_data_pins[LCD_8BITS];  // Data pins  
    
} char_lcd_8bit_t;

/* Section: Function Declarations */
Std_ReturnType lcd_4bit_initialize(const char_lcd_4bit_t* _lcd);
Std_ReturnType lcd_4bit_send_command(const char_lcd_4bit_t* _lcd, uint8_t command);
Std_ReturnType lcd_4bit_send_char_data(const char_lcd_4bit_t* _lcd, uint8_t data);
Std_ReturnType lcd_4bit_send_char_data_pos(const char_lcd_4bit_t* _lcd, 
                                           uint8_t row, uint8_t column, uint8_t data);
Std_ReturnType lcd_4bit_send_string(const char_lcd_4bit_t* _lcd, uint8_t* str);
Std_ReturnType lcd_4bit_send_string_pos(const char_lcd_4bit_t* _lcd, 
                                        uint8_t row, uint8_t column, uint8_t* str);
Std_ReturnType lcd_4bit_send_custom_char(const char_lcd_4bit_t* _lcd,
                                         uint8_t row, uint8_t column, 
                                         const uint8_t _char[], uint8_t memory_pos);
Std_ReturnType lcd_4bit_set_cursor(const char_lcd_4bit_t* _lcd, uint8_t row, uint8_t column);

Std_ReturnType lcd_8bit_initialize(const char_lcd_4bit_t* _lcd);
Std_ReturnType lcd_8bit_send_command(const char_lcd_4bit_t* _lcd, uint8_t command);
Std_ReturnType lcd_8bit_send_char_data(const char_lcd_4bit_t* _lcd, uint8_t data);
Std_ReturnType lcd_8bit_send_char_data_pos(const char_lcd_4bit_t* _lcd, 
                                           uint8_t row, uint8_t column, uint8_t data);
Std_ReturnType lcd_8bit_send_string(const char_lcd_4bit_t* _lcd, uint8_t* str);
Std_ReturnType lcd_8bit_send_string_pos(const char_lcd_4bit_t* _lcd, 
                                        uint8_t row, uint8_t column, uint8_t* str);
Std_ReturnType lcd_8bit_send_custom_char(const char_lcd_4bit_t* _lcd,
                                         uint8_t row, uint8_t column, 
                                         const uint8_t _char[], uint8_t memory_pos);
Std_ReturnType lcd_8bit_set_cursor(const char_lcd_8bit_t* _lcd, uint8_t row, uint8_t column);

Std_ReturnType convert_uint8_to_string(uint8_t value, uint8_t* str);
Std_ReturnType convert_uint16_to_string(uint16_t value, uint8_t* str);
Std_ReturnType convert_uint32_to_string(uint32_t value, uint8_t* str);

#endif	/* LCD_H */

