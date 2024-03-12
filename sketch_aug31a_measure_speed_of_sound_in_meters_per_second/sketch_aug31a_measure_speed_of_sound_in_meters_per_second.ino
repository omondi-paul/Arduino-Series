int trigPin = 13;   //Sensor trig pin is connected to arduino pin 13
int echoPin = 11;   //connect echo  pin to 11
float pingTime;       //declare variable for time taked for ping to hit target and back
float speedOfSound;     // variable for speedOfSound to be calculated
float targetDistance = 100;   //declare variable and set it to distance  between sensor and obstacle 10cm



void setup() {

 Serial.begin(9600);                 //start the serial monitor

 pinMode(trigPin, OUTPUT);          // set the trigpin as output pin
 pinMode(echoPin, INPUT);          //set the echo pin as input


}

void loop() {
       digitalWrite(trigPin, LOW);  //writes a low to trigpin
       delayMicroseconds(250);        //wait for 250 micro seconds
       digitalWrite(trigPin, HIGH);   //write a high to trigPin to send a pulse
       delayMicroseconds(25);         //wait to let the signal settle
       digitalWrite(trigPin, LOW);     //write a lot to trigpin to mark end of pulse
       
     pingTime = pulseIn(echoPin, HIGH);       //read the time taken to reach the target and back and put in a variable
     pingTime = pingTime/1000000.;             //change ping time to seconds
     speedOfSound =  2 * targetDistance/ pingTime;  //calculate speed of sound for distance and time
     speedOfSound = speedOfSound/100;               //change the speed from cm/s to m/s
     
     Serial.print("Speed of Sound is: ");          //print to serial monitor
     Serial.println(speedOfSound);
     Serial.println(" meters per second");
     delay(250);



}