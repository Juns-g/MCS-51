#include <reg51.h>

sbit pwm = P1 ^ 0;
int counter = 0;

void main()
{
  TMOD = 0x01;
  TH0 = (65536 - 50000) / 256;
  TL0 = (65536 - 50000) % 256;
  TR0 = 1;

  EA = 1;
  ET0 = 1;

  pwm = 1;

  while (1)
    ;
}

void timer() interrupt 1
{
  TH0 = (65536 - 100) / 256;
  TL0 = (65536 - 100) / 256;

  counter++;

  if (counter == 4)
  {
    pwm = 0;
  }
  else if (counter == 10)
  {
    counter = 0;
    pwm = 1;
  }
}
