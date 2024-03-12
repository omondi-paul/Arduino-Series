int redLedPin = 6; // declaring redLedPin as int , and set it as 13
int yellowLedPin = 9; // declaring yellowLedPin as int, and set it to 12
int redOnTime = 250 ; // This is the red led on time
int redOffTime = 250; //This is the red led off time
int yellowOnTime = 250 ; // This is the yellow on time
int yellowOffTime = 250 ;// This is the yellow off time
int redLedBlink = 5; //Declare the int
int yellowLedBlink = 5; //Declare an integer
String redMessage = "The Red LED is Blinking: "; //Declaring a string variable and assigning it a string
String yellowMessage = "The Yellow LED is Blinking: "; //Declaring a string variable and assigning it a string
String blinkNumMessage = "   You are on Blink #: " ; //Declaring a string variable and assigning it a string
String spaceln = "   "; //Declaring a string variable and assigning it a string
int off = 0; // declaring an int off and setting it to 0
int redValue;
int yellowValue;

void setup() {
  Serial.begin(115200); //Turn on the Serial port
   
   pinMode( redLedPin, OUTPUT); //Tell Arduino that redLedPin is an ourput port
   pinMode(yellowLedPin, OUTPUT); //Tell Arduino that yellowLedPin is an ourput port
  Serial.println("What number do you want to set the red LED? (0-250) ");
  while(Serial.available() == 0) {}
  redValue = Serial.parseInt(); // takes the User input into the variable redValue

  Serial.println("What number do you want to set the yellow LED? (0-250) ");
  while(Serial.available() == 0) {}
  yellowValue = Serial.parseInt(); // takes the User input into the variable redValue
}

void loop() {
  Serial.println(spaceln);// prints a blank line to make our work look neat
  Serial.println(redMessage); //Prints message on screen
  int j = 1; //Declares int j and sets it to 1
  while (j<=redLedBlink){ //start our for looop
  Serial.print(blinkNumMessage); //print to screen without and not moving the cursor to next line
  Serial.println(j); //print to screen
  analogWrite(redLedPin,redValue);// Turn the red LED on
  delay(redOnTime);// wait
  analogWrite(redLedPin,off);// Turn the red LED off
  delay(redOffTime);   // wait
  j+=1;  //increments j by 1
  }

  Serial.println(spaceln);       // Prints a blank line
  Serial.println(yellowMessage);
  j=1;//Resets j to 1
  while(j<=yellowLedBlink){     //Start the while loop
  Serial.print(blinkNumMessage); 
  Serial.println(j);
  analogWrite(yellowLedPin,yellowValue);// Turn the yellow LED on with an analogueWrite value
  delay(yellowOnTime);// wait
  analogWrite(yellowLedPin, off);// Turn the yellow LED off
  delay(yellowOffTime);// wait
  j+=1;

  }
}

