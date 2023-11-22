#include <reg51.h>
#include <absacc.h>
#define add XBYTE[0x0000];

void main()
{
  unsigned char port_data;
  unsigned char xdata *pt;

  pt = &add;
  *(pt + 0x7fff) = 0x82;

  while (1)
  {
    port_data = *(pt + 0x7dff);
    *(pt + 0x7cff) = port_data;
  }
}