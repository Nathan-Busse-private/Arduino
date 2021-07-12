#include"SendData2App.h"


//Change the limits as per your sensor data
int UpperThreshold = 560;
int LowerThreshold = 520;


//Default values
int reading = 0;
float BPM = 0.0;
bool IgnoreReading = false;
bool FirstPulseDetected = false;
unsigned long FirstPulseTime = 0;
unsigned long SecondPulseTime = 0;
unsigned long PulseInterval = 0;
const unsigned long delayTime = 10;
const unsigned long delayTime2 = 1000;
const unsigned long delayTime3 = 6000;
const unsigned long baudRate = 9600;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

bool stream = false;

void setup()
{
  Serial.begin(baudRate);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

}

void loop()
{
  unsigned long currentMillis = millis();



  // First event
  if (myTimer1(delayTime, currentMillis) == 1)
  {

    reading = analogRead(A2);

    GetInput();

    SendBeatData( stream, reading);

    DetectLeadingEdge();

    DetectTrailingEdge();

    CalculateBPM();
  }

  // Second event
  if (myTimer2(delayTime2, currentMillis) == 1)
  {
    SendBPM( stream, BPM);
  }
int myBPM = reading.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
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

void GetInput()
{
  if (Serial.available() > 0)
  {
    char re = Serial.read();
    if (re == 'E')
      stream = true;
    else if (re == 'Q')
      stream = false;
  }
}

void DetectLeadingEdge()
{
  // Heart beat leading edge detected.
  if (reading > UpperThreshold && IgnoreReading == false) {
    if (FirstPulseDetected == false) {
      FirstPulseTime = millis();
      FirstPulseDetected = true;
    }
    else {
      SecondPulseTime = millis();
      PulseInterval = SecondPulseTime - FirstPulseTime;
      FirstPulseTime = SecondPulseTime;
    }
    IgnoreReading = true;
    digitalWrite(LED_BUILTIN, HIGH);



  }
}

void DetectTrailingEdge()
{
  // Heart beat trailing edge detected.
  if (reading < LowerThreshold && IgnoreReading == true)
  {
    IgnoreReading = false;
    digitalWrite(LED_BUILTIN, LOW);

  }
}

void CalculateBPM()
{
  // Calculate Beats Per Minute.
  BPM = (1.0 / PulseInterval) * 60.0 * 1000;


}

// First event timer
int myTimer1(long delayTime, long currentMillis)
{
  if (currentMillis - previousMillis >= delayTime)
  {
    previousMillis = currentMillis;
    return 1;
  }
  else {
    return 0;
  }
}

// Second event timer
int myTimer2(long delayTime2, long currentMillis)
{
  if (currentMillis - previousMillis2 >= delayTime2)
  {
    previousMillis2 = currentMillis;
    return 1;
  }
  else {
    return 0;
  }
}
