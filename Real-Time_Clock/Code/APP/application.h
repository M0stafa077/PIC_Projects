/* 
 * File:   application.h
 * Author: Mostafa _Asaad
 *
 * Created on Feb 1, 2024, 09:23 PM
 */
#ifndef APPLICATION_H
#define	APPLICATION_H

/* ======================================================================= */
/* =================== Section : Includes ================================ */
/* ======================================================================= */
#include "ECUAL/ecu_layer_init.h"
#include "../MCAL/TIMER0/timer0.h"
#include "../MCAL/TIMER1/timer1.h"

/* ======================================================================= */
/* =================== Section : Extern Devices from ECU Layer =========== */
/* ======================================================================= */
extern seven_segment_t segment_hours;
extern seven_segment_t segment_minutes;
extern seven_segment_t segment_seconds;
extern pin_config_t SEG_SEC_EN1;
extern pin_config_t SEG_SEC_EN2;
extern pin_config_t SEG_MIN_EN1;
extern pin_config_t SEG_MIN_EN2;
extern pin_config_t SEG_HRS_EN1;
extern pin_config_t SEG_HRS_EN2;

/* ======================================================================= */
/* =================== Section : Datatype Declarations =================== */
/* ======================================================================= */
typedef struct
{
    uint8_t sec;
    uint8_t min;
    uint8_t hours;
} real_time_clock_t;

/* ======================================================================= */
/* =================== Section : Functions Prototypes ==================== */
/* ======================================================================= */
Std_ReturnType application_initialize(void);
Std_ReturnType real_time_clock_init(real_time_clock_t *clock);
void delay_5ms(void);
void ISR (void);
void dely_timer_isr (void);

#endif	/* APPLICATION_H */

