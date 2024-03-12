int potPin = A1; //Assign int potPin to A1
int readValue;
float voltage;

void setup() {
  pinMode(potPin, INPUT); //Setting potPin as and input pin 
  Serial.begin(9600); //Start the serial monitor


}

void loop() {
  
  for(int j = 1; j>0; j=j+1){
  readValue = analogRead(potPin); //Read the voltage in potPin and take it into value variable
  voltage =  (5./ 1023.) * readValue; // Calculate the voltage read; 
  Serial.print(" The voltage is: ");
  Serial.print(voltage); //Prints the equivalent voltage to the monitor
  Serial.println("volts"); //Prints the units of the measurement which in this case is volts
  delay(500); // wait 
  }

}
