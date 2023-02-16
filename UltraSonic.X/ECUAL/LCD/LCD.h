#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/GPIO/GPIO_Lcfg.h"
#include <util/delay.h>

/**********************************     LCD Modes   **************************************************/
#define M_4BIT_SAMEPORT  0
#define M_4BIT_SEPARATED 1
#define M_8BIT           2


/********************************* define control pins     *******************************************/
#define RS  PIN4
//#define RW  PIN7
#define EN  PIN5
/*********************************   define LCD Mode       *******************************************/
#define LCD_MODE  M_4BIT_SEPARATED

/*******************for 8 bit mode and 4 bit_sameport mode define the LCD port **********************/
#define LCD_PORT  PA
/*******************for 4 bit same port mode define pins mask in port *******************************/
#define M_4BIT_MASK 0X78
/*******************    for 4 bit separated pins  mode define pins    *******************************/
#define D4 PIN0
#define D5 PIN1
#define D6 PIN2
#define D7 PIN3

/******************************************************************************************************/


extern void LCD_Init(void);
extern void LCD_WriteChar(u8 Character);
extern void LCD_WriteSentence(const u8 *PtrSentance);
extern void LCD_GoTo(u8 Line, u8 x);
extern void LCD_WriteNumber(u64 Number);
extern void LCD_WriteNumber2(u16 Number);
extern void LCD_Create_Character(u8 *Pattern,u8 Location);
extern void LCD_Clear(void);






#endif
