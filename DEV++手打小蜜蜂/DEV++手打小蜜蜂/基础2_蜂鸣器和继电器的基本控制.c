#include "reg52.h"
void SelectHC573(unsigned char n)
{
	switch(n)
	{
		case 4:
		P2 = (P2 & 0x1f) | 0x80;  break;
		case 5:
		P2 = (P2 & 0x1f) | 0xa0;  break;
		case 6:
		P2 = (P2 & 0x1f) | 0xc0;  break;
		case 7:
		P2 = (P2 & 0x1f) | 0xe0;  break;
	}
} 

void InitLED()
{
	SelectHC573(4);
	P0 = 0xff;
	SelectHC573(5);
	P0 = 0x00;            //0000 1010
}

void Delay(unsigned int t)
{
	while(t--);
}

unsigned char i = 0;
void LEDWorking()
{
	SelectHC573(4);
	for(i = 1; i <= 3;i++)
	{
	P0 = 0x00;
	Delay(50000);
	Delay(50000);
	P0 = 0xff;
	Delay(50000);
	Delay(50000);		
	}

	
	for(i = 1; i <= 8;i++)  // 1111 1111  low
	{
		P0 = 0xff << i;
		Delay(50000);
		Delay(50000);
	}
	SelectHC573(5);
	P0 = 0x40; //0000 1010
	Delay(50000);
	Delay(50000);
	P0 = 0x00; //0000 1010
	SelectHC573(4);
	for(i = 1; i <= 8;i++)  // 1111 1110  low   0000 0001
	{
		P0 = ~(0xff << i);
		Delay(50000);
		Delay(50000);
	}
	SelectHC573(5);
	P0 = 0x10; //0000 1010
	Delay(50000);
	Delay(50000);
	P0 = 0x00; //0000 1010
}

void main()
{
	InitLED();
	while(1)
	{
	LEDWorking();	
	}
}
