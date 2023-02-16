#include "Timer.h"



/****************************Pointer to functions to be assigned to ISR*********************************/
static void (*Timer0_OC_Fptr) (void) = NULLPTR;
static void (*Timer0_OVF_Fptr)(void) = NULLPTR;
static void (*Timer1_OVF_Fptr)(void) = NULLPTR;
static void (*Timer1_OCA_Fptr)(void) = NULLPTR;
static void (*Timer1_OCB_Fptr)(void) = NULLPTR;
static void (*Timer1_ICU_Fptr)(void) = NULLPTR;
/********************************************************************************************************/


/**********************************Timer 0 ****************************************************/

void Timer0_Init( Timer0Mode_type mode,Timer0Scaler_type scaler ,OC0Mode_type oc_mode)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}

	TCCR0 &= PRESCALER_CLEAR_MASK;
	TCCR0 |= scaler;

	switch (oc_mode)
	{
		case OCO_DISCONNECTED:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case OCO_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case OCO_NON_INVERTING:
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case OCO_INVERTING:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
	

}

/*******************Macro functions******************************/
#define Timer0_OVF_InterruptEnable()  SET_BIT(TIMSK,TOIE0)
#define Timer0_OVF_InterruptDisable() CLEAR_BIT(TIMSK,TOIE0)
#define Timer0_OC_InterruptEnable()  SET_BIT(TIMSK,OCIE0)
#define Timer0_OC_InterruptDisable() CLEAR_BIT(TIMSK,OCIE0)
/****************************************************************/


void Timer0_OVF_SetCallBack(void (*fptr)(void))
{
    Timer0_OVF_Fptr = fptr;
}


void Timer0_OC_SetCallBack(void (*fptr)(void))
{
    Timer0_OC_Fptr = fptr;
}


ISR(TIMER0_OVF_vect)
{
    Timer0_OVF_Fptr();
}

ISR(TIMER0_COMP_vect)
{
    Timer0_OC_Fptr();
}


/*************************************************TIMER 1 **************************************************/

void Timer1_Init(Timer1Mode_type mode, Timer1Scaler_type scaler, OC1AMode_type ocr1a_mode, OC1BMode_type ocr1b_mode)
{
    switch(mode)
    {
        case TIMER1_NORMAL_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            CLEAR_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            break;
        case TIMER1_CTC_TOP_OCR1A_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            break;
        case TIMER1_PHASECORRECT_TOP_ICR1_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            CLEAR_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;
        case TIMER1_PHASECORRECT_TOP_OCR1A_MODE:
            SET_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            CLEAR_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;
        case TIMER1_PHASE_FREQ_CORRECT_TOP_ICR1_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            CLEAR_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;
        case TIMER1_PHASE_FREQ_CORRECT_TOP_OCR1A_MODE:
            SET_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            CLEAR_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;
        case TIMER1_FASTPWM_TOP_ICR1_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;
        case TIMER1_FASTPWM_TOP_OCR1A_MODE:
            SET_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;
    }
    
    TCCR1B &= PRESCALER_CLEAR_MASK; //clear the least bits (prescaler select bits)
    TCCR1B |= scaler;
    
    switch(ocr1a_mode)
    {
        case OC1A_DISCONNECTED:
            CLEAR_BIT(TCCR1A, COM1A0);
            CLEAR_BIT(TCCR1A, COM1A1);
            break;
        case OC1A_TOGGLE:
            SET_BIT(TCCR1A, COM1A0);
            CLEAR_BIT(TCCR1A, COM1A1);
            break;
        case OC1A_NON_INVERTING:
            CLEAR_BIT(TCCR1A, COM1A0);
            SET_BIT(TCCR1A, COM1A1);
            break;
        case OC1A_INVERTING:
            SET_BIT(TCCR1A, COM1A0);
            SET_BIT(TCCR1A, COM1A1);
            break;
    }
    
    switch(ocr1b_mode)
    {
        case OC1B_DISCONNECTED:
            CLEAR_BIT(TCCR1A, COM1B0);
            CLEAR_BIT(TCCR1A, COM1B1);
            break;
        case OC1B_TOGGLE:
            SET_BIT(TCCR1A, COM1B0);
            CLEAR_BIT(TCCR1A, COM1B1);
            break;
        case OC1B_NON_INVERTING:
            CLEAR_BIT(TCCR1A, COM1B0);
            SET_BIT(TCCR1A, COM1B1);
            break;
        case OC1B_INVERTING:
            SET_BIT(TCCR1A, COM1B0);
            SET_BIT(TCCR1A, COM1B1);
            break;
    }
}

void Timer1_ICU_Set_Edge(ICU_EDGE_T edge)
{
    switch(edge)
    {
        case FALLING:
            CLEAR_BIT(TCCR1B, ICES1);
            break;
        case RISING:
            SET_BIT(TCCR1B, ICES1);
            break;
    }
}


/****************Set Interrupts Functions Call Back*********************/
void Timer1_OVF_SetCallBack(void (*fptr)(void))
{
    Timer1_OVF_Fptr = fptr;
}

void Timer1_OC1A_SetCallBack(void (*fptr)(void))
{
    Timer1_OCA_Fptr = fptr;
}

void Timer1_OC1B_SetCallBack(void (*fptr)(void))
{
    Timer1_OCB_Fptr = fptr;
}

void Timer1_ICU_SetCallBack(void (*fptr)(void))
{
    Timer1_ICU_Fptr = fptr;
}
/*************************************************************************/


ISR(TIMER1_OVF_vect)
{
    Timer1_OVF_Fptr();
}
ISR(TIMER1_COMPA_vect)
{
    Timer1_OCA_Fptr();
}
ISR(TIMER1_COMPB_vect)
{
    Timer1_OCB_Fptr();
}
ISR(Timer1_ICU_vect)
{
    Timer1_ICU_Fptr();
}