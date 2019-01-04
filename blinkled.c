/* Header is in /usr/avr/include. For more, see http://bit.ly/avrgcc-headers */
#include <avr/io.h>
/* #include <avr/iom328p.h> -- *bad* non-portable alternative                */
#include <stdint.h>

uint16_t __seed = 1;
/* random generation */
#define random() ({__seed = 5 * __seed + 3;})

uint16_t r;
uint8_t lower;

int main(void)
{
    /* set PD6 to output */
    DDRD |= (1 << 6);

    /* Set FAST PWM Mode */
    TCCR0A |= (1 << WGM01) | (1 << WGM00);

    /* configure timers */
    TCCR0A |= (1 << COM0A1); /* Set non-inverting output mode */

    /* frequency devider */
    TCCR0B |= (1 << CS02) ; 
    while (1)
    {	
	r = random();
	lower = r;
	
	/* [0..15] - 16 stages of candle burning */	

	/* probability distribution */
		if (r > 50461) {
	    OCR0A = (15 << 4) | lower;  /* var = 240 + [0..15] */
	} else if (r > 39976) {
	    OCR0A = (14 << 4) | lower;
	} else if (r > 34078) {
	    OCR0A = (13 << 4) | lower;
	} else if (r > 30801) {
	    OCR0A = (12 << 4) | lower;
	} else if (r > 27524) {
	    OCR0A = (11 << 4) | lower;
	} else if (r > 24247) {
	    OCR0A = (10 << 4) | lower;
	} else if (r > 20971) {
	    OCR0A = (9 << 4) | lower;
	} else if (r > 17694) {
	    OCR0A = (8 << 4) | lower;
	} else if (r > 14417) {
	    OCR0A = (7 << 4) | lower;
	} else if (r > 11140) {
	    OCR0A = (6 << 4) | lower;
	} else if (r > 7863) {
	    OCR0A = (5 << 4) | lower;
	} else if (r > 4587) {
	    OCR0A = (4 << 4) | lower;
	} else if (r > 1965) {
	    OCR0A = (3 << 4) | lower;
	} else if (r > 1310) {
	    OCR0A = (2 << 4) | lower;
	} else if (r > 654) {
	    OCR0A = (1 << 4) | lower;
	} else 
	    OCR0A = lower;  
	}
}