#include "EXT_Interrupt.h"

static void (*INT0_fptr)(void);
static void (*INT1_fptr)(void);
static void (*INT2_fptr)(void);

void EXI_Enable(Interrupt_Name_T Interrupt_Name)
{
    switch(Interrupt_Name)
    {
        case EX_INT0:
            SET_BIT(GICR, INT0);
            break;
        
        case EX_INT1:
            SET_BIT(GICR, INT1);
            break;
            
        case EX_INT2:
            SET_BIT(GICR, INT2);
            break;
    }
}
void EXI_Disable(Interrupt_Name_T Interrupt_Name)
{
    switch(Interrupt_Name)
    {
        case EX_INT0:
            CLEAR_BIT(GICR, INT0);
            break;
        
        case EX_INT1:
            CLEAR_BIT(GICR, INT1);
            break;
            
        case EX_INT2:
            CLEAR_BIT(GICR, INT2);
            break;
    }
}
void EXI_TriggerEdge(Interrupt_Name_T Interrupt_Name, EDGE_T Edge)
{
    switch(Interrupt_Name)
    {
        case EX_INT0:
            switch(Edge)
            {
                case LOW_LEVEL:
                    CLEAR_BIT(MCUCR, ISC00);
                    CLEAR_BIT(MCUCR, ISC01);
                    break;
                    
                case ANY_LOGICAL_CHANGE:
                    SET_BIT(MCUCR, ISC00);
                    CLEAR_BIT(MCUCR, ISC01);
                    break;
                    
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR, ISC00);
                    SET_BIT(MCUCR, ISC01);
                    break;
                    
                case RISING_EDGE:
                    SET_BIT(MCUCR, ISC00);
                    SET_BIT(MCUCR, ISC01);
                    break;
            }
            break;
        
        case EX_INT1:
            switch(Edge)
            {
                case LOW_LEVEL:
                    CLEAR_BIT(MCUCR, ISC10);
                    CLEAR_BIT(MCUCR, ISC11);
                    break;
                    
                case ANY_LOGICAL_CHANGE:
                    SET_BIT(MCUCR, ISC10);
                    CLEAR_BIT(MCUCR, ISC11);
                    break;
                    
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR, ISC10);
                    SET_BIT(MCUCR, ISC11);
                    break;
                    
                case RISING_EDGE:
                    SET_BIT(MCUCR, ISC10);
                    SET_BIT(MCUCR, ISC11);
                    break;
            }
            break;
            
        case EX_INT2:
            switch(Edge)
            {
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR, ISC2);
                    break;
                    
                case RISING_EDGE:
                    SET_BIT(MCUCR, ISC2);
                    break;
            }
            break;
    }
}

void EXI_SetCallBack(Interrupt_Name_T Interrupt_Name, void (*fptr)(void))
{
    switch(Interrupt_Name)
    {
        case EX_INT0:
            INT0_fptr = fptr;
            break;
        case EX_INT1:
            INT1_fptr = fptr;
            break;
        case EX_INT2:
            INT2_fptr = fptr;
            break;
    }
}

ISR(INT0_vect)
{
    INT0_fptr();
}

ISR(INT1_vect)
{
    INT1_fptr();
}

ISR(INT2_vect)
{
    INT2_fptr();
}