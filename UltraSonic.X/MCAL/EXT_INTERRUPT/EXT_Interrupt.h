/* 
 * File:   EXT_Interrupt.h
 * Author: hossam elzhar
 *
 * Created on October 24, 2022, 2:04 AM
 */

#ifndef EXT_INTERRUPT_H
#define	EXT_INTERRUPT_H

#include "../Utiles/MemMap.h"
#include "../Utiles/Std_Types.h"
#include "../Utiles/Macros.h"

typedef enum 
{
    EX_INT0,
    EX_INT1,
    EX_INT2
}Interrupt_Name_T;

typedef enum
{
    LOW_LEVEL,
    ANY_LOGICAL_CHANGE,
    FALLING_EDGE,
    RISING_EDGE
}EDGE_T;

#define sei()  __asm__ __volatile__ ("sei" ::)
#define cli()  __asm__ __volatile__ ("cli" ::)



void EXI_Enable(Interrupt_Name_T Interrupt_Name);
void EXI_Disable(Interrupt_Name_T Interrupt_Name);
void EXI_TriggerEdge(Interrupt_Name_T Interrupt_Name, EDGE_T Edge);
void EXI_SetCallBack(Interrupt_Name_T Interrupt_Name, void (*fptr)(void));

#endif	/* EXT_INTERRUPT_H */

