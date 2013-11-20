MovingRobot
===========

This repo is a working project to move a robot utilizing two DC motors with an MSP microconroller. 
The MSP430 utilizes the SMCLK in the TA0 and TA1 clocks available on P1.1, P1.2, P2.0, and P2.1. In 
order to move the robot, I set two of the pins to OUTMOD_7 which is a Set/Reset triggering based off the 
clock, and I set the other two pins to OUTMOD_5 which is a Reset to those pins. The Set/Reset signal 
given to the pins creates a MOD signal to a DC motor driver chip which can provide sufficient current 
to operate the motors. 


FUNCTIONS
=========

void initializePins();
  * This function directs and selects the above mentioned pins as well as initializes the clock to 
  * a 60% duty cycle for TA0 and TA1. It also counts sets which direction the clock counts as well 
  * as what it does once the clock triggers
  
void turnLeft90();
  * This function turns the robot 90 degrees by setting left motor in reverse while 
  * keeping the right motor going forward. after a predetermined period of time, the 
  * robot automatically starts moving in the forward direction again. It only does this
  * once it reaches a 90 degree turn
  
void turnLeft45();
  * This function turns the robot 90 degrees by setting left motor in reverse while 
  * keeping the right motor going forward. after a predetermined period of time, the 
  * robot automatically starts moving in the forward direction again. It only does this
  * once it reaches a 45 degree turn
   
void turnRight90();
  * This function turns the robot 90 degrees by setting right motor in reverse while 
  * keeping the left motor going forward. after a predetermined period of time, the 
  * robot automatically starts moving in the forward direction again. It only does this
  * once it reaches a 90 degree turn
   
void turnRight45();
  * This function turns the robot 45 degrees by setting right motor in reverse while 
  * keeping the left motor going forward. after a predetermined period of time, the 
  * robot automatically starts moving in the forward direction again. It only does this
  * once it reaches a 45 degree turn
  
void moveForward();
  * This function moves the robot in the forward direction at 60% duty cycle
  
void moveBack();
  * This function moves hte robot in the reverse direction at 50% duty cycle
  
void stop();
  * This function kills power to both motors but the robot can still coast
  

LISCENCING
==========
Keep on using me, until you use me up! (Bill Withers)
  
