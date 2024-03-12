int s2 = 7;  //connect sensor pin to arduino pin 7
int s3 = 8;  //connect sensor pin to arduino pin 8
int outPin = 4;  //colour sensor out pin to arduino pin 4

int trigPin = 13;                   //ultrasonic trigger pin to pin 13
int echoPin = 11;                   // Ultrasonic sensor pin to arduino pin 11

int rColorStrength;                 //measured strength of red color
int gColorStrength;                //measured strength of green color
int bColorStrength;                //measured strength of blue color

unsigned int pulseWidth ;                 //for measuring color strength pulse width

float pingTime;            //time for ping to travel to target and back
float  targetDistance;          //measure distance to target 
float  speedOfSound =  343.86;       //speed of sound in meters per second

void setup() {
  Serial.begin(115200);  //turn on serial port to baud rate of 115200

  pinMode(s2, OUTPUT);          //tell arduino s3 is an output
  pinMode(s3,  OUTPUT);         //tell the arduiino s3 is an output
  pinMode(outPin, INPUT);        //set the output color sensor to an input in arduino

  pinMode(trigPin, OUTPUT);       //ultrasonic trigpin is arduino output
  pinMode(echoPin, INPUT);        //ultrasonic echoPin is arduino input

  

 

}

void loop() {
  //start by measuring red by setting both s2 and s3 to low
  digitalWrite(s2, LOW);
  digitalWrite(s3,  HIGH);

  pulseWidth = pulseIn(outPin , LOW);       //measure pulseWidth of low pulse at outpin on color sensor

  rColorStrength = pulseWidth/400 - 1;        //convert measured measured pulseWidth to a no between 0 and 255 

  rColorStrength = 255- rColorStrength;      //reverse so strong color is a large number


//measure blue component by setting s2 to high and s3 to low
  digitalWrite(s2, HIGH);
  digitalWrite(s3,  LOW);

  pulseWidth = pulseIn(outPin , LOW);       //measure pulseWidth of low pulse at outpin on color sensor

  bColorStrength = pulseWidth/400 - 1;        //convert measured measured pulseWidth to a no between 0 and 255 

  bColorStrength = 255- bColorStrength;      //reverse so strong color is a large number

//measure green component by setting s2 to high and s3 to high
  digitalWrite(s2, HIGH);
  digitalWrite(s3,  HIGH);

  pulseWidth = pulseIn(outPin , LOW);       //measure pulseWidth of low pulse at outpin on color sensor

  gColorStrength = pulseWidth/400 - 1;        //convert measured measured pulseWidth to a no between 0 and 255 

  gColorStrength = 255- gColorStrength;      //reverse so strong color is a large number


  
   if ( rColorStrength > gColorStrength && gColorStrength > bColorStrength){   //case where red is strongest and blue is weakest
      rColorStrength=255;
      gColorStrength=gColorStrength/2;
      bColorStrength=0; 
  }
  
  if ( rColorStrength > bColorStrength && bColorStrength > gColorStrength){   //case where red is strongest and  is green weakest
      rColorStrength=255;
      bColorStrength=bColorStrength/2;
      gColorStrength=0; 
  }
  
   if ( gColorStrength > rColorStrength && rColorStrength > bColorStrength){   //case where green is strongest and blue is weakest
      gColorStrength=255;
      rColorStrength=rColorStrength/2;
      bColorStrength=0; 
  }
  
    if ( gColorStrength > bColorStrength && bColorStrength > rColorStrength){   //case where green is strongest and red is weakest
      gColorStrength=255;
      bColorStrength=bColorStrength/2;
      rColorStrength=0; 
  }
   
   
    if ( bColorStrength > rColorStrength && rColorStrength > gColorStrength){   //case where blue is strongest and green is weakest
      bColorStrength=255;
      rColorStrength=rColorStrength/2;
      gColorStrength=0; 
  }

    if ( bColorStrength > gColorStrength && gColorStrength > rColorStrength){   //case where blue is strongest and red is weakest
      bColorStrength=255;
      gColorStrength=gColorStrength/2;
      rColorStrength=0; 
  }
     //send out ping(pulse) to measure time and hence distance
     digitalWrite(trigPin, LOW);  
     delayMicroseconds(250);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(15);
     digitalWrite(trigPin, LOW);
     delayMicroseconds(15);

     pingTime = pulseIn(echoPin, HIGH);
     pingTime = pingTime/1000000;       //convert ping time to seconds

     targetDistance = speedOfSound* pingTime * 100/2 ;   //calculate distance in centimeters

     Serial.print(rColorStrength);
     Serial.print(" , ");
     Serial.print(gColorStrength);
     Serial.print(" , ");
     Serial.print(bColorStrength);
     Serial.print(" , ");

}






























































