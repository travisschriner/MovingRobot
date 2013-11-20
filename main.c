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
	

    initializePins();

       while (1) {
    	  moveForward();
    	  __delay_cycles(1000000);
    	  stop();
    	  __delay_cycles(10000);
          moveBack();
          __delay_cycles(1000000);
          stop();
          __delay_cycles(10000);

          moveForward();
          __delay_cycles(1000000);

          stop();
          __delay_cycles(10000);

           turnRight90();
           __delay_cycles(500000);
           stop();
           __delay_cycles(10000);

           turnLeft90();
           __delay_cycles(500000);
           stop();
           __delay_cycles(10000);

           turnRight45();
           __delay_cycles(500000);
           stop();
           __delay_cycles(10000);

           turnLeft45();
           __delay_cycles(500000);
           stop();
           __delay_cycles(10000);

       }
	return 0;
}
