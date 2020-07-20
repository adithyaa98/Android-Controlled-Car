// this program works for HC-05 bluetooth module by interfacing with 8051 microcontroller
#include<reg51.h>
sbit m1p=P2^0 ;
sbit m1n=P2^1;
sbit m2p=P2^2;
sbit m2n=P2^3;
// motor inputs connections//
void main()
{
 unsigned char x;
 SCON=0x50;
 TMOD=0x20;
 TH1=-3;
 TR1=1; //Intialize serial conditions//
 while (1)
 {
    while (RI==0) //indicating SBUF is ready
	x=SBUF;
	RI=0; // clear ri to recieve the next bit from the module
	SBUF=x;
	while (TI==0);
	TI=0;
	if(x=='f')
	{
	  	m1p=1;m1n=0; // motor rotates in clockwise direction
		m2p=1;m2n=0;
	}
	if(x=='b')
	{
	  	m1p=0;m1n=1; // motor rotates in anti-clockwise direction
		m2p=0;m2n=1;
	}
	if(x=='l')
	{
	  	m1p=1;m1n=0; // motor rotates in clockwise direction
		m2p=0;m2n=1; // motor rotates in anti-clockwise direction
	}
	if(x=='r')
	{
	  	m1p=0;m1n=1; // motor rotates in anti-clockwise direction
		m2p=1;m2n=0; // motor rotates in clockwise direction
	}
	 if(x=='s')
	{
	  	m1p=0;m1n=0; // no movement in motor
		m2p=0;m2n=0; 
	}
 }
}