/*
 * LEDeep.c
 *
 * Created: 2022-01-16 22:26:44
 * Author : svartsol
 */ 

#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

// ADMUX = (1<<REFS1) | (0<<REFS0) | (1<<ADLAR) | (0<<MUX4) | (0<<MUX3) | (0<<MUX2) | (0<<MUX1) | (0<<MUX0);
#define FILTERCONFIG		(0b10100000)
#define FIRST_ADC_CHANNEL	(0b10100000)
#define SECOND_ADC_CHANNEL	(0b10100001)
#define THIRD_ADC_CHANNEL	(0b10100010)
#define FOURTH_ADC_CHANNEL	(0b10100011)
#define FIFTH_ADC_CHANNEL	(0b10100100)
#define SIXTH_ADC_CHANNEL	(0b10100101)
#define SEVENTH_ADC_CHANNEL	(0b10100110)
#define LAST_ADC_CHANNEL	(0b10100111)


void ignite(uint8_t row, uint8_t nrb_of_led);
uint32_t binToDec(uint32_t b);
uint8_t decToStr(int32_t dec);
void pixelPulse1(uint8_t x);
void pixelPulse2(uint8_t x);
void pixelPulse3(uint8_t x);
void pixelPulse4(uint8_t x);
void pixelPulse5(uint8_t x);
void pixelPulse6(uint8_t x);
void pixelPulse7(uint8_t x);
void pixelPulse8(uint8_t x);
void setColor(uint8_t g_dec, uint8_t r_dec, uint8_t b_dec);
	/* Setup ADC to use internal 2.56V reference 
    and select temp sensor channel from 0 to 7. */
   

    /* Set conversion time to 
    112usec = [(1/(8Mhz / 64)) * (14 ADC clocks  per conversion)]
     and enable the ADC*/
    //ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);

    /* Perform Dummy Conversion to complete ADC init */
    //ADCSRA |= (1<<ADSC);

    /* wait for conversion to complete */
    //while ((ADCSRA & (1<<ADSC)) != 0);

uint8_t zeroArray [8] = {0,0,0,0,0,0,0,0};
uint8_t g_bin[8] = {0,0,0,0,0,0,0,0};
uint8_t r_bin[8] = {0,0,0,0,0,0,0,0};
uint8_t b_bin[8] = {0,0,0,0,0,0,0,0};
uint32_t bin;
uint32_t test;
uint32_t pretest;

	//Code Zero high 0.35us low 0.8us
	//Code One high 0.7us low 0.6us
	//Lions den nexus neo pixels are port D5
int main(void){
	_delay_ms(1000);
	//Green Red Blue
	//RGBB (r, g, b)	(102, 2, 60)
	setColor(2, 102, 60);
	DDRB = (1 << DDRB3) |(1 << DDRB2) |(1 << DDRB1) | (1 << DDRB0);
	DDRC = (1 << DDRC7) |(1 << DDRC6) |(1 << DDRC1) | (1 << DDRC0);

	// Vref 2.56v is 11, 1.1 is 10.
	//MUX channel 0 to 7.
// 	while(1){
// 		ignite(7,8);
// 		_delay_ms(1000);
// 		ignite(7,0);
// 		_delay_ms(1000);
// 	};
// 	
// 	while(1){
// 		ignite(3,0);
// 		ignite(6,0);
// 		ignite(8,0);
// 		ignite(1,8);
// 		ignite(4,8);
// 		_delay_ms(1000);
// 		ignite(1,0);
// 		ignite(4,0);
// 		ignite(2,8);
// 		ignite(5,8);
// 		ignite(7,8);
// 		_delay_ms(1000);
// 		ignite(2,0);
// 		ignite(5,0);
// 		ignite(7,0);
// 		ignite(3,8);
// 		ignite(6,8);
// 		ignite(8,8);
// 		_delay_ms(1000);
// 	};
	ADMUX = (1<<REFS1) | (0<<REFS0) | (1<<ADLAR) | (0<<MUX3) | (1<<MUX2) | (0<<MUX1) | (1<<MUX0);
	ADCSRA = (1<<ADPS2) | (1<<ADPS1) |(1<<ADPS0)| (1<<ADEN);
 	ADCSRA |= (1<<ADSC);
	while ((ADCSRA & (1<<ADSC)) != 0);
	while(1){
// 			
// 		ADMUX = FOURTH_ADC_CHANNEL;
// 		ADCSRA |= (1<<ADSC);
// 		while ((ADCSRA & (1<<ADSC)) != 0);
// 		test = ADCH<<2;
// 		ignite(4,decToStr(test));		
// 		ADMUX = SIXTH_ADC_CHANNEL;
// 		ADCSRA |= (1<<ADSC);
// 		while ((ADCSRA & (1<<ADSC)) != 0);
// 		test = ADCH<<4;
// 		ignite(5,decToStr(test));
	setSampleChannel(0);
 	};
// 		while ((ADCSRA & (1<<ADSC)) != 0);
// 		test = ADC;
// 		bin = binToDec(test);
// 		ignite(decToStr(bin),4);
		
	
};


