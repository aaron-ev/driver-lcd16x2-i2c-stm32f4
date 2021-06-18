/*
*       Author: Aarón Escoboza Villegas
*       Github: aaron-ev
*
**/

#include "lcd1602_i2c.h"

void lcd_writeCMD(uint8_t cmd)
{
    uint8_t data[4];
    uint8_t data_upper,data_lower;  //upper nibble and lower nibble

    data_lower = (cmd << 4 ) & MASK_UPPER_NIBBLE;
    data_upper = cmd & MASK_UPPER_NIBBLE;

    data[0] = data_upper | 0x0C; //add E = 1 and RS = 0
    data[1] = data_upper | 0x08; //add E = 0 and RS = 0
    data[2] = data_lower | 0x0C;
    data[3] = data_lower | 0x08;

    HAL_I2C_Master_Transmit(&hi2c1,LCD_ADDRESS,data,4,LCD_DELAY_100ms);
}


