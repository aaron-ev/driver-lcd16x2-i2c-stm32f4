/*
*       Author: Aar�n Escoboza Villegas
*       Github: aaron-ev
*
**/


#ifndef LCD1602_I2C_H
#define LCD1602_I2C_H
#include "stm32f4xx_hal.h"


// change here your handler and lcd address
extern I2C_HandleTypeDef hi2c1; // change I2C handler based on the I2C peripheral used
#define LCD_ADDRESS 0x4e  // Changed based on your settings


/***********************************************
 *
 * 				Macro definitions
 *
 ***********************************************
*/
//masks

#define MASK_UPPER_NIBBLE 0xf0

//delays

#define LCD_DELAY_100MS    100
#define LCD_DELAY_5MS       5
#define LCD_DELAY_1MS       1

// @commands

#define  CMD_4BITMODE		        0x20
#define  CMD_4BITMODE_2L		    0x28
#define  CMD_DISPLAY_OFF 	        0x08
#define  CMD_DISPLAY_ON 	        0x0C
#define  CMD_DISPLAY_ON_BLIK_ON 	0x0D
#define  CMD_CLEAR			        0x01
#define  CMD_RETURN_HOME			0x02
#define  CMD_SPECIAL_FSET           0x30
#define  CMD_ENTRY_MODE1            0x06  // cursor/blink moves to the right and DDRAM address is increased by 1,shift OFF


/***********************************************
 *
 * 				Function prototypes
 *
 ***********************************************
*/


/*
*   function name: lcd_writeCMD(char cmd);
*     description: send a command to the lcd
*           input: command to send refers <this command can be @ref commands >
*/
void lcd_writeCMD(uint8_t cmd);

/*
*   function name: lcd_init(void);
*     description: initialize lcd screen
*
*/
void lcd_init(void);

/*
*   function name: lcd_writeData(char data);
*     description: send data to the lcd
*           input: data to be sent
*/
void lcd_writeData(char data);
/*
*   function name: lcd_writeString(char *str);
*     description: send a string to the lcd
*           input: data to be sent
*/
void lcd_writeString(char *str);
#endif
