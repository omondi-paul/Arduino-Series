int greenLed = 12;
int greenOnTime = 250;
int greenOffTime = 250;
int orangeLed = 11;
int orangeOnTime = 250;
int orangeOffTime = 250;
int greenBlink;
int orangeBlink;
String greenBlinking = "The Green LED is Blinking";
String orangeBlinking= "The Orange LED is Blinking";
String space = "   ";
String blinkNo = "   You are on Blink Number: ";

void setup() {
    Serial.begin(74880);
    String wm1= "Welcome to ";
    String wm2 = "Polito's Arduino Sketch";
    String wm3;
    wm3= wm1 + wm2;
    ;
    Serial.println(wm3);
    Serial.println("How many times do you want the Green LED to blink? ");
  while(Serial.available()==0){}
  greenBlink = Serial.parseInt();
   Serial.println("How many times do you want the Orange LED to blink? ");
  while(Serial.available()==0){}
  orangeBlink = Serial.parseInt();

    

    pinMode(greenLed, OUTPUT);
    pinMode(orangeLed, OUTPUT);

}

void loop() {
  
  Serial.println(space);
  Serial.println(greenBlinking);
  for ( int j= 1; j<=greenBlink; j= j+1){
    Serial.print(blinkNo);
    Serial.println(j);
   digitalWrite(greenLed, HIGH);
   delay(greenOnTime);
   digitalWrite(greenLed, LOW);
   delay(greenOffTime);

  }

  Serial.println(space);
  Serial.println(orangeBlinking);
   for (int j = 1; j<= orangeBlink; j= j+1){
   Serial.print(blinkNo);
   Serial.println(j);
   digitalWrite(orangeLed, HIGH);
   delay(orangeOnTime);
   digitalWrite(orangeLed, LOW);
   delay(orangeOffTime);

   } 
}
