#include<reg52.h>

#define u8 unsigned char
#define u16 unsigned int

void delayms(u16 ms)
{
	u8 i;
	while(ms--)
		for (i=0; i<123; i++);
}

void int0(void) interrupt 0 using 0
{
	P1 = 0x0f;
	delayms(800);
	P1 = 0xf0;
	delayms(800);
}

void main(void)
{ 	
	EA = 1;
	EX0 = 1;
	IT0 = 1;
	while(1)
	{
		P1 = 0;
	}
} 