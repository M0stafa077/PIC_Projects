/* 
 * File:   application.c
 * Author: Mostafa_Assad
 *
 * Created on November 3, 2023, 2:28 PM
 */

#include "application.h"


#define SLAVE_1_ADDRESS         0x15
#define SLAVE_2_ADDRESS         0x30

uint8_t ack = 0;

i2c_t i2c_master = {
    .i2c_default_interrupt_handler = NULL,
    .i2c_interrupt_priority = PRIORITY_HIGH,
    .i2c_master_clock_freq = 100000,
    .i2c_receive_overflow_handler = NULL,
    .i2c_write_collision_handler = NULL,
    .i2c_cfg.i2c_mode = I2C_MASTER_MODE,
    .i2c_cfg.i2c_mode_config = I2C_MASTER_MODE_SSPADD_CLOCK
};

void main() 
{
    Std_ReturnType ret = E_OK;
    ret = I2C_Init(&i2c_master);
    
    
    while(1)
    {   
        ret = I2C_Send_Byte(&i2c_master, 'a', SLAVE_1_ADDRESS);
        __delay_ms(50);
        ret = I2C_Send_Byte(&i2c_master, 'c', SLAVE_2_ADDRESS);
        __delay_ms(3000);
        
        ret = I2C_Send_Byte(&i2c_master, 'b', SLAVE_1_ADDRESS);
        __delay_ms(50);
        ret = I2C_Send_Byte(&i2c_master, 'd', SLAVE_2_ADDRESS);
        __delay_ms(3000);               
    }
}

Std_ReturnType application_initialize(void)
{
    Std_ReturnType ret = E_OK;
    ret = ecu_layer_intialize();
    return ret;
}
