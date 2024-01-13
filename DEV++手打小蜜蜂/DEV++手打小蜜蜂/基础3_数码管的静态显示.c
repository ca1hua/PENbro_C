#include "reg52.h"

unsigned char arr[18] =
{    0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
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
	while(t--);
}

void SMG_Display(unsigned char n,unsigned char pos)
{
	SelectHC573(6);
	P0 = 0x01 << pos;
	SelectHC573(7);
	P0 = arr[n];
}

unsigned char i = 0;
unsigned char j = 0;
void SMG_Working()
{
	for(i = 0;i < 8;i++)  //0000 0001
	{
		for(j = 0;j < 16; j++)
		{
			SMG_Display(j ,i);
			Delay(60000);
			Delay(60000);

		}
	}	
	
	SelectHC573(6);
	P0 = 0xff;
	SelectHC573(7);
	for(j = 0;j < 16; j++)
		{
			P0 = arr[j];
			Delay(60000);
			Delay(60000);
		}
}


void main()
{
	Init();
	while(1)
	{
		SMG_Working();
	}	
} 
