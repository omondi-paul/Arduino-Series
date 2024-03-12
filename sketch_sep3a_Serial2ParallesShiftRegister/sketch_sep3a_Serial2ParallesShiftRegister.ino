int latchPin= 11;   //set the latch pin of shift register to pin 11 of the arduino
int clockPin=9;     //set clockPin of shift register to pin 9 of the arduino
int dataPin=12;      //set dataPin of the shift register to pin 12 of the arduino
int dt = 250;

byte LEDs=0xFF;          //declare a variable LED of type byte

void setup() {
  Serial.begin(9600);                     //begin the serial monitor at a baud rate of 9600
  pinMode(latchPin, OUTPUT);              //initialize latchPin as on output pin
  pinMode(clockPin, OUTPUT);              //initialize clocPin as on output pin
  pinMode(dataPin, OUTPUT);               //initialize dataPin as on output pin

}

void loop() {
      digitalWrite(latchPin, LOW);     //write a low to latch pin to indicate writing; refer to microprocessors knowledge i8086
      shiftOut(dataPin, clockPin, LSBFIRST,LEDs);  /*use shift out command to send out data
                                                   1. datapin- output pin that we set to pin 12 carries your data out in a serial manner
                                                  2.  clockpin-sends out clock signals , microP takes care of that after you use shiftout 
                                                    command
                                                   3. either LSRFIRST out or MSBFIRST
                                                   4. and the variable sent out(LEDS)     */
      
      digitalWrite(latchPin, HIGH);
      delay(dt);

      digitalWrite(latchPin, LOW);     //write a low to latch pin to indicate writing; refer to microprocessors knowledge i8086
      shiftOut(dataPin, clockPin, LSBFIRST,LEDs);  /*use shift out command to send out data
                                                   1. datapin- output pin that we set to pin 12 carries your data out in a serial manner
                                                  2.  clockpin-sends out clock signals , microP takes care of that after you use shiftout 
                                                    command
                                                   3. either LSRFIRST out or MSBFIRST
                                                   4. and the variable sent out(LEDS)     */
      
      digitalWrite(latchPin, HIGH);
      delay(dt);
}
