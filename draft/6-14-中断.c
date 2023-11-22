#include <reg51.h>
unsigned int flag = 0;

void main()
{
  TMOD = 0x05;
  TH0 = (65536 - 100) / 256;
  TL0 = (65536 - 100) % 256;

  EA = 1;  // 开启中断
  ET0 = 1; // 计数器0中断
  TR0 = 1; // 启动计数器
  while (1)
    ;
}

void timer() interrupt 1
{
  TR0 = 0;
  if (flag == 0)
  {
    TMOD = 0x01;
    TH0 = (65536 - 500) / 256;
    TL0 = (65536 - 500) % 256;
  }
  else
  {
    TMOD = 0x05;
    TH0 = (65536 - 100) / 256;
    TL0 = (65536 - 100) % 256;
  }
  TR0 = 1;
  flag = ~flag;
}