/*#ifndef LCD_H_
#define LCD_H_
//------------------------------------------------
#include "stm32f1xx_hal.h"
//------------------------------------------------
#define d4_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET)
#define d5_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET)
#define d6_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET)
#define d7_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET)
#define d4_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET)
#define d5_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET)
#define d6_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET)
#define d7_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET)
#define e1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET)  //óñòàíîâêà ëèíèè Å â 1
#define e0 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET) //óñòàíîâêà ëèíèè Å â 0
#define rs1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET) //óñòàíîâêà ëèíèè RS â 1
#define rs0 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET) //óñòàíîâêà ëèíèè RS â 0
//------------------------------------------------
void LCD_ini(void);
void LCD_Clear(void);
void LCD_SendChar(char ch);
void LCD_String(char* st);
void LCD_SetPos(uint8_t x, uint8_t y);
//------------------------------------------------
#endif  LCD_H_ */



#ifndef LCD_H_
#define LCD_H_

#include "stm32f1xx.h"
#define d4_set() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET)
#define d5_set() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET)
#define d6_set() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET)
#define d7_set() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET)
#define d4_reset() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET)
#define d5_reset() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET)
#define d6_reset() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET)
#define d7_reset() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET)
#define e1 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET)
#define e0 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET)
#define rs1 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET)
#define rs0 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET)
#define rw1 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET)
#define rw0 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET)

class Lcd
{
public:
	Lcd(PinOutputBoolean e, PinOutputBoolean rw, PinOutputBoolean rs, PinOutputBoolean d4, PinOutputBoolean d5, PinOutputBoolean d6, PinOutputBoolean d7)
	{
		fullMode = false;
		this->e = e;
		this->rw = rw;
		this->rs = rs;
		this->d4 = d4;
		this->d5 = d5;
		this->d6 = d6;
		this->d7 = d7;
	}
	Lcd()
	{

	}
	PinOutputBoolean e, ew, es, d4, d5, d6, d7;
	bool fullMode;

	void delay();
	void LCD_ini(void);
	void LCD_Clear(void);
	void LCD_SendChar(char ch);
	void LCD_String(char* st);
	void LCD_SetPos(uint8_t x, uint8_t y);
	void LCD_print(char array);


	virtual ~Lcd();
};




#endif /* MAIN_H_ */
