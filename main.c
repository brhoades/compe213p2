//CompE 213 Project 2
//Billy Rhoades
//Dane Greer
//Michael Jolley
//
//Main Program Code

#include "stdio.h"
//#include "STARTUP.A51"
#include <intrins.h>
#include <math.h>

#include "main.h"

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
  sound( 60, 500 );    
  ledC( 1, ON );
  msleep( 750 );
  
  sound( 120, 500 );    
  ledC( 7, ON );
  ledC( 5, ON );
  ledC( 3, ON );
  msleep( 750 );
  
  sound( 75, 500 );   
  ledC( 9, ON );
  msleep( 750 );
  
  sound( 45, 500 );    
  ledC( 2, ON );
  ledC( 4, ON );
  ledC( 8, ON );
  ledC( 6, ON );
  msleep( 750 );
  
  TR0 = 0;
}

void lightDelay()
{
  msleep( 200 );
}

void hline()
{
  char i;
  
  for( i=0; i<NUMLEDS; i++ )
  {
    ledC( horizontalOrder[i], ON );
    lightDelay( );
    ledC( horizontalOrder[i], OFF );
  }
}

void rline()
{
  char i;
  
  for( i=NUMLEDS-1; i>=0; i-- )
  {
    ledC( horizontalOrder[i], ON );
    lightDelay( );
    ledC( horizontalOrder[i], OFF );
  }
}

void vline()
{
  char i;
  
  for( i=0; i<NUMLEDS; i++ )
  {
    ledC( verticalOrder[i], ON );
    lightDelay( );
    ledC( verticalOrder[i], OFF );
  }
}

void rvline()
{
  char i;
  
  for( i=NUMLEDS-1; i>=0; i-- )
  {
    ledC( verticalOrder[i], ON );
    lightDelay( );
    ledC( verticalOrder[i], OFF );
  }
}

void flashleds()
{
  static char counter = 2, i;
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

char getSwNum( )
{
  if(!sw1)
    return 0;
  else if(!sw2)
    return 1;
  else if(!sw3)
    return 2;
  else if(!sw4)
    return 3;
  else if(!sw5)
    return 4;
  else if(!sw6)
    return 5;
  else if(!sw7)
    return 6;
  else if(!sw8)
    return 7;
  else if(!sw9)
    return 8;
  
  return -1;
}

void simonSays()
{
  char aSpot = 0, button, gDurr = 3, gNow, swSpot = 0;		  
  idata char gArr[MAXGAMES]; 
        
  while(gDurr != MAXGAMES)
  {
    gNow = gDurr;

    // This loop adds on to the top
    do
    {
      button = (char)(rand() % 9); //returns [0,8]
      gArr[aSpot] = button;
      aSpot++;
    }
    while(aSpot != gDurr);

    //tell them what to push, the whole way through
    //previous way was showing only the new one
    for( aSpot=0; aSpot<gDurr; aSpot++ )
    {
      //Give them some time to see what we're doing.
      ledC( gArr[aSpot]+1, ON );
      sound( (gArr[aSpot]+1)*SOUNDRANGE, 50 );
      
      //As game goes on (gdurr increases), decrease the time between showing.
      msleep( floor( 1500 - ( 500 * ( 1 - ( MAXGAMES - gDurr ) / MAXGAMES ) ) ) );
      TR0 = 0; //cut the sound
      
      ledC( gArr[aSpot]+1, OFF );
    }
    
    //put our index back at 0 and ask the user to do input
    aSpot = 0;

    //this loop is when the user puts in the numbers
    do
    {
      //change to the buttons function
      //because of active low if thw Switch = 1 it is not being pushed
      //wait forever until they do something
      while( getSwNum( ) == -1 );
      swSpot = getSwNum( );      

      ledC(swSpot+1, ON);
      sound( (gArr[aSpot]+1)*SOUNDRANGE, 30 ); //make the button's sound
      
      if( swSpot == gArr[aSpot] )
      {
        //wait until they let go
        while( getSwNum( ) == gArr[aSpot] );
        msleep( 500 );
        
        TR0 = 0; //cut the sound
        
        ledC(swSpot+1, OFF);
      
        aSpot++;

        if( aSpot >= gDurr)
        {  
          victory();
          gDurr++;
          msleep( 1000 );
        }
      }
      else
      {
        //cut the sound after a second
        msleep( 1000 );
        TR0 = 0;
        ledC(swSpot+1, OFF);
        //wait
        msleep( 500 );
        
        failure( gArr[aSpot]+1 );
        return;  
      } 
        
    }while(gDurr == gNow);
    
  }
  
  return;
}

void victory( )
{
   ledC( 1, ON);
   lightDelay();
   ledC( 2, ON);
   lightDelay();
   ledC( 3, ON);
   lightDelay();
   ledC( 6, ON);
   lightDelay();
   ledC( 9, ON);
   lightDelay();
   ledC( 8, ON);
   lightDelay();
   ledC( 7, ON);
   lightDelay();
   ledC( 4, ON);
   lightDelay();
   lightDelay();
   lightDelay();

   ledC( 1, OFF);
   ledC( 2, OFF);
   ledC( 3, OFF);
   ledC( 4, OFF);
   ledC( 6, OFF);
   ledC( 7, OFF);
   ledC( 8, OFF);
   ledC( 9, OFF);

   return;

}

void failure( char correct )
{
 char i;

  ledC( 1, ON);
  ledC( 3, ON);
  ledC( 5, ON);
  ledC( 7, ON);
  ledC( 9, ON);

  sound(290, 50);
  msleep(2500);
  TR0 = 0;

  ledC( 1, OFF);
  ledC( 3, OFF);
  ledC( 5, OFF);
  ledC( 7, OFF);
  ledC( 9, OFF);

  for( i=0; i<2; i++ )
  {
    ledC( correct, ON );
    sound( correct*SOUNDRANGE, 30 ); //make the button's sound
    msleep( 1000 );
    ledC( correct, OFF );
    TR0 = 0;
    msleep( 500 );
  }


  TR0 = 0;

  return;
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

  //startup();
  
  while( 1 )
  {
    unsigned int i = 0;
	i = 0;

    //Get them to hit sw8 to start.
    //While we wait, count the number of cycles (and keep rolling over)
    // and use that as our seed.
    // Using a 50 ms delay, 50 times, so we appear really responsive to button presses.
    while( sw8 )
    {
      if( i > STARTUPRANGE * 50 )
        i = 0;

      if( i % 50 == 0 )
      {
        if( i >= 50 )
          ledC( startOrder[i/50-1], OFF );
        else
          ledC( startOrder[STARTUPRANGE-1], OFF );

        ledC( startOrder[i/50], ON );
      }

      i++;
      msleep( 50 );
    }


    srand( i );
    for( i=0; i<NUMLEDS; i++ )
    {
      ledC( horizontalOrder[i], OFF );
    }
    simonSays();
  }
}
