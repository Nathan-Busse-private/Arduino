//#include <AFMotor.h>

//#include <AFMotor.h>
#define trig 2
#define echo A0

int incomingByte = 0;
int MA1 =  12;     // Motor A
int MA2 =  9;      // Motor A
int PWM_A =10;     // Speed PWM Motor A
int MB1 =  13;     // Motor B
int MB2 =  8;      // Motor B
int PWM_B =11;     //

char bt ;
int Speed = 100;


void setup()

{
  Serial.begin(9600);
 
  MA1.setSpeed(255);
  MA2.setSpeed(255);
  MB1.setSpeed(255);
  MB2.setSpeed(255);
  

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}


void loop() {

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  long t = pulseIn(echo,HIGH);
  long cm = t / 29 / 2;

  
  if (Serial.available() > 0) {
    bt = Serial.read();
    
    Stop(); 

switch (bt){
  case 'F':
    if(cm<20){
      Stop();
    }
    else{ forward( );  }     ; break;
    
  case 'B': backward()      ; break;
  case 'L': left()          ; break;
  case 'R': right()         ; break;
  case 'S': Stop()          ; break;

  case '0': Speed = 100     ; break;
  case '1': Speed = 140     ; break;
  case '2': Speed = 153     ; break;
  case '3': Speed = 165     ; break;
  case '4': Speed = 178     ; break;
  case '5': Speed = 191     ; break;
  case '6': Speed = 204     ; break;
  case '7': Speed = 216     ; break;
  case '8': Speed = 229     ; break;
  case '9': Speed = 242     ; break;
  case 'q': Speed = 255     ; break;

}
}}

void forward()
{
  MA1.setSpeed(Speed);
  MA2.setSpeed(Speed);
  MB1.run(FORWARD);
  MB2.run(FORWARD);
}

void backward()
{
  MA1.setSpeed(Speed);
  MA2.setSpeed(Speed);
  MB1.run(BACKWARD);
  MB2.run(BACKWARD);
}
void left()
{
  MA1.setSpeed(Speed);
  MA2.setSpeed(Speed);
  MB1.run(FORWARD);
  MB2.run(BACKWARD);
}
void right()
{
  MA1.setSpeed(Speed);
  MA2.setSpeed(Speed);
  MB1.run(BACKWARD);
  MB2.run(FORWARD);
}

void Stop()
{
  MA1.run(RELEASE);
  MA2.run(RELEASE);
}
