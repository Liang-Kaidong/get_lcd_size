/***************************************************************************************************************
File name: get_lcd_size.h
Author: KD
Version: V_1.0
Build date: 2025-07-07
Description: get_lcd_size.h is a header file that provides declarations for the functions implemented in the 
             get_lcd_size.c file. These functions are primarily used to obtain key parameters of the LCD screen,
             such as the screen width, height, and bits per pixel. They can also check whether the LCD screen 
             supports RGB565 and RGB888 color formats. 
Others: Usage requires preservation of original author attribution.
***************************************************************************************************************/

#ifndef GET_LCD_SIZE_H
#define GET_LCD_SIZE_H

/*
* @file get_lcd_size.h
* @brief LCD屏幕参数获取库
*/

#include <stdint.h>

/*
* 获取LCD屏幕宽度
* @return LCD宽度(像素)
*/
int get_lcd_width(void);

/*
* 获取LCD屏幕高度
* @return LCD高度(像素)
*/
int get_lcd_height(void);

/*
* 获取LCD位深度
* @return LCD位深度(16/24/32位)
*/
int get_lcd_bpp(void);

/*
* 检查LCD是否支持RGB565格式
* @return 支持返回1，否则返回0
*/
int is_lcd_rgb565(void);

/*
* 检查LCD是否支持RGB888格式
* @return 支持返回1，否则返回0
*/
int is_lcd_rgb888(void);

#endif /* GET_LCD_SIZE_H */