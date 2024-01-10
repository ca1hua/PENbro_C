#include "reg52.h"

sbit L1 = P0^0;
sbit S7 = P3^0;

void SelectHC573()
{
	P2 = (P2 & 0x1f) | 0x80;
}

unsigned char count = 0;
unsigned char duty = 0;
void InitTimer0()
{
	TMOD = 0x01;
	TH0 = (65535 - 100)/256;
	TL0 = (65535 - 100)%256;
	
	ET0 = 1;
	EA = 1;
}

void SreviceTimer0() interrupt 1
{
	TH0 = (65535 - 100)/256;
	TL0 = (65535 - 100)%256;
	
	count++;
	if(count <= duty)
	{
		L1 = 0;
	}
	else if(count < 100)
	{
		L1 = 1;
		
	}
	else if(count == 0)
	{
	L1 = 0;
	count = 0;	
	}
	
}


void Delay(unsigned int t)
{
	while(t--);
}

unsigned char state = 0;
void ScanKeys()
{
	if(S7 == 0)
	{
		Delay(100);
		if(S7 == 0)
		{
			switch(state)
			{
				case 0:
					L1 = 0;
					TR0 = 1;
					duty = 10;
					state = 1;
					break;
					
				case 1:
				duty = 50;
				state = 2;
				break;	
				
				case 2:
				duty = 90;
				state = 3;
				break;
				
				case 3:
				L1 = 1;
				TR0 = 0;
				state = 0;
				break;
			}
			while(S7 == 0);
		}
	}
}

void main()
{
	SelectHC573();
	InitTimer0();
	while(1)
	{
		ScanKeys();
	}	
}
