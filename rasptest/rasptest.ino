void setup()

{

pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);

Serial.begin(9600);

while (!Serial);

Serial.println("Input 1 to Turn LED on and 2 to off");

}

void loop() {

if (Serial.available())

{

int state = Serial.parseInt();

if (state == 1)

{

digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);

Serial.println("Command completed LED turned ON");

}

if (state == 2)

{

digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);

Serial.println("Command completed LED turned OFF");

}

}

}
