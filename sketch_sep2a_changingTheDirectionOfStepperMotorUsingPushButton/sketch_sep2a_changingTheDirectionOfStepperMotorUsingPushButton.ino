#include <Stepper.h>                 //import the stepper library
int stepsPerRevolution=2048;         //declare an int and set it to the steps the stepper motor makes per revolution
int motSpeed=10;                      //set the number of revolutions per minute(rpm) in this case 10, hence 1 revolution every 6 seconds
int dt=500;                          //declare an int for delay time and set it in milliseconds
int buttonValNew;                        //declare 2 variables to read from push buttons
int buttonValOld=1;                   //equate this variable to 1 to use to control direction
int pushButton=2;

Stepper  myStepper(stepsPerRevolution, 8,10,9,11);         //declare an object for the stepper motor and enter sequence of pins used

void setup() {
  Serial.begin(9600);                //begin the serial monitor
  myStepper.setSpeed(motSpeed);        //set the motor speed by calling the object and input the rpm value needed

  
  
}

void loop() {                     //this to help maintain direction if no change in pushbutton value
       myStepper.step(stepsPerRevolution);              //run the motor
       delay(dt);                                           //delay time to allow settling
                               //pass the buttonValNew to buttonValOld

}






































