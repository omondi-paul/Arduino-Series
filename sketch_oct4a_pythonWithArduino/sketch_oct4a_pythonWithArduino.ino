String cmd;
int LED1=9:
int LED2=6:
int LED3=5;
int LED4=3;
int LED5=10;

void setup() {
  // put your setup code here, to run once:

pinMode=(LED1,OUTPUT);
pinMode=(LED2,OUTPUT);
pinMode=(LED3,OUTPUT);
pinMode=(LED4,OUTPUT);
pinMode=(LED5,OUTPUT);
Serial begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly
while(Serial.available()==0){}
cmd=Serial.readStringUntil('\r');

if(cmd=="One"){
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
}
if(cmd=="Two"){
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
}
if(cmd=="Three"){
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
}
if(cmd=="Four"){
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,LOW);
}
if(cmd=="Five"){
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,HIGH);
}

}
