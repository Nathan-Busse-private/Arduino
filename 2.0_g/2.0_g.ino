#include "DHT.h"
#define USE_ARDUINO_INTERRUPTS true 
#define DHTPIN 10 
#define DHTTYPE DHT11 
// Set-up low-level interrupts for most acurate BPM math.

DHT dht(DHTPIN, DHTTYPE);

#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
#include <LiquidCrystal.h>
//  Variables
const int PulseWire = 2;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
 int redLed = 5;
int greenLed = 11;
int buzzer = 12;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400; // Otherwise leave the default "550" value. 
 

              
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"
 
#define rs 9 
#define en 8 
#define d4 7 
#define d5 6  
#define d6 5 
#define d7 4 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 

  
void setup() {  
  
Serial.begin(9600);
   pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
 
  Serial.begin(9600);  
  dht.begin();       // For Serial Monitor
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   
 
  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
    lcd.clear();
    lcd.print("BPM:"); // BEATS PER MINUTE

    
  }
}
 
 
 
void loop() {


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
{
  delay(000);
}
 
 

 


{
  delay(1000);
}
                    // considered best practice in a simple sketch.

  

  
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


  int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 
 
if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
 Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);                        // Print the value inside of myBPM. 
    lcd.clear();  
  lcd.print("BPM:");
   lcd.setCursor(0,1);
  lcd.print(myBPM); 
}
}
