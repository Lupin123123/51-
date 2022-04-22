#include<reg51.h>
#define u8 unsigned char
#define u16 unsigned int

u8 seg_code[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
u8 dis[] = {0, 1, 2, 3, 4, 5, 6, 7};															   

void delayms(u16 ms)
{
	u8 i;
	while(ms--){
		for (i=0; i<123; i++);
	}
	return;
}

void main()
{
	u8 i=0;
	P0 = 0;
	P2 = 0;
	while(1)
	{
		P2 = dis[i];
		P0 = seg_code[i];
		delayms(500);
		P0 = 0;
		delayms(100);

		i++;
		if (i==8) i=0;
	}
}
