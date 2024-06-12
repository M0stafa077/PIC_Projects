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

volatile uint8_t i2c_slave_received = 0;

void i2c_slave_isr(void)
{
    if((SSPSTATbits.R_nW == 0) && (SSPSTATbits.D_nA == 0))
    {
        i2c_slave_received = SSPBUF;
        while(!SSPSTATbits.BF);
        i2c_slave_received = SSPBUF;
    }
}

i2c_t i2c_slave_1 = {
    .i2c_default_interrupt_handler = i2c_slave_isr,
    .i2c_interrupt_priority = PRIORITY_HIGH,
    .i2c_receive_overflow_handler = NULL,
    .i2c_write_collision_handler = NULL,
    .i2c_cfg.i2c_mode = I2C_SLAVE_MODE,
    .i2c_cfg.i2c_mode_config = I2C_SLAVE_MODE_7BIT_ADDRESS_NO_INTERRUPT,
    .i2c_cfg.i2c_SMBus_stat = I2C_SMBUS_DISABLE,
    .i2c_cfg.i2c_general_call_stat = I2C_GENERAL_CALL_DISABLE,
    .i2c_cfg.i2c_slave_address = SLAVE_1_ADDRESS * 2,
    .i2c_cfg.i2c_slew_rate_stat = I2C_SLEW_RATE_DISABLE
};

void main() 
{
    Std_ReturnType ret = E_OK;
    ret = I2C_Init(&i2c_slave_1);
   
    while(1)
    {   
        switch(i2c_slave_received)
        {
            case 'a':
                ret = led_turn_ON(&led_0);
                break;
            case 'b':
                ret = led_turn_OFF(&led_0);
                break;
            default: /* NOTHING */
                break;
        }
    }
}

Std_ReturnType application_initialize(void)
{
    Std_ReturnType ret = E_OK;
    ret = ecu_layer_intialize();
    return ret;
}
