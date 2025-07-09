# LCD屏幕参数获取库 - 使用说明文档

## 概述

`get_lcd_size`库提供了一组函数用于检测和获取LCD显示屏的关键参数，包括屏幕宽度、高度、每像素位数(bpp)，以及检查显示屏是否支持RGB565和RGB888颜色格式。

## 功能特性

- 自动检测LCD屏幕参数
- 支持获取屏幕宽度、高度和位深度
- 支持检测RGB565和RGB888颜色格式
- 自动初始化机制
- 提供默认值以防检测失败

## API参考

### `get_lcd_width`

```c
int get_lcd_width(void);
```

**功能**: 获取LCD屏幕宽度(像素)

**返回值**:
- 成功: LCD屏幕宽度(像素)
- 失败: 默认值1024

### `get_lcd_height`

```c
int get_lcd_height(void);
```

**功能**: 获取LCD屏幕高度(像素)

**返回值**:
- 成功: LCD屏幕高度(像素)
- 失败: 默认值600

### `get_lcd_bpp`

```c
int get_lcd_bpp(void);
```

**功能**: 获取LCD位深度

**返回值**:
- 成功: LCD位深度(16/24/32位)
- 失败: 默认值16(RGB565)

### `is_lcd_rgb565`

```c
int is_lcd_rgb565(void);
```

**功能**: 检查LCD是否支持RGB565格式

**返回值**:
- 支持: 1
- 不支持: 0
- 检测失败: 默认返回1(假设支持RGB565)

### `is_lcd_rgb888`

```c
int is_lcd_rgb888(void);
```

**功能**: 检查LCD是否支持RGB888格式

**返回值**:
- 支持: 1
- 不支持: 0
- 检测失败: 默认返回0(假设不支持RGB888)

## 使用示例

```c
#include "get_lcd_size.h"
#include <stdio.h>

int main() {
    printf("LCD屏幕参数:\n");
    printf("宽度: %d 像素\n", get_lcd_width());
    printf("高度: %d 像素\n", get_lcd_height());
    printf("位深度: %d 位\n", get_lcd_bpp());
    
    if (is_lcd_rgb565()) {
        printf("支持RGB565格式\n");
    }
    
    if (is_lcd_rgb888()) {
        printf("支持RGB888格式\n");
    }
    
    return 0;
}
```

## 编译说明

1. 将`get_lcd_size.c`和`get_lcd_size.h`添加到您的项目中
2. 在需要使用的源文件中包含头文件`#include "get_lcd_size.h"`
3. 编译时链接相关库(可能需要`-lm`等选项)

示例编译命令:
```bash
arm-linux-gnueabihf-gcc -c get_lcd_size.c -o get_lcd_size.o
arm-linux-gnueabihf-ar rcs libget_lcd_size.a get_lcd_size.o
arm-linux-gnueabihf-gcc get_lcd_size_demo.c -L. -lget_lcd_size -o get_lcd_size_demo
```

## 注意事项

1. 使用此库需要保留原作者署名信息
2. 此库需要访问`/dev/fb0`设备文件，确保程序有足够的权限
3. 如果检测失败，函数会返回默认值，请根据实际情况判断是否需要处理错误情况
4. 此库仅适用于Linux系统
