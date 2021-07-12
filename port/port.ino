#include <L298N.h>                                  // Library for L298N Motor Driver Module

 

int val;                                                        // Initialize Variable

int nb;                                                         // Initialize Variable

 

/* The setup() function is called when a sketch starts. It is used to initialize variables, pin modes, start using libraries, etc. This function will only run once, after each power up or reset of the Arduino board. */

 

void setup()

{

 

Serial.begin(9600);                                           // Baud Rate for Serial Communication

pinMode(10,INPUT);                                        // Digital Pin 10 as Input Pin for Motor A

pinMode(9,INPUT);                                          // Digital Pin 9 as Input Pin for Motor A

pinMode(7,INPUT);                                          // Digital Pin 7 as Input Pin for Motor B

pinMode(6,INPUT);                                          // Digital Pin 6 as Input Pin for Motor B

 

}

 

/* This Particular Function is used for Repeated Execution of the Circuit until Specified. */

 

/* digitalWrite is used to write a HIGH or a LOW value to a digital pin (LOW is the voltage level) */

 

void loop()

{

if(Serial.available()>0)                                 // Check if Data is available

{

int data= Serial.read();                                // Read the Data

Stop();                                                       

 

  if(data=='R')                                               // For Right Movement

  {

    digitalWrite(10,HIGH);                             // Pin 10 is High for Motor A

    digitalWrite(9,LOW);                                // Pin 9 is Low

    digitalWrite(6,HIGH);                               // Pin 6 is High for Motor B

    digitalWrite(7,LOW);                                // Pin 7 is Low

    }

    else if(data=='L')                                      // For Left Movement

    {

    digitalWrite(10,LOW);                              // Pin 10 is Low

    digitalWrite(9,HIGH);                               // Pin 9 is High for Motor A

    digitalWrite(6,LOW);                                // Pin 6 is Low

    digitalWrite(7,HIGH);                               // Pin 7 is High for Motor B

     

    }

      else if(data=='F')                                      // For Forward Movement

      {

        digitalWrite(10,LOW);                           // Pin 10 is Low

        digitalWrite(9,HIGH);                            // Pin 9 is High for Motor A

        digitalWrite(6,HIGH);                            // Pin 6 is High for Motor B

        digitalWrite(7,LOW);                             // Pin 7 is Low

      }

    else if(data=='B')                                      // For Backward Movement      

    {

      digitalWrite(10,HIGH);                           // Pin 10 is High for Motor A

      digitalWrite(9,LOW);                              // Pin 9 is Low

      digitalWrite(6,LOW);                              // Pin 6 is Low

      digitalWrite(7,HIGH);                             // Pin 7 is High for Motor B

    } 

 

}

 

}

void Stop()                                                   // Function to Stop the Motor

{

  digitalWrite(10,LOW);                                // Pin 10 is Low

  digitalWrite(9,LOW);                                  // Pin 9 is Low

  digitalWrite(6,LOW);                                  // Pin 6 is Low

  digitalWrite(7,LOW);                                  // Pin 7 is Low

 

 

  }
