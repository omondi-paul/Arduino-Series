#include <LiquidCrystal.h>        //load liquid crystal library
LiquidCrystal myLcd(10, 9, 5, 4, 3, 2); // Creating a liquid crystal display called myLcd
int myCounter = 0;   //declare a variable myCounter



void setup() {
 myLcd.begin(16, 2);  //Tell our arduino our LCD has 16 columnns and 2 rows
 myLcd.setCursor(0,0);  //set Lcd cursor to upper left corner
 myLcd.print("My Timer: ");   //print out the first line

}

void loop() {
   for(myCounter = 1; myCounter<=10; myCounter+=1){
  myLcd.setCursor(0,1);   //Set the cursor to first column(column 0) and second row(row 1)
  myLcd.print("                ");      //Clears the line


  myLcd.setCursor(0,1);   //Set the cursor to first column(column 0) and second row(row 1)
  myLcd.print(myCounter);      //print myCounter
  myLcd.print("  Seconds.");   //print units
  delay(1000);               //delay for 1 second


   }
   for(myCounter = 10; myCounter>=1; myCounter-=1){
   myLcd.setCursor(0,1);   //Set the cursor to first column(column 0) and second row(row 1)
  myLcd.print("                ");      //Clears the line
  
  myLcd.setCursor(0,1);   //Set the cursor to first column(column 0) and second row(row 1)
  myLcd.print(myCounter);      //print myCounter
  myLcd.print("  Seconds.");   //print units
  delay(1000);               //delay for 1 second

   }
}
