#include <TimerOne.h>
String ledStatus="OFF";
int yellowLed=10;
int redLed=9;

void setup() {
  pinMode(yellowLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  Timer1.initialize(1000000);
  timer1.attachInterrupt(lbinkYellow);

}

void loop() {
  digitalWrite(redLed,HIGH);
  delay(250);
  digitalWrite(redLed,LOW);
  delay(250);
 

}
void blinkYellow(){
  if(ledStatus=="ON"){
    digitalWrite(yellowLed,LOW);
    ledStatus="OFF";
    return;
  if(ledStatus=="OFF"){
    digitalWrite(yellowLed,HIGH);
    ledStatus="ON"
  }
  }

}

/*dos and don'ts in interrupt
1.use the minimum amount of time in the interrupt function
2.Do something simple
3.Do not use a delay in the interrupt function
4.Don't use slow steps e.g print(they might also mess with serial data)
5.Don't ask user for input in the interrupt function


