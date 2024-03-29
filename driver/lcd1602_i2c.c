/*
*       Author: Aar�n Escoboza Villegas
*       Github: aaron-ev
*
**/

#include "lcd1602_i2c.h"

void lcd_writeCMD(uint8_t cmd)
{
    uint8_t cmd_tr[4];
    uint8_t cmd_upper,cmd_lower;  //upper nibble and lower nibble

    cmd_lower = (cmd << 4 ) & MASK_UPPER_NIBBLE;
    cmd_upper = cmd & MASK_UPPER_NIBBLE;

    cmd_tr[0] = cmd_upper | 0x0C; //add E = 1 and RS = 0
    cmd_tr[1] = cmd_upper | 0x08; //add E = 0 and RS = 0
    cmd_tr[2] = cmd_lower | 0x0C;
    cmd_tr[3] = cmd_lower | 0x08;

    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADDRESS,cmd_tr,4,LCD_DELAY_100MS);
}
void lcd_writeData(char data)
{
    uint8_t data_tr[4];
    uint8_t data_upper,data_lower;  //upper nibble and lower nibble

    data_lower = (data << 4 ) & MASK_UPPER_NIBBLE;
    data_upper = data & MASK_UPPER_NIBBLE;

    data_tr[0] = data_upper | 0x0D; //add E = 1 and RS = 1
    data_tr[1] = data_upper | 0x09; //add E = 0 and RS = 1
    data_tr[2] = data_lower | 0x0D;
    data_tr[3] = data_lower | 0x09;

    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADDRESS,data_tr,4,LCD_DELAY_100MS);
}


void lcd_init(void)
{
    HAL_Delay(LCD_DELAY_100MS);
    lcd_writeCMD(CMD_SPECIAL_FSET);
    HAL_Delay(LCD_DELAY_5MS);
    lcd_writeCMD(CMD_SPECIAL_FSET);
    HAL_Delay(LCD_DELAY_1MS);
    lcd_writeCMD(CMD_SPECIAL_FSET);
    HAL_Delay(LCD_DELAY_1MS);

    lcd_writeCMD(CMD_4BITMODE);
    HAL_Delay(LCD_DELAY_1MS);

    lcd_writeCMD (CMD_4BITMODE_2L);
	HAL_Delay(LCD_DELAY_1MS);


    lcd_writeCMD(CMD_DISPLAY_OFF);
    HAL_Delay(LCD_DELAY_1MS);
    lcd_writeCMD(CMD_CLEAR);
    HAL_Delay(LCD_DELAY_1MS);
    lcd_writeCMD(CMD_ENTRY_MODE1);
    HAL_Delay(LCD_DELAY_1MS);
    lcd_writeCMD(CMD_DISPLAY_ON);
    HAL_Delay(LCD_DELAY_1MS);
}

void lcd_writeString(char *str)
{
    while(*str)
    lcd_writeData(*str++)
}
