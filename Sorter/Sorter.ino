#include "meArm.h"
#include <Servo.h>
/* Color sorter using MeArm and TSC
 *  mearm library by https://github.com/yorkhackspace/meArm
*/

//pins for meArm
int basePin = 11;
int elbowPin = 10;
int shoulderPin = 9;
int gripperPin = 6;

//pins for color sensor
//s0 & s1 frequency output scaling
//s0 = yellow
//s1 = green
//s0(yellow)  s1(green)
//L           L         = power down no output
//L           H         = 2%
//H           L         = 20%
//H           H         = 100% * (use this setting)
//
//EO = set to low - low to enable fo setting above

int s2 = 7; //color sensor pin s2 to Arduino pin 7
int s3 = 8; //color sensor pin s3 to Arduino pin 8
int outPin = 4; //color sensor pin OUT to Arduino pin 4

//meArm arm: get below parameters from ik_calibration
meArm arm(
      180,0, -pi/2, pi/2,    //Base     (-90 to  90 degrees)
      125,37, pi/4, 3*pi/4,   //Shoulder ( 45 to 135 degrees)
      89,44, 0, -pi/4,      //Elbow    (  0 to -45 degrees)
      //40,120, pi/2, 0);        //Gripper open to close  ( 90 to   0 degrees)
      40,140, pi/2, 0);        //Gripper open to close  ( 90 to   0 degrees)

boolean DEBUG = true;

void setup() {
  arm.begin(basePin, shoulderPin, elbowPin, gripperPin);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); //out from sensor becomes input to arduino

  Serial.begin(9600); //turn on serial port

  //move the arm to the home position
  arm.gotoPoint(0,80,60);
  delay(1000);
  arm.closeGripper();
  delay(100);
}

void loop() {

  //***** grab a color token *****

  arm.openGripper();
  
  //token location
  arm.gotoPoint(-131,131,-17); 
  delay(100); 

  //grab it
  arm.closeGripper();
  delay(100);

  //bring it up
  arm.gotoPoint(-130,130,35); 

  //***** take it to color sensor
  arm.gotoPoint(-172,0,35); 
  delay(2000);

  //identify color
  char color = get_color();

  switch(color) {
    case 'r':   //red
      arm.gotoPoint(70,170,50);
      delay(500); //pause
      arm.openGripper();
      break;
    case 'y':
      arm.gotoPoint(110,170,50);
      delay(500); //pause
      arm.openGripper();
      break;
    case 'g':
      arm.gotoPoint(170,170,50);
      delay(500); //pause
      arm.openGripper();
      break;
    case 'u':   //unidentified. reject
      arm.gotoPoint(-180,50,50);
      delay(500); //pause
      arm.openGripper();
      break;
  }
  
  delay(500);
  return;
  
}

char get_color() {

  int R;
  int G;
  int B;

  char color;
   
  //read red component
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  R = pulseIn(outPin, LOW);

 //read green component
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  G = pulseIn(outPin, LOW);
  
 //let's read blue component
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  
  B = pulseIn(outPin, LOW);

  //*********** calibration required ***************
  //Color sensor is very sensitive to ambient light. You must calibrate following range of values for green, red, and yellow chips.
  //The following values are obtained when a color token is placed at appprox 1 inch from the sensor 
  //Color
  //RGB values for tokens are:
  //red:  30<R<60, 70<G<120, 50<B<90
  //yellow: 10<R<25, 10<G<40, 20<B<50
  //green: 40<R<70, 20<G<50, 20<B<50 daytime calibration
  
  if((R>40) && (R<85) && (G>90) && (G<220) && (B>70) && (B<160))    // red
    {
      if (DEBUG) Serial.println("Color is RED");
      color = 'r';
    }
  else if((R>10) && (R<30) && (G>10) && (G<40) && (B>15) && (B<50))  // yellow
    {
      if (DEBUG) Serial.println("Color is YELLOW");
      color = 'y';
    }
  else if((R>60) && (R<130) && (G>20) && (G<70) && (B>30) && (B<80))  // green
    {
      Serial.println("Color is GREEN"); 
      color = 'g';
    }
  else 
    {  
      if (DEBUG) {
        Serial.print("R = ");
        Serial.print(R);
        Serial.print("  G = ");
        Serial.print(G);
        Serial.print("  B = ");
        Serial.println(B);
      }
      color = 'u'; //unidentified
    }

  return color;
  
}