void setSampleChannel(uint8_t x){
	switch (x)
	{
	//this case cycles from 1 to 8.
	case 0:
	for(uint8_t i = 1; i < 9; i++){
		setSampleChannel(i);
	};
// 		if (ADMUX & 0b00000111 = LAST_ADC_CHANNEL){
// 		ADMUX &= ~LAST_ADC_CHANNEL;
// 		for(uint8_t i = 0; i < 8; i++){
// 			ADCSRA |= (1<<ADSC);
// 			while ((ADCSRA & (1<<ADSC)) != 0);
// 			test = ADCH<<4 ;
// 			ignite(i+1,decToStr(test));
// 			ADMUX =+ 0b00000001;
// 			};
	break;
	case 1:
		ADMUX = FIRST_ADC_CHANNEL;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		//MaxValue is 0.4
		test = ADCH<<1 ;
		test = test*5;
		ignite(1,decToStr(test));		
	break;
	case 2:
		ADMUX = SECOND_ADC_CHANNEL;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		//Max value is 1
		test = ADCH<<2 ;
		ignite(2,decToStr(test));
	break;
	case 3:
		ADMUX = THIRD_ADC_CHANNEL;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		//MaxValue is 0.5
		test = ADCH<<3 ;
		ignite(3,decToStr(test));
	break;
	case 4:
		ADMUX = FOURTH_ADC_CHANNEL;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		//MaxValue is 1
		test = ADCH<<2 ;
		ignite(4,decToStr(test));
	break;
	case 5:
		ADMUX = FIFTH_ADC_CHANNEL;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		//Max value is 1
		test = ADCH<<2 ;
		ignite(5,decToStr(test));
	break;
	case 6:
		ADMUX = SIXTH_ADC_CHANNEL;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		//Max value is 0.4
		test = ADCH<<1;
		test = test*5;
		ignite(6,decToStr(test));
	break;			
	case 7:	
		ADMUX = SEVENTH_ADC_CHANNEL;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		//Max value is 0.4
		test = ADCH<<1;
		test = test*5;
		ignite(7,decToStr(test));
	break;
	case 8:
		ADMUX = LAST_ADC_CHANNEL;
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADSC)) != 0);
		test = ADCH<<1 ;
		test = test*5;
		ignite(8,decToStr(test));
	break;
}
};
uint32_t binToDec(uint32_t b){
	uint32_t dec = 0, i = 0, rem;

	while (b!=0) {
		rem = b % 10;
		b /= 10;
		dec += rem * pow(2, i);
		++i;
	}

	return dec;
};
uint8_t decToStr(int32_t dec){
	signed int temp = dec;
	if (temp < 10)
	{
		return 0;
	}
	uint8_t str = 0;
	while (temp > 0){
		str = str + 1;
		temp = temp - 128;
	};
	return str;
};
	
