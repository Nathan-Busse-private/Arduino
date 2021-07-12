
const int tiltSensor = 7;
int steps = 0;
int switchState = HIGH;
int prevSwitchState = LOW;

void setup() {
  Serial.begin(9600);

  pinMode(tiltSensor, INPUT);

  
  Serial.println("Hey Fatty");
  
  Serial.println("Start Walking!");
}

void loop() {
 switchState = digitalRead(tiltSensor);

  if (switchState != prevSwitchState) {

    if (switchState == LOW) {
      steps = steps + 1;
      
      Serial.println("Steps:");
      
      Serial.print(steps / 5); //This is because I had no luck getting an accurate debouce on the sensor and didn't want to waste any more time trying
    }
  }
  prevSwitchState = switchState;
}
