#include "stdlib.h"


#define MAXGAMES 64

#define ON 1
#define OFF 0

// Speaker
sbit SPKR = P1^7;

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

// Initialize the switches for the program
sbit sw1 = P2^0;
sbit sw2 = P0^1;
sbit sw3 = P2^3;
sbit sw4 = P0^2;
sbit sw5 = P1^4;
sbit sw6 = P0^0;
sbit sw7 = P2^1;
sbit sw8 = P0^3;
sbit sw9 = P2^2;

// Function Prototypes
void ledC( char num, bit state );
void lightDelay();

#ifndef GAME

#define GAME
#include "game.h"

#endif

char gen_rand()
{
  char r = rand()%9;
  return r;
}

void simonSays()
{
  char aSpot = 0, button, gDurr = 3, gNow, swSpot = 0;
  char gArr[MAXGAMES]; 
        
  while(gDurr != MAXGAMES)
  {
    gNow  = gDurr;

    //this loop shows the light order
    do
    {
      if(aSpot != 0)
        ledC(button, OFF);
      button = gen_rand();
      gArr[aSpot] = button;
      ledC(button, ON);
      aSpot++;
      lightDelay();
      lightDelay();
    }
    while(aSpot != gDurr);

    aSpot = 0;

    //this loop is when the user puts in the numbers
    do
    {
      //change to the buttons function
      while((sw1)&&(sw2)&&(sw3)&&(sw4)&&(sw5)&&(sw6)&&(sw7)&&(sw8)&&(sw9))//because of active low if thw Switch = 1 it is not being pushed
      {
      }
      if(!sw1)
        swSpot = 1;
      else
      {
        if(!sw2)
          swSpot = 2;
        else
        {
          if(!sw3)
            swSpot = 3;
          else if(!sw4)
            swSpot = 4;
          else if(!sw5)
            swSpot = 5;
          else if(!sw6)
            swSpot = 6;
          else if(!sw7)
            swSpot = 7;
          else if(!sw8)
            swSpot = 8;
          else if(!sw9)
            swSpot = 9;
        }
      }
      if(swSpot == gArr[aSpot])
      {
        ledC(gArr[aSpot], ON);
        aSpot++;
        lightDelay();
        lightDelay();
        ledC(gArr[aSpot], OFF);
        if( aSpot == gDurr)
        {  
          victory();
          gDurr++;
        }
      }
      else
      {
        failure();
        return;  
      } 
         
    }while(gDurr == gNow);
  }
  
  return;
}

void victory()
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

void failure()
{
   ledC( 1, ON);
   ledC( 3, ON);
   ledC( 5, ON);
   ledC( 7, ON);
   ledC( 9, ON);
   lightDelay();
   lightDelay();
   lightDelay();
   lightDelay();
   lightDelay();

   ledC( 1, OFF);
   ledC( 3, OFF);
   ledC( 5, OFF);
   ledC( 7, OFF);
   ledC( 9, OFF);

   return;
}