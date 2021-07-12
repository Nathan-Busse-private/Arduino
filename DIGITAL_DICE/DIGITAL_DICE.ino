#include <SevSeg.h>

SevSeg sevseg;
long randNumber;
const int buttonPin = 10;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
   bool resistorsOnSegments = true;
   randomSeed(analogRead(0));


   byte hardwareConfig = COMMON_CATHODE;
   sevseg.begin(hardwareConfig, numDigits, digitPins,segmentPins, resistorsOnSegments);
   sevseg.setBrightness(100);
   pinMode(buttonPin, INPUT);
}

void loop() {
 int i;
 randNumber = random(1, 7);
 Serial.println(randNumber);
 i = randNumber;
 sevseg.setNumber(i, i%2);

 buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH){
  delay(3000);
 } else {
  delay(30);
 }
 sevseg.refreshDisplay();
 
 
}
