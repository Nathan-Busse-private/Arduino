#include "DHT.h"

#define DHTPIN 10     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11

int redLed = 12;
int greenLed = 11;
int buzzer = 7;
int smokeA0 = 5;
// Your threshold value
int sensorThres = 400;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("BlueCore Tech Temperature and Humidity");

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  // Give it time to calibrate
  delay(20000);
delay(2000);
int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
  
  float h = dht.readHumidity();
  // Read Celsius
  float t = dht.readTemperature();
  // Read Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check errors
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.println("Humidity: ");
  Serial.print(h);
  Serial.println(" %.");
  Serial.println("  ");
  Serial.println("Temperature: ");
  Serial.print(t);
  Serial.println(" Degrees ");
}
