/* 
 * File:   Timer_Servics.h
 * Author: Hossam Elzhar
 *
 * Created on December 25, 2022, 3:42 PM
 */

#ifndef TIMER_SERVICS_H
#define	TIMER_SERVICS_H


#define F_CPU 8000000
#include <util/delay.h>
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/Timer/Timer.h"

typedef struct
{
    GPIO_Port_t Port;
    GPIO_Pin_t PIN;
}Ultrasonic_T;

void PWM_Generator_HZ(u16 Frequancy, u8 Duty);
void PWM_Generator_KHZ(u16 Frequancy, u8 Duty);
void Ultrasonic_Init(void);
u16  Ultrasonic_Get_Distance_CM(Ultrasonic_T* Ultrasonic);

#endif	/* TIMER_SERVICS_H */

