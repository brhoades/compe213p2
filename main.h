//#include "reg51.h"
#include "reg932.h"
#include "stdlib.h"
#include "string.h"

#define NUMLEDS 9

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

// Speaker
sbit SPKR = P1^7;
int R0 = 0x00;
int R1 = 0x00;
int R2 = 0x00;
int R3 = 0x00;
int R4 = 0x00;
int R5 = 0x00;
int R6 = 0x00;

// Order of leds from top left to bottom right, done horizontally
char horizontalOrder[NUMLEDS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// Order of leds from top left to bottom right, done vertically
char verticalOrder[NUMLEDS] = { 1, 4, 7, 2, 5, 8, 3, 6, 9 };

// Precomp cheats
#define ON 0
#define OFF 1