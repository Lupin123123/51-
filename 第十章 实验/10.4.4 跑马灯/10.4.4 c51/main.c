#include"reg52.h"

#define u8 unsigned char
#define u16 unsigned int

u16 a[] = {0xff, 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};

void delayms(u16 ms)
{
	u8 i;
	while(ms--)
		for (i=0; i<123; i++);
}

//void main()
//{
//	while(1)
//	{
//		u8 i;
//		for (i=1; i<=8; i++)
//		{
//			P1 = a[i];
//			delayms(500);
//			if (i==8) i=-1;
//		}
//	}
//	return;
//}

void main()
{
	P1 = 0xfe;
	while(1)
	{
		delayms(500);
		P1 <<= 1;
		P1 |= 0x01;
		if (P1==0x7f)
		{
			delayms(500);
			P1 = 0xfe;
		}
	}
}