#include "stdio.h"
//#include "STARTUP.A51"
//#include <reg932.h>
#include <reg51.h>
#include <stdlib.h>
#include <string.h>
// Initialize all the lights for the program
sbit led1 = P2^4;
sbit led2 = P0^5; // Yellow
sbit led3 = P2^7; // Green
sbit led4 = P0^6; // Amber
sbit led5 = P1^6; // Blue
sbit led6 = P0^4; // Red
sbit led7 = P2^5; // Yellow
sbit led8 = P0^7; // Green
sbit led9 = P2^6; // Amber
// Set basic system bits

#define ON 0;
#define OFF 1;
void startupSound()
{
	// Need to write sound function using the timer
}
void lightDelay()
{
}
void  hline()
{
	led1 = ON;
	led1 = OFF;
	lightDelay();
	led2 = ON;
	led2 = OFF;
	lightDelay();
	led3 = ON;
	led3 = OFF;
	lightDelay();
	led4 = ON;
	led4 =  OFF;
	lightDelay();
	led5 = ON;
	led5 = OFF;
	lightDelay();
	led6 = ON;
	led6 = OFF;
	lightDelay();
	led7 = ON;
	led7 = OFF;
	lightDelay();
	led8 = ON;
	led8 = OFF;
	lightDelay();
	led9 = ON;
	led9 = OFF;
	lightDelay();
}
void rline()
{
	led9 = ON;
	led9 = OFF;
	lightDelay();
	led8 = ON;
	led8 = OFF;
	lightDelay();
	led7 = ON;
	led7 = OFF;
	lightDelay();
	led6 = ON;
	led6 = OFF;
	lightDelay();
	led5 = ON;
	led5 = OFF;
	lightDelay();
	led4 = ON;
	led4 = OFF;
	lightDelay();
	led3 = ON;
	led3 = OFF;
	lightDelay();
	led2 = ON;
	led2 = OFF;
	lightDelay();
	led1 = ON;
	led1 = OFF;
	lightDelay();
}
void vline()
{
	led1 = ON;
	led1 = OFF;
	lightDelay();
	led4 = ON;
	led4 = OFF;
	lightDelay();
	led7 = ON;
	led7 = OFF;
	lightDelay();
	led8 = ON;
	led8 = OFF;
	lightDelay();
	led5 = ON;
	led5 = OFF;
	lightDelay();
	led2 = ON;
	led2 = OFF;
	lightDelay();
	led3 = ON;
	led3 = OFF;
	lightDelay();
	led6 = ON;
	led6 = OFF;
	lightDelay();
	led9 = ON;
	led9 = OFF;
	lightDelay();
}
void rvline()
{
	led9 = ON;
	led9 = OFF;
	lightDelay();
	led6 = ON;
	led6 = OFF;
	lightDelay();
	led3 = ON;
	led3 = OFF;
	lightDelay();
	led2 = ON;
	led2 = OFF;
	lightDelay();
	led5 = ON;
	led5 = OFF;
	lightDelay();
	led8 = ON;
	led8 = OFF;
	lightDelay();
	led7 = ON;
	led7 = OFF;
	lightDelay();
	led4 = ON;
	led4 = OFF;
	lightDelay();
	led1 = ON;
	led1 = OFF;
	lightDelay();
}
void flashleds()
{
	int counter = 10;
	while(counter != 0)
	{
		led1 = ON;
		led1 = OFF;
		led2 = ON;
		led2 = OFF;
		led3 = ON;
		led3 = OFF;
		led4 = ON;
		led4 = OFF;
		led5 = ON;
		led5 = OFF;
		led6 = ON;
		led6 = OFF;
		led7 = ON;
		led7 = OFF;
		led8 = ON;
		led8 = OFF;
		led9 = ON;
		led9 = OFF;
		counter--;
	}
	lightDelay();
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
