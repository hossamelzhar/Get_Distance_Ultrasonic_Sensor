/* 
 * File:   GPIO.c
 * Author: Hossam Elzhar
 *
 * Created on December 23, 2022, 11:26 PM
 */

#include "GPIO.h"


void GPIO_Init(void)
{
    u8 PinNum_InPort;
	GPIO_Port_t Port;
	PinStatus_type Status;
	u8 LocalIterator;
	
	for (LocalIterator=0;LocalIterator<TOTAL_PINS;LocalIterator++)
	{
		Status=PinsStatus[LocalIterator];
		Port=LocalIterator/8;
		PinNum_InPort=LocalIterator%8;
		
		switch (Status)
		{
			case OUTPUT:
			switch (Port)
			{
				case PA:
				SET_BIT(DDRA,PinNum_InPort);
				break;
				case PB:
				SET_BIT(DDRB,PinNum_InPort);
				break;
				case PC:
				SET_BIT(DDRC,PinNum_InPort);
				break;
				case PD:
				SET_BIT(DDRD,PinNum_InPort);
				break;
			}
			break;
			case IN_PULLUP:
			switch (Port)
			{
				case PA:
				CLEAR_BIT(DDRA,PinNum_InPort);
				SET_BIT(PORTA,PinNum_InPort);
				break;
				case PB:
				CLEAR_BIT(DDRB,PinNum_InPort);
				SET_BIT(PORTB,PinNum_InPort);
				break;
				case PC:
				CLEAR_BIT(DDRC,PinNum_InPort);
				SET_BIT(PORTC,PinNum_InPort);
				break;
				case PD:
				CLEAR_BIT(DDRD,PinNum_InPort);
				SET_BIT(PORTD,PinNum_InPort);
				break;
			}
			break;
			case INPUT:
			switch (Port)
			{
				case PA:
				CLEAR_BIT(DDRA,PinNum_InPort);
				CLEAR_BIT(PORTA,PinNum_InPort);
				break;
				case PB:
				CLEAR_BIT(DDRB,PinNum_InPort);
				CLEAR_BIT(PORTB,PinNum_InPort);
				break;
				case PC:
				CLEAR_BIT(DDRC,PinNum_InPort);
				CLEAR_BIT(PORTC,PinNum_InPort);
				break;
				case PD:
				CLEAR_BIT(DDRD,PinNum_InPort);
				CLEAR_BIT(PORTD,PinNum_InPort);
				break;
			}
			break;
            case FLOATING:
                break;
		}
		
	}
}

void GPIO_setPin_Dir(GPIO_Port_t PORTx, GPIO_Pin_t PINx, PinStatus_type Dir)
{
    switch(PORTx)
    {
        case PA:
            switch(Dir)
            {
                case INPUT: CLEAR_BIT(DDRA, PINx); break;
                case OUTPUT: SET_BIT(DDRA, PINx); break;
                case IN_PULLUP: CLEAR_BIT(DDRA, PINx); SET_BIT(PORTA, PINx); break;
            }
            break;
            
        case PB:
            switch(Dir)
            {
                case INPUT: CLEAR_BIT(DDRB, PINx); break;
                case OUTPUT: SET_BIT(DDRB, PINx); break;
                case IN_PULLUP: CLEAR_BIT(DDRB, PINx); SET_BIT(PORTB, PINx); break;
            }
            break;
        
        case PC:
            switch(Dir)
            {
                case INPUT: CLEAR_BIT(DDRC, PINx); break;
                case OUTPUT: SET_BIT(DDRC, PINx); break;
                case IN_PULLUP: CLEAR_BIT(DDRC, PINx); SET_BIT(PORTC, PINx); break;
            }
            break;
            
        case PD:
            switch(Dir)
            {
                case INPUT: CLEAR_BIT(DDRD, PINx); break;
                case OUTPUT: SET_BIT(DDRD, PINx); break;
                case IN_PULLUP: CLEAR_BIT(DDRD, PINx); SET_BIT(PORTD, PINx); break;
            }
            break;
    }
}

void GPIO_writePort(GPIO_Port_t PORTx, u8 Value)
{
    switch(PORTx)
    {
        case PA:
            PORTA = Value;
            break;
            
        case PB:
            PORTB = Value;
            break;
        
        case PC:
            PORTC = Value;
            break;
            
        case PD:
            PORTD = Value;
            break;
    }
}

void GPIO_writePin(GPIO_Port_t PORTx, GPIO_Pin_t PINx, Volt_Level_t Level)
{
    switch(PORTx)
    {
        case PA:
            switch(Level)
            {
                case LOW: CLEAR_BIT(PORTA, PINx); break;
                case HIGH: SET_BIT(PORTA, PINx); break;
            }
            break;
            
        case PB:
            switch(Level)
            {
                case LOW: CLEAR_BIT(PORTB, PINx); break;
                case HIGH: SET_BIT(PORTB, PINx); break;
            }
            break;
        
        case PC:
            switch(Level)
            {
                case LOW: CLEAR_BIT(PORTC, PINx); break;
                case HIGH: SET_BIT(PORTC, PINx); break;
            }
            break;
            
        case PD:
            switch(Level)
            {
                case LOW: CLEAR_BIT(PORTD, PINx); break;
                case HIGH: SET_BIT(PORTD, PINx); break;
            }
            break;
    }
}

u8   GPIO_readPort(GPIO_Port_t PORTx)
{
    u8 value = 0;
    
     switch(PORTx)
    {
        case PA:
            value = PINA;
            break;
            
        case PB:
            value = PINB;
            break;
        
        case PC:
            value = PINC;
            break;
            
        case PD:
            value = PIND;
            break;
    }
     
     return value;
}

u8   GPIO_readPin(GPIO_Port_t PORTx, GPIO_Pin_t PINx)
{
    u8 value = 0;
    
     switch(PORTx)
    {
        case PA:
            value = CHECK_BIT(PINA, PINx);
            break;
            
        case PB:
            value = CHECK_BIT(PINB, PINx);
            break;
        
        case PC:
            value = CHECK_BIT(PINC, PINx);
            break;
            
        case PD:
            value = CHECK_BIT(PIND, PINx);
            break;
    }
     
     return value;
}

void GPIO_togglePort(GPIO_Port_t PORTx)
{
    switch(PORTx)
    {
        case PA:
            TOGGLE_REG(PORTA);
            break;
            
        case PB:
            TOGGLE_REG(PORTB);
            break;
        
        case PC:
            TOGGLE_REG(PORTC);
            break;
            
        case PD:
            TOGGLE_REG(PORTD);
            break;
    }
}

void GPIO_togglePin(GPIO_Port_t PORTx, GPIO_Pin_t PINx)
{
    switch(PORTx)
    {
        case PA:
            TOGGLE_BIT(PORTA, PINx);
            break;
            
        case PB:
            TOGGLE_BIT(PORTB, PINx);
            break;
        
        case PC:
            TOGGLE_BIT(PORTC, PINx);
            break;
            
        case PD:
            TOGGLE_BIT(PORTD, PINx);
            break;
    }
}