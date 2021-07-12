const int LeftMotorForward = 10;
const int LeftMotorBackward = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(4000);
digitalWrite(LeftMotorBackward, LOW);
delay(400);
digitalWrite(LeftMotorForward, HIGH);
delay(400);
Serial.println("HI");
}
