#include "reg52.h"

sfr P4 = 0xc0;

unsigned char arr[19] ={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
     0x80,0x90,0x88,0x80,0xc6,0xc0,0x86,0x8e,
     0xbf,0x7f,0xff};

sbit R1 = P3^0;
sbit R2 = P3^1;
sbit R3 = P3^2;
sbit R4 = P3^3;

sbit C4 = P3^4;
sbit C3 = P3^5;
sbit C2 = P4^2;
sbit C1 = P4^4;

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

void DisplaySMG_Bit(unsigned char n,unsigned char pos)
{
	SelectHC573(6);
	P0 = 0x01 << pos;
	SelectHC573(7);
	P0 = arr[n];
}

void DelaySMG(unsigned int t)
{
	while(t--);
}

void Display_Dynamic(unsigned char yu)
{
	DisplaySMG_Bit(yu/10,0);
	DelaySMG(500);
	DisplaySMG_Bit(yu%10,1);
	DelaySMG(500);
	DisplaySMG_Bit(18,2);
	DelaySMG(500);
	DisplaySMG_Bit(18,3);
	DelaySMG(500);
	
	DisplaySMG_Bit(18,4);
	DelaySMG(500);
	DisplaySMG_Bit(18,5);
	DelaySMG(500);
	
	DisplaySMG_Bit(18,6);
	DelaySMG(500);
	DisplaySMG_Bit(18,7);
	DelaySMG(500);
}


unsigned char flag = 0;
unsigned char key_num;
void Working()
{
	R1 = 0;
	R2 = R3 = R4 = 1;
	C1 = C2 = C3 = C4 = 1;
	if(C1 == 0)
	{
		
		key_num = 0;
		flag = 1;
		while(C1 == 0);
		while(flag == 1&& C1 == 1)
		{
			Display_Dynamic(key_num);
		}
	}
	else if(C2 == 0)
	{
		
		key_num = 1;
		flag = 1;
		while(C2 == 0);
		while(flag == 1 && C2 == 1)
		{
			Display_Dynamic(key_num);
		}
	}
	else if(C3 == 0)
	{
		while(C3 == 0);
		key_num = 2;
		Display_Dynamic(key_num);
	}
	else if(C4 == 0)
	{
		while(C4 == 0);
		key_num = 3;
		Display_Dynamic(key_num);
	}
	
	R2 = 0;
	R1 = R3 = R4 = 1;
	C1 = C2 = C3 = C4 = 1;
	if(C1 == 0)
	{
		while(C1 == 0);
		key_num = 4;
		Display_Dynamic(key_num);
	}
	else if(C2 == 0)
	{
		while(C2 == 0);
		key_num = 5;
		Display_Dynamic(key_num);
	}
	else if(C3 == 0)
	{
		while(C3 == 0);
		key_num = 6;
		Display_Dynamic(key_num);
	}
	else if(C4 == 0)
	{
		while(C4 == 0)
		{
			
		}
		key_num = 7;
		Display_Dynamic(key_num);
	}
	
	R3 = 0;
	R2 = R1 = R4 = 1;
	C1 = C2 = C3 = C4 = 1;
	if(C1 == 0)
	{
		while(C1 == 0);
		key_num = 8;
		Display_Dynamic(key_num);
	}
	else if(C2 == 0)
	{
		while(C2 == 0);
		key_num = 9;
		Display_Dynamic(key_num);
	}
	else if(C3 == 0)
	{
		while(C3 == 0);
		key_num = 10;
		Display_Dynamic(key_num);
	}
	else if(C4 == 0)
	{
		while(C4 == 0);
		key_num = 11;
		Display_Dynamic(key_num);
	}
	
	R4 = 0;
	R2 = R1 = R3 = 1;
	C1 = C2 = C3 = C4 = 1;
	if(C1 == 0)
	{
		while(C1 == 0);
		key_num = 12;
		Display_Dynamic(key_num);
	}
	else if(C2 == 0)
	{
		while(C2 == 0);
		key_num = 13;
		Display_Dynamic(key_num);
	}
	else if(C3 == 0)
	{
		while(C3 == 0);
		key_num = 14;
		Display_Dynamic(key_num);
	}
	else if(C4 == 0)
	{
		while(C4 == 0);
		key_num = 15;
		Display_Dynamic(key_num);
	}
	
	
}

void main()
{
	Init();
	while(1)
	{
		Working();
	}
}
