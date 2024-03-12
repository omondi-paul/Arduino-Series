int numGrades;
float grades[15];
int j;
float av;
float bucket=0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  inputGrades();
  avGrades();
  printGrades();

}
void inputGrades(){
  Serial.println("How many Grades? ");
  while(Serial.available()==0){}
  numGrades=Serial.parseInt();
  for (j=1; j<=numGrades; j=j+1){
    Serial.println("Please Input a Grade: ");
    while (Serial.available()==0){}
    grades[j]=Serial.parseFloat();
  }
}

void avGrades(){
  for (j=1; j<=numGrades; j=j+1){
    bucket=bucket+grades[j];
  }
  av=bucket/numGrades;
  bucket=0;
}

void printGrades(){
  Serial.println("Your Grades Are: ");
  for(j=i; j<=numGrades; j=j+1){
    Serial.println(grades[j]);
  }
  Serial.println("");
  Serial.print("Your Average is: ");
  Serial.println(av);
  Serial.println("");
}

