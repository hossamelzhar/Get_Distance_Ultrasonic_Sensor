/* 
 * File:   Timer.h
 * Author: Hossam Elzhar
 *
 * Created on December 24, 2022, 4:40 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#include "../Utiles/MemMap.h"
#include "../Utiles/Std_Types.h"
#include "../Utiles/Macros.h"


/**************************************Timer0***************************************************/

#define PRESCALER_CLEAR_MASK 0XF8

typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer0Scaler_type;

typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;

typedef enum
{
	OCO_DISCONNECTED=0,
	OCO_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING

}OC0Mode_type;



void Timer0_Init( Timer0Mode_type mode,Timer0Scaler_type scaler ,OC0Mode_type oc_mode);
void Timer0_OVF_SetCallBack(void (*fptr)(void));
void Timer0_OC_SetCallBack(void (*fptr)(void));
/*********************************************************************************************************/

/*******************************************Timer1********************************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL1_RISING
}Timer1Scaler_type;

typedef enum
{
	OC1A_DISCONNECTED=0,
	OC1A_TOGGLE,
	OC1A_NON_INVERTING,
	OC1A_INVERTING

}OC1AMode_type;

typedef enum
{
	OC1B_DISCONNECTED=0,
	OC1B_TOGGLE,
	OC1B_NON_INVERTING,
	OC1B_INVERTING

}OC1BMode_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_TOP_OCR1A_MODE,
    TIMER1_PHASECORRECT_TOP_ICR1_MODE,
    TIMER1_PHASECORRECT_TOP_OCR1A_MODE,
	TIMER1_PHASE_FREQ_CORRECT_TOP_ICR1_MODE,
    TIMER1_PHASE_FREQ_CORRECT_TOP_OCR1A_MODE,
	TIMER1_FASTPWM_TOP_ICR1_MODE,
    TIMER1_FASTPWM_TOP_OCR1A_MODE
}Timer1Mode_type;

typedef enum
{
    FALLING,
    RISING
}ICU_EDGE_T;

void Timer1_Init(Timer1Mode_type mode, Timer1Scaler_type scaler, OC1AMode_type ocr1a_mode, OC1BMode_type ocr1b_mode);
void Timer1_ICU_Set_Edge(ICU_EDGE_T edge);
void Timer1_OVF_SetCallBack(void (*fptr)(void));
void Timer1_OC1A_SetCallBack(void (*fptr)(void));
void Timer1_OC1B_SetCallBack(void (*fptr)(void));
void Timer1_ICU_SetCallBack(void (*fptr)(void));
/**********Timer1 Interrupts Enable/Disable Macro Functions**************/
#define Timer1_ICU_Interrupt_Enable()  SET_BIT(TIMSK, TICIE1)
#define Timer1_ICU_Interrupt_Disable() CLEAR_BIT(TIMSK, TICIE1)
#define TIMER1_ICU_NOIS_CANCEL_ENABLE() SET_BIT(TCCR1B, ICNC1)
#define TIMER1_ICU_NOIS_CANCEL_DISABLE() CLEAR_BIT(TCCR1B, ICNC1)
#define Timer1_OC1A_Interrupt_Enable() SET_BIT(TIMSK, OCIE1A)
#define Timer1_OC1A_Interrupt_Disable() CLEAR_BIT(TIMSK, OCIE1A)
#define Timer1_OC1B_Interrupt_Enable() SET_BIT(TIMSK, OCIE1B)
#define Timer1_OC1B_Interrupt_Disable() CLEAR_BIT(TIMSK, OCIE1B)
#define Timer1_OVF_Interrupt_Enable() SET_BIT(TIMSK, TOIE1)
#define Timer1_OVF_Interrupt_Disable() CLEAR_BIT(TIMSK, TOIE1)
/***********************************************************************/
/*********************************************************************************************************/

#endif	/* TIMER_H */

