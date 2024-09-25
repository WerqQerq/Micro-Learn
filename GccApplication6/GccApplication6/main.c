#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define SEG7_DDR DDRD
#define SEG7_PORT PORTD

// int -32768...32767
// char -128...127
// unsigned int 0...65535
// unsigned char 0...255


int digits [10] =
{
	0b00111111, //0
	0b00000110, //1
	0b01011011, //2
	0b01001111, //3
	0b01100110, //4
	0b01101101, //5
	0b01111101, //6
	0b00000111, //7
	0b01111111, //8
	0b01101111 //9
};



int main(void)
{
	unsigned int number = 0;
	SEG7_DDR = 0b11111111;
	SEG7_PORT = 0b00000000;
	DDRB = 0b00000000;
	PORTD = 0b11000000;
		
	while (1)
	{
		
		SEG7_PORT = digits [number];
		
		
		if((PINB == 0b01000000) && (number < 9))
		{
			_delay_ms(150);
			number++;
			_delay_ms(150);
		}
		
		else if ((PINB == 0b10000000) && (number > 0))
		{
			_delay_ms(150);
			number--;
			_delay_ms(150);
						
		}
				
	}
}