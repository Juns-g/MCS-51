#include <reg51.h>

void main()
{
  SM0 = 0;
  SM1 = 1;
  REN = 1;
  PCON = 0;

  TMOD = 0x20;
  TH1 = 0xfd;
  TL1 = 0xfd;
  TR1 = 1;

  while (1)
  {
    while (RT == 0)
      ;
    RT = 0;

    P1 = SBUF;
    SBUF = P1;

    while (TI == 0)
      ;
    TI = 0;
  }
}