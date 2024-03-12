//This program uses the DHT11 to measure the temperature and humidity values
#include <DHT.h>     //first load the library

#define  Type DHT11       //initialize a constant
int sensePin =10;         //declare variable for sensePin and set it to arduino pin eg 10
DHT HT(sensePin, Type);    //initialize the library
float humidity;             //declarea a variable for humidity type float
float tempC;                 //declare a variable for temperature in celsius type float
float tempF;                  //declare a variable for temperature in farenheit type float
int setTime=500;              //declar a variable for wait time
int dt = 500;


void setup() {
  Serial.begin(9600);         //start the serial monitor
  HT.begin();             //start the sensor
  delay(setTime);          //set delay for measurement
  
  
}

void loop() {
  humidity = HT.readHumidity();         //read the humidity value into the variable humidity
  tempC=HT.readTemperature();            //read the temperature into the variable tempC and tempF
  tempF =HT.readTemperature(true);
  

  Serial.print("Humidity: ");             //print the values to the serial monitor
  Serial.print(humidity);
  Serial.print("Temperature C: ");
  Serial.print(tempC);
  Serial.print("C");
  Serial.print(tempF);
  Serial.print("F");
  delay(dt);

  

}
