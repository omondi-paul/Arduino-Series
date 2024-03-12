int speedPin = 5;
int dir1=4;
int dir2=3;
int mSpeed = 255;


void setup() {
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

}

void loop() {
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, LOW);
      analogWrite(speedPin, mSpeed);

}
