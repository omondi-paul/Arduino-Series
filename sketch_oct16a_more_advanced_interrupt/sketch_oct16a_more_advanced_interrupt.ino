#include <TimerOne.h>
#include <SoftwareSerial.h>
int flag=0;
int redLed=9;
int tmr;
String NMEA="";
char c;
String UPDATE_10_sec= "SPMTK220,10000*2F\r\n";
String GPRMC_ONLY= "SPMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n";
SoftwareSerial GPSSerial(2,3);
void setup() {
  pinMode(redLed,OUTPUT);
  GPSSerial.begin(9600);
  Serial.begin(115200);
  delay(100);
  GPSSerial.print(GPRMC_ONLY);
  delay(100);
  GPSSerial.print(UPDATE_10_sec);
  Timer1.intialize(1000);
  Timer1.attachInterrupt(readGPS);
 
}

void loop() {
  digitalWrite(redLed,HIGH);
  delay(1000);
  digitalWrite(redLed,LOW);
  delay(1000);


  if(flag==1);{
    Timer1.stop();
    NMEA.trim();
    Serial.println(NMEA);
    NMEA="";
    flag=0;
    Timer1.restart
  }
}

void readGPS() {
  if (GPSSerial.available()>0){
    c=GPSSerial.read();
    NMEA.concat(c);

  }
 if (c=='\r\'){
  flag=1;
 }
}
