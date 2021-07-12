int pin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode (pin, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
   
  digitalWrite(pin, HIGH);
  Serial.println("On!");

  delay(1000);
  digitalWrite(pin, LOW);
  Serial.println("Off!");

}
