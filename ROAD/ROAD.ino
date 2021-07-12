#include <L293.h>



//MakewithREX Bot controller android app
#include <NewPing.h>

//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); 
char data = 0;
char getstr;

const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;

const int RightMotorForward = 4;
const int RightMotorBackward = 5;
const int Led = 8;
const int Buzzer = 13;
const int Head = 12;



void _Trig()
{
  digitalWrite(Buzzer, HIGH);
  delay(300);
    digitalWrite(Buzzer, LOW);
}

void _mForward()
{ 
  
  digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  Serial.println("go forward!");
}
void _mBack()
{
  
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  Serial.println("go back!");
}
void _mleft()
{
  
  digitalWrite(LeftMotorBackward, HIGH); 
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  
  Serial.println("go left!");
}
void _mright()
{
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH); 
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  
}
void _mStop()
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  Serial.println("Stop!");
}
void _Led(){
  
  
  
  digitalWrite(Led, HIGH);
  delay(500);
  digitalWrite(Led, LOW);
  Serial.println("Shine!");
}




void setup()
{ 
  
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(Led, OUTPUT);
  
  
  distance = readPing();
  delay(100);

   
}
void loop()
  { 

   

   
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    _mStop();
      delay(300);
    _Led();
    delay(300);
    _Trig();
    delay(300);
    _mBack();
    delay(2000);
    _mStop();
    delay(300);
  }

   else{ 
  getstr=Serial.read();
 if(getstr=='F')
  {
    _Led();
    _mForward();
  }
  else if(getstr=='B')
  {
    _Led();
    _mBack();
    delay(200);
  }
  else if(getstr=='L')
  {
    _Led();
    _mleft();
    delay(200);
    _mleft();
  }
  else if(getstr=='R') 
  {
    _Led();
    _mright();
    delay(200);
    _mright();
  }
  else if(getstr=='X')
  {
     _mStop();     
  }
   }
   distance = readPing();
}
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=30;
  }
  return cm;
}