//The ignite function takes a number from 1 to 8 and turns that many Pixels on. And the last argument is the said row. 
void ignite( uint8_t row, uint8_t nrb_of_led){
	switch(row){
		case 1:
		for (uint8_t x = 0; x < nrb_of_led; x++){
			for(int y = 0; y < 8; y++){
				pixelPulse1(g_bin[y]);
			};
			for(int z = 0; z < 8; z++){
				pixelPulse1(r_bin[z]);
			};
			for(int s = 0; s < 8; s++){
				pixelPulse1(b_bin[s]);
			};
		};
		for (uint8_t v = nrb_of_led; v < 8; v++){
			for (uint8_t t = 0; t < 24; t++){
				pixelPulse1(0);
			};
			
	};
	_delay_ms(1);
		break;
		case 2:
		for (uint8_t x = 0; x < nrb_of_led; x++){
			for(int y = 0; y < 8; y++){
				pixelPulse2(g_bin[y]);
			};
			for(int z = 0; z < 8; z++){
				pixelPulse2(r_bin[z]);
			};
			for(int s = 0; s < 8; s++){
				pixelPulse2(b_bin[s]);
			};
		};
		for (uint8_t v = nrb_of_led; v < 8; v++){
			for (uint8_t t = 0; t < 24; t++){
				pixelPulse2(0);
			};
			
		};
		_delay_ms(1);
		break;
		case 3:
		for (uint8_t x = 0; x < nrb_of_led; x++){
			for(int y = 0; y < 8; y++){
				pixelPulse3(g_bin[y]);
			};
			for(int z = 0; z < 8; z++){
				pixelPulse3(r_bin[z]);
			};
			for(int s = 0; s < 8; s++){
				pixelPulse3(b_bin[s]);
			};
		};
		for (uint8_t v = nrb_of_led; v < 8; v++){
			for (uint8_t t = 0; t < 24; t++){
				pixelPulse3(0);
			};
			
		};
		_delay_ms(1);
		break;
		case 4:
		for (uint8_t x = 0; x < nrb_of_led; x++){
			for(int y = 0; y < 8; y++){
				pixelPulse4(g_bin[y]);
			};
			for(int z = 0; z < 8; z++){
				pixelPulse4(r_bin[z]);
			};
			for(int s = 0; s < 8; s++){
				pixelPulse4(b_bin[s]);
			};
		};
		for (uint8_t v = nrb_of_led; v < 8; v++){
			for (uint8_t t = 0; t < 24; t++){
				pixelPulse4(0);
			};
			
		};
		_delay_ms(1);
		break;
		case 5:
		for (uint8_t x = 0; x < nrb_of_led; x++){
			for(int y = 0; y < 8; y++){
				pixelPulse5(g_bin[y]);
			};
			for(int z = 0; z < 8; z++){
				pixelPulse5(r_bin[z]);
			};
			for(int s = 0; s < 8; s++){
				pixelPulse5(b_bin[s]);
			};
		};
		for (uint8_t v = nrb_of_led; v < 8; v++){
			for (uint8_t t = 0; t < 24; t++){
				pixelPulse5(0);
			};
			
		};
		_delay_ms(1);
		break;
		case 6:
		for (uint8_t x = 0; x < nrb_of_led; x++){
			for(int y = 0; y < 8; y++){
				pixelPulse6(g_bin[y]);
			};
			for(int z = 0; z < 8; z++){
				pixelPulse6(r_bin[z]);
			};
			for(int s = 0; s < 8; s++){
				pixelPulse6(b_bin[s]);
			};
		};
		for (uint8_t v = nrb_of_led; v < 8; v++){
			for (uint8_t t = 0; t < 24; t++){
				pixelPulse6(0);
			};
			
		};
		_delay_ms(1);
		break;
		case 7:
		for (uint8_t x = 0; x < nrb_of_led; x++){
			for(int y = 0; y < 8; y++){
				pixelPulse7(g_bin[y]);
			};
			for(int z = 0; z < 8; z++){
				pixelPulse7(r_bin[z]);
			};
			for(int s = 0; s < 8; s++){
				pixelPulse7(b_bin[s]);
			};
		};
		for (uint8_t v = nrb_of_led; v < 8; v++){
			for (uint8_t t = 0; t < 24; t++){
				pixelPulse7(0);
			};
			
		};
		_delay_ms(1);
		
		break;
		case 8:
		for (uint8_t x = 0; x < nrb_of_led; x++){
			for(int y = 0; y < 8; y++){
				pixelPulse8(g_bin[y]);
			};
			for(int z = 0; z < 8; z++){
				pixelPulse8(r_bin[z]);
			};
			for(int s = 0; s < 8; s++){
				pixelPulse8(b_bin[s]);
			};
		};
		for (uint8_t v = nrb_of_led; v < 8; v++){
			for (uint8_t t = 0; t < 24; t++){
				pixelPulse8(0);
			};
			
		};
		_delay_ms(1);
		
		break;
		default:
		break;
		
	}
	
	

};
//Denna functionen konverterar decimal till binart. First element in each array is MSB. GRB!
void setColor(uint8_t g_dec, uint8_t r_dec, uint8_t b_dec){
		for(int x = 0; x < 8; x++){
			if (g_dec/pow(2,7-x) >= 1){
				g_bin[x] = 1;
				g_dec = g_dec - (pow(2,7-x));
			 }else{
				g_bin[x] = 0;
			};
		};
		for(int y = 0; y < 8; y++){
			if (r_dec/pow(2,7-y) >= 1){
				r_bin[y] = 1;
				r_dec = r_dec - (pow(2,7-y));
			}else{ 
				r_bin[y] = 0;
			};
		};
		for(int z = 0; z < 8; z++){
			if (b_dec/pow(2,7-z) >= 1){
				b_bin[z] = 1;
				b_dec = b_dec - (pow(2,7-z));
			}else{
				b_bin[z] = 0;
			};
		};
};
void pixelPulse8(uint8_t x){
			if(x == 0){
				PORTC |= (1 << PORTC1);
				asm volatile(
				"nop\n\t"
				"nop\n\t"
				::);
				PORTC &=~(1 << PORTC1);
				asm volatile(
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
				::);
				}	else	{
				PORTC |= (1 << PORTC1);
				asm volatile(
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
				::);
				PORTC &=~(1 << PORTC1);
				asm volatile(
				"nop\n\t"
				"nop\n\t"
				::);

			};
};
void pixelPulse7(uint8_t x){
	if(x == 0){
		PORTC |= (1 << PORTC0);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);
		PORTC &=~(1 << PORTC0);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		}	else	{
		PORTC |= (1 << PORTC0);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		PORTC &=~(1 << PORTC0);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);

	};
};
void pixelPulse6(uint8_t x){
	if(x == 0){
		PORTC |= (1 << PORTC6);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);
		PORTC &=~(1 << PORTC6);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		}	else	{
		PORTC |= (1 << PORTC6);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		PORTC &=~(1 << PORTC6);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);

	};
};
void pixelPulse5(uint8_t x){
	if(x == 0){
		PORTC |= (1 << PORTC7);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);
		PORTC &=~(1 << PORTC7);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		}	else	{
		PORTC |= (1 << PORTC7);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		PORTC &=~(1 << PORTC7);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);

	};
};
void pixelPulse4(uint8_t x){
	if(x == 0){
		PORTB |= (1 << PORTB0);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);
		PORTB &=~(1 << PORTB0);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		}	else	{
		PORTB |= (1 << PORTB0);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		PORTB &=~(1 << PORTB0);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);

	};
};
void pixelPulse3(uint8_t x){
	if(x == 0){
		PORTB |= (1 << PORTB1);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);
		PORTB &=~(1 << PORTB1);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		}	else	{
		PORTB |= (1 << PORTB1);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		PORTB &=~(1 << PORTB1);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);

	};
};
void pixelPulse2(uint8_t x){
		if(x == 0){
			PORTB |= (1 << PORTB2);
			asm volatile(
			"nop\n\t"
			"nop\n\t"
			::);
			PORTB &=~(1 << PORTB2);
			asm volatile(
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			::);
			}	else	{
			PORTB |= (1 << PORTB2);
			asm volatile(
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			::);
			PORTB &=~(1 << PORTB2);
			asm volatile(
			"nop\n\t"
			"nop\n\t"
			::);

};
};
void pixelPulse1(uint8_t x){
	if(x == 0){
		PORTB |= (1 << PORTB3);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);
		PORTB &=~(1 << PORTB3);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		}	else	{
		PORTB |= (1 << PORTB3);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		"nop\n\t"
		::);
		PORTB &=~(1 << PORTB3);
		asm volatile(
		"nop\n\t"
		"nop\n\t"
		::);

	};
};


