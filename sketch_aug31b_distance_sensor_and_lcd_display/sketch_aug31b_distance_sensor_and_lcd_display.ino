#include <LiquidCrystal.h>        //load liquid crystal library
LiquidCrystal myLcd(10, 9, 5, 4, 3, 2); // Creating a liquid crystal display called myLcd
int trigPin = 13;    //Sets trigger pin to pin 13
int echoPin = 11;     //Sets echo pin to pin 11
float speedOfSound = 350.0;
float blockDist;
float pingTime;



void setup() {
  Serial.begin(9600);
 myLcd.begin(16, 2);  //Tell our arduino our LCD has 16 columnns and 2 rows
 myLcd.setCursor(0,0);  //set Lcd cursor to upper left corner
 myLcd.print("My Timer: ");   //print out the first line

 pinMode(trigPin , OUTPUT);   //Sets trigPin as output
 pinMode(echoPin, INPUT);    //Sets echoPin as input


}

void loop() {
    digitalWrite(trigPin, LOW);  //set trigPin to low to mark  start of signal
    delayMicroseconds(250);      //delay to give time for arduino to settle
    digitalWrite(trigPin, HIGH);  //set trigPin to high to send a pulse
    delayMicroseconds(25);         //delay time is shorter to mark a pulse
    digitalWrite(trigPin, LOW);   //to mark end of signal

    pingTime = pulseIn(echoPin, HIGH);   //reads the amount of time the echo hit the obstacle and back
    Serial.println(pingTime);
    pingTime = pingTime/1000000 ;     //convert pingTime from microseconds to  seconds
    blockDist = speedOfSound/2. * pingTime;    //calculate the distance to object
    blockDist = blockDist*100;                  //conver dist in metres to centimetres
    
    myLcd.setCursor(0,1);               //set the lcd cursor to first column, second row
    myLcd.print("                ");   //clears the line

    myLcd.setCursor(0,1);     //set the lcd cursor to first column, second row
    myLcd.print(blockDist);   //print the distance to the obstacle
    myLcd.print(" cm");  //prints the units 

   
    

  
}
