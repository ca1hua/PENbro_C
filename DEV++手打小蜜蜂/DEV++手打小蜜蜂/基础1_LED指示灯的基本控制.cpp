#include "reg52.h"
void SelectHC573()
{
	P2 = (P2 & 0x1f) | 0x80; // 4        a c e
} 

void InitLED()
{
	P0 = 0xff;
}

void Delay(unsigned int t)
{
	while(t--);
}

unsigned char i = 0;
void LEDWorking()
{
	SelectHC573();
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
	for(i = 1; i <= 8;i++)  // 1111 1110  low   0000 0001
	{
		P0 = ~(0xff << i);
		Delay(50000);
		Delay(50000);
	}
	
}

void main()
{
	InitLED();
	while(1)
	{
	LEDWorking();	
	}
}
