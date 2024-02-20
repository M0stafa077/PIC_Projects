/* 
 * File:   ecu_layer_init.c
 * Author: Mostafa_Asaad
 *
 * Created on December 8, 2023, 11:47 PM
 */

/* --------------- Section : Includes --------------- */
#include "ecu_layer_init.h"
/* --------------- Section : Electronic Devices --------------- */
led_t F_R_LED = { .port = PORTC_INDEX, .pin = PIN4_INDEX, .led_status = LED_OFF };

led_t F_L_LED = { .port = PORTC_INDEX, .pin = PIN5_INDEX, .led_status = LED_OFF };

led_t B_LED_R = { .port = PORTD_INDEX, .pin = PIN0_INDEX, .led_status = LED_OFF };

led_t B_LED_L = { .port = PORTD_INDEX, .pin = PIN1_INDEX, .led_status = LED_OFF };

/*
 * A dc motor object
 * for the right motor
 * of the RC Car
 */
dc_motor_t Right_Motor = 
{
    /* Positive pin configurations */
    .button_pin[0].port = PORTC_INDEX,
    .button_pin[0].pin = PIN0_INDEX,
    .button_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .button_pin[0].logic = STD_LOW,

    /* Negative pin configurations */
    .button_pin[1].port = PORTC_INDEX,
    .button_pin[1].pin = PIN1_INDEX,
    .button_pin[1].direction = GPIO_DIRECTION_OUTPUT,
    .button_pin[1].logic = STD_LOW
};

/*
 * A dc motor object
 * for the left motor
 * of the RC Car
 */
dc_motor_t Left_Motor = 
{
    /* Positive pin configurations */
    .button_pin[0].port = PORTA_INDEX,
    .button_pin[0].pin = PIN4_INDEX,
    .button_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .button_pin[0].logic = STD_LOW,

    /* Negative pin configurations */
    .button_pin[1].port = PORTA_INDEX,
    .button_pin[1].pin = PIN5_INDEX,
    .button_pin[1].direction = GPIO_DIRECTION_OUTPUT,
    .button_pin[1].logic = STD_LOW
};
/* ---------- Section : Functions Definitions ---------- */
/**
 * A software Interface Initializes 
 * the Electronic Abstraction Layer.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Ecu_Layer_Intialize(void)
{
    Std_ReturnType ret = E_OK;
    
    /* Initialize the Motors */
    ret = dc_motor_init(&Right_Motor);
    ret = dc_motor_init(&Left_Motor);
    
    /* Initialize the Bluetooth Module */
    ret = Bluetooth_Init();
    
    /* Initialize the LEDs */
    ret = led_init(&F_R_LED);
    ret = led_init(&F_L_LED);
    ret = led_init(&B_LED_R);
    ret = led_init(&B_LED_L);
    
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