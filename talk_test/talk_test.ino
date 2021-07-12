int const redPin = 9;
int const yellowPin = 8;
int const greenPin = 7;

void setup()
{
pinMode(redPin,OUTPUT);
pinMode(yellowPin,OUTPUT);
pinMode(greenPin,OUTPUT);
TurnOffAll();
Serial.begin(9600);

}

void loop()
{
if(Serial.available()>0)
{
int pinNumber = GetPinNumber();
Serial.readString();
Serial.print("Value Serial got:");
Serial.println(pinNumber);
TurnOffAll();
TurnCorrespondedLED(pinNumber);
delay(250);
}

}

int GetPinNumber()
{
int pinNumber = 0;

while(Serial.available()>0)
{
char val = Serial.read();
Serial.println(val);
pinNumber*=10;
pinNumber+= (val-'0');
delay(25);
}

return pinNumber;
}

void TurnCorrespondedLED(int pinNumber)
{
if(pinNumber == redPin || pinNumber == yellowPin || pinNumber == greenPin)
digitalWrite(pinNumber,HIGH);

}

void TurnOffAll()
{
digitalWrite(redPin,LOW);
digitalWrite(yellowPin,LOW);
digitalWrite(greenPin,LOW);
}
