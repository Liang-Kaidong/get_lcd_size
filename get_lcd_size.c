/*************************************************************************************************************
File name: get_lcd_size.c
Author: KD
Version: V_1.0
Build date: 2025-07-07
Description: The C file get_lcd_size.c provides a set of functions to detect and obtain key parameters of the 
             LCD display, including the screen width, height, and bits per pixel. It can also check whether 
             the display supports RGB565 and RGB888 color formats. If the parameters are not initialized, the 
             functions will automatically attempt to initialize them.
Others: Usage requires preservation of original author attribution.
*************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include "get_lcd_size.h"

/* LCD屏幕宽度 */
static int lcd_width = 0;

/* LCD屏幕高度 */
static int lcd_height = 0;

/* LCD位深度(16/24/32位) */
static int lcd_bpp = 0;

/* 是否已初始化标志 */
static int is_initialized = 0;

/*
* 初始化并探测LCD参数
* @return 成功返回0，失败返回-1
*/
static int init_lcd_params(void) {
    int fd;
    struct fb_var_screeninfo vinfo;
    
    /* 打开帧缓冲设备 */
    fd = open("/dev/fb0", O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "无法打开帧缓冲设备\n");
        return -1;
    }
    
    /* 获取可变屏幕信息 */
    if (ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) < 0) {
        fprintf(stderr, "无法获取屏幕信息\n");
        close(fd);
        return -1;
    }
    
    /* 保存屏幕参数 */
    lcd_width = vinfo.xres;
    lcd_height = vinfo.yres;
    lcd_bpp = vinfo.bits_per_pixel;
    
    /* 打印LCD信息 */
    printf("成功获取LCD参数:\n");
    printf("  分辨率: %dx%d\n", lcd_width, lcd_height);
    printf("  位深度: %d位\n", lcd_bpp);
    
    /* 判断颜色格式 */
    const char *format;
    if (lcd_bpp == 16) {
        format = "RGB565";
    } else if (lcd_bpp == 24) {
        format = "RGB888";
    } else if (lcd_bpp == 32) {
        format = "ARGB8888";
    } else {
        format = "未知";
    }
    printf("  颜色格式: %s\n", format);
    
    /* 标记已初始化 */
    is_initialized = 1;
    
    close(fd);
    return 0;
}

/*
* 检查是否已初始化
* @return 已初始化返回1，否则返回0
*/
static int check_initialized(void) {
    if (!is_initialized) {
        if (init_lcd_params() != 0) {
            return 0;
        }
    }
    return 1;
}

/*
* 获取LCD宽度
* @return LCD宽度(像素)，失败时返回默认值1024
*/
int get_lcd_width(void) {
    if (check_initialized()) {
        return lcd_width;
    }
    return 1024;  /* 默认值 */ 
}

/*
* 获取LCD高度
* @return LCD高度(像素)，失败时返回默认值600
*/
int get_lcd_height(void) {
    if (check_initialized()) {
        return lcd_height;
    }
    return 600;  /* 默认值 */
}

/*
* 获取LCD位深度
* @return LCD位深度(16/24/32)，失败时返回默认值16(RGB565)
*/
int get_lcd_bpp(void) {
    if (check_initialized()) {
        return lcd_bpp;
    }
    return 16;  /* 默认值(RGB565) */ 
}

/*
* 检查LCD是否支持RGB565格式
* @return 支持返回1，否则返回0
*/
int is_lcd_rgb565(void) {
    if (check_initialized()) {
        return (lcd_bpp == 16);
    }
    return 1;  /* 默认假设为RGB565 */ 
}

/*
* 检查LCD是否支持RGB888格式
* @return 支持返回1，否则返回0
*/
int is_lcd_rgb888(void) {
    if (check_initialized()) {
        return (lcd_bpp == 24 || lcd_bpp == 32);
    }
    return 0;  /* 默认假设不支持RGB888 */ 
}