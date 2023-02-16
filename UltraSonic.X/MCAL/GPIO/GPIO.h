/* 
 * File:   GPIO.h
 * Author: Hossam Elzhar
 *
 * Created on December 23, 2022, 11:26 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include "../Utiles/MemMap.h"
#include "../Utiles/Std_Types.h"
#include "../Utiles/Macros.h"
#include "GPIO_Lcfg.h"

typedef enum
{
    PA,
    PB,
    PC,
    PD
}GPIO_Port_t;

typedef enum
{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}GPIO_Pin_t;


typedef enum
{
    LOW,
    HIGH
}Volt_Level_t;


void GPIO_Init(void);
void GPIO_setPin_Dir(GPIO_Port_t PORTx, GPIO_Pin_t PINx, PinStatus_type Dir);
void GPIO_writePort(GPIO_Port_t PORTx, u8 Value);
void GPIO_writePin(GPIO_Port_t PORTx, GPIO_Pin_t PINx, Volt_Level_t Level);
u8   GPIO_readPort(GPIO_Port_t PORTx);
u8   GPIO_readPin(GPIO_Port_t PORTx, GPIO_Pin_t PINx);
void GPIO_togglePort(GPIO_Port_t PORTx);
void GPIO_togglePin(GPIO_Port_t PORTx, GPIO_Pin_t PINx);


#endif	/* GPIO_H */

