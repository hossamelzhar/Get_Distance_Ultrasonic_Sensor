#include "LCD.h"
/************************************* 8 BIT Mode functions********************************************/
#if (LCD_MODE==M_8BIT)

static void LCD_WriteCommand(u8 Command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,(Command));
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
}

void LCD_Init(void)
{
	
	_delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	
	LCD_WriteCommand(0x38); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	LCD_WriteCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_WriteCommand(0x01); //clear LCD
	_delay_ms(20);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x80);
}

static void LCD_WriteData(u8 Data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,(Data));
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
}
/************************************* 4 BIT Mode functions********************************************/
#elif (LCD_MODE==M_4BIT_SAMEPORT)



static void LCD_WriteCommand(u8 Command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WriteBitsInPort(LCD_PORT,(Command>>1),M_4BIT_MASK);
	//DIO_WriteBitsInPort(LCD_PORT,(Command),0xf0);
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
	DIO_WriteBitsInPort(LCD_PORT,(Command<<3),M_4BIT_MASK);
	//DIO_WriteBitsInPort(LCD_PORT,(Command<<4),0xf0);
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
}

 static void LCD_WriteData(u8 Data)
{
	GPIO_writePin(RS,HIGH);
	GPIO_writePin(RW,LOW);
	DIO_WriteBitsInPort(LCD_PORT,(Data>>1),M_4BIT_MASK);
	//DIO_WriteBitsInPort(LCD_PORT,((Data)),0xf0);
	GPIO_writePin(EN,HIGH);
	_delay_ms(2);
	GPIO_writePin(EN,LOW);
	_delay_ms(2);
	DIO_WriteBitsInPort(LCD_PORT,(Data<<3),M_4BIT_MASK);
	//DIO_WriteBitsInPort(LCD_PORT,(Data<<4),0xf0);
	GPIO_writePin(EN,HIGH);
	_delay_ms(2);
	GPIO_writePin(EN,LOW);
	_delay_ms(2);
}
void LCD_Init(void)
{
	
	_delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	LCD_WriteCommand(0x02);//4 bit mode only
	_delay_ms(1); 
	LCD_WriteCommand(0x28); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	LCD_WriteCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_WriteCommand(0x01); //clear LCD
	_delay_ms(20);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x80);
}
/************************************* 4 BIT Mode separated Pins functions********************************************/
#elif (LCD_MODE==M_4BIT_SEPARATED)

static void LCD_WriteCommand(u8 Command)
{
	GPIO_writePin(LCD_PORT, RS, LOW);
	//GPIO_writePin(RW,LOW);
	GPIO_writePin(LCD_PORT, D4, CHECK_BIT(Command,4));
	GPIO_writePin(LCD_PORT, D5, CHECK_BIT(Command,5));
	GPIO_writePin(LCD_PORT, D6, CHECK_BIT(Command,6));
	GPIO_writePin(LCD_PORT, D7, CHECK_BIT(Command,7));
	GPIO_writePin(LCD_PORT, EN, HIGH);
	_delay_ms(2);
	GPIO_writePin(LCD_PORT, EN, LOW);
	_delay_ms(2);
	GPIO_writePin(LCD_PORT, D4, CHECK_BIT(Command,0));
	GPIO_writePin(LCD_PORT, D5, CHECK_BIT(Command,1));
	GPIO_writePin(LCD_PORT, D6, CHECK_BIT(Command,2));
	GPIO_writePin(LCD_PORT, D7, CHECK_BIT(Command,3));
	GPIO_writePin(LCD_PORT, EN, HIGH);
	_delay_ms(2);
	GPIO_writePin(LCD_PORT, EN, LOW);
	_delay_ms(2);
}

static void LCD_WriteData(u8 Data)
{
	GPIO_writePin(LCD_PORT, RS, HIGH);
	//GPIO_writePin(RW,LOW);
	GPIO_writePin(LCD_PORT, D4, CHECK_BIT(Data,4));
	GPIO_writePin(LCD_PORT, D5, CHECK_BIT(Data,5));
	GPIO_writePin(LCD_PORT, D6, CHECK_BIT(Data,6));
	GPIO_writePin(LCD_PORT, D7, CHECK_BIT(Data,7));
	GPIO_writePin(LCD_PORT, EN, HIGH);
	_delay_ms(2);
	GPIO_writePin(LCD_PORT, EN, LOW);
	_delay_ms(2);
	GPIO_writePin(LCD_PORT, D4, CHECK_BIT(Data,0));
	GPIO_writePin(LCD_PORT, D5, CHECK_BIT(Data,1));
	GPIO_writePin(LCD_PORT, D6, CHECK_BIT(Data,2));
	GPIO_writePin(LCD_PORT, D7, CHECK_BIT(Data,3));
	GPIO_writePin(LCD_PORT, EN, HIGH);
	_delay_ms(2);
	GPIO_writePin(LCD_PORT, EN, LOW);
	_delay_ms(2);
}
void LCD_Init(void)
{
	_delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	LCD_WriteCommand(0x02);//4 bit mode only
	_delay_ms(1);
	LCD_WriteCommand(0x28); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	LCD_WriteCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_WriteCommand(0x01); //clear LCD
	_delay_ms(20);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x80);
}
#endif

/*************************** service functions*****************************************************/
void LCD_WriteChar(u8 character)
{
	LCD_WriteData(character);
}



void LCD_WriteSentence(const u8 *PtrSentance)
{
	u8 i=0;
	for(i=0;PtrSentance[i];i++)
	{
		LCD_WriteData(PtrSentance[i]);
	}

	

}
void LCD_GoTo(u8 Line, u8 x)
{
	if(0 == Line)
	{
		if ( x <=15)
		{
			LCD_WriteCommand(0x80 + x);
		}
	}
	else if (1 == Line)
	{
		if ( x <=15)
		{
			LCD_WriteCommand(0xC0 + x);
		}
	}
}



void LCD_WriteNumber(u64 Number)
{
	u8 i=0,arr[10],j;
	if(Number==0)
	LCD_WriteData('0');
	else{
			while(Number)
			{
				arr[i]=Number%10+'0';
				Number/=10;
				i++;
			}
			for(j=i;j>0;j--)
			{
				LCD_WriteData(arr[j-1]);
			}
	   }
}
void LCD_WriteNumber2(u16 Number)
{
	LCD_WriteData(Number%10000/1000+'0');
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}

void Create_Character(u8 *Pattern,u8 Location) {

	u8 iLoop=0;

	LCD_WriteCommand(0x40+(Location*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(Pattern[iLoop]); //Pass the bytes of pattern on LCD

}
void LCD_Clear(void)
{

	LCD_WriteCommand(0x01);

}

	

