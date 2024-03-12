// This sketch uses potentiometer to make a dimmable Led

int potPin = A1;             // Declares an int and sets it to Analogue pin A1
int redLedPin = 11;             //Declares an int and sets it to 11
int readValue;                  //Declares an int
float writeValue;              //Decalre a float variable

void setup() {
  Serial.begin(9600) ;           //Starts the serial monitor
  pinMode(A1, INPUT)  ;          //Sets pin A1 as input pin
  pinMode (redLedPin, OUTPUT) ;     //Sets int LedPin as output pin

}

void loop() {
     readValue = analogRead(potPin); //Read potentiometer value and store in an int 
     writeValue = (255./1023.)*readValue;  //convert the read value into equivalent write value
     analogWrite(redLedPin,writeValue); //light up the led
     Serial.print("you are writing the value: ");
     Serial.println(writeValue);
}
