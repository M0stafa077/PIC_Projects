/* 
 * File:   app.c
 * Author: Mostafa Asaad
 *
 * Created on February 20, 2024, 8:50 PM
 */
/* --------------- Section : Includes --------------- */
#include "app.h"
/* --------------- Section: Global Variables --------------- */
uint8_t ble_value = ZERO_INIT;
/* --------------- Section: Functions Definitions --------------- */
int main(void)
{
    Std_ReturnType ret = E_OK;
    /* Initialize the Application */
    ret = app_init();
            
    while(1)
    {
        ret = Bluetooth_Get_Byte(&ble_value);
        
        switch(ble_value)
        {
            /* Move the Car Forward */
            case 'f' : ret = Car_Move_Forward();
                    break;
            case 'F' : ret = Car_Move_Forward();
                    break;
            
            /* Move the Car Backward */
            case 'b' : ret = Car_Move_Backward();
                    break;
            case 'B' : ret = Car_Move_Backward();
                    break;
            
            /* Move the Car Right */
            case 'r' : ret = Car_Move_Right();
                    break;
            case 'R' : ret = Car_Move_Right();
                    break;
            
            /* Move the Car Left */
            case 'l' : ret = Car_Move_Left();
                    break;
            case 'L' : ret = Car_Move_Left();
                    break;
            
            /* Stop the Car */
            case 's' : ret = Car_Stop();
                    break;
            case 'S' : ret = Car_Stop();
                    break;
            
            default : ret = Car_Stop();
                    break;
        }
        __delay_ms(100);
    }
    return ret;
}

/**
 * A software Interface initializes the 
 * Application Layer.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType app_init(void)
{
    Std_ReturnType ret = E_OK;
    
    /* Initialize the ECUAL */
    ret = Ecu_Layer_Intialize();
    
    return ret;
}