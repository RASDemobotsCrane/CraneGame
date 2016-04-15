/*Program for Spring 2016 DemoBots 
* Claw Machine 
* Hardware Specifications:
* - Stepper Motors (4)
* - JoyStick (1)
* - ON/OFF Switch (1)
*/
#include <stdint.h>

void InitPorts(void);
void InitPosition(void);
void endGame(void);
void movement(void);

int main(){
	InitPorts();
}
