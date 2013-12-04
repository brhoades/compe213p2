#include "reg51.h"
#include "stdlib.h"
#include "string.h"

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

//Precomp cheats
#define ON 0;
#define OFF 1;