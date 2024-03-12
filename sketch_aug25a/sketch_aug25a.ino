int redLedPin = 12; // declaring redLedPin as int , and set it as 13
int yellowLedPin = 13; // declaring yellowLedPin as int, and set it to 12
int redOnTime ; // This is the red led on time
int redOffTime ; //This is the red led off time
int yellowOnTime ; // This is the yellow on time
int yellowOffTime ;// This is the yellow off time
int redLedBlink; //Declare the int
int yellowLedBlink; //Declare an integer
String redMessage = "The Red LED is Blinking: "; //Declaring a string variable and assigning it a string
String yellowMessage = "The Yellow LED is Blinking: "; //Declaring a string variable and assigning it a string
String blinkNumMessage = "   You are on Blink #: " ; //Declaring a string variable and assigning it a string
String spaceln = "   "; //Declaring a string variable and assigning it a string
  


void setup() {
   Serial.begin(115200); //Turn on the Serial port
   
   pinMode( redLedPin, OUTPUT); //Tell Arduino that redLedPin is an ourput port
   pinMode(yellowLedPin, OUTPUT); //Tell Arduino that yellowLedPin is an ourput port

   String wm1 = "Welcome to "; //Declaring and assigning a String
   String wm2 = "Polito's program"; //Declaring and assigning a String
   String wm3; //Declaring a String
   wm3 = wm1+wm2; //Concatanating 2 strings
   Serial.println(wm3); // Print a string on the screen

   Serial.println( "How much time do you want the Red LED to be On?"); //Prompt User for input
   while(Serial.available()== 0){} //Waits for User input
   redOnTime = Serial.parseInt(); // Passes the User input into the variable redOnTime
   Serial.println( "How much time do you want the Red LED to be Off?");// Asks for the Red LED Off time 
   while(Serial.available()== 0){}//Waits for User input
   redOffTime = Serial.parseInt();//Passes the User input into the variable named redOffTime
   Serial.println( "How many times do you want the Red LED to blink?");//Asks for the times the Red Led should blink
   while(Serial.available()== 0){}//Waits for User input
   redLedBlink = Serial.parseInt(); //passes the User input into the variable redLedBlink

   Serial.println( "How much time do you want the Yellow LED to be On?");//Asks for the Yellow LED On time
   while(Serial.available()== 0){}  //Waits for User input
   yellowOnTime = Serial.parseInt();  // Passes the User input into the variable yellowOnTime
   Serial.println( "How much time do you want the Yellow LED to be Off?");//Asks for the Yellow LED Off time
   while(Serial.available()== 0){}  //Waits for User input 
   yellowOffTime = Serial.parseInt();  // Passes the User input into the variable yellowOffTime
   Serial.println( "How many times do you want the Yellow LED to blink?");//Asks for number of times the User wants the LED to blink
   while(Serial.available()== 0){} //Waits for User input
   yellowLedBlink = Serial.parseInt();  // Passes the User input into the variable yellowLedBlink

   


}

void loop() {
   Serial.println(spaceln);// prints a blank line to make our work look neat
  Serial.println(redMessage); //Prints message on screen
  for ( int j = 1; j <= redLedBlink; j=j+1){ //start our for looop
  Serial.print(blinkNumMessage); //print to screen without and not moving the cursor to next line
  Serial.println(j); //print to screen
  digitalWrite( redLedPin, HIGH);// Turn the red LED on
  delay(redOnTime);// wait
  digitalWrite(redLedPin, LOW);// Turn the red LED off
  delay(redOffTime);// wait
  }
  Serial.println(spaceln);
  Serial.println(yellowMessage);

  for (int j = 1; j<= yellowLedBlink; j = j+1){ //Start the for loop
  Serial.print(blinkNumMessage); 
  Serial.println(j);
  digitalWrite( yellowLedPin, HIGH);// Turn the yellow LED on
  delay(yellowOnTime);// wait
  digitalWrite(yellowLedPin, LOW);// Turn the yellow LED off
  delay(yellowOffTime);// wait

  }
}

