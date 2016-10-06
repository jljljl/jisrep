#include "src/Lcd.h"



Lcd::~Lcd() {
	// TODO Auto-generated destructor stub
}

//------------------------------------------------
void Lcd::delay(void)
{
	uint16_t i;
	for(i=0;i<1000;i++)
	{

	}
}
//------------------------------------------------
void Lcd::LCD_WriteData(uint8_t dt)
{
	if(((dt>>3)&0x01)==1) {d7_set();} else {d7_reset();}
	if(((dt>>2)&0x01)==1) {d6_set();} else {d6_reset();}
	if(((dt>>1)&0x01)==1) {d5_set();} else {d5_reset();}
	if((dt&0x01)==1) {d4_set();} else {d4_reset();}
}
//------------------------------------------------
void Lcd::LCD_Command(uint8_t dt)
{
	rs0;
	rw0;
	LCD_WriteData(dt>>4);
	e1;
	delay();
	e0;
	LCD_WriteData(dt);
	e1;
	delay();
	e0;
}
//------------------------------------------------
void Lcd::LCD_Data(uint8_t dt)
{
	rs1;
	rw0;
	LCD_WriteData(dt>>4);
	e1;
	delay();
	e0;
	LCD_WriteData(dt);
	e1;
	delay();
	e0;
}
//------------------------------------------------
void Lcd::LCD_Clear(void)
{
	LCD_Command(0x01);
	HAL_Delay(2);
}
//------------------------------------------------
void Lcd::LCD_SendChar(char ch)
{
	LCD_Data((uint8_t)ch);
	delay();
}
//------------------------------------------------
void Lcd::LCD_String(char* st)
{
	uint8_t i=0;
	while(st[i]!=0)
	{
		LCD_Data(st[i]);
		delay();
		i++;
	}
}
//------------------------------------------------
void Lcd::Lcd::LCD_SetPos(uint8_t x, uint8_t y)
{
	switch(y)
	{
		case 0:
			LCD_Command(x|0x80);
			HAL_Delay(1);
			break;
		case 1:
			LCD_Command((0x40+x)|0x80);
			HAL_Delay(1);
			break;
		case 2:
			LCD_Command((0x14+x)|0x80);
			HAL_Delay(1);
			break;
		case 3:
			LCD_Command((0x54+x)|0x80);
			HAL_Delay(1);
			break;
	}
}
//------------------------------------------------
void Lcd::LCD_ini(void)
{
	HAL_Delay(40);
	rs0;
	rw0;
	LCD_WriteData(3);
	e1;
	delay();
	e0;
	HAL_Delay(1);
	LCD_WriteData(3);
	e1;
	delay();
	e0;
	HAL_Delay(1);
	LCD_WriteData(3);
	e1;
	delay();
	e0;
	HAL_Delay(1);
	LCD_Command(0x3C);//ðåæèì 4 áèò, 2 ëèíèè (äëÿ íàøåãî áîëüøîãî äèñïëåÿ ýòî 4 ëèíèè, øðèôò 5õ8
	HAL_Delay(1);
	LCD_Command(0x3C);//åùå ðàç äëÿ âåðíîñòè
	HAL_Delay(1);
	LCD_Command(0x0F);//äèñïëåé âêëþ÷àåì (D=1), êóðñîðû íèêàêèå íå íóæíû
	HAL_Delay(1);
	LCD_Command(0x01);//óáåðåì ìóñîð
	HAL_Delay(2);
	LCD_Command(0x06);//ïèøåì âëåâî
	HAL_Delay(1);
	LCD_Command(0x02);//âîçâðàùàåì êóðñîð â íóëåâîå ïîëîæåíèå
	HAL_Delay(2);

}

void LCD_print(String s)
{
	uint32_t i=2;
	char str[50];
	LCD_SetPos(0, 0);
	sprintf(str, s);
	LCD_String(str);
}
