/*
 * MovingRobot.c
 *
 *  Created on: Nov 14, 2013
 *  Author: C15Travis.Schriner
 */

#include "MovingRobot.h"
#include <msp430.h>


//sets all my pins
void initializePins(){
	    P1DIR |= BIT2;                // TA0CCR1 on P1.2
	    P1DIR |= BIT1;                // TA0CCR1 on P1.1
	    P2DIR |= BIT1;				  // TA1CCR1 on P2.1
	    P2DIR |= BIT0;				  // TA1CCR1 on P2.0

	    P1SEL |= BIT2;                // TA0CCR1 on P1.2
	    P1SEL |= BIT1;                // TA0CCR1 on P1.1
	    P2SEL |= BIT1;                // TA0CCR1 on P2.1
	    P2SEL |= BIT0;                // TA0CCR1 on P2.0

	    TA0CTL &= ~(MC1|MC0);          // stop timer A0
	    TA1CTL &= ~MC1|MC0;            // stop timer A1

	    TA0CTL |= TACLR;               // clear timer A0
	    TA1CTL |= TACLR;			   // clear timer A1

	    TA0CTL |= TASSEL1;             // configure for SMCLK
	    TA1CTL |= TASSEL1;             // configure for SMCLK

	    TA0CCR0 = 100;                 // set signal period to 100 clock cycles (~100 microseconds)
	    TA0CCR1 = 60;                  // set duty cycle to 60/100 (60%)

	    TA1CCR0 = 100;                 // set signal period to 100 clock cycles (~100 microseconds)
	    TA1CCR1 = 60;                  // set duty cycle to 60/100 (60%)

	    TA0CCTL1 |= OUTMOD_7;          // set TA0CCTL1 to Reset / Set mode
	    TA0CCTL0 |= OUTMOD_5;		   // set TA0CCTL0 to ground

	    TA1CCTL1 |= OUTMOD_7;          // set TA1CCTL1 to Reset / Set mode
	    TA1CCTL0 |= OUTMOD_5;		   // set TA1CCTL0 to ground

	    TA0CTL |= MC0;                 // count up
	    TA1CTL |= MC0;                 // count up
}

void turnLeft90(){


	TA0CCTL1 &= ~OUTMOD_7;         // clears
	TA0CCTL1 |= OUTMOD_5;          // set TA0CCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_7;         // clears
	TA0CCTL0 |= OUTMOD_7;		   // set TA0CCTL0 to ground

	TA1CCTL1 &= ~OUTMOD_7;         // clears
	TA1CCTL1 |= OUTMOD_7;          // set TA1CCTL1 to Reset / Set mode
	TA1CCTL0 &= ~OUTMOD_7;         // clears
	TA1CCTL0 |= OUTMOD_5;		   // set TA1CCTL0 to ground

	_delay_cycles(280000);

	moveForward();
}

void turnLeft45(){

	TA0CCTL1 &= ~OUTMOD_7;         // clears
	TA0CCTL1 |= OUTMOD_5;          // set TA0CCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_7;         // clears
	TA0CCTL0 |= OUTMOD_7;		   // set TA0CCTL0 to ground

	TA1CCTL1 &= ~OUTMOD_7;         // clears
	TA1CCTL1 |= OUTMOD_7;          // set TA1CCTL1 to Reset / Set mode
	TA1CCTL0 &= ~OUTMOD_7;         // clears
	TA1CCTL0 |= OUTMOD_5;		   // set TA1CCTL0 to ground

	_delay_cycles(140000);

	moveForward();

}

void turnRight90(){

	TA0CCTL1 &= ~OUTMOD_7;         // clears
	TA0CCTL1 |= OUTMOD_7;          // set TA0CCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_7;         // clears
	TA0CCTL0 |= OUTMOD_5;		   // set TA0CCTL0 to ground

	TA1CCTL1 &= ~OUTMOD_7;         // clears
	TA1CCTL1 |= OUTMOD_5;          // set TA1CCTL1 to Reset / Set mode
	TA1CCTL0 &= ~OUTMOD_7;         // clears
	TA1CCTL0 |= OUTMOD_7;		   // set TA1CCTL0 to ground

	_delay_cycles(260000);

	moveForward();

}

void turnRight45(){

	TA0CCTL1 &= ~OUTMOD_7;         // clears
	TA0CCTL1 |= OUTMOD_7;          // set TA0CCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_7;         // clears
	TA0CCTL0 |= OUTMOD_5;		   // set TA0CCTL0 to ground

	TA1CCTL1 &= ~OUTMOD_7;         // clears
	TA1CCTL1 |= OUTMOD_5;          // set TA1CCTL1 to Reset / Set mode
	TA1CCTL0 &= ~OUTMOD_7;         // clears
	TA1CCTL0 |= OUTMOD_7;		   // set TA1CCTL0 to ground

	_delay_cycles(130000);

	moveForward();

}

void moveForward(){

	TA0CCTL1 &= ~OUTMOD_7;         // clears
	TA0CCTL1 |= OUTMOD_7;          // set TA0CCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_7;         // clears
	TA0CCTL0 |= OUTMOD_5;		   // set TA0CCTL0 to ground

	TA1CCTL1 &= ~OUTMOD_7;         // clears
	TA1CCTL1 |= OUTMOD_7;          // set TA1CCTL1 to Reset / Set mode
	TA1CCTL0 &= ~OUTMOD_7;         // clears
	TA1CCTL0 |= OUTMOD_5;		   // set TA1CCTL0 to ground



}

void moveBack(){

	TA0CCTL1 &= ~OUTMOD_7;         // clears
	TA0CCTL1 |= OUTMOD_5;          // set TA0CCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_7;         // clears
	TA0CCTL0 |= OUTMOD_7;		   // set TA0CCTL0 to ground

	TA1CCTL1 &= ~OUTMOD_7;         // clears
	TA1CCTL1 |= OUTMOD_5;          // set TA1CCTL1 to Reset / Set mode
	TA1CCTL0 &= ~OUTMOD_7;         // clears
	TA1CCTL0 |= OUTMOD_7;		   // set TA1CCTL0 to ground

}

void stop(){

	TA0CCTL1 &= ~OUTMOD_7;         // clears
	TA0CCTL1 |= OUTMOD_5;          // set TA0CCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_7;         // clears
	TA0CCTL0 |= OUTMOD_5;		   // set TA0CCTL0 to ground

	TA1CCTL1 &= ~OUTMOD_7;         // clears
	TA1CCTL1 |= OUTMOD_5;          // set TA1CCTL1 to Reset / Set mode
	TA1CCTL0 &= ~OUTMOD_7;         // clears
	TA1CCTL0 |= OUTMOD_5;		   // set TA1CCTL0 to ground

}


