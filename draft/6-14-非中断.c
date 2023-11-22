#include <reg51.h>

void main()
{
  while (1)
  {
    TMOD = 0x05;
    TH0 = (65536 - 100) / 256;
    TL0 = (65536 - 100) % 256;
    TR0 = 1;

    while (TF0 == 0)
      ;
    TF0 = 0;

    TR0 = 0;
    TMOD = 0x01;
    TH0 = (65536 - 500) / 256;
    TH0 = (65536 - 500) % 256;
    TR0 = 1;

    while (TF0 == 0)
      ;
    TF0 = 0;
    TR0 = 0;
  }
}