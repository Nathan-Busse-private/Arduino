#include <Servo.h>
Servo myServo;
 int servoPin = 5;
 int pos = 0;
 int min = 5;
 int max = 160;

int pinPot = A0;

 
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(pinPot));
  for (pos= min; pos <=max; pos += 1) {
    myServo.write(pos);
    delay(15);
    
  }
  delay(500);
  for (pos = max; pos >= min; pos -= 1) {
    myServo.write(pos);
    delay(15);

  
  }
  delay(1000);
  

}
