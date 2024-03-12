int redPin =9;  //set red pin to 9
int bluePin =10;         //set blue pin to 10
int greenPin =11;        //set green pin to 11

int s2 = 7;   
int s3 = 8;
int outPin = 4;

unsigned int pulseWidth;

 int rColorStrength;
 int bColorStrength;
 int gColorStrength;


void setup() {
     Serial.begin(9600);

     pinMode (redPin , OUTPUT);
     pinMode( bluePin, OUTPUT);
     pinMode(greenPin, OUTPUT);
    
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(outPin, INPUT);

}

void loop() {
   digitalWrite(s2, LOW);
   digitalWrite(s3,  LOW);
   pulseWidth = pulseIn(outPin,LOW);
   rColorStrength = pulseWidth/400. -1;
   rColorStrength = 255 - rColorStrength;

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   pulseWidth = pulseIn(outPin,LOW);
   bColorStrength = pulseWidth /400. -1;
   bColorStrength = 255 - bColorStrength;


 digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   pulseWidth = pulseIn(outPin,LOW);
   gColorStrength = pulseWidth /400. -1;
   gColorStrength = 255-gColorStrength;

   analogWrite(redPin,rColorStrength);
   analogWrite(bluePin,bColorStrength);
   analogWrite(greenPin,gColorStrength);

   Serial.print("rColorStrength is: ");
   Serial.print(rColorStrength);
   Serial.print(" , ");
  Serial.print("bColorStrength is: ");
   Serial.print(bColorStrength);
   Serial.print(" , ");
    Serial.print("Green ColorStrength is: ");
   Serial.println(gColorStrength);
   Serial.print("");
}
