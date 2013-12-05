#include "stdio.h"
//#include "STARTUP.A51"
#include "main.h"
#include <intrins.h>
#include <math.h>

//global for sound length
unsigned long int timerLen;
unsigned short int th0b, tl0b; //Backup for the high/low bit


//sleep uses these
unsigned int waitTime;

void T0ISR(void) interrupt 1
{
  SPKR = ~SPKR;
  
  TH0 = th0b;
  TL0 = tl0b;
  
  timerLen--;
  if( timerLen == 0 )
    TR0 = 0;
}

void T1ISR(void) interrupt 3
{
  if( --waitTime == 0 )
  {
    TR1 = 0;
  }
  
  TH1 = 0;
  TL1 = 0;
}


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

//pitch: 0-509, above about 300 is actually like a tone
void sound( unsigned int pitch, unsigned long ms ) //pitch is in hz
{
  unsigned char period = floor(pitch/2); //get the period for the timer
  
  // global length, this is the time in terms of the pitch
    //   in other words: the number of times we reload our timers
  timerLen = floor((ms*1000+16)/((unsigned long)period))*2;  
  th0b = TH0 = 0xFF-period;
  tl0b = TL0 = 0x00;
  
  TR0 = 1;
}

//ms => milliseconds
void msleep(unsigned long ms)
{  
  waitTime = floor(ms*2000/65536);
  //for 1 second, or 1k ms, do 1,000,000/65536 (cycles in timer)
  //and that's our length
  
  TH1 = 0x00;
  TL1 = 0x00;
  TR1 = 1;
  
  while( TR1 );
}

void startupSound()
{
    sound( 50, 500 );    
    msleep( 500 );
    
    sound( 100, 500 );    
    msleep( 500 );
    
    sound( 75, 500 );    
    msleep( 500 );
    
    sound( 45, 250 );    
    msleep( 500 );
    while( 1 );
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

  IEN0 = 0x82;
  ET0 = 1;
  ET1 = 1;
  TMOD = 0x11;

  startup();
}
