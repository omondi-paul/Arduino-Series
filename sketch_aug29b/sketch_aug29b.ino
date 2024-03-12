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
  Serial.print("You are on read number print # ");
  Serial.print(j);
  Serial.print(":  ");
  Serial.print(readValue); //Print the value of the volatage to the serial monitor
  Serial.print(" Which is equal to: ");
  Serial.print(voltage);
  Serial.println("volts");
  delay(250); // wait 
  }

}
