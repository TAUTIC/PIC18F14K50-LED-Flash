#include <p18f14k50.h>
//Bootloader support code start 
extern void _startup (void); // See c018i.c in your C18 compiler dir
#pragma code REMAPPED_RESET_VECTOR = 0x1000
void _reset (void)
{
	_asm goto _startup _endasm
}

#pragma code 
//Bootloader support code end
void main (void)
{
	TRISC = 0; //configure port
	LATC = 0;
	LATCbits.LATC4 = 1; //set port bit
	LATCbits.LATC5 = 0;
	while (1) {
		Delay10KTCYx(125); // Delay 1,250,000 cycles
		LATCbits.LATC4 = !LATCbits.LATC4;
		LATCbits.LATC5 = !LATCbits.LATC5;
	}
}