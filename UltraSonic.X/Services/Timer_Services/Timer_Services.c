#include "Timer_Servics.h"



volatile u16 T1, T2;
volatile u8 counter;
volatile u8 flag;

static void Timer1_OC1A_Interrupt_Function(void);
static void Timer1_ICU_Interrupt_Function(void);

void PWM_Generator_HZ(u16 Frequancy, u8 Duty)
{    
    Timer1_Init(TIMER1_FASTPWM_TOP_OCR1A_MODE, TIMER1_SCALER_8, OC1A_TOGGLE, OC1B_NON_INVERTING);
    OCR1A = ((u32)1000000/Frequancy);
    OCR1B = (((u32)OCR1A * Duty) / 100);
    
}

void PWM_Generator_KHZ(u16 Frequancy, u8 Duty)
{
    Timer1_Init(TIMER1_PHASECORRECT_TOP_OCR1A_MODE, TIMER1_SCALER_8, OC1A_TOGGLE, OC1B_NON_INVERTING);
    OCR1A = ((u32)1000/(Frequancy*2)) -1;
    OCR1B = (((u32)OCR1A * Duty) / 100) -1;
}

void Ultrasonic_Init(void)
{
    Timer1_ICU_SetCallBack(Timer1_ICU_Interrupt_Function);
    Timer1_OC1A_SetCallBack(Timer1_OC1A_Interrupt_Function);
    
}

u16 Ultrasonic_Get_Distance_CM(Ultrasonic_T* Ultrasonic)
{
    u16 Time = 0;
    u16 distance = 0;
    u16 Top = OCR1A;
    if(Ultrasonic)//Not NULL
    {   
        flag = 0;
        
        while(TCNT1 != 0);//wait until timer1 initial value == 0
        
        GPIO_writePin(Ultrasonic->Port, Ultrasonic->PIN, HIGH);
        _delay_us(10);
        Timer1_ICU_Set_Edge(RISING);
        Timer1_ICU_Interrupt_Enable();  
        GPIO_writePin(Ultrasonic->Port, Ultrasonic->PIN, LOW);
        Timer1_OC1A_Interrupt_Enable();
        
        while(flag < 2);
        
        Time = T2 + ((u32) counter * Top) - T1;
       
        distance = (Time)/58;
    }
    
    return distance;
}

static void Timer1_ICU_Interrupt_Function(void)
{
    if(flag == 0)
    {
        T1 = ICR1;
        counter = 0;
        Timer1_ICU_Set_Edge(FALLING);
        flag = 1;
    }
    else if(flag == 1)
    {
        T2 = ICR1;
        Timer1_ICU_Set_Edge(RISING);
        Timer1_ICU_Interrupt_Disable();
        Timer1_OC1A_Interrupt_Disable();
        flag = 2;
    }
}
static void Timer1_OC1A_Interrupt_Function(void)
{
    counter++;
}