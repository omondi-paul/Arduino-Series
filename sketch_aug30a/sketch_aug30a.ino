int redLed = 9;                          //set redLed pin to 9
int blueLed = 10;                        //set blueLed pin to 10
int greenLed = 11;                       //set greenLed pint to 11



void setup() {
  Serial.begin(115200);                 //start the serial monitor
  pinMode(redLed, OUTPUT);              //Set the Led pins to output
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  
}

void loop() {
  for(int redBright = 0; redBright<=255; redBright+=4){             //Start a for loop
     analogWrite(redLed, redBright);                           //apply a voltage to redLed pin
     delay(100);                                                 //wait for 100 millisecondse
     for(int blueBright=0; blueBright<= 255;blueBright+=4){      //Start a for loop inside another for loop
         analogWrite(blueLed, blueBright);                      //apply a voltage to redLed pin
         delay(100);                                               //wait for 100 millisecondse
         for(int greenBright=0; greenBright<=255; greenBright+=4){   //Start a for loop
     analogWrite(greenLed, greenBright);                               //apply a voltage to redLed pin
     delay(100);                                                      //wait for 100 millisecondse
     Serial.print("Red LED value is:    ");
     Serial.println(redBright);                                       //Print value of variable redBright to serial monitor
     Serial.print("Blue LED value is:    ");
    Serial.println(blueBright);                                     //Print value of variable to serial monitor
     Serial.print("Green LED value is:     ");
     Serial.println(greenBright);                                  //Print value of variable to serial monitor
     

         }    
     }
  }
  
}
