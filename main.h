//CompE 213 Project 2
//Billy Rhoades
//Dane Greer
//Michael Jolley
//
//Main Headers Program Code

//#include "reg51.h"
#ifndef REGNINE

#define REGNINE
#include "reg932.h"

#endif

#include "stdlib.h"

#define NUMLEDS 9
#define MAXGAMES 7

#define SOUNDRANGE 15
					
#define STARTUPRANGE 35

// Speaker
sbit SPKR = P1^7;

// Note that the pinout diagram has different LED/SW nums!
// Initialize all the lights for the program
sbit led1 = P2^4; // Red, top left
sbit led2 = P0^6; // Amber, middle left
sbit led3 = P2^5; // Yellow, bottom left
sbit led4 = P0^5; // Yellow, top middle
sbit led5 = P1^6; // Blue, middle
sbit led6 = P0^7; // Green, bottom middle
sbit led7 = P2^7; // Green, top right
sbit led8 = P0^4; // Red, middle right
sbit led9 = P2^6; // Amber, bottom right

// Initialize the switches for the program
sbit sw1 = P2^0; // Red, top left
sbit sw2 = P0^2; // Amber, middle left
sbit sw3 = P2^1; // Yellow, bottom left
sbit sw4 = P0^1; // Yellow, top middle
sbit sw5 = P1^4; // Blue, middle
sbit sw6 = P0^3; // Green, bottom middle
sbit sw7 = P2^3; // Green, top right
sbit sw8 = P0^0; // Red, middle right
sbit sw9 = P2^2; // Amber, bottom right

// Order of leds from top left to bottom right, done horizontally
idata const char horizontalOrder[NUMLEDS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// Order of leds from top left to bottom right, done vertically
idata const char verticalOrder[NUMLEDS] = { 1, 4, 7, 2, 5, 8, 3, 6, 9 };

// Order of leds to flash when waiting for them to hit simon
// Spaced w/ 10, which does nothing
idata const char startOrder[STARTUPRANGE] = { 2, 5, 8, 10, 8, 10, 8, 1, 4, 7, 8, 10, 8, 10, 8, 3, 6, 9, 8, 10, 8, 10, 8, 7, 4, 1, 2, 3, 6, 9, 8, 10, 8, 10, 8 };

// Precomp cheats
#define ON 0
#define OFF 1

// Function Prototypes
void ledC( char num, bit state );
void lightDelay();
void victory();
void failure( char correct );