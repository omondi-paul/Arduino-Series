/*This program uses a for loop to count in binary from 0x00 to 0xFF equivalent of 255 then resets back to zero */ 
int latchPin= 11;   //set the latch pin of shift register to pin 11 of the arduino
int clockPin=9;     //set clockPin of shift register to pin 9 of the arduino
int dataPin=12;      //set dataPin of the shift register to pin 12 of the arduino
int dt = 1000;
int mod;

byte myByte= 0x00;          //declare a variable LED of type byte

void setup() {
  Serial.begin(9600);                     //begin the serial monitor at a baud rate of 9600
  pinMode(latchPin, OUTPUT);              //initialize latchPin as on output pin
  pinMode(clockPin, OUTPUT);              //initialize clocPin as on output pin
  pinMode(dataPin, OUTPUT);               //initialize dataPin as on output pin

}

void loop() {

      digitalWrite(latchPin, LOW);     //write a low to latch pin to indicate writing; refer to microprocessors knowledge i8086
      shiftOut(dataPin, clockPin, LSBFIRST,myByte); 
      digitalWrite(latchPin, HIGH);
            
      Serial.print(myByte, DEC);
      Serial.print("     ");
      Serial.print(myByte, BIN);
      Serial.print("     ");
      Serial.println(myByte, HEX);
      
     
      myByte=255-myByte;
    
      delay(dt);
  
  
  }


























