/*
 * File:   main.c
 * Author: Hossam Elzhar
 *
 * Created on December 23, 2022, 10:27 PM
 */


#include "Services/Timer_Services/Timer_Servics.h"
#include "ECUAL/LCD/LCD.h"


Ultrasonic_T u1 = {PC, PIN0};
Ultrasonic_T u2 = {PC, PIN1};
Ultrasonic_T u3 = {PC, PIN2};
Ultrasonic_T u4 = {PC, PIN3};

u16 Distance;
u8 sentence[] = "Distance:";
u8 spaces[] = "   ";

int main(void) 
{
    sei();
    GPIO_Init();
    LCD_Init();
   
    PWM_Generator_HZ(50, 20);
    
    Ultrasonic_Init();
    
    LCD_WriteSentence(sentence);
    Distance = Ultrasonic_Get_Distance_CM(&u1);
    LCD_GoTo(1,0);
    LCD_WriteNumber(Distance);
    LCD_GoTo(1,0);
    LCD_WriteSentence(spaces);
    //u8 x = 0;
    while(1)
    {
        Distance = Ultrasonic_Get_Distance_CM(&u1);
        LCD_GoTo(1,0);
        LCD_WriteNumber(Distance);
        
        Distance = Ultrasonic_Get_Distance_CM(&u2);
        LCD_GoTo(1,4);
        LCD_WriteNumber(Distance);
        
        Distance = Ultrasonic_Get_Distance_CM(&u3);
        LCD_GoTo(1,8);
        LCD_WriteNumber(Distance);
        
        Distance = Ultrasonic_Get_Distance_CM(&u4);
        LCD_GoTo(1,12);
        LCD_WriteNumber(Distance);
        
    }
    return 0;
}
