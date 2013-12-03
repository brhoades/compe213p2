#include "reg51.h"
#include "stdlib.h"
#include "string.h"

// Number of lights
#define NUMLIGHTS 9

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

//Array of locations of LEDs for easier use
//These are just ordered from top to bottom
//First is a spacer so leds[6] == led6
sbit leds[10] = { P0, led1, led2, led3, led4, led5, led6, led7, led8, led9 };

//These are ordered from left to right
sbit horizontalLeds[10] = { P0, led1, led4, led7, led2, led5, led8, led3, led6, led9 };

//Precomp cheats
#define ON 0;
#define OFF 1;