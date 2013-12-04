#include "stdio.h"
//#include "STARTUP.A51"
#include "main.h"
#include <intrins.h>

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


void msleep(unsigned char ms)
{
	unsigned long us = 1000*ms;
	
	while (us--)
	{
		_nop_();
	}
}

void startupSound()
{
	// Need to write sound function using the timer
}

void lightDelay()
{
	msleep( 250 );
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
int main()
{
	// not sure how to set p0 and p1 to bi-directional
	TMOD = 0;
	TH0 = 0;
	TL0 = 0;
	printf("Hello World");
	startup();
	
	return 0;
}
