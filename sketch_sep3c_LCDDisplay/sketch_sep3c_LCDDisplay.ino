#include <LiquidCrystal.h>

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float num1;
float num2;
float ans=0.;
String op;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Hello World");
 
  Serial.begin(9600);

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("First number: ");
  while(Serial.available()==0){}
  num1 = Serial.parseFloat();
  lcd.clear();

  lcd.setCursor(0,0);
 lcd.print("op(+,-,*,/) ");
  while(Serial.available()==0){}
  op = Serial.readString(); 

  lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("Second number: ");
  while(Serial.available()==0){}
  num2 = Serial.parseFloat();               

if(op=="+"){
   ans= num1+num2;
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("The Answer to: ");
   lcd.setCursor(0,1);
   lcd.print(num1);
   lcd.print(op);
   lcd.print(num2);
   lcd.print("=");
   lcd.print(ans);
   delay(2000);
}
 
if(op=="-"){
   ans= num1-num2;
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("The Answer to: ");
   lcd.setCursor(0,1);
   lcd.print(num1);
   lcd.print(op);
   lcd.print(num2);
   lcd.print("=");
   lcd.print(ans);
   delay(2000);
}


if(op=="/"){
   ans= num1/num2;
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("The Answer to: ");
   lcd.setCursor(0,1);
   lcd.print(num1);
   lcd.print(op);
   lcd.print(num2);
   lcd.print("=");
   lcd.print(ans);
   delay(2000);
}

if(op=="*"){
   ans= num1*num2;
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("The Answer to: ");
   lcd.setCursor(0,1);
   lcd.print(num1);
   lcd.print(op);
   lcd.print(num2);
   lcd.print("=");
   lcd.print(ans);
  
    
   
   
   
   
}


}

