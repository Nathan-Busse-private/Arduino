# Arduino-HeartRateMonitor

[![N|Solid](https://github.com/Abiram-N/Arduino-HeartRateMonitor/blob/master/asset/elektik_icon.png)]()

![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)

[DOWNLOAD THE APP FROM GOOGLE PLAY STORE]

Arduino Heart Rate Monitor is a Heart Rate Monitor which uses Bluetooth to communicate with arduino and displays heart rate and BPM.

  - Bluetooth Communication
  - Displays Heart Beat Visually in Real Time
  - Displays Real Time BPM

# New Features!

  - Added support for portrait mode
  - Material UI


Future Development:
  - Add support to ESP32
  - Cloud integration
  - IOT support
  - Add Dark Mode

### Tech

This Project is built using following software:

* [node.js] - evented I/O for the backend
* [Android Studio] – Used to Build the app
* [asksensors] – To bring IOT support for project
* [Adafruit] – To log BPM data in cloud
* [Arduino IDE] – To program ESP8366/NODE MCU

And of course Arduino Heart Rate Monitor itself is open source with a [public repository][dill]
 on GitHub.

## Implementation

### Android APP

#### Regular Heart Beat `Landscape`
<p align="center">
  <img src="https://github.com/Abiram-N/Arduino-HeartRateMonitor/blob/master/asset/RegularLandscape.gif">
</p>

#### Regular Heart Beat `Portrait`
<p align="center">
  <img width="300" src="https://github.com/Abiram-N/Arduino-HeartRateMonitor/blob/master/asset/Regular_Portrait.png">
</p>

#### Irregular Heart Beat `Landscape`
<p align="center">
  <img src="https://github.com/Abiram-N/Arduino-HeartRateMonitor/blob/master/asset/Irregular_Landscape.gif">
</p>

#### Irregular Heart Beat `Portrait`
<p align="center">
  <img width="300" src="https://github.com/Abiram-N/Arduino-HeartRateMonitor/blob/master/asset/Irregular_Portrait.png">
</p>


#### Arduino Code

```sh
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
    reading = analogRead(A0);

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
```

Library to Send Data to APP (SendData2App.h)...

```sh
float floatMap(float x, float inMin, float inMax, float outMin, float outMax) 
{
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

void SendBeatData(bool stream,int reading)
{
	if (stream)
    {
      String Value;
      Value = "sr" + String(floatMap(reading, 0, 1024, 0, 5), 2);
      Serial.println(Value);
      delay(90);
    }
}

void SendBPM(bool stream,float BPM)
{
	if (stream)
    {
      String Value1;
      Value1 = "s\nb";
      Value1 += BPM;
      Serial.println(Value1);
    }
}

```
Be sure to set `UpperThreshold` and `LowerThreshold` in arduino Code according to your sensor output

### IOT Support

Arduino-HeartRateMonitor is currently offline and supports only Bluetooth Based Communication.The future update will include IOT support with cloud integration

| Service | Link |
| ------ | ------ |
| Ask Sensors | [asksensors.com][PlDb] |
| Adafruit | [adafruit.io][Adafruit] |

[//]: # ()


   [dill]: <https://github.com/Abiram-N/Arduino-HeartRateMonitor>
   [asksensors]: <https://asksensors.com/>
   [Android Studio]: <https://developer.android.com/studio>
   [Adafruit]: <https://io.adafruit.com>
   [Arduino IDE]: <https://www.arduino.cc/en/main/software>
   [node.js]: <http://nodejs.org>
   [PlDb]: <https://asksensors.com/>
   [DOWNLOAD THE APP FROM GOOGLE PLAY STORE]:<https://microsoftindia.app.link/heartratemonitor>
