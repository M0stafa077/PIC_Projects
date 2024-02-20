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
/*
 * Main Function
 */
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

/**
 * A software Interface moves the 
 * RC Car forward.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Move_Forward(void)
{
    Std_ReturnType ret = E_OK;
    
    /* Move Both motors in forward direction */
    ret = dc_motor_move_CW(&Right_Motor);
    ret = dc_motor_move_CW(&Left_Motor);
    
    /* Turn On the Two LEDs in the Front */
    ret = led_turn_ON(&F_R_LED);
    ret = led_turn_ON(&F_L_LED);
    
    /* Turn Off the Two LEDs in the Back */
    ret = led_turn_OFF(&B_LED_R);
    ret = led_turn_OFF(&B_LED_L);
    
    return ret;
}
/**
 * A software Interface moves the 
 * RC Car Backward.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Move_Backward(void)
{
    Std_ReturnType ret = E_OK;
    
    ret = dc_motor_move_CCW(&Right_Motor);
    ret = dc_motor_move_CCW(&Left_Motor);
    
    /* Turn Off the Two LEDs in the Front */
    ret = led_turn_OFF(&F_R_LED);
    ret = led_turn_OFF(&F_L_LED);
    
    /* Turn On the Two LEDs in the Back */
    ret = led_turn_ON(&B_LED_R);
    ret = led_turn_ON(&B_LED_L);
    
    return ret;
}
/**
 * A software Interface moves the 
 * RC Car Right.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Move_Right(void)
{
    Std_ReturnType ret = E_OK;
    
    ret = dc_motor_stop(&Right_Motor);
    ret = dc_motor_move_CW(&Left_Motor);
    
    /* Turn On the Right LED in the Front */
    ret = led_turn_ON(&F_R_LED);
    
    /* Turn Off all Other LEDs */
    ret = led_turn_OFF(&F_L_LED);
    ret = led_turn_OFF(&B_LED_R);
    ret = led_turn_OFF(&B_LED_L);
    
    return ret;
}
/**
 * A software Interface moves the 
 * RC Car Left.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Move_Left(void)
{
    Std_ReturnType ret = E_OK;
    
    ret = dc_motor_move_CCW(&Right_Motor);
    ret = dc_motor_stop(&Left_Motor);
    
    /* Turn On the Left LED in the Front */
    ret = led_turn_ON(&F_L_LED);
    
    /* Turn Off all Other LEDs */
    ret = led_turn_OFF(&F_R_LED);
    ret = led_turn_OFF(&B_LED_R);
    ret = led_turn_OFF(&B_LED_L);
    
    return ret;
}
/**
 * A software Interface stops
 * the RC Car.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Stop(void)
{
    Std_ReturnType ret = E_OK;
    
    ret = dc_motor_stop(&Right_Motor);
    ret = dc_motor_stop(&Left_Motor);
    
    /* Turn Off all the LEDs */
    ret = led_turn_OFF(&F_R_LED);
    ret = led_turn_OFF(&F_L_LED);
    ret = led_turn_OFF(&B_LED_R);
    ret = led_turn_OFF(&B_LED_L);
    
    return ret;
}
