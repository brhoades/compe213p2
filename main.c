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
