#include <Servo.h>

/*When controlling a servo motor there are 3 new things you should put to mind
  1) Import the servo library first
  2) in global variable declaration, outside the loops, create a servo object : Servo objectName
  3) in the set up, attach the object you created to  your output servo pin insted of declarin the pin as output: objectName.attach(pin)
  4) in the loop, write to the pin by calling the object and using the angle from 0 to 180 degrees(objectName.write(angle))

*/
int pos;
int servoPin = 6;
int servoDelay = 25;     // set a variable 
int potPin = A0;         //Declare variable and set to A0
int potValue;       //Decalre variable for potentiometer reading

Servo myPointer;      //create aa servo object

void setup() {
  
  Serial.begin(9600);          //start the serial monitor 
  myPointer.attach(servoPin);     //attach the object to your servo output pin NB: don't declare pin as output pin
  pinMode(potPin, INPUT);          //set potentiometer pin as input

}

void loop() {
potValue = analogRead(potPin);  //analog read the potentiometer voltage values between 0-1023

pos = (160./1023.) *potValue +10;    //calculate the angle using the potetiometer value
myPointer.write(pos);                 //write to teh servo motor pin
Serial.println(pos);                  //print the pos value to the monitor





}
