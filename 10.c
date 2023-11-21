// 应用 8255A 扩展单片机的 I/O 口，将 8255A 的 A 口设置为输出方式
// B 口设置为输入方式，实现通过 B 口的开关控制 A 口的发光二极管亮/灭的功能

#include <reg51.h>
#include <absacc.h>
#define add XBYTE[0x0000] // 定义片外首地址
// 下面三个不用记，会给
// A 口地址 0x7cff
// B 口地址 0x7dff
// 控制字地址 0x7fff
void main()
{
    unsigned char port_data;
    unsigned char xdata *pt; // 宏定义片外指针
    pt = &add;               // pt 指向片外首地址
    *(pt + 0x7fff) = 0x82;
    // 控制字, 0x82 = 1000 0010, 设置A为输出方式，B为输入方式
    // 如果是A入B出，就是0x28
    while (1)
    {
        port_data = *(pt + 0x7dff);
        // 读取B口数据, 输入到port_data里
        *(pt + 0x7cff) = port_data;
        // 将port_data的值输出到A口
    }
}