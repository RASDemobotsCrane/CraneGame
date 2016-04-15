/*
	DemoBots 2016
	Stepper Motor
	
	Hardware Connections:
	**GPIO Ports on Stellaris tmf4c123**
	AP - Port E, PIN0
	AN - Port E, PIN1
	BP - Port E, PIN2
	BN - Port E, PIN3
*/

#include <stdint.h>
#include "Stepper Motors.h"
#include "tm4c123gh6pm.h"

//These Are the coils for the steppers
#define AP 0x01
#define AN 0x02
#define BP 0x04
#define BN 0x08

//This address is PE0 - PE3 *i.e., the stepper*
#define motor (*((volatile uint32_t *)0x40024400))
//Port E initialization
void Stepper_Init(void);

void Stepper_Init(void){
	//Turn on clock for Port E
	SYSCTL_RCGCGPIO_R |= 0x10;
	volatile unsigned long delay;
	delay = SYSCTL_RCGCGPIO_R;
	
	//Set up PE0-PE3 as output pins
	GPIO_PORTE_DIR_R	 |= 0x0F;
	GPIO_PORTE_DEN_R 	 |= 0x0F;
	GPIO_PORTE_AFSEL_R &= 0xF0;
}

int main(void){
	Stepper_Init();
// Step sequence for bipolar motor
// to move forwards. 
	uint8_t step[4] = {AP,AN,BP,BN};
// An index to the current step
	uint8_t cur_Step = 0;
	
//Loop that steps the motor forward
	while(1){
		//Checks to see if at the last step
		if(cur_Step == 4){
			cur_Step = 0;
		}
		motor = step[cur_Step];
		cur_Step++;
	}
}