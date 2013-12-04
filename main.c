#include "stdio.h"
//#include "STARTUP.A51"
//#include "reg932.h"
#include "main.h"

void startupSound()
{
	// Need to write sound function using the timer
}

void lightDelay()
{
}

void upline()
{
	int i;
	
	for( i=1; i<=NUMLIGHTS; i++ )
	{
		leds[i] = ON;	
		lightDelay( );
		leds[i] = OFF;
	}
}

void downline()
{
	int i;
	
	for( i=NUMLIGHTS; i>0; i-- )
	{
		leds[i] = ON;	
		lightDelay( );
		leds[i] = OFF;
	}
}

void leftline()
{
	for( i=1; i<=NUMLIGHTS; i++)
	{
		horizontalLeds[i] = ON;	
		lightDelay( );
		horizontalLeds[i] = OFF;
	}
}
void rightline()
{
	for( i=NUMLIGHTS; i>0; i-- )
	{
		horizontalLeds[i] = ON;	
		lightDelay( );
		horizontalLeds[i] = OFF;
	}
}
void flashleds()
{
	int counter = 10, i;
	
	while(counter != 0)
	{
		for( i=1; i<=NUMLIGHTS; i++ )
		{
			leds[i] = ON;
		}
		lightDelay( )
		
		for( i=1; i<=NUMLIGHTS; i++ )
		{
			leds[i] = OFF;
		}
		
		counter--;
	}
	
	lightDelay();
}
void startup()
{
	startupSound();
	upline(); // vertical
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
