/* define section */

//Motor driver setup L298N
const int IN1 = 7; //connect IN1 in the motor driver to pin number 7 in arduino
const int IN2 = 6; //connect IN2 in the motor driver to pin number 6 in arduino
const int IN3 = 5; //connect IN3 in the motor driver to pin number 5 in arduino
const int IN4 = 4; //connect IN4 in the motor driver to pin number 4 in arduino

/* this will allow you to control the speed of the motors */

const int ENA = 9; //connect IN1 in the motor driver to pin number 9 in arduino
const int ENB = 3; //connect IN1 in the motor driver to pin number 3 in arduino

//***************************************************************************//

int command = 0;// int to store the data that we will receive from the bluetooth

/* define the pins for the ultrasonic sensor */

int trig = 11; /* connect trigger pin of Ultrasonic to pin number 11 */
int echo = 12; /* connect echo pin of Ultrasonic to pin number 12 */

/* void setup section we are going to setup our pins to input or output */

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  
  // set motor driver`s pins to output
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
//set trig pin as output and the echo pin as input for the ultrasonic sesor
  pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
}

/*void loop section we are going to write our main program here*/

void loop()
{


  if (Serial.available() > 0) //check if the arduino is receiving data or not
{
  command=Serial.read(); //set command integer value sama as the value that we will receive from the bluetooth NOT(we are going to send characters from 0 to 5 and each character will do a different job.

}
if (command == 'F')//if we receive a character 0 then both motors will move forward

  {
    // by setting IN1 and IN3 HIGH and IN2 and IN4 LOW both motors will move forward accoring to my connections and ENA and ENB to control the speed from 0 to 250 and this same as the following characters
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 2000);
    analogWrite(ENB, 2000);
command=0; //set command value back to 0
  }
else if(command == 'B') // moving backward
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 2000);
    analogWrite(ENB, 2000);
    
    command=0; //set command value back to 0
  }
 else if (command == 'L') //moving left
 {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 2000);
    analogWrite(ENB, 2000);
      command=0; //set command value back to 0
  }
else if (command == 'R') //moving right
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 2000);
    analogWrite(ENB, 2000);
      command=0; //set command value back to 0
  }
else if (command == 'S') //stop the motors
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
      command=0; //set command value back to 0
  }
else if (command == 'X') 
{


long du = 0, ds = 0; // Transmitting pulse
digitalWrite(trig, LOW); //set trig pin to high
delayMicroseconds(10); //wait 2MS
digitalWrite(trig, HIGH); //set trig pin to high to send pulse
delayMicroseconds(10); //wait 10MS
digitalWrite(trig, LOW);// Waiting for pulse
du = pulseIn(echo, HIGH);// check for the pulse
ds = du*0.034/2 ;// Calculating distance

//move the motors forward

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 2000);
    analogWrite(ENB, 2000);

if (ds<=10) //if the space betwen the robot and the object less than 10 or 10 then turn right until the robot gets a space more than 10
{
    analogWrite(ENA, 2000);
    analogWrite(ENB, 2000);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(1000);
    analogWrite(ENA, 2000);
    analogWrite(ENB, 2000);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
   delay(1000);
} 
command='x'; //here we will let the robot do the same job untill the we press stop bottom from mobile or press any bottom so we control it manualy 
}


}
