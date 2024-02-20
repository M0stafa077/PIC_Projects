/* 
 * File:   ecu_layer_init.h
 * Author: Mostafa_Asaad
 *
 * Created on December 8, 2023, 11:47 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

/* Section : Includes */
#include "LED/LED.h"
#include "DC_Motor/dc_motor.h"
#include "Bluetooth_Module/bluetooth_module.h"
/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */
/**
 * A software Interface Initializes 
 * the Electronic Abstraction Layer.
 * @return: Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Ecu_Layer_Intialize(void);
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



#endif	/* ECU_LAYER_INIT_H */

