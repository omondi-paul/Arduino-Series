int redLed = 13;      //declare int for red led
int greenLed = 12;     //declare int for green led
int tiltPin = 8;       //declare int for tiltPin
int tiltVal;          //declare int for tilt value
int dt = 250;         //declare an int for delay time and set to a value in milliseconds

void setup() {
  Serial.begin(9600);          //start the serial monitor at a baud rate set to 9600

  pinMode(redLed, OUTPUT);       //set the red LED pin to output
  pinMode(greenLed, OUTPUT);       //set the green LED pin to output

  pinMode(tiltPin, INPUT);          //set the tiltpin to input
  digitalWrite(tiltPin, HIGH);      //write a 1 to the tiltpin in order to use the arduino internal pull up resistor
 
}

void loop() {
  tiltVal = digitalRead(tiltPin);      //read the value of tilt pin and store in the variable tiltvalue
  if (tiltVal==0){                   //start an if conditional statement
    digitalWrite(redLed, LOW);        //digital write to red LED pin 
    digitalWrite(greenLed, HIGH);     //digital write to green LED pin
    delay(dt);                        //wait time
  }
  else{
    digitalWrite(redLed, HIGH);         //digital write to red LED pin 
    digitalWrite(greenLed, LOW);         //digital write to green LED pin
    delay(dt);                            //wait time
  }
  Serial.println(tiltVal);                //write to tilt value
  delay(dt);
  
}
