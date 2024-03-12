#include <SD.h> //Load the SD library
#include <SPI.h> //Load the Serial Port Interface Library

#include "Wire.h"    // imports the wire library for talking over I2C 
#include "Adafruit_BMP085.h"  // import the Pressure Sensor Library
Adafruit_BMP085 mySensor;  // create sensor object called mySensor

float tempC;  // Variable for holding temp in C
float tempF;  // Variable for holding temp in F
float pressure; //Variable for holding pressure reading

int chipSelect=4;  //set chip select to 4
file mySensorData; //Variable for writing our file object

void setup(){
Serial.begin(9600); //turn on serial monitor
mySensor.begin();   //initialize mySensor

pinMode(10, OUTPUT); //Reserve pin 10 as an output, don't use it for other parts of circuit
SD.begin(chipSelect); //Initialize the SD card with chipSelect connected to pin 4
}

void loop() {
tempC = mySensor.readTemperature(); //  Read Temperature
tempF = tempC*1.8 + 32.; // Convert degrees C to F
pressure=mySensor.readPressure(); //Read Pressure

mySensorData= SD.open("PTData.txt", FILE_WRITE); //open PTData.txt on the SD card as a file to write to

if (mySensorData) {          //only do this things if data file opened successfully
Serial.print("The Temp is: "); //Print Your results
Serial.print(tempF);
Serial.println(" degrees F");
Serial.print("The Pressure is: ");
Serial.print(pressure);
Serial.println(" Pa.");
Serial.println("");
delay(250); //Pause between readings.

mySensorData.print(tempF); //write tempF to the SD card
mySensorData.print(",")   //Write comma to the line
mySensorData.print(pressure); //Write pressure data and go to the next line
mySensorData.close();  //close the file

}

}






