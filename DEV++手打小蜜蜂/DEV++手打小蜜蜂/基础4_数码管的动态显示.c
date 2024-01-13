#include "reg52.h"

unsigned char arr[18] = 
	 {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
     0x80,0x90,0x88,0x80,0xc6,0xc0,0x86,0x8e,
     0xbf,0x7f};

void SelectHC573(unsigned char channel)
{
	switch(channel)
	{
		case 4: P2 = (P2 & 0x1f) | 0x80; break;
		case 5: P2 = (P2 & 0x1f) | 0xa0; break;
		case 6: P2 = (P2 & 0x1f) | 0xc0; break;
		case 7: P2 = (P2 & 0x1f) | 0xe0; break;
	}
}

void Init()
{
	SelectHC573(4);
	P0 = 0xff;
	SelectHC573(5);
	P0 = 0x00;
}

void Delay(unsigned int t)
{
	while(t--);
}

void SMG_Display(unsigned char n,unsigned char pos)
{
	SelectHC573(6);
	P0 = 0x01 << pos;
	SelectHC573(7);
	P0 = arr[n];
}


unsigned char s = 0;
unsigned char g = 0;
void SMG_Working()
{
		SMG_Display(2,0);
		Delay(500);
		SMG_Display(0,1);
		Delay(500);
		SMG_Display(2,2);
		Delay(500);
		SMG_Display(4,3);
		Delay(500);
		SMG_Display(16,4);
		Delay(500);
		SMG_Display(16,5);
		Delay(500);
		SMG_Display(s,6);
		Delay(500);
		SMG_Display(g,7);
		Delay(500);
}

void DelayMain(unsigned int  t1)
{
		while(t1--)
		{
			SMG_Working();
		}
}

unsigned char m = 1;
void main()
{
	Init();
	while(1)
	{
		
		s = m / 10;
		g = m % 10;
		m++;
		if(m > 12)
		{
			m = 1;
		}
		DelayMain(200);
		SMG_Working();
	}
} 
