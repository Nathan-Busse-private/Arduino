char Blutoothdata; 

void setup() {
  
  Serial.begin(9600);  
          pinMode(11,OUTPUT);
        pinMode(10,OUTPUT);
      pinMode(9,OUTPUT);
   Blutoothdata='N';}

void loop() {
  
if(Serial.available()){
  Blutoothdata=Serial.read();}
  
while(Blutoothdata=='A'){
  
        digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  
if(Serial.available()){
  
    Blutoothdata=Serial.read();}
    Serial.print(Blutoothdata);}
  
while(Blutoothdata=='B'){
  
       digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  
if(Serial.available()){
      Blutoothdata=Serial.read();}
    Serial.print(Blutoothdata);}
while(Blutoothdata=='C'){
  
      digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  
      if(Serial.available()){
   Blutoothdata=Serial.read();}
  Serial.print(Blutoothdata);}}
