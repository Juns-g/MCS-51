// 单片机 6-14题 不使用中断的形式
#include <reg51.h>
void main()
{
    while (1)
    {
        TMOD = 0x05; // 计数器
        TH0 = (65536 - 100) / 256;
        TL0 = (65536 - 100) % 256;

        TR0 = 1; // 开启定时器
        while (TF0 == 0); // 等待中断, TF0是中断溢出标志位
        TF0 = 0;

        TR0 = 0; // 关闭定时器
        TMOD = 0x01; // 定时器
        TH0 = (65536 - 500) / 256;
        TL0 = (65536 - 500) % 256;
        TR0 = 1; // 开启定时器

        while (TF0 == 0);
        TF0 = 0;
        TR0 = 0;
    }
}