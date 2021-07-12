+#include <Servo.h>

Servo servo1; // front left 
Servo servo2; //rear left
Servo servo3; // front right
Servo servo4; // rear right

int middle = 90;
int endPoint = 80;
int stepDelay = 200;

void setup()
{
  servo1.attach(9); 
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);
}

void loop() {
  servo1.write(middle);
  servo2.write(middle);
  servo3.write(middle);
  servo4.write(middle);
  delay(stepDelay);

  servo1.write(middle - endPoint);
  delay(stepDelay);
  servo3.write(middle + endPoint);
  delay(stepDelay);
  servo2.write(middle - endPoint);
  delay(stepDelay);
  servo4.write(middle + endPoint);
  delay(stepDelay);
}
