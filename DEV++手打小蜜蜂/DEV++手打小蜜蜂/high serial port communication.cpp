#include "reg52.h"

sfr AUXR = 0x8e;

void SelectHC573(unsigned char channel)
{
	switch(channel)
	{
		case 4:
			P2 = (P2 & 0x1f) | 0x80;break;
		case 5:
			P2 = (P2 & 0x1f) | 0xa0;break;
		case 6:
			P2 = (P2 & 0x1f) | 0xc0;break;
		case 7:
			P2 = (P2 & 0x1f) | 0xe0;break;
		case 8:
			P2 = (P2 & 0x1f) | 0x00;break;
	}
}

void InitSystem()
{
	SelectHC573(5);
	P0 = 0x00;
	SelectHC573(4);
	P0 = 0xff;

	
}

void InitUart()
{
	TMOD = 0x20;
	TH1 = 0xfd;
	TL1 = 0xfd;
	TR1 = 1;
	
	SCON = 0x50;
	AUXR = 0x00;
	ES = 1;
	EA = 1;
}

unsigned char comman = 0x00;
void ServiceUart() interrupt 4
{
	if(RI == 1)
	{
		comman = SBUF;
		RI = 0;
	}
	
}

void SendByte(unsigned char dat)
{
	SBUF = dat;
	while(TI == 0);
	TI = 0;
}

void SendString(unsigned char *str)
{
	while(*str != '\0')
	{
		SendByte(*str++);
	}
}

void Working()
{
	if(comman != 0x00)
	{
		switch(comman & 0xf0)
		{
			case 0xa0:
					P0 = (P0 | 0x0f) & (~comman | 0xf0);
				break;
				
			case 0xb0:
				P0 = (P0 | 0xf0) & ((~comman << 4)| 0x0f);
					comman = 0x00;
				break;
				
			case 0xc0:
					SendString("hello world!\r\n");
					comman = 0x00;
				break;
		}
	}
}

void main()
{
	InitSystem();
	InitUart();
	SendString("hello world!\r\n");
	while(1)
	{
		Working();
	}
}
