//This sketch prompts user for input(name and mass) then it calaculates that mass in different units and 
//outputs to the user
String putName;              //Declares a variable type string
float putWeight;             //Declares a variable type float
float putMass;
float putPounds;
float putCarats;
float putOunces;
float putGrams;

void setup() {
  Serial.begin(6900);         //Starts the serial monitor
}

void loop() {
  Serial.println("What is your Name?");             //Prompts User for input
  while(Serial.available() ==0){}                   //waits for user input
  putName = Serial.readString();                    //takes user input and passes it into a variable
  Serial.println("Input your mass in kilograms: ");
  while(Serial.available() ==0){}
  putMass = Serial.parseFloat();
  
  putGrams = putMass* 1000;
  putPounds = putMass*2.20462;
  putCarats = putMass*5000;
  putOunces = putMass*35.275;
  putWeight = putMass*9.8;


  Serial.print("Hello there! You are ");
  Serial.print(putName);
  Serial.println(" and your mass is");
  Serial.print(putMass);
  Serial.println(" kilograms");
  Serial.print(putGrams);
  Serial.println(" grams");
  Serial.print(putPounds);
  Serial.println(" pounds");
  Serial.print(putOunces);
  Serial.println(" Ounces");
  Serial.print(putCarats);
  Serial.println(" carats"); 
  Serial.print("And you weigh ");
  Serial.print(putWeight);
  Serial.println(" Newtons");

}
