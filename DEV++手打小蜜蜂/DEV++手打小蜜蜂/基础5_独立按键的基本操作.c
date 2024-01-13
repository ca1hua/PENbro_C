#include "reg52.h"

sbit L1 = P0^0;
sbit L2 = P0^1;
sbit L3 = P0^2;
sbit L4 = P0^3;

sbit S7 = P3^0;
sbit S6 = P3^1;
sbit S5 = P3^2;
sbit S4 = P3^3;

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

//void Init()
//{
//	SelectHC573(4);
//	P0 = 0xff;
//	SelectHC573(5);
//	P0 = 0x00;
//}       //  是不是P0口被占用了 ？ 在上面已经被sbit定义了 

void Delay(unsigned int t)
{
	while(t--);
}

void KeyBoard()
{
	while(S7 == 0)
	{
		Delay(100);
		if(S7 == 0)
		{
			L1 = 0;
			while(S7 == 0);
			L1 = 1;
		}
	}
	
	while(S6 == 0)
	{
		Delay(100);
		if(S6 == 0)
		{
			L2 = 0;
			while(S6 == 0);
			L2 = 1;
		}
	}
	
	while(S5 == 0)
	{
		Delay(100);
		if(S5 == 0)
		{
			L3 = 0;
			while(S5 == 0);
			L3 = 1;
		}
	}
	
	while(S4 == 0)
	{
		Delay(100);
		if(S4 == 0)
		{
			L4 = 0;
			while(S4 == 0);
			L4 = 1;
		}
	}
}

void main()
{
//	Init();
	SelectHC573(4);
	while(1)
	{
		KeyBoard();
	}
}
