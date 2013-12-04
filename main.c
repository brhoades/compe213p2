#include "stdio.h"
//#include "STARTUP.A51"
#include "main.h"
#include <intrins.h>
#include <math.h>

//global for sound length
unsigned long timerLen = 0;
unsigned short int th0b = 0;
unsigned short int tl0b = 0;

void ledC( char num, bit state )
{
	switch( num )
	{
		case 1:
			led1 = state;
			break;
			
		case 2:
			led2 = state;
			break;
			
		case 3:
			led3 = state;
			break;
			
		case 4:
			led4 = state;
			break;
			
		case 5:
			led5 = state;
			break;
			
		case 6:
			led6 = state;
			break;
			
		case 7:
			led7 = state;
			break;
			
		case 8:
			led8 = state;
			break;
		
		case 9:
			led9 = state;
			break;
	}
}

void sound( unsigned int pitch, unsigned int ms ) //pitch is in hz
{
	unsigned int period = floor(pitch/2); //get the period for the timer
	
	// global length, this is the time in terms of the pitch
    //   in other words: the number of times we reload our timers
	timerLen = floor(ms*1000/pitch);	
	th0b = TH0 = (unsigned short int)( period >> 8 );
	tl0b = TL0 = (unsigned short int)( period & 0xFF );
	TR0 = 1;
}

void timer0_ISR (void) interrupt 1
{
	SPKR = !SPKR;
	if( timerLen-- == 0 )
	{
		TR0 = 0;
		return;
	}
	else
	{
		TH0 = th0b;
		TL0 = tl0b;
	}
}

void msleep(unsigned char ms)
{
	unsigned long us = floor(1000*ms/2-9); //div = 3 cyc, mult 3, sub 1, floor 2 or so
	
	while(us--)
	{
		_nop_();
	}
}

void usleep(unsigned int us)
{
	us = floor(us/2)-6; //floor is about 2 cycles and divide 3. sub 1
						//Divide / 2 since we do 2 ops a loop
						//
	
	while(us--)
	{
		_nop_();
	}
}

void startupSound()
{
	// Need to write sound function using the timer
	sound( 550, 1000 );
}

void lightDelay()
{
	msleep( 15 );
}

void hline()
{
	int i;
	
	for( i=0; i<NUMLEDS; i++ )
	{
		ledC( horizontalOrder[i], ON );
		lightDelay( );
		ledC( horizontalOrder[i], OFF );
	}
}

void rline()
{
	int i;
	
	for( i=NUMLEDS-1; i>=0; i-- )
	{
		ledC( horizontalOrder[i], ON );
		lightDelay( );
		ledC( horizontalOrder[i], OFF );
	}
}

void vline()
{
	int i;
	
	for( i=0; i<NUMLEDS; i++ )
	{
		ledC( verticalOrder[i], ON );
		lightDelay( );
		ledC( verticalOrder[i], OFF );
	}
}

void rvline()
{
	int i;
	
	for( i=NUMLEDS-1; i>=0; i-- )
	{
		ledC( verticalOrder[i], ON );
		lightDelay( );
		ledC( verticalOrder[i], OFF );
	}
}

void flashleds()
{
	int counter = 5, i;
	while(counter != 0)
	{
		for( i=0; i<NUMLEDS; i++ )
		{
			ledC( verticalOrder[i], ON );
		}
		lightDelay();
		for( i=0; i<NUMLEDS; i++ )
		{
			ledC( verticalOrder[i], OFF );
		}
		lightDelay();
		counter--;
	}
}

void startup()
{
	startupSound();
	hline(); // horizontal line
	rline(); // line that goes back to led1
	vline(); // vertical line
	rvline(); // vertical line that goes back to led1
	flashleds(); // flashes leds 5x
}

void mainloop()
{
}

void main( void )
{
	//Set P1-P3 to bidirectional
	P0M1 = 0x00;
	P1M1 = 0x00;
	P2M1 = 0x00;
	
	EA = 1;
	//IE = 0x82;
	//Setup timers
	TMOD = 0x02;
	TH0 = 0;
	TL0 = 0;
	
	//printf("Hello World");
	startup();

	while(1 == 1)
	{
	}
}
