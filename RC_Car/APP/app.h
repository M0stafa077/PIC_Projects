/* 
 * File:   app.h
 * Author: Mostafa Asaad
 *
 * Created on February 20, 2024, 8:50 PM
 */

#ifndef APP_H
#define	APP_H

/* --------------- Section : Includes --------------- */
#include "../ECUAL/ecu_layer_init.h"
/* --------------- Section : Extern Electronic Devices --------------- */
/*
 * Right-Front LED
 */
extern led_t F_R_LED;

/*
 * Left-Front LED
 */
extern led_t F_L_LED;

/*
 * Right-Back LED
 */
extern led_t B_LED_R;

/*
 * Left-Back LED
 */
extern led_t B_LED_L;

/*
 * A dc motor object
 * for the right motor
 * of the RC Car
 */
extern dc_motor_t Right_Motor;

/*
 * A dc motor object
 * for the left motor
 * of the RC Car
 */
extern dc_motor_t Left_Motor;

/*---------------  Section: Function Declarations --------------- */
/**
 * A software Interface initializes the 
 * Application Layer.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType app_init(void);
/**
 * A software Interface moves the 
 * RC Car forward.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Move_Forward(void);
/**
 * A software Interface moves the 
 * RC Car Backward.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Move_Backward(void);
/**
 * A software Interface moves the 
 * RC Car Right.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Move_Right(void);
/**
 * A software Interface moves the 
 * RC Car Left.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Move_Left(void);
/**
 * A software Interface stops
 * the RC Car.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Car_Stop(void);

#endif	/* APP_H */
