/**********************************************************************************************************
File name: get_lcd_size.c
Author: KD
Version: V_1.0
Build date: 2025-07-07
Description: This C file get_lcd_size_demo.c is a demonstration program. Its main function is to obtain 
             relevant parameters of the LCD screen, including the screen width, height, and bits per pixel. 
             The program prints out these basic information, checks whether the LCD screen supports RGB565 
             and RGB888 color formats, and prints information about the supported color formats. Finally, 
             based on the color formats supported by the screen, it selects an appropriate display mode 
             and outputs corresponding prompts. If neither of these two formats is supported, it uses the 
             default settings.
Others: Usage requires preservation of original author attribution.
**********************************************************************************************************/
#include <stdio.h>
#include "get_lcd_size.h"

int main() {
    /* 获取LCD参数 */ 
    int width = get_lcd_width();
    int height = get_lcd_height();
    int bpp = get_lcd_bpp();
    
    /* 打印基本信息 */ 
    printf("LCD信息: %dx%d, %d位\n", width, height, bpp);
    
    /* 检查颜色格式支持 */ 
    if (is_lcd_rgb565()) {
        printf("支持RGB565格式\n");
    }
    
    if (is_lcd_rgb888()) {
        printf("支持RGB888格式\n");
    }
    
    /* 根据屏幕格式选择合适的显示方式 */ 
    if (is_lcd_rgb565()) {
        /* 使用RGB565格式显示 */ 
        printf("将使用RGB565格式进行显示\n");
    } else if (is_lcd_rgb888()) {
        /* 使用RGB888格式显示 */ 
        printf("将使用RGB888格式进行显示\n");
    } else {
        printf("未知屏幕格式，使用默认设置\n");
    }
    
    return 0;
}