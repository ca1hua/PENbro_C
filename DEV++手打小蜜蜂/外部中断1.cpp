#include "reg52.h"

sbit L1 = P0^0;
sbit L8 = P0^7;

void Delay(unsigned int t)
{
	while(t--);
	while(t--);
	while(t--);
}

void SelectHC573()
{
	P2 = (P2 & 0x1f) | 0x80;
}

void Working()
{
	SelectHC573();
	L1 = 0;
	Delay(60000);
	L1 = 1;
	Delay(60000);
}

void Init_INT0()
{
	IT0 = 1;
	EX0 = 1;
	EA = 1;
}

void ServiceINT0() interrupt 0
{
	SelectHC573();
	L8 = 0;
	Delay(60000);
	Delay(60000);
	L8 = 1;
	Delay(60000);
	Delay(60000);
}

void main()
{
	
			
	while(1)
	{
	Init_INT0();
	Working();
	}
	
}
