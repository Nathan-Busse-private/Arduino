#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define ENA 9
#define ENB 3

void setup() {
  
  
  // put your setup code here, to run once:
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available())
  {
    char In=Serial.read();
     if(In=='f' || In=='F')//forward
      {    
      
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 2000);
      analogWrite(ENB, 2000);
    
      
     }
    
     else if(In=='b' || In=='B')            //backward
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 2000);
      analogWrite(ENB, 2000);
    }
    
     else if(In=='l' || In=='L')     // Left
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 2000);
      analogWrite(ENB, 2000);
    }
    
     else if(In=='r' || In=='R')     // Right
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 2000);
      analogWrite(ENB, 2000);
    }
    
     else if(In=='s' || In=='S')    // stop
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 2000);
      analogWrite(ENB, 2000);
    }
    
    else
    {
      
    }
  }
}
