#include <msp430.h> 

/*
 * Created By: Travis Schriner
 * Date: 14 November 2013
 * Description: This main.c file is to move a robot
 * utilizing a DC motor with an MSP430 microcontroller
 *
 */
#include "MovingRobot.h"

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
	return 0;
}
