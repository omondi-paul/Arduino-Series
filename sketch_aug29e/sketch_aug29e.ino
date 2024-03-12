//This sketch uses analogue read value to read from potentiometer
//It then  uses those values to control the blink rate of an Led
// 0 volts cause a blink of one in 1 second 
// 0 volts for one in 0.1 second


int potPin = A1;             // Declares an int and sets it to Analogue pin A1
int redLedPin = 11;             //Declares an int and sets it to 11
int readValue;                  //Declares an int
int wait;                //Declares an int variable 

void setup() {
  Serial.begin(9600) ;           //Starts the serial monitor
  pinMode(A1, INPUT)  ;          //Sets pin A1 as input pin
}

void loop() {
    readValue = analogRead(potPin); //Read potentiometer value and store in an int 
    wait= 1000- (1023./900.)*readValue; //Calculate the equivalent Blink rate
    digitalWrite(redLedPin, HIGH); // Sets pin to HIGH
    delay(wait);                   //wait 
    digitalWrite(redLedPin, LOW); // Sets pin to LOW
    delay(wait);                   //wait
    Serial.print(wait);           //prints on monitor
    
}
