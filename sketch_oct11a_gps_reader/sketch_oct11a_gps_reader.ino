#include <Adafruit.gps.h> //install the adafruit gps library
#include <SoftwareSerial.h>   //Load the software serial library
SoftwareSerial mySerial(3,2);   //Initialize the software serial port
Adafruit_GPS GPS(mySerial);   //Create the GPS object

String NMEA1; //Variable for first nmea sentence
String NMEA2;     //Variable for second nmea sentence
char c;   //to read characters coming from the GPS

void setup() {
  
  Serial.begin(115200);   //Turn on the serial monitor
  GPS.begin(9600);    //Turn on GPS at 9600 baud
  GPS.sendCommand("$PGCND,33,0*6D");    //Turn off antenna update nuisance data
  GPS.sendCommand(PNTK_SET_NMEA_UPDATE_10HZ);    //Set update rate to 10hz
  GPS.sendCommand(PNTK_SET_NMEA_OUTPUT_RMCGGA);   //Request RMC and GGA Sentences only
  delay(1000);

}

void loop() {
  
  readGPS();
  delay(250);
}

void readGPS(){
  clearGPS();

  while(!GPS.newNMEAreceived()){    //Loop until you have a good NMEA sentence
    c=GPS.read();
  
  }
  GPS.parse(GPS.lastNMEA());    //Parse that last good NMEA sentence
  NMEA1=GPS.lastNMEA();

  while(!GPS.newNMEAreceived()){    //Loop until you have a good NMEA sentence
    c=GPS.read();
  
  }
  GPS.parse(GPS.lastNMEA());    //Parse that last good NMEA sentence
  NMEA2=GPS.lastNMEA();

  Serial.println(NMEA1);
  Serial.println(NMEA2);
                    
}
void clearGPS(){    //clear old and corrupt data from serial port

   while(!GPS.newNMEAreceived()){    //Loop until you have a good NMEA sentence
    c=GPS.read();
  
  }
  GPS.parse(GPS.lastNMEA());    //Parse that last good NMEA sentence


}
